/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file Client.h
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 */

#pragma once

#include <thread>
#include <mutex>
#include <list>
#include <atomic>
#include <string>
#include <array>

#include <boost/utility.hpp>

#include <libdevcore/Common.h>
#include <libdevcore/CommonIO.h>
#include <libdevcore/Guards.h>
#include <libdevcore/Worker.h>
#include <libethcore/Params.h>
#include <libp2p/Common.h>
#include "CanonBlockChain.h"
#include "TransactionQueue.h"
#include "State.h"
#include "CommonNet.h"
#include "Miner.h"
#include "InterfaceStub.h"

namespace dev
{
namespace eth
{

class Client;
class DownloadMan;

enum ClientWorkState
{
	Active = 0,
	Deleting,
	Deleted
};

class VersionChecker
{
public:
	VersionChecker(std::string const& _dbPath);

	void setOk();
	bool ok() const { return m_ok; }

private:
	bool m_ok;
	std::string m_path;
};

static const int GenesisBlock = INT_MIN;

template <class T> struct ABISerialiser {};
template <unsigned N> struct ABISerialiser<FixedHash<N>> { static bytes serialise(FixedHash<N> const& _t) { static_assert(N <= 32, "Cannot serialise hash > 32 bytes."); static_assert(N > 0, "Cannot serialise zero-length hash."); return bytes(32 - N, 0) + _t.asBytes(); } };
template <> struct ABISerialiser<u256> { static bytes serialise(u256 const& _t) { return h256(_t).asBytes(); } };
template <> struct ABISerialiser<u160> { static bytes serialise(u160 const& _t) { return bytes(12, 0) + h160(_t).asBytes(); } };
template <> struct ABISerialiser<string32> { static bytes serialise(string32 const& _t) { return bytesConstRef((byte const*)_t.data(), 32).toBytes(); } };

inline bytes abiInAux() { return {}; }
template <class T, class ... U> bytes abiInAux(T const& _t, U const& ... _u)
{
	return ABISerialiser<T>::serialise(_t) + abiInAux(_u ...);
}

template <class ... T> bytes abiIn(std::string _id, T const& ... _t)
{
	return sha3(_id).ref().cropped(0, 4).toBytes() + abiInAux(_t ...);
}

template <class T> struct ABIDeserialiser {};
template <unsigned N> struct ABIDeserialiser<FixedHash<N>> { static FixedHash<N> deserialise(bytesConstRef& io_t) { static_assert(N <= 32, "Parameter sizes must be at most 32 bytes."); FixedHash<N> ret; io_t.cropped(32 - N, N).populate(ret.ref()); io_t = io_t.cropped(32); return ret; } };
template <> struct ABIDeserialiser<u256> { static u256 deserialise(bytesConstRef& io_t) { u256 ret = fromBigEndian<u256>(io_t.cropped(0, 32)); io_t = io_t.cropped(32); return ret; } };
template <> struct ABIDeserialiser<u160> { static u160 deserialise(bytesConstRef& io_t) { u160 ret = fromBigEndian<u160>(io_t.cropped(12, 20)); io_t = io_t.cropped(32); return ret; } };
template <> struct ABIDeserialiser<string32> { static string32 deserialise(bytesConstRef& io_t) { string32 ret; io_t.cropped(0, 32).populate(bytesRef((byte*)ret.data(), 32)); io_t = io_t.cropped(32); return ret; } };

template <class T> T abiOut(bytes const& _data)
{
	bytesConstRef o(&_data);
	return ABIDeserialiser<T>::deserialise(o);
}

class RemoteMiner: public Miner
{
public:
	RemoteMiner() {}

	void update(State const& _provisional, BlockChain const& _bc) { m_state = _provisional; m_state.commitToMine(_bc); }

	h256 workHash() const { return m_state.info().headerHash(IncludeNonce::WithoutNonce); }
	u256 const& difficulty() const { return m_state.info().difficulty; }

	bool submitWork(ProofOfWork::Proof const& _result) { return (m_isComplete = m_state.completeMine(_result)); }

	virtual bool isComplete() const override { return m_isComplete; }
	virtual bytes const& blockData() const { return m_state.blockData(); }

