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
/** @file InterfaceStub.cpp
 * @author Marek Kotewicz <marek@ethdev.com>
 * @date 2015
 */

#include <libdevcore/StructuredLogger.h>
#include "InterfaceStub.h"
#include "BlockChain.h"
#include "Executive.h"

using namespace std;
using namespace dev;
using namespace dev::eth;

void InterfaceStub::transact(Secret _secret, u256 _value, Address _dest, bytes const& _data, u256 _gas, u256 _gasPrice)
{
//	startWorking();
	
	u256 n = postMine().transactionsFrom(toAddress(_secret));
	Transaction t(_value, _gasPrice, _gas, _dest, _data, n, _secret);
	m_tq.attemptImport(t.rlp());
	
	StructuredLogger::transactionReceived(t.sha3().abridged(), t.sender().abridged());
	cnote << "New transaction " << t;
}

// TODO: use structured logger here?
Address InterfaceStub::transact(Secret _secret, u256 _endowment, bytes const& _init, u256 _gas, u256 _gasPrice)
{
//	startWorking();
	
	u256 n = postMine().transactionsFrom(toAddress(_secret));
	Transaction t(_endowment, _gasPrice, _gas, _init, n, _secret);
	m_tq.attemptImport(t.rlp());
	
	cnote << "New transaction " << t;
	
	return right160(sha3(rlpList(t.sender(), t.nonce())));
}

void InterfaceStub::flushTransactions()
{
//	doWork();
}

// TODO: this should throw an exception
bytes InterfaceStub::call(Secret _secret, u256 _value, Address _dest, bytes const& _data, u256 _gas, u256 _gasPrice, int _blockNumber)
{
	bytes out;
	try
	{
		State temp = asOf(_blockNumber);
		u256 n = temp.transactionsFrom(toAddress(_secret));
		Transaction t(_value, _gasPrice, _gas, _dest, _data, n, _secret);
		u256 gasUsed = temp.execute(bc(), t.rlp(), &out, false);
		(void)gasUsed; // TODO: do something with gasused which it returns.
	}
	catch (...)
	{
		// TODO: Some sort of notification of failure.
	}
	return out;
}

u256 InterfaceStub::balanceAt(Address _a, int _block) const
{
	return asOf(_block).balance(_a);
}

u256 InterfaceStub::countAt(Address _a, int _block) const
{
	return asOf(_block).transactionsFrom(_a);
}

u256 InterfaceStub::stateAt(Address _a, u256 _l, int _block) const
{
	return asOf(_block).storage(_a, _l);
}

bytes InterfaceStub::codeAt(Address _a, int _block) const
{
	return asOf(_block).code(_a);
}

map<u256, u256> InterfaceStub::storageAt(Address _a, int _block) const
{
	return asOf(_block).storage(_a);
}

// TODO: this should throw an exception
LocalisedLogEntries InterfaceStub::logs(unsigned _watchId) const
{
	LogFilter f;
	try
	{
		Guard l(m_filterLock);
		f = m_filters.at(m_watches.at(_watchId).id).filter;
	}
	catch (...)
	{
		return LocalisedLogEntries();
	}
	return logs(f);
}

LocalisedLogEntries InterfaceStub::logs(LogFilter const& _f) const
{
	LocalisedLogEntries ret;
	unsigned begin = min<unsigned>(bc().number() + 1, (unsigned)_f.latest());
	unsigned end = min(bc().number(), min(begin, (unsigned)_f.earliest()));
	
	// Handle pending transactions differently as they're not on the block chain.
	if (begin > bc().number())
	{
		State temp = postMine();
		for (unsigned i = 0; i < temp.pending().size(); ++i)
		{
			// Might have a transaction that contains a matching log.
			TransactionReceipt const& tr = temp.receipt(i);
			auto th = temp.pending()[i].sha3();
			LogEntries le = _f.matches(tr);
			if (le.size())
				for (unsigned j = 0; j < le.size(); ++j)
					ret.insert(ret.begin(), LocalisedLogEntry(le[j], begin, th));
		}
		begin = bc().number();
	}
	
	set<unsigned> matchingBlocks;
	for (auto const& i: _f.bloomPossibilities())
		for (auto u: bc().withBlockBloom(i, end, begin))
			matchingBlocks.insert(u);

	unsigned falsePos = 0;
	for (auto n: matchingBlocks)
	{
		int total = 0;
		auto h = bc().numberHash(n);
		auto receipts = bc().receipts(h).receipts;
		for (size_t i = 0; i < receipts.size(); i++)
		{
			TransactionReceipt receipt = receipts[i];
			if (_f.matches(receipt.bloom()))
			{
				auto info = bc().info(h);
				auto th = transaction(info.hash, i).sha3();
				LogEntries le = _f.matches(receipt);
				if (le.size())
				{
					total += le.size();
					for (unsigned j = 0; j < le.size(); ++j)
						ret.insert(ret.begin(), LocalisedLogEntry(le[j], n, th));
				}
			}
			
			if (!total)
				falsePos++;
		}
	}

	cdebug << matchingBlocks.size() << "searched from" << (end - begin) << "skipped; " << falsePos << "false +ves";
	return ret;
}

