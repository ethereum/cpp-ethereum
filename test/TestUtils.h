
#pragma once

#include <functional>
#include <string>
#include <json/json.h>
#include <libethereum/BlockChain.h>
#include <libethereum/InterfaceStub.h>

namespace dev
{
namespace test
{

class TestUtils
{
public:
	static dev::eth::State toState(Json::Value const& _json);
};

struct LoadTestFileFixture
{
	LoadTestFileFixture();
	
	Json::Value m_json;
};

struct BlockChainFixture: public LoadTestFileFixture
{
	BlockChainFixture() {}
	void enumerateBlockchains(std::function<void(Json::Value const&, dev::eth::BlockChain&, dev::eth::State state)> callback);
};

struct InterfaceStubFixture: public BlockChainFixture
{
	InterfaceStubFixture() {}
	void enumerateInterfaces(std::function<void(Json::Value const&, dev::eth::InterfaceStub&)> callback);
};

}
}
