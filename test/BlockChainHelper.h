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
/** @file BlockChainHelper.h
 * @author Dimitry Khokhlov <dimitry@ethdev.com>
 * @date 2015
 */

#pragma once
#ifndef BLOCKCHAIN_HELPER_HEADER_H
#define BLOCKCHAIN_HELPER_HEADER_H
#include "JsonSpiritHeaders.h"
#include <libethereum/BlockChain.h>
#include <libethereum/TransactionQueue.h>
#include <libdevcore/TransientDirectory.h>
#include <libethcore/Ethash.h>

using namespace std;
using namespace json_spirit;
using namespace dev;
using namespace dev::eth;


namespace dev {  namespace test {

class TestTransaction;
class TestBlock;
class TestBlockChain;

enum class RecalcBlockHeader
{
	Update,				//find new valid nonce and hash
	Verify,				//check that block content is matching header
	UpdateAndVerify,
	SkipVerify
};

class TestTransaction
{
public:
	TestTransaction(json_spirit::mObject const& _o);
	TestTransaction(Transaction const& _tr) : m_transaction(_tr) {}
	Transaction const& getTransaction() const { return m_transaction; }
private:
	json_spirit::mObject m_jsonTransaction;
	Transaction  m_transaction;
};

class TestBlock
{
private:
	typedef Ethash::BlockHeader BlockHeader;

public:
	TestBlock() {};
	TestBlock(TestBlock const& _original);	
	TestBlock(std::string const& _blockRlp);
	TestBlock& operator = (TestBlock const& _original);
	TestBlock(mObject const& _blockObj, mObject const& _stateObj, RecalcBlockHeader _verify);
	void addTransaction(TestTransaction const& _tr);
	void addUncle(TestBlock const& _uncle);
	void setUncles(vector<TestBlock> const& _uncles);
	void mine(TestBlockChain const& bc);

	void setBlockHeader(Ethash::BlockHeader const& _header, RecalcBlockHeader _recalculate);
	void setState(State const& _state);

	bytes const& getBytes() const { return m_bytes; }
	State const& getState() const { return m_state; }
	BlockHeader const& getBlockHeader() const { return m_blockHeader;}
	TransactionQueue const& getTransactionQueue() const { return m_transactionQueue; }
	TransactionQueue & getTransactionQueue() { return m_transactionQueue; }
	vector<TestTransaction> const& getTestTransactions() const { return m_testTransactions; }
	vector<TestBlock> const& getUncles() const { return m_uncles; }
	Address const& getBeneficiary() const { return m_blockHeader.beneficiary(); }

private:
	BlockHeader constructBlock(mObject const& _o, h256 const& _stateRoot);
	bytes createBlockRLPFromFields(mObject const& _tObj, h256 const& _stateRoot = h256{});
	void recalcBlockHeaderBytes(RecalcBlockHeader _recalculate);
	void copyStateFrom(State const& _state);
	void populateFrom(TestBlock const& _original);

private:
	BlockHeader m_blockHeader;
	vector<TestBlock> m_uncles;
	State m_state;
	TransactionQueue m_transactionQueue;
	BlockQueue m_uncleQueue;
	bytes m_bytes;
	TransientDirectory m_tempDirState;
	vector<TestTransaction> m_testTransactions;
};

class TestBlockChain
{
private:
	typedef FullBlockChain<Ethash> FullBlockChainEthash;
public:
	TestBlockChain(TestBlock const& _genesisBlock);
	void addBlock(TestBlock const& _block);
	vector<TestBlock> syncUncles(vector<TestBlock> const& uncles);
	TestBlock const& getTopBlock() { return m_lastBlock; }
	FullBlockChain<Ethash> const& getInterface() const { return *m_blockChain.get();}
	TestBlock const& getTestGenesis() const { return m_genesisBlock; }
private:
	std::unique_ptr<FullBlockChainEthash> m_blockChain;
	TestBlock m_genesisBlock;
	TestBlock m_lastBlock;
	TransientDirectory m_tempDirBlockchain;
};

}}
#endif