	virtual void noteStateChange() override {}

private:
	bool m_isComplete = false;
	State m_state;
};

class BasicGasPricer: public GasPricer
{
public:
	explicit BasicGasPricer(u256 _weiPerRef, u256 _refsPerBlock): m_weiPerRef(_weiPerRef), m_refsPerBlock(_refsPerBlock) {}

	void setRefPrice(u256 _weiPerRef) { m_weiPerRef = _weiPerRef; }
	void setRefBlockFees(u256 _refsPerBlock) { m_refsPerBlock = _refsPerBlock; }

	u256 ask(State const&) const override { return m_weiPerRef * m_refsPerBlock / m_gasPerBlock; }
	u256 bid(TransactionPriority _p = TransactionPriority::Medium) const override { return m_octiles[(int)_p] > 0 ? m_octiles[(int)_p] : (m_weiPerRef * m_refsPerBlock / m_gasPerBlock); }

	void update(BlockChain const& _bc) override;

private:
	u256 m_weiPerRef;
	u256 m_refsPerBlock;
	u256 m_gasPerBlock = 1000000;
	std::array<u256, 9> m_octiles;
};

/**
 * @brief Main API hub for interfacing with Ethereum.
 */
class Client: public MinerHost, public InterfaceStub, Worker
{
	friend class Miner;

public:
	/// New-style Constructor.
	explicit Client(
		p2p::Host* _host,
		std::string const& _dbPath = std::string(),
		bool _forceClean = false,
		u256 _networkId = 0,
		int _miners = -1
	);

	explicit Client(
		p2p::Host* _host,
		std::shared_ptr<GasPricer> _gpForAdoption,		// pass it in with new.
		std::string const& _dbPath = std::string(),
		bool _forceClean = false,
		u256 _networkId = 0,
		int _miners = -1
	);

	/// Destructor.
	virtual ~Client();

	/// Resets the gas pricer to some other object.
	void setGasPricer(std::shared_ptr<GasPricer> _gp) { m_gp = _gp; }

	/// Differences between transactions.
	using Interface::diff;
	virtual StateDiff diff(unsigned _txi, h256 _block) const;
	virtual StateDiff diff(unsigned _txi, int _block) const;

	/// Get the remaining gas limit in this block.
	virtual u256 gasLimitRemaining() const { return m_postMine.gasLimitRemaining(); }

	// [PRIVATE API - only relevant for base clients, not available in general]

	dev::eth::State state(unsigned _txi, h256 _block) const;
	dev::eth::State state(h256 _block) const;
	dev::eth::State state(unsigned _txi) const;

	/// Get the object representing the current state of Ethereum.
	dev::eth::State postState() const { ReadGuard l(x_stateDB); return m_postMine; }
	/// Get the object representing the current canonical blockchain.
	CanonBlockChain const& blockChain() const { return m_bc; }

	// Mining stuff:

	/// Check block validity prior to mining.
	bool miningParanoia() const { return m_paranoia; }
	/// Change whether we check block validity prior to mining.
	void setParanoia(bool _p) { m_paranoia = _p; }
	/// Should we force mining to happen, even without transactions?
	bool forceMining() const { return m_forceMining; }
	/// Enable/disable forcing of mining to happen, even without transactions.
	void setForceMining(bool _enable);
	/// Are we mining as fast as we can?
	bool turboMining() const { return m_turboMining; }
	/// Enable/disable fast mining.
	void setTurboMining(bool _enable = true) { m_turboMining = _enable; }


	/// Stops mining and sets the number of mining threads (0 for automatic).
	virtual void setMiningThreads(unsigned _threads = 0);
	/// Get the effective number of mining threads.
	virtual unsigned miningThreads() const { ReadGuard l(x_localMiners); return m_localMiners.size(); }
	/// Start mining.
	/// NOT thread-safe - call it & stopMining only from a single thread
	virtual void startMining() { startWorking(); { ReadGuard l(x_localMiners); for (auto& m: m_localMiners) m.start(); } }
	/// Stop mining.
	/// NOT thread-safe
	virtual void stopMining() { { ReadGuard l(x_localMiners); for (auto& m: m_localMiners) m.stop(); } }
	/// Are we mining now?
	virtual bool isMining() { { ReadGuard l(x_localMiners); if (!m_localMiners.empty() && m_localMiners[0].isRunning()) return true; } return false; }
	/// Check the progress of the mining.
	virtual MineProgress miningProgress() const;
	/// Get and clear the mining history.
	std::list<MineInfo> miningHistory();