unsigned InterfaceStub::installWatch(LogFilter const& _f, Reaping _r)
{
	h256 h = _f.sha3();
	{
		Guard l(m_filterLock);
		if (!m_filters.count(h))
		{
			cwatch << "FFF" << _f << h.abridged();
			m_filters.insert(make_pair(h, _f));
		}
	}
	return installWatch(h, _r);
}

unsigned InterfaceStub::installWatch(h256 _h, Reaping _r)
{
	unsigned ret;
	{
		Guard l(m_filterLock);
		ret = m_watches.size() ? m_watches.rbegin()->first + 1 : 0;
		m_watches[ret] = ClientWatch(_h, _r);
		cwatch << "+++" << ret << _h.abridged();
	}
	auto ch = logs(ret);
	if (ch.empty())
		ch.push_back(InitialChange);
	{
		Guard l(m_filterLock);
		swap(m_watches[ret].changes, ch);
	}
	return ret;
}

bool InterfaceStub::uninstallWatch(unsigned _i)
{
	cwatch << "XXX" << _i;
	
	Guard l(m_filterLock);
	
	auto it = m_watches.find(_i);
	if (it == m_watches.end())
		return false;
	auto id = it->second.id;
	m_watches.erase(it);
	
	auto fit = m_filters.find(id);
	if (fit != m_filters.end())
		if (!--fit->second.refCount)
		{
			cwatch << "*X*" << fit->first << ":" << fit->second.filter;
			m_filters.erase(fit);
		}
	return true;
}

LocalisedLogEntries InterfaceStub::peekWatch(unsigned _watchId) const
{
	Guard l(m_filterLock);
	
	cwatch << "peekWatch" << _watchId;
	auto& w = m_watches.at(_watchId);
	cwatch << "lastPoll updated to " << chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
	w.lastPoll = chrono::system_clock::now();
	return w.changes;
}

LocalisedLogEntries InterfaceStub::checkWatch(unsigned _watchId)
{
	Guard l(m_filterLock);
	LocalisedLogEntries ret;
	
	cwatch << "checkWatch" << _watchId;
	auto& w = m_watches.at(_watchId);
	cwatch << "lastPoll updated to " << chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
	std::swap(ret, w.changes);
	w.lastPoll = chrono::system_clock::now();
	
	return ret;
}

h256 InterfaceStub::hashFromNumber(unsigned _number) const
{
	return bc().numberHash(_number);
}

BlockInfo InterfaceStub::blockInfo(h256 _hash) const
{
	return BlockInfo(bc().block(_hash));
}

BlockDetails InterfaceStub::blockDetails(h256 _hash) const
{
	return bc().details(_hash);
}

Transaction InterfaceStub::transaction(h256 _transactionHash) const
{
	return Transaction(bc().transaction(_transactionHash), CheckSignature::Range);
}

Transaction InterfaceStub::transaction(h256 _blockHash, unsigned _i) const
{
	auto bl = bc().block(_blockHash);
	RLP b(bl);
	if (_i < b[1].itemCount())
		return Transaction(b[1][_i].data(), CheckSignature::Range);
	else
		return Transaction();
}

Transactions InterfaceStub::transactions(h256 _blockHash) const
{
	auto bl = bc().block(_blockHash);
	RLP b(bl);
	Transactions res;
	for (unsigned i = 0; i < b[1].itemCount(); i++)
		res.emplace_back(b[1][i].data(), CheckSignature::Range);
	return res;
}

TransactionHashes InterfaceStub::transactionHashes(h256 _blockHash) const
{
	return bc().transactionHashes(_blockHash);
}

BlockInfo InterfaceStub::uncle(h256 _blockHash, unsigned _i) const
{
	auto bl = bc().block(_blockHash);
	RLP b(bl);
	if (_i < b[2].itemCount())
		return BlockInfo::fromHeader(b[2][_i].data());
	else
		return BlockInfo();
}

unsigned InterfaceStub::transactionCount(h256 _blockHash) const
{
	auto bl = bc().block(_blockHash);
	RLP b(bl);
	return b[1].itemCount();
}

unsigned InterfaceStub::uncleCount(h256 _blockHash) const
{
	auto bl = bc().block(_blockHash);
	RLP b(bl);
	return b[2].itemCount();
}

unsigned InterfaceStub::number() const
{
	return bc().number();
}

Transactions InterfaceStub::pending() const
{
	return postMine().pending();
}

Addresses InterfaceStub::addresses(int _block) const
{
	Addresses ret;
	for (auto const& i: asOf(_block).addresses())
		ret.push_back(i.first);
	return ret;
}

u256 InterfaceStub::gasLimitRemaining() const
{
	return postMine().gasLimitRemaining();
}


void InterfaceStub::setAddress(Address _us)
{
	preMine().setAddress(_us);
}

Address InterfaceStub::address() const
{
	return preMine().address();
}