	/// Update to the latest transactions and get hash of the current block to be mined minus the
	/// nonce (the 'work hash') and the difficulty to be met.
	virtual std::pair<h256, u256> getWork() override;
	/// Submit the proof for the proof-of-work.
	virtual bool submitWork(ProofOfWork::Proof const& _proof) override;

	// Debug stuff:

	DownloadMan const* downloadMan() const;
	bool isSyncing() const;
	/// Sets the network id.
	void setNetworkId(u256 _n);
	/// Clears pending transactions. Just for debug use.
	void clearPending();
	/// Kills the blockchain. Just for debug use.
	void killChain();
	
	virtual BlockChain const& bc() const { return m_bc; }
	virtual State asOf(int _h) const;
	virtual State preMine() const { return m_preMine; }
	virtual State postMine() const { return m_postMine; }

protected:
	/// Collate the changed filters for the bloom filter of the given pending transaction.
	/// Insert any filters that are activated into @a o_changed.
	void appendFromNewPending(TransactionReceipt const& _receipt, h256Set& io_changed, h256 _sha3);

	/// Collate the changed filters for the hash of the given block.
	/// Insert any filters that are activated into @a o_changed.
	void appendFromNewBlock(h256 const& _blockHash, h256Set& io_changed);

	/// Record that the set of filters @a _filters have changed.
	/// This doesn't actually make any callbacks, but incrememnts some counters in m_watches.
	void noteChanged(h256Set const& _filters);

private:
	/// Do some work. Handles blockchain maintenance and mining.
	virtual void doWork();

	/// Called when Worker is exiting.
	virtual void doneWorking();

	/// Overrides for being a mining host.
	virtual void setupState(State& _s);
	virtual bool turbo() const { return m_turboMining; }
	virtual bool force() const { return m_forceMining; }

	/// Return the actual block number of the block with the given int-number (positive is the same, INT_MIN is genesis block, < 0 is negative age, thus -1 is most recently mined, 0 is pending.
	unsigned numberOf(int _b) const;

	VersionChecker m_vc;					///< Dummy object to check & update the protocol version.
	CanonBlockChain m_bc;					///< Maintains block database.
//	TransactionQueue m_tq;					///< Maintains a list of incoming transactions not yet in a block on the blockchain.
	BlockQueue m_bq;						///< Maintains a list of incoming blocks not yet on the blockchain (to be imported).
	std::shared_ptr<GasPricer> m_gp;		///< The gas pricer.

	mutable SharedMutex x_stateDB;			///< Lock on the state DB, effectively a lock on m_postMine.
	OverlayDB m_stateDB;					///< Acts as the central point for the state database, so multiple States can share it.
	State m_preMine;						///< The present state of the client.
	State m_postMine;						///< The state of the client which we're mining (i.e. it'll have all the rewards added).

	std::weak_ptr<EthereumHost> m_host;		///< Our Ethereum Host. Don't do anything if we can't lock.

	mutable Mutex x_remoteMiner;			///< The remote miner lock.
	RemoteMiner m_remoteMiner;				///< The remote miner.

	std::vector<LocalMiner> m_localMiners;	///< The in-process miners.
	mutable SharedMutex x_localMiners;		///< The in-process miners lock.
	bool m_paranoia = false;				///< Should we be paranoid about our state?
	bool m_turboMining = false;				///< Don't squander all of our time mining actually just sleeping.
	bool m_forceMining = false;				///< Mine even when there are no transactions pending?
	bool m_verifyOwnBlocks = true;			///< Should be verify blocks that we mined?

	mutable std::chrono::system_clock::time_point m_lastGarbageCollection;
};

}
}
