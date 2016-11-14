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
/** @file GenesisInfo.cpp
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 */

#include "GenesisInfo.h"
using namespace dev;
using namespace eth;

static h256 const c_genesisStateRootOlympic;
static std::string const c_genesisInfoOlympic =
R"ETHEREUM(
{
	"sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"homsteadForkBlock": "0xffffffff",
		"maximumExtraDataSize": "0x0400",
		"tieBreakingGas": false,
		"minGasLimit": "125000",
		"maxGasLimit": "7fffffffffffffff",
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x08",
		"blockReward": "0x14D1120D7B160000",
		"registrar": "5e70c0bbcd5636e0f9f9316e9f8633feb64d4050",
		"networkID" : "0x00"
	},
	"genesis": {
		"nonce": "0x000000000000002a",
		"difficulty": "0x20000",
		"mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x",
		"gasLimit": "0x2fefd8"
	},
	"accounts": {
		"0000000000000000000000000000000000000001": { "wei": "1", "precompiled": { "name": "ecrecover", "linear": { "base": 3000, "word": 0 } } },
		"0000000000000000000000000000000000000002": { "wei": "1", "precompiled": { "name": "sha256", "linear": { "base": 60, "word": 12 } } },
		"0000000000000000000000000000000000000003": { "wei": "1", "precompiled": { "name": "ripemd160", "linear": { "base": 600, "word": 120 } } },
		"0000000000000000000000000000000000000004": { "wei": "1", "precompiled": { "name": "identity", "linear": { "base": 15, "word": 3 } } },
		"dbdbdb2cbd23b783741e8d7fcf51e459b497e4a6": { "wei": "1606938044258990275541962092341162602522202993782792835301376" },
		"e6716f9544a56c530d868e4bfbacb172315bdead": { "wei": "1606938044258990275541962092341162602522202993782792835301376" },
		"b9c015918bdaba24b4ff057a92a3873d6eb201be": { "wei": "1606938044258990275541962092341162602522202993782792835301376" },
		"1a26338f0d905e295fccb71fa9ea849ffa12aaf4": { "wei": "1606938044258990275541962092341162602522202993782792835301376" },
		"2ef47100e0787b915105fd5e3f4ff6752079d5cb": { "wei": "1606938044258990275541962092341162602522202993782792835301376" },
		"cd2a3d9f938e13cd947ec05abc7fe734df8dd826": { "wei": "1606938044258990275541962092341162602522202993782792835301376" },
		"6c386a4b26f73c802f34673f7248bb118f97424a": { "wei": "1606938044258990275541962092341162602522202993782792835301376" },
		"e4157b34ea9615cfbde6b4fda419828124b70c78": { "wei": "1606938044258990275541962092341162602522202993782792835301376" }
	}
}
)ETHEREUM";

static h256 const c_genesisStateRootMorden;
static std::string const c_genesisInfoMorden =
R"ETHEREUM(
{
	"sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x0100000",
		"homsteadForkBlock": "0x789b0",
		"maximumExtraDataSize": "0x20",
		"tieBreakingGas": false,
		"minGasLimit": "0x1388",
		"maxGasLimit": "7fffffffffffffff",
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x0d",
		"blockReward": "0x4563918244F40000",
		"registrar": "",
		"networkID" : "0x02",
		"chainID": "0x02"
	},
	"genesis": {
		"nonce": "0x00006d6f7264656e",
		"difficulty": "0x20000",
		"mixHash": "0x00000000000000000000000000000000000000647572616c65787365646c6578",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x",
		"gasLimit": "0x2fefd8"
	},
	"accounts": {
		"0000000000000000000000000000000000000001": { "wei": "1", "precompiled": { "name": "ecrecover", "linear": { "base": 3000, "word": 0 } } },
		"0000000000000000000000000000000000000002": { "wei": "1", "precompiled": { "name": "sha256", "linear": { "base": 60, "word": 12 } } },
		"0000000000000000000000000000000000000003": { "wei": "1", "precompiled": { "name": "ripemd160", "linear": { "base": 600, "word": 120 } } },
		"0000000000000000000000000000000000000004": { "wei": "1", "precompiled": { "name": "identity", "linear": { "base": 15, "word": 3 } } },
		"102e61f5d8f9bc71d0ad4a084df4e65e05ce0e1c": { "wei": "1606938044258990275541962092341162602522202993782792835301376" }
	}
}
)ETHEREUM";

static h256 const c_genesisStateRootFrontierTest;
static std::string const c_genesisInfoFrontierTest =
R"E(
{
	"sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"homsteadForkBlock": "0xffffffffffffffff",
		"daoHardforkBlock": "0xfffffffffffffff",
		"EIP150ForkBlock": "0xfffffffffffffff",
		"EIP158ForkBlock": "0xfffffffffffffff",
		"networkID" : "0x01",
		"chainID": "0x01",
		"maximumExtraDataSize": "0x20",
		"tieBreakingGas": false,
		"minGasLimit": "0x1388",
		"maxGasLimit": "7fffffffffffffff",
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x0d",
		"blockReward": "0x4563918244F40000",
		"registrar" : "0xc6d9d2cd449a754c494264e1809c50e34d64562b"
	},
	"genesis": {
		"nonce": "0x0000000000000042",
		"difficulty": "0x400000000",
		"mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x11bbe8db4e347b4e8c937c1c8370e4b5ed33adb3db69cbdb7a38e1e50b1b82fa",
		"gasLimit": "0x1388"
	},
	"accounts": {
		"0000000000000000000000000000000000000001": { "precompiled": { "name": "ecrecover", "linear": { "base": 3000, "word": 0 } } },
		"0000000000000000000000000000000000000002": { "precompiled": { "name": "sha256", "linear": { "base": 60, "word": 12 } } },
		"0000000000000000000000000000000000000003": { "precompiled": { "name": "ripemd160", "linear": { "base": 600, "word": 120 } } },
		"0000000000000000000000000000000000000004": { "precompiled": { "name": "identity", "linear": { "base": 15, "word": 3 } } }
	}
}
)E";

static h256 const c_genesisStateRootTest;
static std::string const c_genesisInfoTest = std::string() +
R"E(
{
	"sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"homsteadForkBlock": "0x05",
		"daoHardforkBlock": "0x08",
		"EIP150ForkBlock": "0x0a",
		"EIP158ForkBlock": "0x0e",
		"networkID" : "0x01",
		"chainID": "0x01",
		"maximumExtraDataSize": "0x20",
		"tieBreakingGas": false,
		"minGasLimit": "0x1388",
		"maxGasLimit": "7fffffffffffffff",
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x0d",
		"blockReward": "0x4563918244F40000",
		"registrar" : "0xc6d9d2cd449a754c494264e1809c50e34d64562b"
	},
	"genesis": {
		"nonce": "0x0000000000000042",
		"difficulty": "0x400000000",
		"mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x11bbe8db4e347b4e8c937c1c8370e4b5ed33adb3db69cbdb7a38e1e50b1b82fa",
		"gasLimit": "0x1388"
	},
	"accounts": {
		"0000000000000000000000000000000000000001": { "wei": "1", "precompiled": { "name": "ecrecover", "linear": { "base": 3000, "word": 0 } } },
		"0000000000000000000000000000000000000002": { "wei": "1", "precompiled": { "name": "sha256", "linear": { "base": 60, "word": 12 } } },
		"0000000000000000000000000000000000000003": { "wei": "1", "precompiled": { "name": "ripemd160", "linear": { "base": 600, "word": 120 } } },
		"0000000000000000000000000000000000000004": { "wei": "1", "precompiled": { "name": "identity", "linear": { "base": 15, "word": 3 } } }
	}
}
)E";

static h256 const c_genesisStateRootHomesteadTest;
static std::string const c_genesisInfoHomesteadTest = std::string() +
R"E(
{
	"sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"maximumExtraDataSize": "0x20",
		"daoHardforkBlock": "0x1d4c00",
		"EIP150ForkBlock": "0x259518",
		"EIP158ForkBlock": "0x333333",
		"networkID" : "0x01",
		"chainID": "0x01",
		"minGasLimit": "0x1388",
		"maxGasLimit": "7fffffffffffffff",
		"tieBreakingGas": false,
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x0d",
		"blockReward": "0x4563918244F40000",
		"registrar" : "0xc6d9d2cd449a754c494264e1809c50e34d64562b"
	},
	"genesis": {
		"nonce": "0x0000000000000042",
		"difficulty": "0x400000000",
		"mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x11bbe8db4e347b4e8c937c1c8370e4b5ed33adb3db69cbdb7a38e1e50b1b82fa",
		"gasLimit": "0x1388"
	},
	"accounts": {
		"0000000000000000000000000000000000000001": { "wei": "1", "precompiled": { "name": "ecrecover", "linear": { "base": 3000, "word": 0 } } },
		"0000000000000000000000000000000000000002": { "wei": "1", "precompiled": { "name": "sha256", "linear": { "base": 60, "word": 12 } } },
		"0000000000000000000000000000000000000003": { "wei": "1", "precompiled": { "name": "ripemd160", "linear": { "base": 600, "word": 120 } } },
		"0000000000000000000000000000000000000004": { "wei": "1", "precompiled": { "name": "identity", "linear": { "base": 15, "word": 3 } } }
	}
}
)E";

static h256 const c_genesisStateRootEIP150Test;
static std::string const c_genesisInfoEIP150Test = std::string() +
R"E(
{
	"sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"maximumExtraDataSize": "0x20",
		"daoHardforkBlock": "0xfffffffffffffff",
		"EIP150ForkBlock": "0x00",
		"EIP158ForkBlock": "0xfffffffffffffff",
		"networkID" : "0x01",
		"chainID": "0x01",
		"minGasLimit": "0x1388",
		"maxGasLimit": "7fffffffffffffff",
		"tieBreakingGas": false,
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x0d",
		"blockReward": "0x4563918244F40000",
		"registrar" : "0xc6d9d2cd449a754c494264e1809c50e34d64562b"
	},
	"genesis": {
		"nonce": "0x0000000000000042",
		"difficulty": "0x400000000",
		"mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x11bbe8db4e347b4e8c937c1c8370e4b5ed33adb3db69cbdb7a38e1e50b1b82fa",
		"gasLimit": "0x1388"
	},
	"accounts": {
		"0000000000000000000000000000000000000001": { "wei": "1", "precompiled": { "name": "ecrecover", "linear": { "base": 3000, "word": 0 } } },
		"0000000000000000000000000000000000000002": { "wei": "1", "precompiled": { "name": "sha256", "linear": { "base": 60, "word": 12 } } },
		"0000000000000000000000000000000000000003": { "wei": "1", "precompiled": { "name": "ripemd160", "linear": { "base": 600, "word": 120 } } },
		"0000000000000000000000000000000000000004": { "wei": "1", "precompiled": { "name": "identity", "linear": { "base": 15, "word": 3 } } }
	}
}
)E";

static h256 const c_genesisStateRootEIP158Test;
static std::string const c_genesisInfoEIP158Test = std::string() +
R"E(
{
	"sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"maximumExtraDataSize": "0x20",
		"daoHardforkBlock": "0xfffffffffffffff",
		"EIP150ForkBlock": "0x00",
		"EIP158ForkBlock": "0x00",
		"minGasLimit": "0x1388",
		"maxGasLimit": "7fffffffffffffff",
		"tieBreakingGas": false,
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x0d",
		"blockReward": "0x4563918244F40000",
		"registrar" : "0xc6d9d2cd449a754c494264e1809c50e34d64562b",
		"networkID" : "0x1"
	},
	"genesis": {
		"nonce": "0x0000000000000042",
		"difficulty": "0x400000000",
		"mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x11bbe8db4e347b4e8c937c1c8370e4b5ed33adb3db69cbdb7a38e1e50b1b82fa",
		"gasLimit": "0x1388"
	},
	"accounts": {
		"0000000000000000000000000000000000000001": { "wei": "1", "precompiled": { "name": "ecrecover", "linear": { "base": 3000, "word": 0 } } },
		"0000000000000000000000000000000000000002": { "wei": "1", "precompiled": { "name": "sha256", "linear": { "base": 60, "word": 12 } } },
		"0000000000000000000000000000000000000003": { "wei": "1", "precompiled": { "name": "ripemd160", "linear": { "base": 600, "word": 120 } } },
		"0000000000000000000000000000000000000004": { "wei": "1", "precompiled": { "name": "identity", "linear": { "base": 15, "word": 3 } } }
	}
}
)E";

static h256 const c_genesisStateRootFrontier("d7f8974fb5ac78d9ac099b9ad5018bedc2ce0a72dad1827a1709da30580f0544");
static std::string const c_genesisInfoFrontier = std::string() +
R"E(
{
	"sealEngine": "Ethash",
	"params": {
		"accountStartNonce": "0x00",
		"homsteadForkBlock": "0x118c30",
		"daoHardforkBlock": "0x1d4c00",
		"EIP150ForkBlock": "0xfffffffffffffff",
		"EIP158ForkBlock": "0xfffffffffffffff",
		"networkID" : "0x01",
		"chainID": "0x01",
		"maximumExtraDataSize": "0x20",
		"tieBreakingGas": false,
		"minGasLimit": "0x1388",
		"maxGasLimit": "7fffffffffffffff",
		"gasLimitBoundDivisor": "0x0400",
		"minimumDifficulty": "0x020000",
		"difficultyBoundDivisor": "0x0800",
		"durationLimit": "0x0d",
		"blockReward": "0x4563918244F40000",
		"registrar" : "0xc6d9d2cd449a754c494264e1809c50e34d64562b"
	},
	"genesis": {
		"nonce": "0x0000000000000042",
		"difficulty": "0x400000000",
		"mixHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"author": "0x0000000000000000000000000000000000000000",
		"timestamp": "0x00",
		"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
		"extraData": "0x11bbe8db4e347b4e8c937c1c8370e4b5ed33adb3db69cbdb7a38e1e50b1b82fa",
		"gasLimit": "0x1388"
	},
	"accounts": {
		"0000000000000000000000000000000000000001": { "precompiled": { "name": "ecrecover", "linear": { "base": 3000, "word": 0 } } },
		"0000000000000000000000000000000000000002": { "precompiled": { "name": "sha256", "linear": { "base": 60, "word": 12 } } },
		"0000000000000000000000000000000000000003": { "precompiled": { "name": "ripemd160", "linear": { "base": 600, "word": 120 } } },
		"0000000000000000000000000000000000000004": { "precompiled": { "name": "identity", "linear": { "base": 15, "word": 3 } } },
		"3282791d6fd713f1e94f4bfd565eaa78b3a0599d": {
			"balance": "1337000000000000000000"
		},
		"17961d633bcf20a7b029a7d94b7df4da2ec5427f": {
			"balance": "229427000000000000000"
		},
		"493a67fe23decc63b10dda75f3287695a81bd5ab": {
			"balance": "880000000000000000000"
		},
		"01fb8ec12425a04f813e46c54c05748ca6b29aa9": {
			"balance": "259800000000000000000"
		},
		"d2a030ac8952325f9e1db378a71485a24e1b07b2": {
			"balance": "2000000000000000000000"
		},
		"77a34907f305a54c85db09c363fde3c47e6ae21f": {
			"balance": "985000000000000000000"
		},
		"391a77405c09a72b5e8436237aaaf95d68da1709": {
			"balance": "49082000000000000000"
		},
		"00aada25ea2286709abb422d41923fd380cd04c7": {
			"balance": "650100000000000000000"
		},
		"acc46a2a555c74ded4a2bd094e821b97843b40c0": {
			"balance": "1940000000000000000000"
		},
		"de07fb5b7a464e3ba7fbe09e9acb271af5338c58": {
			"balance": "50000000000000000000"
		},
		"4c696be99f3a690440c3436a59a7d7e937d6ba0d": {
			"balance": "3460000000000000000000"
		},
		"fa33553285a973719a0d5f956ff861b2d89ed304": {
			"balance": "20000000000000000000"
		},
		"67cfda6e70bf7657d39059b59790e5145afdbe61": {
			"balance": "646000000000000000000"
		},
		"a321091d3018064279db399d2b2a88a6f440ae24": {
			"balance": "3200000000000000000000"
		},
		"fb3fa1ac08aba9cc3bf0fe9d483820688f65b410": {
			"balance": "30000000000000000000000"
		},
		"6715c14035fb57bb3d667f7b707498c41074b855": {
			"balance": "700000000000000000000"
		},
		"d4344f7d5cad65d17e5c2d0e7323943d6f62fe92": {
			"balance": "267400000000000000000"
		},
		"a3294626ec2984c43b43da4d5d8e4669b11d4b59": {
			"balance": "1008000000000000000000"
		},
		"656018584130db83ab0591a8128d9381666a8d0e": {
			"balance": "63960000000000000000"
		},
		"0fa010ce0c731d3b628e36b91f571300e49dbeab": {
			"balance": "999800000000000000000"
		},
		"3098b65db93ecacaf7353c48808390a223d57684": {
			"balance": "449965000000000000000"
		},
		"ae635bf73831119d2d29c0d04ff8f8d8d0a57a46": {
			"balance": "1337000000000000000000"
		},
		"0f7515ff0e808f695e0c20485ff96ed2f7b79310": {
			"balance": "1000169000000000000000"
		},
		"8b30c04098d7a7e6420c357ea7bfa49bac9a8a18": {
			"balance": "8000200000000000000000"
		},
		"64dba2d6615b8bd7571836dc75bc79d314f5ecee": {
			"balance": "10000000000000000000000"
		},
		"e7912d4cf4562c573ddc5b71e37310e378ef86c9": {
			"balance": "394000000000000000000"
		},
		"a4da34450d22ec0ffcede0004b02f7872ee0b73a": {
			"balance": "93342000000000000000"
		},
		"34437d1465640b136cb5841c3f934f9ba0b7097d": {
			"balance": "173000000000000000000"
		},
		"c652871d192422c6bc235fa063b44a7e1d43e385": {
			"balance": "155000000000000000000"
		},
		"a8a708e84f82db86a35502193b4c6ee9a76ebe8f": {
			"balance": "1015200000000000000000"
		},
		"5c3f567faff7bad1b5120022e8cbcaa82b4917b3": {
			"balance": "2000000000000000000000"
		},
		"dbc1d0ee2bab531140de137722cd36bdb4e47194": {
			"balance": "200000000000000000000"
		},
		"f59dab1bf8df11327e61f9b7a14b563a96ec3554": {
			"balance": "6000000000000000000000"
		},
		"456f8d746682b224679349064d1b368c7c05b176": {
)E" + R"E(
			"balance": "3700000000000000000000"
		},
		"5f13154631466dcb1353c890932a7c97e0878e90": {
			"balance": "6000000000000000000000"
		},
		"f4b1626e24f30bcad9273c527fcc714b5d007b8f": {
			"balance": "200000000000000000000"
		},
		"a8db0b9b201453333c757f6ad9bcb555c02da93b": {
			"balance": "2199970000000000000000"
		},
		"a0fc7e53c5ebd27a2abdac45261f84ab3b51aefb": {
			"balance": "3008250000000000000000"
		},
		"1b636b7a496f044d7359596e353a104616436f6b": {
			"balance": "360354000000000000000"
		},
		"74bce9ec38362d6c94ccac26d5c0e13a8b3b1d40": {
			"balance": "999954000000000000000"
		},
		"9834682180b982d166badb9d9d1d9bbf016d87ee": {
			"balance": "2000000000000000000000"
		},
		"1e6e0153fc161bc05e656bbb144c7187bf4fe84d": {
			"balance": "2000000000000000000000"
		},
		"989c0ccff654da03aeb11af701054561d6297e1d": {
			"balance": "4000000000000000000000"
		},
		"78a1e254409fb1b55a7cb4dd8eba3b30c8bad9ef": {
			"balance": "100000000000000000000"
		},
		"9ef1896b007c32a15114fb89d73dbd47f9122b69": {
			"balance": "4000000000000000000000"
		},
		"33320dd90f2baa110dd334872a998f148426453c": {
			"balance": "999972000000000000000"
		},
		"e72e1d335cc29a96b9b1c02f003a16d971e90b9d": {
			"balance": "1580000000000000000000"
		},
		"0921605f99164e3bcc28f31caece78973182561d": {
			"balance": "793744000000000000000"
		},
		"fc00a420a36107dfd5f495128a5fe5abb2db0f34": {
			"balance": "5960000000000000000000"
		},
		"dfcbdf09454e1a5e4a40d3eef7c5cf1cd3de9486": {
			"balance": "4000000000000000000000"
		},
		"646e043d0597a664948fbb0dc15475a3a4f3a6ed": {
			"balance": "20000000000000000000"
		},
		"79aeb34566b974c35a5881dec020927da7df5d25": {
			"balance": "2000000000000000000000"
		},
		"dbadc61ed5f0460a7f18e51b2fb2614d9264a0e0": {
			"balance": "40000000000000000000"
		},
		"97b91efe7350c2d57e7e406bab18f3617bcde14a": {
			"balance": "9999980000000000000000"
		},
		"8398e07ebcb4f75ff2116de77c1c2a99f303a4cf": {
			"balance": "500000000000000000000"
		},
		"f02796295101674288c1d93467053d042219b794": {
			"balance": "740000000000000000000"
		},
		"f4ed848ec961739c2c7e352f435ba70a7cd5db38": {
			"balance": "1970000000000000000000"
		},
		"82485728d0e281563758c75ab27ed9e882a0002d": {
			"balance": "147000000000000000000"
		},
		"427ec668ac9404e895cc861511d1620a4912be98": {
			"balance": "40000000000000000000000"
		},
		"1bbc199e586790be87afedc849c04726745c5d7b": {
			"balance": "4000000000000000000000"
		},
		"10d945334ecde47beb9ca3816c173dfbbd0b5333": {
			"balance": "1400000000000000000000"
		},
		"1dcebcb7656df5dcaa3368a055d22f9ed6cdd940": {
			"balance": "499800000000000000000"
		},
		"2ac1f8d7bf721f3cfe74d20fea9b87a28aaa982c": {
			"balance": "161000000000000000000"
		},
		"0a47ad9059a249fc936b2662353da6905f75c2b9": {
			"balance": "2000000000000000000000"
		},
		"768498934e37e905f1d0e77b44b574bcf3ec4ae8": {
			"balance": "20000000000000000000000"
		},
		"f46b6b9c7cb552829c1d3dfd8ffb11aabae782f6": {
			"balance": "21000000000000000000"
		},
		"7aea25d42b2612286e99c53697c6bc4100e2dbbf": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"af3615c789d0b1152ad4db25fe5dcf222804cf62": {
			"balance": "1000000000000000000000"
		},
		"92e6581e1da1f9b846e09347333dc818e2d2ac66": {
			"balance": "3640000000000000000000"
		},
		"240305727313d01e73542c775ff59d11cd35f819": {
			"balance": "5931229000000000000000"
		},
		"b95cfda8465ba9c2661b249fc3ab661bdfa35ff0": {
			"balance": "318949000000000000000"
		},
		"1b0d076817e8d68ee2df4e1da1c1142d198c4435": {
			"balance": "1550000000000000000000"
		},
		"93c2e64e5de5589ed25006e843196ee9b1cf0b3e": {
			"balance": "1670000000000000000000"
		},
		"0e2e504a2d1122b5a9feee5cb1451bf4c2ace87b": {
			"balance": "3940000000000000000000"
		},
		"22b96ab2cad55db100b53001f9e4db378104c807": {
			"balance": "10000000000000000000000"
		},
		"a927d48bb6cb814bc609cbcaa9151f5d459a27e1": {
			"balance": "271600000000000000000"
		},
		"5cbd8daf27ddf704cdd0d909a789ba36ed4f37b2": {
			"balance": "13400000000000000000"
		},
		"9adbd3bc7b0afc05d1d2eda49ff863939c48db46": {
			"balance": "199955000000000000000"
		},
		"ac7e03702723cb16ee27e22dd0b815dc2d5cae9f": {
			"balance": "16000000000000000000000"
		},
		"1e210e7047886daa52aaf70f4b991dac68e3025e": {
			"balance": "200000000000000000000"
		},
		"c98048687f2bfcc9bd90ed18736c57edd352b65d": {
			"balance": "1000000000000000000000"
		},
		"81c18c2a238ddc4cba230a072dd7dc101e620273": {
			"balance": "1337000000000000000000"
		},
		"cb3d766c983f192bcecac70f4ee03dd9ff714d51": {
			"balance": "100000000000000000000"
		},
		"44a63d18424587b9b307bfc3c364ae10cd04c713": {
			"balance": "20000000000000000000"
		},
		"4ab2d34f04834fbf7479649cab923d2c4725c553": {
			"balance": "3520000000000000000000"
		},
		"b834acf3015322c58382eeb2b79638906e88b6de": {
			"balance": "24000000000000000000000"
		},
		"7d551397f79a2988b064afd0efebee802c7721bc": {
			"balance": "39400000000000000000000"
		},
		"b537d36a70eeb8d3e5c80de815225c1158cb92c4": {
			"balance": "1500000000000000000000"
		},
		"805ce51297a0793b812067f017b3e7b2df9bb1f9": {
			"balance": "100000000000000000000"
		},
		"085ba65febe23eefc2c802666ab1262382cfc494": {
			"balance": "400000000000000000000"
		},
		"b1c0d08b36e184f9952a4037e3e53a667d070a4e": {
			"balance": "1000000000000000000000"
		},
		"83fe5a1b328bae440711beaf6aad6026eda6d220": {
			"balance": "20000000000000000000000"
		},
		"7fd679e5fb0da2a5d116194dcb508318edc580f3": {
			"balance": "6560000000000000000000"
		},
		"41ad369f758fef38a19aa3149379832c818ef2a0": {
			"balance": "1000060000000000000000"
		},
		"6d846dc12657e91af25008519c3e857f51707dd6": {
			"balance": "4590000000000000000000"
		},
		"c02d6eadeacf1b78b3ca85035c637bb1ce01f490": {
			"balance": "4000000000000000000000"
		},
		"826eb7cd7319b82dd07a1f3b409071d96e39677f": {
			"balance": "1000000000000000000000"
		},
		"4ac9905a4cb6ab1cfd62546ee5917300b87c4fde": {
			"balance": "1015200000000000000000"
		},
		"cf6e52e6b77480b1867efec6446d9fc3cc3577e8": {
			"balance": "222010000000000000000"
		},
		"2476b2bb751ce748e1a4c4ff7b230be0c15d2245": {
			"balance": "4000000000000000000000"
		},
)E" + R"E(
		"1a505e62a74e87e577473e4f3afa16bedd3cfa52": {
			"balance": "500000000000000000000"
		},
		"21d02705f3f64905d80ed9147913ea8c7307d695": {
			"balance": "1363740000000000000000"
		},
		"7b1daf14891b8a1e1bd429d8b36b9a4aa1d9afbf": {
			"balance": "500000000000000000000"
		},
		"5338ef70eac9dd9af5a0503b5efad1039e67e725": {
			"balance": "2674000000000000000000"
		},
		"50ca86b5eb1d01874df8e5f34945d49c6c1ab848": {
			"balance": "1000000000000000000000"
		},
		"f3cc8bcb559465f81bfe583bd7ab0a2306453b9e": {
			"balance": "20000000000000000000000"
		},
		"5c323457e187761a8276e359b7b7af3f3b6e3df6": {
			"balance": "10000000000000000000000"
		},
		"4d82d7700c123bb919419bbaf046799c6b0e2c66": {
			"balance": "20000000000000000000000"
		},
		"8a66abbc2d30ce21a833b0db8e561d5105e0a72c": {
			"balance": "699958000000000000000"
		},
		"2ae53866fc2d14d572ab73b4a065a1188267f527": {
			"balance": "8000000000000000000000"
		},
		"9af5c9894c33e42c2c518e3ac670ea9505d1b53e": {
			"balance": "18200000000000000000"
		},
		"cba25c7a503cc8e0d04971ca05c762f9b762b48b": {
			"balance": "500000000000000000000"
		},
		"fda3042819af3e662900e1b92b4358eda6e92590": {
			"balance": "118200000000000000000000"
		},
		"9bd7c38a4210304a4d653edeff1b3ce45fce7843": {
			"balance": "282000000000000000000"
		},
		"edc22fb92c638e1e21ff5cf039daa6e734dafb29": {
			"balance": "298000000000000000000"
		},
		"a1f193a0592f1feb9fdfc90aa813784eb80471c9": {
			"balance": "1400000000000000000000"
		},
		"e97fde0b67716325cf0ecce8a191a3761b2c791d": {
			"balance": "1004700000000000000000"
		},
		"110237cf9117e767922fc4a1b78d7964da82df20": {
			"balance": "3940000000000000000000"
		},
		"e32f95766d57b5cd4b173289d6876f9e64558194": {
			"balance": "100000000000000000000"
		},
		"f2d59c8923759073d6f415aaf8eb065ff2f3b685": {
			"balance": "7880000000000000000000"
		},
		"c53d79f7cb9b70952fd30fce58d54b9f0b59f647": {
			"balance": "5089200000000000000000"
		},
		"9eb281c32719c40fdb3e216db0f37fbc73a026b7": {
			"balance": "20000000000000000000"
		},
		"2d6511fd7a3800b26854c7ec39c0dcb5f4c4e8e8": {
			"balance": "399910000000000000000"
		},
		"61ba87c77e9b596de7ba0e326fddfeec2163ef66": {
			"balance": "200000000000000000000"
		},
		"de1121829c9a08284087a43fbd2fc1142a3233b4": {
			"balance": "1000000000000000000000"
		},
		"22a25812ab56dcc423175ed1d8adacce33cd1810": {
			"balance": "1850000000000000000000"
		},
		"518cef27b10582b6d14f69483ddaa0dd3c87bb5c": {
			"balance": "600000000000000000000"
		},
		"59161749fedcf1c721f2202d13ade2abcf460b3d": {
			"balance": "2000000000000000000000"
		},
		"3e36c17253c11cf38974ed0db1b759160da63783": {
			"balance": "7000000000000000000000"
		},
		"cbfa76db04ce38fb205d37b8d377cf1380da0317": {
			"balance": "1430000000000000000000"
		},
		"a7e83772bc200f9006aa2a260dbaa8483dc52b30": {
			"balance": "207730000000000000000"
		},
		"e87eac6d602b4109c9671bf57b950c2cfdb99d55": {
			"balance": "49932000000000000000"
		},
		"9b06ad841dffbe4ccf46f1039fc386f3c321446e": {
			"balance": "2000000000000000000000"
		},
		"e0f903c1e48ac421ab48528f3d4a2648080fe043": {
)E" + R"E(
			"balance": "1015200000000000000000"
		},
		"5d872b122e994ef27c71d7deb457bf65429eca6c": {
			"balance": "7999973000000000000000"
		},
		"f34083ecea385017aa40bdd35ef7effb4ce7762d": {
			"balance": "400000000000000000000"
		},
		"7f3709391f3fbeba3592d175c740e87a09541d02": {
			"balance": "480000000000000000000"
		},
		"888e94917083d152202b53163939869d271175b4": {
			"balance": "4000000000000000000000"
		},
		"bed4c8f006a27c1e5f7ce205de75f516bfb9f764": {
			"balance": "16000000000000000000000"
		},
		"b3a6bd41f9d9c3201e050b87198fbda399342210": {
			"balance": "3622615000000000000000"
		},
		"550aadae1221b07afea39fba2ed62e05e5b7b5f9": {
			"balance": "20000000000000000000"
		},
		"bcedc4267ccb89b31bb764d7211171008d94d44d": {
			"balance": "200000000000000000000"
		},
		"6229dcc203b1edccfdf06e87910c452a1f4d7a72": {
			"balance": "32500000000000000000000"
		},
		"94be3ae54f62d663b0d4cc9e1ea8fe9556ea9ebf": {
			"balance": "23280000000000000000"
		},
		"0e0c9d005ea016c295cd795cc9213e87febc33eb": {
			"balance": "198000000000000000000"
		},
		"55d057bcc04bd0f4af9642513aa5090bb3ff93fe": {
			"balance": "1106680000000000000000"
		},
		"ed9e030ca75cb1d29ea01d0d4cdfdccd3844b6e4": {
			"balance": "30895000000000000000"
		},
		"86c4ce06d9ac185bb148d96f7b7abe73f441006d": {
			"balance": "10000000000000000000000"
		},
		"2c04115c3e52961b0dc0b0bf31fba4546f5966fd": {
			"balance": "200000000000000000000"
		},
		"b959dce02e91d9db02b1bd8b7d17a9c41a97af09": {
			"balance": "8000000000000000000000"
		},
		"e01547ba42fcafaf93938becf7699f74290af74f": {
			"balance": "2000000000000000000000"
		},
		"c593d6e37d14b566643ac4135f243caa0787c182": {
			"balance": "12000000000000000000000"
		},
		"2c0ee134d8b36145b47beee7af8d2738dbda08e8": {
			"balance": "201000000000000000000"
		},
		"0ef54ac7264d2254abbb5f8b41adde875157db7c": {
			"balance": "40000000000000000000"
		},
		"0349634dc2a9e80c3f7721ee2b5046aeaaedfbb5": {
			"balance": "4000000000000000000000"
		},
		"873e49135c3391991060290aa7f6ccb8f85a78db": {
			"balance": "20000000000000000000"
		},
		"05236d4c90d065f9e3938358aaffd777b86aec49": {
			"balance": "500000000000000000000"
		},
		"d2abd84a181093e5e229136f42d835e8235de109": {
			"balance": "100007000000000000000"
		},
		"b56a780028039c81caf37b6775c620e786954764": {
			"balance": "2000000000000000000000"
		},
		"86df73bd377f2c09de63c45d67f283eaefa0f4ab": {
			"balance": "1000000000000000000000"
		},
		"7670b02f2c3cf8fd4f4730f3381a71ea431c33c7": {
			"balance": "267400000000000000000"
		},
		"24aa1151bb765fa3a89ca50eb6e1b1c706417fd4": {
			"balance": "3100000000000000000000"
		},
		"43227d65334e691cf231b4a4e1d339b95d598afb": {
			"balance": "10000000000000000000000"
		},
		"695550656cbf90b75d92ad9122d90d23ca68ca4d": {
			"balance": "1000000000000000000000"
		},
		"5281733473e00d87f11e9955e589b59f4ac28e7a": {
			"balance": "660360000000000000000000"
		},
		"99a96bf2242ea1b39ece6fcc0d18aed00c0179f3": {
			"balance": "300000000000000000000"
		},
		"b1cf94f8091505055f010ab4bac696e0ca0f67a1": {
			"balance": "1580000000000000000000"
)E" + R"E(
		},
		"54391b4d176d476cea164e5fb535c69700cb2535": {
			"balance": "100076000000000000000"
		},
		"152f2bd229ddf3cb0fdaf455c183209c0e1e39a2": {
			"balance": "2000000000000000000000"
		},
		"affc99d5ebb4a84fe7788d97dce274b038240438": {
			"balance": "5000000000000000000000"
		},
		"23df8f48ee009256ea797e1fa369beebcf6bc663": {
			"balance": "2302671000000000000000"
		},
		"3a72d635aadeee4382349db98a1813a4cfeb3df1": {
			"balance": "200000000000000000000000"
		},
		"ce26f9a5305f8381094354dbfc92664e84f902b5": {
			"balance": "230200000000000000000"
		},
		"d283b8edb10a25528a4404de1c65e7410dbcaa67": {
			"balance": "12000000000000000000000"
		},
		"a7859fc07f756ea7dcebbccd42f05817582d973f": {
			"balance": "10000000000000000000000"
		},
		"b28181a458a440f1c6bb1de8400281a3148f4c35": {
			"balance": "376000000000000000000"
		},
		"27b1694eafa165ebd7cc7bc99e74814a951419dc": {
			"balance": "800000000000000000000"
		},
		"66cc8ab23c00d1b82acd7d73f38c99e0d05a4fa6": {
			"balance": "100000000000000000000"
		},
		"926082cb7eed4b1993ad245a477267e1c33cd568": {
			"balance": "374300000000000000000"
		},
		"4a47fc3e177f567a1e3893e000e36bba23520ab8": {
			"balance": "2000000000000000000000"
		},
		"594a76f06935388dde5e234696a0668bc20d2ddc": {
			"balance": "2800000000000000000000"
		},
		"e91fa0badaddb9a97e88d3f4db7c55d6bb7430fe": {
			"balance": "376000000000000000000"
		},
		"574de1b3f38d915846ae3718564a5ada20c2f3ed": {
			"balance": "4000000000000000000000"
		},
		"5816c2687777b6d7d2a2432d59a41fa059e3a406": {
			"balance": "133700000000000000000000"
		},
		"b50955aa6e341571986608bdc891c2139f540cdf": {
			"balance": "1970000000000000000000"
		},
		"6d44974a31d187eda16ddd47b9c7ec5002d61fbe": {
			"balance": "940000000000000000000"
		},
		"80abec5aa36e5c9d098f1b942881bd5acac6963d": {
			"balance": "2000000000000000000000"
		},
		"294f494b3f2e143c2ffc9738cbfd9501850b874e": {
			"balance": "2240000000000000000000"
		},
		"bca3ffd4683fba0ad3bbc90734b611da9cfb457e": {
			"balance": "200000000000000000000"
		},
		"5992624c54cdec60a5ae938033af8be0c50cbb0a": {
			"balance": "3621678000000000000000"
		},
		"6560941328ff587cbc56c38c78238a7bb5f442f6": {
			"balance": "744900000000000000000"
		},
		"74b7e0228baed65957aebb4d916d333aae164f0e": {
			"balance": "2000000000000000000000"
		},
		"8516fcaf77c893970fcd1a958ba9a00e49044019": {
			"balance": "196279000000000000000"
		},
		"b992a967308c02b98af91ee760fd3b6b4824ab0e": {
			"balance": "2000000000000000000000"
		},
		"30bb4357cd6910c86d2238bf727cbe8156680e62": {
			"balance": "100014000000000000000"
		},
		"b8cc0f060aad92d4eb8b36b3b95ce9e90eb383d7": {
			"balance": "150000000000000000000000"
		},
		"28d4ebf41e3d3c451e943bdd7e1f175fae932a3d": {
			"balance": "6000000000000000000000"
		},
		"8c83d424a3cf24d51f01923dd54a18d6b6fede7b": {
			"balance": "4000000000000000000000"
		},
		"7efc90766a00bc52372cac97fabd8a3c831f8ecd": {
			"balance": "158000000000000000000"
		},
		"7c2b9603884a4f2e464eceb97d17938d828bc02c": {
			"balance": "3000000000000000000000"
		},
)E" + R"E(
		"9d250ae4f110d71cafc7b0adb52e8d9acb6679b8": {
			"balance": "9840000000000000000000"
		},
		"61b3df2e9e9fd968131f1e88f0a0eb5bd765464d": {
			"balance": "4000000000000000000000"
		},
		"9ae13bd882f2576575921a94974cbea861ba0d35": {
			"balance": "3160000000000000000000"
		},
		"3d09688d93ad07f3abe68c722723cd680990435e": {
			"balance": "29999948000000000000000"
		},
		"5e58e255fc19870a04305ff2a04631f2ff294bb1": {
			"balance": "17600000000000000000"
		},
		"bcaed0acb6a76f113f7c613555a2c3b0f5bf34a5": {
			"balance": "193600000000000000000"
		},
		"159adce27aa10b47236429a34a5ac42cad5b6416": {
			"balance": "31867951000000000000000"
		},
		"e834c64318205ca7dd4a21abcb08266cb21ff02c": {
			"balance": "999999000000000000000"
		},
		"7b6a84718dd86e63338429ac811d7c8a860f21f1": {
			"balance": "1790000000000000000000"
		},
		"2118c116ab0cdf6fd11d54a4309307b477c3fc0f": {
			"balance": "10000000000000000000000"
		},
		"34a901a69f036bcf9f7843c0ba01b426e8c3dc2b": {
			"balance": "4000000000000000000000"
		},
		"c7d44fe32c7f8cd5f1a97427b6cd3afc9e45023e": {
			"balance": "1580000000000000000000"
		},
		"c6045b3c350b4ce9ca0c6b754fb41a69b97e9900": {
			"balance": "925000000000000000000"
		},
		"cf5a6f9df75579c644f794711215b30d77a0ce40": {
			"balance": "2000000000000000000000"
		},
		"e2904b1aefa056398b6234cb35811288d736db67": {
			"balance": "40000000000000000000"
		},
		"7101bd799e411cde14bdfac25b067ac890eab8e8": {
			"balance": "1450054000000000000000"
		},
		"cc45fb3a555bad807b388a0357c855205f7c75e8": {
			"balance": "865000000000000000000"
		},
		"ff0c3c7798e8733dd2668152891bab80a8be955c": {
			"balance": "80220000000000000000"
		},
		"3536453322c1466cb905af5c335ca8db74bff1e6": {
			"balance": "447000000000000000000"
		},
		"08cac8952641d8fc526ec1ab4f2df826a5e7710f": {
			"balance": "300000000000000000000"
		},
		"0d8aab8f74ea862cdf766805009d3f3e42d8d00b": {
			"balance": "5820000000000000000000"
		},
		"8908760cd39b9c1e8184e6a752ee888e3f0b7045": {
			"balance": "6000000000000000000000"
		},
		"8156360bbd370961ceca6b6691d75006ad204cf2": {
			"balance": "40000000000000000000000"
		},
		"a304588f0d850cd8d38f76e9e83c1bf63e333ede": {
			"balance": "39800000000000000000"
		},
		"14c63ba2dcb1dd4df33ddab11c4f0007fa96a62d": {
			"balance": "15500000000000000000000"
		},
		"a009bf076f1ba3fa57d2a7217218bed5565a7a7a": {
			"balance": "1000000000000000000000"
		},
		"1c89060f987c518fa079ec2c0a5ebfa30f5d20f7": {
			"balance": "38000000000000000000000"
		},
		"8895eb726226edc3f78cc6a515077b3296fdb95e": {
			"balance": "3940000000000000000000"
		},
		"7919e7627f9b7d54ea3b14bb4dd4649f4f39dee0": {
			"balance": "1670000000000000000000"
		},
		"b3c65b845aba6cd816fbaae983e0e46c82aa8622": {
			"balance": "1000000000000000000000"
		},
		"eff51d72adfae143edf3a42b1aec55a2ccdd0b90": {
			"balance": "300000000000000000000"
		},
		"05bb64a916be66f460f5e3b64332110d209e19ae": {
			"balance": "4200000000000000000000"
		},
		"d5b117ec116eb846418961eb7edb629cd0dd697f": {
			"balance": "3000000000000000000000"
		},
		"05e97b09492cd68f63b12b892ed1d11d152c0eca": {
)E" + R"E(
			"balance": "1015200000000000000000"
		},
		"84cc7878da605fdb019fab9b4ccfc157709cdda5": {
			"balance": "1336922000000000000000"
		},
		"79cac6494f11ef2798748cb53285bd8e22f97cda": {
			"balance": "2000000000000000000000"
		},
		"bd5a8c94bd8be6470644f70c8f8a33a8a55c6341": {
			"balance": "200000000000000000000"
		},
		"b119e79aa9b916526581cbf521ef474ae84dcff4": {
			"balance": "1470700000000000000000"
		},
		"aff1045adf27a1aa329461b24de1bae9948a698b": {
			"balance": "33400000000000000000"
		},
		"4398628ea6632d393e929cbd928464c568aa4a0c": {
			"balance": "1400000000000000000000"
		},
		"99997668f7c1a4ff9e31f9977ae3224bcb887a85": {
			"balance": "291200000000000000000"
		},
		"bc0e8745c3a549445c2be900f52300804ab56289": {
			"balance": "33104697000000000000000"
		},
		"e5bab4f0afd8a9d1a381b45761aa18f3d3cce105": {
			"balance": "1508010000000000000000"
		},
		"be60037e90714a4b917e61f193d834906703b13a": {
			"balance": "1700000000000000000000"
		},
		"8ed4284c0f47449c15b8d9b3245de8beb6ce80bf": {
			"balance": "800000000000000000000"
		},
		"333ad1596401e05aea2d36ca47318ef4cd2cb3df": {
			"balance": "2910000000000000000000"
		},
		"22db559f2c3c1475a2e6ffe83a5979599196a7fa": {
			"balance": "1000000000000000000000"
		},
		"fdf449f108c6fb4f5a2b081eed7e45e6919e4d25": {
			"balance": "2000000000000000000000"
		},
		"0be1bcb90343fae5303173f461bd914a4839056c": {
			"balance": "6000000000000000000000"
		},
		"b981ad5e6b7793a23fc6c1e8692eb2965d18d0da": {
			"balance": "9999924000000000000000"
		},
		"c75d2259306aec7df022768c69899a652185dbc4": {
			"balance": "4000000000000000000000"
		},
		"6c2e9be6d4ab450fd12531f33f028c614674f197": {
			"balance": "3580000000000000000000"
		},
		"6dcc7e64fcafcbc2dc6c0e5e662cb347bffcd702": {
			"balance": "20000000000000000000000"
		},
		"aabdb35c1514984a039213793f3345a168e81ff1": {
			"balance": "309760000000000000000"
		},
		"d315deea1d8c1271f9d1311263ab47c007afb6f5": {
			"balance": "69760000000000000000"
		},
		"4faf90b76ecfb9631bf9022176032d8b2c207009": {
			"balance": "1000032000000000000000"
		},
		"3e7a966b5dc357ffb07e9fe067c45791fd8e3049": {
			"balance": "59100000000000000000"
		},
		"2e64a8d71111a22f4c5de1e039b336f68d398a7c": {
			"balance": "2000000000000000000000"
		},
		"181fbba852a7f50178b1c7f03ed9e58d54162929": {
			"balance": "666000000000000000000"
		},
		"4f7330096f79ed264ee0127f5d30d2f73c52b3d8": {
			"balance": "499970000000000000000"
		},
		"a8a8dbdd1a85d1beee2569e91ccc4d09ae7f6ea1": {
			"balance": "5800000000000000000000"
		},
		"1f9c3268458da301a2be5ab08257f77bb5a98aa4": {
			"balance": "200000000000000000000"
		},
		"fc372ff6927cb396d9cf29803500110da632bc52": {
			"balance": "2000000000000000000000"
		},
		"4fa554ab955c249217386a4d3263bbf72895434e": {
			"balance": "19982000000000000000"
		},
		"2a59e47ea5d8f0e7c028a3e8e093a49c1b50b9a3": {
			"balance": "2000000000000000000000"
		},
		"5e32c72191b8392c55f510d8e3326e3a60501d62": {
			"balance": "44000000000000000000000"
		},
		"1dfaee077212f1beaf0e6f2f1840537ae154ad86": {
			"balance": "1000000000000000000000"
)E" + R"E(
		},
		"7eaba035e2af3793fd74674b102540cf190addb9": {
			"balance": "1273000000000000000000"
		},
		"d62edb96fce2969aaf6c545e967cf1c0bc805205": {
			"balance": "85705000000000000000"
		},
		"220dc68df019b6b0ccbffb784b5a5ab4b15d4060": {
			"balance": "3940000000000000000000"
		},
		"45bb829652d8bfb58b8527f0ecb621c29e212ec3": {
			"balance": "2000000000000000000000"
		},
		"79b120eb8806732321288f675a27a9225f1cd2eb": {
			"balance": "2465000000000000000000"
		},
		"740af1eefd3365d78ba7b12cb1a673e06a077246": {
			"balance": "19700000000000000000000"
		},
		"0f042c9c2fb18766f836bb59f735f27dc329fe3c": {
			"balance": "10000000000000000000000"
		},
		"6dda5f788a6c688ddf921fa3852eb6d6c6c62966": {
			"balance": "40000000000000000000"
		},
		"96ad579bbfa8db8ebec9d286a72e4661eed8e356": {
			"balance": "1070750000000000000000"
		},
		"0c2073ba44d3ddbdb639c04e191039a71716237f": {
			"balance": "1430000000000000000000"
		},
		"1a3520453582c718a21c42375bc50773255253e1": {
			"balance": "790000000000000000000"
		},
		"efcaae9ff64d2cd95b5249dcffe7faa0a0c0e44d": {
			"balance": "401100000000000000000"
		},
		"0a3de155d5ecd8e81c1ff9bbf0378301f8d4c623": {
			"balance": "4000000000000000000000"
		},
		"80f07ac09e7b2c3c0a3d1e9413a544c73a41becb": {
			"balance": "20000000000000000000"
		},
		"c3631c7698b6c5111989bf452727b3f9395a6dea": {
			"balance": "10683500000000000000000"
		},
		"4cc22c9bc9ad05d875a397dbe847ed221c920c67": {
			"balance": "2000000000000000000000"
		},
		"1a987e3f83de75a42f1bde7c997c19217b4a5f24": {
			"balance": "2000000000000000000000"
		},
		"5b2b64e9c058e382a8b299224eecaa16e09c8d92": {
			"balance": "161000000000000000000"
		},
		"86caafacf32aa0317c032ac36babed974791dc03": {
			"balance": "40000000000000000000000"
		},
		"1cd1f0a314cbb200de0a0cb1ef97e920709d97c2": {
			"balance": "2000000000000000000000"
		},
		"7d980f4b566bb045517e4c14c87750de9346744b": {
			"balance": "1337000000000000000000"
		},
		"8b5f29cc2faa262cdef30ef554f50eb488146eac": {
			"balance": "5818250000000000000000"
		},
		"5153a0c3c8912881bf1c3501bf64b45649e48222": {
			"balance": "4000000000000000000000"
		},
		"d21a7341eb84fd151054e5e387bb25d36e499c09": {
			"balance": "14000000000000000000000"
		},
		"9560e8ac6718a6a1cdcff189d603c9063e413da6": {
			"balance": "4000000000000000000000"
		},
		"e49ba0cd96816c4607773cf8a5970bb5bc16a1e6": {
			"balance": "1670000000000000000000"
		},
		"b8ac117d9f0dba80901445823c4c9d4fa3fedc6e": {
			"balance": "15759015000000000000000"
		},
		"af67fd3e127fd9dc36eb3fcd6a80c7be4f7532b2": {
			"balance": "1670000000000000000000"
		},
		"b43c27f7a0a122084b98f483922541c8836cee2c": {
			"balance": "715000000000000000000"
		},
		"4d9279962029a8bd45639737e98b511eff074c21": {
			"balance": "1337000000000000000000"
		},
		"c667441e7f29799aba616451d53b3f489f9e0f48": {
			"balance": "13920000000000000000000"
		},
		"275875ff4fbb0cf3a430213127487f7608d04cba": {
			"balance": "500080000000000000000"
		},
		"9a953b5bcc709379fcb559d7b916afdaa50cadcc": {
			"balance": "100000000000000000000"
		},
)E" + R"E(
		"7ea791ebab0445a00efdfc4e4a8e9a7e7565136d": {
			"balance": "18200000000000000000"
		},
		"6ffe5cf82cc9ea5e36cad7c2974ce7249f3749e6": {
			"balance": "1940000000000000000000"
		},
		"f1b4ecc63525f7432c3d834ffe2b970fbeb87212": {
			"balance": "3000064000000000000000"
		},
		"6b72a8f061cfe6996ad447d3c72c28c0c08ab3a7": {
			"balance": "4271316000000000000000"
		},
		"bba3c68004248e489573abb2743677066b24c8a7": {
			"balance": "2000000000000000000000"
		},
		"b7c0d0cc0b4d342d4062bac624ccc3c70cc6da3f": {
			"balance": "4000000000000000000000"
		},
		"fe98c664c3e447a95e69bd582171b7176ea2a685": {
			"balance": "4000000000000000000000"
		},
		"ce71086d4c602554b82dcbfce88d20634d53cc4d": {
			"balance": "43250000000000000000000"
		},
		"1c601993789207f965bb865cbb4cd657cce76fc0": {
			"balance": "98294000000000000000"
		},
		"476b5599089a3fb6f29c6c72e49b2e4740ea808d": {
			"balance": "2800000000000000000000"
		},
		"3439998b247cb4bf8bc80a6d2b3527f1dfe9a6d2": {
			"balance": "140000000000000000000"
		},
		"c4f7d2e2e22084c44f70feaab6c32105f3da376f": {
			"balance": "1970000000000000000000"
		},
		"c1eba5684aa1b24cba63150263b7a9131aeec28d": {
			"balance": "20000000000000000000"
		},
		"94ad4bad824bd0eb9ea49c58cebcc0ff5e08346b": {
			"balance": "1940000000000000000000"
		},
		"ded877378407b94e781c4ef4af7cfc5bc220b516": {
			"balance": "372500000000000000000"
		},
		"699c9ee47195511f35f862ca4c22fd35ae8ffbf4": {
			"balance": "80000000000000000000"
		},
		"e3a89a1927cc4e2d43fbcda1e414d324a7d9e057": {
			"balance": "205500000000000000000"
		},
		"4d93696fa24859f5d2939aebfa54b4b51ae1dccc": {
			"balance": "19100000000000000000"
		},
		"0af65f14784e55a6f95667fd73252a1c94072d2a": {
			"balance": "192987000000000000000"
		},
		"5b70c49cc98b3df3fbe2b1597f5c1b6347a388b7": {
			"balance": "970000000000000000000"
		},
		"426f78f70db259ac8534145b2934f4ef1098b5d8": {
			"balance": "360000000000000000000"
		},
		"58b8ae8f63ef35ed0762f0b6233d4ac14e64b64d": {
			"balance": "2000000000000000000000"
		},
		"8eae29435598ba8f1c93428cdb3e2b4d31078e00": {
			"balance": "2000000000000000000000"
		},
		"17fd9b551a98cb61c2e07fbf41d3e8c9a530cba5": {
			"balance": "26989000000000000000"
		},
		"ab3e78294ba886a0cfd5d3487fb3a3078d338d6e": {
			"balance": "1970000000000000000000"
		},
		"bdf6e68c0cd7584080e847d72cbb23aad46aeb1d": {
			"balance": "1970000000000000000000"
		},
		"f989346772995ec1906faffeba2a7fe7de9c6bab": {
			"balance": "6685000000000000000000"
		},
		"dc5f5ad663a6f263327d64cac9cb133d2c960597": {
			"balance": "2000000000000000000000"
		},
		"68fe1357218d095849cd579842c4aa02ff888d93": {
			"balance": "2000000000000000000000"
		},
		"e09c68e61998d9c81b14e4ee802ba7adf6d74cdb": {
			"balance": "4000000000000000000000"
		},
		"890fe11f3c24db8732d6c2e772e2297c7e65f139": {
			"balance": "62980000000000000000000"
		},
		"a76929890a7b47fb859196016c6fdd8289ceb755": {
			"balance": "5000000000000000000000"
		},
		"2dc79d6e7f55bce2e2d0c02ad07ceca8bb529354": {
			"balance": "1580000000000000000000"
		},
		"19687daa39c368139b6e7be60dc1753a9f0cbea3": {
)E" + R"E(
			"balance": "8000000000000000000000"
		},
		"c69be440134d6280980144a9f64d84748a37f349": {
			"balance": "715000000000000000000"
		},
		"3d8d0723721e73a6c0d860aa0557abd14c1ee362": {
			"balance": "5000000000000000000000"
		},
		"2b241f037337eb4acc61849bd272ac133f7cdf4b": {
			"balance": "378000000000000000000000"
		},
		"24b95ebef79500baa0eda72e77f877415df75c33": {
			"balance": "910000000000000000000"
		},
		"106ed5c719b5261477890425ae7551dc59bd255c": {
			"balance": "11979600000000000000000"
		},
		"5b2e2f1618552eab0db98add55637c2951f1fb19": {
			"balance": "12000000000000000000000"
		},
		"403145cb4ae7489fcc90cd985c6dc782b3cc4e44": {
			"balance": "5999800000000000000000"
		},
		"e8be24f289443ee473bc76822f55098d89b91cc5": {
			"balance": "2000000000000000000000"
		},
		"f6bc37b1d2a3788d589b6de212dc1713b2f6e78e": {
			"balance": "5000000000000000000000"
		},
		"67fc527dce1785f0fb8bc7e518b1c669f7ecdfb5": {
			"balance": "240000000000000000000"
		},
		"6580b1bc94390f04b397bd73e95d96ef11eaf3a8": {
			"balance": "20000000000000000000"
		},
		"98bf4af3810b842387db70c14d46099626003d10": {
			"balance": "4000000000000000000000"
		},
		"17993d312aa1106957868f6a55a5e8f12f77c843": {
			"balance": "450065000000000000000"
		},
		"0729b4b47c09eb16158464c8aa7fd9690b438839": {
			"balance": "1999800000000000000000"
		},
		"ae70e69d2c4a0af818807b1a2705f79fd0b5dbc4": {
			"balance": "985000000000000000000"
		},
		"38b50146e71916a5448de12a4d742135dcf39833": {
			"balance": "32200000000000000000000"
		},
		"38439aaa24e3636f3a18e020ea1da7e145160d86": {
			"balance": "2600000000000000000000"
		},
		"54b4429b182f0377be7e626939c5db6440f75d7a": {
			"balance": "1970000000000000000000"
		},
		"7179726f5c71ae1b6d16a68428174e6b34b23646": {
			"balance": "7353500000000000000000"
		},
		"c2ee91d3ef58c9d1a589844ea1ae3125d6c5ba69": {
			"balance": "970000000000000000000"
		},
		"912304118b80473d9e9fe3ee458fbe610ffda2bb": {
			"balance": "200000000000000000000"
		},
		"3308b03466c27a17dfe1aafceb81e16d2934566f": {
			"balance": "17000000000000000000000"
		},
		"10346414bec6d3dcc44e50e54d54c2b8c3734e3e": {
			"balance": "4000000000000000000000"
		},
		"4fee50c5f988206b09a573469fb1d0b42ebb6dce": {
			"balance": "2009400000000000000000"
		},
		"9ece1400800936c7c6485fcdd3626017d09afbf6": {
			"balance": "310000000000000000000"
		},
		"ddf3ad76353810be6a89d731b787f6f17188612b": {
			"balance": "20000000000000000000000"
		},
		"72402300e81d146c2e644e2bbda1da163ca3fb56": {
			"balance": "7000000000000000000000"
		},
		"bb4b4a4b548070ff41432c9e08a0ca6fa7bc9f76": {
			"balance": "850000000000000000000"
		},
		"c3dd58903886303b928625257ae1a013d71ae216": {
			"balance": "2000000000000000000000"
		},
		"ca6c818befd251361e02744068be99d8aa60b84a": {
			"balance": "6000000000000000000000"
		},
		"b8d2ddc66f308c0158ae3ccb7b869f7d199d7b32": {
			"balance": "844800000000000000000"
		},
		"8e486a0442d171c8605be348fee57eb5085eff0d": {
			"balance": "4000000000000000000000"
		},
		"a807104f2703d679f8deafc442befe849e42950b": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"bb61a04bffd57c10470d45c39103f64650347616": {
			"balance": "1000000000000000000000"
		},
		"d1c45954a62b911ad701ff2e90131e8ceb89c95c": {
			"balance": "1394000000000000000000"
		},
		"5e65458be964ae449f71773704979766f8898761": {
			"balance": "528600000000000000000"
		},
		"f9b37825f03073d31e249378c30c795c33f83af2": {
			"balance": "200152000000000000000"
		},
		"e309974ce39d60aadf2e69673251bf0e04760a10": {
			"balance": "254030000000000000000"
		},
		"d541ac187ad7e090522de6da3213e9a7f4439673": {
			"balance": "2000000000000000000000"
		},
		"f33efc6397aa65fb53a8f07a0f893aae30e8bcee": {
			"balance": "2304850000000000000000"
		},
		"d2f1998e1cb1580cec4f6c047dcd3dcec54cf73c": {
			"balance": "200000000000000000000"
		},
		"0ed76c2c3b5d50ff8fb50b3eeacd681590be1c2d": {
			"balance": "100000000000000000000"
		},
		"637d67d87f586f0a5a479e20ee13ea310a10b647": {
			"balance": "48300000000000000000000"
		},
		"1a5ee533acbfb3a2d76d5b685277b796c56a052b": {
			"balance": "2000000000000000000000"
		},
		"323fca5ed77f699f9d9930f5ceeff8e56f59f03c": {
			"balance": "1337000000000000000000"
		},
		"a5fe2ce97f0e8c3856be0de5f4dcb2ce5d389a16": {
			"balance": "22892000000000000000"
		},
		"93258255b37c7f58f4b10673a932dd3afd90f4f2": {
			"balance": "1000000000000000000000"
		},
		"950fe9c6cad50c18f11a9ed9c45740a6180612d0": {
			"balance": "8000000000000000000000"
		},
		"ee31167f9cc93b3c6465609d79db0cde90e8484c": {
			"balance": "2000000000000000000000"
		},
		"6ebb5e6957aa821ef659b6018a393a504cae4450": {
			"balance": "2000000000000000000000"
		},
		"be305a796e33bbf7f9aeae6512959066efda1010": {
			"balance": "10880000000000000000000"
		},
		"537f9d4d31ef70839d84b0d9cdb72b9afedbdf35": {
			"balance": "70000000000000000000000"
		},
		"fe9e1197d7974a7648dcc7a03112a88edbc9045d": {
			"balance": "4925000000000000000000"
		},
		"99f77f998b20e0bcdcd9fc838641526cf25918ef": {
			"balance": "1790000000000000000000"
		},
		"76ffc157ad6bf8d56d9a1a7fddbc0fea010aabf4": {
			"balance": "1000000000000000000000"
		},
		"defe9141f4704599159d7b223de42bffd80496b3": {
			"balance": "100000000000000000000"
		},
		"7b1bf53a9cbe83a7dea434579fe72aac8d2a0cd0": {
			"balance": "199800000000000000000"
		},
		"23ccc3c6acd85c2e460c4ffdd82bc75dc849ea14": {
			"balance": "4000000000000000000000"
		},
		"9f86a066edb61fcb5856de93b75c8c791864b97b": {
			"balance": "2000000000000000000000"
		},
		"871b8a8b51dea1989a5921f13ec1a955a515ad47": {
			"balance": "8000000000000000000000"
		},
		"4efcd9c79fb4334ca6247b0a33bd9cc33208e272": {
			"balance": "1337000000000000000000"
		},
		"35ac1d3ed7464fa3db14e7729213ceaa378c095e": {
			"balance": "1520000000000000000000"
		},
		"c69d663c8d60908391c8d236191533fdf7775613": {
			"balance": "485000000000000000000"
		},
		"c2ed5ffdd1add855a2692fe062b5d618742360d4": {
			"balance": "1200000000000000000000"
		},
		"454f0141d721d33cbdc41018bd01119aa4784818": {
			"balance": "6000000000000000000000"
		},
		"6c8687e3417710bb8a93559021a1469e6a86bc77": {
			"balance": "11126675000000000000000"
		},
)E" + R"E(
		"ec5b198a00cfb55a97b5d53644cffa8a04d2ab45": {
			"balance": "2000000000000000000000"
		},
		"cd59f3dde77e09940befb6ee58031965cae7a336": {
			"balance": "10000000000000000000000"
		},
		"8eebec1a62c08b05a7d1d59180af9ff0d18e3f36": {
			"balance": "500000000000000000000"
		},
		"92a971a739799f8cb48ea8475d72b2d2474172e6": {
			"balance": "3940000000000000000000"
		},
		"bed4649df646e2819229032d8868556fe1e053d3": {
			"balance": "18200000000000000000"
		},
		"c50fe415a641b0856c4e75bf960515441afa358d": {
			"balance": "2000000000000000000000"
		},
		"91f516146cda20281719978060c6be4149067c88": {
			"balance": "2000000000000000000000"
		},
		"54a1370116fe22099e015d07cd2669dd291cc9d1": {
			"balance": "20000000000000000000"
		},
		"80c04efd310f440483c73f744b5b9e64599ce3ec": {
			"balance": "1200000000000000000000"
		},
		"a8914c95b560ec13f140577338c32bcbb77d3a7a": {
			"balance": "180000000000000000000"
		},
		"e3c812737ac606baf7522ad817428a36050e7a34": {
			"balance": "1940000000000000000000"
		},
		"6d1456fff0104ee844a3314737843338d24cd66c": {
			"balance": "141840000000000000000"
		},
		"0e6ece99111cad1961c748ed3df51edd69d2a3b1": {
			"balance": "100000000000000000000000"
		},
		"019d709579ff4bc09fdcdde431dc1447d2c260bc": {
			"balance": "20000000000000000000"
		},
		"ebff84bbef423071e604c361bba677f5593def4e": {
			"balance": "10000000000000000000000"
		},
		"e10c540088113fa6ec00b4b2c8824f8796e96ec4": {
			"balance": "236400000000000000000000"
		},
		"e03220c697bcd28f26ef0b74404a8beb06b2ba7b": {
			"balance": "8000000000000000000000"
		},
		"e69a6cdb3a8a7db8e1f30c8b84cd73bae02bc0f8": {
			"balance": "16915503000000000000000"
		},
		"e5fb31a5caee6a96de393bdbf89fbe65fe125bb3": {
			"balance": "1000000000000000000000"
		},
		"030fb3401f72bd3418b7d1da75bf8c519dd707dc": {
			"balance": "3000000000000000000000"
		},
		"1c751e7f24df9d94a637a5dedeffc58277b5db19": {
			"balance": "3220000000000000000000"
		},
		"bded7e07d0711e684de65ac8b2ab57c55c1a8645": {
			"balance": "591000000000000000000"
		},
		"dd7ff441ba6ffe3671f3c0dabbff1823a5043370": {
			"balance": "2000000000000000000000"
		},
		"b55474ba58f0f2f40e6cbabed4ea176e011fcad6": {
			"balance": "1970000000000000000000"
		},
		"b92427ad7578b4bfe20a9f63a7c5506d5ca12dc8": {
			"balance": "2000000000000000000000"
		},
		"91a8baaed012ea2e63803b593d0d0c2aab4c5b0a": {
			"balance": "1500000000000000000000"
		},
		"a97e072144499fe5ebbd354acc7e7efb58985d08": {
			"balance": "2674000000000000000000"
		},
		"75c2ffa1bef54919d2097f7a142d2e14f9b04a58": {
			"balance": "2673866000000000000000"
		},
		"53faf165be031ec18330d9fce5bd1281a1af08db": {
			"balance": "140000000000000000000"
		},
		"055ab658c6f0ed4f875ed6742e4bc7292d1abbf0": {
			"balance": "83500000000000000000"
		},
		"6f18ec767e320508195f1374500e3f2e125689ff": {
			"balance": "1000000000000000000000"
		},
		"90fc537b210658660a83baa9ac4a8402f65746a8": {
			"balance": "1880000000000000000000"
		},
		"34664d220fa7f37958024a3332d684bcc6d4c8bd": {
			"balance": "10000000000000000000000"
		},
		"15acb61568ec4af7ea2819386181b116a6c5ee70": {
)E" + R"E(
			"balance": "31000000000000000000000"
		},
		"69d98f38a3ba3dbc01fa5c2c1427d862832f2f70": {
			"balance": "100000000000000000000000"
		},
		"ece1152682b7598fe2d1e21ec15533885435ac85": {
			"balance": "4000000000000000000000"
		},
		"f618d9b104411480a863e623fc55232d1a4f48aa": {
			"balance": "265793000000000000000"
		},
		"f9debaecb5f339beea4894e5204bfa340d067f25": {
			"balance": "1665000000000000000000"
		},
		"5e731b55ced452bb3f3fe871ddc3ed7ee6510a8f": {
			"balance": "3000000000000000000000"
		},
		"67df242d240dd4b8071d72f8fcf35bb3809d71e8": {
			"balance": "4000000000000000000000"
		},
		"c4cf930e5d116ab8d13b9f9a7ec4ab5003a6abde": {
			"balance": "320000000000000000000"
		},
		"01a25a5f5af0169b30864c3be4d7563ccd44f09e": {
			"balance": "1430000000000000000000"
		},
		"7f6efb6f4318876d2ee624e27595f44446f68e93": {
			"balance": "1550000000000000000000"
		},
		"82249fe70f61c6b16f19a324840fdc020231bb02": {
			"balance": "9504014000000000000000"
		},
		"205237c4be146fba99478f3a7dad17b09138da95": {
			"balance": "2000000000000000000000"
		},
		"fd1fb5a89a89a721b8797068fbc47f3e9d52e149": {
			"balance": "236400000000000000000"
		},
		"e47fbaed99fc209962604ebd20e240f74f4591f1": {
			"balance": "2000000000000000000000"
		},
		"a24c3ab62181e9a15b78c4621e4c7c588127be26": {
			"balance": "162410000000000000000"
		},
		"b6cd7432d5161be79768ad45de3e447a07982063": {
			"balance": "4000000000000000000000"
		},
		"32a70691255c9fc9791a4f75c8b81f388e0a2503": {
			"balance": "985000000000000000000"
		},
		"562f16d79abfcec3943e34b20f05f97bdfcda605": {
			"balance": "4000000000000000000000"
		},
		"dbc66965e426ff1ac87ad6eb78c1d95271158f9f": {
			"balance": "18200000000000000000"
		},
		"7e87863ec43a481df04d017762edcb5caa629b5a": {
			"balance": "39400000000000000000"
		},
		"587d6849b168f6c3332b7abae7eb6c42c37f48bf": {
			"balance": "880000000000000000000"
		},
		"721158be5762b119cc9b2035e88ee4ee78f29b82": {
			"balance": "10000000000000000000000"
		},
		"84b91e2e2902d05e2b591b41083bd7beb2d52c74": {
			"balance": "9848621000000000000000"
		},
		"632cecb10cfcf38ec986b43b8770adece9200221": {
			"balance": "20000000000000000000"
		},
		"c34e3ba1322ed0571183a24f94204ee49c186641": {
			"balance": "58200000000000000000"
		},
		"ae78bb849139a6ba38ae92a09a69601cc4cb62d1": {
			"balance": "500000000000000000000"
		},
		"5ce0b6862cce9162e87e0849e387cb5df4f9118c": {
			"balance": "1670000000000000000000"
		},
		"f52c0a7877345fe0c233bb0f04fd6ab18b6f14ba": {
			"balance": "400440000000000000000000"
		},
		"e016dc138e25815b90be3fe9eee8ffb2e105624f": {
			"balance": "500000000000000000000"
		},
		"5789d01db12c816ac268e9af19dc0dd6d99f15df": {
			"balance": "200000000000000000000"
		},
		"d8b77db9b81bbe90427b62f702b201ffc29ff618": {
			"balance": "930200000000000000000"
		},
		"5dff811dad819ece3ba602c383fb5dc64c0a3a48": {
			"balance": "186000000000000000000"
		},
		"af3087e62e04bf900d5a54dc3e946274da92423b": {
			"balance": "20000000000000000000"
		},
		"8c1023fde1574db8bb54f1739670157ca47da652": {
			"balance": "6969382000000000000000"
)E" + R"E(
		},
		"bb3b010b18e6e2be1135871026b7ba15ea0fde24": {
			"balance": "10044000000000000000000"
		},
		"cabdaf354f4720a466a764a528d60e3a482a393c": {
			"balance": "1000000000000000000000"
		},
		"94bbc67d13f89ebca594be94bc5170920c30d9f3": {
			"balance": "80200000000000000000"
		},
		"3275496fd4dd8931fd69fb0a0b04c4d1ff879ef5": {
			"balance": "446000000000000000000"
		},
		"281250a29121270a4ee5d78d24feafe82c70ba3a": {
			"balance": "1000000000000000000000"
		},
		"590ccb5911cf78f6f622f535c474375f4a12cfcf": {
			"balance": "20000000000000000000000"
		},
		"542e8096bafb88162606002e8c8a3ed19814aeac": {
			"balance": "2000000000000000000000"
		},
		"a65426cff378ed23253513b19f496de45fa7e18f": {
			"balance": "7200000000000000000000"
		},
		"4aa693b122f314482a47b11cc77c68a497876162": {
			"balance": "1970000000000000000000"
		},
		"d9b783d31d32adc50fa3eacaa15d92b568eaeb47": {
			"balance": "34010000000000000000000"
		},
		"068e655766b944fb263619658740b850c94afa31": {
			"balance": "35200000000000000000"
		},
		"9e23c5e4b782b00a5fadf1aead87dacf5b0367a1": {
			"balance": "20000000000000000000"
		},
		"bf17f397f8f46f1bae45d187148c06eeb959fa4d": {
			"balance": "1001440000000000000000"
		},
		"8578e10212ca14ff0732a8241e37467db85632a9": {
			"balance": "6000000000000000000000"
		},
		"2cb5495a505336c2465410d1cae095b8e1ba5cdd": {
			"balance": "20000000000000000000000"
		},
		"695b0f5242753701b264a67071a2dc880836b8db": {
			"balance": "16400000000000000000"
		},
		"f2edde37f9a8c39ddea24d79f4015757d06bf786": {
			"balance": "100000000000000000000000"
		},
		"480f31b989311e4124c6a7465f5a44094d36f9d0": {
			"balance": "1025000000000000000000"
		},
		"cf157612764e0fd696c8cb5fba85df4c0ddc3cb0": {
			"balance": "30000000000000000000000"
		},
		"27521deb3b6ef1416ea4c781a2e5d7b36ee81c61": {
			"balance": "2000000000000000000000"
		},
		"6efd90b535e00bbd889fda7e9c3184f879a151db": {
			"balance": "10100000000000000000000"
		},
		"b635a4bc71fb28fdd5d2c322983a56c284426e69": {
			"balance": "170000000000000000000"
		},
		"a17c9e4323069518189d5207a0728dcb92306a3f": {
			"balance": "1000000000000000000000"
		},
		"6af940f63ec9b8d876272aca96fef65cdacecdea": {
			"balance": "3000000000000000000000"
		},
		"469358709332c82b887e20bcddd0220f8edba7d0": {
			"balance": "17300000000000000000000"
		},
		"a257ad594bd88328a7d90fc0a907df95eecae316": {
			"balance": "520510000000000000000"
		},
		"6f051666cb4f7bd2b1907221b829b555d7a3db74": {
			"balance": "1760000000000000000000"
		},
		"46bfc5b207eb2013e2e60f775fecd71810c5990c": {
			"balance": "1550000000000000000000"
		},
		"62b9081e7710345e38e02e16449ace1b85bcfc4e": {
			"balance": "910000000000000000000"
		},
		"bc73f7b1ca3b773b34249ada2e2c8a9274cc17c2": {
			"balance": "2000000000000000000000"
		},
		"1adaf4abfa867db17f99af6abebf707a3cf55df6": {
			"balance": "6000000000000000000000"
		},
		"8d629c20608135491b5013f1002586a0383130e5": {
			"balance": "1370000000000000000000"
		},
		"38e46de4453c38e941e7930f43304f94bb7b2be8": {
			"balance": "2005500000000000000000"
		},
)E" + R"E(
		"3485f621256433b98a4200dad857efe55937ec98": {
			"balance": "2000000000000000000000"
		},
		"775c10c93e0db7205b2643458233c64fc33fd75b": {
			"balance": "2000000000000000000000"
		},
		"7c4401ae98f12ef6de39ae24cf9fc51f80eba16b": {
			"balance": "200000000000000000000"
		},
		"17b807afa3ddd647e723542e7b52fee39527f306": {
			"balance": "400010000000000000000"
		},
		"0ab366e6e7d5abbce6b44a438d69a1cabb90d133": {
			"balance": "320000000000000000000"
		},
		"194ffe78bbf5d20dd18a1f01da552e00b7b11db1": {
			"balance": "7000000000000000000000"
		},
		"c45d47ab0c9aa98a5bd62d16223ea2471b121ca4": {
			"balance": "593640000000000000000"
		},
		"2487c3c4be86a2723d917c06b458550170c3edba": {
			"balance": "1000000000000000000000"
		},
		"ec4d08aa2e47496dca87225de33f2b40a8a5b36f": {
			"balance": "158000000000000000000"
		},
		"aaa8defe11e3613f11067fb983625a08995a8dfc": {
			"balance": "200000000000000000000"
		},
		"50bb67c8b8d8bd0f63c4760904f2d333f400aace": {
			"balance": "2000000000000000000000"
		},
		"1227e10a4dbf9caca31b1780239f557615fc35c1": {
			"balance": "200000000000000000000"
		},
		"44a8989e32308121f72466978db395d1f76c3a4b": {
			"balance": "7236900000000000000000"
		},
		"59569a21d28fba4bda37753405a081f2063da150": {
			"balance": "4000000000000000000000"
		},
		"c3756bcdcc7eec74ed896adfc335275930266e08": {
			"balance": "6000000000000000000000"
		},
		"ce3a61f0461b00935e85fa1ead82c45e5a64d488": {
			"balance": "500000000000000000000"
		},
		"012f396a2b5eb83559bac515e5210df2c8c362ba": {
			"balance": "200000000000000000000"
		},
		"93bc7d9a4abd44c8bbb8fe8ba804c61ad8d6576c": {
			"balance": "3999922000000000000000"
		},
		"e20bb9f3966419e14bbbaaaa6789e92496cfa479": {
			"balance": "3465116000000000000000"
		},
		"9eef442d291a447d74c5d253c49ef324eac1d8f0": {
			"balance": "3420000000000000000000"
		},
		"db6c2a73dac7424ab0d031b66761122566c01043": {
			"balance": "3000000000000000000000"
		},
		"704d243c2978e46c2c86adbecd246e3b295ff633": {
			"balance": "2012000000000000000000"
		},
		"d2ff672016f63b2f85398f4a6fedbb60a50d3cce": {
			"balance": "342500000000000000000"
		},
		"d2051cb3cb6704f0548cc890ab0a19db3415b42a": {
			"balance": "334000000000000000000"
		},
		"1111e5dbf45e6f906d62866f1708101788ddd571": {
			"balance": "1300200000000000000000"
		},
		"6a686bf220b593deb9b7324615fb9144ded3f39d": {
			"balance": "1460000000000000000000"
		},
		"911feea61fe0ed50c5b9e5a0d66071399d28bdc6": {
			"balance": "60000000000000000000"
		},
		"3881defae1c07b3ce04c78abe26b0cdc8d73f010": {
			"balance": "200000000000000000000"
		},
		"ea94f32808a2ef8a9bf0861d1d2404f7b7be258a": {
			"balance": "20000000000000000000"
		},
		"2eef6b1417d7b10ecfc19b123a8a89e73e526c58": {
			"balance": "600000000000000000000"
		},
		"dd8af9e7765223f4446f44d3d509819a3d3db411": {
			"balance": "10000000000000000000000"
		},
		"2efc4c647dac6acac35577ad221758fef6616faa": {
			"balance": "8000000000000000000000"
		},
		"1547b9bf7ad66274f3413827231ba405ee8c88c1": {
			"balance": "17300000000000000000000"
		},
		"250a40cef3202397f240469548beb5626af4f23c": {
)E" + R"E(
			"balance": "92500000000000000000"
		},
		"c175be3194e669422d15fee81eb9f2c56c67d9c9": {
			"balance": "200000000000000000000"
		},
		"c9e02608066828848aeb28c73672a12925181f4d": {
			"balance": "500038000000000000000"
		},
		"8229ceb9f0d70839498d44e6abed93c5ca059f5d": {
			"balance": "123300000000000000000000"
		},
		"39f198331e4b21c1b760a3155f4ab2fe00a74619": {
			"balance": "2000000000000000000000"
		},
		"3ffcb870d4023d255d5167d8a507cefc366b68ba": {
			"balance": "649400000000000000000"
		},
		"00dae27b350bae20c5652124af5d8b5cba001ec1": {
			"balance": "40000000000000000000"
		},
		"fc5500825105cf712a318a5e9c3bfc69c89d0c12": {
			"balance": "4000000000000000000000"
		},
		"1ed8bb3f06778b039e9961d81cb71a73e6787c8e": {
			"balance": "2000000000000000000000"
		},
		"530ffac3bc3412e2ec0ea47b7981c770f5bb2f35": {
			"balance": "133700000000000000000"
		},
		"5f344b01c7191a32d0762ac188f0ec2dd460911d": {
			"balance": "1000000000000000000000"
		},
		"5cfa9877f719c79d9e494a08d1e41cf103fc87c9": {
			"balance": "200000000000000000000"
		},
		"f6eaac7032d492ef17fd6095afc11d634f56b382": {
			"balance": "500038000000000000000"
		},
		"962c0dec8a3d464bf39b1215eafd26480ae490cd": {
			"balance": "2001680000000000000000"
		},
		"262a8bfd7d9dc5dd3ad78161b6bb560824373655": {
			"balance": "1169820000000000000000"
		},
		"9b4824ff9fb2abda554dee4fb8cf549165570631": {
			"balance": "20000000000000000000"
		},
		"bb3b9005f46fd2ca3b30162599928c77d9f6b601": {
			"balance": "8000014000000000000000"
		},
		"f7dc251196fbcbb77c947d7c1946b0ff65021cea": {
			"balance": "1000000000000000000000"
		},
		"af1148ef6c8e103d7530efc91679c9ac27000993": {
			"balance": "200000000000000000000"
		},
		"0bb2650ea01aca755bc0c017b64b1ab5a66d82e3": {
			"balance": "1337000000000000000000"
		},
		"0cda12bf72d461bbc479eb92e6491d057e6b5ad1": {
			"balance": "10000000000000000000000"
		},
		"4e5b77f9066159e615933f2dda7477fa4e47d648": {
			"balance": "200000000000000000000"
		},
		"391161b0e43c302066e8a68d2ce7e199ecdb1d57": {
			"balance": "4000000000000000000000"
		},
		"c7e330cd0c890ac99fe771fcc7e7b009b7413d8a": {
			"balance": "4000000000000000000000"
		},
		"d4b38a5fdb63e01714e9801db47bc990bd509183": {
			"balance": "5999000000000000000000"
		},
		"bc0f98598f88056a26339620923b8f1eb074a9fd": {
			"balance": "200000000000000000000"
		},
		"dbc59ed88973dead310884223af49763c05030f1": {
			"balance": "20000000000000000000"
		},
		"0f85e42b1df321a4b3e835b50c00b06173968436": {
			"balance": "985000000000000000000"
		},
		"d7788ef28658aa06cc53e1f3f0de58e5c371be78": {
			"balance": "6685000000000000000000"
		},
		"ecd276af64c79d1bd9a92b86b5e88d9a95eb88f8": {
			"balance": "20000000000000000000"
		},
		"81c9e1aee2d3365d53bcfdcd96c7c538b0fd7eec": {
			"balance": "1820000000000000000000"
		},
		"5d39ef9ea6bdfff15d11fe91f561a6f9e31f5da5": {
			"balance": "2000000000000000000000"
		},
		"99878f9d6e0a7ed9aec78297b73879a80195afe0": {
			"balance": "3980000000000000000000"
		},
		"7294c918b1aefb4d25927ef9d799e71f93a28e85": {
			"balance": "197000000000000000000"
)E" + R"E(
		},
		"a33f70da7275ef057104dfa7db64f472e9f5d553": {
			"balance": "80220000000000000000"
		},
		"255bdd6474cc8262f26a22c38f45940e1ceea69b": {
			"balance": "4000000000000000000000"
		},
		"52f8b509fee1a874ab6f9d87367fbeaf15ac137f": {
			"balance": "1000000000000000000000"
		},
		"e2728a3e8c2aaac983d05dc6877374a8f446eee9": {
			"balance": "197600000000000000000"
		},
		"ed0206cb23315128f8caff26f6a30b985467d022": {
			"balance": "40000000000000000000000"
		},
		"87cf36ad03c9eae9053abb5242de9117bb0f2a0b": {
			"balance": "500000000000000000000"
		},
		"a929c8bd71db0c308dac06080a1747f21b1465aa": {
			"balance": "500000000000000000000"
		},
		"9da6e075989c7419094cc9f6d2e49393bb199688": {
			"balance": "11100000000000000000000"
		},
		"763eece0b08ac89e32bfa4bece769514d8cb5b85": {
			"balance": "4000000000000000000000"
		},
		"5df3277ca85936c7a0d2c0795605ad25095e7159": {
			"balance": "2000000000000000000000"
		},
		"7163758cbb6c4c525e0414a40a049dcccce919bb": {
			"balance": "200000000000000000000"
		},
		"14cdddbc8b09e6675a9e9e05091cb92238c39e1e": {
			"balance": "5100000000000000000000"
		},
		"b3b7f493b44a2c8d80ec78b1cdc75a652b73b06c": {
			"balance": "2000000000000000000000"
		},
		"c69b855539ce1b04714728eec25a37f367951de7": {
			"balance": "2000000000000000000000"
		},
		"052eab1f61b6d45517283f41d1441824878749d0": {
			"balance": "4000000000000000000000"
		},
		"515651d6db4faf9ecd103a921bbbbe6ae970fdd4": {
			"balance": "20000000000000000000000"
		},
		"c7aff91929797489555a2ff1d14d5c695a108355": {
			"balance": "1000000000000000000000"
		},
		"d7ca7fdcfebe4588eff5421d1522b61328df7bf3": {
			"balance": "4001070000000000000000"
		},
		"eefba12dfc996742db790464ca7d273be6e81b3e": {
			"balance": "1000000000000000000000"
		},
		"ebaa216de9cc5a43031707d36fe6d5bedc05bdf0": {
			"balance": "1969606000000000000000"
		},
		"559194304f14b1b93afe444f0624e053c23a0009": {
			"balance": "400000000000000000000"
		},
		"4ecc19948dd9cd87b4c7201ab48e758f28e7cc76": {
			"balance": "500200000000000000000"
		},
		"f224eb900b37b4490eee6a0b6420d85c947d8733": {
			"balance": "970000000000000000000"
		},
		"97810bafc37e84306332aacb35e92ad911d23d24": {
			"balance": "1000000000000000000000"
		},
		"bd67d2e2f82da8861341bc96a2c0791fddf39e40": {
			"balance": "200014000000000000000"
		},
		"1b6495891240e64e594493c2662171db5e30ce13": {
			"balance": "172400000000000000000"
		},
		"00bdd4013aa31c04616c2bc9785f2788f915679b": {
			"balance": "13400000000000000000"
		},
		"c6ae287ddbe1149ba16ddcca4fe06aa2eaa988a9": {
			"balance": "400000000000000000000"
		},
		"b7c9f12b038e73436d17e1c12ffe1aeccdb3f58c": {
			"balance": "540000000000000000000"
		},
		"c1b500011cfba95d7cd636e95e6cbf6167464b25": {
			"balance": "200000000000000000000"
		},
		"39e0db4d60568c800b8c5500026c2594f5768960": {
			"balance": "1000000000000000000000"
		},
		"40e3c283f7e24de0410c121bee60a5607f3e29a6": {
			"balance": "1000000000000000000000"
		},
		"2f7d3290851be5c6b4b43f7d4574329f61a792c3": {
			"balance": "100000000000000000000"
		},
)E" + R"E(
		"c33ece935a8f4ef938ea7e1bac87cb925d8490ca": {
			"balance": "33122000000000000000000"
		},
		"57bddf078834009c89d88e6282759dc45335b470": {
			"balance": "2148000000000000000000"
		},
		"50ad187ab21167c2b6e78be0153f44504a07945e": {
			"balance": "100076000000000000000"
		},
		"5bd24aac3612b20c609eb46779bf95698407c57c": {
			"balance": "1970000000000000000000"
		},
		"16526c9edf943efa4f6d0f0bae81e18b31c54079": {
			"balance": "985000000000000000000"
		},
		"4c6a9dc2cab10abb2e7c137006f08fecb5b779e1": {
			"balance": "499000000000000000000"
		},
		"02c9f7940a7b8b7a410bf83dc9c22333d4275dd3": {
			"balance": "5000000000000000000000"
		},
		"b9fd3833e88e7cf1fa9879bdf55af4b99cd5ce3f": {
			"balance": "1000000000000000000000"
		},
		"7e268f131ddf687cc325c412f78ba961205e9112": {
			"balance": "16000600000000000000000"
		},
		"180478a655d78d0f3b0c4f202b61485bc4002fd5": {
			"balance": "2000000000000000000000"
		},
		"ed4014538cee664a2fbcb6dc669f7ab16d0ba57c": {
			"balance": "200000000000000000000"
		},
		"f63a579bc3eac2a9490410128dbcebe6d9de8243": {
			"balance": "1490000000000000000000"
		},
		"5d822d9b3ef4b502627407da272f67814a6becd4": {
			"balance": "20000000000000000000"
		},
		"eb52ab10553492329c1c54833ae610f398a65b9d": {
			"balance": "152000000000000000000"
		},
		"63340a57716bfa63eb6cd133721202575bf796f0": {
			"balance": "209967000000000000000"
		},
		"933bf33f8299702b3a902642c33e0bfaea5c1ca3": {
			"balance": "15200000000000000000"
		},
		"25bc49ef288cd165e525c661a812cf84fbec8f33": {
			"balance": "338464000000000000000"
		},
		"c8231ba5a411a13e222b29bfc1083f763158f226": {
			"balance": "1000090000000000000000"
		},
		"6c15ec3520bf8ebbc820bd0ff19778375494cf9d": {
			"balance": "2005500000000000000000"
		},
		"aaced8a9563b1bc311dbdffc1ae7f57519c4440c": {
			"balance": "2000000000000000000000"
		},
		"d90f3009db437e4e11c780bec8896f738d65ef0d": {
			"balance": "4000000000000000000000"
		},
		"5603241eb8f08f721e348c9d9ad92f48e390aa24": {
			"balance": "200000000000000000000"
		},
		"53cec6c88092f756efe56f7db11228a2db45b122": {
			"balance": "4000000000000000000000"
		},
		"194cebb4929882bf3b4bf9864c2b1b0f62c283f9": {
			"balance": "571300000000000000000"
		},
		"4be8628a8154874e048d80c142181022b180bcc1": {
			"balance": "60000000000000000000"
		},
		"5fd973af366aa5157c54659bcfb27cbfa5ac15d6": {
			"balance": "4000000000000000000000"
		},
		"303139bc596403d5d3931f774c66c4ba467454db": {
			"balance": "1699830000000000000000"
		},
		"87584a3f613bd4fac74c1e780b86d6caeb890cb2": {
			"balance": "1700000000000000000000"
		},
		"77f4e3bdf056883cc87280dbe640a18a0d02a207": {
			"balance": "193806000000000000000"
		},
		"4de3fe34a6fbf634c051997f47cc7f48791f5824": {
			"balance": "1999000000000000000000"
		},
		"c45a1ca1036b95004187cdac44a36e33a94ab5c3": {
			"balance": "254800000000000000000"
		},
		"65d33eb39cda6453b19e61c1fe4db93170ef9d34": {
			"balance": "13370000000000000000"
		},
		"f65616be9c8b797e7415227c9138faa0891742d7": {
			"balance": "790000000000000000000"
		},
		"e17812f66c5e65941e186c46922b6e7b2f0eeb46": {
)E" + R"E(
			"balance": "1820000000000000000000"
		},
		"d47f50df89a1cff96513bef1b2ae3a2971accf2c": {
			"balance": "840000000000000000000"
		},
		"8ed1528b447ed4297902f639c514d0944a88f8c8": {
			"balance": "198800000000000000000"
		},
		"a4fb14409a67b45688a8593e5cc2cf596ced6f11": {
			"balance": "1790000000000000000000"
		},
		"855d9aef2c39c6230d09c99ef6494989abe68785": {
			"balance": "161000000000000000000"
		},
		"778c43d11afe3b586ff374192d96a7f23d2b9b7f": {
			"balance": "2577139000000000000000"
		},
		"e3ece1f632711d13bfffa1f8f6840871ee58fb27": {
			"balance": "4000000000000000000000"
		},
		"beb3358c50cf9f75ffc76d443c2c7f55075a0589": {
			"balance": "2674000000000000000000"
		},
		"f156dc0b2a981e5b55d3f2f03b8134e331dbadb7": {
			"balance": "100000000000000000000"
		},
		"eb9cc9fe0869d2dab52cc7aae8fd57adb35f9feb": {
			"balance": "1966000000000000000000"
		},
		"2467c6a5c696ede9a1e542bf1ad06bcc4b06aca0": {
			"balance": "18500000000000000000"
		},
		"ec75b4a47513120ba5f86039814f1998e3817ac3": {
			"balance": "178756000000000000000"
		},
		"9c3d0692ceeef80aa4965ceed262ffc7f069f2dc": {
			"balance": "200000000000000000000"
		},
		"e05029aceb0778675bef1741ab2cd2931ef7c84b": {
			"balance": "5000057000000000000000"
		},
		"41d3b731a326e76858baa5f4bd89b57b36932343": {
			"balance": "394000000000000000000"
		},
		"c346cb1fbce2ab285d8e5401f42dd7234d37e86d": {
			"balance": "83500000000000000000"
		},
		"45f4fc60f08eaca10598f0336329801e3c92cb46": {
			"balance": "200000000000000000000"
		},
		"f04a6a379708b9428d722aa2b06b77e88935cf89": {
			"balance": "300000000000000000000"
		},
		"232832cd5977e00a4c30d0163f2e24f088a6cb09": {
			"balance": "3000000000000000000000"
		},
		"d2ac0d3a58605e1d0f0eb3de25b2cad129ed6058": {
			"balance": "4000000000000000000000"
		},
		"a356551bb77d4f45a6d7e09f0a089e79cca249cb": {
			"balance": "340000000000000000000"
		},
		"b50c9f5789ae44e2dce017c714caf00c830084c2": {
			"balance": "394000000000000000000"
		},
		"21fd6c5d97f9c600b76821ddd4e776350fce2be0": {
			"balance": "1999946000000000000000"
		},
		"f0d5c31ccb6cbe30c7c9ea19f268d159851f8c9c": {
			"balance": "16700000000000000000000"
		},
		"ab7091932e4bc39dbb552380ca934fd7166d1e6e": {
			"balance": "3340000000000000000000"
		},
		"acd8dd91f714764c45677c63d852e56eb9eece2e": {
			"balance": "2000000000000000000000"
		},
		"57d032a43d164e71aa2ef3ffd8491b0a4ef1ea5b": {
			"balance": "2000000000000000000000"
		},
		"5af46a25ac09cb73616b53b14fb42ff0a51cddb2": {
			"balance": "4000000000000000000000"
		},
		"1ea6bf2f15ae9c1dbc64daa7f8ea4d0d81aad3eb": {
			"balance": "4200000000000000000000"
		},
		"03337012ae1d7ff3ee7f697c403e7780188bf0ef": {
			"balance": "200000000000000000000"
		},
		"32eb64be1b5dede408c6bdefbe6e405c16b7ed02": {
			"balance": "1970000000000000000000"
		},
		"22e2488e2da26a49ae84c01bd54b21f2947891c6": {
			"balance": "1730000000000000000000"
		},
		"be98a77fd41097b34f59d7589baad021659ff712": {
			"balance": "900000000000000000000"
		},
		"dda4ed2a58a8dd20a73275347b580d71b95bf99a": {
			"balance": "399000000000000000000"
)E" + R"E(
		},
		"671110d96aaff11523cc546bf9940eedffb2faf7": {
			"balance": "4000000000000000000000"
		},
		"5d71799c8df3bccb7ee446df50b8312bc4eb71c5": {
			"balance": "200000000000000000000"
		},
		"ae179a460db66326743d24e67523a57b246daf7f": {
			"balance": "4722920000000000000000"
		},
		"198bfcf1b07ae308fa2c02069ac9dafe7135fb47": {
			"balance": "20000000000000000000"
		},
		"4662a1765ee921842ddc88898d1dc8627597bd7e": {
			"balance": "10000000000000000000000"
		},
		"783eec8aa5dac77b2e6623ed5198a431abbaee07": {
			"balance": "440000000000000000000"
		},
		"ed6643c0e8884b2d3211853785a08bf8f33ed29f": {
			"balance": "1337000000000000000000"
		},
		"5cc7d3066d45d27621f78bb4b339473e442a860f": {
			"balance": "9999908000000000000000"
		},
		"94ef8be45077c7d4c5652740de946a62624f713f": {
			"balance": "100085000000000000000"
		},
		"2f853817afd3b8f3b86e9f60ee77b5d97773c0e3": {
			"balance": "1451450000000000000000"
		},
		"3e0b8ed86ed669e12723af7572fbacfe829b1e16": {
			"balance": "1499800000000000000000"
		},
		"fa68e0cb3edf51f0a6f211c9b2cb5e073c9bffe6": {
			"balance": "291200000000000000000"
		},
		"2c234f505ca8dcc77d9b7e01d257c318cc19396d": {
			"balance": "100000000000000000000"
		},
		"f3f24fc29e20403fc0e8f5ebbb553426f78270a2": {
			"balance": "100000000000000000000"
		},
		"91546b79ecf69f936b5a561508b0d7e50cc5992f": {
			"balance": "267400000000000000000"
		},
		"435443b81dfdb9bd8c6787bc2518e2d47e57c15f": {
			"balance": "5968500000000000000000"
		},
		"3a06e3bb1edcfd0c44c3074de0bb606b049894a2": {
			"balance": "10000000000000000000000"
		},
		"3a3108c1e680a33b336c21131334409d97e5adec": {
			"balance": "20000000000000000000"
		},
		"2caf6bf4ec7d5a19c5e0897a5eeb011dcece4210": {
			"balance": "139740000000000000000"
		},
		"f44f8551ace933720712c5c491cdb6f2f951736c": {
			"balance": "4000000000000000000000"
		},
		"5bc1f95507b1018642e45cd9c0e22733b9b1a326": {
			"balance": "100000000000000000000"
		},
		"94ca56de777fd453177f5e0694c478e66aff8a84": {
			"balance": "500000000000000000000"
		},
		"afdd1b786162b8317e20f0e979f4b2ce486d765d": {
			"balance": "20000000000000000000"
		},
		"3a805fa0f7387f73055b7858ca8519edd93d634f": {
			"balance": "1850000000000000000000"
		},
		"8b36224c7356e751f0c066c35e3b44860364bfc2": {
			"balance": "998987000000000000000"
		},
		"cfecbea07c27002f65fe534bb8842d0925c78402": {
			"balance": "4000000000000000000000"
		},
		"482982ac1f1c6d1721feecd9b9c96cd949805055": {
			"balance": "10000000000000000000000"
		},
		"af880fc7567d5595cacce15c3fc14c8742c26c9e": {
			"balance": "133700000000000000000"
		},
		"acc1c78786ab4d2b3b277135b5ba123e0400486b": {
			"balance": "78800000000000000000"
		},
		"41f27e744bd29de2b0598f02a0bb9f98e681eaa4": {
			"balance": "7760000000000000000000"
		},
		"09a025316f967fa8b9a1d60700063f5a68001caa": {
			"balance": "38200000000000000000"
		},
		"391f20176d12360d724d51470a90703675594a4d": {
			"balance": "1600000000000000000000"
		},
		"fe4d8403216fd571572bf1bdb01d00578978d688": {
			"balance": "9850000000000000000000"
		},
)E" + R"E(
		"900f0b8e35b668f81ef252b13855aa5007d012e7": {
			"balance": "425000000000000000000"
		},
		"c35b95a2a3737cb8f0f596b34524872bd30da234": {
			"balance": "7540000000000000000000"
		},
		"412a68f6c645559cc977fc4964047a201d1bb0e2": {
			"balance": "50000000000000000000000"
		},
		"d3dad1b6d08d4581ccae65a8732db6ac69f0c69e": {
			"balance": "6000000000000000000000"
		},
		"35855ec641ab9e081ed0c2a6dcd81354d0244a87": {
			"balance": "1201897000000000000000"
		},
		"88015d7203c5e0224aeda286ed12f1a51b789333": {
			"balance": "4999711000000000000000"
		},
		"251c12722c6879227992a304eb3576cd18434ea5": {
			"balance": "2000000000000000000000"
		},
		"1f6f0030349752061c96072bc3d6eb3549208d6b": {
			"balance": "23891000000000000000"
		},
		"86153063a1ae7f02f1a88136d4d69c7c5e3e4327": {
			"balance": "1000000000000000000000"
		},
		"78355df0a230f83d032c703154414de3eedab557": {
			"balance": "2000000000000000000000"
		},
		"c5b56cd234267c28e89c6f6b2266b086a12f970c": {
			"balance": "4000000000000000000000"
		},
		"3e3cd3bec06591d6346f254b621eb41c89008d31": {
			"balance": "993800000000000000000"
		},
		"378ea1dc8edc19bae82638029ea8752ce98bcfcd": {
			"balance": "2000000000000000000000"
		},
		"67632046dcb25a54936928a96f423f3320cbed92": {
			"balance": "2000000000000000000000"
		},
		"ddbee6f094eae63420b003fb4757142aea6cd0fd": {
			"balance": "2000000000000000000000"
		},
		"b555d00f9190cc3677aef314acd73fdc39399259": {
			"balance": "2000000000000000000000"
		},
		"e230fe1bff03186d0219f15d4c481b7d59be286a": {
			"balance": "36710000000000000000"
		},
		"3e4e9265223c9738324cf20bd06006d0073edb8c": {
			"balance": "133700000000000000000"
		},
		"7450ff7f99eaa9116275deac68e428df5bbcd8b9": {
			"balance": "2000000000000000000000"
		},
		"021f69043de88c4917ca10f1842897eec0589c7c": {
			"balance": "1978760000000000000000"
		},
		"351787843505f8e4eff46566cce6a59f4d1c5fe7": {
			"balance": "9250000000000000000000"
		},
		"ebd37b256563e30c6f9289a8e2702f0852880833": {
			"balance": "1999944000000000000000"
		},
		"ed41e1a28f5caa843880ef4e8b08bd6c33141edf": {
			"balance": "790174000000000000000"
		},
		"8d238e036596987643d73173c37b0ad06055b96c": {
			"balance": "2089724000000000000000"
		},
		"478e524ef2a381d70c82588a93ca7a5fa9d51cbf": {
			"balance": "254908000000000000000000"
		},
		"4419ac618d5dea7cdc6077206fb07dbdd71c1702": {
			"balance": "4000000000000000000000"
		},
		"ca25ff34934c1942e22a4e7bd56f14021a1af088": {
			"balance": "197000000000000000000"
		},
		"5552f4b3ed3e1da79a2f78bb13e8ae5a68a9df3b": {
			"balance": "1000000000000000000000"
		},
		"4354221e62dc09e6406436163a185ef06d114a81": {
			"balance": "2000000000000000000000"
		},
		"ca0432cb157b5179f02ebba5c9d1b54fec4d88ca": {
			"balance": "1000000000000000000000"
		},
		"8a780ab87a9145fe10ed60fa476a740af4cab1d2": {
			"balance": "334000000000000000000"
		},
		"4ff676e27f681a982d8fd9d20e648b3dce05e945": {
			"balance": "2800000000000000000000"
		},
		"6c63fc85029a2654d79b2bea4de349e4524577c5": {
			"balance": "660000000000000000000"
		},
		"1ac089c3bc4d82f06a20051a9d732dc0e734cb61": {
)E" + R"E(
			"balance": "700300000000000000000"
		},
		"4bf4479799ef82eea20943374f56a1bf54001e5e": {
			"balance": "3940000000000000000000"
		},
		"08411652c871713609af0062a8a1281bf1bbcfd9": {
			"balance": "1400000000000000000000"
		},
		"e1bfaa5a45c504428923c4a61192a55b1400b45d": {
			"balance": "2674000000000000000000"
		},
		"5e1fbd4e58e2312b3c78d7aaaafa10bf9c3189e3": {
			"balance": "40000000000000000000000"
		},
		"bb27c6a7f91075475ab229619040f804c8ec7a6a": {
			"balance": "10000000000000000000000"
		},
		"5d8d31faa864e22159cd6f5175ccecc53fa54d72": {
			"balance": "26980000000000000000000"
		},
		"2dd8eeef87194abc2ce7585da1e35b7cea780cb7": {
			"balance": "999999000000000000000"
		},
		"0e1801e70b6262861b1134ccbc391f568afc92f7": {
			"balance": "4000000000000000000000"
		},
		"61042b80fd6095d1b87be2f00f109fabafd157a6": {
			"balance": "100000000000000000000"
		},
		"fb5518714cefc36d04865de5915ef0ff47dfe743": {
			"balance": "2000000000000000000000"
		},
		"b5add1e7809f7d03069bfe883b0a932210be8712": {
			"balance": "1000000000000000000000"
		},
		"c2e2d498f70dcd0859e50b023a710a6d4b2133bd": {
			"balance": "1037130000000000000000"
		},
		"4ad047fae67ef162fe68fedbc27d3b65caf10c36": {
			"balance": "1970000000000000000000"
		},
		"69cb3e2153998d86e5ee20c1fcd1a6baeeb2863f": {
			"balance": "4000000000000000000000"
		},
		"683633010a88686bea5a98ea53e87997cbf73e69": {
			"balance": "99960000000000000000"
		},
		"6cb11ecb32d3ce829601310636f5a10cf7cf9b5f": {
			"balance": "20068370000000000000000"
		},
		"a613456996408af1c2e93e177788ab55895e2b32": {
			"balance": "6366000000000000000000"
		},
		"8308ed0af7f8a3c1751fafc877b5a42af7d35882": {
			"balance": "1000000000000000000000"
		},
		"e5edf8123f2403ce1a0299becf7aac744d075f23": {
			"balance": "200200000000000000000"
		},
		"05665155cc49cbf6aabdd5ae92cbfaad82b8c0c1": {
			"balance": "400000000000000000000"
		},
		"00b277b099a8e866ca0ec65bcb87284fd142a582": {
			"balance": "1970000000000000000000"
		},
		"4b9e068fc4680976e61504912985fd5ce94bab0d": {
			"balance": "668500000000000000000"
		},
		"12134e7f6b017bf48e855a399ca58e2e892fa5c8": {
			"balance": "1000000000000000000000"
		},
		"dffcea5421ec15900c6ecfc777184e140e209e24": {
			"balance": "19980000000000000000"
		},
		"2132c0516a2e17174ac547c43b7b0020d1eb4c59": {
			"balance": "985000000000000000000"
		},
		"d39a5da460392b940b3c69bc03757bf3f2e82489": {
			"balance": "7019250000000000000000"
		},
		"66c8331efe7198e98b2d32b938688e3241d0e24f": {
			"balance": "9620000000000000000000"
		},
		"bdca2a0ff34588af625fa8e28fc3015ab5a3aa00": {
			"balance": "2339800000000000000000"
		},
		"7dfc342dffcf45dfee74f84c0995397bd1a63172": {
			"balance": "250000000000000000000"
		},
		"a202547242806f6e70e74058d6e5292defc8c8d4": {
			"balance": "2002000000000000000000"
		},
		"3bbc13d04accc0707aebdcaef087d0b87e0b5ee3": {
			"balance": "3520000000000000000000"
		},
		"be5cba8d37427986e8ca2600e858bb03c359520f": {
			"balance": "2955000000000000000000"
		},
		"4174fa1bc12a3b7183cbabb77a0b59557ba5f1db": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"9eb3a7cb5e6726427a3a361cfa8d6164dbd0ba16": {
			"balance": "804000000000000000000"
		},
		"25e661c939863acc044e6f17b5698cce379ec3cc": {
			"balance": "1370000000000000000000"
		},
		"24bd5904059091d2f9e12d6a26a010ca22ab14e8": {
			"balance": "1880000000000000000000"
		},
		"c96626728aaa4c4fb3d31c26df3af310081710d1": {
			"balance": "3340000000000000000000"
		},
		"0fb5d2c673bfb1ddca141b9894fd6d3f05da6720": {
			"balance": "100000000000000000000"
		},
		"2de31afd189a13a76ff6fe73ead9f74bb5c4a629": {
			"balance": "6000000000000000000000"
		},
		"bd09126c891c4a83068059fe0e15796c4661a9f4": {
			"balance": "800000000000000000000"
		},
		"496f5843f6d24cd98d255e4c23d1e1f023227545": {
			"balance": "1754143000000000000000"
		},
		"540cf23dd95c4d558a279d778d2b3735b3164191": {
			"balance": "10000000000000000000000"
		},
		"9b5ec18e8313887df461d2902e81e67a8f113bb1": {
			"balance": "100000000000000000000"
		},
		"b7a7f77c348f92a9f1100c6bd829a8ac6d7fcf91": {
			"balance": "1820000000000000000000"
		},
		"2590126870e0bde8a663ab040a72a5573d8d41c2": {
			"balance": "5000000000000000000000"
		},
		"090fa9367bda57d0d3253a0a8ff76ce0b8e19a73": {
			"balance": "1000000000000000000000"
		},
		"2a5ba9e34cd58da54c9a2712663a3be274c8e47b": {
			"balance": "197000000000000000000"
		},
		"3e8641d43c42003f0a33c929f711079deb2b9e46": {
			"balance": "500000000000000000000"
		},
		"f4d97664cc4eec9edbe7fa09f4750a663b507d79": {
			"balance": "4000000000000000000000"
		},
		"b1540e94cff3465cc3d187e7c8e3bdaf984659e2": {
			"balance": "2989950000000000000000"
		},
		"f96883582459908c827627e86f28e646f9c7fc7a": {
			"balance": "8350000000000000000000"
		},
		"d4feed99e8917c5c5458635f3603ecb7e817a7d0": {
			"balance": "300031000000000000000"
		},
		"14b1603ec62b20022033eec4d6d6655ac24a015a": {
			"balance": "50000000000000000000"
		},
		"af8e1dcb314c950d3687434d309858e1a8739cd4": {
			"balance": "267400000000000000000"
		},
		"4b9206ba6b549a1a7f969e1d5dba867539d1fa67": {
			"balance": "7880000000000000000000"
		},
		"471010da492f4018833b088d9872901e06129174": {
			"balance": "500000000000000000000"
		},
		"d243184c801e5d79d2063f3578dbae81e7b3a9cb": {
			"balance": "1989700000000000000000"
		},
		"3eada8c92f56067e1bb73ce378da56dc2cdfd365": {
			"balance": "2210000000000000000000"
		},
		"33ea6b7855e05b07ab80dab1e14de9b649e99b6c": {
			"balance": "532000000000000000000"
		},
		"700711e311bb947355f755b579250ca7fd765a3e": {
			"balance": "1790000000000000000000"
		},
		"87fb26c31e48644d693134205cae43b21f18614b": {
			"balance": "1370000000000000000000"
		},
		"001d14804b399c6ef80e64576f657660804fec0b": {
			"balance": "4200000000000000000000"
		},
		"f9642086b1fbae61a6804dbe5fb15ec2d2b537f4": {
			"balance": "2000000000000000000000"
		},
		"6919dd5e5dfb1afa404703b9faea8cee35d00d70": {
			"balance": "5910000000000000000000"
		},
		"9ac4da51d27822d1e208c96ea64a1e5b55299723": {
			"balance": "100040000000000000000"
		},
		"1bd8ebaa7674bb18e19198db244f570313075f43": {
			"balance": "150000000000000000000"
		},
)E" + R"E(
		"e64ef012658d54f8e8609c4e9023c09fe865c83b": {
			"balance": "28000000000000000000"
		},
		"43b079baf0727999e66bf743d5bcbf776c3b0922": {
			"balance": "2000000000000000000000"
		},
		"06ac26ad92cb859bd5905ddce4266aa0ec50a9c5": {
			"balance": "775000000000000000000"
		},
		"99c1d9f40c6ab7f8a92fce2fdce47a54a586c53f": {
			"balance": "985000000000000000000"
		},
		"4ae93082e45187c26160e66792f57fad3551c73a": {
			"balance": "21658000000000000000000"
		},
		"7da7613445a21299aa74f0ad71431ec43fbb1be9": {
			"balance": "68000000000000000000"
		},
		"4a9a26fd0a8ba10f977da4f77c31908dab4a8016": {
			"balance": "1790000000000000000000"
		},
		"972c2f96aa00cf8a2f205abcf8937c0c75f5d8d9": {
			"balance": "200000000000000000000"
		},
		"b5046cb3dc1dedbd364514a2848e44c1de4ed147": {
			"balance": "16445100000000000000000"
		},
		"48c2ee91a50756d8ce9abeeb7589d22c6fee5dfb": {
			"balance": "3220000000000000000000"
		},
		"46c1aa2244b9c8a957ca8fac431b0595a3b86824": {
			"balance": "4000000000000000000000"
		},
		"21fd0bade5f4ef7474d058b7f3d854cb1300524e": {
			"balance": "20000000000000000000"
		},
		"1864a3c7b48155448c54c88c708f166709736d31": {
			"balance": "133700000000000000000"
		},
		"5dd53ae897526b167d39f1744ef7c3da5b37a293": {
			"balance": "8000000000000000000000"
		},
		"ece111670b563ccdbebca52384290ecd68fe5c92": {
			"balance": "20000000000000000000"
		},
		"74d671d99cbea1ab57906375b63ff42b50451d17": {
			"balance": "1000000000000000000000"
		},
		"5717cc9301511d4a81b9f583148beed3d3cc8309": {
			"balance": "2600000000000000000000"
		},
		"8f92844f282a92999ee5b4a8d773d06b694dbd9f": {
			"balance": "1940000000000000000000"
		},
		"b5a606f4ddcbb9471ec67f658caf2b00ee73025e": {
			"balance": "4325000000000000000000"
		},
		"bdb60b823a1173d45a0792245fb496f1fd3301cf": {
			"balance": "2000000000000000000000"
		},
		"1d2615f8b6ca5012b663bdd094b0c5137c778ddf": {
			"balance": "10000000000000000000000"
		},
		"82ff716fdf033ec7e942c909d9831867b8b6e2ef": {
			"balance": "1790000000000000000000"
		},
		"44c14765127cde11fab46c5d2cf4d4b2890023fd": {
			"balance": "2000000000000000000000"
		},
		"c72cb301258e91bc08998a805dd192f25c2f9a35": {
			"balance": "591000000000000000000"
		},
		"ad732c976593eec4783b4e2ecd793979780bfedb": {
			"balance": "2000000000000000000000"
		},
		"d8f62036f03b7635b858f1103f8a1d9019a892b6": {
			"balance": "50000000000000000000"
		},
		"0a06fad7dcd7a492cbc053eeabde6934b39d8637": {
			"balance": "20000000000000000000"
		},
		"67f2bb78b8d3e11f7c458a10b5c8e0a1d374467d": {
			"balance": "1790000000000000000000"
		},
		"4b5cdb1e428c91dd7cb54a6aed4571da054bfe52": {
			"balance": "88000000000000000000"
		},
		"b3557d39b5411b84445f5f54f38f62d2714d0087": {
			"balance": "600000000000000000000"
		},
		"0b0e055b28cbd03dc5ff44aa64f3dce04f5e63fb": {
			"balance": "2000000000000000000000"
		},
		"9b2be7f56754f505e3441a10f7f0e20fd3ddf849": {
			"balance": "340000000000000000000"
		},
		"0b93fca4a4f09cac20db60e065edcccc11e0a5b6": {
			"balance": "200000000000000000000"
		},
		"3bc85d6c735b9cda4bba5f48b24b13e70630307b": {
)E" + R"E(
			"balance": "1970000000000000000000"
		},
		"52102354a6aca95d8a2e86d5debda6de69346076": {
			"balance": "2000000000000000000000"
		},
		"cda4530f4b9bc50905b79d17c28fc46f95349bdf": {
			"balance": "942000000000000000000"
		},
		"ff545bbb66fbd00eb5e6373ff4e326f5feb5fe12": {
			"balance": "20000000000000000000"
		},
		"4030a925706b2c101c8c5cb9bd05fbb4f6759b18": {
			"balance": "4000000000000000000000"
		},
		"f11e01c7a9d12499005f4dae7716095a34176277": {
			"balance": "400000000000000000000"
		},
		"a4826b6c3882fad0ed5c8fbb25cc40cc4f33759f": {
			"balance": "2068000000000000000000"
		},
		"28510e6eff1fc829b6576f4328bc3938ec7a6580": {
			"balance": "10000000000000000000000"
		},
		"9ce5363b13e8238aa4dd15acd0b2e8afe0873247": {
			"balance": "200000000000000000000"
		},
		"d97bc84abd47c05bbf457b2ef659d61ca5e5e48f": {
			"balance": "122000000000000000000"
		},
		"4a719061f5285495b37b9d7ef8a51b07d6e6acac": {
			"balance": "199800000000000000000"
		},
		"8b714522fa2839620470edcf0c4401b713663df1": {
			"balance": "200000000000000000000"
		},
		"b6decf82969819ba02de29b9b593f21b64eeda0f": {
			"balance": "740000000000000000000"
		},
		"c87d3ae3d88704d9ab0009dcc1a0067131f8ba3c": {
			"balance": "1969606000000000000000"
		},
		"dccb370ed68aa922283043ef7cad1b9d403fc34a": {
			"balance": "4000000000000000000000"
		},
		"2d532df4c63911d1ce91f6d1fcbff7960f78a885": {
			"balance": "1669833000000000000000"
		},
		"1fcfd1d57f872290560cb62d600e1defbefccc1c": {
			"balance": "1490000000000000000000"
		},
		"d9e27eb07dfc71a706060c7f079238ca93e88539": {
			"balance": "1000000000000000000000"
		},
		"da7732f02f2e272eaf28df972ecc0ddeed9cf498": {
			"balance": "205274000000000000000"
		},
		"bf09d77048e270b662330e9486b38b43cd781495": {
			"balance": "436000000000000000000000"
		},
		"619f171445d42b02e2e07004ad8afe694fa53d6a": {
			"balance": "20000000000000000000"
		},
		"2bdd03bebbee273b6ca1059b34999a5bbd61bb79": {
			"balance": "20000000000000000000"
		},
		"8da1d359ba6cb4bcc57d7a437720d55db2f01c72": {
			"balance": "80000000000000000000"
		},
		"be935793f45b70d8045d2654d8dd3ad24b5b6137": {
			"balance": "880000000000000000000"
		},
		"ee71793e3acf12a7274f563961f537529d89c7de": {
			"balance": "2000000000000000000000"
		},
		"86f05d19063e9369c6004eb3f123943a7cff4eab": {
			"balance": "1999944000000000000000"
		},
		"87b10f9c280098179a2b76e9ce90be61fc844d0d": {
			"balance": "1337000000000000000000"
		},
		"243c84d12420570cc4ef3baba1c959c283249520": {
			"balance": "2345000000000000000000"
		},
		"6bc85acd5928722ef5095331ee88f484b8cf8357": {
			"balance": "180000000000000000000"
		},
		"2561a138dcf83bd813e0e7f108642be3de3d6f05": {
			"balance": "999940000000000000000"
		},
		"7d0350e40b338dda736661872be33f1f9752d755": {
			"balance": "49933000000000000000"
		},
		"e5dc9349cb52e161196122cf87a38936e2c57f34": {
			"balance": "2000000000000000000000"
		},
		"543a8c0efb8bcd15c543e2a6a4f807597631adef": {
			"balance": "5893800000000000000000"
		},
		"0413d0cf78c001898a378b918cd6e498ea773c4d": {
			"balance": "280000000000000000000"
)E" + R"E(
		},
		"3708e59de6b4055088782902e0579c7201a8bf50": {
			"balance": "200000000000000000000000"
		},
		"699fc6d68a4775573c1dcdaec830fefd50397c4e": {
			"balance": "60000000000000000000"
		},
		"379a7f755a81a17edb7daaa28afc665dfa6be63a": {
			"balance": "25000000000000000000"
		},
		"260a230e4465077e0b14ee4442a482d5b0c914bf": {
			"balance": "1677935000000000000000"
		},
		"3daa01ceb70eaf9591fa521ba4a27ea9fb8ede4a": {
			"balance": "1667400000000000000000"
		},
		"7f3a1e45f67e92c880e573b43379d71ee089db54": {
			"balance": "100000000000000000000000"
		},
		"38643babea6011316cc797d9b093c897a17bdae7": {
			"balance": "334400000000000000000"
		},
		"84675e9177726d45eaa46b3992a340ba7f710c95": {
			"balance": "1000000000000000000000"
		},
		"0f83461ba224bb1e8fdd9dae535172b735acb4e0": {
			"balance": "200000000000000000000"
		},
		"31aa3b1ebe8c4dbcb6a708b1d74831e60e497660": {
			"balance": "400000000000000000000"
		},
		"a32cf7dde20c3dd5679ff5e325845c70c5962662": {
			"balance": "20000000000000000000"
		},
		"c007f0bdb6e7009202b7af3ea90902697c721413": {
			"balance": "2999966000000000000000"
		},
		"05c64004a9a826e94e5e4ee267fa2a7632dd4e6f": {
			"balance": "16191931000000000000000"
		},
		"f622e584a6623eaaf99f2be49e5380c5cbcf5cd8": {
			"balance": "200000000000000000000"
		},
		"9dc10fa38f9fb06810e11f60173ec3d2fd6a751e": {
			"balance": "1970000000000000000000"
		},
		"423c3107f4bace414e499c64390a51f74615ca5e": {
			"balance": "2000000000000000000000"
		},
		"92438e5203b6346ff886d7c36288aacccc78ceca": {
			"balance": "1000000000000000000000"
		},
		"bef07d97c3481f9d6aee1c98f9d91a180a32442b": {
			"balance": "100000000000000000000000"
		},
		"55aa5d313ebb084da0e7801091e29e92c5dec3aa": {
			"balance": "2000000000000000000000"
		},
		"89c433d601fad714da6369308fd26c1dc9942bbf": {
			"balance": "2000000000000000000000"
		},
		"25106ab6755df86d6b63a187703b0cfea0e594a0": {
			"balance": "27400000000000000000"
		},
		"494256e99b0f9cd6e5ebca3899863252900165c8": {
			"balance": "14000000000000000000000"
		},
		"5f4ace4c1cc13391e01f00b198e1f20b5f91cbf5": {
			"balance": "5000196000000000000000"
		},
		"135cecd955e5798370769230159303d9b1839f66": {
			"balance": "5000000000000000000000"
		},
		"ced81ec3533ff1bfebf3e3843ee740ad11758d3e": {
			"balance": "1970000000000000000000"
		},
		"688eb3853bbcc50ecfee0fa87f0ab693cabdef02": {
			"balance": "31600000000000000000000"
		},
		"2159240813a73095a7ebf7c3b3743e8028ae5f09": {
			"balance": "2000000000000000000000"
		},
		"99d1579cd42682b7644e1d4f7128441eeffe339d": {
			"balance": "20000000000000000000000"
		},
		"8a243a0a9fea49b839547745ff2d11af3f4b0522": {
			"balance": "985000000000000000000"
		},
		"c1a41a5a27199226e4c7eb198b031b59196f9842": {
			"balance": "191000000000000000000"
		},
		"7514adbdc63f483f304d8e94b67ff3309f180b82": {
			"balance": "622911000000000000000"
		},
		"74aeec915de01cc69b2cb5a6356feea14658c6c5": {
			"balance": "232500000000000000000"
		},
		"76f9ad3d9bbd04ae055c1477c0c35e7592cb2a20": {
			"balance": "40200000000000000000000"
		},
)E" + R"E(
		"a8a7b68adab4e3eadff19ffa58e34a3fcec0d96a": {
			"balance": "6000000000000000000000"
		},
		"60de22a1507432a47b01cc68c52a0bf8a2e0d098": {
			"balance": "19100000000000000000"
		},
		"ceb33d78e7547a9da2e87d51aec5f3441c87923a": {
			"balance": "20000000000000000000"
		},
		"432809a2390f07c665921ff37d547d12f1c9966a": {
			"balance": "30000000000000000000000"
		},
		"d5e656a1b916f9bf45afb07dd8afaf73b4c56f41": {
			"balance": "97000000000000000000"
		},
		"e3410bb7557cf91d79fa69d0dfea0aa075402651": {
			"balance": "2000000000000000000000"
		},
		"dee942d5caf5fac11421d86b010b458e5c392990": {
			"balance": "4000000000000000000000"
		},
		"a98f109835f5eacd0543647c34a6b269e3802fac": {
			"balance": "400000000000000000000"
		},
		"932b9c04d40d2ac83083d94298169dae81ab2ed0": {
			"balance": "2000000000000000000000"
		},
		"ba10f2764290f875434372f79dbf713801caac01": {
			"balance": "955000000000000000000"
		},
		"a2c7eaffdc2c9d937345206c909a52dfb14c478f": {
			"balance": "143000000000000000000"
		},
		"6c67e0d7b62e2a08506945a5dfe38263339f1f22": {
			"balance": "1970000000000000000000"
		},
		"60c3714fdddb634659e4a2b1ea42c4728cc7b8ba": {
			"balance": "13370000000000000000"
		},
		"73b4d499de3f38bf35aaf769a6e318bc6d123692": {
			"balance": "2000000000000000000000"
		},
		"3b22dea3c25f1b59c7bd27bb91d3a3eaecef3984": {
			"balance": "100000000000000000000"
		},
		"1e3badb1b6e1380e27039c576ae6222e963a5b53": {
			"balance": "20000000000000000000000"
		},
		"abd4d6c1666358c0406fdf3af248f78ece830104": {
			"balance": "2112000000000000000000"
		},
		"0c925ad5eb352c8ef76d0c222d115b0791b962a1": {
			"balance": "3180000000000000000000"
		},
		"be9186c34a52514abb9107860f674f97b821bd5b": {
			"balance": "509600000000000000000"
		},
		"b7f67314cb832e32e63b15a40ce0d7ffbdb26985": {
			"balance": "1060866000000000000000"
		},
		"3f30d3bc9f602232bc724288ca46cd0b0788f715": {
			"balance": "4000000000000000000000"
		},
		"970abd53a54fca4a6429207c182d4d57bb39d4a0": {
			"balance": "2000000000000000000000"
		},
		"36d85dc3683156e63bf880a9fab7788cf8143a27": {
			"balance": "20000000000000000000000"
		},
		"2836123046b284e5ef102bfd22b1765e508116ad": {
			"balance": "411880000000000000000"
		},
		"de06d5ea777a4eb1475e605dbcbf43444e8037ea": {
			"balance": "50000000000000000000000"
		},
		"9af11399511c213181bfda3a8b264c05fc81b3ce": {
			"balance": "14000000000000000000000"
		},
		"e2191215983f33fd33e22cd4a2490054da53fddc": {
			"balance": "15800000000000000000"
		},
		"2eebf59432b52892f9380bd140aa99dcf8ad0c0f": {
			"balance": "152000000000000000000"
		},
		"dc087f9390fb9e976ac23ab689544a0942ec2021": {
			"balance": "1820000000000000000000"
		},
		"fd4b989558ae11be0c3b36e2d6f2a54a9343ca2e": {
			"balance": "2000000000000000000000"
		},
		"770c2fb2c4a81753ac0182ea460ec09c90a516f8": {
			"balance": "20000000000000000000"
		},
		"b28dbfc6499894f73a71faa00abe0f4bc9d19f2a": {
			"balance": "100000000000000000000"
		},
		"b0cef8e8fb8984a6019f01c679f272bbe68f5c77": {
			"balance": "152000000000000000000"
		},
		"f400f93d5f5c7e3fc303129ac8fb0c2f786407fa": {
)E" + R"E(
			"balance": "2000000000000000000000"
		},
		"f2133431d1d9a37ba2f0762bc40c5acc8aa6978e": {
			"balance": "2000000000000000000000"
		},
		"9003d270891ba2df643da8341583193545e3e000": {
			"balance": "4000000000000000000000"
		},
		"8938d1b4daee55a54d738cf17e4477f6794e46f7": {
			"balance": "18200000000000000000"
		},
		"98e6f547db88e75f1f9c8ac2c5cf1627ba580b3e": {
			"balance": "1000000000000000000000"
		},
		"009fdbf44e1f4a6362b769c39a475f95a96c2bc7": {
			"balance": "564000000000000000000"
		},
		"d0f9597811b0b992bb7d3757aa25b4c2561d32e2": {
			"balance": "500000000000000000000"
		},
		"dcd10c55bb854f754434f1219c2c9a98ace79f03": {
			"balance": "4000086000000000000000"
		},
		"67048f3a12a4dd1f626c64264cb1d7971de2ca38": {
			"balance": "180000000000000000000"
		},
		"d33cf82bf14c592640a08608914c237079d5be34": {
			"balance": "2000000000000000000000"
		},
		"f5b068989df29c253577d0405ade6e0e7528f89e": {
			"balance": "1610000000000000000000"
		},
		"a9a8eca11a23d64689a2aa3e417dbb3d336bb59a": {
			"balance": "262025000000000000000"
		},
		"99413704b1a32e70f3bc0d69dd881c38566b54cb": {
			"balance": "27382708000000000000000"
		},
		"2a085e25b64862f5e68d768e2b0f7a8529858eee": {
			"balance": "1983618000000000000000"
		},
		"833d3fae542ad5f8b50ce19bde2bec579180c88c": {
			"balance": "346000000000000000000"
		},
		"c3483d6e88ac1f4ae73cc4408d6c03abe0e49dca": {
			"balance": "17000000000000000000000"
		},
		"fde395bc0b6d5cbb4c1d8fea3e0b4bff635e9db7": {
			"balance": "2000000000000000000000"
		},
		"eddacd94ec89a2ef968fcf977a08f1fae2757869": {
			"balance": "8000000000000000000000"
		},
		"dc29119745d2337320da51e19100c948d980b915": {
			"balance": "160000000000000000000"
		},
		"640bf87415e0cf407301e5599a68366da09bbac8": {
			"balance": "493207000000000000000"
		},
		"afcc7dbb8356d842d43ae7e23c8422b022a30803": {
			"balance": "30400000000000000000000"
		},
		"9120e71173e1ba19ba8f9f4fdbdcaa34e1d6bb78": {
			"balance": "2000000000000000000000"
		},
		"9092918707c621fdbd1d90fb80eb787fd26f7350": {
			"balance": "2460000000000000000000"
		},
		"263e57dacbe0149f82fe65a2664898866ff5b463": {
			"balance": "38000000000000000000000"
		},
		"315db7439fa1d5b423afa7dd7198c1cf74c918bc": {
			"balance": "600000000000000000000"
		},
		"09b4668696f86a080f8bebb91db8e6f87015915a": {
			"balance": "656010000000000000000"
		},
		"5c31996dcac015f9be985b611f468730ef244d90": {
			"balance": "200000000000000000000"
		},
		"b1179589e19db9d41557bbec1cb24ccc2dec1c7f": {
			"balance": "100000000000000000000000"
		},
		"3b1937d5e793b89b63fb8eb5f1b1c9ca6ba0fa8e": {
			"balance": "2000000000000000000000"
		},
		"c9127b7f6629ee13fc3f60bc2f4467a20745a762": {
			"balance": "16465639000000000000000"
		},
		"7306de0e288b56cfdf987ef0d3cc29660793f6dd": {
			"balance": "508060000000000000000"
		},
		"2aa192777ca5b978b6b2c2ff800ac1860f753f47": {
			"balance": "335000000000000000000"
		},
		"55da9dcdca61cbfe1f133c7bcefc867b9c8122f9": {
			"balance": "880000000000000000000"
		},
		"cdd9efac4d6d60bd71d95585dce5d59705c13564": {
			"balance": "100000000000000000000"
)E" + R"E(
		},
		"ad8e48a377695de014363a523a28b1a40c78f208": {
			"balance": "1000000000000000000000"
		},
		"252b6555afdc80f2d96d972d17db84ea5ad521ac": {
			"balance": "7880000000000000000000"
		},
		"60ab71cd26ea6d6e59a7a0f627ee079c885ebbf6": {
			"balance": "26740000000000000000"
		},
		"f40b134fea22c6b29c8457f49f000f9cda789adb": {
			"balance": "600000000000000000000"
		},
		"85a2f6ea94d05e8c1d9ae2f4910338a358e98ded": {
			"balance": "2000000000000000000000"
		},
		"ae13a08511110f32e53be4127845c843a1a57c7b": {
			"balance": "500000000000000000000"
		},
		"40db1ba585ce34531edec5494849391381e6ccd3": {
			"balance": "1790000000000000000000"
		},
		"0c5589a7a89b9ad15b02751930415948a875fbef": {
			"balance": "126000000000000000000"
		},
		"89054430dcdc28ac15fa635ef87c105e602bf70c": {
			"balance": "108000000000000000000"
		},
		"6c882c27732cef5c7c13a686f0a2ea77555ac289": {
			"balance": "100000000000000000000000"
		},
		"de374299c1d07d79537385190f442ef9ca24061f": {
			"balance": "133700000000000000000"
		},
		"b146a0b925553cf06fcaf54a1b4dfea621290757": {
			"balance": "2000200000000000000000"
		},
		"09ae49e37f121df5dc158cfde806f173a06b0c7f": {
			"balance": "3988000000000000000000"
		},
		"b758896f1baa864f17ebed16d953886fee68aae6": {
			"balance": "1000000000000000000000"
		},
		"30730466b8eb6dc90d5496aa76a3472d7dbe0bbe": {
			"balance": "1999800000000000000000"
		},
		"fc02734033e57f70517e0afc7ee62461f06fad8e": {
			"balance": "394000000000000000000"
		},
		"a9b2d2e0494eab18e07d37bbb856d80e80f84cd3": {
			"balance": "10000000000000000000000"
		},
		"95278b08dee7c0f2c8c0f722f9fcbbb9a5241fda": {
			"balance": "2408672000000000000000"
		},
		"dab6bcdb83cf24a0ae1cb21b3b5b83c2f3824927": {
			"balance": "50000000000000000000000"
		},
		"94439ca9cc169a79d4a09cae5e67764a6f871a21": {
			"balance": "240000000000000000000"
		},
		"e06c29a81517e0d487b67fb0b6aabc4f57368388": {
			"balance": "401100000000000000000"
		},
		"458e3cc99e947844a18e6a42918fef7e7f5f5eb3": {
			"balance": "36400000000000000000000"
		},
		"0a9804137803ba6868d93a55f9985fcd540451e4": {
			"balance": "13370000000000000000"
		},
		"40630024bd2c58d248edd8465617b2bf1647da0e": {
			"balance": "1000000000000000000000"
		},
		"15224ad1c0face46f9f556e4774a3025ad06bd52": {
			"balance": "13370000000000000000"
		},
		"2e2810dee44ae4dff3d86342ab126657d653c336": {
			"balance": "200000000000000000000"
		},
		"48a30de1c919d3fd3180e97d5f2b2a9dbd964d2d": {
			"balance": "44000000000000000000"
		},
		"46a30b8a808931217445c3f5a93e882c0345b426": {
			"balance": "250019000000000000000"
		},
		"455396a4bbd9bae8af9fb7c4d64d471db9c24505": {
			"balance": "161000000000000000000"
		},
		"edfda2d5db98f9380714664d54b4ee971a1cae03": {
			"balance": "40044000000000000000"
		},
		"f5eadcd2d1b8657a121f33c458a8b13e76b65526": {
			"balance": "249828000000000000000"
		},
		"90e7070f4d033fe6910c9efe5a278e1fc6234def": {
			"balance": "100392000000000000000"
		},
		"d55508adbbbe9be81b80f97a6ea89add68da674f": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"66925de3e43f4b41bf9dadde27d5488ef569ea0d": {
			"balance": "39400000000000000000"
		},
		"b7c077946674ba9341fb4c747a5d50f5d2da6415": {
			"balance": "1000000000000000000000"
		},
		"c52d1a0c73c2a1be84915185f8b34faa0adf1de3": {
			"balance": "1400001000000000000000"
		},
		"79b8aad879dd30567e8778d2d231c8f37ab8734e": {
			"balance": "2000000000000000000000"
		},
		"3aae4872fd9093cbcad1406f1e8078bab50359e2": {
			"balance": "39400000000000000000"
		},
		"b2e9d76bf50fc36bf7d3944b63e9ca889b699968": {
			"balance": "2660000000000000000000"
		},
		"405f596b94b947344c033ce2dcbff12e25b79784": {
			"balance": "2000000000000000000000"
		},
		"232cb1cd49993c144a3f88b3611e233569a86bd6": {
			"balance": "15576000000000000000000"
		},
		"9e232c08c14dc1a6ed0b8a3b2868977ba5c17d10": {
			"balance": "20000000000000000000"
		},
		"095270cc42141dd998ad2862dbd1fe9b44e7e650": {
			"balance": "1200000000000000000000"
		},
		"15d99468507aa0413fb60dca2adc7f569cb36b54": {
			"balance": "2000000000000000000000"
		},
		"04852732b4c652f6c2e58eb36587e60a62da14db": {
			"balance": "20000000000000000000000"
		},
		"ecf24cdd7c22928c441e694de4aa31b0fab59778": {
			"balance": "600000000000000000000"
		},
		"512b91bbfaa9e581ef683fc90d9db22a8f49f48b": {
			"balance": "310000000000000000000000"
		},
		"a88577a073fbaf33c4cd202e00ea70ef711b4006": {
			"balance": "2000000000000000000000"
		},
		"00acc6f082a442828764d11f58d6894ae408f073": {
			"balance": "60000000000000000000000"
		},
		"0355bcacbd21441e95adeedc30c17218c8a408ce": {
			"balance": "400000000000000000000"
		},
		"4e73cf2379f124860f73d6d91bf59acc5cfc845b": {
			"balance": "40110000000000000000"
		},
		"2a742b8910941e0932830a1d9692cfd28494cf40": {
			"balance": "499986000000000000000"
		},
		"41a8c2830081b102df6e0131657c07ab635b54ce": {
			"balance": "1999944000000000000000"
		},
		"b63064bd3355e6e07e2d377024125a33776c4afa": {
			"balance": "38800000000000000000000"
		},
		"1a25e1c5bc7e5f50ec16f8885f210ea1b938800e": {
			"balance": "4000000000000000000000"
		},
		"09b59b8698a7fbd3d2f8c73a008988de3e406b2b": {
			"balance": "40000000000000000000000"
		},
		"c555b93156f09101233c6f7cf6eb3c4f196d3346": {
			"balance": "3000000000000000000000"
		},
		"12f32c0a1f2daab676fe69abd9e018352d4ccd45": {
			"balance": "50000000000000000000"
		},
		"5956b28ec7890b76fc061a1feb52d82ae81fb635": {
			"balance": "2000000000000000000000"
		},
		"c739259e7f85f2659bef5f609ed86b3d596c201e": {
			"balance": "200000000000000000000"
		},
		"fae92c1370e9e1859a5df83b56d0f586aa3b404c": {
			"balance": "106480000000000000000"
		},
		"d5a7bec332adde18b3104b5792546aa59b879b52": {
			"balance": "2000000000000000000000"
		},
		"4f88dfd01091a45a9e2676021e64286cd36b8d34": {
			"balance": "1000000000000000000000"
		},
		"102c477d69aadba9a0b0f62b7459e17fbb1c1561": {
			"balance": "2000000000000000000000"
		},
		"34272d5e7574315dcae9abbd317bac90289d4765": {
			"balance": "1820000000000000000000"
		},
		"fe615d975c0887e0c9113ec7298420a793af8b96": {
			"balance": "8000000000000000000000"
		},
		"487adf7d70a6740f8d51cbdd68bb3f91c4a5ce68": {
)E" + R"E(
			"balance": "66850000000000000000"
		},
		"7e5d9993104e4cb545e179a2a3f971f744f98482": {
			"balance": "2000000000000000000000"
		},
		"5529830a61c1f13c197e550beddfd6bd195c9d02": {
			"balance": "10000000000000000000000"
		},
		"2f282abbb6d4a3c3cd3b5ca812f7643e80305f06": {
			"balance": "1850000000000000000000"
		},
		"7352586d021ad0cf77e0e928404a59f374ff4582": {
			"balance": "3400000000000000000000"
		},
		"03f7b92008813ae0a676eb212814afab35221069": {
			"balance": "2000000000000000000000"
		},
		"056686078fb6bcf9ba0a8a8dc63a906f5feac0ea": {
			"balance": "499800000000000000000"
		},
		"8063379a7bf2cb923a84c5093e68dac7f75481c5": {
			"balance": "322102000000000000000"
		},
		"200264a09f8c68e3e6629795280f56254f8640d0": {
			"balance": "20000000000000000000"
		},
		"5a891155f50e42074374c739baadf7df2651153a": {
			"balance": "4775000000000000000000"
		},
		"80022a1207e910911fc92849b069ab0cdad043d3": {
			"balance": "13370000000000000000"
		},
		"e781ec732d401202bb9bd13860910dd6c29ac0b6": {
			"balance": "1240000000000000000000"
		},
		"4c2f1afef7c5868c44832fc77cb03b55f89e6d6e": {
			"balance": "20000000000000000000000"
		},
		"34ff582952ff24458f7b13d51f0b4f987022c1fe": {
			"balance": "2804400000000000000000"
		},
		"73914b22fc2f131584247d82be4fecbf978ad4ba": {
			"balance": "2000000000000000000000"
		},
		"562be95aba17c5371fe2ba828799b1f55d2177d6": {
			"balance": "38200000000000000000000"
		},
		"648f5bd2a2ae8902db37847d1cb0db9390b06248": {
			"balance": "7769965000000000000000"
		},
		"6a9758743b603eea3aa0524b42889723c4153948": {
			"balance": "10100000000000000000000"
		},
		"5985c59a449dfc5da787d8244e746c6d70caa55f": {
			"balance": "100000000000000000000"
		},
		"56ee197f4bbf9f1b0662e41c2bbd9aa1f799e846": {
			"balance": "1000000000000000000000"
		},
		"d47c242edffea091bc54d57df5d1fdb93101476c": {
			"balance": "2914000000000000000000"
		},
		"d482e7f68e41f238fe517829de15477fe0f6dd1d": {
			"balance": "500000000000000000000"
		},
		"05bf4fcfe772e45b826443852e6c351350ce72a2": {
			"balance": "8000000000000000000000"
		},
		"f10462e58fcc07f39584a187639451167e859201": {
			"balance": "169830000000000000000"
		},
		"1aa27699cada8dc3a76f7933aa66c71919040e88": {
			"balance": "400000000000000000000"
		},
		"24046b91da9b61b629cb8b8ec0c351a07e0703e4": {
			"balance": "2000000000000000000000"
		},
		"41033c1b6d05e1ca89b0948fc64453fbe87ab25e": {
			"balance": "1337000000000000000000"
		},
		"369822f5578b40dd1f4471706b22cd971352da6b": {
			"balance": "346000000000000000000"
		},
		"044e853144e3364495e7a69fa1d46abea3ac0964": {
			"balance": "49225000000000000000"
		},
		"abf728cf9312f22128024e7046c251f5dc5901ed": {
			"balance": "29550000000000000000000"
		},
		"d781f7fc09184611568570b4986e2c72872b7ed0": {
			"balance": "20002000000000000000"
		},
		"6bb4a661a33a71d424d49bb5df28622ed4dffcf4": {
			"balance": "630400000000000000000"
		},
		"fef3b3dead1a6926d49aa32b12c22af54d9ff985": {
			"balance": "1000000000000000000000"
		},
		"fa410971ad229c3036f41acf852f2ac999281950": {
			"balance": "3997400000000000000000"
)E" + R"E(
		},
		"de176b5284bcee3a838ba24f67fc7cbf67d78ef6": {
			"balance": "37600000000000000000"
		},
		"23120046f6832102a752a76656691c863e17e59c": {
			"balance": "329800000000000000000"
		},
		"a2f472fe4f22b77db489219ea4023d11582a9329": {
			"balance": "40000000000000000000000"
		},
		"f0d64cf9df09741133d170485fd24b005011d520": {
			"balance": "498680000000000000000"
		},
		"8b505e2871f7deb7a63895208e8227dcaa1bff05": {
			"balance": "61216600000000000000000"
		},
		"481e3a91bfdc2f1c8428a0119d03a41601417e1c": {
			"balance": "1000000000000000000000"
		},
		"bc69a0d2a31c3dbf7a9122116901b2bdfe9802a0": {
			"balance": "3000000000000000000000"
		},
		"20a81680e465f88790f0074f60b4f35f5d1e6aa5": {
			"balance": "1279851000000000000000"
		},
		"194a6bb302b8aba7a5b579df93e0df1574967625": {
			"balance": "500000000000000000000"
		},
		"264cc8086a8710f91b21720905912cd7964ae868": {
			"balance": "26740000000000000000"
		},
		"24aca08d5be85ebb9f3132dfc1b620824edfedf9": {
			"balance": "18200000000000000000"
		},
		"1851a063ccdb30549077f1d139e72de7971197d5": {
			"balance": "2000000000000000000000"
		},
		"f64a4ac8d540a9289c68d960d5fb7cc45a77831c": {
			"balance": "2000000000000000000000"
		},
		"c3db5657bb72f10d58f231fddf11980aff678693": {
			"balance": "5910000000000000000000"
		},
		"b46ace865e2c50ea4698d216ab455dff5a11cd72": {
			"balance": "1000000000000000000000"
		},
		"9faea13c733412dc4b490402bfef27a0397a9bc3": {
			"balance": "310000000000000000000"
		},
		"b40594c4f3664ef849cca6227b8a25aa690925ee": {
			"balance": "4000000000000000000000"
		},
		"672fa0a019088db3166f6119438d07a99f8ba224": {
			"balance": "13370000000000000000000"
		},
		"c1ffad07db96138c4b2a530ec1c7de29b8a0592c": {
			"balance": "17600000000000000000"
		},
		"87af25d3f6f8eea15313d5fe4557e810c524c083": {
			"balance": "19700000000000000000000"
		},
		"d6a22e598dabd38ea6e958bd79d48ddd9604f4df": {
			"balance": "1000000000000000000000"
		},
		"a2a435de44a01bd0ecb29e44e47644e46a0cdffb": {
			"balance": "500171000000000000000"
		},
		"549b47649cfad993e4064d2636a4baa0623305cc": {
			"balance": "601650000000000000000"
		},
		"1321b605026f4ffb296a3e0edcb390c9c85608b7": {
			"balance": "2000000000000000000000"
		},
		"b4bf24cb83686bc469869fefb044b909716993e2": {
			"balance": "2000000000000000000000"
		},
		"12d91a92d74fc861a729646db192a125b79f5374": {
			"balance": "18200000000000000000"
		},
		"7f0662b410298c99f311d3a1454a1eedba2fea76": {
			"balance": "200000000000000000000"
		},
		"83908aa7478a6d1c9b9b0281148f8f9f242b9fdc": {
			"balance": "2000000000000000000000"
		},
		"c1438c99dd51ef1ca8386af0a317e9b041457888": {
			"balance": "223500000000000000000"
		},
		"545bb070e781172eb1608af7fc2895d6cb87197e": {
			"balance": "2244000000000000000000"
		},
		"161d26ef6759ba5b9f20fdcd66f16132c352415e": {
			"balance": "2000000000000000000000"
		},
		"d7f370d4bed9d57c6f49c999de729ee569d3f4e4": {
			"balance": "200000000000000000000"
		},
		"90e35aabb2deef408bb9b5acef714457dfde6272": {
			"balance": "100076000000000000000"
		},
)E" + R"E(
		"0fcfc4065008cfd323305f6286b57a4dd7eee23b": {
			"balance": "20000000000000000000000"
		},
		"cd725d70be97e677e3c8e85c0b26ef31e9955045": {
			"balance": "1337000000000000000000"
		},
		"dcf6b657266e91a4dae6033ddac15332dd8d2b34": {
			"balance": "1760000000000000000000"
		},
		"31f006f3494ed6c16eb92aaf9044fa8abb5fd5a3": {
			"balance": "500000000000000000000"
		},
		"cdea386f9d0fd804d02818f237b7d9fa7646d35e": {
			"balance": "3012139000000000000000"
		},
		"d45b3341e8f15c80329320c3977e3b90e7826a7e": {
			"balance": "500000000000000000000"
		},
		"0b649da3b96a102cdc6db652a0c07d65b1e443e6": {
			"balance": "2000000000000000000000"
		},
		"0a58fddd71898de773a74fdae45e7bd84ef43646": {
			"balance": "20000000000000000000"
		},
		"0256149f5b5063bea14e15661ffb58f9b459a957": {
			"balance": "704000000000000000000"
		},
		"4438e880cb2766b0c1ceaec9d2418fceb952a044": {
			"balance": "133712000000000000000"
		},
		"9ed80eda7f55054db9fb5282451688f26bb374c1": {
			"balance": "300000000000000000000"
		},
		"8dab948ae81da301d972e3f617a912e5a753712e": {
			"balance": "400000000000000000000"
		},
		"5b5d8c8eed6c85ac215661de026676823faa0a0c": {
			"balance": "20000000000000000000000"
		},
		"46722a36a01e841d03f780935e917d85d5a67abd": {
			"balance": "14900000000000000000"
		},
		"d4b8bdf3df9a51b0b91d16abbea05bb4783c8661": {
			"balance": "1000000000000000000000"
		},
		"98f6b8e6213dbc9a5581f4cce6655f95252bdb07": {
			"balance": "319968000000000000000"
		},
		"3599493ce65772cf93e98af1195ec0955dc98002": {
			"balance": "1500048000000000000000"
		},
		"ecab5aba5b828de1705381f38bc744b32ba1b437": {
			"balance": "940000000000000000000"
		},
		"9a82826d3c29481dcc2bd2950047e8b60486c338": {
			"balance": "20000000000000000000000"
		},
		"6c474bc66a54780066aa4f512eefa773abf919c7": {
			"balance": "94000000000000000000"
		},
		"d5903e9978ee20a38c3f498d63d57f31a39f6a06": {
			"balance": "10380000000000000000000"
		},
		"341480cc8cb476f8d01ff30812e7c70e05afaf5d": {
			"balance": "2000000000000000000000"
		},
		"af771039345a343001bc0f8a5923b126b60d509c": {
			"balance": "985000000000000000000"
		},
		"b5a4679685fa14196c2e9230c8c4e33bffbc10e2": {
			"balance": "1400000000000000000000"
		},
		"2a400dff8594de7228b4fd15c32322b75bb87da8": {
			"balance": "95810000000000000000"
		},
		"a1336dfb96b6bcbe4b3edf3205be5723c90fad52": {
			"balance": "5000000000000000000000"
		},
		"e9b1f1fca3fa47269f21b061c353b7f5e96d905a": {
			"balance": "500000000000000000000"
		},
		"0ee414940487fd24e390378285c5d7b9334d8b65": {
			"balance": "2680000000000000000000"
		},
		"6ab5b4c41cddb829690c2fda7f20c85e629dd5d5": {
			"balance": "1860000000000000000000"
		},
		"dd63042f25ed32884ad26e3ad959eb94ea36bf67": {
			"balance": "21340000000000000000000"
		},
		"c0b3f244bca7b7de5b48a53edb9cbeab0b6d88c0": {
			"balance": "5820000000000000000000"
		},
		"ed1a5c43c574d4e934299b24f1472cdc9fd6f010": {
			"balance": "200000000000000000000"
		},
		"b2d9ab9664bcf6df203c346fc692fd9cbab9205e": {
			"balance": "438000000000000000000"
		},
		"ede8c2cb876fbe8a4cca8290361a7ea01a69fdf8": {
)E" + R"E(
			"balance": "7813091000000000000000"
		},
		"6a7c252042e7468a3ff773d6450bba85efa26391": {
			"balance": "500000000000000000000"
		},
		"a106e6923edd53ca8ed650968a9108d6ccfd9670": {
			"balance": "9499935000000000000000"
		},
		"031e25db516b0f099faebfd94f890cf96660836b": {
			"balance": "2000000000000000000000"
		},
		"7fdbc3a844e40d96b2f3a635322e6065f4ca0e84": {
			"balance": "2000000000000000000000"
		},
		"df47a61b72535193c561cccc75c3f3ce0804a20e": {
			"balance": "398000000000000000000"
		},
		"ed31305c319f9273d3936d8f5b2f71e9b1b22963": {
			"balance": "100000000000000000000"
		},
		"a6b2d573297360102c07a18fc21df2e7499ff4eb": {
			"balance": "4011000000000000000000"
		},
		"f68464bf64f2411356e4d3250efefe5c50a5f65b": {
			"balance": "20000000000000000000"
		},
		"927cc2bfda0e088d02eff70b38b08aa53cc30941": {
			"balance": "1852700000000000000000"
		},
		"41cb9896445f70a10a14215296daf614e32cf4d5": {
			"balance": "1910000000000000000000"
		},
		"3ad70243d88bf0400f57c8c1fd57811848af162a": {
			"balance": "860000000000000000000"
		},
		"63b9754d75d12d384039ec69063c0be210d5e0e3": {
			"balance": "2694055000000000000000"
		},
		"ad1799aad7602b4540cd832f9db5f11150f1687a": {
			"balance": "2000000000000000000000"
		},
		"a8b65ba3171a3f77a6350b9daf1f8d55b4d201eb": {
			"balance": "745000000000000000000"
		},
		"ad0a4ae478e9636e88c604f242cf5439c6d45639": {
			"balance": "3520000000000000000000"
		},
		"4cd0b0a6436362595ceade052ebc9b929fb6c6c0": {
			"balance": "2000000000000000000000"
		},
		"c1d4af38e9ba799040894849b8a8219375f1ac78": {
			"balance": "20000000000000000000000"
		},
		"49ddee902e1d0c99d1b11af3cc8a96f78e4dcf1a": {
			"balance": "199358000000000000000"
		},
		"ae842210f44d14c4a4db91fc9d3b3b50014f7bf7": {
			"balance": "4000000000000000000000"
		},
		"10a1c42dc1ba746986b985a522a73c93eae64c63": {
			"balance": "1000000000000000000000"
		},
		"5103bc09933e9921fd53dc536f11f05d0d47107d": {
			"balance": "4000000000000000000000"
		},
		"c88eec54d305c928cc2848c2fee23531acb96d49": {
			"balance": "1999946000000000000000"
		},
		"9a2ce43b5d89d6936b8e8c354791b8afff962425": {
			"balance": "2000000000000000000000"
		},
		"562020e3ed792d2f1835fe5f55417d5111460c6a": {
			"balance": "20000000000000000000000"
		},
		"ed16ce39feef3bd7f5d162045e0f67c0f00046bb": {
			"balance": "20000000000000000000"
		},
		"ab948a4ae3795cbca13126e19253bdc21d3a8514": {
			"balance": "200000000000000000000"
		},
		"c12b7f40df9a2f7bf983661422ab84c9c1f50858": {
			"balance": "8000000000000000000000"
		},
		"62e6b2f5eb94fa7a43831fc87e254a3fe3bf8f89": {
			"balance": "250000000000000000000"
		},
		"423bca47abc00c7057e3ad34fca63e375fbd8b4a": {
			"balance": "18000000000000000000000"
		},
		"5ff326cd60fd136b245e29e9087a6ad3a6527f0d": {
			"balance": "1880000000000000000000"
		},
		"79ffb4ac13812a0b78c4a37b8275223e176bfda5": {
			"balance": "17300000000000000000"
		},
		"f757fc8720d3c4fa5277075e60bd5c411aebd977": {
			"balance": "2000000000000000000000"
		},
		"0bdbc54cc8bdbbb402a08911e2232a5460ce866b": {
			"balance": "3000000000000000000000"
)E" + R"E(
		},
		"9ee9760cc273d4706aa08375c3e46fa230aff3d5": {
			"balance": "8950000000000000000000"
		},
		"d23a24d7f9468343c143a41d73b88f7cbe63be5e": {
			"balance": "200000000000000000000"
		},
		"46d80631284203f6288ecd4e5758bb9d41d05dbe": {
			"balance": "2000000000000000000000"
		},
		"3f4cd1399f8a34eddb9a17a471fc922b5870aafc": {
			"balance": "200000000000000000000"
		},
		"44c54eaa8ac940f9e80f1e74e82fc14f1676856a": {
			"balance": "7880000000000000000000"
		},
		"aec27ff5d7f9ddda91183f46f9d52543b6cd2b2f": {
			"balance": "450000000000000000000"
		},
		"203c6283f20df7bc86542fdfb4e763ecdbbbeef5": {
			"balance": "25000000000000000000000"
		},
		"bcaf347918efb2d63dde03e39275bbe97d26df50": {
			"balance": "100000000000000000000"
		},
		"974d0541ab4a47ec7f75369c0069b64a1b817710": {
			"balance": "400000000000000000000"
		},
		"5da54785c9bd30575c89deb59d2041d20a39e17b": {
			"balance": "1967031000000000000000"
		},
		"1fb463a0389983df7d593f7bdd6d78497fed8879": {
			"balance": "20000000000000000000"
		},
		"6e1ea4b183e252c9bb7767a006d4b43696cb8ae9": {
			"balance": "294245000000000000000"
		},
		"c2aa74847e86edfdd3f3db22f8a2152feee5b7f7": {
			"balance": "2048852000000000000000"
		},
		"a13b9d82a99b3c9bba5ae72ef2199edc7d3bb36c": {
			"balance": "1999944000000000000000"
		},
		"5135fb8757600cf474546252f74dc0746d06262c": {
			"balance": "2000000000000000000000"
		},
		"43e7ec846358d7d0f937ad1c350ba069d7bf72bf": {
			"balance": "118800000000000000000"
		},
		"f2ed3e77254acb83231dc0860e1a11242ba627db": {
			"balance": "1980000000000000000000"
		},
		"c0a02ab94ebe56d045b41b629b98462e3a024a93": {
			"balance": "100000000000000000000"
		},
		"f21549bdd1487912f900a7523db5f7626121bba3": {
			"balance": "10000000000000000000000"
		},
		"886d0a9e17c9c095af2ea2358b89ec705212ee94": {
			"balance": "28000000000000000000"
		},
		"211b29cefc79ae976744fdebcebd3cbb32c51303": {
			"balance": "14000000000000000000000"
		},
		"b8c2703d8c3f2f44c584bc10e7c0a6b64c1c097e": {
			"balance": "5550000000000000000000"
		},
		"ec30addd895b82ee319e54fb04cb2bb03971f36b": {
			"balance": "2000000000000000000000"
		},
		"b71b62f4b448c02b1201cb5e394ae627b0a560ee": {
			"balance": "500000000000000000000"
		},
		"e1334e998379dfe983177062791b90f80ee22d8d": {
			"balance": "500000000000000000000"
		},
		"1d633097a85225a1ff4321b12988fdd55c2b3844": {
			"balance": "4000000000000000000000"
		},
		"8bd8d4c4e943f6c8073921dc17e3e8d7a0761627": {
			"balance": "2933330000000000000000"
		},
		"a5d96e697d46358d119af7819dc7087f6ae47fef": {
			"balance": "14605131000000000000000"
		},
		"d0809498c548047a1e2a2aa6a29cd61a0ee268bd": {
			"balance": "2000000000000000000000"
		},
		"3cd6b7593cbee77830a8b19d0801958fcd4bc57a": {
			"balance": "500000000000000000000"
		},
		"ead4d2eefb76abae5533961edd11400406b298fc": {
			"balance": "3880000000000000000000"
		},
		"6331028cbb5a21485bc51b565142993bdb2582a9": {
			"balance": "534800000000000000000"
		},
		"163bad4a122b457d64e8150a413eae4d07023e6b": {
			"balance": "18800000000000000000"
		},
)E" + R"E(
		"c522e20fbf04ed7f6b05a37b4718d6fce0142e1a": {
			"balance": "4000000000000000000000"
		},
		"2d9bad6f1ee02a70f1f13def5cccb27a9a274031": {
			"balance": "1790000000000000000000"
		},
		"5ed0d6338559ef44dc7a61edeb893fa5d83fa1b5": {
			"balance": "220000000000000000000"
		},
		"ec8c1d7b6aaccd429db3a91ee4c9eb1ca4f6f73c": {
			"balance": "4250000000000000000000"
		},
		"3896ad743579d38e2302454d1fb6e2ab69e01bfd": {
			"balance": "1880000000000000000000"
		},
		"e73ccf436725c151e255ccf5210cfce5a43f13e3": {
			"balance": "19982000000000000000"
		},
		"9483d98f14a33fdc118d403955c29935edfc5f70": {
			"balance": "459600000000000000000"
		},
		"1cfcf7517f0c08459720942b647ad192aa9c8828": {
			"balance": "800000000000000000000"
		},
		"8d378f0edc0bb0f0686d6a20be6a7692c4fa24b8": {
			"balance": "100000000000000000000"
		},
		"06f68de3d739db41121eacf779aada3de8762107": {
			"balance": "28000000000000000000"
		},
		"9909650dd5b1397b8b8b0eb69499b291b0ad1213": {
			"balance": "200000000000000000000"
		},
		"b66675142e3111a1c2ea1eb2419cfa42aaf7a234": {
			"balance": "1000000000000000000000"
		},
		"7836f7ef6bc7bd0ff3acaf449c84dd6b1e2c939f": {
			"balance": "4142296000000000000000"
		},
		"3ddedbe48923fbf9e536bf9ffb0747c9cdd39eef": {
			"balance": "16100000000000000000000"
		},
		"c47d610b399250f70ecf1389bab6292c91264f23": {
			"balance": "288800000000000000000"
		},
		"51a6d627f66a8923d88d6094c4715380d3057cb6": {
			"balance": "1152044000000000000000"
		},
		"6c0cc917cbee7d7c099763f14e64df7d34e2bf09": {
			"balance": "250000000000000000000"
		},
		"aaaae68b321402c8ebc13468f341c63c0cf03fce": {
			"balance": "1520000000000000000000"
		},
		"819cdaa5303678ef7cec59d48c82163acc60b952": {
			"balance": "14523448000000000000000"
		},
		"d071192966eb69c3520fca3aa4dd04297ea04b4e": {
			"balance": "110000000000000000000"
		},
		"e53425d8df1f11c341ff58ae5f1438abf1ca53cf": {
			"balance": "322000000000000000000"
		},
		"8ffe322997b8e404422d19c54aadb18f5bc8e9b7": {
			"balance": "3940000000000000000000"
		},
		"305f78d618b990b4295bac8a2dfa262884f804ea": {
			"balance": "4000000000000000000000"
		},
		"274d69170fe7141401882b886ac4618c6ae40edb": {
			"balance": "955000000000000000000"
		},
		"69c94e07c4a9be3384d95dfa3cb9290051873b7b": {
			"balance": "70000000000000000000"
		},
		"859c600cf13d1d0273d5d1da3cd789e495899f27": {
			"balance": "2674000000000000000000"
		},
		"c06cebbbf7f5149a66f7eb976b3e47d56516da2f": {
			"balance": "2000000000000000000000"
		},
		"37bbc47212d82fcb5ee08f5225ecc2041ad2da7d": {
			"balance": "3280000000000000000000"
		},
		"11e7997edd904503d77da6038ab0a4c834bbd563": {
			"balance": "388000000000000000000"
		},
		"d333627445f2d787901ef33bb2a8a3675e27ffec": {
			"balance": "400000000000000000000"
		},
		"16a58e985dccd707a594d193e7cca78b5d027849": {
			"balance": "1360000000000000000000"
		},
		"f8ae857b67a4a2893a3fbe7c7a87ff1c01c6a6e7": {
			"balance": "4000000000000000000000"
		},
		"491561db8b6fafb9007e62d050c282e92c4b6bc8": {
			"balance": "30000000000000000000000"
		},
		"21df1ec24b4e4bfe79b0c095cebae198f291fbd1": {
)E" + R"E(
			"balance": "20000000000000000000000"
		},
		"e208812a684098f3da4efe6aba256256adfe3fe6": {
			"balance": "2000000000000000000000"
		},
		"f4ec8e97a20aa5f8dd206f55207e06b813df2cc0": {
			"balance": "200000000000000000000"
		},
		"29eb7eefdae9feb449c63ff5f279d67510eb1422": {
			"balance": "19400000000000000000"
		},
		"0d678706d037187f3e22e6f69b99a592d11ebc59": {
			"balance": "1580000000000000000000"
		},
		"de6d363106cc6238d2f092f0f0372136d1cd50c6": {
			"balance": "5348000000000000000000"
		},
		"c8710d7e8b5a3bd69a42fe0fa8b87c357fddcdc8": {
			"balance": "4000000000000000000000"
		},
		"5267f4d41292f370863c90d793296903843625c7": {
			"balance": "1400000000000000000000"
		},
		"4cda41dd533991290794e22ae324143e309b3d3d": {
			"balance": "2400000000000000000000"
		},
		"f8a50cee2e688ceee3aca4d4a29725d4072cc483": {
			"balance": "2000000000000000000000"
		},
		"5ed3bbc05240e0d399eb6ddfe60f62de4d9509af": {
			"balance": "193999806000000000000000"
		},
		"0befb54707f61b2c9fb04715ab026e1bb72042bd": {
			"balance": "4000000000000000000000"
		},
		"cab9a301e6bd46e940355028eccd40ce4d5a1ac3": {
			"balance": "400000000000000000000"
		},
		"64672da3ab052821a0243d1ce4b6e0a36517b8eb": {
			"balance": "200000000000000000000"
		},
		"eac0827eff0c6e3ff28a7d4a54f65cb7689d7b99": {
			"balance": "2856500000000000000000"
		},
		"f4b6cdcfcb24230b337d770df6034dfbd4e1503f": {
			"balance": "19000000000000000000000"
		},
		"7be2f7680c802da6154c92c0194ae732517a7169": {
			"balance": "18200000000000000000"
		},
		"869f1aa30e4455beb1822091de5cadec79a8f946": {
			"balance": "8000000000000000000000"
		},
		"c4681e73bb0e32f6b726204831ff69baa4877e32": {
			"balance": "1820000000000000000000"
		},
		"962cd22a8edf1e4f4e55b4b15ddbfb5d9d541971": {
			"balance": "2000000000000000000000"
		},
		"131df8d330eb7cc7147d0a55576f05de8d26a8b7": {
			"balance": "188000000000000000000"
		},
		"19f99f2c0b46ce8906875dc9f90ae104dae35594": {
			"balance": "4507300000000000000000"
		},
		"91bb3f79022bf3c453f4ff256e269b15cf2c9cbd": {
			"balance": "1519000000000000000000"
		},
		"7301dc4cf26d7186f2a11bf8b08bf229463f64a3": {
			"balance": "2000000000000000000000"
		},
		"7cbca88fca6a0060b960985c9aa1b02534dc2208": {
			"balance": "462500000000000000000"
		},
		"f3c1abd29dc57b41dc192d0e384d021df0b4f6d4": {
			"balance": "2798000000000000000000"
		},
		"5d32f6f86e787ff78e63d78b0ef95fe6071852b8": {
			"balance": "401100000000000000000"
		},
		"1678c5f2a522393225196361894f53cc752fe2f3": {
			"balance": "1936000000000000000000"
		},
		"1cf04cb14380059efd3f238b65d5beb86afa14d8": {
			"balance": "20000000000000000000"
		},
		"52e1731350f983cc2c4189842fde0613fad50ce1": {
			"balance": "11640000000000000000000"
		},
		"d0b11d6f2bce945e0c6a5020c3b52753f803f9d1": {
			"balance": "200000000000000000000"
		},
		"409bd75085821c1de70cdc3b11ffc3d923c74010": {
			"balance": "4000000000000000000000"
		},
		"0bb7160aba293762f8734f3e0326ffc9a4cac190": {
			"balance": "1000000000000000000000"
		},
		"7aad4dbcd3acf997df93586956f72b64d8ad94ee": {
			"balance": "4000000000000000000000"
)E" + R"E(
		},
		"2dec98329d1f96c3a59caa7981755452d4da49d5": {
			"balance": "200000000000000000000"
		},
		"c18ab467feb5a0aadfff91230ff056464d78d800": {
			"balance": "2000000000000000000000"
		},
		"c90c3765156bca8e4897ab802419153cbe5225a9": {
			"balance": "200000000000000000000"
		},
		"85c8f3cc7a354feac99a5e7bfe7cdfa351cfe355": {
			"balance": "400000000000000000000"
		},
		"f4fc4d39bc0c2c4068a36de50e4ab4d4db7e340a": {
			"balance": "25380000000000000000"
		},
		"f50abbd4aa45d3eb88515465a8ba0b310fd9b521": {
			"balance": "6685000000000000000000"
		},
		"4d200110124008d56f76981256420c946a6ff45c": {
			"balance": "199955000000000000000"
		},
		"f4ba6a46d55140c439cbcf076cc657136262f4f8": {
			"balance": "2000000000000000000000"
		},
		"fa7adf660b8d99ce15933d7c5f072f3cbeb99d33": {
			"balance": "5910000000000000000000"
		},
		"84503334630d77f74147f68b2e086613c8f1ade9": {
			"balance": "1600000000000000000000"
		},
		"31ed858788bda4d5270992221cc04206ec62610d": {
			"balance": "1176000000000000000000"
		},
		"bfbca418d3529cb393081062032a6e1183c6b2dc": {
			"balance": "8000000000000000000000"
		},
		"8263ece5d709e0d7ae71cca868ed37cd2fef807b": {
			"balance": "990000000000000000000"
		},
		"23ba3864da583dab56f420873c37679690e02f00": {
			"balance": "9800000000000000000000"
		},
		"cedcb3a1d6843fb6bef643617deaf38f8e98dd5f": {
			"balance": "477500000000000000000"
		},
		"8fac748f784a0fed68dba43319b42a75b4649c6e": {
			"balance": "910000000000000000000"
		},
		"18b8bcf98321da61fb4e3eacc1ec5417272dc27e": {
			"balance": "880000000000000000000"
		},
		"776943ffb2ef5cdd35b83c28bc046bd4f4677098": {
			"balance": "3000000000000000000000"
		},
		"fb8113f94d9173eefd5a3073f516803a10b286ae": {
			"balance": "80000000000000000000"
		},
		"3e8349b67f5745449f659367d9ad4712db5b895a": {
			"balance": "1820000000000000000000"
		},
		"79cfa9780ae6d87b2c31883f09276986c89a6735": {
			"balance": "1000000000000000000000"
		},
		"5006fe4c22173980f00c74342b39cd231c653129": {
			"balance": "2000000000000000000000"
		},
		"13848b46ea75beb7eaa85f59d866d77fd24cf21a": {
			"balance": "50000000000000000000000"
		},
		"d64a2d50f8858537188a24e0f50df1681ab07ed7": {
			"balance": "38800000000000000000000"
		},
		"4f9ce2af9b8c5e42c6808a3870ec576f313545d1": {
			"balance": "10000000000000000000000"
		},
		"8764d02722000996ecd475b433298e9f540b05bf": {
			"balance": "200000000000000000000"
		},
		"3b7c77dbe95dc2602ce3269a9545d04965fefdbd": {
			"balance": "2000000000000000000000"
		},
		"c9dcbb056f4db7d9da39936202c5bd8230b3b477": {
			"balance": "20000000000000000000000"
		},
		"9ecbabb0b22782b3754429e1757aaba04b81189f": {
			"balance": "823743000000000000000"
		},
		"831c44b3084047184b2ad218680640903750c45d": {
			"balance": "1970000000000000000000"
		},
		"ff8eb07de3d49d9d52bbe8e5b26dbe1d160fa834": {
			"balance": "3986000000000000000000"
		},
		"8ccf3aa21ab742576ad8c422f71bb188591dea8a": {
			"balance": "1000000000000000000000"
		},
		"ddac312a9655426a9c0c9efa3fd82559ef4505bf": {
			"balance": "401100000000000000000"
		},
)E" + R"E(
		"9a3e2b1bf346dd070b027357feac44a4b2c97db8": {
			"balance": "10000000000000000000000"
		},
		"69d39d510889e552a396135bfcdb06e37e387633": {
			"balance": "4000000000000000000000"
		},
		"83a3148833d9644984f7c475a7850716efb480ff": {
			"balance": "3400000000000000000000"
		},
		"62b4a9226e61683c72c183254690daf511b4117a": {
			"balance": "260000000000000000000"
		},
		"50763add868fd7361178342fc055eaa2b95f6846": {
			"balance": "66838000000000000000"
		},
		"91898eab8c05c0222883cd4db23b7795e1a24ad7": {
			"balance": "2000000000000000000000"
		},
		"066647cfc85d23d37605573d208ca154b244d76c": {
			"balance": "10000000000000000000000"
		},
		"aaf9ee4b886c6d1e95496fd274235bf4ecfcb07d": {
			"balance": "1400000000000000000000"
		},
		"06860a93525955ff624940fadcffb8e149fd599c": {
			"balance": "1999800000000000000000"
		},
		"e81c2d346c0adf4cc56708f6394ba6c8c8a64a1e": {
			"balance": "2000000000000000000000"
		},
		"41a8e236a30e6d63c1ff644d132aa25c89537e01": {
			"balance": "20000000000000000000"
		},
		"6a679e378fdce6bfd97fe62f043c6f6405d79e99": {
			"balance": "4000000000000000000000"
		},
		"933436c8472655f64c3afaaf7c4c621c83a62b38": {
			"balance": "1000000000000000000000"
		},
		"abe07ced6ac5ddf991eff6c3da226a741bd243fe": {
			"balance": "10000000000000000000000"
		},
		"bb56a404723cff20d0685488b05a02cdc35aacaa": {
			"balance": "20000000000000000000"
		},
		"0d551ec1a2133c981d5fc6a8c8173f9e7c4f47af": {
			"balance": "2000000000000000000000"
		},
		"23376ecabf746ce53321cf42c86649b92b67b2ff": {
			"balance": "2000000000000000000000"
		},
		"644ba6c61082e989109f5c11d4b40e991660d403": {
			"balance": "4000000000000000000000"
		},
		"680d5911ed8dd9eec45c060c223f89a7f620bbd5": {
			"balance": "20000000000000000000000"
		},
		"cb1bb6f1da5eb10d4899f7e61d06c1b00fdfb52d": {
			"balance": "1038000000000000000000"
		},
		"303a30ac4286ae17cf483dad7b870c6bd64d7b4a": {
			"balance": "500000000000000000000"
		},
		"7b0b31ff6e24745ead8ed9bb85fc0bf2fe1d55d4": {
			"balance": "800000000000000000000"
		},
		"854691ce714f325ced55ce5928ce9ba12facd1b8": {
			"balance": "4380000000000000000000"
		},
		"a13cfe826d6d1841dcae443be8c387518136b5e8": {
			"balance": "140000000000000000000000"
		},
		"5fcd84546896dd081db1a320bd4d8c1dd1528c4c": {
			"balance": "20000000000000000000"
		},
		"3db5fe6a68bd3612ac15a99a61e555928eeceaf3": {
			"balance": "1580000000000000000000"
		},
		"7a79e30ff057f70a3d0191f7f53f761537af7dff": {
			"balance": "400000000000000000000"
		},
		"3d3fad49c9e5d2759c8e8e5a7a4d60a0dd135692": {
			"balance": "20000000000000000000"
		},
		"05a830724302bc0f6ebdaa1ebeeeb46e6ce00b39": {
			"balance": "98500000000000000000"
		},
		"e4b6ae22c7735f5b89f34dd77ad0975f0acc9181": {
			"balance": "1000000000000000000000"
		},
		"3f2dd55db7eab0ebee65b33ed8202c1e992e958b": {
			"balance": "820000000000000000000"
		},
		"395d6d255520a8db29abc47d83a5db8a1a7df087": {
			"balance": "100000000000000000000"
		},
		"1cc90876004109cd79a3dea866cb840ac364ba1b": {
			"balance": "2000000000000000000000"
		},
		"c83e9d6a58253beebeb793e6f28b054a58491b74": {
)E" + R"E(
			"balance": "281800000000000000000"
		},
		"901d99b699e5c6911519cb2076b4c76330c54d22": {
			"balance": "2000000000000000000000"
		},
		"3a9132b7093d3ec42e1e4fb8cb31ecdd43ae773c": {
			"balance": "2000000000000000000000"
		},
		"b41eaf5d51a5ba1ba39bb418dbb54fab750efb1f": {
			"balance": "1000000000000000000000"
		},
		"aa493d3f4fb866491cf8f800efb7e2324ed7cfe5": {
			"balance": "1700000000000000000000"
		},
		"509982f56237ee458951047e0a2230f804e2e895": {
			"balance": "17500000000000000000000"
		},
		"316e92a91bbda68b9e2f98b3c048934e3cc0b416": {
			"balance": "2000000000000000000000"
		},
		"a3430e1f647f321ed34739562323c7d623410b56": {
			"balance": "999942000000000000000"
		},
		"fca43bbc23a0d321ba9e46b929735ce7d8ef0c18": {
			"balance": "20000000000000000000"
		},
		"ff45cb34c928364d9cc9d8bb00373474618f06f3": {
			"balance": "100000000000000000000"
		},
		"8c999591fd72ef7111efca7a9e97a2356b3b000a": {
			"balance": "4084000000000000000000"
		},
		"8579dadf1a395a3471e20b6f763d9a0ff19a3f6f": {
			"balance": "4000000000000000000000"
		},
		"c8d4e1599d03b79809e0130a8dc38408f05e8cd3": {
			"balance": "2945500000000000000000"
		},
		"2abce1808940cd4ef5b5e05285f82df7a9ab5e03": {
			"balance": "9800000000000000000000"
		},
		"0bb0c12682a2f15c9b5741b2385cbe41f034068e": {
			"balance": "1500000000000000000000"
		},
		"08b7bdcf944d5570838be70460243a8694485858": {
			"balance": "2000000000000000000000"
		},
		"c452e0e4b3d6ae06b836f032ca09db409ddfe0fb": {
			"balance": "800000000000000000000"
		},
		"48d4f2468f963fd79a006198bb67895d2d5aa4d3": {
			"balance": "1400000000000000000000"
		},
		"f9e7222faaf0f4da40c1c4a40630373a09bed7b6": {
			"balance": "2865000000000000000000"
		},
		"bf59aee281fa43fe97194351a9857e01a3b897b2": {
			"balance": "600000000000000000000"
		},
		"da0d4b7ef91fb55ad265f251142067f10376ced6": {
			"balance": "20000000000000000000000"
		},
		"2c6f5c124cc789f8bb398e3f889751bc4b602d9e": {
			"balance": "24928000000000000000"
		},
		"c85ef27d820403805fc9ed259fff64acb8d6346a": {
			"balance": "2000000000000000000000"
		},
		"9aa8308f42910e5ade09c1a5e282d6d91710bdbf": {
			"balance": "200000000000000000000"
		},
		"9e4cec353ac3e381835e3c0991f8faa5b7d0a8e6": {
			"balance": "9999917000000000000000"
		},
		"137cf341e8516c815814ebcd73e6569af14cf7bc": {
			"balance": "1000000000000000000000"
		},
		"889da662eb4a0a2a069d2bc24b05b4ee2e92c41b": {
			"balance": "1663417000000000000000"
		},
		"0998d8273115b56af43c505e087aff0676ed3659": {
			"balance": "3999984000000000000000"
		},
		"3e4d13c55a84e46ed7e9cb90fd355e8ad991e38f": {
			"balance": "1000000000000000000000"
		},
		"abc068b4979b0ea64a62d3b7aa897d73810dc533": {
			"balance": "1970000000000000000000"
		},
		"d8fdf546674738c984d8fab857880b3e4280c09e": {
			"balance": "20000000000000000000"
		},
		"aff161740a6d909fe99c59a9b77945c91cc91448": {
			"balance": "60000000000000000000"
		},
		"92ad1b3d75fba67d54663da9fc848a8ade10fa67": {
			"balance": "2000000000000000000000"
		},
		"819eb4990b5aba5547093da12b6b3c1093df6d46": {
			"balance": "1000000000000000000000"
)E" + R"E(
		},
		"643d9aeed4b180947ed2b9207cce4c3ddc55e1f7": {
			"balance": "200000000000000000000"
		},
		"ab3e62e77a8b225e411592b1af300752fe412463": {
			"balance": "9850000000000000000000"
		},
		"650b425555e4e4c51718146836a2c1ee77a5b421": {
			"balance": "20000000000000000000000"
		},
		"ba8e46d69d2e2343d86c60d82cf42c2041a0c1c2": {
			"balance": "100000000000000000000"
		},
		"f9570e924c95debb7061369792cf2efec2a82d5e": {
			"balance": "20000000000000000000"
		},
		"4dc4bf5e7589c47b28378d7503cf96488061dbbd": {
			"balance": "1760000000000000000000"
		},
		"3d7ea5bf03528100ed8af8aed2653e921b6e6725": {
			"balance": "1000000000000000000000"
		},
		"a02bde6461686e19ac650c970d0672e76dcb4fc2": {
			"balance": "8865000000000000000000"
		},
		"b0e760bb07c081777345e0578e8bc898226d4e3b": {
			"balance": "2000000000000000000000"
		},
		"979cbf21dfec8ace3f1c196d82df962534df394f": {
			"balance": "2832860000000000000000"
		},
		"9f8245c3ab7d173164861cd3991b94f1ba40a93a": {
			"balance": "2860000000000000000000"
		},
		"c25cf826550c8eaf10af2234fef904ddb95213be": {
			"balance": "1000000000000000000000"
		},
		"967bfaf76243cdb9403c67d2ceefdee90a3feb73": {
			"balance": "970582000000000000000"
		},
		"0b2113504534642a1daf102eee10b9ebde76e261": {
			"balance": "2733351000000000000000"
		},
		"74bc4a5e2045f4ff8db184cf3a9b0c065ad807d2": {
			"balance": "2000000000000000000000"
		},
		"f1da40736f99d5df3b068a5d745fafc6463fc9b1": {
			"balance": "121546000000000000000"
		},
		"0fa6c7b0973d0bae2940540e247d3627e37ca347": {
			"balance": "1000000000000000000000"
		},
		"72b05962fb2ad589d65ad16a22559eba1458f387": {
			"balance": "133700000000000000000"
		},
		"6ceae3733d8fa43d6cd80c1a96e8eb93109c83b7": {
			"balance": "298000000000000000000"
		},
		"28eaea78cd4d95faecfb68836eafe83520f3bbb7": {
			"balance": "200000000000000000000"
		},
		"f49f6f9baabc018c8f8e119e0115f491fc92a8a4": {
			"balance": "10000000000000000000000"
		},
		"833316985d47742bfed410604a91953c05fb12b0": {
			"balance": "2000000000000000000000"
		},
		"ead75016e3a0815072b6b108bcc1b799acf0383e": {
			"balance": "2000000000000000000000"
		},
		"0032403587947b9f15622a68d104d54d33dbd1cd": {
			"balance": "77500000000000000000"
		},
		"8f64b9c1246d857831643107d355b5c75fef5d4f": {
			"balance": "1999944000000000000000"
		},
		"15dcafcc2bace7b55b54c01a1c514626bf61ebd8": {
			"balance": "9400000000000000000000"
		},
		"6886ada7bbb0617bda842191c68c922ea3a8ac82": {
			"balance": "1160000000000000000000"
		},
		"f736dc96760012388fe88b66c06efe57e0d7cf0a": {
			"balance": "2100000000000000000000"
		},
		"0b288a5a8b75f3dc4191eb0457e1c83dbd204d25": {
			"balance": "4853000000000000000000"
		},
		"56b6c23dd2ec90b4728f3bb2e764c3c50c85f144": {
			"balance": "1000000000000000000000"
		},
		"6310b020fd98044957995092090f17f04e52cdfd": {
			"balance": "1580000000000000000000"
		},
		"b0baeb30e313776c4c6d247402ba4167afcda1cc": {
			"balance": "1970000000000000000000"
		},
		"7641f7d26a86cddb2be13081810e01c9c83c4b20": {
			"balance": "13370000000000000000"
		},
)E" + R"E(
		"07a8dadec142571a7d53a4297051786d072cba55": {
			"balance": "22729000000000000000"
		},
		"cc73dd356b4979b579b401d4cc7a31a268ddce5a": {
			"balance": "500000000000000000000"
		},
		"adf1acfe99bc8c14b304c8d905ba27657b8a7bc4": {
			"balance": "20000000000000000000000"
		},
		"72dabb5b6eed9e99be915888f6568056381608f8": {
			"balance": "208433000000000000000"
		},
		"9de20ae76aa08263b205d5142461961e2408d266": {
			"balance": "252000000000000000000"
		},
		"9d4ff989b7bed9ab109d10c8c7e55f02d76734ad": {
			"balance": "1000000000000000000000"
		},
		"e58dd23238ee6ea7c2138d385df500c325f376be": {
			"balance": "1820000000000000000000"
		},
		"4bd6dd0cff23400e1730ba7b894504577d14e74a": {
			"balance": "206028000000000000000000"
		},
		"35147430c3106500e79fa2f502462e94703c23b1": {
			"balance": "1999944000000000000000"
		},
		"c0ae14d724832e2fce2778de7f7b8daf7b12a93e": {
			"balance": "20000000000000000000"
		},
		"b57413060af3f14eb479065f1e9d19b3757ae8cc": {
			"balance": "40000000000000000000"
		},
		"7d04d2edc058a1afc761d9c99ae4fc5c85d4c8a6": {
			"balance": "314807840000000000000000"
		},
		"1c94d636e684eb155895ce6db4a2588fba1d001b": {
			"balance": "2000000000000000000000"
		},
		"c721b2a7aa44c21298e85039d00e2e460e670b9c": {
			"balance": "140800000000000000000"
		},
		"2d89a8006a4f137a20dc2bec46fe2eb312ea9654": {
			"balance": "200000000000000000000"
		},
		"646afba71d849e80c0ed59cac519b278e7f7abe4": {
			"balance": "1000000000000000000000"
		},
		"71f2cdd1b046e2da2fbb5a26723422b8325e25a3": {
			"balance": "99960000000000000000"
		},
		"2c9fa72c95f37d08e9a36009e7a4b07f29bad41a": {
			"balance": "16100000000000000000"
		},
		"848fbd29d67cf4a013cb02a4b176ef244e9ee68d": {
			"balance": "20116000000000000000"
		},
		"68190ca885da4231874c1cfb42b1580a21737f38": {
			"balance": "3820000000000000000000"
		},
		"9adf458bff3599eee1a26398853c575bc38c6313": {
			"balance": "280000000000000000000"
		},
		"b72220ade364d0369f2d2da783ca474d7b9b34ce": {
			"balance": "499986000000000000000"
		},
		"38e2af73393ea98a1d993a74df5cd754b98d529a": {
			"balance": "1790000000000000000000"
		},
		"4d38d90f83f4515c03cc78326a154d358bd882b7": {
			"balance": "185000000000000000000"
		},
		"aa8eb0823b07b0e6d20aadda0e95cf3835be192e": {
			"balance": "32000000000000000000"
		},
		"008639dabbe3aeac887b5dc0e43e13bcd287d76c": {
			"balance": "310200000000000000000"
		},
		"fa3a0c4b903f6ea52ea7ab7b8863b6a616ad6650": {
			"balance": "20000000000000000000"
		},
		"e26bf322774e18288769d67e3107deb7447707b8": {
			"balance": "2000000000000000000000"
		},
		"e061a4f2fc77b296d19ada238e49a5cb8ecbfa70": {
			"balance": "4000000000000000000000"
		},
		"b320834836d1dbfda9e7a3184d1ad1fd4320ccc0": {
			"balance": "1000000000000000000000"
		},
		"0ed3bb3a4eb554cfca97947d575507cdfd6d21d8": {
			"balance": "547863000000000000000"
		},
		"32fa0e86cd087dd68d693190f32d93310909ed53": {
			"balance": "4000000000000000000000"
		},
		"5b759fa110a31c88469f54d44ba303d57dd3e10f": {
			"balance": "1683760000000000000000"
		},
		"136f4907cab41e27084b9845069ff2fd0c9ade79": {
)E" + R"E(
			"balance": "4000000000000000000000"
		},
		"3d89e505cb46e211a53f32f167a877bec87f4b0a": {
			"balance": "25019000000000000000"
		},
		"57a852fdb9b1405bf53ccf9508f83299d3206c52": {
			"balance": "2000000000000000000000"
		},
		"747abc9649056d3926044d28c3ad09ed17b67d70": {
			"balance": "5000057000000000000000"
		},
		"5c29f9e9a523c1f8669448b55c48cbd47c25e610": {
			"balance": "964320000000000000000"
		},
		"30a9da72574c51e7ee0904ba1f73a6b7b83b9b9d": {
			"balance": "20200000000000000000"
		},
		"220e2b92c0f6c902b513d9f1e6fab6a8b0def3d7": {
			"balance": "800000000000000000000"
		},
		"5af7c072b2c5acd71c76addcce535cf7f8f93585": {
			"balance": "20000000000000000000"
		},
		"81556db27349ab8b27004944ed50a46e941a0f5f": {
			"balance": "3998000000000000000000"
		},
		"987618c85656207c7bac1507c0ffefa2fb64b092": {
			"balance": "64419000000000000000"
		},
		"e0f372347c96b55f7d4306034beb83266fd90966": {
			"balance": "400000000000000000000"
		},
		"71784c105117c1f68935797fe159abc74e43d16a": {
			"balance": "2001600000000000000000"
		},
		"9284f96ddb47b5186ee558aa31324df5361c0f73": {
			"balance": "16000000000000000000000"
		},
		"a60c1209754f5d87b181da4f0817a81859ef9fd8": {
			"balance": "50000000000000000000"
		},
		"5afda9405c8e9736514574da928de67456010918": {
			"balance": "6008500000000000000000"
		},
		"6978696d5150a9a263513f8f74c696f8b1397cab": {
			"balance": "6640000000000000000000"
		},
		"a9ad1926bc66bdb331588ea8193788534d982c98": {
			"balance": "30000000000000000000000"
		},
		"e3f80b40fb83fb97bb0d5230af4f6ed59b1c7cc8": {
			"balance": "1337000000000000000000"
		},
		"e207578e1f4ddb8ff6d5867b39582d71b9812ac5": {
			"balance": "3880000000000000000000"
		},
		"86883d54cd3915e549095530f9ab1805e8c5432d": {
			"balance": "4000000000000000000000"
		},
		"6974c8a414ceaefd3c2e4dfdbef430568d9a960b": {
			"balance": "334250000000000000000"
		},
		"532d32b00f305bcc24dcef56817d622f34fb2c24": {
			"balance": "1800000000000000000000"
		},
		"761f8a3a2af0a8bdbe1da009321fb29764eb62a1": {
			"balance": "10000000000000000000000"
		},
		"4677b04e0343a32131fd6abb39b1b6156bba3d5b": {
			"balance": "200000000000000000000"
		},
		"ef69781f32ffce33346f2c9ae3f08493f3e82f89": {
			"balance": "18200000000000000000"
		},
		"e3b3d2c9bf570be6a2f72adca1862c310936a43c": {
			"balance": "100100000000000000000"
		},
		"d19caf39bb377fdf2cf19bd4fb52591c2631a63c": {
			"balance": "1000000000000000000000"
		},
		"5d68324bcb776d3ffd0bf9fea91d9f037fd6ab0f": {
			"balance": "2000000000000000000000"
		},
		"1c99fe9bb6c6d1066d912099547fd1f4809eacd9": {
			"balance": "2000000000000000000000"
		},
		"bbfe0a830cace87b7293993a7e9496ce64f8e394": {
			"balance": "6000000000000000000000"
		},
		"26c0054b700d3a7c2dcbe275689d4f4cad16a335": {
			"balance": "2000000000000000000000"
		},
		"7d7e7c61779adb7706c94d32409a2bb4e994bf60": {
			"balance": "865992000000000000000"
		},
		"d037d215d11d1df3d54fbd321cd295c5465e273b": {
			"balance": "1400000000000000000000"
		},
		"08166f02313feae18bb044e7877c808b55b5bf58": {
			"balance": "1970000000000000000000"
)E" + R"E(
		},
		"781b1501647a2e06c0ed43ff197fccec35e1700b": {
			"balance": "3000000000000000000000"
		},
		"74316adf25378c10f576d5b41a6f47fa98fce33d": {
			"balance": "336082000000000000000"
		},
		"44e2fdc679e6bee01e93ef4a3ab1bcce012abc7c": {
			"balance": "410231000000000000000"
		},
		"178eaf6b8554c45dfde16b78ce0c157f2ee31351": {
			"balance": "320000000000000000000"
		},
		"cf923a5d8fbc3d01aa079d1cfe4b43ce071b1611": {
			"balance": "2000000000000000000000"
		},
		"0c28847e4f09dfce5f9b25af7c4e530f59c880fe": {
			"balance": "1000000000000000000000"
		},
		"54ce88275956def5f9458e3b95decacd484021a0": {
			"balance": "2000000000000000000000"
		},
		"9d4213339a01551861764c87a93ce8f85f87959a": {
			"balance": "200000000000000000000"
		},
		"e559b5fd337b9c5572a9bf9e0f2521f7d446dbe4": {
			"balance": "200000000000000000000"
		},
		"dcb03bfa6c1131234e56b7ea7c4f721487546b7a": {
			"balance": "1337000000000000000000"
		},
		"db6ff71b3db0928f839e05a7323bfb57d29c87aa": {
			"balance": "910000000000000000000"
		},
		"eb7c202b462b7cc5855d7484755f6e26ef43a115": {
			"balance": "2000000000000000000000"
		},
		"323486ca64b375474fb2b759a9e7a135859bd9f6": {
			"balance": "400000000000000000000"
		},
		"2c1df8a76f48f6b54bcf9caf56f0ee1cf57ab33d": {
			"balance": "10118000000000000000000"
		},
		"2cd87866568dd81ad47d9d3ad0846e5a65507373": {
			"balance": "400000000000000000000"
		},
		"8566610901aace38b83244f3a9c831306a67b9dc": {
			"balance": "3256000000000000000000"
		},
		"1c257ad4a55105ea3b58ed374b198da266c85f63": {
			"balance": "10000000000000000000000"
		},
		"cf4f1138f1bd6bf5b6d485cce4c1017fcb85f07d": {
			"balance": "882038000000000000000"
		},
		"c934becaf71f225f8b4a4bf7b197f4ac9630345c": {
			"balance": "20000000000000000000000"
		},
		"1e2bf4ba8e5ef18d37de6d6ad636c4cae489d0cc": {
			"balance": "2000000000000000000000"
		},
		"9d78a975b7db5e4d8e28845cfbe7e31401be0dd9": {
			"balance": "1340000000000000000000"
		},
		"16aa52cb0b554723e7060f21f327b0a68315fea3": {
			"balance": "250000000000000000000"
		},
		"97e28973b860c567402800fbb63ce39a048a3d79": {
			"balance": "97000000000000000000"
		},
		"4ac5acad000b8877214cb1ae00eac9a37d59a0fd": {
			"balance": "4000000000000000000000"
		},
		"01226e0ad8d62277b162621c62c928e96e0b9a8c": {
			"balance": "2000000000000000000000"
		},
		"479abf2da4d58716fd973a0d13a75f530150260a": {
			"balance": "20000000000000000000"
		},
		"31d81d526c195e3f10b5c6db52b5e59afbe0a995": {
			"balance": "264000000000000000000"
		},
		"749087ac0f5a97c6fad021538bf1d6cda18e0daa": {
			"balance": "1000000000000000000000"
		},
		"1565af837ef3b0bd4e2b23568d5023cd34b16498": {
			"balance": "393284000000000000000"
		},
		"997d6592a31589acc31b9901fbeb3cc3d65b3215": {
			"balance": "2000000000000000000000"
		},
		"9d207517422cc0d60de7c237097a4d4fce20940c": {
			"balance": "500000000000000000000"
		},
		"24b8b446debd1947955dd084f2c544933346d3ad": {
			"balance": "4324135000000000000000"
		},
		"107a03cf0842dbdeb0618fb587ca69189ec92ff5": {
			"balance": "1970000000000000000000"
		},
)E" + R"E(
		"7f603aec1759ea5f07c7f8d41a1428fbbaf9e762": {
			"balance": "20000000000000000000"
		},
		"53a244672895480f4a2b1cdf7da5e5a242ec4dbc": {
			"balance": "1000000000000000000000"
		},
		"7db4c7d5b797e9296e6382f203693db409449d62": {
			"balance": "400000000000000000000"
		},
		"2ae82dab92a66389eea1abb901d1d57f5a7cca0b": {
			"balance": "2000000000000000000000"
		},
		"16bc40215abbd9ae5d280b95b8010b4514ff1292": {
			"balance": "200000000000000000000"
		},
		"bba4fac3c42039d828e742cde0efffe774941b39": {
			"balance": "1999946000000000000000"
		},
		"5431ca427e6165a644bae326bd09750a178c650d": {
			"balance": "2000000000000000000000"
		},
		"dcf33965531380163168fc11f67e89c6f1bc178a": {
			"balance": "334885000000000000000"
		},
		"65fd02d704a12a4dace9471b0645f962a89671c8": {
			"balance": "28615000000000000000"
		},
		"135d1719bf03e3f866312479fe338118cd387e70": {
			"balance": "2000000000000000000000"
		},
		"f3159866c2bc86bba40f9d73bb99f1eee57bb9d7": {
			"balance": "1000000000000000000000"
		},
		"e3a4621b66004588e31206f718cb00a319889cf0": {
			"balance": "2000000000000000000000"
		},
		"abcdbc8f1dd13af578d4a4774a62182bedf9f9be": {
			"balance": "36660000000000000000"
		},
		"9fbe066de57236dc830725d32a02aef9246c6c5e": {
			"balance": "2000000000000000000000"
		},
		"81cfad760913d3c322fcc77b49c2ae3907e74f6e": {
			"balance": "197000000000000000000"
		},
		"0ab59d390702c9c059db148eb4f3fcfa7d04c7e7": {
			"balance": "18200000000000000000"
		},
		"2c2db28c3309375eea3c6d72cd6d0eec145afcc0": {
			"balance": "2000000000000000000000"
		},
		"08306de51981e7aca1856859b7c778696a6b69f9": {
			"balance": "3200000000000000000000"
		},
		"f814799f6ddf4dcb29c7ee870e75f9cc2d35326d": {
			"balance": "1000000000000000000000"
		},
		"ee867d20916bd2e9c9ece08aa04385db667c912e": {
			"balance": "50000000000000000000000"
		},
		"97a86f01ce3f7cfd4441330e1c9b19e1b10606ef": {
			"balance": "2000000000000000000000"
		},
		"4c759813ad1386bed27ffae9e4815e3630cca312": {
			"balance": "2000000000000000000000"
		},
		"8f226096c184ebb40105e08dac4d22e1c2d54d30": {
			"balance": "306552000000000000000"
		},
		"13acada8980affc7504921be84eb4944c8fbb2bd": {
			"balance": "1601600000000000000000"
		},
		"122dcfd81addb97d1a0e4925c4b549806e9f3beb": {
			"balance": "1514954000000000000000"
		},
		"232f525d55859b7d4e608d20487faadb00293135": {
			"balance": "4000000000000000000000"
		},
		"6f7ac681d45e418fce8b3a1db5bc3be6f06c9849": {
			"balance": "2000000000000000000000"
		},
		"0c8692eeff2a53d6d1688ed56a9ddbbd68dabba1": {
			"balance": "2000000000000000000000"
		},
		"6a6337833f8f6a6bf10ca7ec21aa810ed444f4cb": {
			"balance": "1028200000000000000000"
		},
		"209377b6ad3fe101c9685b3576545c6b1684e73c": {
			"balance": "1820000000000000000000"
		},
		"560fc08d079f047ed8d7df75551aa53501f57013": {
			"balance": "7600000000000000000000"
		},
		"8e78f351457d016f4ad2755ec7424e5c21ba6d51": {
			"balance": "146000000000000000000"
		},
		"2ce11a92fad024ff2b3e87e3b542e6c60dcbd996": {
			"balance": "4000000000000000000000"
		},
		"8ab839aeaf2ad37cb78bacbbb633bcc5c099dc46": {
)E" + R"E(
			"balance": "2000000000000000000000"
		},
		"673144f0ec142e770f4834fee0ee311832f3087b": {
			"balance": "500038000000000000000"
		},
		"ba8a63f3f40de4a88388bc50212fea8e064fbb86": {
			"balance": "2000000000000000000000"
		},
		"ee899b02cbcb3939cd61de1342d50482abb68532": {
			"balance": "1760000000000000000000"
		},
		"c2d9eedbc9019263d9d16cc5ae072d1d3dd9db03": {
			"balance": "20000000000000000000000"
		},
		"355c0c39f5d5700b41d375b3f17851dcd52401f9": {
			"balance": "3979000000000000000000"
		},
		"8179c80970182cc5b7d82a4df06ea94db63a25f3": {
			"balance": "727432000000000000000"
		},
		"b388b5dfecd2c5e4b596577c642556dbfe277855": {
			"balance": "20000000000000000000"
		},
		"a9e28337e6357193d9e2cb236b01be44b81427df": {
			"balance": "2200000000000000000000"
		},
		"04ba4bb87140022c214a6fac42db5a16dd954045": {
			"balance": "1000000000000000000000"
		},
		"67c926093e9b8927933810d98222d62e2b8206bb": {
			"balance": "1910000000000000000000"
		},
		"ed7346766e1a676d0d06ec821867a276a083bf31": {
			"balance": "4012890000000000000000"
		},
		"92558226b384626cad48e09d966bf1395ee7ea5d": {
			"balance": "334250000000000000000"
		},
		"bdf693f833c3fe471753184788eb4bfe4adc3f96": {
			"balance": "1970000000000000000000"
		},
		"4474299d0ee090dc90789a1486489c3d0d645e6d": {
			"balance": "1000000000000000000000"
		},
		"b1178ad47383c31c8134a1941cbcd474d06244e2": {
			"balance": "1000000000000000000000"
		},
		"979d681c617da16f21bcaca101ed16ed015ab696": {
			"balance": "1880000000000000000000"
		},
		"6b20c080606a79c73bd8e75b11717a4e8db3f1c3": {
			"balance": "299720000000000000000"
		},
		"b85218f342f8012eda9f274e63ce2152b2dcfdab": {
			"balance": "3100000000000000000000"
		},
		"530b61e42f39426d2408d40852b9e34ab5ebebc5": {
			"balance": "267400000000000000000"
		},
		"76afc225f4fa307de484552bbe1d9d3f15074c4a": {
			"balance": "2998800000000000000000"
		},
		"1e783e522ab7df0acaac9eeed3593039e5ac7579": {
			"balance": "203435800000000000000000"
		},
		"0f7bf6373f771a4601762c4dae5fbbf4fedd9cc9": {
			"balance": "2000000000000000000000"
		},
		"7a8797690ab77b5470bf7c0c1bba612508e1ac7d": {
			"balance": "8865000000000000000000"
		},
		"2a2ab6b74c7af1d9476bb5bcb4524797bedc3552": {
			"balance": "1000000000000000000000"
		},
		"523e140dc811b186dee5d6c88bf68e90b8e096fd": {
			"balance": "2000000000000000000000"
		},
		"ea8168fbf225e786459ca6bb18d963d26b505309": {
			"balance": "500000000000000000000"
		},
		"20ff3ede8cadb5c37b48cb14580fb65e23090a7b": {
			"balance": "42000000000000000000000"
		},
		"e482d255ede56b04c3e8df151f56e9ca62aaa8c2": {
			"balance": "500000000000000000000"
		},
		"2e0880a34596230720f05ac8f065af8681dcb6c2": {
			"balance": "100000000000000000000000"
		},
		"c674f28c8afd073f8b799691b2f0584df942e844": {
			"balance": "2000000000000000000000"
		},
		"b646df98b49442746b61525c81a3b04ba3106250": {
			"balance": "1970000000000000000000"
		},
		"d55c1c8dfbe1e02cacbca60fdbdd405b09f0b75f": {
			"balance": "2000000000000000000000"
		},
		"65ebaed27edb9dcc1957aee5f452ac2105a65c0e": {
			"balance": "43531987000000000000000"
)E" + R"E(
		},
		"f079e1b1265f50e8c8a98ec0c7815eb3aeac9eb4": {
			"balance": "20094000000000000000"
		},
		"867eba56748a5904350d2ca2a5ce9ca00b670a9b": {
			"balance": "20000000000000000000000"
		},
		"51ee0cca3bcb10cd3e983722ced8493d926c0866": {
			"balance": "999972000000000000000"
		},
		"88d541c840ce43cefbaf6d19af6b9859b573c145": {
			"balance": "170000000000000000000"
		},
		"f851b010f633c40af1a8f06a73ebbaab65077ab5": {
			"balance": "4400000000000000000000"
		},
		"e0aa69365555b73f282333d1e30c1bbd072854e8": {
			"balance": "7000000000000000000000"
		},
		"c7b1c83e63203f9547263ef6282e7da33b6ed659": {
			"balance": "18200000000000000000"
		},
		"af06f5fa6d1214ec43967d1bd4dde74ab814a938": {
			"balance": "88000000000000000000"
		},
		"991173601947c2084a62d639527e961512579af9": {
			"balance": "600000000000000000000"
		},
		"7a381122bada791a7ab1f6037dac80432753baad": {
			"balance": "10000000000000000000000"
		},
		"e766f34ff16f3cfcc97321721f43ddf5a38b0cf4": {
			"balance": "1550000000000000000000"
		},
		"d785a8f18c38b9bc4ffb9b8fa8c7727bd642ee1c": {
			"balance": "1000000000000000000000"
		},
		"aebd4f205de799b64b3564b256d42a711d37ef99": {
			"balance": "1177100000000000000000"
		},
		"a2fa17c0fb506ce494008b9557841c3f641b8cae": {
			"balance": "20000000000000000000"
		},
		"a8aca748f9d312ec747f8b6578142694c7e9f399": {
			"balance": "2000000000000000000000"
		},
		"950c68a40988154d2393fff8da7ccda99614f72c": {
			"balance": "4597943000000000000000"
		},
		"075d15e2d33d8b4fa7dba8b9e607f04a261e340b": {
			"balance": "1910000000000000000000"
		},
		"3616d448985f5d32aefa8b93a993e094bd854986": {
			"balance": "205400000000000000000"
		},
		"4bb9655cfb2a36ea7c637a7b859b4a3154e26ebe": {
			"balance": "16000000000000000000000"
		},
		"84949dba559a63bfc845ded06e9f2d9b7f11ef24": {
			"balance": "2000000000000000000000"
		},
		"937563d8a80fd5a537b0e66d20a02525d5d88660": {
			"balance": "2500000000000000000000"
		},
		"b183ebee4fcb42c220e47774f59d6c54d5e32ab1": {
			"balance": "1604266000000000000000"
		},
		"21e5d77320304c201c1e53b261a123d0a1063e81": {
			"balance": "86972000000000000000"
		},
		"fa14b566234abee73042c31d21717182cba14aa1": {
			"balance": "328000000000000000000"
		},
		"2da617695009cc57d26ad490b32a5dfbeb934e5e": {
			"balance": "20000000000000000000000"
		},
		"3326b88de806184454c40b27f309d9dd6dcfb978": {
			"balance": "17900000000000000000000"
		},
		"95e6a54b2d5f67a24a4875af75107ca7ea9fd2fa": {
			"balance": "1337000000000000000000"
		},
		"8db58e406e202df9bc703c480bd8ed248d52a032": {
			"balance": "2000000000000000000000"
		},
		"f777361a3dd8ab62e5f1b9b047568cc0b555704c": {
			"balance": "1000000000000000000000"
		},
		"83a93b5ba41bf88720e415790cdc0b67b4af34c4": {
			"balance": "200000000000000000000"
		},
		"8a1cc5ac111c49bfcfd848f37dd768aa65c88802": {
			"balance": "10000000000000000000000"
		},
		"52214378b54004056a7cc08c891327798ac6b248": {
			"balance": "15200000000000000000000"
		},
		"ad80d865b85c34d2e6494b2e7aefea6b9af184db": {
			"balance": "4000000000000000000000"
		},
)E" + R"E(
		"e7d6240620f42c5edbb2ede6aec43da4ed9b5757": {
			"balance": "1000000000000000000000"
		},
		"d0e35e047646e759f4517093d6408642517f084d": {
			"balance": "3939507000000000000000"
		},
		"9340345ca6a3eabdb77363f2586043f29438ce0b": {
			"balance": "530922000000000000000"
		},
		"6640ccf053555c130ae2b656647ea6e31637b9ab": {
			"balance": "1970000000000000000000"
		},
		"184d86f3466ae6683b19729982e7a7e1a48347b2": {
			"balance": "10000000000000000000000"
		},
		"84ec06f24700fe42414cb9897c154c88de2f6132": {
			"balance": "1337000000000000000000"
		},
		"d1e5e234a9f44266a4a6241a84d7a1a55ad5a7fe": {
			"balance": "20000000000000000000000"
		},
		"e8a9a41740f44f54c3688b53e1ddd42e43c9fe94": {
			"balance": "4000000000000000000000"
		},
		"6e3a51db743d334d2fe88224b5fe7c008e80e624": {
			"balance": "106000000000000000000"
		},
		"3e94df5313fa520570ef232bc3311d5f622ff183": {
			"balance": "2000000000000000000000"
		},
		"8957727e72cf629020f4e05edf799aa7458062d0": {
			"balance": "2200000000000000000000"
		},
		"cf5e0eacd1b39d0655f2f77535ef6608eb950ba0": {
			"balance": "2000000000000000000000"
		},
		"f4aaa3a6163e3706577b49c0767e948a681e16ee": {
			"balance": "2000000000000000000000"
		},
		"97f1fe4c8083e596212a187728dd5cf80a31bec5": {
			"balance": "20000000000000000000"
		},
		"57d5fd0e3d3049330ffcdcd020456917657ba2da": {
			"balance": "1991240000000000000000"
		},
		"49bdbc7ba5abebb6389e91a3285220d3451bd253": {
			"balance": "1000000000000000000000"
		},
		"ae126b382cf257fad7f0bc7d16297e54cc7267da": {
			"balance": "300000000000000000000"
		},
		"bbf8616d97724af3def165d0e28cda89b800009a": {
			"balance": "114063000000000000000"
		},
		"adb948b1b6fefe207de65e9bbc2de98e605d0b57": {
			"balance": "2000000000000000000000"
		},
		"8a217db38bc35f215fd92906be42436fe7e6ed19": {
			"balance": "6000000000000000000000"
		},
		"e28b062259e96eeb3c8d4104943f9eb325893cf5": {
			"balance": "1337000000000000000000"
		},
		"6a6b18a45a76467e2e5d5a2ef911c3e12929857b": {
			"balance": "82000000000000000000000"
		},
		"cb68ae5abe02dcf8cbc5aa719c25814651af8b85": {
			"balance": "500000000000000000000"
		},
		"4c7e2e2b77ad0cd6f44acb2861f0fb8b28750ef9": {
			"balance": "20000000000000000000"
		},
		"58ba1569650e5bbbb21d35d3e175c0d6b0c651a9": {
			"balance": "500000000000000000000"
		},
		"1eb4bf73156a82a0a6822080c6edf49c469af8b9": {
			"balance": "1910000000000000000000"
		},
		"4103299671d46763978fa4aa19ee34b1fc952784": {
			"balance": "200000000000000000000"
		},
		"e321bb4a946adafdade4571fb15c0043d39ee35f": {
			"balance": "1575212000000000000000"
		},
		"893608751d68d046e85802926673cdf2f57f7cb8": {
			"balance": "19700000000000000000"
		},
		"70fee08b00c6c2c04a3c625c1ff77caf1c32df01": {
			"balance": "200000000000000000000"
		},
		"7b0fea1176d52159333a143c294943da36bbddb4": {
			"balance": "9380000000000000000000"
		},
		"d331c823825a9e5263d052d8915d4dcde07a5c37": {
			"balance": "564000000000000000000"
		},
		"a45432a6f2ac9d56577b938a37fabac8cc7c461c": {
			"balance": "1000000000000000000000"
		},
		"764fc46d428b6dbc228a0f5f55c9508c772eab9f": {
)E" + R"E(
			"balance": "26000000000000000000000"
		},
		"1a95a8a8082e4652e4170df9271cb4bb4305f0b2": {
			"balance": "50000000000000000000"
		},
		"08c9f1bfb689fdf804d769f82123360215aff93b": {
			"balance": "1970000000000000000000"
		},
		"1572cdfab72a01ce968e78f5b5448da29853fbdd": {
			"balance": "5061500000000000000000"
		},
		"379c7166849bc24a02d6535e2def13daeef8aa8d": {
			"balance": "100000000000000000000"
		},
		"e0a254ac09b9725bebc8e460431dd0732ebcabbf": {
			"balance": "6000000000000000000000"
		},
		"3225c1ca5f2a9c88156bb7d9cdc44a326653c214": {
			"balance": "400000000000000000000"
		},
		"84686c7bad762c54b667d59f90943cd14d117a26": {
			"balance": "20000000000000000000"
		},
		"3d5a8b2b80be8b35d8ecf789b5ed7a0775c5076c": {
			"balance": "20000000000000000000"
		},
		"2ccf80e21898125eb4e807cd82e09b9d28592f6e": {
			"balance": "2000000000000000000000"
		},
		"dde969aef34ea87ac299b7597e292b4a0155cc8a": {
			"balance": "298819000000000000000"
		},
		"19e94e620050aad766b9e1bad931238312d4bf49": {
			"balance": "2396000000000000000000"
		},
		"959f57fded6ae37913d900b81e5f48a79322c627": {
			"balance": "255599000000000000000"
		},
		"b9b0a3219a3288d9b35b091b14650b8fe23dce2b": {
			"balance": "14000000000000000000000"
		},
		"3575c770668a9d179f1ef768c293f80166e2aa3d": {
			"balance": "474000000000000000000"
		},
		"58f05b262560503ca761c61890a4035f4c737280": {
			"balance": "8000000000000000000000"
		},
		"3286d1bc657a312c8847d93cb3cb7950f2b0c6e3": {
			"balance": "20000000000000000000000"
		},
		"1d9e6aaf8019a05f230e5def05af5d889bd4d0f2": {
			"balance": "133700000000000000000"
		},
		"a375b4bc24a24e1f797593cc302b2f331063fa5c": {
			"balance": "200000000000000000000"
		},
		"108ba7c2895c50e072dc6f964932d50c282d3034": {
			"balance": "500000000000000000000"
		},
		"b6b34a263f10c3d2eceb0acc559a7b2ab85ce565": {
			"balance": "4000000000000000000000"
		},
		"a4d2b429f1ad5349e31704969edc5f25ee8aca10": {
			"balance": "10000000000000000000000"
		},
		"674adb21df4c98c7a347ac4c3c24266757dd7039": {
			"balance": "2000000000000000000000"
		},
		"33565ba9da2c03e778ce12294f081dfe81064d24": {
			"balance": "16000000000000000000000"
		},
		"4ddda7586b2237b053a7f3289cf460dc57d37a09": {
			"balance": "10000000000000000000000"
		},
		"cc4faac00be6628f92ef6b8cb1b1e76aac81fa18": {
			"balance": "205410000000000000000"
		},
		"5f99dc8e49e61d57daef606acdd91b4d7007326a": {
			"balance": "3000000000000000000000"
		},
		"b8a979352759ba09e35aa5935df175bff678a108": {
			"balance": "20000000000000000000"
		},
		"86fff220e59305c09f483860d6f94e96fbe32f57": {
			"balance": "42900000000000000000"
		},
		"03e8b084537557e709eae2e1e1a5a6bce1ef8314": {
			"balance": "20000000000000000000"
		},
		"dda4ff7de491c687df4574dd1b17ff8f246ba3d1": {
			"balance": "19600000000000000000000"
		},
		"2538532936813c91e653284f017c80c3b8f8a36f": {
			"balance": "2002000000000000000000"
		},
		"5a82f96cd4b7e2d93d10f3185dc8f43d4b75aa69": {
			"balance": "1999400000000000000000"
		},
		"86740a46648e845a5d96461b18091ff57be8a16f": {
			"balance": "98000000000000000000000"
)E" + R"E(
		},
		"7e3f63e13129a221ba1ab06326342cd98b5126ae": {
			"balance": "1597960000000000000000"
		},
		"1f5f3b34bd134b2781afe5a0424ac5846cdefd11": {
			"balance": "99000000000000000000"
		},
		"39936c2719450b9420cc2522cf91db01f227c1c1": {
			"balance": "500000000000000000000"
		},
		"967076a877b18ec15a415bb116f06ef32645dba3": {
			"balance": "2000000000000000000000"
		},
		"a42908e7fe53980a9abf4044e957a54b70e99cbe": {
			"balance": "2000000000000000000000"
		},
		"5eb371c407406c427b3b7de271ad3c1e04269579": {
			"balance": "3000000000000000000000"
		},
		"a570223ae3caa851418a9843a1ac55db4824f4fd": {
			"balance": "200000000000000000000"
		},
		"764692cccb33405dd0ab0c3379b49caf8e6221ba": {
			"balance": "20000000000000000000"
		},
		"a365918bfe3f2627b9f3a86775d8756e0fd8a94b": {
			"balance": "400000000000000000000"
		},
		"069ed0ab7aa77de571f16106051d92afe195f2d0": {
			"balance": "200000000000000000000"
		},
		"bd432a3916249b4724293af9146e49b8280a7f2a": {
			"balance": "4000000000000000000000"
		},
		"61c9dce8b2981cb40e98b0402bc3eb28348f03ac": {
			"balance": "196910000000000000000"
		},
		"8f1fcc3c51e252b693bc5b0ec3f63529fe69281e": {
			"balance": "6000000000000000000000"
		},
		"55fd08d18064bd202c0ec3d2cce0ce0b9d169c4d": {
			"balance": "1970000000000000000000"
		},
		"383a7c899ee18bc214969870bc7482f6d8f3570e": {
			"balance": "10000000000000000000000"
		},
		"b14cc8de33d6338236539a489020ce4655a32bc6": {
			"balance": "8000000000000000000000"
		},
		"448bf410ad9bbc2fecc4508d87a7fc2e4b8561ad": {
			"balance": "199955000000000000000"
		},
		"06f7dc8d1b9462cef6feb13368a7e3974b097f9f": {
			"balance": "2000000000000000000000"
		},
		"9c9f89a3910f6a2ae8a91047a17ab788bddec170": {
			"balance": "10000000000000000000000"
		},
		"5de598aba344378cab4431555b4f79992dc290c6": {
			"balance": "1337000000000000000000"
		},
		"87e6034ecf23f8b5639d5f0ea70a22538a920423": {
			"balance": "328000000000000000000"
		},
		"8b27392206b958cd375d7ef8af2cf8ef0598c0bc": {
			"balance": "1000000000000000000000"
		},
		"49136fe6e28b7453fcb16b6bbbe9aaacba8337fd": {
			"balance": "2000000000000000000000"
		},
		"6982fe8a867e93eb4a0bd051589399f2ec9a5292": {
			"balance": "2000000000000000000000"
		},
		"9fd1052a60506bd1a9ef003afd9d033c267d8e99": {
			"balance": "1000000000000000000000"
		},
		"d38fa2c4cc147ad06ad5a2f75579281f22a7cc1f": {
			"balance": "20000000000000000000000"
		},
		"6f794dbdf623daa6e0d00774ad6962737c921ea4": {
			"balance": "2000000000000000000000"
		},
		"e96b184e1f0f54924ac874f60bbf44707446b72b": {
			"balance": "2910840000000000000000"
		},
		"b5ba29917c78a1d9e5c5c713666c1e411d7f693a": {
			"balance": "3100000000000000000000"
		},
		"81d619ff5726f2405f12904c72eb1e24a0aaee4f": {
			"balance": "20000000000000000000000"
		},
		"b02fa29387ec12e37f6922ac4ce98c5b09e0b00f": {
			"balance": "2000000000000000000000"
		},
		"b7230d1d1ff2aca366963914a79df9f7c5ea2c98": {
			"balance": "8000000000000000000000"
		},
		"7b4007c45e5a573fdbb6f8bd746bf94ad04a3c26": {
			"balance": "15202564000000000000000"
		},
)E" + R"E(
		"8d9a0c70d2262042df1017d6c303132024772712": {
			"balance": "2000000000000000000000"
		},
		"323aad41df4b6fc8fece8c93958aa901fa680843": {
			"balance": "970000000000000000000"
		},
		"db04fad9c49f9e880beb8fcf1d3a3890e4b3846f": {
			"balance": "1242482000000000000000"
		},
		"27824666d278d70423f03dfe1dc7a3f02f43e2b5": {
			"balance": "1000070000000000000000"
		},
		"e04920dc6ecc1d6ecc084f88aa0af5db97bf893a": {
			"balance": "182000000000000000000"
		},
		"b0c1b177a220e41f7c74d07cde8569c21c75c2f9": {
			"balance": "5600000000000000000000"
		},
		"7864dc999fe4f8e003c0f43decc39aae1522dc0f": {
			"balance": "94400000000000000000"
		},
		"c75c37ce2da06bbc40081159c6ba0f976e3993b1": {
			"balance": "1078640000000000000000"
		},
		"179a825e0f1f6e985309668465cffed436f6aea9": {
			"balance": "20000000000000000000"
		},
		"2c6b699d9ead349f067f45711a074a641db6a897": {
			"balance": "20000000000000000000"
		},
		"068ce8bd6e902a45cb83b51541b40f39c4469712": {
			"balance": "5240000000000000000000"
		},
		"767ac690791c2e23451089fe6c7083fe55deb62b": {
			"balance": "820000000000000000000"
		},
		"b34f04b8db65bba9c26efc4ce6efc50481f3d65d": {
			"balance": "20000000000000000000000"
		},
		"29aef48de8c9fbad4b9e4ca970797a5533eb722d": {
			"balance": "10000000000000000000000"
		},
		"0a0ecda6636f7716ef1973614687fd89a820a706": {
			"balance": "394000000000000000000"
		},
		"b32825d5f3db249ef4e85cc4f33153958976e8bc": {
			"balance": "501375000000000000000"
		},
		"7ef16fd8d15b378a0fba306b8d03dd98fc92619f": {
			"balance": "700000000000000000000"
		},
		"b58b52865ea55d8036f2fab26098b352ca837e18": {
			"balance": "18200000000000000000"
		},
		"9b658fb361e046d4fcaa8aef6d02a99111223625": {
			"balance": "2000000000000000000000"
		},
		"b2a498f03bd7178bd8a789a00f5237af79a3e3f8": {
			"balance": "19400000000000000000000"
		},
		"cb48fe8265d9af55eb7006bc335645b0a3a183be": {
			"balance": "3000000000000000000000"
		},
		"3cf9a1d465e78b7039e3694478e2627b36fcd141": {
			"balance": "1372000000000000000000"
		},
		"5db84400570069a9573cab04b4e6b69535e202b8": {
			"balance": "9700000000000000000000"
		},
		"214c89c5bd8e7d22bc574bb35e48950211c6f776": {
			"balance": "18903000000000000000"
		},
		"53396f4a26c2b4604496306c5442e7fcba272e36": {
			"balance": "20055000000000000000000"
		},
		"720994dbe56a3a95929774e20e1fe525cf3704e4": {
			"balance": "8000000000000000000000"
		},
		"3571cf7ad304ecaee595792f4bbfa484418549d6": {
			"balance": "5825500000000000000000"
		},
		"6042c644bae2b96f25f94d31f678c90dc96690db": {
			"balance": "2000000000000000000000"
		},
		"2e24b597873bb141bdb237ea8a5ab747799af02d": {
			"balance": "20000000000000000000000"
		},
		"08c802f87758349fa03e6bc2e2fd0791197eea9a": {
			"balance": "2000000000000000000000"
		},
		"297a88921b5fca10e5bb9ded60025437ae221694": {
			"balance": "200000000000000000000"
		},
		"aee49d68adedb081fd43705a5f78c778fb90de48": {
			"balance": "20000000000000000000"
		},
		"4cee901b4ac8b156c5e2f8a6f1bef572a7dceb7e": {
			"balance": "1000000000000000000000"
		},
		"dfaf31e622c03d9e18a0ddb8be60fbe3e661be0a": {
)E" + R"E(
			"balance": "9999800000000000000000"
		},
		"00aa5381b2138ebeffc191d5d8c391753b7098d2": {
			"balance": "990049000000000000000"
		},
		"5b4c0c60f10ed2894bdb42d9dd1d210587810a0d": {
			"balance": "500000000000000000000"
		},
		"c44f4ab5bc60397c737eb0683391b633f83c48fa": {
			"balance": "1000000000000000000000"
		},
		"50bef2756248f9a7a380f91b051ba3be28a649ed": {
			"balance": "1999884000000000000000"
		},
		"1bd909ac0d4a1102ec98dcf2cca96a0adcd7a951": {
			"balance": "20055000000000000000"
		},
		"9ec03e02e587b7769def538413e97f7e55be71d8": {
			"balance": "19700000000000000000000"
		},
		"9874803fe1f3a0365e7922b14270eaeb032cc1b5": {
			"balance": "1124500000000000000000"
		},
		"4e2310191ead8d3bc6489873a5f0c2ec6b87e1be": {
			"balance": "1000000000000000000000"
		},
		"93678a3c57151aeb68efdc43ef4d36cb59a009f3": {
			"balance": "30060000000000000000"
		},
		"f483f607a21fcc28100a018c568ffbe140380410": {
			"balance": "1000000000000000000000"
		},
		"2a91a9fed41b7d0e5cd2d83158d3e8a41a9a2d71": {
			"balance": "1940000000000000000000"
		},
		"240e559e274aaef0c258998c979f671d1173b88b": {
			"balance": "4000000000000000000000"
		},
		"108a2b7c336f784779d8b54d02a8d31d9a139c0a": {
			"balance": "10000000000000000000000"
		},
		"9c98fdf1fdcd8ba8f4c5b04c3ae8587efdf0f6e6": {
			"balance": "6000000000000000000000"
		},
		"194ff44aefc17bd20efd7a204c47d1620c86db5d": {
			"balance": "2999400000000000000000"
		},
		"1f8116bd0af5570eaf0c56c49c7ab5e37a580458": {
			"balance": "2000000000000000000000"
		},
		"d79835e404fb86bf845fba090d6ba25e0c8866a6": {
			"balance": "2400000000000000000000"
		},
		"a8e7201ff619faffc332e6ad37ed41e301bf014a": {
			"balance": "600000000000000000000"
		},
		"286906b6bd4972e3c71655e04baf36260c7cb153": {
			"balance": "340000000000000000000"
		},
		"db4bc83b0e6baadb1156c5cf06e0f721808c52c7": {
			"balance": "880000000000000000000"
		},
		"a158148a2e0f3e92dc2ce38febc20107e3253c96": {
			"balance": "2000000000000000000000"
		},
		"9f6a322a6d469981426ae844865d7ee0bb15c7b3": {
			"balance": "50003000000000000000"
		},
		"32f29e8727a74c6b4301e3ffff0687c1b870dae9": {
			"balance": "1000000000000000000000"
		},
		"19918aa09e7d494e98ffa5db50350892f7156ac6": {
			"balance": "10000000000000000000000"
		},
		"5a5f8508da0ebebb90be9033bd4d9e274105ae00": {
			"balance": "6685000000000000000000"
		},
		"6fc25e7e00ca4f60a9fe6f28d1fde3542e2d1079": {
			"balance": "792000000000000000000"
		},
		"72094f3951ffc9771dced23ada080bcaf9c7cca7": {
			"balance": "6000000000000000000000"
		},
		"43f7e86e381ec51ec4906d1476cba97a3db584e4": {
			"balance": "1000000000000000000000"
		},
		"05696b73916bd3033e05521e3211dfec026e98e4": {
			"balance": "2000000000000000000000"
		},
		"5e7f70378775589fc66a81d3f653e954f55560eb": {
			"balance": "2434000000000000000000"
		},
		"895613236f3584216ad75c5d3e07e3fa6863a778": {
			"balance": "2000000000000000000000"
		},
		"4eb1454b573805c8aca37edec7149a41f61202f4": {
			"balance": "300000000000000000000"
		},
		"d99999a2490d9494a530cae4daf38554f4dd633e": {
			"balance": "120000000000000000000"
)E" + R"E(
		},
		"1704cefcfb1331ec7a78388b29393e85c1af7916": {
			"balance": "400000000000000000000"
		},
		"ac4acfc36ed6094a27e118ecc911cd473e8fb91f": {
			"balance": "1799800000000000000000"
		},
		"a975b077fcb4cc8efcbf838459b6fa243a4159d6": {
			"balance": "40000000000000000000"
		},
		"9c405cf697956138065e11c5f7559e67245bd1a5": {
			"balance": "200000000000000000000"
		},
		"cafde855864c2598da3cafc05ad98df2898e8048": {
			"balance": "14179272000000000000000"
		},
		"8ef711e43a13918f1303e81d0ea78c9eefd67eb2": {
			"balance": "4000000000000000000000"
		},
		"0b14891999a65c9ef73308efe3100ca1b20e8192": {
			"balance": "800000000000000000000"
		},
		"47cf9cdaf92fc999cc5efbb7203c61e4f1cdd4c3": {
			"balance": "131400000000000000000"
		},
		"04ba8a3f03f08b895095994dda619edaacee3e7a": {
			"balance": "2000000000000000000000"
		},
		"02b6d65cb00b7b36e1fb5ed3632c4cb20a894130": {
			"balance": "20000000000000000000000"
		},
		"f99aee444b5783c093cfffd1c4632cf93c6f050c": {
			"balance": "400000000000000000000"
		},
		"2541314a0b408e95a694444977712a50713591ab": {
			"balance": "1634706000000000000000"
		},
		"3096dca34108085bcf04ae72b94574a13e1a3e1d": {
			"balance": "200000000000000000000"
		},
		"56df05bad46c3f00ae476ecf017bb8c877383ff1": {
			"balance": "197248000000000000000"
		},
		"6d59b21cd0e2748804d9abe064eac2bef0c95f27": {
			"balance": "2000000000000000000000"
		},
		"b29f5b7c1930d9f97a115e067066f0b54db44b3b": {
			"balance": "1000000000000000000000"
		},
		"888c16144933197cac26504dd76e06fd6600c789": {
			"balance": "100000000000000000000"
		},
		"dfe3c52a92c30396a4e33a50170dc900fcf8c9cf": {
			"balance": "50000000000000000000"
		},
		"f76f69cee4faa0a63b30ae1e7881f4f715657010": {
			"balance": "200000000000000000000"
		},
		"ee0007b0960d00908a94432a737557876aac7c31": {
			"balance": "53053000000000000000"
		},
		"effc15e487b1beda0a8d1325bdb4172240dc540a": {
			"balance": "64940000000000000000"
		},
		"40ab0a3e83d0c8ac9366910520eab1772bac3b1a": {
			"balance": "976600000000000000000"
		},
		"1895a0eb4a4372722fcbc5afe6936f289c88a419": {
			"balance": "910000000000000000000"
		},
		"81efe296ae76c860d1c5fbd33d47e8ce9996d157": {
			"balance": "1000000000000000000000"
		},
		"9ddd355e634ee9927e4b7f6c97e7bf3a2f1e687a": {
			"balance": "50000000000000000000"
		},
		"f2b4ab2c9427a9015ef6eefff5edb60139b719d1": {
			"balance": "716800000000000000000"
		},
		"765be2e12f629e6349b97d21b62a17b7c830edab": {
			"balance": "6000000000000000000000"
		},
		"ff61c9c1b7a3d8b53bba20b34466544b7b216644": {
			"balance": "2000000000000000000000"
		},
		"36a08fd6fd1ac17ce15ed57eefb12a2be28188bf": {
			"balance": "1337000000000000000000"
		},
		"17049311101d817efb1d65910f663662a699c98c": {
			"balance": "1999800000000000000000"
		},
		"30511832918d8034a7bee72ef2bfee440ecbbcf6": {
			"balance": "16100000000000000000000"
		},
		"d27c234ff7accace3d996708f8f9b04970f97d36": {
			"balance": "1337000000000000000000"
		},
		"a961171f5342b173dd70e7bfe5b5ca238b13bcdd": {
			"balance": "3397053000000000000000"
		},
)E" + R"E(
		"30bf61b2d877fe10635126326fa189e4b0b1c3b0": {
			"balance": "1027580000000000000000"
		},
		"4bb6d86b8314c22d8d37ea516d0019f156aae12d": {
			"balance": "1000000000000000000000"
		},
		"5f363e0ab747e02d1b3b66abb69ea53c7baf523a": {
			"balance": "11640000000000000000000"
		},
		"283e11203749b1fa4f32febb71e49d135919382a": {
			"balance": "1000000000000000000000"
		},
		"ac5999a89d2dd286d5a80c6dee7e86aad40f9e12": {
			"balance": "3880000000000000000000"
		},
		"3f6dd3650ee428dcb7759553b017a96a94286ac9": {
			"balance": "1337000000000000000000"
		},
		"b3fc1d6881abfcb8becc0bb021b8b73b7233dd91": {
			"balance": "50000000000000000000"
		},
		"f0832a6bb25503eeca435be31b0bf905ca1fcf57": {
			"balance": "6685000000000000000000"
		},
		"9d7fda7070bf3ee9bbd9a41f55cad4854ae6c22c": {
			"balance": "11027380000000000000000"
		},
		"4b0bd8acfcbc53a6010b40d4d08ddd2d9d69622d": {
			"balance": "668500000000000000000"
		},
		"f3b668b3f14d920ebc379092db98031b67b219b3": {
			"balance": "199955000000000000000"
		},
		"d91d889164479ce436ece51763e22cda19b22d6b": {
			"balance": "3365200000000000000000"
		},
		"ffe28db53c9044b4ecd4053fd1b4b10d7056c688": {
			"balance": "100000000000000000000"
		},
		"c77b01a6e911fa988d01a3ab33646beef9c138f3": {
			"balance": "721400000000000000000"
		},
		"c0064f1d9474ab915d56906c9fb320a2c7098c9b": {
			"balance": "358000000000000000000"
		},
		"4e3edad4864dab64cae4c5417a76774053dc6432": {
			"balance": "590943000000000000000"
		},
		"71d2cc6d02578c65f73c575e76ce8fbcfadcf356": {
			"balance": "72400000000000000000"
		},
		"9971df60f0ae66dce9e8c84e17149f09f9c52f64": {
			"balance": "200000000000000000000"
		},
		"58e661d0ba73d6cf24099a5562b808f7b3673b68": {
			"balance": "2000000000000000000000"
		},
		"84b0ee6bb837d3a4c4c5011c3a228c0edab4634a": {
			"balance": "20000000000000000000"
		},
		"84375afbf59b3a1d61a1be32d075e0e15a4fbca5": {
			"balance": "200000000000000000000"
		},
		"9ae9476bfecd3591964dd325cf8c2a24faed82c1": {
			"balance": "4000000000000000000000"
		},
		"6a4c8907b600248057b1e46354b19bdc859c991a": {
			"balance": "20000000000000000000"
		},
		"1c045649cd53dc23541f8ed4d341812808d5dd9c": {
			"balance": "7000000000000000000000"
		},
		"c5e488cf2b5677933971f64cb8202dd05752a2c0": {
			"balance": "1000000000000000000000"
		},
		"eb25481fcd9c221f1ac7e5fd1ecd9307a16215b8": {
			"balance": "197000000000000000000"
		},
		"a61887818f914a20e31077290b83715a6b2d6ef9": {
			"balance": "1880000000000000000000"
		},
		"679437eacf437878dc293d48a39c87b7421a216c": {
			"balance": "64528000000000000000"
		},
		"331a1c26cc6994cdd3c14bece276ffff4b9df77c": {
			"balance": "18049000000000000000"
		},
		"75b95696e8ec4510d56868a7c1a735c68b244890": {
			"balance": "6400000000000000000000"
		},
		"a77f3ee19e9388bbbb2215c62397b96560132360": {
			"balance": "200000000000000000000"
		},
		"bc7afc8477412274fc265df13c054473427d43c6": {
			"balance": "130034000000000000000"
		},
		"91050a5cffadedb4bb6eaafbc9e5013428e96c80": {
			"balance": "1700000000000000000000"
		},
		"24586ec5451735eeaaeb470dc8736aae752f82e5": {
)E" + R"E(
			"balance": "17600000000000000000"
		},
		"51039377eed0c573f986c5e8a95fb99a59e9330f": {
			"balance": "1970000000000000000000"
		},
		"fbb161fe875f09290a4b262bc60110848f0d2226": {
			"balance": "2000000000000000000000"
		},
		"ed52a2cc0869dc9e9f842bd0957c47a8e9b0c9ff": {
			"balance": "9550000000000000000000"
		},
		"bad235d5085dc7b068a67c412677b03e1836884c": {
			"balance": "2000000000000000000000"
		},
		"055eac4f1ad3f58f0bd024d68ea60dbe01c6afb3": {
			"balance": "100000000000000000000"
		},
		"4058808816fdaa3a5fc98ed47cfae6c18315422e": {
			"balance": "199800000000000000000"
		},
		"3540c7bd7a8442d5bee21a2180a1c4edff1649e0": {
			"balance": "1239295000000000000000"
		},
		"c5edbbd2ca0357654ad0ea4793f8c5cecd30e254": {
			"balance": "6000000000000000000000"
		},
		"b5906b0ae9a28158e8ac550e39da086ee3157623": {
			"balance": "200000000000000000000"
		},
		"4d801093c19ca9b8f342e33cc9c77bbd4c8312cf": {
			"balance": "345005000000000000000"
		},
		"206482ee6f138a778fe1ad62b180ce856fbb23e6": {
			"balance": "2000000000000000000000"
		},
		"c0ed0d4ad10de03435b153a0fc25de3b93f45204": {
			"balance": "3160000000000000000000"
		},
		"29e67990e1b6d52e1055ffe049c53195a81542cf": {
			"balance": "20000000000000000000000"
		},
		"e6d22209ffd0b87509ade3a8e2ef429879cb89b5": {
			"balance": "17260000000000000000000"
		},
		"d6644d40e90bc97fe7dfe7cabd3269fd579ba4b3": {
			"balance": "159000000000000000000"
		},
		"ece1290877b583e361a2d41b009346e6274e2538": {
			"balance": "300000000000000000000"
		},
		"ab3861226ffec1289187fb84a08ec3ed043264e8": {
			"balance": "1000000000000000000000"
		},
		"60e0bdd0a259bb9cb09d3f37e5cd8b9daceabf8a": {
			"balance": "1370000000000000000000"
		},
		"28b77585cb3d55a199ab291d3a18c68fe89a848a": {
			"balance": "1960000000000000000000"
		},
		"73128173489528012e76b41a5e28c68ba4e3a9d4": {
			"balance": "1000000000000000000000"
		},
		"018492488ba1a292342247b31855a55905fef269": {
			"balance": "140000000000000000000"
		},
		"0bb54c72fd6610bfa4363397e020384b022b0c49": {
			"balance": "1337000000000000000000"
		},
		"520f66a0e2657ff0ac4195f2f064cf2fa4b24250": {
			"balance": "40000000000000000000"
		},
		"a1432ed2c6b7777a88e8d46d388e70477f208ca5": {
			"balance": "7999538000000000000000"
		},
		"149ba10f0da2725dc704733e87f5a524ca88515e": {
			"balance": "7880000000000000000000"
		},
		"b287f7f8d8c3872c1b586bcd7d0aedbf7e732732": {
			"balance": "20000000000000000000"
		},
		"c46bbdef76d4ca60d316c07f5d1a780e3b165f7e": {
			"balance": "2000000000000000000000"
		},
		"b5a589dd9f4071dbb6fba89b3f5d5dae7d96c163": {
			"balance": "2000000000000000000000"
		},
		"d218efb4db981cdd6a797f4bd48c7c26293ceb40": {
			"balance": "2975000000000000000000"
		},
		"af87d2371ef378957fbd05ba2f1d66931b01e2b8": {
			"balance": "700000000000000000000"
		},
		"86ef6426211949cc37f4c75e7850369d0cf5f479": {
			"balance": "13399196000000000000000"
		},
		"fb3a0b0d6b6a718f6fc0292a825dc9247a90a5d0": {
			"balance": "199950000000000000000"
		},
		"da16dd5c3d1a2714358fe3752cae53dbab2be98c": {
			"balance": "19400000000000000000000"
)E" + R"E(
		},
		"9eb7834e171d41e069a77947fca87622f0ba4e48": {
			"balance": "100000000000000000000"
		},
		"e1d91b0954cede221d6f24c7985fc59965fb98b8": {
			"balance": "2000000000000000000000"
		},
		"85d0d88754ac84b8b21ba93dd2bfec72626faba8": {
			"balance": "1000000000000000000000"
		},
		"695b4cce085856d9e1f9ff3e79942023359e5fbc": {
			"balance": "5000000000000000000000"
		},
		"9156d18029350e470408f15f1aa3be9f040a67c6": {
			"balance": "1000000000000000000000"
		},
		"a9d64b4f3bb7850722b58b478ba691375e224e42": {
			"balance": "6000000000000000000000"
		},
		"17e4a0e52bac3ee44efe0954e753d4b85d644e05": {
			"balance": "2000000000000000000000"
		},
		"b8a79c84945e47a9c3438683d6b5842cff7684b1": {
			"balance": "2000000000000000000000"
		},
		"cfac2e1bf33205b05533691a02267ee19cd81836": {
			"balance": "1000000000000000000000"
		},
		"6b992521ec852370848ad697cc2df64e63cc06ff": {
			"balance": "1000000000000000000000"
		},
		"60af0ee118443c9b37d2fead77f5e521debe1573": {
			"balance": "1910000000000000000000"
		},
		"c6dbdb9efd5ec1b3786e0671eb2279b253f215ed": {
			"balance": "1000000000000000000000"
		},
		"659c0a72c767a3a65ced0e1ca885a4c51fd9b779": {
			"balance": "2000000000000000000000"
		},
		"ed1276513b6fc68628a74185c2e20cbbca7817bf": {
			"balance": "191000000000000000000"
		},
		"5ad12c5ed4fa827e2150cfa0d68c0aa37b1769b8": {
			"balance": "800000000000000000000"
		},
		"17c0fef6986cfb2e4041f9979d9940b69dff3de2": {
			"balance": "4000000000000000000000"
		},
		"ca98c7988efa08e925ef9c9945520326e9f43b99": {
			"balance": "4000000000000000000000"
		},
		"fe8f1fdcab7fbec9a6a3fcc507619600505c36a3": {
			"balance": "19700000000000000000"
		},
		"4420aa35465be617ad2498f370de0a3cc4d230af": {
			"balance": "2000000000000000000000"
		},
		"8232d1f9742edf8dd927da353b2ae7b4cbce7592": {
			"balance": "668500000000000000000"
		},
		"eca5f58792b8c62d2af556717ee3ee3028be4dce": {
			"balance": "2000000000000000000000"
		},
		"6bf86f1e2f2b8032a95c4d7738a109d3d0ed8104": {
			"balance": "1820000000000000000000"
		},
		"3ac2f0ff1612e4a1c346d53382abf6d8a25baa53": {
			"balance": "2000000000000000000000"
		},
		"daa1bd7a9148fb865cd612dd35f162861d0f3bdc": {
			"balance": "3066243000000000000000"
		},
		"5169c60aee4ceed1849ab36d664cff97061e8ea8": {
			"balance": "3000000000000000000000"
		},
		"2a5e3a40d2cd0325766de73a3d671896b362c73b": {
			"balance": "100000000000000000000000"
		},
		"a83382b6e15267974a8550b98f7176c1a353f9be": {
			"balance": "3541608000000000000000"
		},
		"b50c149a1906fad2786ffb135aab501737e9e56f": {
			"balance": "388000000000000000000"
		},
		"d9775965b716476675a8d513eb14bbf7b07cd14a": {
			"balance": "5076200000000000000000"
		},
		"66662006015c1f8e3ccfcaebc8ee6807ee196303": {
			"balance": "500024000000000000000"
		},
		"78746a958dced4c764f876508c414a68342cecb9": {
			"balance": "50600000000000000000"
		},
		"e982e6f28c548f5f96f45e63f7ab708724f53fa1": {
			"balance": "396238000000000000000"
		},
		"740bfd52e01667a3419b029a1b8e45576a86a2db": {
			"balance": "16800000000000000000000"
		},
)E" + R"E(
		"2bd252e0d732ff1d7c78f0a02e6cb25423cf1b1a": {
			"balance": "2674000000000000000000"
		},
		"2e2d7ea66b9f47d8cc52c01c52b6e191bc7d4786": {
			"balance": "3999800000000000000000"
		},
		"3e3161f1ea2fbf126e79da1801da9512b37988c9": {
			"balance": "49250000000000000000000"
		},
		"7e2ba86da52e785d8625334f3397ba1c4bf2e8d1": {
			"balance": "197000000000000000000"
		},
		"7608f437b31f18bc0b64d381ae86fd978ed7b31f": {
			"balance": "50000000000000000000"
		},
		"25a5a44d38a2f44c6a9db9cdbc6b1e2e97abb509": {
			"balance": "17000000000000000000000"
		},
		"745ad3abc6eeeb2471689b539e789ce2b8268306": {
			"balance": "1129977000000000000000"
		},
		"09e437d448861228a232b62ee8d37965a904ed9c": {
			"balance": "21708305000000000000000"
		},
		"be53322f43fbb58494d7cce19dda272b2450e827": {
			"balance": "200018000000000000000"
		},
		"4166fc08ca85f766fde831460e9dc93c0e21aa6c": {
			"balance": "1000000000000000000000"
		},
		"99c0174cf84e0783c220b4eb6ae18fe703854ad3": {
			"balance": "2074800000000000000000"
		},
		"3cf484524fbdfadae26dc185e32b2b630fd2e726": {
			"balance": "448798000000000000000"
		},
		"fdcd5d80b105897a57abc47865768b2900524295": {
			"balance": "6400000000000000000000"
		},
		"f22f4078febbbaa8b0e78e642c8a42f35d433905": {
			"balance": "1999944000000000000000"
		},
		"eac768bf14b8f9432e69eaa82a99fbeb94cd0c9c": {
			"balance": "98500000000000000000000"
		},
		"2639eee9873ceec26fcc9454b548b9e7c54aa65c": {
			"balance": "1000000000000000000000"
		},
		"c3c3c2510d678020485a63735d1307ec4ca6302b": {
			"balance": "1000000000000000000000"
		},
		"b73d6a77559c86cf6574242903394bacf96e3570": {
			"balance": "91200000000000000000"
		},
		"5ce2e7ceaaa18af0f8aafa7fbad74cc89e3cd436": {
			"balance": "20000000000000000000000"
		},
		"03377c0e556b640103289a6189e1aeae63493467": {
			"balance": "20000000000000000000000"
		},
		"6eb0a5a9ae96d22cf01d8fd6483b9f38f08c2c8b": {
			"balance": "4000000000000000000000"
		},
		"fc8215a0a69913f62a43bf1c8590b9ddcd0d8ddb": {
			"balance": "2000000000000000000000"
		},
		"4a835c25824c47ecbfc79439bf3f5c3481aa75cd": {
			"balance": "1400000000000000000000"
		},
		"b5493ef173724445cf345c035d279ba759f28d51": {
			"balance": "20000000000000000000"
		},
		"b9e90c1192b3d5d3e3ab0700f1bf655f5dd4347a": {
			"balance": "499928000000000000000"
		},
		"419bde7316cc1ed295c885ace342c79bf7ee33ea": {
			"balance": "6000000000000000000000"
		},
		"e4625501f52b7af52b19ed612e9d54fdd006b492": {
			"balance": "209440000000000000000"
		},
		"e9d599456b2543e6db80ea9b210e908026e2146e": {
			"balance": "200000000000000000000"
		},
		"2c06dd922b61514aafedd84488c0c28e6dcf0e99": {
			"balance": "100000000000000000000000"
		},
		"06b5ede6fdf1d6e9a34721379aeaa17c713dd82a": {
			"balance": "2000000000000000000000"
		},
		"d8930a39c77357c30ad3a060f00b06046331fd62": {
			"balance": "820000000000000000000"
		},
		"b2a2c2111612fb8bbb8e7dd9378d67f1a384f050": {
			"balance": "20000000000000000000"
		},
		"1f174f40a0447234e66653914d75bc003e5690dc": {
			"balance": "160000000000000000000"
		},
		"e06cb6294704eea7437c2fc3d30773b7bf38889a": {
)E" + R"E(
			"balance": "20094000000000000000"
		},
		"cd06f8c1b5cdbd28e2d96b6346c3e85a0483ba24": {
			"balance": "1000000000000000000000"
		},
		"f316ef1df2ff4d6c1808dba663ec8093697968e0": {
			"balance": "1794400000000000000000"
		},
		"1e6915ebd9a19c81b692ad99b1218a592c1ac7b1": {
			"balance": "4000000000000000000000"
		},
		"885493bda36a0432976546c1ddce71c3f4570021": {
			"balance": "216700000000000000000"
		},
		"18b0407cdad4ce52600623bd5e1f6a81ab61f026": {
			"balance": "319489000000000000000"
		},
		"187d9f0c07f8eb74faaad15ebc7b80447417f782": {
			"balance": "20000000000000000000"
		},
		"5d6ccf806738091042ad97a6e095fe8c36aa79c5": {
			"balance": "188000000000000000000"
		},
		"53437fecf34ab9d435f4deb8ca181519e2592035": {
			"balance": "188000000000000000000"
		},
		"fd1faa347b0fcc804c2da86c36d5f1d18b7087bb": {
			"balance": "52380000000000000000"
		},
		"650cf67db060cce17568d5f2a423687c49647609": {
			"balance": "100000000000000000000"
		},
		"bcd95ef962462b6edfa10fda87d72242fe3edb5c": {
			"balance": "334133000000000000000"
		},
		"3b5e8b3c77f792decb7a8985df916efb490aac23": {
			"balance": "2000000000000000000000"
		},
		"f13b083093ba564e2dc631568cf7540d9a0ec719": {
			"balance": "1999944000000000000000"
		},
		"373c547e0cb5ce632e1c5ad66155720c01c40995": {
			"balance": "4691588000000000000000"
		},
		"7313461208455455465445a459b06c3773b0eb30": {
			"balance": "2000000000000000000000"
		},
		"441f37e8a029fd02482f289c49b5d06d00e408a4": {
			"balance": "333333000000000000000"
		},
		"d30d4c43adcf55b2cb53d68323264134498d89ce": {
			"balance": "1000000000000000000000"
		},
		"f648ea89c27525710172944e79edff847803b775": {
			"balance": "100000000000000000000000"
		},
		"0c7f869f8e90d53fdc03e8b2819b016b9d18eb26": {
			"balance": "20000000000000000000000"
		},
		"c71f92a3a54a7b8c2f5ea44305fccb84eee23148": {
			"balance": "49980000000000000000"
		},
		"7988901331e387f713faceb9005cb9b65136eb14": {
			"balance": "1970000000000000000000"
		},
		"e9a39a8bac0f01c349c64cedb69897f633234ed2": {
			"balance": "3980000000000000000000"
		},
		"ad2a5c00f923aaf21ab9f3fb066efa0a03de2fb2": {
			"balance": "999996000000000000000"
		},
		"f25259a5c939cd25966c9b6303d3731c53ddbc4c": {
			"balance": "200000000000000000000"
		},
		"d1682c2159018dc3d07f08240a8c606daf65f8e1": {
			"balance": "200000000000000000000000"
		},
		"a99991cebd98d9c838c25f7a7416d9e244ca250d": {
			"balance": "1000000000000000000000"
		},
		"5a285755391e914e58025faa48cc685f4fd4f5b8": {
			"balance": "26000000000000000000000"
		},
		"4d24b7ac47d2f27de90974ba3de5ead203544bcd": {
			"balance": "100000000000000000000"
		},
		"21b182f2da2b384493cf5f35f83d9d1ee14f2a21": {
			"balance": "2000000000000000000000"
		},
		"31ab088966ecc7229258f6098fce68cf39b38485": {
			"balance": "1000000000000000000000"
		},
		"4977a7939d0939689455ce2639d0ee5a4cd910ed": {
			"balance": "1820000000000000000000"
		},
		"07af938c1237a27c9030094dcf240750246e3d2c": {
			"balance": "500000000000000000000"
		},
		"4e2bfa4a466f82671b800eee426ad00c071ba170": {
			"balance": "4000000000000000000000"
)E" + R"E(
		},
		"107379d4c467464f235bc18e55938aad3e688ad7": {
			"balance": "50000000000000000000"
		},
		"f7b29b82195c882dab7897c2ae95e77710f57875": {
			"balance": "2199000000000000000000"
		},
		"56586391040c57eec6f5affd8cd4abde10b50acc": {
			"balance": "4000000000000000000000"
		},
		"ac608e2bac9dd20728d2947effbbbf900a9ce94b": {
			"balance": "6000600000000000000000"
		},
		"48548b4ba62bcb2f0d34a88dc69a680e539cf046": {
			"balance": "100084000000000000000"
		},
		"1665ab1739d71119ee6132abbd926a279fe67948": {
			"balance": "100000000000000000000"
		},
		"af4493e8521ca89d95f5267c1ab63f9f45411e1b": {
			"balance": "200000000000000000000"
		},
		"bf6925c00751008440a6739a02bf2b6cdaab5e3a": {
			"balance": "1000000000000000000000"
		},
		"3fe40fbd919aad2818df01ee4df46c46842ac539": {
			"balance": "6000000000000000000000"
		},
		"455b9296921a74d1fc41617f43b8303e6f3ed76c": {
			"balance": "4200000000000000000000"
		},
		"7086b4bde3e35d4aeb24b825f1a215f99d85f745": {
			"balance": "1999800000000000000000"
		},
		"d4ee4919fb37f2bb970c3fff54aaf1f3dda6c03f": {
			"balance": "40000000000000000000000"
		},
		"a4489a50ead5d5445a7bee4d2d5536c2a76c41f8": {
			"balance": "200000000000000000000"
		},
		"505e4f7c275588c533a20ebd2ac13b409bbdea3c": {
			"balance": "17600000000000000000"
		},
		"3bb53598cc20e2055dc553b049404ac9b7dd1e83": {
			"balance": "615020000000000000000"
		},
		"52cd20403ba7eda6bc307a3d63b5911b817c1263": {
			"balance": "20000000000000000000"
		},
		"a211da03cc0e31ecce5309998718515528a090df": {
			"balance": "200000000000000000000"
		},
		"bcb422dc4dd2aae94abae95ea45dd1731bb6b0ba": {
			"balance": "447500000000000000000"
		},
		"cbde9734b8e6aa538c291d6d7facedb0f338f857": {
			"balance": "2000000000000000000000"
		},
		"171ca02a8b6d62bf4ca47e906914079861972cb2": {
			"balance": "200000000000000000000"
		},
		"d40d0055fd9a38488aff923fd03d35ec46d711b3": {
			"balance": "4999711000000000000000"
		},
		"3887192c7f705006b630091276b39ac680448d6b": {
			"balance": "60000000000000000000"
		},
		"3f3c8e61e5604cef0605d436dd22accd862217fc": {
			"balance": "1337000000000000000000"
		},
		"4258fd662fc4ce3295f0d4ed8f7bb1449600a0a9": {
			"balance": "6719600000000000000000"
		},
		"4571de672b9904bad8743692c21c4fdcea4c2e01": {
			"balance": "4000000000000000000000"
		},
		"5be045512a026e3f1cebfd5a7ec0cfc36f2dc16b": {
			"balance": "120000000000000000000"
		},
		"d6300b3215b11de762ecde4b70b7927d01291582": {
			"balance": "2000000000000000000000"
		},
		"f9e37447406c412197b2e2aebc001d6e30c98c60": {
			"balance": "8346700000000000000000"
		},
		"bd047ff1e69cc6b29ad26497a9a6f27a903fc4dd": {
			"balance": "865000000000000000000"
		},
		"23fa7eb51a48229598f97e762be0869652dffc66": {
			"balance": "1000000000000000000000"
		},
		"6679aeecd87a57a73f3356811d2cf49d0c4d96dc": {
			"balance": "600000000000000000000"
		},
		"23c55aeb5739876f0ac8d7ebea13be729685f000": {
			"balance": "1337000000000000000000"
		},
		"757b65876dbf29bf911d4f0692a2c9beb1139808": {
			"balance": "4124263000000000000000"
		},
)E" + R"E(
		"e8fc36b0131ec120ac9e85afc10ce70b56d8b6ba": {
			"balance": "200000000000000000000"
		},
		"1a89899cbebdbb64bb26a195a63c08491fcd9eee": {
			"balance": "2000000000000000000000"
		},
		"6edf7f5283725c953ee64317f66188af1184b033": {
			"balance": "8050000000000000000000"
		},
		"297385e88634465685c231a314a0d5dcd146af01": {
			"balance": "1550000000000000000000"
		},
		"018f20a27b27ec441af723fd9099f2cbb79d6263": {
			"balance": "2167000000000000000000"
		},
		"a5a4227f6cf98825c0d5baff5315752ccc1a1391": {
			"balance": "10000000000000000000000"
		},
		"69517083e303d4fbb6c2114514215d69bc46a299": {
			"balance": "100000000000000000000"
		},
		"1dab172effa6fbee534c94b17e794edac54f55f8": {
			"balance": "1970000000000000000000"
		},
		"c6ee35934229693529dc41d9bb71a2496658b88e": {
			"balance": "19700000000000000000000"
		},
		"a8ee1df5d44b128469e913569ef6ac81eeda4fc8": {
			"balance": "500000000000000000000"
		},
		"35bd246865fab490ac087ac1f1d4f2c10d0cda03": {
			"balance": "400000000000000000000"
		},
		"4bf8bf1d35a231315764fc8001809a949294fc49": {
			"balance": "66850000000000000000"
		},
		"c70fa45576bf9c865f983893002c414926f61029": {
			"balance": "400400000000000000000"
		},
		"fdeaac2acf1d138e19f2fc3f9fb74592e3ed818a": {
			"balance": "668500000000000000000"
		},
		"bfbfbcb656c2992be8fcde8219fbc54aadd59f29": {
			"balance": "9999924000000000000000"
		},
		"1722c4cbe70a94b6559d425084caeed4d6e66e21": {
			"balance": "4000000000000000000000"
		},
		"00e681bc2d10db62de85848324492250348e90bf": {
			"balance": "20000000000000000000000"
		},
		"5c308bac4857d33baea074f3956d3621d9fa28e1": {
			"balance": "4999711000000000000000"
		},
		"68c08490c89bf0d6b6f320b1aca95c8312c00608": {
			"balance": "4000000000000000000000"
		},
		"ce1884ddbbb8e10e4dba6e44feeec2a7e5f92f05": {
			"balance": "4000000000000000000000"
		},
		"427417bd16b1b3d22dbb902d8f9657016f24a61c": {
			"balance": "2000000000000000000000"
		},
		"5ff93de6ee054cad459b2d5eb0f6870389dfcb74": {
			"balance": "220000000000000000000"
		},
		"71946b7117fc915ed107385f42d99ddac63249c2": {
			"balance": "2000000000000000000000"
		},
		"11ec00f849b6319cf51aa8dd8f66b35529c0be77": {
			"balance": "2000000000000000000000"
		},
		"610fd6ee4eebab10a8c55d0b4bd2e7d6ef817156": {
			"balance": "20002000000000000000"
		},
		"a422e4bf0bf74147cc895bed8f16d3cef3426154": {
			"balance": "349281000000000000000"
		},
		"745aecbaf9bb39b74a67ea1ce623de368481baa6": {
			"balance": "10000000000000000000000"
		},
		"9f496cb2069563144d0811677ba0e4713a0a4143": {
			"balance": "1122000000000000000000"
		},
		"c500b720734ed22938d78c5e48b2ba9367a575ba": {
			"balance": "33400000000000000000000"
		},
		"cd072e6e1833137995196d7bb1725fef8761f655": {
			"balance": "6000000000000000000000"
		},
		"94644ad116a41ce2ca7fbec609bdef738a2ac7c7": {
			"balance": "5000000000000000000000"
		},
		"e8d942d82f175ecb1c16a405b10143b3f46b963a": {
			"balance": "568600000000000000000"
		},
		"f73dd9c142b71bce11d06e30e7e7d032f2ec9c9e": {
			"balance": "1970000000000000000000"
		},
		"1327d759d56e0ab87af37ecf63fe01f310be100a": {
)E" + R"E(
			"balance": "659200000000000000000"
		},
		"28fa2580f9ebe420f3e5eefdd371638e3b7af499": {
			"balance": "6000000000000000000000"
		},
		"024bdd2c7bfd500ee7404f7fb3e9fb31dd20fbd1": {
			"balance": "180000000000000000000"
		},
		"b4b14bf45455d0ab0803358b7524a72be1a2045b": {
			"balance": "500000000000000000000"
		},
		"b1e2dd95e39ae9775c55aeb13f12c2fa233053ba": {
			"balance": "2000000000000000000000"
		},
		"35b03ea4245736f57b85d2eb79628f036ddcd705": {
			"balance": "4000000000000000000000"
		},
		"eb2ef3d38fe652403cd4c9d85ed7f0682cd7c2de": {
			"balance": "42784000000000000000000"
		},
		"690594d306613cd3e2fd24bca9994ad98a3d73f8": {
			"balance": "2000000000000000000000"
		},
		"8397a1bc47acd647418159b99cea57e1e6532d6e": {
			"balance": "9169160000000000000000"
		},
		"b44815a0f28e569d0e921a4ade8fb2642526497a": {
			"balance": "55500000000000000000"
		},
		"e24109be2f513d87498e926a286499754f9ed49e": {
			"balance": "886500000000000000000"
		},
		"37ac29bda93f497bc4aeaab935452c431510341e": {
			"balance": "985000000000000000000"
		},
		"4a81abe4984c7c6bef63d69820e55743c61f201c": {
			"balance": "16011846000000000000000"
		},
		"66dcc5fb4ee7fee046e141819aa968799d644491": {
			"balance": "1337000000000000000000"
		},
		"43ff38743ed0cd43308c066509cc8e7e72c862aa": {
			"balance": "1940000000000000000000"
		},
		"b8f20005b61352ffa7699a1b52f01f5ab39167f1": {
			"balance": "10000000000000000000000"
		},
		"1cda411bd5163baeca1e558563601ce720e24ee1": {
			"balance": "18200000000000000000"
		},
		"86245f596691093ece3f3d3ca2263eace81941d9": {
			"balance": "188000000000000000000"
		},
		"f52a5882e8927d944b359b26366ba2b9cacfbae8": {
			"balance": "25000080000000000000000"
		},
		"118c18b2dce170e8f445753ba5d7513cb7636d2d": {
			"balance": "8800000000000000000000"
		},
		"7168b3bb8c167321d9bdb023a6e9fd11afc9afd9": {
			"balance": "1790000000000000000000"
		},
		"d9103bb6b67a55a7fece2d1af62d457c2178946d": {
			"balance": "1000000000000000000000"
		},
		"8b9fda7d981fe9d64287f85c94d83f9074849fcc": {
			"balance": "14000000000000000000000"
		},
		"91211712719f2b084d3b3875a85069f466363141": {
			"balance": "1000000000000000000000"
		},
		"4863849739265a63b0a2bf236a5913e6f959ce15": {
			"balance": "1520000000000000000000"
		},
		"c2d1778ef6ee5fe488c145f3586b6ebbe3fbb445": {
			"balance": "1146000000000000000000"
		},
		"2b77a4d88c0d56a3dbe3bae04a05f4fcd1b757e1": {
			"balance": "300000000000000000000"
		},
		"fe9c0fffefb803081256c0cf4d6659e6d33eb4fb": {
			"balance": "1528000000000000000000"
		},
		"893017ff1adad499aa065401b4236ce6e92b625a": {
			"balance": "1999944000000000000000"
		},
		"073c67e09b5c713c5221c8a0c7f3f74466c347b0": {
			"balance": "19400000000000000000000"
		},
		"93e303411afaf6c107a44101c9ac5b36e9d6538b": {
			"balance": "66000000000000000000000"
		},
		"0ec50aa823f465b9464b0bc0c4a57724a555f5d6": {
			"balance": "59100000000000000000000"
		},
		"a3e3a6ea509573e21bd0239ece0523a7b7d89b2f": {
			"balance": "1970000000000000000000"
		},
		"c069ef0eb34299abd2e32dabc47944b272334824": {
			"balance": "120000000000000000000"
)E" + R"E(
		},
		"28a3da09a8194819ae199f2e6d9d1304817e28a5": {
			"balance": "2000000000000000000000"
		},
		"e9495ba5842728c0ed97be37d0e422b98d69202c": {
			"balance": "2000000000000000000000"
		},
		"bba976f1a1215f7512871892d45f7048acd356c8": {
			"balance": "2000000000000000000000"
		},
		"887cac41cd706f3345f2d34ac34e01752a6e5909": {
			"balance": "595366000000000000000"
		},
		"e0e0b2e29dde73af75987ee4446c829a189c95bc": {
			"balance": "149000000000000000000"
		},
		"4a5fae3b0372c230c125d6d470140337ab915656": {
			"balance": "1600000000000000000000"
		},
		"425177eb74ad0a9d9a5752228147ee6d6356a6e6": {
			"balance": "13370000000000000000"
		},
		"5db7bba1f9573f24115d8c8c62e9ce8895068e9f": {
			"balance": "49984000000000000000"
		},
		"fa6a37f018e97967937fc5e8617ba1d786dd5f77": {
			"balance": "19999800000000000000000"
		},
		"45e3a93e72144ada860cbc56ff85145ada38c6da": {
			"balance": "1610000000000000000000"
		},
		"67da922effa472a6b124e84ea8f86b24e0f515aa": {
			"balance": "20000000000000000000"
		},
		"aa9bd4589535db27fa2bc903ca17d679dd654806": {
			"balance": "2000000000000000000000"
		},
		"16a9e9b73ae98b864d1728798b8766dbc6ea8d12": {
			"balance": "957480000000000000000"
		},
		"d6580ab5ed4c7dfa506fa6fe64ad5ce129707732": {
			"balance": "4000000000000000000000"
		},
		"984a7985e3cc7eb5c93691f6f8cc7b8f245d01b2": {
			"balance": "6000000000000000000000"
		},
		"7746b6c6699c8f34ca2768a820f1ffa4c207fe05": {
			"balance": "4000086000000000000000"
		},
		"2fa491fb5920a6574ebd289f39c1b2430d2d9a6a": {
			"balance": "2000000000000000000000"
		},
		"fae76719d97eac41870428e940279d97dd57b2f6": {
			"balance": "98500000000000000000000"
		},
		"41b2dbd79dda9b864f6a7030275419c39d3efd3b": {
			"balance": "3200000000000000000000"
		},
		"dd8254121a6e942fc90828f2431f511dad7f32e6": {
			"balance": "3018000000000000000000"
		},
		"37fac1e6bc122e936dfb84de0c4bef6e0d60c2d7": {
			"balance": "2000000000000000000000"
		},
		"3a10888b7e149cae272c01302c327d0af01a0b24": {
			"balance": "17000000000000000000"
		},
		"401354a297952fa972ad383ca07a0a2811d74a71": {
			"balance": "14000000000000000000"
		},
		"51865db148881951f51251710e82b9be0d7eadb2": {
			"balance": "2000000000000000000000"
		},
		"bbbd6ecbb5752891b4ceb3cce73a8f477059376f": {
			"balance": "36000000000000000000"
		},
		"3f236108eec72289bac3a65cd283f95e041d144c": {
			"balance": "999925000000000000000"
		},
		"dc83b6fd0d512131204707eaf72ea0c8c9bef976": {
			"balance": "2000000000000000000000"
		},
		"036eeff5ba90a6879a14dff4c5043b18ca0460c9": {
			"balance": "100000000000000000000"
		},
		"fac5ca94758078fbfccd19db3558da7ee8a0a768": {
			"balance": "1017500000000000000000"
		},
		"d0d62c47ea60fb90a3639209bbfdd4d933991cc6": {
			"balance": "194000000000000000000"
		},
		"891cb8238c88e93a1bcf61db49bd82b47a7f4f84": {
			"balance": "2680000000000000000000"
		},
		"df53003346d65c5e7a646bc034f2b7d32fcbe56a": {
			"balance": "2000000000000000000000"
		},
		"6e89c51ea6de13e06cdc748b67c4410fe9bcab03": {
			"balance": "4000000000000000000000"
		},
)E" + R"E(
		"a61cdbadf04b1e54c883de6005fcdf16beb8eb2f": {
			"balance": "2000000000000000000000"
		},
		"e3951de5aefaf0458768d774c254f7157735e505": {
			"balance": "1600930000000000000000"
		},
		"f2732cf2c13b8bb8e7492a988f5f89e38273ddc8": {
			"balance": "600000000000000000000"
		},
		"4752218e54de423f86c0501933917aea08c8fed5": {
			"balance": "20000000000000000000000"
		},
		"152f4e860ef3ee806a502777a1b8dbc91a907668": {
			"balance": "600000000000000000000"
		},
		"15b96f30c23b8664e7490651066b00c4391fbf84": {
			"balance": "410650000000000000000"
		},
		"8693e9b8be94425eef7969bc69f9d42f7cad671e": {
			"balance": "1000090000000000000000"
		},
		"f41557dfdfb1a1bdcefefe2eba1e21fe0a4a9942": {
			"balance": "1970000000000000000000"
		},
		"38458e0685573cb4d28f53098829904570179266": {
			"balance": "40000000000000000000"
		},
		"53e4d9696dcb3f4d7b3f70dcaa4eecb71782ff5c": {
			"balance": "200000000000000000000"
		},
		"2dca0e449ab646dbdfd393a96662960bcab5ae1e": {
			"balance": "40000000000000000000000"
		},
		"87d7ac0653ccc67aa9c3469eef4352193f7dbb86": {
			"balance": "200000000000000000000000"
		},
		"ae9f5c3fbbe0c9bcbf1af8ff74ea280b3a5d8b08": {
			"balance": "1730000000000000000000"
		},
		"7751f363a0a7fd0533190809ddaf9340d8d11291": {
			"balance": "20000000000000000000"
		},
		"708a2af425ceb01e87ffc1be54c0f532b20eacd6": {
			"balance": "134159000000000000000"
		},
		"ac122a03cd058c122e5fe17b872f4877f9df9572": {
			"balance": "1969606000000000000000"
		},
		"5da4ca88935c27f55c311048840e589e04a8a049": {
			"balance": "80000000000000000000"
		},
		"e67c2c1665c88338688187629f49e99b60b2d3ba": {
			"balance": "200000000000000000000"
		},
		"dec82373ade8ebcf2acb6f8bc2414dd7abb70d77": {
			"balance": "200000000000000000000"
		},
		"47c247f53b9fbeb17bba0703a00c009fdb0f6eae": {
			"balance": "20000000000000000000000"
		},
		"9a522e52c195bfb7cf5ffaaedb91a3ba7468161d": {
			"balance": "1000000000000000000000"
		},
		"3159e90c48a915904adfe292b22fa5fd5e72796b": {
			"balance": "1008800000000000000000"
		},
		"defddfd59b8d2c154eecf5c7c167bf0ba2905d3e": {
			"balance": "93588000000000000000"
		},
		"ad1d68a038fd2586067ef6d135d9628e79c2c924": {
			"balance": "4686168000000000000000"
		},
		"038e45eadd3d88b87fe4dab066680522f0dfc8f9": {
			"balance": "10000000000000000000000"
		},
		"2561ec0f379218fe5ed4e028a3f744aa41754c72": {
			"balance": "13370000000000000000"
		},
		"b95396daaa490df2569324fcc6623be052f132ca": {
			"balance": "2000000000000000000000"
		},
		"2376ada90333b1d181084c97e645e810aa5b76f1": {
			"balance": "750000000000000000000"
		},
		"07800d2f8068e448c79a4f69b1f15ef682aae5f6": {
			"balance": "19400000000000000000000"
		},
		"adeb204aa0c38e179e81a94ed8b3e7d53047c26b": {
			"balance": "608000000000000000000"
		},
		"0dc100b107011c7fc0a1339612a16ccec3285208": {
			"balance": "2000000000000000000000"
		},
		"f0b1340b996f6f0bf0d9561c849caf7f4430befa": {
			"balance": "100000000000000000000"
		},
		"e1443dbd95cc41237f613a48456988a04f683282": {
			"balance": "4000086000000000000000"
		},
		"d3c6f1e0f50ec3d2a67e6bcd193ec7ae38f1657f": {
)E" + R"E(
			"balance": "6618150000000000000000"
		},
		"b68899e7610d4c93a23535bcc448945ba1666f1c": {
			"balance": "200000000000000000000"
		},
		"a7253763cf4a75df92ca1e766dc4ee8a2745147b": {
			"balance": "10740000000000000000000"
		},
		"75d67ce14e8d29e8c2ffe381917b930b1aff1a87": {
			"balance": "3000000000000000000000"
		},
		"493d48bda015a9bfcf1603936eab68024ce551e0": {
			"balance": "22528000000000000000"
		},
		"7ddd57165c87a2707f025dcfc2508c09834759bc": {
			"balance": "1400000000000000000000"
		},
		"cff7f89a4d4219a38295251331568210ffc1c134": {
			"balance": "1760000000000000000000"
		},
		"168d30e53fa681092b52e9bae15a0dcb41a8c9bb": {
			"balance": "100000000000000000000"
		},
		"99b743d1d9eff90d9a1934b4db21d519d89b4a38": {
			"balance": "100000000000000000000"
		},
		"a3d0b03cffbb269f796ac29d80bfb07dc7c6ad06": {
			"balance": "2000000000000000000000"
		},
		"816d9772cf11399116cc1e72c26c6774c9edd739": {
			"balance": "200000000000000000000"
		},
		"a880e2a8bf88a1a82648b4013c49c4594c433cc8": {
			"balance": "4728000000000000000000"
		},
		"2a44a7218fe44d65a1b4b7a7d9b1c2c52c8c3e34": {
			"balance": "62221355000000000000000"
		},
		"cb86edbc8bbb1f9131022be649565ebdb09e32a1": {
			"balance": "2000000000000000000000"
		},
		"3915eab5ab2e5977d075dec47d96b68b4b5cf515": {
			"balance": "61520000000000000000000"
		},
		"8165cab0eafb5a328fc41ac64dae715b2eef2c65": {
			"balance": "1000000000000000000000"
		},
		"416c86b72083d1f8907d84efd2d2d783dffa3efb": {
			"balance": "1999944000000000000000"
		},
		"c524086d46c8112b128b2faf6f7c7d8160a8386c": {
			"balance": "400000000000000000000"
		},
		"902d74a157f7d2b9a3378b1f56703730e03a1719": {
			"balance": "4000000000000000000000"
		},
		"74ef2869cbe608856045d8c2041118579f2236ea": {
			"balance": "59724000000000000000"
		},
		"af992dd669c0883e5515d3f3112a13f617a4c367": {
			"balance": "2000000000000000000000"
		},
		"4c6a248fc97d705def495ca20759169ef0d36471": {
			"balance": "760000000000000000000"
		},
		"974d2f17895f2902049deaaecf09c3046507402d": {
			"balance": "14707000000000000000"
		},
		"0239b4f21f8e05cd01512b2be7a0e18a6d974607": {
			"balance": "1000000000000000000000"
		},
		"b97a6733cd5fe99864b3b33460d1672434d5cafd": {
			"balance": "1999579000000000000000"
		},
		"f558a2b2dd26dd9593aae04531fd3c3cc3854b67": {
			"balance": "198000000000000000000"
		},
		"b577b6befa054e9c040461855094b002d7f57bd7": {
			"balance": "114000000000000000000000"
		},
		"73bfe7710f31cab949b7a2604fbf5239cee79015": {
			"balance": "2000000000000000000000"
		},
		"5717f2d8f18ffcc0e5fe247d3a4219037c3a649c": {
			"balance": "3998000000000000000000"
		},
		"20707e425d2a11d2c89f391b2b809f556c592421": {
			"balance": "2000000000000000000000"
		},
		"9a6708ddb8903c289f83fe889c1edcd61f854423": {
			"balance": "1000000000000000000000"
		},
		"fa27cc49d00b6c987336a875ae39da58fb041b2e": {
			"balance": "10000000000000000000000"
		},
		"d688e785c98f00f84b3aa1533355c7a258e87948": {
			"balance": "500000000000000000000"
		},
		"927cb7dc187036b5427bc7e200c5ec450c1d27d4": {
			"balance": "216000000000000000000"
)E" + R"E(
		},
		"b2bfaa58b5196c5cb7f89de15f479d1838de713d": {
			"balance": "21000000000000000000"
		},
		"e180de9e86f57bafacd7904f9826b6b4b26337a3": {
			"balance": "830400000000000000000"
		},
		"a1204dad5f560728a35c0d8fc79481057bf77386": {
			"balance": "1000000000000000000000"
		},
		"6b0da25af267d7836c226bcae8d872d2ce52c941": {
			"balance": "6000000000000000000000"
		},
		"0517448dada761cc5ba4033ee881c83037036400": {
			"balance": "1998000000000000000000"
		},
		"7ed0a5a847bef9a9da7cba1d6411f5c316312619": {
			"balance": "39842000000000000000"
		},
		"5b5d517029321562111b43086d0b043591109a70": {
			"balance": "2600000000000000000000"
		},
		"56fc1a7bad4047237ce116146296238e078f93ad": {
			"balance": "178000000000000000000"
		},
		"6c5422fb4b14e6d98b6091fdec71f1f08640419d": {
			"balance": "400000000000000000000"
		},
		"108fe8ee2a13da487b22c6ab6d582ea71064d98c": {
			"balance": "399800000000000000000"
		},
		"0ad3e44d3c001fa290b393617030544108ac6eb9": {
			"balance": "1969019000000000000000"
		},
		"25aee68d09afb71d8817f3f184ec562f7897b734": {
			"balance": "2000000000000000000000"
		},
		"c2340a4ca94c9678b7494c3c852528ede5ee529f": {
			"balance": "48669000000000000000"
		},
		"44901e0d0e08ac3d5e95b8ec9d5e0ff5f12e0393": {
			"balance": "417500000000000000000"
		},
		"8775a610c502b9f1e6ad4cdadb8ce29bff75f6e4": {
			"balance": "600000000000000000000"
		},
		"682897bc4f8e89029120fcffb787c01a93e64184": {
			"balance": "10000000000000000000000"
		},
		"f7acff934b84da0969dc37a8fcf643b7d7fbed41": {
			"balance": "1999944000000000000000"
		},
		"f05fcd4c0d73aa167e5553c8c0d6d4f2faa39757": {
			"balance": "13334000000000000000000"
		},
		"c981d312d287d558871edd973abb76b979e5c35e": {
			"balance": "1970000000000000000000"
		},
		"9da61ccd62bf860656e0325d7157e2f160d93bb5": {
			"balance": "4999980000000000000000"
		},
		"d284a50382f83a616d39b8a9c0f396e0ebbfa95d": {
			"balance": "1000070000000000000000"
		},
		"d6cf5c1bcf9da662bcea2255905099f9d6e84dcc": {
			"balance": "8349332000000000000000"
		},
		"c71b2a3d7135d2a85fb5a571dcbe695e13fc43cd": {
			"balance": "1000000000000000000000"
		},
		"b22dadd7e1e05232a93237baed98e0df92b1869e": {
			"balance": "2000000000000000000000"
		},
		"b09fe6d4349b99bc37938054022d54fca366f7af": {
			"balance": "200000000000000000000000"
		},
		"427e4751c3babe78cff8830886febc10f9908d74": {
			"balance": "1970000000000000000000"
		},
		"60b358cb3dbefa37f47df2d7365840da8e3bc98c": {
			"balance": "20000000000000000000"
		},
		"dcd5bca2005395b675fde5035659b26bfefc49ee": {
			"balance": "197000000000000000000"
		},
		"81186931184137d1192ac88cd3e1e5d0fdb86a74": {
			"balance": "2900000000000000000000"
		},
		"de212293f8f1d231fa10e609470d512cb8ffc512": {
			"balance": "2000000000000000000000"
		},
		"1937c5c515057553ccbd46d5866455ce66290284": {
			"balance": "1000000000000000000000000"
		},
		"592777261e3bd852c48eca95b3a44c5b7f2d422c": {
			"balance": "20000000000000000000000"
		},
		"bbf84292d954acd9e4072fb860b1504106e077ae": {
			"balance": "1500000000000000000000"
		},
)E" + R"E(
		"3b4100e30a73b0c734b18ffa8426d19b19312f1a": {
			"balance": "55300000000000000000000"
		},
		"a03a3dc7c533d1744295be955d61af3f52b51af5": {
			"balance": "40000000000000000000"
		},
		"4aa148c2c33401e66a2b586e6577c4b292d3f240": {
			"balance": "216200000000000000000"
		},
		"ff850e3be1eb6a4d726c08fa73aad358f39706da": {
			"balance": "1940000000000000000000"
		},
		"743651b55ef8429df50cf81938c2508de5c8870f": {
			"balance": "2000000000000000000000"
		},
		"3700e3027424d939dbde5d42fb78f6c4dbec1a8f": {
			"balance": "40000000000000000000"
		},
		"c1cbd2e2332a524cf219b10d871ccc20af1fb0fa": {
			"balance": "1000000000000000000000"
		},
		"e25b9f76b8ad023f057eb11ad94257a0862e4e8c": {
			"balance": "2000000000000000000000"
		},
		"719e891fbcc0a33e19c12dc0f02039ca05b801df": {
			"balance": "6185800000000000000000"
		},
		"39636b25811b176abfcfeeca64bc87452f1fdff4": {
			"balance": "400000000000000000000"
		},
		"631030a5b27b07288a45696f189e1114f12a81c0": {
			"balance": "499970000000000000000"
		},
		"bcc84597b91e73d5c5b4d69c80ecf146860f779a": {
			"balance": "4380000000000000000000"
		},
		"095e0174829f34c3781be1a5e38d1541ea439b7f": {
			"balance": "6000000000000000000000"
		},
		"2e7e05e29edda7e4ae25c5173543efd71f6d3d80": {
			"balance": "6000000000000000000000"
		},
		"dbb6ac484027041642bbfd8d80f9d0c1cf33c1eb": {
			"balance": "2000000000000000000000"
		},
		"153c08aa8b96a611ef63c0253e2a4334829e579d": {
			"balance": "394000000000000000000"
		},
		"10f4bff0caa5027c0a6a2dcfc952824de2940909": {
			"balance": "2000000000000000000000"
		},
		"2ef869f0350b57d53478d701e3fee529bc911c75": {
			"balance": "50000000000000000000"
		},
		"70ab34bc17b66f9c3b63f151274f2a727c539263": {
			"balance": "2000000000000000000000"
		},
		"3201259caf734ad7581c561051ba0bca7fd6946b": {
			"balance": "180000000000000000000000"
		},
		"84e9cf8166c36abfa49053b7a1ad4036202681ef": {
			"balance": "2000000000000000000000"
		},
		"4ebc5629f9a6a66b2cf3363ac4895c0348e8bf87": {
			"balance": "1000090000000000000000"
		},
		"e50b464ac9de35a5618b7cbf254674182b81b97e": {
			"balance": "4100000000000000000000"
		},
		"2abdf1a637ef6c42a7e2fe217773d677e804ebdd": {
			"balance": "5000000000000000000000"
		},
		"7a0a78a9cc393f91c3d9e39a6b8c069f075e6bf5": {
			"balance": "1337000000000000000000"
		},
		"2d9c5fecd2b44fbb6a1ec732ea059f4f1f9d2b5c": {
			"balance": "1010694000000000000000"
		},
		"7b712c7af11676006a66d2fc5c1ab4c479ce6037": {
			"balance": "8000000000000000000000"
		},
		"3466f67e39636c01f43b3a21a0e8529325c08624": {
			"balance": "842864000000000000000"
		},
		"fdd502a74e813bcfa355ceda3c176f6a6871af7f": {
			"balance": "400000000000000000000"
		},
		"26475419c06d5f147aa597248eb46cf7befa64a5": {
			"balance": "1640000000000000000000"
		},
		"9243d7762d77287b12638688b9854e88a769b271": {
			"balance": "1000000000000000000000"
		},
		"723d8baa2551d2addc43c21b45e8af4ca2bfb2c2": {
			"balance": "1760000000000000000000"
		},
		"f2fbb6d887f8b8cc3a869aba847f3d1f643c53d6": {
			"balance": "3999000000000000000000"
		},
		"2cdb3944650616e47cb182e060322fa1487978ce": {
)E" + R"E(
			"balance": "1820000000000000000000"
		},
		"f0d21663d8b0176e05fde1b90ef31f8530fda95f": {
			"balance": "1999944000000000000000"
		},
		"77cc02f623a9cf98530997ea67d95c3b491859ae": {
			"balance": "1354900000000000000000"
		},
		"d1b5a454ac3405bb4179208c6c84de006bcb9be9": {
			"balance": "500000000000000000000"
		},
		"b9920fd0e2c735c256463caa240fb7ac86a93dfa": {
			"balance": "1760000000000000000000"
		},
		"ed1f1e115a0d60ce02fb25df014d289e3a0cbe7d": {
			"balance": "500000000000000000000"
		},
		"23e2c6a8be8e0acfa5c4df5e36058bb7cbac5a81": {
			"balance": "2000000000000000000000"
		},
		"f0be0faf4d7923fc444622d1980cf2d990aab307": {
			"balance": "2000000000000000000000"
		},
		"0829d0f7bb7c446cfbb0deadb2394d9db7249a87": {
			"balance": "40110000000000000000"
		},
		"2ecac504b233866eb5a4a99e7bd2901359e43b3d": {
			"balance": "20000000000000000000000"
		},
		"06d6cb308481c336a6e1a225a912f6e6355940a1": {
			"balance": "1760000000000000000000"
		},
		"d4879fd12b1f3a27f7e109761b23ca343c48e3d8": {
			"balance": "666000000000000000000"
		},
		"857f100b1a5930225efc7e9020d78327b41c02cb": {
			"balance": "2000000000000000000000"
		},
		"3aa42c21b9b31c3e27ccd17e099af679cdf56907": {
			"balance": "8000000000000000000000"
		},
		"764d5212263aff4a2a14f031f04ec749dc883e45": {
			"balance": "1850000000000000000000"
		},
		"d03a2da41e868ed3fef5745b96f5eca462ff6fda": {
			"balance": "3000000000000000000000"
		},
		"4f26690c992b7a312ab12e1385d94acd58288e7b": {
			"balance": "14000000000000000000000"
		},
		"7b122162c913e7146cad0b7ed37affc92a0bf27f": {
			"balance": "1506799000000000000000"
		},
		"c87352dba582ee2066b9c002a962e003134f78b1": {
			"balance": "500000000000000000000"
		},
		"9f4ac9c9e7e24cb2444a0454fa5b9ad9d92d3853": {
			"balance": "835000000000000000000"
		},
		"ccf62a663f1353ba2ef8e6521dc1ecb673ec8ef7": {
			"balance": "152000000000000000000"
		},
		"557f5e65e0da33998219ad4e99570545b2a9d511": {
			"balance": "11024000000000000000000"
		},
		"a5f0077b351f6c505cd515dfa6d2fa7f5c4cd287": {
			"balance": "40000000000000000000000"
		},
		"79c6002f8452ca157f1317e80a2faf24475559b7": {
			"balance": "20000000000000000000"
		},
		"3aa07a34a1afc8967d3d1383b96b62cf96d5fa90": {
			"balance": "20000000000000000000000"
		},
		"7f389c12f3c6164f6446566c77669503c2792527": {
			"balance": "98500000000000000000"
		},
		"ac4cc256ae74d624ace80db078b2207f57198f6b": {
			"balance": "2001000000000000000000"
		},
		"823ba7647238d113bce9964a43d0a098118bfe4d": {
			"balance": "200000000000000000000"
		},
		"f5a7676ad148ae9c1ef8b6f5e5a0c2c473be850b": {
			"balance": "200000000000000000000"
		},
		"7d34803569e00bd6b59fff081dfa5c0ab4197a62": {
			"balance": "1712700000000000000000"
		},
		"061ea4877cd08944eb64c2966e9db8dedcfec06b": {
			"balance": "1000000000000000000000"
		},
		"df37c22e603aedb60a627253c47d8ba866f6d972": {
			"balance": "24000000000000000000000"
		},
		"529aa002c6962a3a8545027fd8b05f22b5bf9564": {
			"balance": "1670000000000000000000"
		},
		"eb89a882670909cf377e9e78286ee97ba78d46c2": {
			"balance": "802200000000000000000"
)E" + R"E(
		},
		"9ac85397792a69d78f286b86432a07aeceb60e64": {
			"balance": "14300000000000000000"
		},
		"9610592202c282ab9bd8a884518b3e0bd4758137": {
			"balance": "268000000000000000000"
		},
		"73932709a97f02c98e51b091312865122385ae8e": {
			"balance": "1430000000000000000000"
		},
		"5ef8c96186b37984cbfe04c598406e3b0ac3171f": {
			"balance": "9400000000000000000000"
		},
		"b6f78da4f4d041b3bc14bc5ba519a5ba0c32f128": {
			"balance": "172326253000000000000000"
		},
		"6f0edd23bcd85f6015f9289c28841fe04c83efeb": {
			"balance": "19100000000000000000"
		},
		"a8a43c009100616cb4ae4e033f1fc5d7e0b6f152": {
			"balance": "3939015000000000000000"
		},
		"7081fa6baad6cfb7f51b2cca16fb8970991a64ba": {
			"balance": "233953000000000000000"
		},
		"9de7386dde401ce4c67b71b6553f8aa34ea5a17d": {
			"balance": "60000000000000000000"
		},
		"54ec7300b81ac84333ed1b033cd5d7a33972e234": {
			"balance": "200000000000000000000"
		},
		"67a80e0190721f94390d6802729dd12c31a895ad": {
			"balance": "1999964000000000000000"
		},
		"3a4297da3c555e46c073669d0478fce75f2f790e": {
			"balance": "1969606000000000000000"
		},
		"c2e0584a71348cc314b73b2029b6230b92dbb116": {
			"balance": "2000000000000000000000"
		},
		"0a2ade95b2e8c66d8ae6f0ba64ca57d783be6d44": {
			"balance": "4000000000000000000000"
		},
		"544b5b351d1bc82e9297439948cf4861dac9ae11": {
			"balance": "22000000000000000000000"
		},
		"3ae62bd271a760637fad79c31c94ff62b4cd12f7": {
			"balance": "2000000000000000000000"
		},
		"0d8023929d917234ae40512b1aabb5e8a4512771": {
			"balance": "148000000000000000000"
		},
		"2858acacaf21ea81cab7598fdbd86b452e9e8e15": {
			"balance": "666000000000000000000"
		},
		"c033b1325a0af45472c25527853b1f1c21fa35de": {
			"balance": "2000000000000000000000"
		},
		"bbf85aaaa683738f073baef44ac9dc34c4c779ea": {
			"balance": "2000000000000000000000"
		},
		"6ae57f27917c562a132a4d1bf7ec0ac785832926": {
			"balance": "6000000000000000000000"
		},
		"88e6f9b247f988f6c0fc14c56f1de53ec69d43cc": {
			"balance": "100000000000000000000"
		},
		"b72c2a011c0df50fbb6e28b20ae1aad217886790": {
			"balance": "4000000000000000000000"
		},
		"161caf5a972ace8379a6d0a04ae6e163fe21df2b": {
			"balance": "100000000000000000000000"
		},
		"2a63590efe9986c3fee09b0a0a338b15bed91f21": {
			"balance": "6458400000000000000000"
		},
		"50e1c8ec98415bef442618708799437b86e6c205": {
			"balance": "6000000000000000000000"
		},
		"33f4a6471eb1bca6a9f85b3b4872e10755c82be1": {
			"balance": "2000000000000000000000"
		},
		"9c49deff47085fc09704caa2dca8c287a9a137da": {
			"balance": "8000000000000000000000"
		},
		"e1173a247d29d8238df0922f4df25a05f2af77c3": {
			"balance": "40007051000000000000000"
		},
		"51891b2ccdd2f5a44b2a8bc49a5d9bca6477251c": {
			"balance": "310000000000000000000"
		},
		"ecaf3350b7ce144d068b186010852c84dd0ce0f0": {
			"balance": "2000000000000000000000"
		},
		"72393d37b451effb9e1ff3b8552712e2a970d8c2": {
			"balance": "985000000000000000000"
		},
		"1bbc60bcc80e5cdc35c5416a1f0a40a83dae867b": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"b8ab39805bd821184f6cbd3d2473347b12bf175c": {
			"balance": "118200000000000000000"
		},
		"c55a6b4761fd11e8c85f15174d74767cd8bd9a68": {
			"balance": "133700000000000000000"
		},
		"99d1b585965f406a42a49a1ca70f769e765a3f98": {
			"balance": "16700000000000000000000"
		},
		"9ab988b505cfee1dbe9cd18e9b5473b9a2d4f536": {
			"balance": "320000000000000000000"
		},
		"7fef8c38779fb307ec6f044bebe47f3cfae796f1": {
			"balance": "168561000000000000000"
		},
		"322d6f9a140d213f4c80cd051afe25c620bf4c7d": {
			"balance": "20000000000000000000"
		},
		"3bd9a06d1bd36c4edd27fc0d1f5b088ddae3c72a": {
			"balance": "499970000000000000000"
		},
		"5dcdb6b87a503c6d8a3c65c2cf9a9aa883479a1e": {
			"balance": "9200000000000000000000"
		},
		"6e84c2fd18d8095714a96817189ca21cca62bab1": {
			"balance": "340935000000000000000"
		},
		"a5bad86509fbe0e0e3c0e93f6d381f1af6e9d481": {
			"balance": "6000000000000000000000"
		},
		"3954bdfe0bf587c695a305d9244c3d5bdddac9bb": {
			"balance": "19187461000000000000000"
		},
		"63f0e5a752f79f67124eed633ad3fd2705a397d4": {
			"balance": "3940000000000000000000"
		},
		"33fd718f0b91b5cec88a5dc15eecf0ecefa4ef3d": {
			"balance": "432500000000000000000"
		},
		"68027d19558ed7339a08aee8de3559be063ec2ea": {
			"balance": "2000000000000000000000"
		},
		"96f0462ae6f8b96088f7e9c68c74b9d8ad34b347": {
			"balance": "1790000000000000000000"
		},
		"f1f391ca92808817b755a8b8f4e2ca08d1fd1108": {
			"balance": "6000000000000000000000"
		},
		"7fcf5ba6666f966c5448c17bf1cb0bbcd8019b06": {
			"balance": "99999000000000000000"
		},
		"e9b9a2747510e310241d2ece98f56b3301d757e0": {
			"balance": "2000000000000000000000"
		},
		"2100381d60a5b54adc09d19683a8f6d5bb4bfbcb": {
			"balance": "10000000000000000000000"
		},
		"7495ae78c0d90261e2140ef2063104731a60d1ed": {
			"balance": "34250000000000000000"
		},
		"dc911cf7dc5dd0813656670528e9338e67034786": {
			"balance": "2000000000000000000000"
		},
		"262aed4bc0f4a4b2c6fb35793e835a49189cdfec": {
			"balance": "10000000000000000000000"
		},
		"9ee93f339e6726ec65eea44f8a4bfe10da3d3282": {
			"balance": "2000000000000000000000"
		},
		"a3a57b0716132804d60aac281197ff2b3d237b01": {
			"balance": "1400000000000000000000"
		},
		"c799e34e88ff88be7de28e15e4f2a63d0b33c4cb": {
			"balance": "200000000000000000000"
		},
		"c7506c1019121ff08a2c8c1591a65eb4bdfb4a3f": {
			"balance": "600000000000000000000"
		},
		"795ebc2626fc39b0c86294e0e837dcf523553090": {
			"balance": "1000000000000000000000"
		},
		"441aca82631324acbfa2468bda325bbd78477bbf": {
			"balance": "6000000000000000000000"
		},
		"9f271d285500d73846b18f733e25dd8b4f5d4a8b": {
			"balance": "722000000000000000000"
		},
		"d77892e2273b235d7689e430e7aeed9cbce8a1f3": {
			"balance": "2000000000000000000000"
		},
		"4f8972838f70c903c9b6c6c46162e99d6216d451": {
			"balance": "4610000000000000000000"
		},
		"4c85ed362f24f6b9f04cdfccd022ae535147cbb9": {
			"balance": "1500000000000000000000"
		},
		"3807eff43aa97c76910a19752dd715ee0182d94e": {
			"balance": "250190000000000000000"
		},
		"3a9e5441d44b243be55b75027a1ceb9eacf50df2": {
)E" + R"E(
			"balance": "1000000000000000000000"
		},
		"3deae43327913f62808faa1b6276a2bd6368ead9": {
			"balance": "2000000000000000000000"
		},
		"c270456885342b640b4cfc1b520e1a544ee0d571": {
			"balance": "1820000000000000000000"
		},
		"77798f201257b9c35204957057b54674aefa51df": {
			"balance": "149000000000000000000"
		},
		"225f9eb3fb6ff3e9e3c8447e14a66e8d4f3779f6": {
			"balance": "2000000000000000000000"
		},
		"78df2681d6d602e22142d54116dea15d454957aa": {
			"balance": "298000000000000000000"
		},
		"283396ce3cac398bcbe7227f323e78ff96d08767": {
			"balance": "400000000000000000000"
		},
		"747ff7943b71dc4dcdb1668078f83dd7cc4520c2": {
			"balance": "60000000000000000000"
		},
		"a4ed11b072d89fb136759fc69b428c48aa5d4ced": {
			"balance": "262800000000000000000"
		},
		"cc043c4388d345f884c6855e71142a9f41fd6935": {
			"balance": "20000000000000000000"
		},
		"ab14d221e33d544629198cd096ed63dfa28d9f47": {
			"balance": "6000000000000000000000"
		},
		"251e6838f7cec5b383c1d90146341274daf8e502": {
			"balance": "147510000000000000000"
		},
		"36a0e61e1be47fa87e30d32888ee0330901ca991": {
			"balance": "20000000000000000000"
		},
		"bcfc98e5c82b6adb180a3fcb120b9a7690c86a3f": {
			"balance": "1970000000000000000000"
		},
		"18a6d2fc52be73084023c91802f05bc24a4be09f": {
			"balance": "2000000000000000000000"
		},
		"80591a42179f34e64d9df75dcd463b28686f5574": {
			"balance": "20000000000000000000000"
		},
		"881230047c211d2d5b00d8de4c5139de5e3227c7": {
			"balance": "10000000000000000000000"
		},
		"9eb1ff71798f28d6e989fa1ea0588e27ba86cb7d": {
			"balance": "140800000000000000000"
		},
		"a01fd1906a908506dedae1e208128872b56ee792": {
			"balance": "3000000000000000000000"
		},
		"1b05ea6a6ac8af7cb6a8b911a8cce8fe1a2acfc8": {
			"balance": "2000000000000000000000"
		},
		"6add932193cd38494aa3f03aeccc4b7ab7fabca2": {
			"balance": "89600000000000000000"
		},
		"2aaa35274d742546670b7426264521032af4f4c3": {
			"balance": "10000000000000000000000"
		},
		"67b8a6e90fdf0a1cac441793301e8750a9fa7957": {
			"balance": "895000000000000000000"
		},
		"5b5be0d8c67276baabd8edb30d48ea75640b8b29": {
			"balance": "824480000000000000000"
		},
		"28d7e5866f1d85fd1ceb32bfbe1dfc36db434566": {
			"balance": "7199000000000000000000"
		},
		"98e3e90b28fccaee828779b8d40a5568c4116e21": {
			"balance": "40000000000000000000"
		},
		"2dd578f7407dfbd548d05e95ccc39c485429626a": {
			"balance": "4200000000000000000000"
		},
		"8ca6989746b06e32e2487461b1ce996a273acfd7": {
			"balance": "20000000000000000000"
		},
		"a6f93307f8bce03195fece872043e8a03f7bd11a": {
			"balance": "2886000000000000000000"
		},
		"efbd52f97da5fd3a673a46cbf330447b7e8aad5c": {
			"balance": "100033000000000000000"
		},
		"52bdd9af5978850bc24110718b3723759b437e59": {
			"balance": "1730000000000000000000"
		},
		"6e073b66d1b8c66744d88096a8dd99ec7e0228da": {
			"balance": "4000000000000000000000"
		},
		"a29d661a6376f66d0b74e2fe9d8f26c0247ec84c": {
			"balance": "4117300000000000000000"
		},
		"7d34ff59ae840a7413c6ba4c5bb2ba2c75eab018": {
			"balance": "3000000000000000000000"
)E" + R"E(
		},
		"2eca6a3c5d9f449d0956bd43fa7b4d7be8435958": {
			"balance": "2000020000000000000000"
		},
		"f59f9f02bbc98efe097eabb78210979021898bfd": {
			"balance": "9999800000000000000000"
		},
		"90e300ac71451e401f887f6e7728851647a80e07": {
			"balance": "400000000000000000000"
		},
		"05ae7fd4bbcc80ca11a90a1ec7a301f7cccc83db": {
			"balance": "910000000000000000000"
		},
		"e54102534de8f23effb093b31242ad3b233facfd": {
			"balance": "4000000000000000000000"
		},
		"c127aab59065a28644a56ba3f15e2eac13da2995": {
			"balance": "600000000000000000000"
		},
		"ed60c4ab6e540206317e35947a63a9ca6b03e2cb": {
			"balance": "57275000000000000000"
		},
		"d855b03ccb029a7747b1f07303e0a664793539c8": {
			"balance": "2000000000000000000000"
		},
		"1178501ff94add1c5881fe886136f6dfdbe61a94": {
			"balance": "158000000000000000000"
		},
		"f447108b98df64b57e871033885c1ad71db1a3f9": {
			"balance": "6916709000000000000000"
		},
		"deee2689fa9006b59cf285237de53b3a7fd01438": {
			"balance": "450034000000000000000"
		},
		"7f01dc7c3747ca608f983dfc8c9b39e755a3b914": {
			"balance": "206980000000000000000"
		},
		"9edeac4c026b93054dc5b1d6610c6f3960f2ad73": {
			"balance": "1200000000000000000000"
		},
		"e3cffe239c64e7e20388e622117391301b298696": {
			"balance": "500000000000000000000"
		},
		"ebbb4f2c3da8be3eb62d1ffb1f950261cf98ecda": {
			"balance": "2000000000000000000000"
		},
		"38c10b90c859cbb7815692f99dae520ab5febf5e": {
			"balance": "13169000000000000000000"
		},
		"23f9ecf3e5dddca38815d3e59ed34b5b90b4a353": {
			"balance": "204608000000000000000"
		},
		"d7fa5ffb6048f96fb1aba09ef87b1c11dd7005e4": {
			"balance": "1000000000000000000000"
		},
		"9ca42ee7a0b898f6a5cc60b5a5d7b1bfa3c33231": {
			"balance": "2000000000000000000000"
		},
		"8b9577920053b1a00189304d888010d9ef2cb4bf": {
			"balance": "500000000000000000000"
		},
		"fcd0b4827cd208ffbf5e759dba8c3cc61d8c2c3c": {
			"balance": "8000000000000000000000"
		},
		"01ff1eb1dead50a7f2f9638fdee6eccf3a7b2ac8": {
			"balance": "600000000000000000000"
		},
		"abde147b2af789eaa586547e66c4fa2664d328a4": {
			"balance": "247545000000000000000"
		},
		"64042ba68b12d4c151651ca2813b7352bd56f08e": {
			"balance": "600000000000000000000"
		},
		"dccca42045ec3e16508b603fd936e7fd7de5f36a": {
			"balance": "19700000000000000000"
		},
		"e77a89bd45dc04eeb4e41d7b596b707e6e51e74c": {
			"balance": "12000000000000000000000"
		},
		"f77c7b845149efba19e261bc7c75157908afa990": {
			"balance": "2000000000000000000000"
		},
		"fa5201fe1342af11307b9142a041243ca92e2f09": {
			"balance": "152150000000000000000000"
		},
		"40df495ecf3f8b4cef2a6c189957248fe884bc2b": {
			"balance": "12000000000000000000000"
		},
		"3d79a853d71be0621b44e29759656ca075fdf409": {
			"balance": "2000000000000000000000"
		},
		"6de02f2dd67efdb7393402fa9eaacbcf589d2e56": {
			"balance": "1182000000000000000000"
		},
		"729aad4627744e53f5d66309aa74448b3acdf46f": {
			"balance": "2000000000000000000000"
		},
		"4e4318f5e13e824a54edfe30a7ed4f26cd3da504": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"c6a286e065c85f3af74812ed8bd3a8ce5d25e21d": {
			"balance": "18200000000000000000"
		},
		"fd686de53fa97f99639e2568549720bc588c9efc": {
			"balance": "1969606000000000000000"
		},
		"06b0ff834073cce1cbc9ea557ea87b605963e8b4": {
			"balance": "300000000000000000000"
		},
		"72b5633fe477fe542e742facfd690c137854f216": {
			"balance": "1670000000000000000000"
		},
		"8bf373d076814cbc57e1c6d16a82c5be13c73d37": {
			"balance": "200000000000000000000"
		},
		"cf264e6925130906c4d7c18591aa41b2a67f6f58": {
			"balance": "2000000000000000000000"
		},
		"0ea2a210312b3e867ee0d1cc682ce1d666f18ed5": {
			"balance": "10000000000000000000000"
		},
		"d02afecf8e2ec2b62ac8ad204161fd1fae771d0e": {
			"balance": "2000000000000000000000"
		},
		"e6b20f980ad853ad04cbfc887ce6601c6be0b24c": {
			"balance": "4000000000000000000000"
		},
		"4280a58f8bb10b9440de94f42b4f592120820191": {
			"balance": "2000000000000000000000"
		},
		"a914cdb571bfd93d64da66a4e108ea134e50d000": {
			"balance": "1430143000000000000000"
		},
		"60864236930d04d8402b5dcbeb807f3caf611ea2": {
			"balance": "4000000000000000000000"
		},
		"f9dd239008182fb519fb30eedd2093fed1639be8": {
			"balance": "500000000000000000000"
		},
		"18e53243981aabc8767da10c73449f1391560eaa": {
			"balance": "6000000000000000000000"
		},
		"c3a9226ae275df2cab312b911040634a9c9c9ef6": {
			"balance": "4000000000000000000000"
		},
		"4fcc19ea9f4c57dcbce893193cfb166aa914edc5": {
			"balance": "7001380000000000000000"
		},
		"c1e1409ca52c25435134d006c2a6a8542dfb7273": {
			"balance": "34380000000000000000"
		},
		"981ddf0404e4d22dda556a0726f00b2d98ab9569": {
			"balance": "999972000000000000000"
		},
		"e5bcc88c3b256f6ed5fe550e4a18198b943356ad": {
			"balance": "2000000000000000000000"
		},
		"74a17f064b344e84db6365da9591ff1628257643": {
			"balance": "20000000000000000000"
		},
		"2720f9ca426ef2f2cbd2fecd39920c4f1a89e16d": {
			"balance": "2000000000000000000000"
		},
		"8d04a5ebfb5db409db0617c9fa5631c192861f4a": {
			"balance": "970000000000000000000"
		},
		"f18b14cbf6694336d0fe12ac1f25df2da0c05dbb": {
			"balance": "3999800000000000000000"
		},
		"56ac20d63bd803595cec036da7ed1dc66e0a9e07": {
			"balance": "63927000000000000000"
		},
		"92c94c2820dfcf7156e6f13088ece7958b3676fd": {
			"balance": "95500000000000000000"
		},
		"968dea60df3e09ae3c8d3505e9c080454be0e819": {
			"balance": "6000000000000000000000"
		},
		"9268d62646563611dc3b832a30aa2394c64613e3": {
			"balance": "2000000000000000000000"
		},
		"5a192b964afd80773e5f5eda6a56f14e25e0c6f3": {
			"balance": "500000000000000000000"
		},
		"df8d48b1eb07b3c217790e6c2df04dc319e7e848": {
			"balance": "500000000000000000000"
		},
		"7f61fa6cf5f898b440dac5abd8600d6d691fdef9": {
			"balance": "280000000000000000000"
		},
		"929d368eb46a2d1fbdc8ffa0607ede4ba88f59ad": {
			"balance": "2000000000000000000000"
		},
		"9982a5890ffb5406d3aca8d2bfc1dd70aaa80ae0": {
			"balance": "2000000000000000000000"
		},
		"bf2aea5a1dcf6ed3b5e8323944e983fedfd1acfb": {
			"balance": "1580000000000000000000"
		},
		"46aa501870677e7f0a504876b4e8801a0ad01c46": {
)E" + R"E(
			"balance": "800000000000000000000"
		},
		"8f473d0ab876ddaa15608621d7013e6ff714b675": {
			"balance": "470400000000000000000"
		},
		"02290fb5f9a517f82845acdeca0fc846039be233": {
			"balance": "2000000000000000000000"
		},
		"8a5831282ce14a657a730dc18826f7f9b99db968": {
			"balance": "4330268000000000000000"
		},
		"0328510c09dbcd85194a98d67c33ac49f2f94d60": {
			"balance": "11000000000000000000000"
		},
		"cf883a20329667ea226a1e3c765dbb6bab32219f": {
			"balance": "3038972000000000000000"
		},
		"2615100ea7e25bba9bca746058afbbb4ffbe4244": {
			"balance": "500000000000000000000"
		},
		"b115ee3ab7641e1aa6d000e41bfc1ec7210c2f32": {
			"balance": "13000000000000000000000"
		},
		"5cfa8d568575658ca4c1a593ac4c5d0e44c60745": {
			"balance": "291000000000000000000"
		},
		"d3c24d4b3a5e0ff8a4622d518edd73f16ab28610": {
			"balance": "20000000000000000000"
		},
		"a639acd96b31ba53b0d08763229e1f06fd105e9d": {
			"balance": "8000000000000000000000"
		},
		"ffa4aff1a37f984b0a67272149273ae9bd41e3bc": {
			"balance": "10000000000000000000000"
		},
		"cf684dfb8304729355b58315e8019b1aa2ad1bac": {
			"balance": "432500000000000000000"
		},
		"5797b60fd2894ab3c2f4aede86daf2e788d745ad": {
			"balance": "6000000000000000000000"
		},
		"a6a0de421ae54f6d17281308f5646d2f39f7775d": {
			"balance": "2000000000000000000000"
		},
		"08504f05643fab5919f5eea55925d7a3ed7d807a": {
			"balance": "20000000000000000000"
		},
		"7a7068e1c3375c0e599db1fbe6b2ea23b8f407d2": {
			"balance": "2000000000000000000000"
		},
		"1078d7f61b0e56c74ee6635b2e1819ef1e3d8785": {
			"balance": "1000000000000000000000"
		},
		"6e12b51e225b4a4372e59ad7a2a1a13ea3d3a137": {
			"balance": "14172200000000000000000"
		},
		"6a2e86469a5bf37cee82e88b4c3863895d28fcaf": {
			"balance": "519000000000000000000"
		},
		"197672fd39d6f246ce66a790d13aa922d70ea109": {
			"balance": "1000000000000000000000"
		},
		"8009a7cbd192b3aed4adb983d5284552c16c7451": {
			"balance": "4000000000000000000000"
		},
		"f6c3c48a1ac0a34799f04db86ec7a975fe7768f3": {
			"balance": "1970000000000000000000"
		},
		"16be75e98a995a395222d00bd79ff4b6e638e191": {
			"balance": "36000000000000000000000"
		},
		"6c05e34e5ef2f42ed09deff1026cd66bcb6960bb": {
			"balance": "2000000000000000000000"
		},
		"5d6ae8cbd6b3393c22d16254100d0238e808147c": {
			"balance": "719992000000000000000"
		},
		"1a376e1b2d2f590769bb858d4575320d4e149970": {
			"balance": "4841200000000000000000"
		},
		"f6ead67dbf5b7eb13358e10f36189d53e643cfcf": {
			"balance": "40000000000000000000000"
		},
		"467d5988249a68614716659840ed0ae6f6f457bc": {
			"balance": "387500000000000000000"
		},
		"aa960e10c52391c54e15387cc67af827b5316dcc": {
			"balance": "2000000000000000000000"
		},
		"483ba99034e900e3aedf61499d3b2bce39beb7aa": {
			"balance": "985000000000000000000"
		},
		"86f23e9c0aafc78b9c404dcd60339a925bffa266": {
			"balance": "400000000000000000000"
		},
		"d05a447c911dbb275bfb2e5a37e5a703a56f9997": {
			"balance": "200000000000000000000"
		},
		"edb71ec41bda7dce86e766e6e8c3e9907723a69b": {
			"balance": "20000000000000000000"
)E" + R"E(
		},
		"f86a3ea8071f7095c7db8a05ae507a8929dbb876": {
			"balance": "336000000000000000000"
		},
		"323b3cfe3ee62bbde2a261e53cb3ecc05810f2c6": {
			"balance": "13790000000000000000000"
		},
		"936f3813f5f6a13b8e4ffec83fe7f826186a71cd": {
			"balance": "520000000000000000000"
		},
		"6db72bfd43fef465ca5632b45aab7261404e13bf": {
			"balance": "2000000000000000000000"
		},
		"9bb76204186af2f63be79168601687fc9bad661f": {
			"balance": "300000000000000000000"
		},
		"28ab165ffb69eda0c549ae38e9826f5f7f92f853": {
			"balance": "1296890000000000000000"
		},
		"c73e2112282215dc0762f32b7e807dcd1a7aae3e": {
			"balance": "6900000000000000000000"
		},
		"f8086e42661ea929d2dda1ab6c748ce3055d111e": {
			"balance": "1000000000000000000000"
		},
		"4db21284bcd4f787a7556500d6d7d8f36623cf35": {
			"balance": "1939806000000000000000"
		},
		"c48651c1d9c16bff4c9554886c3f3f26431f6f68": {
			"balance": "658000000000000000000"
		},
		"9bdbdc9b973431d13c89a3f9757e9b3b6275bfc7": {
			"balance": "499971000000000000000"
		},
		"560da37e956d862f81a75fd580a7135c1b246352": {
			"balance": "10000000000000000000000"
		},
		"4b60a3e253bf38c8d5662010bb93a473c965c3e5": {
			"balance": "1490000000000000000000"
		},
		"64e02abb016cc23a2934f6bcddb681905021d563": {
			"balance": "1000000000000000000000"
		},
		"ac2c8e09d06493a63858437bd20be01962450365": {
			"balance": "1910000000000000000000"
		},
		"9bf9b3b2f23cf461eb591f28340bc719931c8364": {
			"balance": "1000000000000000000000"
		},
		"9b5c39f7e0ac168c8ed0ed340477117d1b682ee9": {
			"balance": "98000000000000000000"
		},
		"f75bb39c799779ebc04a336d260da63146ed98d0": {
			"balance": "25000000000000000000"
		},
		"a7966c489f4c748a7ae980aa27a574251767caf9": {
			"balance": "3000000000000000000000"
		},
		"ea53c954f4ed97fd4810111bdab69ef981ef25b9": {
			"balance": "17300000000000000000000"
		},
		"03a26cfc4c18316f70d59e9e1a79ee3e8b962f4c": {
			"balance": "2000000000000000000000"
		},
		"3e63ce3b24ca2865b4c5a687b7aea3597ef6e548": {
			"balance": "2000000000000000000000"
		},
		"500c902958f6421594d1b6ded712490d52ed6c44": {
			"balance": "1970000000000000000000"
		},
		"6f44ca09f0c6a8294cbd519cdc594ad42c67579f": {
			"balance": "50000000000000000000"
		},
		"3616fb46c81578c9c8eb4d3bf880451a88379d7d": {
			"balance": "200000000000000000000"
		},
		"57bc20e2d62b3d19663cdb4c309d5b4f2fc2db8f": {
			"balance": "100000000000000000000"
		},
		"1cebf0985d7f680aaa915c44cc62edb49eab269e": {
			"balance": "1000000000000000000000"
		},
		"c0cbf6032fa39e7c46ff778a94f7d445fe22cf30": {
			"balance": "310000000000000000000"
		},
		"c58b9cc61dedbb98c33f224d271f0e228b583433": {
			"balance": "3880000000000000000000"
		},
		"e9c6dfae97f7099fc5f4e94b784db802923a1419": {
			"balance": "48800000000000000000"
		},
		"9bacd3d40f3b82ac91a264d9d88d908eac8664b9": {
			"balance": "20000000000000000000000"
		},
		"63d80048877596e0c28489e650cd4ac180096a49": {
			"balance": "280000000000000000000"
		},
		"e6a6f6dd6f70a456f4ec15ef7ad5e5dbb68bd7dc": {
			"balance": "200000000000000000000"
		},
)E" + R"E(
		"d418870bc2e4fa7b8a6121ae0872d55247b62501": {
			"balance": "1580000000000000000000"
		},
		"e2f9383d5810ea7b43182b8704b62b27f5925d39": {
			"balance": "400000000000000000000"
		},
		"bd5e473abce8f97a6932f77c2facaf9cc0a00514": {
			"balance": "1117350000000000000000"
		},
		"2ff1ca55fd9cec1b1fe9f0a9abb74c513c1e2aaa": {
			"balance": "3000000000000000000000"
		},
		"9d99b189bbd9a48fc2e16e8fcda33bb99a317bbb": {
			"balance": "1126900000000000000000"
		},
		"6e96faeda3054302c45f58f161324c99a3eebb62": {
			"balance": "20000000000000000000"
		},
		"ef93818f684db0c3675ec81332b3183ecc28a495": {
			"balance": "1550000000000000000000"
		},
		"2659facb1e83436553b5b42989adb8075f9953ed": {
			"balance": "29356000000000000000"
		},
		"c4ffadaaf2823fbea7bff702021bffc4853eb5c9": {
			"balance": "42233000000000000000"
		},
		"e9864c1afc8eaad37f3ba56fcb7477cc622009b7": {
			"balance": "79000000000000000000"
		},
		"87ef6d8b6a7cbf9b5c8c97f67ee2adc2a73b3f77": {
			"balance": "200400000000000000000"
		},
		"c043f2452dcb9602ef62bd360e033dd23971fe84": {
			"balance": "2000000000000000000000"
		},
		"0fdd65402395df9bd19fee4507ef5345f745104c": {
			"balance": "5000000000000000000000"
		},
		"939c4313d2280edf5e071bced846063f0a975d54": {
			"balance": "120000000000000000000000"
		},
		"b28245037cb192f75785cb86cbfe7c930da258b0": {
			"balance": "16000000000000000000000"
		},
		"a80cb1738bac08d4f9c08b4deff515545fa8584f": {
			"balance": "500000000000000000000"
		},
		"62971bf2634cee0be3c9890f51a56099dbb9519b": {
			"balance": "656000000000000000000"
		},
		"f2efe96560c9d97b72bd36447843885c1d90c231": {
			"balance": "2000000000000000000000"
		},
		"0e390f44053ddfcef0d608b35e4d9c2cbe9871bb": {
			"balance": "1970000000000000000000"
		},
		"61d101a033ee0e2ebb3100ede766df1ad0244954": {
			"balance": "500000000000000000000"
		},
		"6785513cf732e47e87670770b5419be10cd1fc74": {
			"balance": "2000000000000000000000"
		},
		"167699f48a78c615512515739958993312574f07": {
			"balance": "39000000000000000000"
		},
		"68ec79d5be7155716c40941c79d78d17de9ef803": {
			"balance": "500600000000000000000"
		},
		"a0e8ba661b48154cf843d4c2a5c0f792d528ee29": {
			"balance": "400000000000000000000"
		},
		"1a201b4327cea7f399046246a3c87e6e03a3cda8": {
			"balance": "1000000000000000000000"
		},
		"f60f62d73937953fef35169e11d872d2ea317eec": {
			"balance": "5348000000000000000000"
		},
		"c0c04d0106810e3ec0e54a19f2ab8597e69a573d": {
			"balance": "50000000000000000000"
		},
		"ef47cf073e36f271d522d7fa4e7120ad5007a0bc": {
			"balance": "2500000000000000000000"
		},
		"a44fe800d96fcad73b7170d0f610cb8c0682d6ce": {
			"balance": "4000000000000000000000"
		},
		"010f4a98dfa1d9799bf5c796fb550efbe7ecd877": {
			"balance": "8023366000000000000000"
		},
		"708fa11fe33d85ad1befcbae3818acb71f6a7d7e": {
			"balance": "18200000000000000000"
		},
		"b38c4e537b5df930d65a74d043831d6b485bbde4": {
			"balance": "400000000000000000000"
		},
		"250a69430776f6347703f9529783955a6197b682": {
			"balance": "1940000000000000000000"
		},
		"2d35a9df62757f7ffad1049afb06ca4afc464c51": {
)E" + R"E(
			"balance": "20000000000000000000"
		},
		"6aff1466c2623675e3cb0e75e423d37a25e442eb": {
			"balance": "1730000000000000000000"
		},
		"fc15cb99a8d1030b12770add033a79ee0d0c908c": {
			"balance": "350056000000000000000"
		},
		"e784dcc873aa8c1513ec26ff36bc92eac6d4c968": {
			"balance": "200000000000000000000"
		},
		"b1c328fb98f2f19ab6646f0a7c8c566fda5a8540": {
			"balance": "2500000000000000000000"
		},
		"247a0a11c57f0383b949de540b66dee68604b0a1": {
			"balance": "1069600000000000000000"
		},
		"1af60343360e0b2d75255210375720df21db5c7d": {
			"balance": "1000000000000000000000"
		},
		"8794bf47d54540ece5c72237a1ffb511ddb74762": {
			"balance": "2000000000000000000000"
		},
		"e76d945aa89df1e457aa342b31028a5e9130b2ce": {
			"balance": "1015200000000000000000"
		},
		"a30e0acb534c9b3084e8501da090b4eb16a2c0cd": {
			"balance": "2000000000000000000000"
		},
		"7099d12f6ec656899b049a7657065d62996892c8": {
			"balance": "400000000000000000000"
		},
		"7be7f2456971883b9a8dbe4c91dec08ac34e8862": {
			"balance": "3000000000000000000000"
		},
		"42746aeea14f27beff0c0da64253f1e7971890a0": {
			"balance": "1550000000000000000000"
		},
		"736b44503dd2f6dd5469ff4c5b2db8ea4fec65d0": {
			"balance": "313950000000000000000"
		},
		"822edff636563a6106e52e9a2598f7e6d0ef2782": {
			"balance": "36099000000000000000"
		},
		"03c647a9f929b0781fe9ae01caa3e183e876777e": {
			"balance": "445800000000000000000"
		},
		"63612e7862c27b587cfb6daf9912cb051f030a9f": {
			"balance": "43458000000000000000"
		},
		"d46bae61b027e5bb422e83a3f9c93f3c8fc77d27": {
			"balance": "2000000000000000000000"
		},
		"5f23ba1f37a96c45bc490259538a54c28ba3b0d5": {
			"balance": "1200000000000000000000"
		},
		"d41d7fb49fe701baac257170426cc9b38ca3a9b2": {
			"balance": "176000000000000000000"
		},
		"1ebacb7844fdc322f805904fbf1962802db1537c": {
			"balance": "10000000000000000000000"
		},
		"9c80bc18e9f8d4968b185da8c79fa6e11ffc3e23": {
			"balance": "240000000000000000000"
		},
		"e4ca0a5238564dfc91e8bf22bade2901619a1cd4": {
			"balance": "1000000000000000000000"
		},
		"1ad72d20a76e7fcc6b764058f48d417d496fa6cd": {
			"balance": "2000000000000000000000"
		},
		"d3bc730937fa75d8452616ad1ef1fe7fffe0d0e7": {
			"balance": "83363000000000000000"
		},
		"eac1482826acb6111e19d340a45fb851576bed60": {
			"balance": "32177000000000000000"
		},
		"01e40521122530d9ac91113c06a0190b6d63850b": {
			"balance": "1337000000000000000000"
		},
		"9e20e5fd361eabcf63891f5b87b09268b8eb3793": {
			"balance": "100000000000000000000"
		},
		"69ff429074cb9b6c63bc914284bce5f0c8fbf7d0": {
			"balance": "500000000000000000000"
		},
		"0d3265d3e7bdb93d5e8e8b1ca47f210a793ecc8e": {
			"balance": "200000000000000000000"
		},
		"5b4ea16db6809b0352d4b6e81c3913f76a51bb32": {
			"balance": "400000000000000000000"
		},
		"d8fe088fffce948f5137ee23b01d959e84ac4223": {
			"balance": "227942000000000000000"
		},
		"7e4e9409704121d1d77997026ff06ea9b19a8b90": {
			"balance": "2602600000000000000000"
		},
		"96b434fe0657e42acc8212b6865139dede15979c": {
			"balance": "4000000000000000000000"
)E" + R"E(
		},
		"22f004df8de9e6ebf523ccace457accb26f97281": {
			"balance": "10000000000000000000000"
		},
		"d8f9240c55cff035523c6d5bd300d370dc8f0c95": {
			"balance": "285000000000000000000"
		},
		"9d9e57fde30e5068c03e49848edce343b7028358": {
			"balance": "1730000000000000000000"
		},
		"317cf4a23cb191cdc56312c29d15e210b3b9b784": {
			"balance": "144000000000000000000"
		},
		"79f08e01ce0988e63c7f8f2908fade43c7f9f5c9": {
			"balance": "18200000000000000000"
		},
		"04e5f5bc7c923fd1e31735e72ef968fd67110c6e": {
			"balance": "1611000000000000000000"
		},
		"1ec4ec4b77bf19d091a868e6f49154180541f90e": {
			"balance": "2000000000000000000000"
		},
		"8737dae671823a8d5917e0157ace9c43468d946b": {
			"balance": "1999944000000000000000"
		},
		"f998ca3411730a6cd10e7455b0410fb0f6d3ff80": {
			"balance": "2000000000000000000000"
		},
		"6e2eab85dc89fe29dc0aa1853247dab43a523d56": {
			"balance": "80000000000000000000"
		},
		"72c083beadbdc227c5fb43881597e32e83c26056": {
			"balance": "20000000000000000000000"
		},
		"5902e44af769a87246a21e079c08bf36b06efeb3": {
			"balance": "1000000000000000000000"
		},
		"cc2d04f0a4017189b340ca77198641dcf6456b91": {
			"balance": "3940000000000000000000"
		},
		"bde4c73f969b89e9ceae66a2b51844480e038e9a": {
			"balance": "1000000000000000000000"
		},
		"adff0d1d0b97471e76d789d2e49c8a74f9bd54ff": {
			"balance": "1880000000000000000000"
		},
		"397cdb8c80c67950b18d654229610e93bfa6ee1a": {
			"balance": "1172938000000000000000"
		},
		"a3e051fb744aa3410c3b88f899f5d57f168df12d": {
			"balance": "2955000000000000000000"
		},
		"810db25675f45ea4c7f3177f37ce29e22d67999c": {
			"balance": "200000000000000000000"
		},
		"1e13ec51142cebb7a26083412c3ce35144ba56a1": {
			"balance": "5000000000000000000000"
		},
		"25bdfa3ee26f3849617b230062588a97e3cae701": {
			"balance": "1000008000000000000000"
		},
		"ae538c73c5b38d8d584d7ebdadefb15cabe48357": {
			"balance": "999000000000000000000"
		},
		"a2ecce2c49f72a0995a0bda57aacf1e9f001e22a": {
			"balance": "4000000000000000000000"
		},
		"7e24fbdad290175eb2df6d180a19b9a9f41370be": {
			"balance": "1000000000000000000000"
		},
		"e8cc43bc4f8acf39bff04ebfbf42aac06a328470": {
			"balance": "400000000000000000000"
		},
		"c2779771f0536d79a8708f6931abc44b3035e999": {
			"balance": "20002000000000000000000"
		},
		"ab27ba78c8e5e3daef31ad05aef0ff0325721e08": {
			"balance": "468000000000000000000"
		},
		"563cb8803c1d32a25b27b64114852bd04d9c20cd": {
			"balance": "204400000000000000000"
		},
		"08d4267feb15da9700f7ccc3c84a8918bf17cfde": {
			"balance": "1790000000000000000000"
		},
		"d1778c13fbd968bc083cb7d1024ffe1f49d02caa": {
			"balance": "4020000000000000000000"
		},
		"1796bcc97b8abc717f4b4a7c6b1036ea2182639f": {
			"balance": "355242000000000000000"
		},
		"beecd6af900c8b064afcc6073f2d85d59af11956": {
			"balance": "2000000000000000000000"
		},
		"045ed7f6d9ee9f252e073268db022c6326adfc5b": {
			"balance": "100000000000000000000"
		},
		"b88a37c27f78a617d5c091b7d5b73a3761e65f2a": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"72fb49c29d23a18950c4b2dc0ddf410f532d6f53": {
			"balance": "2000000000000000000000"
		},
		"6ecaefa6fc3ee534626db02c6f85a0c395571e77": {
			"balance": "600000000000000000000"
		},
		"d1811c55976980f083901d8a0db269222dfb5cfe": {
			"balance": "1550000000000000000000"
		},
		"98855c7dfbee335344904a12c40c731795b13a54": {
			"balance": "1069600000000000000000"
		},
		"92a898d46f19719c38126a8a3c27867ae2cee596": {
			"balance": "2000000000000000000000"
		},
		"ca428863a5ca30369892d612183ef9fb1a04bcea": {
			"balance": "1520000000000000000000"
		},
		"797427e3dbf0feae7a2506f12df1dc40326e8505": {
			"balance": "1000000000000000000000"
		},
		"3d574fcf00fae1d98cc8bf9ddfa1b3953b9741bc": {
			"balance": "1970000000000000000000"
		},
		"28818e18b610001321b31df6fe7d2815cdadc9f5": {
			"balance": "1000000000000000000000"
		},
		"5f3e1e6739b0c62200e00a003691d9efb238d89f": {
			"balance": "3000000000000000000000"
		},
		"d9d370fec63576ab15b318bf9e58364dc2a3552a": {
			"balance": "100000000000000000000"
		},
		"b223bf1fbf80485ca2b5567d98db7bc3534dd669": {
			"balance": "4000000000000000000000"
		},
		"7b27d0d1f3dd3c140294d0488b783ebf4015277d": {
			"balance": "400000000000000000000"
		},
		"7930c2d9cbfa87f510f8f98777ff8a8448ca5629": {
			"balance": "199955000000000000000"
		},
		"820c19291196505b65059d9914b7090be1db87de": {
			"balance": "140000000000000000000"
		},
		"e545ee84ea48e564161e9482d59bcf406a602ca2": {
			"balance": "1850000000000000000000"
		},
		"af4cf41785161f571d0ca69c94f8021f41294eca": {
			"balance": "9850000000000000000000"
		},
		"7a4f9b850690c7c94600dbee0ca4b0a411e9c221": {
			"balance": "1910000000000000000000"
		},
		"ddab6b51a9030b40fb95cf0b748a059c2417bec7": {
			"balance": "2000000000000000000000"
		},
		"315ef2da620fd330d12ee55de5f329a696e0a968": {
			"balance": "150000000000000000000"
		},
		"4db1c43a0f834d7d0478b8960767ec1ac44c9aeb": {
			"balance": "872870000000000000000"
		},
		"2fef81478a4b2e8098db5ff387ba2153f4e22b79": {
			"balance": "999000000000000000000"
		},
		"6c6aa0d30b64721990b9504a863fa0bfb5e57da7": {
			"balance": "2700000000000000000000"
		},
		"33380c6fff5acd2651309629db9a71bf3f20c5ba": {
			"balance": "16100000000000000000000"
		},
		"4eebf1205d0cc20cee6c7f8ff3115f56d48fba26": {
			"balance": "19400000000000000000"
		},
		"03cc9d2d21f86b84ac8ceaf971dba78a90e62570": {
			"balance": "1610000000000000000000"
		},
		"728f9ab080157db3073156dbca1a169ef3179407": {
			"balance": "500000000000000000000"
		},
		"30ed11b77bc17e5e6694c8bc5b6e4798f68d9ca7": {
			"balance": "143731500000000000000000"
		},
		"f617b967b9bd485f7695d2ef51fb7792d898f500": {
			"balance": "500000000000000000000"
		},
		"c0cbad3ccdf654da22cbcf5c786597ca1955c115": {
			"balance": "2000000000000000000000"
		},
		"80522ddf944ec52e27d724ed4c93e1f7be6083d6": {
			"balance": "200000000000000000000"
		},
		"4e90ccb13258acaa9f4febc0a34292f95991e230": {
			"balance": "15800000000000000000"
		},
		"ff207308ced238a6c01ad0213ca9eb4465d42590": {
			"balance": "1999944000000000000000"
		},
		"35f2949cf78bc219bb4f01907cf3b4b3d3865482": {
)E" + R"E(
			"balance": "289800000000000000000"
		},
		"68f525921dc11c329b754fbf3e529fc723c834cd": {
			"balance": "1610000000000000000000"
		},
		"81139bfdcca656c430203f72958c543b6580d40c": {
			"balance": "2000000000000000000000"
		},
		"9d511543b3d9dc60d47f09d49d01b6c498d82078": {
			"balance": "11245000000000000000000"
		},
		"084d103254759b343cb2b9c2d8ff9e1ac5f14596": {
			"balance": "7600000000000000000000"
		},
		"b323dcbf2eddc5382ee4bbbb201ca3931be8b438": {
			"balance": "2000000000000000000000"
		},
		"349d2c918fd09e2807318e66ce432909176bd50b": {
			"balance": "1120000000000000000000"
		},
		"b535f8db879fc67fec58824a5cbe6e5498aba692": {
			"balance": "1910000000000000000000"
		},
		"824074312806da4748434266ee002140e3819ac2": {
			"balance": "1507000000000000000000"
		},
		"e8ef100d7ce0895832f2678df72d4acf8c28b8e3": {
			"balance": "500038000000000000000"
		},
		"84af1b157342d54368260d17876230a534b54b0e": {
			"balance": "985000000000000000000"
		},
		"419a71a36c11d105e0f2aef5a3e598078e85c80b": {
			"balance": "5000000000000000000000"
		},
		"55af092f94ba6a79918b0cf939eab3f01b3f51c7": {
			"balance": "149940000000000000000"
		},
		"35a549e8fd6c368d6dcca6d2e7d18e4db95f5284": {
			"balance": "499938000000000000000"
		},
		"f0e2649c7e6a3f2c5dfe33bbfbd927ca3c350a58": {
			"balance": "2000000000000000000000"
		},
		"f4b759cc8a1c75f80849ebbcda878dc8f0d66de4": {
			"balance": "400000000000000000000"
		},
		"21846f2fdf5a41ed8df36e5ed8544df75988ece3": {
			"balance": "1999944000000000000000"
		},
		"229ff80bf5708009a9f739e0f8b560914016d5a6": {
			"balance": "333333000000000000000"
		},
		"da505537537ffb33c415fec64e69bae090c5f60f": {
			"balance": "160000000000000000000"
		},
		"b91d9e916cd40d193db60e79202778a0087716fc": {
			"balance": "404800000000000000000"
		},
		"bb6823a1bd819f13515538264a2de052b4442208": {
			"balance": "25610000000000000000"
		},
		"459393d63a063ef3721e16bd9fde45ee9dbd77fb": {
			"balance": "1968818000000000000000"
		},
		"95f62d0243ede61dad9a3165f53905270d54e242": {
			"balance": "1610000000000000000000"
		},
		"b0bb29a861ea1d424d45acd4bfc492fb8ed809b7": {
			"balance": "80000000000000000000"
		},
		"5e74ed80e9655788e1bb269752319667fe754e5a": {
			"balance": "56000000000000000000"
		},
		"a276b058cb98d88beedb67e543506c9a0d9470d8": {
			"balance": "2668652000000000000000"
		},
		"8ae9ef8c8a8adfa6ab798ab2cdc405082a1bbb70": {
			"balance": "2000000000000000000000"
		},
		"e5102c3b711b810344197419b1cd8a7059f13e32": {
			"balance": "299999000000000000000"
		},
		"c32038ca52aee19745be5c31fcdc54148bb2c4d0": {
			"balance": "49984000000000000000"
		},
		"13e321728c9c57628058e93fc866a032dd0bda90": {
			"balance": "714580000000000000000"
		},
		"c2bae4a233c2d85724f0dabebda0249d833e37d3": {
			"balance": "5000000000000000000000"
		},
		"10d32416722ca4e648630548ead91edd79c06aff": {
			"balance": "100000000000000000000"
		},
		"d5f07552b5c693c20067b378b809cee853b8f136": {
			"balance": "505540000000000000000"
		},
		"8668af868a1e98885f937f2615ded6751804eb2d": {
			"balance": "20000000000000000000"
)E" + R"E(
		},
		"139d3531c9922ad56269f6309aa789fb2485f98c": {
			"balance": "4000000000000000000000"
		},
		"1d29c7aab42b2048d2b25225d498dba67a03fbb2": {
			"balance": "200000000000000000000"
		},
		"d35075ca61fe59d123969c36a82d1ab2d918aa38": {
			"balance": "2674000000000000000000"
		},
		"d6fc0446c6a8d40ae3551db7e701d1fa876e4a49": {
			"balance": "2000000000000000000000"
		},
		"fccd0d1ecee27addea95f6857aeec8c7a04b28ee": {
			"balance": "10000000000000000000000"
		},
		"c12cfb7b3df70fceca0ede263500e27873f8ed16": {
			"balance": "1000000000000000000000"
		},
		"d0db456178206f5c4430fe005063903c3d7a49a7": {
			"balance": "706245000000000000000"
		},
		"73cf80ae9688e1580e68e782cd0811f7aa494d2c": {
			"balance": "7760000000000000000000"
		},
		"d60651e393783423e5cc1bc5f889e44ef7ea243e": {
			"balance": "398800000000000000000"
		},
		"048a8970ea4145c64d5517b8de5b46d0595aad06": {
			"balance": "20000000000000000000000"
		},
		"dd9b485a3b1cd33a6a9c62f1e5bee92701856d25": {
			"balance": "225073000000000000000"
		},
		"5b287c7e734299e727626f93fb1187a60d5057fe": {
			"balance": "101230000000000000000"
		},
		"635c00fdf035bca15fa3610df3384e0fb79068b1": {
			"balance": "9000000000000000000000"
		},
		"630a913a9031c9492abd4c41dbb15054cfec4416": {
			"balance": "5688000000000000000000"
		},
		"af3614dcb68a36e45a4e911e62796247222d595b": {
			"balance": "2259800000000000000000"
		},
		"335e22025b7a77c3a074c78b8e3dfe071341946e": {
			"balance": "10178744000000000000000"
		},
		"f0e1dfa42adeac2f17f6fdf584c94862fd563393": {
			"balance": "500000000000000000000"
		},
		"1a9e702f385dcd105e8b9fa428eea21c57ff528a": {
			"balance": "1400000000000000000000"
		},
		"8ce4949d8a16542d423c17984e6739fa72ceb177": {
			"balance": "24999975000000000000000"
		},
		"5f29c9de765dde25852af07d33f2ce468fd20982": {
			"balance": "2000000000000000000000"
		},
		"dbf5f061a0f48e5e69618739a77d2ec19768d201": {
			"balance": "152000000000000000000"
		},
		"b247cf9c72ec482af3eaa759658f793d670a570c": {
			"balance": "912000000000000000000"
		},
		"99f4147ccc6bcb80cc842e69f6d00e30fa4133d9": {
			"balance": "400000000000000000000"
		},
		"ba6d31b9a261d640b5dea51ef2162c3109f1eba8": {
			"balance": "5000000000000000000000"
		},
		"f05ba8d7b68539d933300bc9289c3d9474d0419e": {
			"balance": "126400000000000000000"
		},
		"682e96276f518d31d7e56e30dfb009c1218201bd": {
			"balance": "20000000000000000000"
		},
		"0927220492194b2eda9fc4bbe38f25d681dfd36c": {
			"balance": "6000000000000000000000"
		},
		"a3c33afc8cb4704e23153de2049d35ae71332472": {
			"balance": "799600000000000000000"
		},
		"05c736d365aa37b5c0be9c12c8ad5cd903c32cf9": {
			"balance": "6002000000000000000000"
		},
		"d8eef4cf4beb01ee20d111748b61cb4d3f641a01": {
			"balance": "2740000000000000000000"
		},
		"16c1bf5b7dc9c83c179efacbcf2eb174e3561cb3": {
			"balance": "1000000000000000000000"
		},
		"d79db5ab43621a7a3da795e58929f3dd25af67d9": {
			"balance": "1999944000000000000000"
		},
		"28efae6356509edface89fc61a7fdcdb39eea8e5": {
			"balance": "5348000000000000000000"
		},
)E" + R"E(
		"c55005a6c37e8ca7e543ce259973a3cace961a4a": {
			"balance": "2000000000000000000000"
		},
		"ab3d86bc82927e0cd421d146e07f919327cdf6f9": {
			"balance": "1910000000000000000000"
		},
		"b74ed2666001c16333cf7af59e4a3d4860363b9c": {
			"balance": "193600000000000000000"
		},
		"1899f69f653b05a5a6e81f480711d09bbf97588c": {
			"balance": "1955000000000000000000"
		},
		"27fc85a49cff90dbcfdadc9ddd40d6b9a2210a6c": {
			"balance": "100000000000000000000"
		},
		"cd1ed263fbf6f6f7b48aef8f733d329d4382c7c7": {
			"balance": "18500000000000000000"
		},
		"d97fe6f53f2a58f6d76d752adf74a8a2c18e9074": {
			"balance": "309990000000000000000"
		},
		"80da2fdda29a9e27f9e115975e69ae9cfbf3f27e": {
			"balance": "200000000000000000000"
		},
		"09146ea3885176f07782e1fe30dce3ce24c49e1f": {
			"balance": "20000000000000000000"
		},
		"393ff4255e5c658f2e7f10ecbd292572671bc2d2": {
			"balance": "2000000000000000000000"
		},
		"a390ca122b8501ee3e5e07a8ca4b419f7e4dae15": {
			"balance": "100000000000000000000"
		},
		"6d9193996b194617211106d1635eb26cc4b66c6c": {
			"balance": "399640000000000000000"
		},
		"999c49c174ca13bc836c1e0a92bff48b271543ca": {
			"balance": "3280000000000000000000"
		},
		"7421ce5be381738ddc83f02621974ff0686c79b8": {
			"balance": "1632000000000000000000"
		},
		"6be9030ee6e2fbc491aca3de4022d301772b7b7d": {
			"balance": "26740000000000000000"
		},
		"81bd75abd865e0c3f04a0b4fdbcb74d34082fbb7": {
			"balance": "4000000000000000000000"
		},
		"8bc1ff8714828bf286ff7e8a7709106548ed1b18": {
			"balance": "10000000000000000000000"
		},
		"a0aadbd9509722705f6d2358a5c79f37970f00f6": {
			"balance": "200000000000000000000"
		},
		"3d881433f04a7d0d27f84944e08a512da3555287": {
			"balance": "1200000000000000000000"
		},
		"cc1d6ead01aada3e8dc7b95dca25df26eefa639d": {
			"balance": "2000000000000000000000"
		},
		"35106ba94e8563d4b3cb3c5c692c10e604b7ced8": {
			"balance": "2000000000000000000000"
		},
		"4d8697af0fbf2ca36e8768f4af22133570685a60": {
			"balance": "20000000000000000000"
		},
		"1afcc585896cd0ede129ee2de5c19ea811540b64": {
			"balance": "3231259000000000000000"
		},
		"e5215631b14248d45a255296bed1fbfa0330ff35": {
			"balance": "1310000000000000000000"
		},
		"e3878f91ca86053fced5444686a330e09cc388fb": {
			"balance": "194000000000000000000"
		},
		"555df19390c16d01298772bae8bc3a1152199cbd": {
			"balance": "200000000000000000000"
		},
		"dc3dae59ed0fe18b58511e6fe2fb69b219689423": {
			"balance": "100000000000000000000"
		},
		"74648caac748dd135cd91ea14c28e1bd4d7ff6ae": {
			"balance": "3100000000000000000000"
		},
		"cf2e2ad635e9861ae95cb9bafcca036b5281f5ce": {
			"balance": "35200000000000000000000"
		},
		"14eec09bf03e352bd6ff1b1e876be664ceffd0cf": {
			"balance": "20094000000000000000"
		},
		"856e5ab3f64c9ab56b009393b01664fc0324050e": {
			"balance": "1790000000000000000000"
		},
		"632b9149d70178a7333634275e82d5953f27967b": {
			"balance": "700000000000000000000"
		},
		"2a39190a4fde83dfb3ddcb4c5fbb83ac6c49755c": {
			"balance": "1000000000000000000000"
		},
		"369ef761195f3a373e24ece6cd22520fe0b9e86e": {
)E" + R"E(
			"balance": "534933000000000000000"
		},
		"16afa787fc9f94bdff6976b1a42f430a8bf6fb0f": {
			"balance": "2000000000000000000000"
		},
		"1b0b31afff4b6df3653a94d7c87978ae35f34aae": {
			"balance": "354600000000000000000"
		},
		"b4d82f2e69943f7de0f5f7743879406fac2e9cec": {
			"balance": "40000000000000000000"
		},
		"09d6cefd75b0c4b3f8f1d687a522c96123f1f539": {
			"balance": "6000000000000000000000"
		},
		"01577afd4e50890247c9b10d44af73229aec884f": {
			"balance": "680000000000000000000"
		},
		"a35606d51220ee7f2146d411582ee4ee4a45596e": {
			"balance": "3996800000000000000000"
		},
		"352e77c861696ef96ad54934f894aa8ea35151dd": {
			"balance": "1000000000000000000000"
		},
		"b87f5376c2de0b6cc3c179c06087aa473d6b4674": {
			"balance": "1337000000000000000000"
		},
		"5b49afcd75447838f6e7ceda8d21777d4fc1c3c0": {
			"balance": "4000000000000000000000"
		},
		"b884add88d83dc564ab8e0e02cbdb63919aea844": {
			"balance": "2000000000000000000000"
		},
		"5c312a56c784b122099b764d059c21ece95e84ca": {
			"balance": "95000000000000000000"
		},
		"4697baaf9ccb603fd30430689d435445e9c98bf5": {
			"balance": "199600000000000000000"
		},
		"c625f8c98d27a09a1bcabd5128b1c2a94856af30": {
			"balance": "200000000000000000000"
		},
		"19f5caf4c40e6908813c0745b0aea9586d9dd931": {
			"balance": "664000000000000000000"
		},
		"1e596a81b357c6f24970cc313df6dbdaabd0d09e": {
			"balance": "2000000000000000000000"
		},
		"c1631228efbf2a2e3a4092ee8900c639ed34fbc8": {
			"balance": "955000000000000000000"
		},
		"6f6cf20649a9e973177ac67dbadee4ebe5c7bdda": {
			"balance": "5080000000000000000000"
		},
		"5fa7bfe043886127d4011d8356a47e947963aca8": {
			"balance": "1820000000000000000000"
		},
		"6af8e55969682c715f48ad4fc0fbb67eb59795a3": {
			"balance": "2000000000000000000000"
		},
		"122f56122549d168a5c5e267f52662e5c5cce5c8": {
			"balance": "185000000000000000000"
		},
		"7713ab8037411c09ba687f6f9364f0d3239fac28": {
			"balance": "10000000000000000000000"
		},
		"31ccc616b3118268e75d9ab8996c8858ebd7f3c3": {
			"balance": "399924000000000000000"
		},
		"09c88f917e4d6ad473fa12e98ea3c4472a5ed6da": {
			"balance": "10000000000000000000000"
		},
		"e796fd4e839b4c95d7510fb7c5c72b83c6c3e3c7": {
			"balance": "512200000000000000000"
		},
		"a8285539869d88f8a961533755717d7eb65576ae": {
			"balance": "200000000000000000000"
		},
		"d929c65d69d5bbaea59762662ef418bc21ad924a": {
			"balance": "1000000000000000000000"
		},
		"f7418aa0e713d248228776b2e7434222ae75e3a5": {
			"balance": "2000000000000000000000"
		},
		"7f0b90a1fdd48f27b268feb38382e55ddb50ef0f": {
			"balance": "940000000000000000000"
		},
		"34a0431fff5ead927f3c69649616dc6e97945f6f": {
			"balance": "400000000000000000000"
		},
		"1b3cb81e51011b549d78bf720b0d924ac763a7c2": {
			"balance": "560000000000000000000000"
		},
		"155b3779bb6d56342e2fda817b5b2d81c7f41327": {
			"balance": "50200000000000000000"
		},
		"ecd486fc196791b92cf612d348614f9156488b7e": {
			"balance": "12000000000000000000000"
		},
		"82a8cbbfdff02b2e38ae4bbfca15f1f0e83b1aea": {
			"balance": "84999000000000000000"
)E" + R"E(
		},
		"06b0c1e37f5a5ec4bbf50840548f9d3ac0288897": {
			"balance": "4000098000000000000000"
		},
		"e6d49f86c228f47367a35e886caacb271e539429": {
			"balance": "412656000000000000000"
		},
		"704a6eb41ba34f13addde7d2db7df04915c7a221": {
			"balance": "1820000000000000000000"
		},
		"745ccf2d819edbbddea8117b5c49ed3c2a066e93": {
			"balance": "4000000000000000000000"
		},
		"6d3b7836a2b9d899721a4d237b522385dce8dfcd": {
			"balance": "1000070000000000000000"
		},
		"856aa23c82d7215bec8d57f60ad75ef14fa35f44": {
			"balance": "20000000000000000000000"
		},
		"ea79057dabef5e64e7b44f7f18648e7e533718d2": {
			"balance": "200000000000000000000"
		},
		"9df057cd03a4e27e8e032f857985fd7f01adc8d7": {
			"balance": "2000000000000000000000"
		},
		"5f2f07d2d697e8c567fcfdfe020f49f360be2139": {
			"balance": "2000000000000000000000"
		},
		"5efbdfe5389999633c26605a5bfc2c1bb5959393": {
			"balance": "69200000000000000000"
		},
		"047e87c8f7d1fce3b01353a85862a948ac049f3e": {
			"balance": "1490000000000000000000"
		},
		"265383d68b52d034161bfab01ae1b047942fbc32": {
			"balance": "21000600000000000000000"
		},
		"760ff3354e0fde938d0fb5b82cef5ba15c3d2916": {
			"balance": "10000000000000000000000"
		},
		"bc46d537cf2edd403565bde733b2e34b215001bd": {
			"balance": "20000000000000000000000"
		},
		"ee58fb3db29070d0130188ce472be0a172b89055": {
			"balance": "10021400000000000000000"
		},
		"75abe5270f3a78ce007cf37f8fbc045d489b7bb1": {
			"balance": "1999944000000000000000"
		},
		"5fc6c11426b4a1eae7e51dd512ad1090c6f1a85b": {
			"balance": "2730000000000000000000"
		},
		"26cfffd052152bb3f957b478d5f98b233a7c2b92": {
			"balance": "4000000000000000000000"
		},
		"0a4a011995c681bc999fdd79754e9a324ae3b379": {
			"balance": "41350300000000000000000"
		},
		"6fa60df818a5446418b1bbd62826e0b9825e1318": {
			"balance": "13200000000000000000000"
		},
		"63d55ad99b9137fd1b20cc2b4f03d42cbaddf334": {
			"balance": "400000000000000000000"
		},
		"679b9a109930517e8999099ccf2a914c4c8dd934": {
			"balance": "60000000000000000000"
		},
		"3e83544f0082552572c782bee5d218f1ef064a9d": {
			"balance": "100076000000000000000"
		},
		"968b14648f018333687cd213fa640aec04ce6323": {
			"balance": "1000000000000000000000"
		},
		"427b462ab84e5091f48a46eb0cdc92ddcb26e078": {
			"balance": "2000000000000000000000"
		},
		"df8510793eee811c2dab1c93c6f4473f30fbef5b": {
			"balance": "1000000000000000000000"
		},
		"362fbcb10662370a068fc2652602a2577937cce6": {
			"balance": "200000000000000000000"
		},
		"5d83b21bd2712360436b67a597ee3378db3e7ae4": {
			"balance": "2000000000000000000000"
		},
		"5777441c83e03f0be8dd340bde636850847c620b": {
			"balance": "10000000000000000000000"
		},
		"c94a585203da7bbafd93e15884e660d4b1ead854": {
			"balance": "7000000000000000000000"
		},
		"35a08081799173e001cc5bd46a02406dc95d1787": {
			"balance": "10000000000000000000000"
		},
		"21d13f0c4024e967d9470791b50f22de3afecf1b": {
			"balance": "4452210000000000000000"
		},
		"fdfd6134c04a8ab7eb16f00643f8fed7daaaecb2": {
			"balance": "400000000000000000000"
		},
)E" + R"E(
		"fd812bc69fb170ef57e2327e80affd14f8e4b6d2": {
			"balance": "2000000000000000000000"
		},
		"7148aef33261d8031fac3f7182ff35928daf54d9": {
			"balance": "4100000000000000000000"
		},
		"0b06390f2437b20ec4a3d3431b3279c6583e5ed7": {
			"balance": "194000000000000000000"
		},
		"4909b31998ead414b8fb0e846bd5cbde393935be": {
			"balance": "4000000000000000000000"
		},
		"b70dba9391682b4a364e77fe99256301a6c0bf1f": {
			"balance": "200000000000000000000"
		},
		"6b83bae7b565244558555bcf4ba8da2011891c17": {
			"balance": "2000000000000000000000"
		},
		"70a03549aa6168e97e88a508330a5a0bea74711a": {
			"balance": "1337000000000000000000"
		},
		"0fc9a0e34145fbfdd2c9d2a499b617d7a02969b9": {
			"balance": "180000000000000000000"
		},
		"2ddf40905769bcc426cb2c2938ffe077e1e89d98": {
			"balance": "3000000000000000000000"
		},
		"794b51c39e53d9e762b0613b829a44b472f4fff3": {
			"balance": "667965000000000000000"
		},
		"d062588171cf99bbeb58f126b870f9a3728d61ec": {
			"balance": "4500000000000000000000"
		},
		"8db185fe1b70a94a6a080e7e23a8bedc4acbf34b": {
			"balance": "1400000000000000000000"
		},
		"e73bfeada6f0fd016fbc843ebcf6e370a65be70c": {
			"balance": "1970000000000000000000"
		},
		"79ed10cf1f6db48206b50919b9b697081fbdaaf3": {
			"balance": "2000000000000000000000"
		},
		"276b0521b0e68b277df0bb32f3fd48326350bfb2": {
			"balance": "50000000000000000000"
		},
		"2e439348df8a4277b22a768457d1158e97c40904": {
			"balance": "776970000000000000000"
		},
		"6c25327f8dcbb2f45e561e86e35d8850e53ab059": {
			"balance": "1103200000000000000000"
		},
		"04d73896cf6593a691972a13a6e4871ff2c42b13": {
			"balance": "2000000000000000000000"
		},
		"b10fd2a647102f881f74c9fbc37da632949f2375": {
			"balance": "40000000000000000000"
		},
		"615f82365c5101f071e7d2cb6af14f7aad2c16c6": {
			"balance": "20000000000000000000"
		},
		"93aa8f92ebfff991fc055e906e651ac768d32bc8": {
			"balance": "940000000000000000000"
		},
		"0cbf8770f0d1082e5c20c5aead34e5fca9ae7ae2": {
			"balance": "1000000000000000000000"
		},
		"ffc9cc3094b041ad0e076f968a0de3b167255866": {
			"balance": "432400000000000000000"
		},
		"46531e8b1bde097fdf849d6d119885608a008df7": {
			"balance": "200000000000000000000"
		},
		"23cd2598a20e149ead2ad69379576ecedb60e38e": {
			"balance": "2000000000000000000000"
		},
		"85ca8bc6da2803d0725f5e1a456c89f9bc774e2f": {
			"balance": "600000000000000000000"
		},
		"c0725ec2bdc33a1d826071dea29d62d4385a8c25": {
			"balance": "40740000000000000000000"
		},
		"0e4765790352656bc656682c24fc5ef3e76a23c7": {
			"balance": "46610000000000000000"
		},
		"2ef9e465716acacfb8c8252fa8e7bc7969ebf6e4": {
			"balance": "2760000000000000000000"
		},
		"0ec5308b31282e218fc9e759d4fec5db3708cec4": {
			"balance": "1001000000000000000000"
		},
		"bf7701fc6225d5a17815438a8941d21ebc5d059d": {
			"balance": "1880000000000000000000"
		},
		"c489c83ffbb0252ac0dbe3521217630e0f491f14": {
			"balance": "4000000000000000000000"
		},
		"8eb51774af206b966b8909c45aa6722748802c0c": {
			"balance": "500000000000000000000"
		},
		"7b9226d46fe751940bc416a798b69ccf0dfab667": {
)E" + R"E(
			"balance": "4200000000000000000000"
		},
		"8f660f8b2e4c7cc2b4ac9c47ed28508d5f8f8650": {
			"balance": "20000000000000000000000"
		},
		"9f19fac8a32437d80ac6837a0bb7841729f4972e": {
			"balance": "650100000000000000000"
		},
		"201864a8f784c2277b0b7c9ee734f7b377eab648": {
			"balance": "4467000000000000000000"
		},
		"a6101c961e8e1c15798ffcd0e3201d7786ec373a": {
			"balance": "6000000000000000000000"
		},
		"d4ff46203efa23064b1caf00516e28704a82a4f8": {
			"balance": "1337000000000000000000"
		},
		"aa136b47962bb8b4fb540db4ccf5fdd042ffb8cf": {
			"balance": "500038000000000000000"
		},
		"704ae21d762d6e1dde28c235d13104597236db1a": {
			"balance": "2000000000000000000000"
		},
		"f17a92e0361dbacecdc5de0d1894955af6a9b606": {
			"balance": "2000000000000000000000"
		},
		"8b48e19d39dd35b66e6e1bb6b9c657cb2cf59d04": {
			"balance": "17844175000000000000000"
		},
		"9ad47fdcf9cd942d28effd5b84115b31a658a13e": {
			"balance": "3290000000000000000000"
		},
		"df0d08617bd252a911df8bd41a39b83ddf809673": {
			"balance": "10000000000000000000000"
		},
		"4c666b86f1c5ee8ca41285f5bde4f79052081406": {
			"balance": "500000000000000000000"
		},
		"88dec5bd3f4eba2d18b8aacefa7b721548c319ba": {
			"balance": "1370000000000000000000"
		},
		"9f9fe0c95f10fee87af1af207236c8f3614ef02f": {
			"balance": "6000000000000000000000"
		},
		"f7d0d310acea18406138baaabbfe0571e80de85f": {
			"balance": "1337000000000000000000"
		},
		"9569c63a9284a805626db3a32e9d236393476151": {
			"balance": "1970000000000000000000"
		},
		"5d5c2c1099bbeefb267e74b58880b444d94449e0": {
			"balance": "253574000000000000000"
		},
		"8c6ae7a05a1de57582ae2768204276c0ff47ed03": {
			"balance": "208000000000000000000000"
		},
		"432d884bd69db1acc0d89c64ade4cb4fc3a88b7a": {
			"balance": "2483000000000000000000"
		},
		"672cbca8440a8577097b19aff593a2ad9d28a756": {
			"balance": "80000000000000000000"
		},
		"19df9445a81c1b3d804aeaeb6f6e204e4236663f": {
			"balance": "37387000000000000000"
		},
		"1cb5f33b4d488936d13e3161da33a1da7df70d1b": {
			"balance": "200000000000000000000"
		},
		"df60f18c812a11ed4e2776e7a80ecf5e5305b3d6": {
			"balance": "900000000000000000000"
		},
		"c99a9cd6c9c1be3534eecd92ecc22f5c38e9515b": {
			"balance": "4821030000000000000000"
		},
		"00c40fe2095423509b9fd9b754323158af2310f3": {
			"balance": "0"
		},
		"da4a5f557f3bab390a92f49b9b900af30c46ae80": {
			"balance": "10000000000000000000000"
		},
		"f36df02fbd89607347afce2969b9c4236a58a506": {
			"balance": "2000000000000000000000"
		},
		"c549df83c6f65eec0f1dc9a0934a5c5f3a50fd88": {
			"balance": "2910000000000000000000"
		},
		"9f662e95274121f177566e636d23964cf1fd686f": {
			"balance": "2000000000000000000000"
		},
		"5a267331facb262daaecd9dd63a9700c5f5259df": {
			"balance": "100000000000000000000"
		},
		"117d9aa3c4d13bee12c7500f09f5dd1c66c46504": {
			"balance": "206000000000000000000"
		},
		"1b4d07acd38183a61bb2783d2b7b178dd502ac8d": {
			"balance": "200000000000000000000"
		},
		"3c0c3defac9cea7acc319a96c30b8e1fedab4574": {
			"balance": "1940000000000000000000"
)E" + R"E(
		},
		"e4dc22ed595bf0a337c01e03cc6be744255fc9e8": {
			"balance": "191000000000000000000"
		},
		"8f067c7c1bbd57780b7b9eeb9ec0032f90d0dcf9": {
			"balance": "20000000000000000000000"
		},
		"40e2440ae142c880366a12c6d4102f4b8434b62a": {
			"balance": "1000000000000000000000"
		},
		"f9ece022bccd2c92346911e79dd50303c01e0188": {
			"balance": "1000000000000000000000"
		},
		"f70328ef97625fe745faa49ee0f9d4aa3b0dfb69": {
			"balance": "1000000000000000000000"
		},
		"b6aacb8cb30bab2ae4a2424626e6e12b02d04605": {
			"balance": "8000000000000000000000"
		},
		"154459fa2f21318e3434449789d826cdc1570ce5": {
			"balance": "2000000000000000000000"
		},
		"684a44c069339d08e19a75668bdba303be855332": {
			"balance": "70000000000000000000000"
		},
		"9fe501aa57ead79278937cd6308c5cfa7a5629fe": {
			"balance": "50003000000000000000"
		},
		"3e45bd55db9060eced923bb9cb733cb3573fb531": {
			"balance": "1640000000000000000000"
		},
		"9c9f3b8a811b21f3ff3fe20fe970051ce66a824f": {
			"balance": "1157740000000000000000"
		},
		"e99aece90541cae224b87da673965e0aeb296afd": {
			"balance": "920000000000000000000"
		},
		"2f6dce1330c59ef921602154572d4d4bacbd048a": {
			"balance": "1000000000000000000000"
		},
		"6a6353b971589f18f2955cba28abe8acce6a5761": {
			"balance": "3000000000000000000000"
		},
		"98c10ebf2c4f97cba5a1ab3f2aafe1cac423f8cb": {
			"balance": "300000000000000000000"
		},
		"8077c3e4c445586e094ce102937fa05b737b568c": {
			"balance": "100000000000000000000"
		},
		"13371f92a56ea8381e43059a95128bdc4d43c5a6": {
			"balance": "1000000000000000000000"
		},
		"35a6885083c899dabbf530ed6c12f4dd3a204cf5": {
			"balance": "200000000000000000000"
		},
		"36b2c85e3aeeebb70d63c4a4730ce2e8e88a3624": {
			"balance": "10000000000000000000000"
		},
		"5ce44068b8f4a3fe799e6a8311dbfdeda29dee0e": {
			"balance": "2000000000000000000000"
		},
		"6fa6388d402b30afe59934c3b9e13d1186476018": {
			"balance": "670000000000000000000"
		},
		"8251358ca4e060ddb559ca58bc0bddbeb4070203": {
			"balance": "2000000000000000000000"
		},
		"17e86f3b5b30c0ba59f2b2e858425ba89f0a10b0": {
			"balance": "2000000000000000000000"
		},
		"298ec76b440d8807b3f78b5f90979bee42ed43db": {
			"balance": "30000000000000000000000"
		},
		"ce4b065dbcb23047203262fb48c1188364977470": {
			"balance": "500000000000000000000"
		},
		"c8e2adeb545e499d982c0c117363ceb489c5b11f": {
			"balance": "985000000000000000000"
		},
		"9928ff715afc3a2b60f8eb4cc4ba4ee8dab6e59d": {
			"balance": "440000000000000000000"
		},
		"c76130c73cb9210238025c9df95d0be54ac67fbe": {
			"balance": "1500000000000000000000"
		},
		"72d03d4dfab3500cf89b86866f15d4528e14a195": {
			"balance": "4488000000000000000000"
		},
		"d193e583d6070563e7b862b9614a47e99489f3e5": {
			"balance": "999972000000000000000"
		},
		"4df140ba796585dd5489315bca4bba680adbb818": {
			"balance": "2674000000000000000000"
		},
		"009eef0a0886056e3f69211853b9b7457f3782e4": {
			"balance": "3000512000000000000000"
		},
		"6e255b700ae7138a4bacf22888a9e2c00a285eec": {
			"balance": "4000000000000000000000"
		},
)E" + R"E(
		"aa47a4ffc979363232c99b99fada0f2734b0aeee": {
			"balance": "8121800000000000000000"
		},
		"9d069197d1de50045a186f5ec744ac40e8af91c6": {
			"balance": "2000000000000000000000"
		},
		"b514882c979bb642a80dd38754d5b8c8296d9a07": {
			"balance": "955000000000000000000"
		},
		"17c0478657e1d3d17aaa331dd429cecf91f8ae5d": {
			"balance": "999942000000000000000"
		},
		"5f9616c47b4a67f406b95a14fe6fc268396f1721": {
			"balance": "200000000000000000000"
		},
		"f70a998a717b338d1dd99854409b1a338deea4b0": {
			"balance": "2000000000000000000000"
		},
		"d1ee905957fe7cc70ec8f2868b43fe47b13febff": {
			"balance": "44000000000000000000"
		},
		"fc018a690ad6746dbe3acf9712ddca52b6250039": {
			"balance": "10000000000000000000000"
		},
		"5118557d600d05c2fcbf3806ffbd93d02025d730": {
			"balance": "11360000000000000000000"
		},
		"1ef5c9c73650cfbbde5c885531d427c7c3fe5544": {
			"balance": "6000000000000000000000"
		},
		"d1a396dcdab2c7494130b3fd307820340dfd8c1f": {
			"balance": "17952000000000000000"
		},
		"2d8e061892a5dcce21966ae1bb0788fd3e8ba059": {
			"balance": "250066000000000000000"
		},
		"8834b2453471f324fb26be5b25166b5b5726025d": {
			"balance": "573000000000000000000"
		},
		"14f221159518783bc4a706676fc4f3c5ee405829": {
			"balance": "200000000000000000000"
		},
		"c056d4bd6bf3cbacac65f8f5a0e3980b852740ae": {
			"balance": "100000000000000000000"
		},
		"560536794a9e2b0049d10233c41adc5f418a264a": {
			"balance": "1000000000000000000000"
		},
		"bc9e0ec6788f7df4c7fc210aacd220c27e45c910": {
			"balance": "500000000000000000000"
		},
		"54bcb8e7f73cda3d73f4d38b2d0847e600ba0df8": {
			"balance": "1078000000000000000000"
		},
		"4361d4846fafb377b6c0ee49a596a78ddf3516a3": {
			"balance": "3580000000000000000000"
		},
		"41c3c2367534d13ba2b33f185cdbe6ac43c2fa31": {
			"balance": "4000000000000000000000"
		},
		"5dc6f45fef26b06e3302313f884daf48e2746fb9": {
			"balance": "500000000000000000000"
		},
		"ad414d29cb7ee973fec54e22a388491786cf5402": {
			"balance": "14000000000000000000000"
		},
		"802dc3c4ff2d7d925ee2859f4a06d7ba60f1308c": {
			"balance": "98040000000000000000"
		},
		"2aed2ce531c056b0097efc3c6de10c4762004ed9": {
			"balance": "10430000000000000000000"
		},
		"39782ffe06ac78822a3c3a8afe305e50a56188ce": {
			"balance": "10000000000000000000000"
		},
		"ec73833de4b810bb027810fc8f69f544e83c12d1": {
			"balance": "1000000000000000000000"
		},
		"8d51a4cc62011322c696fd725b9fb8f53feaaa07": {
			"balance": "1000000000000000000000"
		},
		"29298ccbdff689f87fe41aa6e98fdfb53deaf37a": {
			"balance": "19800000000000000000000"
		},
		"827531a6c5817ae35f82b00b9754fcf74c55e232": {
			"balance": "3600000000000000000000"
		},
		"9c581a60b61028d934167929b22d70b313c34fd0": {
			"balance": "50000000000000000000000"
		},
		"0a077db13ffeb09484c217709d5886b8bf9c5a8b": {
			"balance": "4000000000000000000000"
		},
		"07b7a57033f8f11330e4665e185d234e83ec140b": {
			"balance": "4325683000000000000000"
		},
		"17f523f117bc9fe978aa481eb4f5561711371bc8": {
			"balance": "1999884000000000000000"
		},
		"de42fcd24ce4239383304367595f068f0c610740": {
)E" + R"E(
			"balance": "45120000000000000000"
		},
		"2a46d353777176ff8e83ffa8001f4f70f9733aa5": {
			"balance": "106000000000000000000"
		},
		"92e4392816e5f2ef5fb65837cec2c2325cc64922": {
			"balance": "10000000000000000000000"
		},
		"9a3da65023a13020d22145cfc18bab10bd19ce4e": {
			"balance": "456516000000000000000"
		},
		"1a085d43ec92414ea27b914fe767b6d46b1eef44": {
			"balance": "29550000000000000000000"
		},
		"3b2367f8494b5fe18d683c055d89999c9f3d1b34": {
			"balance": "10000000000000000000000"
		},
		"84244fc95a6957ed7c1504e49f30b8c35eca4b79": {
			"balance": "2000000000000000000000"
		},
		"5e031b0a724471d476f3bcd2eb078338bf67fbef": {
			"balance": "18200000000000000000"
		},
		"97e5cc6127c4f885be02f44b42d1c8b0ac91e493": {
			"balance": "200000000000000000000"
		},
		"eb1cea7b45d1bd4d0e2a007bd3bfb354759e2c16": {
			"balance": "198000000000000000000"
		},
		"72feaf124579523954645b7fafff0378d1c8242e": {
			"balance": "1000000000000000000000"
		},
		"8d07d42d831c2d7c838aa1872b3ad5d277176823": {
			"balance": "349200000000000000000"
		},
		"9637dc12723d9c78588542eab082664f3f038d9d": {
			"balance": "1000000000000000000000"
		},
		"e84b55b525f1039e744b918cb3332492e45eca7a": {
			"balance": "200000000000000000000"
		},
		"b1d6b01b94d854fe8b374aa65e895cf22aa2560e": {
			"balance": "940000000000000000000"
		},
		"8161d940c3760100b9080529f8a60325030f6edc": {
			"balance": "300000000000000000000"
		},
		"d30ee9a12b4d68abace6baca9ad7bf5cd1faf91c": {
			"balance": "1499936000000000000000"
		},
		"057949e1ca0570469e4ce3c690ae613a6b01c559": {
			"balance": "200000000000000000000"
		},
		"4bf8e26f4c2790da6533a2ac9abac3c69a199433": {
			"balance": "200000000000000000000"
		},
		"36fec62c2c425e219b18448ad757009d8c54026f": {
			"balance": "400000000000000000000"
		},
		"77bfe93ccda750847e41a1affee6b2da96e7214e": {
			"balance": "300000000000000000000"
		},
		"cc48414d2ac4d42a5962f29eee4497092f431352": {
			"balance": "161000000000000000000"
		},
		"ddbddd1bbd38ffade0305d30f02028d92e9f3aa8": {
			"balance": "2000000000000000000000"
		},
		"30c01142907acb1565f70438b9980ae731818738": {
			"balance": "2000000000000000000000"
		},
		"cffc49c1787eebb2b56cabe92404b636147d4558": {
			"balance": "5679305000000000000000"
		},
		"f99eeece39fa7ef5076d855061384009792cf2e0": {
			"balance": "500000000000000000000"
		},
		"e9b6a790009bc16642c8d820b7cde0e9fd16d8f5": {
			"balance": "3640000000000000000000"
		},
		"03b41b51f41df20dd279bae18c12775f77ad771c": {
			"balance": "1000000000000000000000"
		},
		"787d313fd36b053eeeaedbce74b9fb0678333289": {
			"balance": "27160000000000000000000"
		},
		"35d2970f49dcc81ea9ee707e9c8a0ab2a8bb7463": {
			"balance": "1440000000000000000000"
		},
		"4c0aca508b3caf5ee028bc707dd1e800b838f453": {
			"balance": "18200000000000000000"
		},
		"514632efbd642c04de6ca342315d40dd90a2dba6": {
			"balance": "2674000000000000000000"
		},
		"36810ff9d213a271eda2b8aa798be654fa4bbe06": {
			"balance": "2000000000000000000000"
		},
		"0c088006c64b30c4ddafbc36cb5f05469eb62834": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"568df31856699bb5acfc1fe1d680df9960ca4359": {
			"balance": "1379999000000000000000"
		},
		"d48e3f9357e303513841b3f84bda83fc89727587": {
			"balance": "1000000000000000000000"
		},
		"953ef652e7b769f53d6e786a58952fa93ee6abe7": {
			"balance": "2860000000000000000000"
		},
		"7c60a05f7a4a5f8cf2784391362e755a8341ef59": {
			"balance": "1892300000000000000000"
		},
		"7a6b26f438d9a352449155b8876cbd17c9d99b64": {
			"balance": "6000000000000000000000"
		},
		"68f719ae342bd7fef18a05cbb02f705ad38ed5b2": {
			"balance": "1050000000000000000000"
		},
		"45ca8d956608f9e00a2f9974028640888465668f": {
			"balance": "2000000000000000000000"
		},
		"3eaf316b87615d88f7adc77c58e712ed4d77966b": {
			"balance": "100141000000000000000"
		},
		"1f0412bfedcd964e837d092c71a5fcbaf30126e2": {
			"balance": "20000000000000000000"
		},
		"7471f72eeb300624eb282eab4d03723c649b1b58": {
			"balance": "8000000000000000000000"
		},
		"9bf71f7fb537ac54f4e514947fa7ff6728f16d2f": {
			"balance": "33400000000000000000"
		},
		"1098c774c20ca1daac5ddb620365316d353f109c": {
			"balance": "100000000000000000000"
		},
		"7dd8d7a1a34fa1f8e73ccb005fc2a03a15b8229c": {
			"balance": "200000000000000000000"
		},
		"0151fa5d17a2dce2d7f1eb39ef7fe2ad213d5d89": {
			"balance": "4000000000000000000000"
		},
		"ad6628352ed3390bafa86d923e56014cfcb360f4": {
			"balance": "2000000000000000000000"
		},
		"02af2459a93d0b3f4d062636236cd4b29e3bcecf": {
			"balance": "1910000000000000000000"
		},
		"ace2abb63b0604409fbde3e716d2876d44e8e5dd": {
			"balance": "152000000000000000000"
		},
		"e710dcd09b8101f9437bd97db90a73ef993d0bf4": {
			"balance": "386100000000000000000"
		},
		"d43ee438d83de9a37562bb4e286cb1bd19f4964d": {
			"balance": "1000000000000000000000"
		},
		"ea3779d14a13f6c78566bcde403591413a6239db": {
			"balance": "197000000000000000000000"
		},
		"6704f169e0d0b36b57bbc39f3c45437b5ee3d28d": {
			"balance": "394000000000000000000"
		},
		"5584423050e3c2051f0bbd8f44bd6dbc27ecb62c": {
			"balance": "3000000000000000000000"
		},
		"2f315d9016e8ee5f536681202f9084b032544d4d": {
			"balance": "1037400000000000000000"
		},
		"e1b63201fae1f129f95c7a116bd9dde5159c6cda": {
			"balance": "22837462000000000000000"
		},
		"2bbe62eac80ca7f4d6fdee7e7d8e28b63acf770e": {
			"balance": "2396000000000000000000"
		},
		"38da1ba2de9e2c954b092dd9d81204fd016ba016": {
			"balance": "10156000000000000000000"
		},
		"8a86e4a51c013b1fb4c76bcf30667c78d52eedef": {
			"balance": "2000000000000000000000"
		},
		"8f717ec1552f4c440084fba1154a81dc003ebdc0": {
			"balance": "10000000000000000000000"
		},
		"c760971bbc181c6a7cf77441f24247d19ce9b4cf": {
			"balance": "2000000000000000000000"
		},
		"7f150afb1a77c2b45928c268c1e9bdb4641d47d8": {
			"balance": "2000000000000000000000"
		},
		"1ea334b5750807ea74aac5ab8694ec5f28aa77cf": {
			"balance": "492500000000000000000"
		},
		"2afb058c3d31032b353bf24f09ae20d54de57dbe": {
			"balance": "1100000000000000000000"
		},
		"caef027b1ab504c73f41f2a10979b474f97e309f": {
			"balance": "200000000000000000000"
		},
)E" + R"E(
		"5dd112f368c0e6ceff77a9df02a5481651a02fb7": {
			"balance": "169800000000000000000"
		},
		"bd93e550403e2a06113ed4c3fba1a8913b19407e": {
			"balance": "2000000000000000000000"
		},
		"500c16352e901d48ba8d04e2c767121772790b02": {
			"balance": "30239000000000000000"
		},
		"d2a80327cbe55c4c7bd51ff9dde4ca648f9eb3f8": {
			"balance": "50000000000000000000"
		},
		"355ccfe0e77d557b971be1a558bc02df9eee0594": {
			"balance": "1759120000000000000000"
		},
		"5aed0e6cfe95f9d680c76472a81a2b680a7f93e2": {
			"balance": "197000000000000000000"
		},
		"f56442f60e21691395d0bffaa9194dcaff12e2b7": {
			"balance": "260000000000000000000"
		},
		"7db9eacc52e429dc83b461c5f4d86010e5383a28": {
			"balance": "1000000000000000000000"
		},
		"4b984ef26c576e815a2eaed2f5177f07dbb1c476": {
			"balance": "1560000000000000000000"
		},
		"9846648836a307a057184fd51f628a5f8c12427c": {
			"balance": "19100000000000000000000"
		},
		"4af0db077bb9ba5e443e21e148e59f379105c592": {
			"balance": "600000000000000000000"
		},
		"e96e2d3813efd1165f12f602f97f4a62909d3c66": {
			"balance": "2300000000000000000000"
		},
		"30e789b3d2465e946e6210fa5b35de4e8c93085f": {
			"balance": "2000000000000000000000"
		},
		"97f99b6ba31346cd98a9fe4c308f87c5a58c5151": {
			"balance": "6000000000000000000000"
		},
		"595e23d788a2d4bb85a15df7136d264a635511b3": {
			"balance": "3940000000000000000000"
		},
		"2f61efa5819d705f2b1e4ee754aeb8a819506a75": {
			"balance": "1460000000000000000000"
		},
		"3554947b7b947b0040da52ca180925c6d3b88ffe": {
			"balance": "66850000000000000000"
		},
		"8feffadb387a1547fb284da9b8147f3e7c6dc6da": {
			"balance": "837200000000000000000"
		},
		"258939bbf00c9de9af5338f5d714abf6d0c1c671": {
			"balance": "1550000000000000000000"
		},
		"5b333696e04cca1692e71986579c920d6b2916f9": {
			"balance": "500000000000000000000"
		},
		"5381448503c0c702542b1de7cc5fb5f6ab1cf6a5": {
			"balance": "8000000000000000000000"
		},
		"7e81f6449a03374191f3b7cb05d938b72e090dff": {
			"balance": "100000000000000000000"
		},
		"4ef1c214633ad9c0703b4e2374a2e33e3e429291": {
			"balance": "1337000000000000000000"
		},
		"fed8476d10d584b38bfa6737600ef19d35c41ed8": {
			"balance": "1820000000000000000000"
		},
		"1a95c9b7546b5d1786c3858fb1236446bc0ca4ce": {
			"balance": "1970000000000000000000"
		},
		"3b07db5a357f5af2484cbc9d77d73b1fd0519fc7": {
			"balance": "500000000000000000000"
		},
		"5f68a24c7eb4117667737b33393fb3c2148a53b6": {
			"balance": "51800000000000000000"
		},
		"d8f665fd8cd5c2bcc6ddc0a8ae521e4dc6aa6060": {
			"balance": "1700000000000000000000"
		},
		"d66acc0d11b689cea6d9ea5ff4014c224a5dc7c4": {
			"balance": "18200000000000000000"
		},
		"6e72b2a1186a8e2916543b1cb36a68870ea5d197": {
			"balance": "186000000000000000000"
		},
		"5102a4a42077e11c58df4773e3ac944623a66d9f": {
			"balance": "2000325000000000000000"
		},
		"72480bede81ad96423f2228b5c61be44fb523100": {
			"balance": "6400000000000000000000"
		},
		"e076db30ab486f79194ebbc45d8fab9a9242f654": {
			"balance": "4840000000000000000000"
		},
		"8ceea15eec3bdad8023f98ecf25b2b8fef27db29": {
)E" + R"E(
			"balance": "2000000000000000000000"
		},
		"40652360d6716dc55cf9aab21f3482f816cc2cbd": {
			"balance": "10000000000000000000000"
		},
		"13e02fb448d6c84ae17db310ad286d056160da95": {
			"balance": "2000000000000000000000"
		},
		"d6598b1386e93c5ccb9602ff4bbbecdbd3701dc4": {
			"balance": "224096000000000000000"
		},
		"d5ea472cb9466018110af00c37495b5c2c713112": {
			"balance": "4997800000000000000000"
		},
		"bb75cb5051a0b0944b4673ca752a97037f7c8c15": {
			"balance": "200000000000000000000"
		},
		"8af626a5f327d7506589eeb7010ff9c9446020d2": {
			"balance": "1400000000000000000000"
		},
		"318c76ecfd8af68d70555352e1f601e35988042d": {
			"balance": "501600000000000000000"
		},
		"5c3d19441d196cb443662020fcad7fbb79b29e78": {
			"balance": "14300000000000000000"
		},
		"27101a0f56d39a88c5a84f9b324cdde33e5cb68c": {
			"balance": "2000000000000000000000"
		},
		"e229e746a83f2ce253b0b03eb1472411b57e5700": {
			"balance": "5730000000000000000000"
		},
		"604cdf18628dbfa8329194d478dd5201eecc4be7": {
			"balance": "23000000000000000000"
		},
		"657473774f63ac3d6279fd0743d5790c4f161503": {
			"balance": "200000000000000000000"
		},
		"1ddefefd35ab8f658b2471e54790bc17af98dea4": {
			"balance": "1000000000000000000000"
		},
		"ac3900298dd14d7cc96d4abb428da1bae213ffed": {
			"balance": "24730250000000000000000"
		},
		"944f07b96f90c5f0d7c0c580533149f3f585a078": {
			"balance": "74000000000000000000"
		},
		"232c6d03b5b6e6711efff190e49c28eef36c82b0": {
			"balance": "1337000000000000000000"
		},
		"c87c77e3c24adecdcd1038a38b56e18dead3b702": {
			"balance": "8800000000000000000000"
		},
		"c4b6e5f09cc1b90df07803ce3d4d13766a9c46f4": {
			"balance": "6000000000000000000000"
		},
		"d44334b4e23a169a0c16bd21e866bba52d970587": {
			"balance": "2600000000000000000000"
		},
		"7757a4b9cc3d0247ccaaeb9909a0e56e1dd6dcc2": {
			"balance": "20000000000000000000"
		},
		"cf694081c76d18c64ca71382be5cd63b3cb476f8": {
			"balance": "1000000000000000000000"
		},
		"133e4f15e1e39c53435930aaedf3e0fe56fde843": {
			"balance": "20000000000000000000"
		},
		"f067fb10dfb293e998abe564c055e3348f9fbf1e": {
			"balance": "2000000000000000000000"
		},
		"94449c01b32a7fa55af8104f42cdd844aa8cbc40": {
			"balance": "16548000000000000000000"
		},
		"0e2094ac1654a46ba1c4d3a40bb8c17da7f39688": {
			"balance": "358000000000000000000"
		},
		"738ca94db7ce8be1c3056cd6988eb376359f3353": {
			"balance": "25500000000000000000000"
		},
		"0cfb172335b16c87d519cd1475530d20577f5e0e": {
			"balance": "100000000000000000000000"
		},
		"3cb561ce86424b359891e364ec925ffeff277df7": {
			"balance": "200000000000000000000"
		},
		"5f981039fcf50225e2adf762752112d1cc26b6e3": {
			"balance": "499954000000000000000"
		},
		"b43657a50eecbc3077e005d8f8d94f377876bad4": {
			"balance": "35460000000000000000"
		},
		"d07e511864b1cf9969e3560602829e32fc4e71f5": {
			"balance": "50000000000000000000"
		},
		"11306c7d57588637780fc9fde8e98ecb008f0164": {
			"balance": "1999944000000000000000"
		},
		"45ca9862003b4e40a3171fb5cafa9028cac8de19": {
			"balance": "13790000000000000000000"
)E" + R"E(
		},
		"231d94155dbcfe2a93a319b6171f63b20bd2b6fa": {
			"balance": "3819952000000000000000"
		},
		"e7533e270cc61fa164ac1553455c105d04887e14": {
			"balance": "121550000000000000000"
		},
		"070d5d364cb7bbf822fc2ca91a35bdd441b215d5": {
			"balance": "2000000000000000000000"
		},
		"d475477fa56390d33017518d6711027f05f28dbf": {
			"balance": "1975032000000000000000"
		},
		"cea34a4dd93dd9aefd399002a97d997a1b4b89cd": {
			"balance": "1500000000000000000000"
		},
		"560becdf52b71f3d8827d927610f1a980f33716f": {
			"balance": "429413000000000000000"
		},
		"f632adff490da4b72d1236d04b510f74d2faa3cd": {
			"balance": "1400000000000000000000"
		},
		"2fdd9b79df8df530ad63c20e62af431ae99216b8": {
			"balance": "21000000000000000000"
		},
		"535201a0a1d73422801f55ded4dfaee4fbaa6e3b": {
			"balance": "39641000000000000000"
		},
		"409d5a962edeeebea178018c0f38b9cdb213f289": {
			"balance": "20000000000000000000"
		},
		"9d911f3682f32fe0792e9fb6ff3cfc47f589fca5": {
			"balance": "4000000000000000000000"
		},
		"9f7a0392f857732e3004a375e6b1068d49d83031": {
			"balance": "2000000000000000000000"
		},
		"6a04f5d53fc0f515be942b8f12a9cb7ab0f39778": {
			"balance": "3129800000000000000000"
		},
		"be478e8e3dde6bd403bb2d1c657c4310ee192723": {
			"balance": "492500000000000000000"
		},
		"007622d84a234bb8b078230fcf84b67ae9a8acae": {
			"balance": "698800000000000000000"
		},
		"9475c510ec9a26979247744c3d8c3b0e0b5f44d3": {
			"balance": "10000000000000000000000"
		},
		"df47a8ef95f2f49f8e6f58184154145d11f72797": {
			"balance": "1910000000000000000000"
		},
		"13ce332dff65a6ab933897588aa23e000980fa82": {
			"balance": "258400000000000000000"
		},
		"9c4bbcd5f1644a6f075824ddfe85c571d6abf69c": {
			"balance": "1800000000000000000000"
		},
		"d42b20bd0311608b66f8a6d15b2a95e6de27c5bf": {
			"balance": "2000000000000000000000"
		},
		"a4dd59ab5e517d398e49fa537f899fed4c15e95d": {
			"balance": "20000000000000000000000"
		},
		"1a8a5ce414de9cd172937e37f2d59cff71ce57a0": {
			"balance": "10000000000000000000000"
		},
		"55c564664166a1edf3913e0169f1cd451fdb5d0c": {
			"balance": "2399800000000000000000"
		},
		"58ae2ddc5f4c8ada97e06c0086171767c423f5d7": {
			"balance": "1610000000000000000000"
		},
		"fb79abdb925c55b9f98efeef64cfc9eb61f51bb1": {
			"balance": "1794000000000000000000"
		},
		"e7a42f59fee074e4fb13ea9e57ecf1cc48282249": {
			"balance": "20000000000000000000000"
		},
		"07e2b4cdeed9d087b12e556d9e770c13c099615f": {
			"balance": "668500000000000000000"
		},
		"68473b7a7d965904bedba556dfbc17136cd5d434": {
			"balance": "100000000000000000000"
		},
		"6c5c3a54cda7c2f118edba434ed81e6ebb11dd7a": {
			"balance": "200000000000000000000"
		},
		"24c117d1d2b3a97ab11a4679c99a774a9eade8d1": {
			"balance": "1000000000000000000000"
		},
		"f68c5e33fa97139df5b2e63886ce34ebf3e4979c": {
			"balance": "3320000000000000000000"
		},
		"bd7419dc2a090a46e2873d7de6eaaad59e19c479": {
			"balance": "6802000000000000000000"
		},
		"1a0a1ddfb031e5c8cc1d46cf05842d50fddc7130": {
			"balance": "1000000000000000000000"
		},
)E" + R"E(
		"2b3a68db6b0cae8a7c7a476bdfcfbd6205e10687": {
			"balance": "2400000000000000000000"
		},
		"426d15f407a01135b13a6b72f8f2520b3531e302": {
			"balance": "20000000000000000000"
		},
		"0394b90fadb8604f86f43fc1e35d3124b32a5989": {
			"balance": "764000000000000000000"
		},
		"7412c9bc30b4df439f023100e63924066afd53af": {
			"balance": "500000000000000000000"
		},
		"80e7b3205230a566a1f061d922819bb4d4d2a0e1": {
			"balance": "14000000000000000000000"
		},
		"ff4fc66069046c525658c337a917f2d4b832b409": {
			"balance": "2000000000000000000000"
		},
		"f5061ee2e5ee26b815503677130e1de07a52db07": {
			"balance": "100000000000000000000"
		},
		"49793463e1681083d6abd6e725d5bba745dccde8": {
			"balance": "545974000000000000000"
		},
		"23551f56975fe92b31fa469c49ea66ee6662f41e": {
			"balance": "1910000000000000000000"
		},
		"fad96ab6ac768ad5099452ac4777bd1a47edc48f": {
			"balance": "100000000000000000000"
		},
		"2a746cd44027af3ebd37c378c85ef7f754ab5f28": {
			"balance": "394000000000000000000"
		},
		"b8d389e624a3a7aebce4d3e5dbdf6cdc29932aed": {
			"balance": "200000000000000000000"
		},
		"7b761feb7fcfa7ded1f0eb058f4a600bf3a708cb": {
			"balance": "4600000000000000000000"
		},
		"5435c6c1793317d32ce13bba4c4ffeb973b78adc": {
			"balance": "250070000000000000000"
		},
		"dd04eee74e0bf30c3f8d6c2c7f52e0519210df93": {
			"balance": "80000000000000000000"
		},
		"4331ab3747d35720a9d8ca25165cd285acd4bda8": {
			"balance": "2000000000000000000000"
		},
		"b84c8b9fd33ece00af9199f3cf5fe0cce28cd14a": {
			"balance": "3820000000000000000000"
		},
		"393f783b5cdb86221bf0294fb714959c7b45899c": {
			"balance": "5910000000000000000000"
		},
		"259ec4d265f3ab536b7c70fa97aca142692c13fc": {
			"balance": "20400000000000000000"
		},
		"5d2f7f0b04ba4be161e19cb6f112ce7a5e7d7fe4": {
			"balance": "35200000000000000000"
		},
		"d54ba2d85681dc130e5b9b02c4e8c851391fd9b9": {
			"balance": "3940000000000000000000"
		},
		"5cd8af60de65f24dc3ce5730ba92653022dc5963": {
			"balance": "1790000000000000000000"
		},
		"3b42a66d979f582834747a8b60428e9b4eeccd23": {
			"balance": "620400000000000000000"
		},
		"4b19eb0c354bc1393960eb06063b83926f0d67b2": {
			"balance": "29000000000000000000"
		},
		"8cf3546fd1cda33d58845fc8fcfecabca7c5642a": {
			"balance": "574027000000000000000"
		},
		"113612bc3ba0ee4898b49dd20233905f2f458f62": {
			"balance": "14000000000000000000000"
		},
		"1f2afc0aed11bfc71e77a907657b36ea76e3fb99": {
			"balance": "4000000000000000000000"
		},
		"03714b41d2a6f751008ef8dd4d2b29aecab8f36e": {
			"balance": "6000000000000000000000"
		},
		"25721c87b0dc21377c7200e524b14a22f0af69fb": {
			"balance": "4000000000000000000000"
		},
		"335858f749f169cabcfe52b796e3c11ec47ea3c2": {
			"balance": "200000000000000000000"
		},
		"52fb46ac5d00c3518b2c3a1c177d442f8165555f": {
			"balance": "1500000000000000000000"
		},
		"7a8c89c014509d56d7b68130668ff6a3ecec7370": {
			"balance": "300000000000000000000"
		},
		"7d5d2f73949dadda0856b206989df0078d51a1e5": {
			"balance": "10560000000000000000000"
		},
		"be538246dd4e6f0c20bf5ad1373c3b463a131e86": {
)E" + R"E(
			"balance": "200000000000000000000"
		},
		"62680a15f8ccb8bdc02f7360c25ad8cfb57b8ccd": {
			"balance": "1000000000000000000000"
		},
		"aa0ca3737337178a0caac3099c584b056c56301c": {
			"balance": "880000000000000000000"
		},
		"1d341fa5a3a1bd051f7db807b6db2fc7ba4f9b45": {
			"balance": "18200000000000000000"
		},
		"6463f715d594a1a4ace4bb9c3b288a74decf294d": {
			"balance": "1970000000000000000000"
		},
		"e00d153b10369143f97f54b8d4ca229eb3e8f324": {
			"balance": "152000000000000000000"
		},
		"8d0b9ea53fd263415eac11391f7ce9123c447062": {
			"balance": "2000000000000000000000"
		},
		"cacb675e0996235404efafbb2ecb8152271b55e0": {
			"balance": "700000000000000000000"
		},
		"b615e940143eb57f875893bc98a61b3d618c1e8c": {
			"balance": "20000000000000000000"
		},
		"606f177121f7855c21a5062330c8762264a97b31": {
			"balance": "4000000000000000000000"
		},
		"e3925509c8d0b2a6738c5f6a72f35314491248ce": {
			"balance": "1012961000000000000000"
		},
		"3f08d9ad894f813e8e2148c160d24b353a8e74b0": {
			"balance": "60000000000000000000000"
		},
		"40f4f4c06c732cd35b119b893b127e7d9d0771e4": {
			"balance": "10000000000000000000000"
		},
		"1406854d149e081ac09cb4ca560da463f3123059": {
			"balance": "1337000000000000000000"
		},
		"ecf05d07ea026e7ebf4941002335baf2fed0f002": {
			"balance": "200000000000000000000"
		},
		"9a990b8aeb588d7ee7ec2ed8c2e64f7382a9fee2": {
			"balance": "33518000000000000000"
		},
		"a2e0683a805de6a05edb2ffbb5e96f0570b637c3": {
			"balance": "20000000000000000000"
		},
		"fba5486d53c6e240494241abf87e43c7600d413a": {
			"balance": "1987592000000000000000"
		},
		"d81bd54ba2c44a6f6beb1561d68b80b5444e6dc6": {
			"balance": "1163806000000000000000"
		},
		"5298ab182a19359ffcecafd7d1b5fa212dede6dd": {
			"balance": "20000000000000000000"
		},
		"d1acb5adc1183973258d6b8524ffa28ffeb23de3": {
			"balance": "4000000000000000000000"
		},
		"4e7aa67e12183ef9d7468ea28ad239c2eef71b76": {
			"balance": "4925000000000000000000"
		},
		"509a20bc48e72be1cdaf9569c711e8648d957334": {
			"balance": "2000000000000000000000"
		},
		"949f84f0b1d7c4a7cf49ee7f8b2c4a134de32878": {
			"balance": "685000000000000000000"
		},
		"edbac9527b54d6df7ae2e000cca3613ba015cae3": {
			"balance": "1970000000000000000000"
		},
		"c697b70477cab42e2b8b266681f4ae7375bb2541": {
			"balance": "5577200000000000000000"
		},
		"86c934e38e53be3b33f274d0539cfca159a4d0d1": {
			"balance": "970000000000000000000"
		},
		"0877eeaeab78d5c00e83c32b2d98fa79ad51482f": {
			"balance": "439420000000000000000"
		},
		"5e11ecf69d551d7f4f84df128046b3a13240a328": {
			"balance": "20000000000000000000"
		},
		"43ff8853e98ed8406b95000ada848362d6a0392a": {
			"balance": "22100000000000000000000"
		},
		"f11cf5d363746fee6864d3ca336dd80679bb87ae": {
			"balance": "40000000000000000000000"
		},
		"fb223c1e22eac1269b32ee156a5385922ed36fb8": {
			"balance": "2000000000000000000000"
		},
		"4e6600806289454acda330a2a3556010dfacade6": {
			"balance": "6000000000000000000000"
		},
		"cfe2caaf3cec97061d0939748739bffe684ae91f": {
			"balance": "10000000000000000000000"
)E" + R"E(
		},
		"adeb52b604e5f77faaac88275b8d6b49e9f9f97f": {
			"balance": "2089268000000000000000"
		},
		"d53c567f0c3ff2e08b7d59e2b5c73485437fc58d": {
			"balance": "600000000000000000000"
		},
		"fbf75933e01b75b154ef0669076be87f62dffae1": {
			"balance": "78000000000000000000000"
		},
		"7dfd2962b575bcbeee97f49142d63c30ab009f66": {
			"balance": "4000000000000000000000"
		},
		"df6485c4297ac152b289b19dde32c77ec417f47d": {
			"balance": "1000000000000000000000"
		},
		"ffb974673367f5c07be5fd270dc4b7138b074d57": {
			"balance": "2470407000000000000000"
		},
		"f7d7af204c56f31fd94398e40df1964bd8bf123c": {
			"balance": "150011000000000000000"
		},
		"4506fe19fa4b006baa3984529d8516db2b2b50ab": {
			"balance": "2000000000000000000000"
		},
		"f4dc7ba85480bbb3f535c09568aaa3af6f3721c6": {
			"balance": "7214962000000000000000"
		},
		"d171c3f2258aef35e599c7da1aa07300234da9a6": {
			"balance": "2000000000000000000000"
		},
		"33581cee233088c0860d944e0cf1ceabb8261c2e": {
			"balance": "13370000000000000000"
		},
		"1c2e3607e127caca0fbd5c5948adad7dd830b285": {
			"balance": "19700000000000000000000"
		},
		"fd7ede8f5240a06541eb699d782c2f9afb2170f6": {
			"balance": "1337000000000000000000"
		},
		"368c5414b56b8455171fbf076220c1cba4b5ca31": {
			"balance": "557940000000000000000"
		},
		"3e8745ba322f5fd6cb50124ec46688c7a69a7fae": {
			"balance": "4925000000000000000000"
		},
		"76506eb4a780c951c74a06b03d3b8362f0999d71": {
			"balance": "500000000000000000000"
		},
		"96d62dfd46087f62409d93dd606188e70e381257": {
			"balance": "2000000000000000000000"
		},
		"37eada93c475ded2f7e15e7787d400470fa52062": {
			"balance": "200000000000000000000"
		},
		"26babf42b267fdcf3861fdd4236a5e474848b358": {
			"balance": "1000000000000000000000"
		},
		"3526eece1a6bdc3ee7b400fe935b48463f31bed7": {
			"balance": "82400000000000000000"
		},
		"27b62816e1e3b8d19b79d1513d5dfa855b0c3a2a": {
			"balance": "99941000000000000000"
		},
		"b3e3c439069880156600c2892e448d4136c92d9b": {
			"balance": "850000000000000000000"
		},
		"574ad9355390e4889ef42acd138b2a27e78c00ae": {
			"balance": "1557000000000000000000"
		},
		"f0b9d683cea12ba600baace219b0b3c97e8c00e4": {
			"balance": "100000000000000000000"
		},
		"a437fe6ec103ca8d158f63b334224eccac5b3ea3": {
			"balance": "8000000000000000000000"
		},
		"7a48d877b63a8f8f9383e9d01e53e80c528e955f": {
			"balance": "8000000000000000000000"
		},
		"e965daa34039f7f0df62375a37e5ab8a72b301e7": {
			"balance": "4796000000000000000000"
		},
		"72cd048a110574482983492dfb1bd27942a696ba": {
			"balance": "2000000000000000000000"
		},
		"6611ce59a98b072ae959dc49ad511daaaaa19d6b": {
			"balance": "200000000000000000000"
		},
		"0d92582fdba05eabc3e51538c56db8813785b328": {
			"balance": "191000000000000000000"
		},
		"e87e9bbfbbb71c1a740c74c723426df55d063dd9": {
			"balance": "7998000000000000000000"
		},
		"9c99a1da91d5920bc14e0cb914fdf62b94cb8358": {
			"balance": "20000000000000000000000"
		},
		"fe8e6e3665570dff7a1bda697aa589c0b4e9024a": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"811461a2b0ca90badac06a9ea16e787b33b196cc": {
			"balance": "164000000000000000000"
		},
		"d211b21f1b12b5096181590de07ef81a89537ead": {
			"balance": "2000000000000000000000"
		},
		"01155057002f6b0d18acb9388d3bc8129f8f7a20": {
			"balance": "1340000000000000000000"
		},
		"8ce22f9fa372449a420610b47ae0c8d565481232": {
			"balance": "2000000000000000000000"
		},
		"e02b74a47628be315b1f76b315054ad44ae9716f": {
			"balance": "4000000000000000000000"
		},
		"92a7c5a64362e9f842a23deca21035857f889800": {
			"balance": "1999944000000000000000"
		},
		"5213f459e078ad3ab95a0920239fcf1633dc04ca": {
			"balance": "2599989000000000000000"
		},
		"c9957ba94c1b29e5277ec36622704904c63dc023": {
			"balance": "1923000000000000000000"
		},
		"6ac40f532dfee5118117d2ad352da77d4f6da2c8": {
			"balance": "400000000000000000000"
		},
		"ea1efb3ce789bedec3d67c3e1b3bc0e9aa227f90": {
			"balance": "734000000000000000000"
		},
		"b01e389b28a31d8e4995bdd7d7c81beeab1e4119": {
			"balance": "1000000000000000000000"
		},
		"ee97aa8ac69edf7a987d6d70979f8ec1fbca7a94": {
			"balance": "376000000000000000000"
		},
		"0fad05507cdc8f24b2be4cb7fa5d927ddb911b88": {
			"balance": "3004447000000000000000"
		},
		"b6e8afd93dfa9af27f39b4df06076710bee3dfab": {
			"balance": "25000000000000000000"
		},
		"7d0b255efb57e10f7008aa22d40e9752dfcf0378": {
			"balance": "29944000000000000000"
		},
		"aef5b12258a18dec07d5ec2e316574919d79d6d6": {
			"balance": "2000000000000000000000"
		},
		"63666755bd41b5986997783c13043008242b3cb5": {
			"balance": "500000000000000000000"
		},
		"921f5261f4f612760706892625c75e7bce96b708": {
			"balance": "2000000000000000000000"
		},
		"10e1e3377885c42d7df218522ee7766887c05e6a": {
			"balance": "300031000000000000000"
		},
		"134163be9fbbe1c5696ee255e90b13254395c318": {
			"balance": "200000000000000000000"
		},
		"870f15e5df8b0eabd02569537a8ef93b56785c42": {
			"balance": "388000000000000000000"
		},
		"68eec1e288ac31b6eaba7e1fbd4f04ad579a6b5d": {
			"balance": "2000000000000000000000"
		},
		"1a2694ec07cf5e4d68ba40f3e7a14c53f3038c6e": {
			"balance": "1000073000000000000000"
		},
		"cd9b4cef73390c83a8fd71d7b540a7f9cf8b8c92": {
			"balance": "90000000000000000000"
		},
		"c8de7a564c7f4012a6f6d10fd08f47890fbf07d4": {
			"balance": "300000000000000000000"
		},
		"c0345b33f49ce27fe82cf7c84d141c68f590ce76": {
			"balance": "1000000000000000000000"
		},
		"fe53b94989d89964da2061539526bbe979dd2ea9": {
			"balance": "1930600000000000000000"
		},
		"14410fb310711be074a80883c635d0ef6afb2539": {
			"balance": "2000000000000000000000"
		},
		"1d344e962567cb27e44db9f2fac7b68df1c1e6f7": {
			"balance": "1940000000000000000000"
		},
		"fe016ec17ec5f10e3bb98ff4a1eda045157682ab": {
			"balance": "375804000000000000000"
		},
		"e89da96e06beaf6bd880b378f0680c43fd2e9d30": {
			"balance": "601400000000000000000"
		},
		"0fee81ac331efd8f81161c57382bb4507bb9ebec": {
			"balance": "400030000000000000000"
		},
		"40cf90ef5b768c5da585002ccbe6617650d8e837": {
			"balance": "999800000000000000000"
		},
		"256fa150cc87b5056a07d004efc84524739e62b5": {
)E" + R"E(
			"balance": "200000000000000000000"
		},
		"1b9b2dc2960e4cb9408f7405827c9b59071612fd": {
			"balance": "1000000000000000000000"
		},
		"0efd1789eb1244a3dede0f5de582d8963cb1f39f": {
			"balance": "1500000000000000000000"
		},
		"049c5d4bc6f25d4e456c697b52a07811ccd19fb1": {
			"balance": "300048000000000000000"
		},
		"02b7b1d6b34ce053a40eb65cd4a4f7dddd0e9f30": {
			"balance": "685000000000000000000"
		},
		"c1827686c0169485ec15b3a7c8c01517a2874de1": {
			"balance": "40000000000000000000"
		},
		"d8e5c9675ef4deed266b86956fc4590ea7d4a27d": {
			"balance": "1000000000000000000000"
		},
		"48f883e567b436a27bb5a3124dbc84dec775a800": {
			"balance": "771840000000000000000"
		},
		"a34076f84bd917f20f8342c98ba79e6fb08ecd31": {
			"balance": "4200000000000000000000"
		},
		"21ce6d5b9018cec04ad6967944bea39e8030b6b8": {
			"balance": "20000000000000000000"
		},
		"0596a27dc3ee115fce2f94b481bc207a9e261525": {
			"balance": "1000000000000000000000"
		},
		"717cf9beab3638308ded7e195e0c86132d163fed": {
			"balance": "15097428000000000000000"
		},
		"d5ce55d1b62f59433c2126bcec09bafc9dfaa514": {
			"balance": "197000000000000000000"
		},
		"7dd46da677e161825e12e80dc446f58276e1127c": {
			"balance": "820000000000000000000"
		},
		"98c5494a03ac91a768dffc0ea1dde0acbf889019": {
			"balance": "200000000000000000000000"
		},
		"617ff2cc803e31c9082233b825d025be3f7b1056": {
			"balance": "1970000000000000000000"
		},
		"1091176be19b9964a8f72e0ece6bf8e3cfad6e9c": {
			"balance": "10020000000000000000000"
		},
		"4ea56e1112641c038d0565a9c296c463afefc17e": {
			"balance": "182000000000000000000"
		},
		"e303167f3d4960fe881b32800a2b4aeff1b088d4": {
			"balance": "2000000000000000000000"
		},
		"773141127d8cf318aebf88365add3d5527d85b6a": {
			"balance": "1000076000000000000000"
		},
		"b916b1a01cdc4e56e7657715ea37e2a0f087d106": {
			"balance": "2406017000000000000000"
		},
		"46a430a2d4a894a0d8aa3feac615361415c3f81f": {
			"balance": "2000000000000000000000"
		},
		"e6a3010f0201bc94ff67a2f699dfc206f9e76742": {
			"balance": "879088000000000000000"
		},
		"d7ad09c6d32657685355b5c6ec8e9f57b4ebb982": {
			"balance": "1970000000000000000000"
		},
		"95e80a82c20cbe3d2060242cb92d735810d034a2": {
			"balance": "32511000000000000000"
		},
		"9a390162535e398877e416787d6239e0754e937c": {
			"balance": "1000000000000000000000"
		},
		"d85fdeaf2a61f95db902f9b5a53c9b8f9266c3ac": {
			"balance": "2010000000000000000000"
		},
		"c3e20c96df8d4e38f50b265a98a906d61bc51a71": {
			"balance": "2000000000000000000000"
		},
		"2949fd1def5c76a286b3872424809a07db3966f3": {
			"balance": "5236067000000000000000"
		},
		"86cdb7e51ac44772be3690f61d0e59766e8bfc18": {
			"balance": "4000000000000000000000"
		},
		"749a4a768b5f237248938a12c623847bd4e688dc": {
			"balance": "72000000000000000000"
		},
		"3524a000234ebaaf0789a134a2a417383ce5282a": {
			"balance": "5635000000000000000000"
		},
		"7b43c7eea8d62355b0a8a81da081c6446b33e9e0": {
			"balance": "4000000000000000000000"
		},
		"0eb189ef2c2d5762a963d6b7bdf9698ea8e7b48a": {
			"balance": "1337000000000000000000"
)E" + R"E(
		},
		"767fd7797d5169a05f7364321c19843a8c348e1e": {
			"balance": "18800000000000000000"
		},
		"1b2639588b55c344b023e8de5fd4087b1f040361": {
			"balance": "1500000000000000000000"
		},
		"1e33d1c2fb5e084f2f1d54bc5267727fec3f985d": {
			"balance": "500000000000000000000"
		},
		"06b106649aa8c421ddcd1b8c32cd0418cf30da1f": {
			"balance": "40000000000000000000000"
		},
		"3c5a241459c6abbf630239c98a30d20b8b3ac561": {
			"balance": "157600000000000000000"
		},
		"0f4f94b9191bb7bb556aaad7c74ddb288417a50b": {
			"balance": "1400000000000000000000"
		},
		"d6f4a7d04e8faf20e8c6eb859cf7f78dd23d7a15": {
			"balance": "131784000000000000000"
		},
		"61adf5929a5e2981684ea243baa01f7d1f5e148a": {
			"balance": "110302000000000000000"
		},
		"8f58d8348fc1dc4e0dd8343b6543c857045ee940": {
			"balance": "13632400000000000000000"
		},
		"a6e3baa38e104a1e27a4d82869afb1c0ae6eff8d": {
			"balance": "19690000000000000000"
		},
		"67350b5331926f5e28f3c1e986f96443809c8b8c": {
			"balance": "352000000000000000000"
		},
		"0b5d66b13c87b392e94d91d5f76c0d450a552843": {
			"balance": "2000000000000000000000"
		},
		"562a8dcbbeeef7b360685d27303bd69e094accf6": {
			"balance": "10000000000000000000000"
		},
		"b5d9934d7b292bcf603b2880741eb760288383a0": {
			"balance": "16700000000000000000"
		},
		"6fc53662371dca587b59850de78606e2359df383": {
			"balance": "180000000000000000000"
		},
		"e069c0173352b10bf6834719db5bed01adf97bbc": {
			"balance": "18894000000000000000"
		},
		"10a93457496f1108cd98e140a1ecdbae5e6de171": {
			"balance": "399600000000000000000"
		},
		"69ff8901b541763f817c5f2998f02dcfc1df2997": {
			"balance": "40000000000000000000"
		},
		"00c27d63fde24b92ee8a1e7ed5d26d8dc5c83b03": {
			"balance": "2000000000000000000000"
		},
		"77f81b1b26fc84d6de97ef8b9fbd72a33130cc4a": {
			"balance": "1000000000000000000000"
		},
		"6d20ef9704670a500bb269b5832e859802049f01": {
			"balance": "130000000000000000000"
		},
		"186afdc085f2a3dce4615edffbadf71a11780f50": {
			"balance": "200000000000000000000"
		},
		"7ff0c63f70241bece19b737e5341b12b109031d8": {
			"balance": "346000000000000000000"
		},
		"9d4174aa6af28476e229dadb46180808c67505c1": {
			"balance": "1219430000000000000000"
		},
		"5fec49c665e64ee89dd441ee74056e1f01e92870": {
			"balance": "6320000000000000000000"
		},
		"6cd228dc712169307fe27ceb7477b48cfc8272e5": {
			"balance": "77600000000000000000"
		},
		"fd918536a8efa6f6cefe1fa1153995fef5e33d3b": {
			"balance": "500000000000000000000"
		},
		"2fbb504a5dc527d3e3eb0085e2fc3c7dd538cb7a": {
			"balance": "1249961000000000000000"
		},
		"6ab323ae5056ed0a453072c5abe2e42fcf5d7139": {
			"balance": "880000000000000000000"
		},
		"67d682a282ef73fb8d6e9071e2614f47ab1d0f5e": {
			"balance": "1000000000000000000000"
		},
		"1858cf11aea79f5398ad2bb22267b5a3c952ea74": {
			"balance": "9850000000000000000000"
		},
		"39d6caca22bccd6a72f87ee7d6b59e0bde21d719": {
			"balance": "2002000000000000000000"
		},
		"daa63cbda45dd487a3f1cd4a746a01bb5e060b90": {
			"balance": "4797800000000000000000"
		},
)E" + R"E(
		"a90476e2efdfee4f387b0f32a50678b0efb573b5": {
			"balance": "10000000000000000000000"
		},
		"ae5aa1e6c2b60f6fd3efe721bb4a719cbe3d6f5d": {
			"balance": "795860000000000000000"
		},
		"ac2e766dac3f648f637ac6713fddb068e4a4f04d": {
			"balance": "197000000000000000000"
		},
		"6191ddc9b64a8e0890b4323709d7a07c48b92a64": {
			"balance": "775000000000000000000"
		},
		"cc4f0ff2aeb67d54ce3bc8c6510b9ae83e9d328b": {
			"balance": "400000000000000000000"
		},
		"ca23f62dff0d6460036c62e840aec5577e0befd2": {
			"balance": "140800000000000000000"
		},
		"97dc26ec670a31e0221d2a75bc5dc9f90c1f6fd4": {
			"balance": "50000000000000000000"
		},
		"848c994a79003fe7b7c26cc63212e1fc2f9c19eb": {
			"balance": "2000000000000000000000"
		},
		"20c284ba10a20830fc3d699ec97d2dfa27e1b95e": {
			"balance": "2000000000000000000000"
		},
		"4fa3f32ef4086448b344d5f0a9890d1ce4d617c3": {
			"balance": "1500000000000000000000"
		},
		"255abc8d08a096a88f3d6ab55fbc7352bddcb9ce": {
			"balance": "82161000000000000000"
		},
		"7c60e51f0be228e4d56fdd2992c814da7740c6bc": {
			"balance": "200000000000000000000"
		},
		"1c356cfdb95febb714633b28d5c132dd84a9b436": {
			"balance": "25000000000000000000"
		},
		"5062e5134c612f12694dbd0e131d4ce197d1b6a4": {
			"balance": "1000000000000000000000"
		},
		"ed862616fcbfb3becb7406f73c5cbff00c940755": {
			"balance": "1700000000000000000000"
		},
		"62c9b271ffd5b770a5eee4edc9787b5cdc709714": {
			"balance": "2000000000000000000000"
		},
		"3c925619c9b33144463f0537d896358706c520b0": {
			"balance": "2000000000000000000000"
		},
		"ffe2e28c3fb74749d7e780dc8a5d422538e6e451": {
			"balance": "253319000000000000000"
		},
		"37195a635dcc62f56a718049d47e8f9f96832891": {
			"balance": "1970000000000000000000"
		},
		"90e9a9a82edaa814c284d232b6e9ba90701d4952": {
			"balance": "100007000000000000000"
		},
		"e0c4ab9072b4e6e3654a49f8a8db026a4b3386a9": {
			"balance": "2000000000000000000000"
		},
		"439dee3f7679ff1030733f9340c096686b49390b": {
			"balance": "2000000000000000000000"
		},
		"548558d08cfcb101181dac1eb6094b4e1a896fa6": {
			"balance": "1999944000000000000000"
		},
		"3090f8130ec44466afadb36ed3c926133963677b": {
			"balance": "4000000000000000000000"
		},
		"d1648503b1ccc5b8be03fa1ec4f3ee267e6adf7b": {
			"balance": "5828000000000000000000"
		},
		"65b42faecc1edfb14283ca979af545f63b30e60c": {
			"balance": "18200000000000000000"
		},
		"6420f8bcc8164a6152a99d6b99693005ccf7e053": {
			"balance": "999972000000000000000"
		},
		"84b4b74e6623ba9d1583e0cfbe49643f16384149": {
			"balance": "20000000000000000000"
		},
		"b8310a16cc6abc465007694b930f978ece1930bd": {
			"balance": "740000000000000000000"
		},
		"16019a4dafab43f4d9bf4163fae0847d848afca2": {
			"balance": "25060000000000000000"
		},
		"479298a9de147e63a1c7d6d2fce089c7e64083bd": {
			"balance": "9999999000000000000000"
		},
		"030973807b2f426914ad00181270acd27b8ff61f": {
			"balance": "5348000000000000000000"
		},
		"b07bcf1cc5d4462e5124c965ecf0d70dc27aca75": {
			"balance": "1600000000000000000000"
		},
		"a2f798e077b07d86124e1407df32890dbb4b6379": {
)E" + R"E(
			"balance": "200000000000000000000"
		},
		"0cbd921dbe121563b98a6871fecb14f1cc7e88d7": {
			"balance": "200000000000000000000"
		},
		"6042276df2983fe2bc4759dc1943e18fdbc34f77": {
			"balance": "1970000000000000000000"
		},
		"be2b2280523768ea8ac35cd9e888d60a719300d4": {
			"balance": "2000000000000000000000"
		},
		"2f4da753430fc09e73acbccdcde9da647f2b5d37": {
			"balance": "200000000000000000000"
		},
		"734223d27ff23e5906caed22595701bb34830ca1": {
			"balance": "2000000000000000000000"
		},
		"5b430d779696a3653fc60e74fbcbacf6b9c2baf1": {
			"balance": "14000000000000000000000"
		},
		"84232107932b12e03186583525ce023a703ef8d9": {
			"balance": "2000000000000000000000"
		},
		"4ed14d81b60b23fb25054d8925dfa573dcae6168": {
			"balance": "340000000000000000000"
		},
		"8b338411f26ccf37658cc75521d77629099e467d": {
			"balance": "2000000000000000000000"
		},
		"a37622ac9bbdc4d82b75015d745b9f8de65a28ec": {
			"balance": "2910000000000000000000"
		},
		"1dd77441844afe9cc18f15d8c77bccfb655ee034": {
			"balance": "4850000000000000000000"
		},
		"65849be1af20100eb8a3ba5a5be4d3ae8db5a70e": {
			"balance": "400000000000000000000"
		},
		"d5586da4e59583c8d86cccf71a86197f17996749": {
			"balance": "2000000000000000000000"
		},
		"4b53ae59c784b6b5c43616b9a0809558e684e10c": {
			"balance": "1200000000000000000000"
		},
		"55d42eb495bf46a634997b5f2ea362814918e2b0": {
			"balance": "106128000000000000000"
		},
		"959ff17f1d51b473b44010052755a7fa8c75bd54": {
			"balance": "1970000000000000000000"
		},
		"5a2daab25c31a61a92a4c82c9925a1d2ef58585e": {
			"balance": "225400000000000000000"
		},
		"24c0c88b54a3544709828ab4ab06840559f6c5e2": {
			"balance": "2674000000000000000000"
		},
		"7e8649e690fc8c1bfda1b5e186581f649b50fe33": {
			"balance": "98500000000000000000"
		},
		"4acfa9d94eda6625c9dfa5f9f4f5d107c4031fdf": {
			"balance": "39400000000000000000"
		},
		"5778ffdc9b94c5a59e224eb965b6de90f222d170": {
			"balance": "335320000000000000000"
		},
		"825a7f4e10949cb6f8964268f1fa5f57e712b4c4": {
			"balance": "20000000000000000000"
		},
		"6f39cc37caaa2ddc9b610f6131e0619fae772a3c": {
			"balance": "500000000000000000000"
		},
		"5b437365ae3a9a2ff97c68e6f90a7620188c7d19": {
			"balance": "2002000000000000000000"
		},
		"6710c2c03c65992b2e774be52d3ab4a6ba217ef7": {
			"balance": "11600000000000000000000"
		},
		"896e335ca47af57962fa0f4dbf3e45e688cba584": {
			"balance": "1368500000000000000000"
		},
		"b57549bfbc9bdd18f736b22650e48a73601fa65c": {
			"balance": "446000000000000000000"
		},
		"85ca1e727e9d1a87991cc2c41840ebb9edf21d1b": {
			"balance": "13370000000000000000"
		},
		"cf4166746e1d3bc1f8d0714b01f17e8a62df1464": {
			"balance": "1004700000000000000000"
		},
		"4a75c3d4fa6fccbd5dd5a703c15379a1e783e9b7": {
			"balance": "1820000000000000000000"
		},
		"9e5811b40be1e2a1e1d28c3b0774acde0a09603d": {
			"balance": "3000000000000000000000"
		},
		"763886e333c56feff85be3951ab0b889ce262e95": {
			"balance": "2000000000000000000000"
		},
		"2b101e822cd962962a06800a2c08d3b15d82b735": {
			"balance": "152000000000000000000"
)E" + R"E(
		},
		"a01e9476df84431825c836e8803a97e22fa5a0cd": {
			"balance": "6000000000000000000000"
		},
		"be4e7d983f2e2a636b1102ec7039efebc842e98d": {
			"balance": "66000000000000000000"
		},
		"9e427272516b3e67d4fcbf82f59390d04c8e28e5": {
			"balance": "4000000000000000000000"
		},
		"e0d231e144ec9107386c7c9b02f1702ceaa4f700": {
			"balance": "5000057000000000000000"
		},
		"6a0f056066c2d56628850273d7ecb7f8e6e9129e": {
			"balance": "5000016000000000000000"
		},
		"d1538e9a87e59ca9ec8e5826a5b793f99f96c4c3": {
			"balance": "1000000000000000000000"
		},
		"f85bab1cb3710fc05fa19ffac22e67521a0ba21d": {
			"balance": "2003000000000000000000"
		},
		"f7cbdba6be6cfe68dbc23c2b0ff530ee05226f84": {
			"balance": "20000000000000000000"
		},
		"4eb87ba8788eba0df87e5b9bd50a8e45368091c1": {
			"balance": "20000000000000000000"
		},
		"1479a9ec7480b74b5db8fc499be352da7f84ee9c": {
			"balance": "1000000000000000000000"
		},
		"d311bcd7aa4e9b4f383ff3d0d6b6e07e21e3705d": {
			"balance": "200000000000000000000"
		},
		"425c1816868f7777cc2ba6c6d28c9e1e796c52b3": {
			"balance": "10000000000000000000000"
		},
		"8510ee934f0cbc900e1007eb38a21e2a5101b8b2": {
			"balance": "106000000000000000000"
		},
		"01e864d354741b423e6f42851724468c74f5aa9c": {
			"balance": "20000000000000000000000"
		},
		"a543a066fb32a8668aa0736a0c9cd40d78098727": {
			"balance": "1000000000000000000000"
		},
		"f3eb1948b951e22df1617829bf3b8d8680ec6b68": {
			"balance": "4000000000000000000000"
		},
		"f6b782f4dcd745a6c0e2e030600e04a24b25e542": {
			"balance": "400000000000000000000"
		},
		"229f4f1a2a4f540774505b4707a81de44410255b": {
			"balance": "2000000000000000000000"
		},
		"cff8d06b00e3f50c191099ad56ba6ae26571cd88": {
			"balance": "1000000000000000000000"
		},
		"910b7d577a7e39aa23acf62ad7f1ef342934b968": {
			"balance": "10000000000000000000000"
		},
		"392433d2ce83d3fb4a7602cca3faca4ec140a4b0": {
			"balance": "51000000000000000000"
		},
		"8ff46045687723dc33e4d099a06904f1ebb584dc": {
			"balance": "2000000000000000000000"
		},
		"9ca0429f874f8dcee2e9c062a9020a842a587ab9": {
			"balance": "2000000000000000000000"
		},
		"160ceb6f980e04315f53c4fc988b2bf69e284d7d": {
			"balance": "19100000000000000000"
		},
		"c340f9b91c26728c31d121d5d6fc3bb56d3d8624": {
			"balance": "2000000000000000000000"
		},
		"afa1d5ad38fed44759c05b8993c1aa0dace19f40": {
			"balance": "80000000000000000000"
		},
		"3969b4f71bb8751ede43c016363a7a614f76118e": {
			"balance": "2000000000000000000000"
		},
		"2bb6f578adfbe7b2a116b3554facf9969813c319": {
			"balance": "7400000000000000000000"
		},
		"8334764b7b397a4e578f50364d60ce44899bff94": {
			"balance": "92500000000000000000"
		},
		"9dd2196624a1ddf14a9d375e5f07152baf22afa2": {
			"balance": "1211747000000000000000"
		},
		"f242da845d42d4bf779a00f295b40750fe49ea13": {
			"balance": "1000000000000000000000"
		},
		"c6234657a807384126f8968ca1708bb07baa493c": {
			"balance": "20000000000000000000"
		},
		"94c055e858357aaa30cf2041fa9059ce164a1f91": {
			"balance": "19999000000000000000000"
		},
)E" + R"E(
		"74c73c90528a157336f1e7ea20620ae53fd24728": {
			"balance": "8969310000000000000000"
		},
		"19e7f3eb7bf67f3599209ebe08b62ad3327f8cde": {
			"balance": "2000000000000000000000"
		},
		"b2b516fdd19e7f3864b6d2cf1b252a4156f1b03b": {
			"balance": "53720000000000000000"
		},
		"8164e78314ae16b28926cc553d2ccb16f356270d": {
			"balance": "8450000000000000000000"
		},
		"4d828894752f6f25175daf2177094487954b6f9f": {
			"balance": "1459683000000000000000"
		},
		"ab84a0f147ad265400002b85029a41fc9ce57f85": {
			"balance": "1000000000000000000000"
		},
		"f3fe51fde34413c73318b9c85437fe7e820f561a": {
			"balance": "1003200000000000000000"
		},
		"16c7b31e8c376282ac2271728c31c95e35d952c3": {
			"balance": "2000000000000000000000"
		},
		"80d5c40c59c7f54ea3a55fcfd175471ea35099b3": {
			"balance": "1000000000000000000000"
		},
		"7abb10f5bd9bc33b8ec1a82d64b55b6b18777541": {
			"balance": "20000000000000000000000"
		},
		"095b0ea2b218d82e0aea7c2889238a39c9bf9077": {
			"balance": "20000000000000000000000"
		},
		"5d5cdbe25b2a044b7b9be383bcaa5807b06d3c6b": {
			"balance": "2000000000000000000000"
		},
		"323749a3b971959e46c8b4822dcafaf7aaf9bd6e": {
			"balance": "20064000000000000000"
		},
		"e0272213e8d2fd3e96bd6217b24b4ba01b617079": {
			"balance": "20000000000000000000"
		},
		"00acbfb2f25a5485c739ef70a44eeeeb7c65a66f": {
			"balance": "100000000000000000000"
		},
		"52f15423323c24f19ae2ab673717229d3f747d9b": {
			"balance": "1026115000000000000000"
		},
		"cb4abfc282aed76e5d57affda542c1f382fcacf4": {
			"balance": "8136100000000000000000"
		},
		"f71b4534f286e43093b1e15efea749e7597b8b57": {
			"balance": "104410000000000000000000"
		},
		"44cd77535a893fa7c4d5eb3a240e79d099a72d2d": {
			"balance": "820000000000000000000"
		},
		"eb3ce7fc381c51db7d5fbd692f8f9e058a4c703d": {
			"balance": "200000000000000000000"
		},
		"f1c8c4a941b4628c0d6c30fda56452d99c7e1b64": {
			"balance": "1449000000000000000000"
		},
		"277677aba1e52c3b53bfa2071d4e859a0af7e8e1": {
			"balance": "1000000000000000000000"
		},
		"a5f075fd401335577b6683c281e6d101432dc6e0": {
			"balance": "2680000000000000000000"
		},
		"e28dbc8efd5e416a762ec0e018864bb9aa83287b": {
			"balance": "24533161000000000000000"
		},
		"2b717cd432a323a4659039848d3b87de26fc9546": {
			"balance": "500000000000000000000000"
		},
		"b358e97c70b605b1d7d729dfb640b43c5eafd1e7": {
			"balance": "20000000000000000000000"
		},
		"293c2306df3604ae4fda0d207aba736f67de0792": {
			"balance": "200000000000000000000"
		},
		"74d366b07b2f56477d7c7077ac6fe497e0eb6559": {
			"balance": "5000000000000000000000"
		},
		"490145afa8b54522bb21f352f06da5a788fa8f1d": {
			"balance": "9231182000000000000000"
		},
		"862569211e8c6327b5415e3a67e5738b15baaf6e": {
			"balance": "140000000000000000000"
		},
		"5a74ba62e7c81a3474e27d894fed33dd24ad95fe": {
			"balance": "18200000000000000000"
		},
		"536e4d8029b73f5579dca33e70b24eba89e11d7e": {
			"balance": "1970000000000000000000"
		},
		"25c6e74ff1d928df98137af4df8430df24f07cd7": {
			"balance": "390000000000000000000"
		},
		"19b36b0c87ea664ed80318dc77b688dde87d95a5": {
)E" + R"E(
			"balance": "1948386000000000000000"
		},
		"abc4caeb474d4627cb6eb456ecba0ecd08ed8ae1": {
			"balance": "3940000000000000000000"
		},
		"8ea656e71ec651bfa17c5a5759d86031cc359977": {
			"balance": "100000000000000000000"
		},
		"8d620bde17228f6cbba74df6be87264d985cc179": {
			"balance": "100000000000000000000"
		},
		"b2aa2f1f8e93e79713d92cea9ffce9a40af9c82d": {
			"balance": "2000000000000000000000"
		},
		"198ef1ec325a96cc354c7266a038be8b5c558f67": {
			"balance": "608334724000000000000000"
		},
		"6a13d5e32c1fd26d7e91ff6e053160a89b2c8aad": {
			"balance": "53480000000000000000"
		},
		"e056bf3ff41c26256fef51716612b9d39ade999c": {
			"balance": "100009000000000000000"
		},
		"2c128c95d957215101f043dd8fc582456d41016d": {
			"balance": "835000000000000000000"
		},
		"2560b09b89a4ae6849ed5a3c9958426631714466": {
			"balance": "1700000000000000000000"
		},
		"d3d6e9fb82542fd29ed9ea3609891e151396b6f7": {
			"balance": "54000000000000000000000"
		},
		"a7607b42573bb6f6b4d4f23c7e2a26b3a0f6b6f0": {
			"balance": "1610000000000000000000"
		},
		"020362c3ade878ca90d6b2d889a4cc5510eed5f3": {
			"balance": "1042883000000000000000"
		},
		"14830704e99aaad5c55e1f502b27b22c12c91933": {
			"balance": "620000000000000000000"
		},
		"8030b111c6983f0485ddaca76224c6180634789f": {
			"balance": "80000000000000000000"
		},
		"2c5b7d7b195a371bf9abddb42fe04f2f1d9a9910": {
			"balance": "200000000000000000000"
		},
		"77d43fa7b481dbf3db530cfbf5fdced0e6571831": {
			"balance": "2000000000000000000000"
		},
		"2d90b415a38e2e19cdd02ff3ad81a97af7cbf672": {
			"balance": "109800000000000000000"
		},
		"2fc82ef076932341264f617a0c80dd571e6ae939": {
			"balance": "7160000000000000000000"
		},
		"dfe549fe8430e552c6d07cc3b92ccd43b12fb50f": {
			"balance": "83620000000000000000"
		},
		"1e8e689b02917cdc29245d0c9c68b094b41a9ed6": {
			"balance": "2000000000000000000000"
		},
		"21c3a8bba267c8cca27b1a9afabad86f607af708": {
			"balance": "8940000000000000000000"
		},
		"143c639752caeecf6a997d39709fc8f19878c7e8": {
			"balance": "1970000000000000000000"
		},
		"02603d7a3bb297c67c877e5d34fbd5b913d4c63a": {
			"balance": "20000000000000000000"
		},
		"a166f911c644ac3213d29e0e1ae010f794d5ad26": {
			"balance": "2000000000000000000000"
		},
		"6eb3819617404058268f0c3cff3596bfe9148c1c": {
			"balance": "1670000000000000000000"
		},
		"7a67dd043a504fc2f2fc7194e9becf484cecb1fb": {
			"balance": "250000000000000000000"
		},
		"f824ee331e4ac3cc587693395b57ecf625a6c0c2": {
			"balance": "1600930000000000000000"
		},
		"1179c60dbd068b150b074da4be23033b20c68558": {
			"balance": "680000000000000000000"
		},
		"d2a479404347c5543aab292ae1bb4a6f158357fa": {
			"balance": "4000000000000000000000"
		},
		"b0d32bd7e4e695b7b01aa3d0416f80557dba9903": {
			"balance": "16300000000000000000000"
		},
		"f734ec03724ddee5bb5279aa1afcf61b0cb448a1": {
			"balance": "4238080000000000000000"
		},
		"c04069dfb18b096c7867f8bee77a6dc7477ad062": {
			"balance": "2674000000000000000000"
		},
		"80c53ee7e3357f94ce0d7868009c208b4a130125": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"0f32d9cb4d0fdaa0150656bb608dcc43ed7d9301": {
			"balance": "753978000000000000000"
		},
		"6ddb6092779d5842ead378e21e8120fd4c6bc132": {
			"balance": "2000000000000000000000"
		},
		"82ea01e3bf2e83836e71704e22a2719377efd9c3": {
			"balance": "3040000000000000000000"
		},
		"44c1110b18870ec81178d93d215838c551d48e64": {
			"balance": "199958000000000000000"
		},
		"7727af101f0aaba4d23a1cafe17c6eb5dab1c6dc": {
			"balance": "2000000000000000000000"
		},
		"a11a03c4bb26d21eff677d5d555c80b25453ee7a": {
			"balance": "69979000000000000000"
		},
		"19e5dea3370a2c746aae34a37c531f41da264e83": {
			"balance": "200000000000000000000"
		},
		"c325c352801ba883b3226c5feb0df9eae2d6e653": {
			"balance": "3940000000000000000000"
		},
		"ae5055814cb8be0c117bb8b1c8d2b63b4698b728": {
			"balance": "32035000000000000000"
		},
		"deb1bc34d86d4a4dde2580d8beaf074eb0e1a244": {
			"balance": "1580000000000000000000"
		},
		"558360206883dd1b6d4a59639e5629d0f0c675d0": {
			"balance": "2000000000000000000000"
		},
		"a9d6f871ca781a759a20ac3adb972cf12829a208": {
			"balance": "925000000000000000000"
		},
		"b0ac4eff6680ee14169cdadbffdb30804f6d25f5": {
			"balance": "2000000000000000000000"
		},
		"f1b58faffa8794f50af8e88309c7a6265455d51a": {
			"balance": "999800000000000000000"
		},
		"a61a54df784a44d71b771b87317509211381f200": {
			"balance": "1000000000000000000000"
		},
		"baa4b64c2b15b79f5f204246fd70bcbd86e4a92a": {
			"balance": "500000000000000000000"
		},
		"a20d8ff60caae31d02e0b665fa435d76f77c9442": {
			"balance": "489600000000000000000"
		},
		"f3e74f470c7d3a3f0033780f76a89f3ef691e6cb": {
			"balance": "3021800000000000000000"
		},
		"d330728131fe8e3a15487a34573c93457e2afe95": {
			"balance": "4000000000000000000000"
		},
		"9af9dbe47422d177f945bdead7e6d82930356230": {
			"balance": "3940000000000000000000"
		},
		"0eb5b662a1c718608fd52f0c25f9378830178519": {
			"balance": "6091400000000000000000"
		},
		"fda6810ea5ac985d6ffbf1c511f1c142edcfddf7": {
			"balance": "4000000000000000000000"
		},
		"832c54176bdf43d2c9bcd7b808b89556b89cbf31": {
			"balance": "200000000000000000000"
		},
		"704d5de4846d39b53cd21d1c49f096db5c19ba29": {
			"balance": "152000000000000000000"
		},
		"344a8db086faed4efc37131b3a22b0782dad7095": {
			"balance": "500000000000000000000"
		},
		"8c7fa5cae82fedb69ab189d3ff27ae209293fb93": {
			"balance": "400030000000000000000"
		},
		"ad660dec825522a9f62fcec3c5b731980dc286ea": {
			"balance": "3000000000000000000000"
		},
		"13b9b10715714c09cfd610cf9c9846051cb1d513": {
			"balance": "1970000000000000000000"
		},
		"40467d80e74c35407b7db51789234615fea66818": {
			"balance": "388000000000000000000"
		},
		"30e9d5a0088f1ddb2fd380e2a049192266c51cbf": {
			"balance": "196910000000000000000"
		},
		"b2d1e99af91231858e7065dd1918330dc4c747d5": {
			"balance": "16700000000000000000000"
		},
		"9f21302ca5096bea7402b91b0fd506254f999a3d": {
			"balance": "1246832000000000000000"
		},
		"d24b6644f439c8051dfc64d381b8c86c75c17538": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"8228ebc087480fd64547ca281f5eace3041453b9": {
			"balance": "1970000000000000000000"
		},
		"29da3e35b23bb1f72f8e2258cf7f553359d24bac": {
			"balance": "20000000000000000000000"
		},
		"c8e558a3c5697e6fb23a2594c880b7a1b68f9860": {
			"balance": "10000000000000000000000"
		},
		"6b951a43274eeafc8a0903b0af2ec92bf1efc839": {
			"balance": "100000000000000000000"
		},
		"d015f6fcb84df7bb410e8c8f04894a881dcac237": {
			"balance": "1038000000000000000000"
		},
		"6ccb03acf7f53ce87aadcc21a9932de915f89804": {
			"balance": "8000000000000000000000"
		},
		"388c85a9b9207d8146033fe38143f6d34b595c47": {
			"balance": "200000000000000000000"
		},
		"429c06b487e8546abdfc958a25a3f0fba53f6f00": {
			"balance": "13503000000000000000"
		},
		"771507aeee6a255dc2cd9df55154062d0897b297": {
			"balance": "334250000000000000000"
		},
		"5a2b1c853aeb28c45539af76a00ac2d8a8242896": {
			"balance": "25000000000000000000"
		},
		"f4d67a9044b435b66e8977ff39a28dc4bd53729a": {
			"balance": "200000000000000000000"
		},
		"063759dd1c4e362eb19398951ff9f8fad1d31068": {
			"balance": "10000000000000000000000"
		},
		"cb58990bcd90cfbf6d8f0986f6fa600276b94e2d": {
			"balance": "999925000000000000000"
		},
		"6df5c84f7b909aab3e61fe0ecb1b3bf260222ad2": {
			"balance": "4000000000000000000000"
		},
		"deb2495d6aca7b2a6a2d138b6e1a42e2dc311fdd": {
			"balance": "2000000000000000000000"
		},
		"59203cc37599b648312a7cc9e06dacb589a9ae6a": {
			"balance": "148689000000000000000"
		},
		"fc9b347464b2f9929d807e039dae48d3d98de379": {
			"balance": "14000000000000000000000"
		},
		"48d2434b7a7dbbff08223b6387b05da2e5093126": {
			"balance": "18000000000000000000000"
		},
		"c9d76446d5aadff80b68b91b08cd9bc8f5551ac1": {
			"balance": "714000000000000000000"
		},
		"3d31587b5fd5869845788725a663290a49d3678c": {
			"balance": "500000000000000000000"
		},
		"d8715ef9176f850b2e30eb8e382707f777a6fbe9": {
			"balance": "2000000000000000000000"
		},
		"2c2147947ae33fb098b489a5c16bfff9abcd4e2a": {
			"balance": "200000000000000000000"
		},
		"d6c0d0bc93a62e257174700e10f024c8b23f1f87": {
			"balance": "2000000000000000000000"
		},
		"d1978f2e34407fab1dc2183d95cfda6260b35982": {
			"balance": "788000000000000000000"
		},
		"1bf974d9904f45ce81a845e11ef4cbcf27af719e": {
			"balance": "100000000000000000000"
		},
		"6e761eaa0f345f777b5441b73a0fa5b56b85f22d": {
			"balance": "2000000000000000000000"
		},
		"ea60436912de6bf187d3a472ff8f5333a0f7ed06": {
			"balance": "19700000000000000000"
		},
		"94f8f057db7e60e675ad940f155885d1a477348e": {
			"balance": "401100000000000000000"
		},
		"8933491760c8f0b4df8caac78ed835caee21046d": {
			"balance": "20000000000000000000000"
		},
		"a7775e4af6a23afa201fb78b915e51a515b7a728": {
			"balance": "120000000000000000000"
		},
		"d8d64384249b776794063b569878d5e3b530a4b2": {
			"balance": "177569000000000000000"
		},
		"be633a3737f68439bac7c90a52142058ee8e8a6f": {
			"balance": "960000000000000000000"
		},
		"90bd62a050845261fa4a9f7cf241ea630b05efb8": {
			"balance": "500000000000000000000"
		},
		"552987f0651b915b2e1e5328c121960d4bdd6af4": {
)E" + R"E(
			"balance": "1790000000000000000000"
		},
		"0baf6ecdb91acb3606a8357c0bc4f45cfd2d7e6f": {
			"balance": "1000000000000000000000"
		},
		"9e5a311d9f69898a7c6a9d6360680438e67a7b2f": {
			"balance": "1490000000000000000000"
		},
		"78859c5b548b700d9284cee4b6633c2f52e529c2": {
			"balance": "2955000000000000000000"
		},
		"d572309169b1402ec8131a17a6aac3222f89e6eb": {
			"balance": "13800000000000000000000"
		},
		"8e6d7485cbe990acc1ad0ee9e8ccf39c0c93440e": {
			"balance": "955000000000000000000"
		},
		"75c11d024d12ae486c1095b7a7b9c4af3e8edeb9": {
			"balance": "20000000000000000000"
		},
		"903413878aea3bc1086309a3fe768b65559e8cab": {
			"balance": "8000000000000000000000"
		},
		"6d0569e5558fc7df2766f2ba15dc8aeffc5beb75": {
			"balance": "4001070000000000000000"
		},
		"3815b0743f94fc8cc8654fd9d597ed7d8b77c57e": {
			"balance": "738578000000000000000"
		},
		"0f26480a150961b8e30750713a94ee6f2e47fc00": {
			"balance": "1000000000000000000000"
		},
		"ede5de7c7fb7eee0f36e64530a41440edfbefacf": {
			"balance": "617200000000000000000"
		},
		"763a7cbab70d7a64d0a7e52980f681472593490c": {
			"balance": "600000000000000000000"
		},
		"6e270ad529f1f0b8d9cb6d2427ec1b7e2dc64a74": {
			"balance": "200000000000000000000"
		},
		"eb3bdd59dcdda5a9bb2ac1641fd02180f5f36560": {
			"balance": "6600000000000000000000"
		},
		"f4ebf50bc7e54f82e9b9bd24baef29438e259ce6": {
			"balance": "10000000000000000000000"
		},
		"882c8f81872c79fed521cb5f950d8b032322ea69": {
			"balance": "40000000000000000000000"
		},
		"394132600f4155e07f4d45bc3eb8d9fb72dcd784": {
			"balance": "2941000000000000000000"
		},
		"0be2b94ad950a2a62640c35bfccd6c67dae450f6": {
			"balance": "1940000000000000000000"
		},
		"d4c6ac742e7c857d4a05a04c33d4d05c1467571d": {
			"balance": "200000000000000000000"
		},
		"1fddd85fc98be9c4045961f40f93805ecc4549e5": {
			"balance": "164000000000000000000"
		},
		"534065361cb854fac42bfb5c9fcde0604ac919da": {
			"balance": "2000000000000000000000"
		},
		"9a6ff5f6a7af7b7ae0ed9c20ecec5023d281b786": {
			"balance": "2547000000000000000000"
		},
		"4f3a4854911145ea01c644044bdb2e5a960a982f": {
			"balance": "4000000000000000000000"
		},
		"00497e92cdc0e0b963d752b2296acb87da828b24": {
			"balance": "194800000000000000000"
		},
		"4ff67fb87f6efba9279930cfbd1b7a343c79fade": {
			"balance": "400000000000000000000"
		},
		"62f2e5ccecd52cc4b95e0597df27cc079715608c": {
			"balance": "143000000000000000000"
		},
		"1eda084e796500ba14c5121c0d90846f66e4be62": {
			"balance": "534800000000000000000"
		},
		"9836b4d30473641ab56aeee19242761d72725178": {
			"balance": "2000000000000000000000"
		},
		"de55de0458f850b37e4d78a641dd2eb2dd8f38ce": {
			"balance": "4000000000000000000000"
		},
		"140ca28ff33b9f66d7f1fc0078f8c1eef69a1bc0": {
			"balance": "1600000000000000000000"
		},
		"2014261f01089f53795630ba9dd24f9a34c2d942": {
			"balance": "1337000000000000000000"
		},
		"11415fab61e0dfd4b90676141a557a869ba0bde9": {
			"balance": "2048000000000000000000"
		},
		"88344909644c7ad4930fd873ca1c0da2d434c07f": {
			"balance": "131970000000000000000"
)E" + R"E(
		},
		"88b217ccb786a254cf4dc57f5d9ac3c455a30483": {
			"balance": "925000000000000000000"
		},
		"dfdbcec1014b96da2158ca513e9c8d3b9af1c3d0": {
			"balance": "2000000000000000000000"
		},
		"1ba9f7997e5387b6b2aa0135ac2452fe36b4c20d": {
			"balance": "850000000000000000000"
		},
		"d70ad2c4e9eebfa637ef56bd486ad2a1e5bce093": {
			"balance": "200000000000000000000"
		},
		"9ce27f245e02d1c312c1d500788c9def7690453b": {
			"balance": "200000000000000000000"
		},
		"8234f463d18485501f8f85ace4972c9b632dbccc": {
			"balance": "2000000000000000000000"
		},
		"994152fc95d5c1ca8b88113abbad4d710e40def6": {
			"balance": "500000000000000000000"
		},
		"e5b980d28eece2c06fca6c9473068b37d4a6d6e9": {
			"balance": "695200000000000000000"
		},
		"2d426912d059fad9740b2e390a2eeac0546ff01b": {
			"balance": "1400000000000000000000"
		},
		"6d9997509882027ea947231424bedede2965d0ba": {
			"balance": "2001600000000000000000"
		},
		"167ce7de65e84708595a525497a3eb5e5a665073": {
			"balance": "575400000000000000000"
		},
		"e430c0024fdbf73a82e21fccf8cbd09138421c21": {
			"balance": "4000000000000000000000"
		},
		"2e52912bc10ea39d54e293f7aed6b99a0f4c73be": {
			"balance": "400000000000000000000"
		},
		"12cf8b0e465213211a5b53dfb0dd271a282c12c9": {
			"balance": "15200000000000000000"
		},
		"06964e2d17e9189f88a8203936b40ac96e533c06": {
			"balance": "18200000000000000000"
		},
		"66b1a63da4dcd9f81fe54f5e3fcb4055ef7ec54f": {
			"balance": "201412000000000000000"
		},
		"0a77e7f72b437b574f00128b21f2ac265133528c": {
			"balance": "2000000000000000000000"
		},
		"78f5c74785c5668a838072048bf8b453594ddaab": {
			"balance": "400000000000000000000"
		},
		"58e554af3d87629620da61d538c7f5b4b54c4afe": {
			"balance": "1297081000000000000000"
		},
		"37a10451f36166cf643dd2de6c1cbba8a011cfa3": {
			"balance": "380000000000000000000"
		},
		"fe9ad12ef05d6d90261f96c8340a0381974df477": {
			"balance": "2000000000000000000000"
		},
		"057f7f81cd7a406fc45994408b5049912c566463": {
			"balance": "1700000000000000000000"
		},
		"55a3df57b7aaec16a162fd5316f35bec082821cf": {
			"balance": "1970000000000000000000"
		},
		"c0e0b903088e0c63f53dd069575452aff52410c3": {
			"balance": "3000000000000000000000"
		},
		"63e88e2e539ffb450386b4e46789b223f5476c45": {
			"balance": "6292000000000000000000"
		},
		"3727341f26c12001e378405ee38b2d8464ec7140": {
			"balance": "2000000000000000000000"
		},
		"c96751656c0a8ef4357b7344322134b983504aca": {
			"balance": "2000000000000000000000"
		},
		"1e060dc6c5f1cb8cc7e1452e02ee167508b56542": {
			"balance": "12715500000000000000000"
		},
		"18136c9df167aa17b6f18e22a702c88f4bc28245": {
			"balance": "4000000000000000000000"
		},
		"116108c12084612eeda7a93ddcf8d2602e279e5c": {
			"balance": "2000000000000000000000"
		},
		"bbb643d2187b364afc10a6fd368d7d55f50d1a3c": {
			"balance": "1000000000000000000000"
		},
		"ec83e798c396b7a55e2a2224abcd834b27ea459c": {
			"balance": "12000000000000000000000"
		},
		"973f4e361fe5decd989d4c8f7d7cc97990385daf": {
			"balance": "388500000000000000000"
		},
)E" + R"E(
		"c0f29ed0076611b5e55e130547e68a48e26df5e4": {
			"balance": "3000000000000000000000"
		},
		"fd4b551f6fdbcda6c511b5bb372250a6b783e534": {
			"balance": "20600000000000000000"
		},
		"144b19f1f66cbe318347e48d84b14039466c5909": {
			"balance": "2000000000000000000000"
		},
		"bf183641edb886ce60b8190261e14f42d93cce01": {
			"balance": "25019000000000000000"
		},
		"94db807873860aac3d5aea1e885e52bff2869954": {
			"balance": "3220000000000000000000"
		},
		"7a74cee4fa0f6370a7894f116cd00c1147b83e59": {
			"balance": "800000000000000000000"
		},
		"cd32a4a8a27f1cc63954aa634f7857057334c7a3": {
			"balance": "1085000000000000000000"
		},
		"7cbeb99932e97e6e02058cfc62d0b26bc7cca52b": {
			"balance": "2000000000000000000000"
		},
		"8cde8b732e6023878eb23ed16229124b5f7afbec": {
			"balance": "133700000000000000000"
		},
		"45c4ecb4ee891ea984a7c5cefd8dfb00310b2850": {
			"balance": "1980000000000000000000"
		},
		"8b393fb0813ee101db1e14ecc7d322c72b8c0473": {
			"balance": "455578000000000000000"
		},
		"7b66126879844dfa34fe65c9f288117fefb449ad": {
			"balance": "6000000000000000000000"
		},
		"162ba503276214b509f97586bd842110d103d517": {
			"balance": "9002000000000000000000"
		},
		"7dece6998ae1900dd3770cf4b93812bad84f0322": {
			"balance": "100000000000000000000"
		},
		"ec0927bac7dc36669c28354ab1be83d7eec30934": {
			"balance": "2000000000000000000000"
		},
		"8d7f3e61299c2db9b9c0487cf627519ed00a9123": {
			"balance": "1742400000000000000000"
		},
		"4fc46c396e674869ad9481638f0013630c87caac": {
			"balance": "1000000000000000000000"
		},
		"bf68d28aaf1eeefef646b65e8cc8d190f6c6da9c": {
			"balance": "2000000000000000000000"
		},
		"00969747f7a5b30645fe00e44901435ace24cc37": {
			"balance": "1700000000000000000000"
		},
		"494dec4d5ee88a2771a815f1ee7264942fb58b28": {
			"balance": "2000000000000000000000"
		},
		"ffeac0305ede3a915295ec8e61c7f881006f4474": {
			"balance": "98500000000000000000"
		},
		"b39139576194a0866195151f33f2140ad1cc86cf": {
			"balance": "100000000000000000000000"
		},
		"fead1803e5e737a68e18472d9ac715f0994cc2be": {
			"balance": "500000000000000000000"
		},
		"698ab9a2f33381e07c0c47433d0d21d6f336b127": {
			"balance": "20000000000000000000"
		},
		"e5edc73e626f5d3441a45539b5f7a398c593edf6": {
			"balance": "865000000000000000000"
		},
		"dd4f5fa2111db68f6bde3589b63029395b69a92d": {
			"balance": "158400000000000000000"
		},
		"8c93c3c6db9d37717de165c3a1b4fe51952c08de": {
			"balance": "400000000000000000000"
		},
		"f87bb07b289df7301e54c0efda6a2cf291e89200": {
			"balance": "1400000000000000000000"
		},
		"e7a4560c84b20e0fb54c49670c2903b0a96c42a4": {
			"balance": "598000000000000000000"
		},
		"00a5797f52c9d58f189f36b1d45d1bf6041f2f6b": {
			"balance": "5456900000000000000000"
		},
		"9da3302240af0511c6fd1857e6ddb7394f77ab6b": {
			"balance": "3100000000000000000000"
		},
		"2c2d15ff39561c1b72eda1cc027ffef23743a144": {
			"balance": "3920000000000000000000"
		},
		"9b4c2715780ca4e99e60ebf219f1590c8cad500a": {
			"balance": "1600000000000000000000"
		},
		"ff5e7ee7d5114821e159dca5e81f18f1bfffbff9": {
)E" + R"E(
			"balance": "2000000000000000000000"
		},
		"0169c1c210eae845e56840412e1f65993ea90fb4": {
			"balance": "2000000000000000000000"
		},
		"abc45f84db7382dde54c5f7d8938c42f4f3a3bc4": {
			"balance": "200000000000000000000"
		},
		"d9383d4b6d17b3f9cd426e10fb944015c0d44bfb": {
			"balance": "800000000000000000000"
		},
		"c090fe23dcd86b358c32e48d2af91024259f6566": {
			"balance": "200000000000000000000"
		},
		"9ffedcc36b7cc312ad2a9ede431a514fccb49ba3": {
			"balance": "669800000000000000000"
		},
		"2ffe93ec1a5636e9ee34af70dff52682e6ff7079": {
			"balance": "2000000000000000000000"
		},
		"6e01e4ad569c95d007ada30d5e2db12888492294": {
			"balance": "4000000000000000000000"
		},
		"d4d92c62b280e00f626d8657f1b86166cb1f740f": {
			"balance": "200028000000000000000"
		},
		"1d36683063b7e9eb99462dabd569bddce71686f2": {
			"balance": "1000000000000000000000"
		},
		"3a48e0a7098b06a905802b87545731118e89f439": {
			"balance": "2000000000000000000000"
		},
		"bd9e56e902f4be1fc8768d8038bac63e2acbbf8e": {
			"balance": "999972000000000000000"
		},
		"4d67f2ab8599fef5fc413999aa01fd7fce70b43d": {
			"balance": "10000000000000000000000"
		},
		"8e74e0d1b77ebc823aca03f119854cb12027f6d7": {
			"balance": "107200000000000000000000"
		},
		"7e5b19ae1be94ff4dee635492a1b012d14db0213": {
			"balance": "100000000000000000000"
		},
		"5de9e7d5d1b667d095dd34099c85b0421a0bc681": {
			"balance": "20000000000000000000"
		},
		"316eb4e47df71b42e16d6fe46825b7327baf3124": {
			"balance": "4000000000000000000000"
		},
		"772c297f0ad194482ee8c3f036bdeb01c201d5cc": {
			"balance": "200000000000000000000"
		},
		"d7052519756af42590f15391b723a03fa564a951": {
			"balance": "4615591000000000000000"
		},
		"2c6846a1aa999a2246a287056000ba4dcba8e63d": {
			"balance": "10020000000000000000000"
		},
		"de5b005fe8daae8d1f05de3eda042066c6c4691c": {
			"balance": "1100000000000000000000"
		},
		"254c1ecc630c2877de8095f0a8dba1e8bf1f550c": {
			"balance": "1700000000000000000000"
		},
		"f8f226142a428434ab17a1864a2597f64aab2f06": {
			"balance": "172473000000000000000"
		},
		"a6c910ce4d494a919ccdaaa1fc3b82aa74ba06cf": {
			"balance": "8000000000000000000000"
		},
		"e587b16abc8a74081e3613e14342c03375bf0847": {
			"balance": "2000000000000000000000"
		},
		"6f176065e88e3c6fe626267d18a088aaa4db80bc": {
			"balance": "3520000000000000000000"
		},
		"50dcbc27bcad984093a212a9b4178eabe9017561": {
			"balance": "145512000000000000000"
		},
		"e1953c6e975814c571311c34c0f6a99cdf48ab82": {
			"balance": "50000000000000000000"
		},
		"be0a2f385f09dbfce96732e12bb40ac349871ba8": {
			"balance": "1610348000000000000000"
		},
		"4712540265cbeec3847022c59f1b318d43400a9e": {
			"balance": "3500000000000000000000"
		},
		"29bdc4f28de0180f433c2694eb74f5504ce94337": {
			"balance": "2000000000000000000000"
		},
		"2f66bfbf2262efcc8d2bd0444fc5b0696298ff1e": {
			"balance": "9940000000000000000000"
		},
		"506411fd79003480f6f2b6aac26b7ba792f094b2": {
			"balance": "500000000000000000000"
		},
		"23ea669e3564819a83b0c26c00a16d9e826f6c46": {
			"balance": "1430590000000000000000"
)E" + R"E(
		},
		"e3ffb02cb7d9ea5243701689afd5d417d7ed2ece": {
			"balance": "78000000000000000000"
		},
		"38e7dba8fd4f1f850dbc2649d8e84f0952e3eb3c": {
			"balance": "50000000000000000000"
		},
		"8644cc281be332ccced36da483fb2a0746d9ba2e": {
			"balance": "400000000000000000000"
		},
		"e8a91da6cf1b9d65c74a02ec1f96eecb6dd241f3": {
			"balance": "1940000000000000000000"
		},
		"0631dc40d74e5095e3729eddf49544ecd4396f67": {
			"balance": "160000000000000000000"
		},
		"83c897a84b695eebe46679f7da19d776621c2694": {
			"balance": "500000000000000000000"
		},
		"db73460b59d8e85045d5e752e62559875e42502e": {
			"balance": "999800000000000000000"
		},
		"0dd4e674bbadb1b0dc824498713dce3b5156da29": {
			"balance": "170000000000000000000"
		},
		"e3933d61b77dcdc716407f8250bc91e4ffaeb09d": {
			"balance": "86600000000000000000000"
		},
		"58c90754d2f20a1cb1dd330625e04b45fa619d5c": {
			"balance": "2000000000000000000000"
		},
		"895ec5545644e0b78330fffab8ddeac9e833156c": {
			"balance": "600000000000000000000"
		},
		"7e1e29721d6cb91057f6c4042d8a0bbc644afe73": {
			"balance": "159800000000000000000"
		},
		"72b90a4dc097239492c5b9777dcd1e52ba2be2c2": {
			"balance": "6000000000000000000000"
		},
		"64241a7844290e0ab855f1d4aa75b55345032224": {
			"balance": "1600000000000000000000"
		},
		"6fd4e0f3f32bee6d3767fdbc9d353a6d3aab7899": {
			"balance": "695240000000000000000"
		},
		"3a035594c747476d42d1ee966c36224cdd224993": {
			"balance": "355890000000000000000"
		},
		"de97f4330700b48c496d437c91ca1de9c4b01ba4": {
			"balance": "2910840000000000000000"
		},
		"716ad3c33a9b9a0a18967357969b94ee7d2abc10": {
			"balance": "482000000000000000000"
		},
		"bfbe05e88c9cbbcc0e92a405fac1d85de248ee24": {
			"balance": "100000000000000000000"
		},
		"cfc4e6f7f8b011414bfba42f23adfaa78d4ecc5e": {
			"balance": "1850000000000000000000"
		},
		"d931ac2668ba6a84481ab139735aec14b7bfbabf": {
			"balance": "2000000000000000000000"
		},
		"e3263ce8af6db3e467584502ed7109125eae22a5": {
			"balance": "2000000000000000000000"
		},
		"f78258c12481bcdddbb72a8ca0c043097261c6c5": {
			"balance": "20000000000000000000"
		},
		"4493123c021ece3b33b1a452c9268de14007f9d3": {
			"balance": "6685000000000000000000"
		},
		"431f2c19e316b044a4b3e61a0c6ff8c104a1a12f": {
			"balance": "1000000000000000000000"
		},
		"e63e787414b9048478a50733359ecdd7e3647aa6": {
			"balance": "1580000000000000000000"
		},
		"e4715956f52f15306ee9506bf82bccc406b3895e": {
			"balance": "274944000000000000000"
		},
		"f7f91e7acb5b8129a306877ce3168e6f438b66a1": {
			"balance": "176000000000000000000"
		},
		"dcdbbd4e2604e40e1710cc6730289dccfad3892d": {
			"balance": "4600000000000000000000"
		},
		"2b5f4b3f1e11707a227aa5e69fa49dded33fb321": {
			"balance": "6000000000000000000000"
		},
		"01488ad3da603c4cdd6cb0b7a1e30d2a30c8fc38": {
			"balance": "200000000000000000000"
		},
		"841145b44840c946e21dbc190264b8e0d5029369": {
			"balance": "300000000000000000000000"
		},
		"bf05070c2c34219311c4548b2614a438810ded6d": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"38f387e1a4ed4a73106ef2b462e474e2e3143ad0": {
			"balance": "6000000000000000000000"
		},
		"f116b0b4680f53ab72c968ba802e10aa1be11dc8": {
			"balance": "20000000000000000000"
		},
		"bea0afc93aae2108a3fac059623bf86fa582a75e": {
			"balance": "1700000000000000000000"
		},
		"4c997992036c5b433ac33d25a8ea1dc3d4e4e6d8": {
			"balance": "29200000000000000000"
		},
		"ab7e0b83ed9a424c6d1e6a6f87a4dbf06409c7d6": {
			"balance": "2400000000000000000000"
		},
		"d71fb130f0150c565269e00efb43902b52a455a6": {
			"balance": "200000000000000000000"
		},
		"99b018932bcad355b6792b255db6702dec8ce5dd": {
			"balance": "4000086000000000000000"
		},
		"4b904e934bd0cc8b20705f879e905b93ea0ccc30": {
			"balance": "2000000000000000000000"
		},
		"672ec42faa8cd69aaa71b32cc7b404881d52ff91": {
			"balance": "10000000000000000000000"
		},
		"acbc2d19e06c3babbb5b6f052b6bf7fc37e07229": {
			"balance": "200000000000000000000"
		},
		"cea8743341533cb2f0b9c6efb8fda80d77162825": {
			"balance": "100000000000000000000"
		},
		"9568b7de755628af359a84543de23504e15e41e6": {
			"balance": "40000000000000000000000"
		},
		"6ec96d13bdb24dc7a557293f029e02dd74b97a55": {
			"balance": "4000000000000000000000"
		},
		"d95c90ffbe5484864780b867494a83c89256d6e4": {
			"balance": "1640000000000000000000"
		},
		"ade6f8163bf7c7bb4abe8e9893bd0cc112fe8872": {
			"balance": "327600000000000000000"
		},
		"250eb7c66f869ddf49da85f3393e980c029aa434": {
			"balance": "4000000000000000000000"
		},
		"a35c19132cac1935576abfed6c0495fb07881ba0": {
			"balance": "2000000000000000000000"
		},
		"d5550caaf743b037c56fd2558a1c8ed235130750": {
			"balance": "5347598000000000000000"
		},
		"03097923ba155e16d82f3ad3f6b815540884b92c": {
			"balance": "1820000000000000000000"
		},
		"d6d9e30f0842012a7176a917d9d2048ca0738759": {
			"balance": "4000000000000000000000"
		},
		"ab9ad36e5c74ce2e96399f57839431d0e79f96ab": {
			"balance": "164000000000000000000"
		},
		"75be8ff65e5788aec6b2a52d5fa7b1e7a03ba675": {
			"balance": "67720000000000000000"
		},
		"4f6d4737d7a940382487264886697cf7637f8015": {
			"balance": "1670000000000000000000"
		},
		"5f7b3bbac16dab831a4a0fc53b0c549dc36c31ca": {
			"balance": "1940000000000000000000"
		},
		"d843ee0863ce933e22f89c802d31287b9671e81c": {
			"balance": "13370000000000000000"
		},
		"361f3ba9ed956b770f257d3672fe1ff9f7b0240c": {
			"balance": "600000000000000000000"
		},
		"6c0ae9f043c834d44271f13406593dfe094f389f": {
			"balance": "1517545000000000000000"
		},
		"db34745ede8576b499db01beb7c1ecda85cf4abe": {
			"balance": "80000000000000000000"
		},
		"7be8ccb4f11b66ca6e1d57c0b5396221a31ba53a": {
			"balance": "20000000000000000000"
		},
		"128b908fe743a434203de294c441c7e20a86ea67": {
			"balance": "713304000000000000000"
		},
		"df236bf6abf4f3293795bf0c28718f93e3b1b36b": {
			"balance": "1337000000000000000000"
		},
		"14254ea126b52d0142da0a7e188ce255d8c47178": {
			"balance": "775000000000000000000"
		},
		"ceed47ca5b899fd1623f21e9bd4db65a10e5b09d": {
			"balance": "133196000000000000000"
		},
		"30acd858875fa24eef0d572fc7d62aad0ebddc35": {
)E" + R"E(
			"balance": "400000000000000000000"
		},
		"47a281dff64167197855bf6e705eb9f2cef632ea": {
			"balance": "1000072000000000000000"
		},
		"297d5dbe222f2fb52531acbd0b013dc446ac7368": {
			"balance": "20000000000000000000000"
		},
		"adf85203c8376a5fde9815384a350c3879c4cb93": {
			"balance": "1147300000000000000000"
		},
		"c3e0471c64ff35fa5232cc3121d1d38d1a0fb7de": {
			"balance": "2000000000000000000000"
		},
		"fdecc82ddfc56192e26f563c3d68cb544a96bfed": {
			"balance": "440000000000000000000"
		},
		"2614f42d5da844377578e6b448dc24305bef2b03": {
			"balance": "2000000000000000000000"
		},
		"1d96bcd58457bbf1d3c2a46ffaf16dbf7d836859": {
			"balance": "171313000000000000000"
		},
		"bd66ffedb530ea0b2e856dd12ac2296c31fe29e0": {
			"balance": "200000000000000000000"
		},
		"6e84876dbb95c40b6656e42ba9aea08a993b54dc": {
			"balance": "1101932000000000000000"
		},
		"a1c4f45a82e1c478d845082eb18875c4ea6539ab": {
			"balance": "200000000000000000000000"
		},
		"2c964849b1f69cc7cea4442538ed87fdf16cfc8f": {
			"balance": "2000000000000000000000"
		},
		"45b47105fe42c4712dce6e2a21c05bffd5ea47a9": {
			"balance": "2000000000000000000000"
		},
		"31e9c00f0c206a4e4e7e0522170dc81e88f3eb70": {
			"balance": "2685000000000000000000"
		},
		"5fe77703808f823e6c399352108bdb2c527cb87c": {
			"balance": "1960000000000000000000"
		},
		"2272186ef27dcbe2f5fc373050fdae7f2ace2316": {
			"balance": "16100000000000000000000"
		},
		"b7576e9d314df41ec5506494293afb1bd5d3f65d": {
			"balance": "20000000000000000000"
		},
		"ac9fff68c61b011efbecf038ed72db97bb9e7281": {
			"balance": "9550000000000000000000"
		},
		"cd9529492b5c29e475acb941402b3d3ba50686b0": {
			"balance": "1970000000000000000000"
		},
		"f19b39389d47b11b8a2c3f1da9124decffbefaf7": {
			"balance": "2000000000000000000000"
		},
		"9e951f6dc5e352afb8d04299d2478a451259bf56": {
			"balance": "72004000000000000000"
		},
		"8eb1fbe4e5d3019cd7d30dae9c0d5b4c76fb6331": {
			"balance": "2000000000000000000000"
		},
		"29cc804d922be91f5909f348b0aaa5d21b607830": {
			"balance": "4000000000000000000000"
		},
		"5c7b9ec7a2438d1e3c7698b545b9c3fd77b7cd55": {
			"balance": "1000000000000000000000"
		},
		"a16160851d2b9c349b92e46f829abfb210943595": {
			"balance": "1790000000000000000000"
		},
		"eac6b98842542ea10bb74f26d7c7488f698b6452": {
			"balance": "20000000000000000000000"
		},
		"57825aeb09076caa477887fbc9ae37e8b27cc962": {
			"balance": "100000000000000000000"
		},
		"b35e8a1c0dac7e0e66dbac736a592abd44012561": {
			"balance": "14974000000000000000"
		},
		"756b84eb85fcc1f4fcdcc2b08db6a86e135fbc25": {
			"balance": "3220000000000000000000"
		},
		"e13b3d2bbfdcbc8772a23315724c1425167c5688": {
			"balance": "1032115000000000000000"
		},
		"0a2dcb7a671701dbb8f495728088265873356c8e": {
			"balance": "152120000000000000000"
		},
		"03cb4c4f4516c4ff79a1b6244fbf572e1c7fea79": {
			"balance": "2740000000000000000000"
		},
		"98ba4e9ca72fddc20c69b4396f76f8183f7a2a4e": {
			"balance": "12800000000000000000000"
		},
		"f8087786b42da04ed6d1e0fe26f6c0eefe1e9f5a": {
			"balance": "10000000000000000000000"
)E" + R"E(
		},
		"02f7f67209b16a17550c694c72583819c80b54ad": {
			"balance": "98400000000000000000"
		},
		"32bb2e9693e4e085344d2f0dbd46a283e3a087fd": {
			"balance": "400000000000000000000"
		},
		"9c78963fbc263c09bd72e4f8def74a9475f7055c": {
			"balance": "13790000000000000000000"
		},
		"27144ca9a7771a836ad50f803f64d869b2ae2b20": {
			"balance": "4000000000000000000000"
		},
		"cc758d071d25a6320af68c5dc9c4f6955ba94520": {
			"balance": "6000000000000000000000"
		},
		"cb42b44eb5fd60b5837e4f9eb47267523d1a229c": {
			"balance": "865000000000000000000"
		},
		"aaf5b207b88b0de4ac40d747cee06e172df6e745": {
			"balance": "31428000000000000000000"
		},
		"52d380511df19d5ec2807bbcb676581b67fd37a3": {
			"balance": "13400000000000000000"
		},
		"aa1b3768c16d821f580e76c8e4c8e86d7dc78853": {
			"balance": "400000000000000000000"
		},
		"41098a81452317c19e3eef0bd123bbe178e9e9ca": {
			"balance": "2800000000000000000000"
		},
		"267148fd72c54f620a592fb92799319cc4532b5c": {
			"balance": "410000000000000000000"
		},
		"d7cdbd41fff20df727c70b6255c1ba7606055468": {
			"balance": "200000000000000000000"
		},
		"0e33fcbbc003510be35785b52a9c5d216bc005f4": {
			"balance": "1880000000000000000000"
		},
		"6727daf5b9d68efcab489fedec96d7f7325dd423": {
			"balance": "2000000000000000000000"
		},
		"cd0a161bc367ae0927a92aac9cf6e5086714efca": {
			"balance": "2000000000000000000000"
		},
		"612667f172135b950b2cd1de10afdece6857b873": {
			"balance": "1000000000000000000000"
		},
		"900194c4b1074305d19de405b0ac78280ecaf967": {
			"balance": "1000000000000000000000"
		},
		"51f55ef47e6456a418ab32b9221ed27dba6608ee": {
			"balance": "4200000000000000000000"
		},
		"0da532c910e3ac0dfb14db61cd739a93353fd05f": {
			"balance": "1336866000000000000000"
		},
		"21df2dcdaf74b2bf803404dd4de6a35eabec1bbd": {
			"balance": "6920000000000000000000"
		},
		"f0e7fb9e420a5340d536f40408344feaefc06aef": {
			"balance": "1000000000000000000000"
		},
		"6742a2cfce8d79a2c4a51b77747498912245cd6a": {
			"balance": "258064000000000000000"
		},
		"8663a241a0a89e70e182c845e2105c8ad7264bcf": {
			"balance": "14825507000000000000000"
		},
		"18e113d8177c691a61be785852fa5bb47aeebdaf": {
			"balance": "1337000000000000000000"
		},
		"1bec4d02ce85fc48feb62489841d85b170586a9b": {
			"balance": "2400000000000000000000"
		},
		"287cf9d0902ef819a7a5f149445bf1775ee8c47c": {
			"balance": "16000000000000000000000"
		},
		"28967280214e218a120c5dda37041b111ea36d74": {
			"balance": "200000000000000000000"
		},
		"a0b771951ce1deee363ae2b771b73e07c4b5e800": {
			"balance": "1400000000000000000000"
		},
		"29f8fba4c30772b057edbbe62ae7420c390572e1": {
			"balance": "1000000000000000000000"
		},
		"ee34c7e7995db9f187cff156918cfb6f13f6e003": {
			"balance": "1960000000000000000000"
		},
		"916bf7e3c545921d3206d900c24f14127cbd5e70": {
			"balance": "18020000000000000000000"
		},
		"93235f340d2863e18d2f4c52996516138d220267": {
			"balance": "73800000000000000000"
		},
		"7efec0c6253caf397f71287c1c07f6c9582b5b86": {
			"balance": "482839000000000000000"
		},
)E" + R"E(
		"8d2e31b08803b2c5f13d398ecad88528209f6057": {
			"balance": "9993000000000000000000"
		},
		"964eab4b276b4cd8983e15ca72b106900fe41fce": {
			"balance": "500000000000000000000"
		},
		"eea1e97988de75d821cd28ad6822b22cce988b31": {
			"balance": "520000000000000000000"
		},
		"278c0bde630ec393b1e7267fc9d7d97019e4145b": {
			"balance": "2000000000000000000000"
		},
		"82e4461eb9d849f0041c1404219e4272c4900ab4": {
			"balance": "2000000000000000000000"
		},
		"4a73389298031b8816cca946421c199e18b343d6": {
			"balance": "631254000000000000000"
		},
		"9a5af31c7e06339ac8b4628d7c4db0ce0f45c8a4": {
			"balance": "500000000000000000000"
		},
		"cb9b5103e4ce89af4f64916150bff9eecb9faa5c": {
			"balance": "500000000000000000000"
		},
		"740f641614779dcfa88ed1d425d60db42a060ca6": {
			"balance": "998630000000000000000"
		},
		"a4e623451e7e94e7e89ba5ed95c8a83a62ffc4ea": {
			"balance": "20000000000000000000"
		},
		"25a500eeec7a662a841552b5168b707b0de21e9e": {
			"balance": "10020000000000000000000"
		},
		"185a7fc4ace368d233e620b2a45935661292bdf2": {
			"balance": "20000000000000000000000"
		},
		"9b68f67416a63bf4451a31164c92f672a68759e9": {
			"balance": "60000000000000000000000"
		},
		"a38b5bd81a9db9d2b21d5ec7c60552cd02ed561b": {
			"balance": "6000000000000000000000"
		},
		"61c830f1654718f075ccaba316faacb85b7d120b": {
			"balance": "400000000000000000000"
		},
		"8392e53776713578015bff4940cf43849d7dcba1": {
			"balance": "153190000000000000000"
		},
		"dc57477dafa42f705c7fe40eae9c81756e0225f1": {
			"balance": "500044000000000000000"
		},
		"febc3173bc9072136354002b7b4fb3bfc53f22f1": {
			"balance": "370000000000000000000"
		},
		"d78f84e38944a0e0255faece48ba4950d4bd39d2": {
			"balance": "5000000000000000000000"
		},
		"a7a3bb6139b0ada00c1f7f1f9f56d994ba4d1fa8": {
			"balance": "2000000000000000000000"
		},
		"aa3f29601a1331745e05c42830a15e71938a6237": {
			"balance": "1700000000000000000000"
		},
		"bec6640f4909b58cbf1e806342961d607595096c": {
			"balance": "1999944000000000000000"
		},
		"9be3c329b62a28b8b0886cbd8b99f8bc930ce3e6": {
			"balance": "74500000000000000000"
		},
		"e3eb2c0a132a524f72ccc0d60fee8b41685d39e2": {
			"balance": "1970000000000000000000"
		},
		"90b1f370f9c1eb0be0fb8e2b8ad96a416371dd8a": {
			"balance": "900000000000000000000"
		},
		"f2742e6859c569d5f2108351e0bf4dca352a48a8": {
			"balance": "10000000000000000000000"
		},
		"b134c004391ab4992878337a51ec242f42285742": {
			"balance": "2000000000000000000000"
		},
		"ab7416ff32254951cbbc624ec7fb45fc7ecaa872": {
			"balance": "340000000000000000000"
		},
		"9795f64319fc17dd0f8261f9d206fb66b64cd0c9": {
			"balance": "200000000000000000000"
		},
		"64e03ef070a54703b7184e48276c5c0077ef4b34": {
			"balance": "320000000000000000000"
		},
		"3430a16381f869f6ea5423915855e800883525a9": {
			"balance": "17900000000000000000000"
		},
		"f4a367b166d2991a2bfda9f56463a09f252c1b1d": {
			"balance": "1970000000000000000000"
		},
		"77c4a697e603d42b12056cbba761e7f51d0443f5": {
			"balance": "680000000000000000000"
		},
		"153ef58a1e2e7a3eb6b459a80ab2a547c94182a2": {
)E" + R"E(
			"balance": "96000000000000000000000"
		},
		"6dbe8abfa1742806263981371bf3d35590806b6e": {
			"balance": "20000000000000000000000"
		},
		"4c99dae96481e807c1f99f8b7fbde29b7547c5bf": {
			"balance": "150000000000000000000"
		},
		"d5b9d277d8aad20697a51f76e20978996bffe055": {
			"balance": "143250000000000000000"
		},
		"0f24105abbdaa03fa6309ef6c188e51f714a6e59": {
			"balance": "200000000000000000000"
		},
		"1cb6b2d7cfc559b7f41e6f56ab95c7c958cd0e4c": {
			"balance": "1337000000000000000000"
		},
		"f37b426547a1642d8033324814f0ede3114fc212": {
			"balance": "401100000000000000000"
		},
		"318f1f8bd220b0558b95fb33100ffdbb640d7ca6": {
			"balance": "4000000000000000000000"
		},
		"206d55d5792a514ec108e090599f2a065e501185": {
			"balance": "200550000000000000000"
		},
		"11d2247a221e70c2d66d17ee138d38c55ffb8640": {
			"balance": "10000000000000000000000"
		},
		"e8de725eca5def805ff7941d31ac1c2e342dfe95": {
			"balance": "2462500000000000000000"
		},
		"d561cbbc05515de73ab8cf9eae1357341e7dfdf4": {
			"balance": "6000000000000000000000"
		},
		"0455dcec8a7fc4461bfd7f37456fce3f4c3caac7": {
			"balance": "400000000000000000000"
		},
		"5161fd49e847f67455f1c8bb7abb36e985260d03": {
			"balance": "1200000000000000000000"
		},
		"8e073bad25e42218615f4a0e6b2ea8f8de2230c0": {
			"balance": "2402500000000000000000"
		},
		"6c08a6dc0173c7342955d1d3f2c065d62f83aec7": {
			"balance": "20000000000000000000"
		},
		"95cb6d8a6379f94aba8b885669562c4d448e56a7": {
			"balance": "2000000000000000000000"
		},
		"2805415e1d7fdec6dedfb89e521d10592d743c10": {
			"balance": "100000000000000000000"
		},
		"daacdaf42226d15cb1cf98fa15048c7f4ceefe69": {
			"balance": "300000000000000000000"
		},
		"e33df4ce80ccb62a76b12bcdfcecc46289973aa9": {
			"balance": "6000000000000000000000"
		},
		"8f8cd26e82e7c6defd02dfad07979021cbf7150c": {
			"balance": "3000000000000000000000"
		},
		"77a17122fa31b98f1711d32a99f03ec326f33d08": {
			"balance": "1700000000000000000000"
		},
		"6f791d359bc3536a315d6382b88311af8ed6da47": {
			"balance": "92000000000000000000"
		},
		"de30e49e5ab313214d2f01dcabce8940b81b1c76": {
			"balance": "197000000000000000000"
		},
		"cf9be9b9ab86c66b59968e67b8d4dcff46b1814a": {
			"balance": "660000000000000000000"
		},
		"7fdfc88d78bf1b285ac64f1adb35dc11fcb03951": {
			"balance": "2287900000000000000000"
		},
		"c5134cfbb1df7a20b0ed7057622eeed280947dad": {
			"balance": "3800000000000000000000"
		},
		"fa9ec8efe08686fa58c181335872ba698560ecab": {
			"balance": "1999944000000000000000"
		},
		"f6a8635757c5e8c134d20d028cf778cf8609e46a": {
			"balance": "1459416000000000000000"
		},
		"6265b2e7730f36b776b52d0c9d02ada55d8e3cb6": {
			"balance": "1000000000000000000000"
		},
		"6a8cea2de84a8df997fd3f84e3083d93de57cda9": {
			"balance": "100007000000000000000"
		},
		"1b7ed974b6e234ce81247498429a5bd4a0a2d139": {
			"balance": "2000000000000000000000"
		},
		"9ba53dc8c95e9a472feba2c4e32c1dc4dd7bab46": {
			"balance": "1337000000000000000000"
		},
		"d7b740dff8c457668fdf74f6a266bfc1dcb723f9": {
			"balance": "20000000000000000000"
)E" + R"E(
		},
		"07bc2cc8eedc01970700efc9c4fb36735e98cd71": {
			"balance": "4000000000000000000000"
		},
		"3e1c962063e0d5295941f210dca3ab531eec8809": {
			"balance": "3000000000000000000000"
		},
		"b447571dacbb3ecbb6d1cf0b0c8f3838e52324e2": {
			"balance": "30199000000000000000"
		},
		"87764e3677eef604cbc59aed24abdc566b09fc25": {
			"balance": "3000000000000000000000"
		},
		"03aa622881236dd0f4940c24c324ff8b7b7e2186": {
			"balance": "3200000000000000000000"
		},
		"a4a7d306f510cd58359428c0d2f7c3609d5674d7": {
			"balance": "3349000000000000000000"
		},
		"3c83c1701db0388b68210d00f5717cd9bd322c6a": {
			"balance": "30000000000000000000000"
		},
		"047d5a26d7ad8f8e70600f70a398ddaa1c2db26f": {
			"balance": "6000000000000000000000"
		},
		"43767bf7fd2af95b72e9312da9443cb1688e4343": {
			"balance": "300000000000000000000"
		},
		"34a85d6d243fb1dfb7d1d2d44f536e947a4cee9e": {
			"balance": "20000000000000000000000"
		},
		"65a9dad42e1632ba3e4e49623fab62a17e4d3611": {
			"balance": "93120000000000000000"
		},
		"48e0cbd67f18acdb7a6291e1254db32e0972737f": {
			"balance": "100007000000000000000"
		},
		"a5de5e434fdcdd688f1c31b6fb512cb196724701": {
			"balance": "800000000000000000000"
		},
		"6d63d38ee8b90e0e6ed8f192eda051b2d6a58bfd": {
			"balance": "30000000000000000000"
		},
		"b079bb4d9866143a6da72ae7ac0022062981315c": {
			"balance": "760000000000000000000"
		},
		"c0413f5a7c2d9a4b8108289ef6ecd271781524f4": {
			"balance": "50000000000000000000000"
		},
		"a91a5a7b341f99c535144e20be9c6b3bb4c28e4d": {
			"balance": "5431790000000000000000"
		},
		"993f146178605e66d517be782ef0b3c61a4e1925": {
			"balance": "7011998000000000000000"
		},
		"966c04781cb5e67dde3235d7f8620e1ab663a9a5": {
			"balance": "75800000000000000000000"
		},
		"b3f82a87e59a39d0d2808f0751eb72c2329cdcc5": {
			"balance": "5000000000000000000000"
		},
		"9b77ebced7e215f0920e8c2b870024f6ecb2ff31": {
			"balance": "1000000000000000000000"
		},
		"fe697ff22ca547bfc95e33d960da605c6763f35b": {
			"balance": "1325000000000000000000"
		},
		"480af52076009ca73781b70e43b95916a62203ab": {
			"balance": "924171000000000000000"
		},
		"a9dc0424c6969d798358b393b1933a1f51bee00a": {
			"balance": "20000000000000000000000"
		},
		"7aba56f63a48bc0817d6b97039039a7ad62fae2e": {
			"balance": "600000000000000000000"
		},
		"59d139e2e40c7b97239d23dfaca33858f602d22b": {
			"balance": "2000000000000000000000"
		},
		"8d6170ff66978e773bb621bf72b1ba7be3a7f87e": {
			"balance": "200000000000000000000"
		},
		"d668523a90f0293d65c538d2dd6c57673710196e": {
			"balance": "39500000000000000000"
		},
		"bbb5a0f4802c8648009e8a6998af352cde87544f": {
			"balance": "95500000000000000000"
		},
		"fc43829ac787ff88aaf183ba352aadbf5a15b193": {
			"balance": "3960000000000000000000"
		},
		"fe22a0b388668d1ae2643e771dacf38a434223cc": {
			"balance": "4000304000000000000000"
		},
		"092acb624b08c05510189bbbe21e6524d644ccad": {
			"balance": "18200000000000000000"
		},
		"8f0538ed71da1155e0f3bde5667ceb84318a1a87": {
			"balance": "1940000000000000000000"
		},
)E" + R"E(
		"06994cd83aa2640a97b2600b41339d1e0d3ede6c": {
			"balance": "250000000000000000000"
		},
		"9d460c1b379ddb19a8c85b4c6747050ddf17a875": {
			"balance": "3340000000000000000000"
		},
		"77a769fafdecf4a638762d5ba3969df63120a41d": {
			"balance": "2000000000000000000000"
		},
		"5f375b86600c40cca8b2676b7a1a1d1644c5f52c": {
			"balance": "78838000000000000000"
		},
		"15ee0fc63ebf1b1fc49d7bb38f8863823a2e17d2": {
			"balance": "1910000000000000000000"
		},
		"6651736fb59b91fee9c93aa0bd6ea2f7b2506180": {
			"balance": "500000000000000000000"
		},
		"361d9ed80b5bd27cf9f1226f26753258ee5f9b3f": {
			"balance": "3530900000000000000000"
		},
		"c9b6b686111691ee6aa197c7231a88dc60bd295d": {
			"balance": "500000000000000000000"
		},
		"e9b4a4853577a9dbcc2e795be0310d1bed28641a": {
			"balance": "1000000000000000000000"
		},
		"36758e049cd98bcea12277a676f9297362890023": {
			"balance": "4000000000000000000000"
		},
		"6bb50813146a9add42ee22038c9f1f7469d47f47": {
			"balance": "200200000000000000000"
		},
		"6de4b581385cf7fc9fe8c77d131fe2ee7724c76a": {
			"balance": "2308840000000000000000"
		},
		"d2a5a024230a57ccc666760b89b0e26cafd189c7": {
			"balance": "49997115000000000000000"
		},
		"65af9087e05167715497c9a5a749189489004def": {
			"balance": "835000000000000000000"
		},
		"ead21c1deccfbf1c5cd96688a2476b69ba07ce4a": {
			"balance": "72800000000000000000"
		},
		"e308435204793764f5fcbe65eb510f5a744a655a": {
			"balance": "200000000000000000000"
		},
		"9376dce2af2ec8dcda741b7e7345664681d93668": {
			"balance": "1000000000000000000000"
		},
		"a1b47c4d0ed6018842e6cfc8630ac3a3142e5e6b": {
			"balance": "20000000000000000000"
		},
		"e2198c8ca1b399f7521561fd5384a7132fba486b": {
			"balance": "1015200000000000000000"
		},
		"92c13fe0d6ce87fd50e03def9fa6400509bd7073": {
			"balance": "40000000000000000000"
		},
		"7517f16c28d132bb40e3ba36c6aef131c462da17": {
			"balance": "18200000000000000000"
		},
		"6a023af57d584d845e698736f130db9db40dfa9a": {
			"balance": "98800000000000000000"
		},
		"1518627b88351fede796d3f3083364fbd4887b0c": {
			"balance": "16000000000000000000000"
		},
		"f5b6e9061a4eb096160777e26762cf48bdd8b55d": {
			"balance": "254030000000000000000"
		},
		"28073efc17d05cab3195c2db332b61984777a612": {
			"balance": "1000000000000000000000"
		},
		"f06a854a3c5dc36d1c49f4c87d6db333b57e4add": {
			"balance": "10000000000000000000000"
		},
		"9225983860a1cb4623c72480ac16272b0c95e5f5": {
			"balance": "2000000000000000000000"
		},
		"5260dc51ee07bddaababb9ee744b393c7f4793a6": {
			"balance": "34040000000000000000"
		},
		"0f127bbf8e311caea2ba502a33feced3f730ba42": {
			"balance": "188000000000000000000"
		},
		"17d521a8d9779023f7164d233c3b6420ffd223ed": {
			"balance": "20000000000000000000"
		},
		"8c2b7d8b608d28b77f5caa9cd645242a823e4cd9": {
			"balance": "1820000000000000000000"
		},
		"6e866d032d405abdd65cf651411d803796c22311": {
			"balance": "2000000000000000000000"
		},
		"dc51b2dc9d247a1d0e5bc36ca3156f7af21ff9f6": {
			"balance": "1000000000000000000000"
		},
		"c84d9bea0a7b9f140220fd8b9097cfbfd5edf564": {
)E" + R"E(
			"balance": "123047000000000000000"
		},
		"ff86e5e8e15b53909600e41308dab75f0e24e46b": {
			"balance": "902400000000000000000"
		},
		"d7164aa261c09ad9b2b5068d453ed8eb6aa13083": {
			"balance": "3000000000000000000000"
		},
		"76aaf8c1ac012f8752d4c09bb46607b6651d5ca8": {
			"balance": "20000000000000000000"
		},
		"41786a10d447f484d33244ccb7facd8b427b5b8c": {
			"balance": "1000000000000000000000"
		},
		"2e0c57b47150f95aa6a7e16ab9b1cbf54328979a": {
			"balance": "100000000000000000000"
		},
		"3f747237806fed3f828a6852eb0867f79027af89": {
			"balance": "1500000000000000000000"
		},
		"a568db4d57e4d67462d733c69a9e0fe26e218327": {
			"balance": "1096140000000000000000"
		},
		"1f88f8a1338fc7c10976abcd3fb8d38554b5ec9c": {
			"balance": "13400000000000000000"
		},
		"d1ea4d72a67b5b3e0f315559f52bd0614d713069": {
			"balance": "2000000000000000000000"
		},
		"bfaeb91067617dcf8b44172b02af615674835dba": {
			"balance": "160661000000000000000"
		},
		"b71a13ba8e95167b80331b52d69e37054fe7a826": {
			"balance": "200000000000000000000"
		},
		"b67a80f170197d96cdcc4ab6cba627b4afa6e12c": {
			"balance": "2400000000000000000000"
		},
		"35af040a0cc2337a76af288154c7561e1a233349": {
			"balance": "1000000000000000000000"
		},
		"c86190904b8d079ec010e462cbffc90834ffaa5c": {
			"balance": "10100000000000000000000"
		},
		"383304dd7a5720b29c1a10f60342219f48032f80": {
			"balance": "5600000000000000000000"
		},
		"191313525238a21c767457a91374f02200c55448": {
			"balance": "116400000000000000000"
		},
		"cc4a2f2cf86cf3e43375f360a4734691195f1490": {
			"balance": "1348127000000000000000"
		},
		"4e020779b5ddd3df228a00cb48c2fc979da6ae38": {
			"balance": "2000000000000000000000"
		},
		"e206fb7324e9deb79e19903496d6961b9be56603": {
			"balance": "100000000000000000000"
		},
		"3ae160e3cd60ae31b9d6742d68e14e76bd96c517": {
			"balance": "30000000000000000000"
		},
		"1f7d8e86d6eeb02545aad90e91327bd369d7d2f3": {
			"balance": "20000000000000000000"
		},
		"68c7d1711b011a33f16f1f55b5c902cce970bdd7": {
			"balance": "152000000000000000000"
		},
		"637be71b3aa815ff453d5642f73074450b64c82a": {
			"balance": "2000000000000000000000"
		},
		"1584a2c066b7a455dbd6ae2807a7334e83c35fa5": {
			"balance": "130000000000000000000"
		},
		"9c05e9d0f0758e795303717e31da213ca157e686": {
			"balance": "1000000000000000000000"
		},
		"4f1a2da54a4c6da19d142412e56e815741db2325": {
			"balance": "100000000000000000000"
		},
		"9a4ca8b82117894e43db72b9fa78f0b9b93ace09": {
			"balance": "50000000000000000000"
		},
		"26c99f8849c9802b83c861217fd07a9e84cdb79d": {
			"balance": "300000000000000000000"
		},
		"45c0d19f0b8e054f9e893836d5ecae7901af2812": {
			"balance": "5000000000000000000000"
		},
		"00dc01cbf44978a42e8de8e436edf94205cfb6ec": {
			"balance": "1458440000000000000000"
		},
		"de7dee220f0457a7187d56c1c41f2eb00ac56021": {
			"balance": "629924000000000000000"
		},
		"1c128bd6cda5fca27575e4b43b3253c8c4172afe": {
			"balance": "2000000000000000000000"
		},
		"666746fb93d1935c5a3c684e725010c4fad0b1d8": {
			"balance": "20000000000000000000"
)E" + R"E(
		},
		"51d78b178d707e396e8710965c4f41b1a1d9179d": {
			"balance": "110600000000000000000"
		},
		"68f7573cd457e14c03fea43e302d30347c10705c": {
			"balance": "5000000000000000000000"
		},
		"9d30cb237bc096f17036fc80dd21ca68992ca2d9": {
			"balance": "30380000000000000000000"
		},
		"fbcfcc4a7b0f26cf26e9f3332132e2fc6a230766": {
			"balance": "8000000000000000000000"
		},
		"b166e37d2e501ae73c84142b5ffb5aa655dd5a99": {
			"balance": "1999000000000000000000"
		},
		"6df24f6685a62f791ba337bf3ff67e91f3d4bc3a": {
			"balance": "2166000000000000000000"
		},
		"92e435340e9d253c00256389f52b067d55974e76": {
			"balance": "268000000000000000000"
		},
		"ea53d26564859d9e90bb0e53b7abf560e0162c38": {
			"balance": "400000000000000000000"
		},
		"e26657f0ed201ea2392c9222b80a7003608ddf30": {
			"balance": "40000000000000000000"
		},
		"f4177a0d85d48b0e264211ce2aa2efd3f1b47f08": {
			"balance": "3593425000000000000000"
		},
		"9d47ba5b4c8505ad8da42934280b61a0e1e8b971": {
			"balance": "100000000000000000000"
		},
		"63c2a3d235e5eeabd0d4a6afdb89d94627396495": {
			"balance": "1241620000000000000000"
		},
		"446a8039cecf9dce4879cbcaf3493bf545a88610": {
			"balance": "7000000000000000000000"
		},
		"7fa37ed67887751a471f0eb306be44e0dbcd6089": {
			"balance": "1060000000000000000000"
		},
		"26d4a16891f52922789217fcd886f7fce296d400": {
			"balance": "2000000000000000000000"
		},
		"487e108502b0b189ef9c8c6da4d0db6261eec6c0": {
			"balance": "1910000000000000000000"
		},
		"7484d26becc1eea8c6315ec3ee0a450117dc86a0": {
			"balance": "12000000000000000000000"
		},
		"ad9e97a0482f353a05c0f792b977b6c7e811fa5f": {
			"balance": "200000000000000000000"
		},
		"2273bad7bc4e487622d175ef7a66988b6a93c4ee": {
			"balance": "20000000000000000000"
		},
		"3b93b16136f11eaf10996c95990d3b2739ccea5f": {
			"balance": "10000000000000000000000"
		},
		"f3f1fa3918ca34e2cf7e84670b1f4d8eca160db3": {
			"balance": "680000000000000000000"
		},
		"88a2154430c0e41147d3c1fee3b3b006f851edbd": {
			"balance": "999972000000000000000"
		},
		"25185f325acf2d64500698f65c769ddf68301602": {
			"balance": "5000000000000000000000"
		},
		"e9cafe41a5e8bbd90ba02d9e06585b4eb546c57f": {
			"balance": "2000000000000000000000"
		},
		"95681cdae69b2049ce101e325c759892cac3f811": {
			"balance": "2857600000000000000000"
		},
		"475066f9ad26655196d5535327bbeb9b7929cb04": {
			"balance": "3040000000000000000000"
		},
		"6685fd2e2544702c360b8bb9ee78f130dad16da5": {
			"balance": "2000000000000000000000"
		},
		"45e68db94c7d0ab7ac41857a71d67147870f4e71": {
			"balance": "400000000000000000000000"
		},
		"4ad95d188d6464709add2555fb4d97fe1ebf311f": {
			"balance": "346000000000000000000"
		},
		"73bedd6fda7ba3272185087b6351fc133d484e37": {
			"balance": "5057200000000000000000"
		},
		"1ea4715504c6af107b0194f4f7b1cb6fcccd6f4b": {
			"balance": "590598000000000000000"
		},
		"77306ffe2e4a8f3ca826c1a249f7212da43aeffd": {
			"balance": "20000000000000000000000"
		},
		"eb453f5a3adddd8ab56750fadb0fe7f94d9c89e7": {
			"balance": "20000000000000000000"
		},
)E" + R"E(
		"7201d1c06920cd397ae8ad869bcda6e47ffb1b5a": {
			"balance": "20000000000000000000"
		},
		"821cb5cd05c7ef909fe1be60733d8963d760dc41": {
			"balance": "4000000000000000000000"
		},
		"496e319592b341eaccd778dda7c8196d54cac775": {
			"balance": "9250000000000000000000"
		},
		"88609e0a465b6e99fce907166d57e9da0814f5c8": {
			"balance": "20000000000000000000000"
		},
		"c7ec62b804b1f69b1e3070b5d362c62fb309b070": {
			"balance": "13068074000000000000000"
		},
		"3eb9ef06d0c259040319947e8c7a6812aa0253d8": {
			"balance": "167000000000000000000"
		},
		"cbf37ff854a2f1ce53934494777892d3ec655782": {
			"balance": "10000000000000000000000"
		},
		"02b1af72339b2a2256389fd64607de24f0de600a": {
			"balance": "2000000000000000000000"
		},
		"a8beb91c2b99c8964aa95b6b4a184b1269fc3483": {
			"balance": "400000000000000000000"
		},
		"922a20c79a1d3a26dd3829677bf1d45c8f672bb6": {
			"balance": "4000000000000000000000"
		},
		"c5843399d150066bf7979c34ba294620368ad7c0": {
			"balance": "200000000000000000000"
		},
		"8cd0cd22e620eda79c0461e896c93c44837e2968": {
			"balance": "2000000000000000000000"
		},
		"6170dd0687bd55ca88b87adef51cfdc55c4dd458": {
			"balance": "2005160000000000000000"
		},
		"eed384ef2d41d9d203974e57c12328ea760e08ea": {
			"balance": "1000000000000000000000"
		},
		"b129a5cb7105fe810bd895dc7206a991a4545488": {
			"balance": "30000000000000000000"
		},
		"3872f48dc5e3f817bc6b2ad2d030fc5e0471193d": {
			"balance": "4000000000000000000000"
		},
		"514b7512c9ae5ea63cbf11715b63f21e18d296c1": {
			"balance": "1999944000000000000000"
		},
		"7ab256b204800af20137fabcc916a23258752501": {
			"balance": "20000000000000000000000"
		},
		"fc66faba277f4b5de64ad45eb19c31e00ced3ed5": {
			"balance": "5640000000000000000000"
		},
		"39824f8bced176fd3ea22ec6a493d0ccc33fc147": {
			"balance": "4000000000000000000000"
		},
		"e338e859fe2e8c15554848b75caecda877a0e832": {
			"balance": "1801800000000000000000"
		},
		"e53c68796212033e4e6f9cff56e19c461eb454f9": {
			"balance": "1000000000000000000000"
		},
		"8461ecc4a6a45eb1a5b947fb86b88069b91fcd6f": {
			"balance": "2000000000000000000000"
		},
		"6b4b99cb3fa9f7b74ce3a48317b1cd13090a1a7a": {
			"balance": "57300000000000000000"
		},
		"97de21e421c37fe4b8025f9a51b7b390b5df7804": {
			"balance": "80000000000000000000000"
		},
		"d25aecd7eb8bd6345b063b5dbd271c77d3514494": {
			"balance": "1820000000000000000000"
		},
		"57b23d6a1adc06c652a779c6a7fb6b95b9fead66": {
			"balance": "200000000000000000000"
		},
		"0d658014a199061cf6b39433140303c20ffd4e5a": {
			"balance": "8200000000000000000000"
		},
		"30eac740e4f02cb56eef0526e5d300322600d03e": {
			"balance": "1970000000000000000000"
		},
		"4eead40aad8c73ef08fc84bc0a92c9092f6a36bf": {
			"balance": "26740000000000000000"
		},
		"30f7d025d16f7bee105580486f9f561c7bae3fef": {
			"balance": "500000000000000000000"
		},
		"0977bfba038a44fb49b03970d8d8cf2cb61f8b25": {
			"balance": "420000000000000000000"
		},
		"b14bbeff70720975dc6191b2a44ff49f2672873c": {
			"balance": "143000000000000000000"
		},
		"d588c3a5df228185d98ee7e60748255cdea68b01": {
)E" + R"E(
			"balance": "4000000000000000000000"
		},
		"225d35faedb391c7bc2db7fa9071160405996d00": {
			"balance": "167774000000000000000"
		},
		"c0e457bd56ec36a1246bfa3230fff38e5926ef22": {
			"balance": "1940000000000000000000"
		},
		"2a9c57fe7b6b138a920d676f3c76b6c2a0eef699": {
			"balance": "9400000000000000000000"
		},
		"36df8f883c1273ec8a171f7a33cfd649b1fe6075": {
			"balance": "227290000000000000000"
		},
		"234f46bab73fe45d31bf87f0a1e0466199f2ebac": {
			"balance": "485000000000000000000"
		},
		"a2e1b8aa900e9c139b3fa122354f6156d92a18b1": {
			"balance": "500000000000000000000"
		},
		"517cd7608e5d0d83a26b717f3603dac2277dc3a4": {
			"balance": "2000000000000000000000"
		},
		"75f7539d309e9039989efe2e8b2dbd865a0df088": {
			"balance": "2460000000000000000000"
		},
		"4b792e29683eb586e394bb33526c6001b397999e": {
			"balance": "600000000000000000000"
		},
		"a34f9d568bf7afd94c2a5b8a5ff55c66c4087999": {
			"balance": "2444000000000000000000"
		},
		"4b31bf41abc75c9ae2cd8f7f35163b6e2b745054": {
			"balance": "382000000000000000000"
		},
		"e35453eef2cc3c7a044d0ac134ba615908fa82ee": {
			"balance": "147510000000000000000"
		},
		"7aa79ac04316cc8d08f20065baa6d4142897d54e": {
			"balance": "1400000000000000000000"
		},
		"f1dc8ac81042c67a9c3c6792b230c46ac016ca10": {
			"balance": "200000000000000000000"
		},
		"2bb366b9edcb0da680f0e10b3b6e28748190d6c3": {
			"balance": "5799400000000000000000"
		},
		"a567770b6ae320bdde50f904d663e746a61dace6": {
			"balance": "2000000000000000000000"
		},
		"d9d42fd13ebd4bf69cac5e9c7e82483ab46dd7e9": {
			"balance": "5348000000000000000000"
		},
		"27830c5f6023afaaf79745676c204a0faccda0ba": {
			"balance": "240000000000000000000"
		},
		"3cb179cb4801a99b95c3b0c324a2bdc101a65360": {
			"balance": "26000000000000000000"
		},
		"976e3ceaf3f1af51f8c29aff5d7fa21f0386d8ee": {
			"balance": "240000000000000000000"
		},
		"752a5ee232612cd3005fb26e5b597de19f776be6": {
			"balance": "5460000000000000000000"
		},
		"7d5aa33fc14b51841a06906edb2bb49c2a117269": {
			"balance": "300048000000000000000"
		},
		"55ca6abe79ea2497f46fdbb830346010fe469cbe": {
			"balance": "5730000000000000000000"
		},
		"6bec311ad05008b4af353c958c40bd06739a3ff3": {
			"balance": "16380000000000000000000"
		},
		"30e9698cf1e08a9d048bd8d8048f28be7ed9409f": {
			"balance": "6685000000000000000000"
		},
		"9afa536b4c66bc38d875c4b30099d9261fdb38eb": {
			"balance": "205981000000000000000"
		},
		"6b63a2dfb2bcd0caec0022b88be30c1451ea56aa": {
			"balance": "809021000000000000000"
		},
		"d07be0f90997caf903c8ac1d53cde904fb190741": {
			"balance": "1000200000000000000000"
		},
		"893cdddf5377f3c751bf2e541120045a47cba101": {
			"balance": "100000000000000000000"
		},
		"c1cdc601f89c0428b31302d187e0dc08ad7d1c57": {
			"balance": "6000000000000000000000"
		},
		"8f8acb107607388479f64baaabea8ff007ada97d": {
			"balance": "27281800000000000000000"
		},
		"88bc43012edb0ea9f062ac437843250a39b78fbb": {
			"balance": "20000000000000000000000"
		},
		"fcfc3a5004d678613f0b36a642269a7f371c3f6a": {
			"balance": "1000000000000000000000"
)E" + R"E(
		},
		"f509557e90183fbf0f0651a786487bcc428ba175": {
			"balance": "194000000000000000000"
		},
		"e3d915eda3b825d6ee4af9328d32ac18ada35497": {
			"balance": "500000000000000000000"
		},
		"f237ef05261c34d79cc22b860de0f17f793c3860": {
			"balance": "200000000000000000000"
		},
		"a3a2e319e7d3a1448b5aa2468953160c2dbcba71": {
			"balance": "2000000000000000000000"
		},
		"3a368efe4ad786e26395ec9fc6ad698cae29fe01": {
			"balance": "632200000000000000000"
		},
		"8e3240b0810e1cf407a500804740cf8d616432a4": {
			"balance": "40309000000000000000"
		},
		"5691dd2f6745f20e22d2e1d1b955aa2903d65656": {
			"balance": "1969606000000000000000"
		},
		"5f93ff832774db5114c55bb4bf44ccf3b58f903f": {
			"balance": "192026650000000000000000"
		},
		"2c1cc6e18c152488ba11c2cc1bcefa2df306abd1": {
			"balance": "1670000000000000000000"
		},
		"bde9786a84e75b48f18e726dd78d70e4af3ed802": {
			"balance": "5730000000000000000000"
		},
		"79551cede376f747e3716c8d79400d766d2e0195": {
			"balance": "46250000000000000000000"
		},
		"49f028395b5a86c9e07f7778630e4c2e3d373a77": {
			"balance": "122735000000000000000"
		},
		"6a3694424c7cc6b8bcd9bccaba540cc1f5df18d7": {
			"balance": "2000000000000000000000"
		},
		"068e29b3f191c812a6393918f71ab933ae6847f2": {
			"balance": "1999944000000000000000"
		},
		"6e64e6129f224e378c0e6e736a7e7a06c211e9ec": {
			"balance": "1000000000000000000000"
		},
		"c4c15318d370c73318cc18bdd466dbaa4c6603bf": {
			"balance": "19700000000000000000"
		},
		"8035bcffaefdeeea35830c497d14289d362023de": {
			"balance": "300000000000000000000"
		},
		"a997dfc7986a27050848fa1c64d7a7d6e07acca2": {
			"balance": "143000000000000000000"
		},
		"2fe13a8d0785de8758a5e41876c36e916cf75074": {
			"balance": "4000000000000000000000"
		},
		"6f24c9af2b763480515d1b0951bb77a540f1e3f9": {
			"balance": "1970000000000000000000"
		},
		"4c23b370fc992bb67cec06e26715b62f0b3a4ac3": {
			"balance": "10000000000000000000000"
		},
		"4ac07673e42f64c1a25ec2fa2d86e5aa2b34e039": {
			"balance": "2000000000000000000000"
		},
		"117db836377fe15455e02c2ebda40b1ceb551b19": {
			"balance": "6000000000000000000000"
		},
		"ef1c0477f1184d60accab374d374557a0a3e10f3": {
			"balance": "152000000000000000000"
		},
		"99fe0d201228a753145655d428eb9fd94985d36d": {
			"balance": "1939268000000000000000"
		},
		"b3731b046c8ac695a127fd79d0a5d5fa6ae6d12e": {
			"balance": "1998000000000000000000"
		},
		"dce30c31f3ca66721ecb213c809aab561d9b52e4": {
			"balance": "2000000000000000000000"
		},
		"ddd69c5b9bf5eb5a39cee7c3341a120d973fdb34": {
			"balance": "1987730000000000000000"
		},
		"216e41864ef98f060da08ecae19ad1166a17d036": {
			"balance": "5730000000000000000000"
		},
		"6a53d41ae4a752b21abed5374649953a513de5e5": {
			"balance": "2000000000000000000000"
		},
		"20dd8fcbb46ea46fe381a68b8ca0ea5be21fe9a5": {
			"balance": "2000000000000000000000"
		},
		"19732bf973055dbd91a4533adaa2149a91d38380": {
			"balance": "2000000000000000000000"
		},
		"51ea1c0934e3d04022ed9c95a087a150ef705e81": {
			"balance": "6280000000000000000000"
		},
)E" + R"E(
		"a0de5c601e696635c698b7ae9ca4539fc7b941ec": {
			"balance": "346150000000000000000"
		},
		"94e1f5cb9b8abace03a1a6428256553b690c2355": {
			"balance": "20000000000000000000"
		},
		"a539b4a401b584dfe0f344b1b422c65543167e2e": {
			"balance": "200000000000000000000"
		},
		"50584d9206a46ce15c301117ee28f15c30e60e75": {
			"balance": "13400000000000000000"
		},
		"856eb204241a87830fb229031343dc30854f581a": {
			"balance": "1000000000000000000000"
		},
		"9dd46b1c6d3f05e29e9c6f037eed9a595af4a9aa": {
			"balance": "500000000000000000000"
		},
		"8925da4549e15155e57a628522cea9dddf627d81": {
			"balance": "1000070000000000000000"
		},
		"a89df34859edd7c820db887740d8ff9e15157c7b": {
			"balance": "2000000000000000000000"
		},
		"ad9f4c890a3b511cee51dfe6cfd7f1093b76412c": {
			"balance": "506600000000000000000"
		},
		"f8c7f34a38b31801da43063477b12b27d0f203ff": {
			"balance": "494800000000000000000"
		},
		"a642501004c90ea9c9ed1998ba140a4cd62c6f5f": {
			"balance": "250543000000000000000"
		},
		"508cf19119db70aa86454253da764a2cb1b2be1a": {
			"balance": "1000000000000000000000"
		},
		"2979741174a8c1ea0b7f9edf658177859417f512": {
			"balance": "461283000000000000000"
		},
		"654f524847b3a6acc0d3d5f1f362b603edf65f96": {
			"balance": "8000000000000000000000"
		},
		"5cf18fa7c8a7c0a2b3d5efd1990f64ddc569242c": {
			"balance": "1000000000000000000000"
		},
		"17e82e7078dc4fd9e879fb8a50667f53a5c54591": {
			"balance": "200000000000000000000"
		},
		"8b07d050754dc9ba230db01c310afdb5395aa1b3": {
			"balance": "118080000000000000000"
		},
		"5f77a107ab1226b3f95f10ee83aefc6c5dff3edc": {
			"balance": "500000000000000000000"
		},
		"475a6193572d4a4e59d7be09cb960ddd8c530e2f": {
			"balance": "667323000000000000000"
		},
		"6470a4f92ec6b0fccd01234fa59023e9ff1f3aac": {
			"balance": "3000000000000000000000"
		},
		"2fbcef3384d420e4bf61a0669990bc7054f1a5af": {
			"balance": "2000000000000000000000"
		},
		"bbabf6643beb4bd01c120bd0598a0987d82967d1": {
			"balance": "3342500000000000000000"
		},
		"41a2f2e6ecb86394ec0e338c0fc97e9c5583ded2": {
			"balance": "2009400000000000000000"
		},
		"fb9473cf7712350a1fa0395273fc80560752e4fb": {
			"balance": "123300000000000000000"
		},
		"38b2197106123387a0d4de368431a8bacdda30e2": {
			"balance": "20000000000000000000"
		},
		"5ed56115bd6505a88273df5c56839470d24a2db7": {
			"balance": "65601000000000000000"
		},
		"523f6d64690fdacd942853591bb0ff20d3656d95": {
			"balance": "1820000000000000000000"
		},
		"55caff4bba04d220c9a5d2018672ec85e31ef83e": {
			"balance": "2000000000000000000000"
		},
		"65af8d8b5b1d1eedfa77bcbc96c1b133f83306df": {
			"balance": "98000000000000000000"
		},
		"7456c5b2c5436e3e571008933f1805ccfe34e9ec": {
			"balance": "1000000000000000000000"
		},
		"a6eebbe464d39187bf80ca9c13d72027ec5ba8be": {
			"balance": "3000000000000000000000"
		},
		"dd35cfdbcb993395537aecc9f59085a8d5ddb6f5": {
			"balance": "1000000000000000000000"
		},
		"98e2b6d606fd2d6991c9d6d4077fdf3fdd4585da": {
			"balance": "901520000000000000000"
		},
		"860f5ffc10de767ded807f71e861d647dfd219b1": {
)E" + R"E(
			"balance": "10000000000000000000000"
		},
		"1a644a50cbc2aee823bd2bf243e825be4d47df02": {
			"balance": "100007000000000000000"
		},
		"a8455b411765d6901e311e726403091e42c56683": {
			"balance": "3380000000000000000000"
		},
		"3a86ee94862b743dd34f410969d94e2c5652d4ad": {
			"balance": "201610000000000000000"
		},
		"a57360f002e0d64d2d74457d8ca4857ee00bcddf": {
			"balance": "335780000000000000000"
		},
		"e59b3bd300893f97233ef947c46f7217e392f7e9": {
			"balance": "1000000000000000000000"
		},
		"9f3a74fd5e7edcc1162993171381cbb632b7cff0": {
			"balance": "10000000000000000000000"
		},
		"675d5caa609bf70a18aca580465d8fb7310d1bbb": {
			"balance": "20000000000000000000000"
		},
		"77f609ca8720a023262c55c46f2d26fb3930ac69": {
			"balance": "17300000000000000000"
		},
		"f8ac4a39b53c11307820973b441365cffe596f66": {
			"balance": "2000000000000000000000"
		},
		"112634b4ec30ff786e024159f796a57939ea144e": {
			"balance": "1999944000000000000000"
		},
		"49d2c28ee9bc545eaaf7fd14c27c4073b4bb5f1a": {
			"balance": "1474134000000000000000"
		},
		"91cc46aa379f856a6640dccd5a648a7902f849d9": {
			"balance": "200000000000000000000"
		},
		"b46440c797a556e04c7d9104660491f96bb076bf": {
			"balance": "14900000000000000000"
		},
		"e5968797468ef767101b761d431fce14abffdbb4": {
			"balance": "8040000000000000000000"
		},
		"c0895efd056d9a3a81c3da578ada311bfb9356cf": {
			"balance": "200000000000000000000"
		},
		"76846f0de03b5a76971ead298cdd08843a4bc6c6": {
			"balance": "15500000000000000000"
		},
		"5f708eaf39d823946c51b3a3e9b7b3c003e26341": {
			"balance": "1820000000000000000000"
		},
		"24f7450ddbf18b020feb1a2032d9d54b633edf37": {
			"balance": "50000000000000000000"
		},
		"cae3a253bcb2cf4e13ba80c298ab0402da7c2aa0": {
			"balance": "5400000000000000000000"
		},
		"91e8810652e8e6161525d63bb7751dc20f676076": {
			"balance": "725000000000000000000"
		},
		"543629c95cdef428ad37d453ca9538a9f90900ac": {
			"balance": "43250000000000000000000"
		},
		"6e79edd4845b076e4cd88d188b6e432dd93f35aa": {
			"balance": "955000000000000000000"
		},
		"bd325d4029e0d8729f6d399c478224ae9e7ae41e": {
			"balance": "3880000000000000000000"
		},
		"42cecfd2921079c2d7df3f08b07aa3beee5e219a": {
			"balance": "1000000000000000000000"
		},
		"3690246ba3c80679e22eac4412a1aefce6d7cd82": {
			"balance": "20000000000000000000000"
		},
		"577aeee8d4bc08fc97ab156ed57fb970925366be": {
			"balance": "333046000000000000000"
		},
		"fe00bf439911a553982db638039245bcf032dbdc": {
			"balance": "394000000000000000000"
		},
		"91f624b24a1fa5a056fe571229e7379db14b9a1e": {
			"balance": "11999974000000000000000"
		},
		"f206d328e471d0117b246d2a4619827709e96df3": {
			"balance": "3001000000000000000000"
		},
		"073f1ed1c9c3e9c52a9b0249a5c1caa0571fdf05": {
			"balance": "70400000000000000000"
		},
		"f56048dd2181d4a36f64fcecc6215481e42abc15": {
			"balance": "200000000000000000000"
		},
		"ef76a4cd8febcbc9b818f17828f8d93473f3f3cb": {
			"balance": "4000000000000000000000"
		},
		"1031e0ecb54985ae21af1793950dc811888fde7c": {
			"balance": "20000000000000000000"
)E" + R"E(
		},
		"8e0fee38685a94aabcd7ce857b6b1409824f75b8": {
			"balance": "500000000000000000000"
		},
		"f0cbef84e169630098d4e301b20208ef05846ac9": {
			"balance": "259084000000000000000"
		},
		"bbca65b3266ea2fb73a03f921635f912c7bede00": {
			"balance": "1970000000000000000000"
		},
		"0aec2e426ed6cc0cf3c249c1897eac47a7faa9bd": {
			"balance": "200000000000000000000"
		},
		"b8f30758faa808dbc919aa7b425ec922b93b8129": {
			"balance": "1000076000000000000000"
		},
		"936dcf000194e3bff50ac5b4243a3ba014d661d8": {
			"balance": "10000000000000000000000"
		},
		"b14ddb0386fb606398b8cc47565afae00ff1d66a": {
			"balance": "2973024000000000000000"
		},
		"2ec95822eb887bc113b4712a4dfd7f13b097b5e7": {
			"balance": "1000000000000000000000"
		},
		"0136a5af6c3299c6b5f005fdaddb148c070b299b": {
			"balance": "20368000000000000000"
		},
		"37cb868d2c3f95b257611eb34a4188d58b749802": {
			"balance": "2000000000000000000000"
		},
		"cd7f09d7ed66d0c38bc5ad4e32b7f2b08dc1b30d": {
			"balance": "1148000000000000000000"
		},
		"b5fa8184e43ed3e0b8ab91216461b3528d84fd09": {
			"balance": "2680000000000000000000"
		},
		"3dbf0dbfd77890800533f09dea8301b9f025d2a6": {
			"balance": "1000000000000000000000"
		},
		"b553d25d6b5421e81c2ad05e0b8ba751f8f010e3": {
			"balance": "2000000000000000000000"
		},
		"dbf8b13967f55125272de0562536c450ba5655a0": {
			"balance": "2046830000000000000000"
		},
		"0f6e840a3f2a24647d8e43e09d45c7c335df4248": {
			"balance": "2500000000000000000000"
		},
		"fa2fd29d03fee9a07893df3a269f56b72f2e1e64": {
			"balance": "10000000000000000000000"
		},
		"8b57b2bc83cc8d4de331204e893f2f3b1db1079a": {
			"balance": "40000000000000000000"
		},
		"7f541491d2ac00d2612f94aa7f0bcb014651fbd4": {
			"balance": "376000000000000000000"
		},
		"4f4a9be10cd5d3fb5de48c17be296f895690645b": {
			"balance": "40000000000000000000000"
		},
		"45d1c9eedf7cab41a779057b79395f5428d80528": {
			"balance": "2000000000000000000000"
		},
		"662334814724935b7931ddca6100e00d467727cd": {
			"balance": "637000000000000000000"
		},
		"2c52c984102ee0cd3e31821b84d408930efa1ac7": {
			"balance": "2000000000000000000000"
		},
		"000d836201318ec6899a67540690382780743280": {
			"balance": "200000000000000000000"
		},
		"81498ca07b0f2f17e8bbc7e61a7f4ae7be66b78b": {
			"balance": "101600000000000000000"
		},
		"7860a3de38df382ae4a4dce18c0c07b98bce3dfa": {
			"balance": "1000000000000000000000"
		},
		"5e8e4df18cf0af770978a8df8dac90931510a679": {
			"balance": "2000000000000000000000"
		},
		"05d68dad61d3bbdfb3f779265c49474aff3fcd30": {
			"balance": "39399000000000000000"
		},
		"96eafbf2fb6f4db9a436a74c45b5654452e23819": {
			"balance": "20000000000000000000"
		},
		"d7d7f2caa462a41b3b30a34aeb3ba61010e2626f": {
			"balance": "2000000000000000000000"
		},
		"0b71f554122469ef978e2f1fefd7cbb410982772": {
			"balance": "3880000000000000000000"
		},
		"504666ce8931175e11a5ed11c1dcaa06e57f4e66": {
			"balance": "11792000000000000000000"
		},
		"d00f067286c0fbd082f9f4a61083ec76deb3cee6": {
			"balance": "1000000000000000000000"
		},
)E" + R"E(
		"02e4cb22be46258a40e16d4338d802fffd00c151": {
			"balance": "379786000000000000000"
		},
		"1c13d38637b9a47ce79d37a86f50fb409c060728": {
			"balance": "1337000000000000000000"
		},
		"e30212b2011bb56bdbf1bc35690f3a4e0fd905ea": {
			"balance": "8022000000000000000000"
		},
		"1df6911672679bb0ef3509038c0c27e394fdfe30": {
			"balance": "540000000000000000000"
		},
		"2b8fe4166e23d11963c0932b8ade8e0145ea0770": {
			"balance": "43250000000000000000000"
		},
		"6509eeb1347e842ffb413e37155e2cbc738273fd": {
			"balance": "2000000000000000000000"
		},
		"8b7e9f6f05f7e36476a16e3e7100c9031cf404af": {
			"balance": "1000000000000000000000"
		},
		"bec8caf7ee49468fee552eff3ac5234eb9b17d42": {
			"balance": "2000000000000000000000"
		},
		"38898bbb4553e00bbfd0cf268b2fc464d154add5": {
			"balance": "320000000000000000000"
		},
		"cbb3189e4bd7f45f178b1c30c76e26314d4a4b0a": {
			"balance": "295007000000000000000"
		},
		"be1cd7f4c472070968f3bde268366b21eeea8321": {
			"balance": "4300000000000000000000"
		},
		"976a18536af41874426308871bcd1512a775c9f8": {
			"balance": "10000000000000000000000"
		},
		"e9c758f8da41e3346e4350e5ac3976345c6c1082": {
			"balance": "1930050000000000000000"
		},
		"64ec8a5b743f3479e707dae9ee20ddaa4f40f1d9": {
			"balance": "200000000000000000000"
		},
		"9e01765aff08bc220550aca5ea2e1ce8e5b09923": {
			"balance": "1000000000000000000000"
		},
		"ba0f39023bdb29eb1862a9f9059cab5d306e662f": {
			"balance": "2000000000000000000000"
		},
		"2baf8d6e221174124820ee492b9459ec4fadafbb": {
			"balance": "2000000000000000000000"
		},
		"655d5cd7489629e2413c2105b5a172d933c27af8": {
			"balance": "4040060000000000000000"
		},
		"badc2aef9f5951a8d78a6b35c3d0b3a4e6e2e739": {
			"balance": "6000000000000000000000"
		},
		"e64f6e1d6401b56c076b64a1b0867d0b2f310d4e": {
			"balance": "51570000000000000000"
		},
		"7a8563867901206f3f2bf0fa3e1c8109cabccd85": {
			"balance": "137000000000000000000"
		},
		"d17fbe22d90462ed37280670a2ea0b3086a0d6d6": {
			"balance": "199955000000000000000"
		},
		"e96d7d4cdd15553a4e4d316d6d6480ca3cea1e38": {
			"balance": "12200000000000000000000"
		},
		"f04d2c91efb6e9c45ffbe74b434c8c5f2b028f1f": {
			"balance": "1000000000000000000000"
		},
		"81164deb10814ae08391f32c08667b6248c27d7a": {
			"balance": "394000000000000000000"
		},
		"7f5ae05ae0f8cbe5dfe721f044d7a7bef4c27997": {
			"balance": "60000000000000000000"
		},
		"c982586d63b0d74c201b1af8418372e30c7616be": {
			"balance": "100000000000000000000"
		},
		"64cf0935bf19d2cebbecd8780d27d2e2b2c34166": {
			"balance": "1970000000000000000000"
		},
		"cd566ad7b883f01fd3998a9a58a9dee4724ddca5": {
			"balance": "58848000000000000000"
		},
		"9da609fa3a7e6cf2cc0e70cdabe78dc4e382e11e": {
			"balance": "1200000000000000000000"
		},
		"0d69100c395ce6c5eaadf95d05d872837ededd21": {
			"balance": "400000000000000000000"
		},
		"fe91eccf2bd566afa11696c5049fa84c69630a52": {
			"balance": "1940000000000000000000"
		},
		"005d0ee8155ec0a6ff6808552ca5f16bb5be323a": {
			"balance": "197000000000000000000"
		},
		"3e5cb8928c417825c03a3bfcc52183e5c91e42d7": {
)E" + R"E(
			"balance": "4264790000000000000000"
		},
		"9c1b771f09af882af0643083de2aa79dc097c40e": {
			"balance": "2480000000000000000000"
		},
		"eba388b0da27c87b1cc0eac6c57b2c5a0b459c1a": {
			"balance": "6800000000000000000000"
		},
		"7529f3797bb6a20f7ea6492419c84c867641d81c": {
			"balance": "2000000000000000000000"
		},
		"532a7da0a5ad7407468d3be8e07e69c7dd64e861": {
			"balance": "500000000000000000000"
		},
		"de82cc8d4a1bb1d9434392965b3e80bad3c03d4f": {
			"balance": "1477500000000000000000"
		},
		"4a82694fa29d9e213202a1a209285df6e745c209": {
			"balance": "4000000000000000000000"
		},
		"3e53ff2107a8debe3328493a92a586a7e1f49758": {
			"balance": "23143470000000000000000"
		},
		"b2ddb786d3794e270187d0451ad6c8b79e0e8745": {
			"balance": "400000000000000000000"
		},
		"6ebcf9957f5fc5e985add475223b04b8c14a7aed": {
			"balance": "1730000000000000000000"
		},
		"c5c7590b5621ecf8358588de9b6890f2626143f1": {
			"balance": "3000000000000000000000"
		},
		"ae4f122e35c0b1d1e4069291457c83c07f965fa3": {
			"balance": "1000000000000000000000"
		},
		"47885ababedf4d928e1c3c71d7ca40d563ed595f": {
			"balance": "1820000000000000000000"
		},
		"78ce3e3d474a8a047b92c41542242d0a08c70f99": {
			"balance": "10000000000000000000000"
		},
		"6134d942f037f2cc3d424a230c603d67abd3edf7": {
			"balance": "2000000000000000000000"
		},
		"1360e87df24c69ee6d51c76e73767ffe19a2131c": {
			"balance": "92000000000000000000"
		},
		"5fd1c3e31778276cb42ea740f5eae9c641dbc701": {
			"balance": "194000000000000000000"
		},
		"98397342ec5f3d4cb877e54ef5d6f1d366731bd4": {
			"balance": "5910000000000000000000"
		},
		"6d4b5c05d06a20957e1748ab6df206f343f92f01": {
			"balance": "10020475000000000000000"
		},
		"e6115b13f9795f7e956502d5074567dab945ce6b": {
			"balance": "100000000000000000000000"
		},
		"23730c357a91026e44b1d0e2fc2a51d071d8d77b": {
			"balance": "4000000000000000000000"
		},
		"fae881937047895a660cf229760f27e66828d643": {
			"balance": "182000000000000000000"
		},
		"ff3ef6ba151c21b59986ae64f6e8228bc9a2c733": {
			"balance": "2000000000000000000000"
		},
		"dfbd4232c17c407a980db87ffbcda03630e5c459": {
			"balance": "553150000000000000000"
		},
		"4429a29fee198450672c0c1d073162250bec6474": {
			"balance": "999200000000000000000"
		},
		"7e8f96cc29f57b0975120cb593b7dd833d606b53": {
			"balance": "197000000000000000000"
		},
		"5ed3f1ebe2ae6756b5d8dc19cad02c419aa5778b": {
			"balance": "0"
		},
		"daa776a6754469d7b9267a89b86725e740da0fa0": {
			"balance": "1970000000000000000000"
		},
		"139e479764b499d666208c4a8a047a97043163dd": {
			"balance": "598880000000000000000"
		},
		"5ad5e420755613886f35aa56ac403eebdfe4b0d0": {
			"balance": "80000000000000000000000"
		},
		"3fe801e61335c5140dc7eda2ef5204460a501230": {
			"balance": "2000000000000000000000"
		},
		"ce8a6b6d5033b1498b1ffeb41a41550405fa03a2": {
			"balance": "4000000000000000000000"
		},
		"26c2ffc30efdc5273e76183a16c2698d6e531286": {
			"balance": "776000000000000000000"
		},
		"71ec3aec3f8f9221f9149fede06903a0f9a232f2": {
			"balance": "200000000000000000000"
)E" + R"E(
		},
		"ef35f6d4b1075e6aa139151c974b2f4658f70538": {
			"balance": "1111111000000000000000"
		},
		"26a68eab905a8b3dce00e317308225dab1b9f6b8": {
			"balance": "1980000000000000000000"
		},
		"63f5b53d79bf2e411489526530223845fac6f601": {
			"balance": "30000000000000000000000"
		},
		"481115296ab7db52492ff7b647d63329fb5cbc6b": {
			"balance": "16100000000000000000000"
		},
		"f19f193508393e4d2a127b20b2031f39c82581c6": {
			"balance": "3500088000000000000000"
		},
		"500e34cde5bd9e2b71bb92d7cf55eee188d5fa0c": {
			"balance": "5348000000000000000000"
		},
		"65ea67ad3fb56ad5fb94387dd38eb383001d7c68": {
			"balance": "100000000000000000000"
		},
		"7f9f9b56e4289dfb58e70fd5f12a97b56d35c6a5": {
			"balance": "1970000000000000000000"
		},
		"60be6f953f2a4d25b6256ffd2423ac1438252e4e": {
			"balance": "150000000000000000000"
		},
		"ac1dfc984b71a19929a81d81f04a7cbb14073703": {
			"balance": "600000000000000000000"
		},
		"a3c14ace28b192cbb062145fcbbd5869c67271f6": {
			"balance": "8000000000000000000000"
		},
		"2da76b7c39b420e388ba2c1020b0856b0270648a": {
			"balance": "2000000000000000000000"
		},
		"622be4b45495fcd93143efc412d699d6cdc23dc5": {
			"balance": "17300000000000000000"
		},
		"d3f873bd9956135789ab00ebc195b922e94b259d": {
			"balance": "2000000000000000000000"
		},
		"975f3764e97bbccf767cbd3b795ba86d8ba9840e": {
			"balance": "346000000000000000000"
		},
		"fc39be41094b1997d2169e8264c2c3baa6c99bc4": {
			"balance": "2000000000000000000000"
		},
		"12ffc1128605cb0c13709a7290506f2690977193": {
			"balance": "3340000000000000000000"
		},
		"9b1168de8ab64b47552f3389800a9cc08b4666cf": {
			"balance": "1730000000000000000000"
		},
		"9f1aa8fcfc89a1a5328cbd6344b71f278a2ca4a0": {
			"balance": "500000000000000000000"
		},
		"505a33a18634dd4800693c67f48a1d693d4833f8": {
			"balance": "7252000000000000000000"
		},
		"d08fc09a0030fd0928cd321198580182a76aae9f": {
			"balance": "1000000000000000000000"
		},
		"6acddca3cd2b4990e25cd65c24149d0912099e79": {
			"balance": "3000037000000000000000"
		},
		"397a6ef8763a18f00fac217e055c0d3094101011": {
			"balance": "2000000000000000000000"
		},
		"4e0bd32473c4c51bf25654def69f797c6b29a232": {
			"balance": "1600930000000000000000"
		},
		"28d8c35fb7eea622582135e3ad47a227c9a663bd": {
			"balance": "18200000000000000000"
		},
		"f96488698590dc3b2c555642b871348dfa067ad5": {
			"balance": "500000000000000000000"
		},
		"4eebe80cb6f3ae5904f6f4b28d907f907189fcab": {
			"balance": "1999944000000000000000"
		},
		"8d1abd897dacd4312e18080c88fb9647eab44052": {
			"balance": "216000000000000000000"
		},
		"457029c469c4548d168cec3e65872e4428d42b67": {
			"balance": "2000000000000000000000"
		},
		"1296acded1e063af39fe8ba0b4b63df789f70517": {
			"balance": "100014000000000000000"
		},
		"71762c63678c18d1c6378ce068e666381315147e": {
			"balance": "2000000000000000000000"
		},
		"6cc1c878fa6cde8a9a0b8311247e741e4642fe6d": {
			"balance": "985000000000000000000"
		},
		"8d9ed7f4553058c26f7836a3802d3064eb1b363d": {
			"balance": "90000000000000000000"
		},
)E" + R"E(
		"5032e4bcf7932b49fdba377b6f1499636513cfc3": {
			"balance": "100000000000000000000"
		},
		"462b678b51b584f3ed7ada070b5cd99c0bf7b87f": {
			"balance": "100000000000000000000"
		},
		"c8aa49e3809f0899f28ab57e6743709d58419033": {
			"balance": "880000000000000000000"
		},
		"01b1cae91a3b9559afb33cdc6d689442fdbfe037": {
			"balance": "200000000000000000000"
		},
		"b1043004ec1941a8cf4f2b00b15700ddac6ff17e": {
			"balance": "1000000000000000000000"
		},
		"5ba2c6c35dfaec296826591904d544464aeabd5e": {
			"balance": "20000000000000000000"
		},
		"b32400fd13c5500917cb037b29fe22e7d5228f2d": {
			"balance": "40000000000000000000000"
		},
		"d59d92d2c8701980cc073c375d720af064743c0c": {
			"balance": "19000000000000000000000"
		},
		"11dd6185d9a8d73ddfdaa71e9b7774431c4dfec2": {
			"balance": "1000000000000000000000"
		},
		"d4cb21e590c5a0e06801366aff342c7d7db16424": {
			"balance": "494000000000000000000"
		},
		"5b6d55f6712967405c659129f4b1de09acf2cb7b": {
			"balance": "267400000000000000000"
		},
		"6179979907fe7f037e4c38029d60bcbab832b3d6": {
			"balance": "1610000000000000000000"
		},
		"33c407133b84b3ca4c3ded1f4658900c38101624": {
			"balance": "2800000000000000000000"
		},
		"cd2a36d753e9e0ed012a584d716807587b41d56a": {
			"balance": "261400000000000000000"
		},
		"8155fa6c51eb31d808412d748aa086105018122f": {
			"balance": "1880000000000000000000"
		},
		"3ecc8e1668dde995dc570fe414f44211c534a615": {
			"balance": "2000000000000000000000"
		},
		"d6395db5a4bb66e60f4cfbcdf0057bb4d97862e2": {
			"balance": "910000000000000000000"
		},
		"b6fb39786250081426a342c70d47ee521e5bc563": {
			"balance": "15000000000000000000000"
		},
		"510eda5601499a0d5e1a006bfffd833672f2e267": {
			"balance": "2000000000000000000000"
		},
		"98c19dba810ba611e68f2f83ee16f6e7744f0c1f": {
			"balance": "200000000000000000000"
		},
		"34ff26eb60a8d1a95a489fae136ee91d4e58084c": {
			"balance": "600000000000000000000"
		},
		"6ad90be252d9cd464d998125fab693060ba8e429": {
			"balance": "4000000000000000000000"
		},
		"038323b184cff7a82ae2e1bda7793fe4319ca0bf": {
			"balance": "20000000000000000000000"
		},
		"dc5305b4020a06b49d657c7ca34c35c91c5f2c56": {
			"balance": "7045990000000000000000"
		},
		"c9c80dc12e7bab86e949d01e4c3ed35f2b9bba5f": {
			"balance": "2000000000000000000000"
		},
		"7beb81fb2f5e91526b2ac9795e76c69bcff04bc0": {
			"balance": "69400000000000000000000"
		},
		"b8bc9bca7f71b4ed12e620438d620f53c114342f": {
			"balance": "500000000000000000000"
		},
		"d288e7cb7ba9f620ab0f7452e508633d1c5aa276": {
			"balance": "4000000000000000000000"
		},
		"a2e460a989cb15565f9ecca7d121a18e4eb405b6": {
			"balance": "2000000000000000000000"
		},
		"7489cc8abe75cda4ef0d01cef2605e47eda67ab1": {
			"balance": "133700000000000000000"
		},
		"38b403fb1fb7c14559a2d6f6564a5552bca39aff": {
			"balance": "2000000000000000000000"
		},
		"e55c80520a1b0f755b9a2cd3ce214f7625653e8a": {
			"balance": "2000000000000000000000"
		},
		"451b7070259bdba27100e36e23428a53dfe304e9": {
			"balance": "13370000000000000000"
		},
		"8b5c914b128bf1695c088923fa467e7911f351fa": {
)E" + R"E(
			"balance": "98500000000000000000"
		},
		"17df49518d73b129f0da36b1c9b40cb66420fdc7": {
			"balance": "10000000000000000000000"
		},
		"c1950543554d8a713003f662bb612c10ad4cdf21": {
			"balance": "18200000000000000000"
		},
		"fa7606435b356cee257bd2fcd3d9eacb3cd1c4e1": {
			"balance": "100000000000000000000"
		},
		"e0bad98eee9698dbf6d76085b7923de5754e906d": {
			"balance": "167000000000000000000"
		},
		"ce53c8cdd74296aca987b2bc19c2b875a48749d0": {
			"balance": "3000000000000000000000"
		},
		"d0c55abf976fdc3db2afe9be99d499484d576c02": {
			"balance": "1000000000000000000000"
		},
		"238a6b7635252f5244486c0af0a73a207385e039": {
			"balance": "1370000000000000000000"
		},
		"ceb389381d48a8ae4ffc483ad0bb5e204cfdb1ec": {
			"balance": "740745000000000000000"
		},
		"3847667038f33b01c1cc795d8daf5475eff5a0d4": {
			"balance": "728330000000000000000"
		},
		"a08d215b5b6aac4861a281ac7e400b78fef04cbf": {
			"balance": "20000000000000000000"
		},
		"2d0dec51a6e87330a6a8fa2a0f65d88d4abcdf73": {
			"balance": "185000000000000000000"
		},
		"9e8f64ddcde9b8b451bafaa235a9bf511a25ac91": {
			"balance": "2674000000000000000000"
		},
		"ddac6bf4bbdd7d597d9c686d0695593bedccc7fa": {
			"balance": "865000000000000000000"
		},
		"22e15158b5ee3e86eb0332e3e6a9ac6cd9b55ecd": {
			"balance": "160000000000000000000"
		},
		"3aea4e82d2400248f99871a41ca257060d3a221b": {
			"balance": "1000000000000000000000"
		},
		"fb126f0ec769f49dcefca2f200286451583084b8": {
			"balance": "5013750000000000000000"
		},
		"1b8bd6d2eca20185a78e7d98e8e185678dac4830": {
			"balance": "16700000000000000000000"
		},
		"664cd67dccc9ac8228b45c55db8d76550b659cdc": {
			"balance": "394000000000000000000"
		},
		"553f37d92466550e9fd775ae74362df030179132": {
			"balance": "2000000000000000000000"
		},
		"730d8763c6a4fd824ab8b859161ef7e3a96a1200": {
			"balance": "20000000000000000000000"
		},
		"04c2c64bb54c3eccd05585e10ec6f99a0cdb01a3": {
			"balance": "100000000000000000000"
		},
		"f1624d980b65336feac5a6d54125005cfcf2aacb": {
			"balance": "2000000000000000000000"
		},
		"0b7fc9ddf70576f6330669eaaa71b6a831e99528": {
			"balance": "140000000000000000000"
		},
		"fa2bbca15d3fe39f8a328e91f90da14f7ac6253d": {
			"balance": "200000000000000000000"
		},
		"07feef54c136850829badc4b49c3f2a73c89fb9e": {
			"balance": "118200000000000000000"
		},
		"3703350c4d6fe337342cddc65bf1e2386bf3f9b2": {
			"balance": "2020000000000000000000"
		},
		"6d7d1c949511f88303808c60c5ea0640fcc02683": {
			"balance": "10000000000000000000000"
		},
		"34fa7792bad8bbd7ff64056214a33eb6600c1ea8": {
			"balance": "50000000000000000000"
		},
		"994cc2b5227ec3cf048512467c41b7b7b748909f": {
			"balance": "2000000000000000000000"
		},
		"08da3a7a0f452161cfbcec311bb68ebfdee17e88": {
			"balance": "2000000000000000000000"
		},
		"bbb4ee1d82f2e156442cc93338a2fc286fa28864": {
			"balance": "1370000000000000000000"
		},
		"7a2dfc770e24368131b7847795f203f3d50d5b56": {
			"balance": "11400000000000000000000"
		},
		"7cef4d43aa417f9ef8b787f8b99d53f1fea1ee88": {
			"balance": "1910000000000000000000"
)E" + R"E(
		},
		"c6a30ef5bb3320f40dc5e981230d52ae3ac19322": {
			"balance": "182000000000000000000"
		},
		"6a74844d8e9cb5581c45079a2e94462a6cee8821": {
			"balance": "1082970000000000000000"
		},
		"c3110be01dc9734cfc6e1ce07f87d77d1345b7e1": {
			"balance": "4999998000000000000000"
		},
		"aeb916ebf49d0f86c13f7331cef19e129937512d": {
			"balance": "599908000000000000000"
		},
		"3e5abd09ce5af7ba8487c359e0f2a93a986b0b18": {
			"balance": "10000000000000000000000"
		},
		"cdd60d73efaad873c9bbfb178ca1b7105a81a681": {
			"balance": "32000000000000000000"
		},
		"31eb123c95c82bf685ace7a75a1881a289efca10": {
			"balance": "920034000000000000000"
		},
		"86e8670e27598ea09c3899ab7711d3b9fe901c17": {
			"balance": "200000000000000000000"
		},
		"a144f6b60f72d64a21e330dadb62d8990ade2b09": {
			"balance": "1000000000000000000000"
		},
		"68883e152e5660fee59626e7e3b4f05110e6222f": {
			"balance": "54683300000000000000000"
		},
		"fe4249127950e2f896ec0e7e2e3d055aab10550f": {
			"balance": "668500000000000000000"
		},
		"403d53cf620f0922b417848dee96c190b5bc8271": {
			"balance": "9850000000000000000000"
		},
		"bec2e6de39c07c2bae556acfbee2c4728b9982e3": {
			"balance": "573000000000000000000"
		},
		"f3c4716d1ee5279a86d0163a14618181e16136c7": {
			"balance": "1000000000000000000000"
		},
		"e38ef28a5ed984a7db24a1ae782dfb87f397dfc6": {
			"balance": "143000000000000000000"
		},
		"30fbe5885f9fcce9ea5edb82ed4a1196dd259aed": {
			"balance": "5200000000000000000000"
		},
		"48bf14d7b1fc84ebf3c96be12f7bce01aa69b03e": {
			"balance": "120000000000000000000"
		},
		"b8d5c324a8209d7c8049d0d4aede02ba80ab578b": {
			"balance": "16889329000000000000000"
		},
		"43d5a71ce8b8f8ae02b2eaf8eaf2ca2840b93fb6": {
			"balance": "6000000000000000000000"
		},
		"f9a59c3cc5ffacbcb67be0fc7256f64c9b127cb4": {
			"balance": "2000000000000000000000"
		},
		"0e21af1b8dbf27fcf63f37e047b87a825cbe7c27": {
			"balance": "3000000000000000000000"
		},
		"1c35aab688a0cd8ef82e76541ba7ac39527f743b": {
			"balance": "500000000000000000000"
		},
		"91ac5cfe67c54aa7ebfba448666c461a3b1fe2e1": {
			"balance": "401880000000000000000"
		},
		"4ba53ab549e2016dfa223c9ed5a38fad91288d07": {
			"balance": "1400000000000000000000"
		},
		"99a4de19ded79008cfdcd45d014d2e584b8914a8": {
			"balance": "1500000000000000000000"
		},
		"4adbf4aae0e3ef44f7dd4d8985cfaf096ec48e98": {
			"balance": "150000000000000000000"
		},
		"9a633fcd112cceeb765fe0418170732a9705e79c": {
			"balance": "18200000000000000000"
		},
		"292f228b0a94748c8eec612d246f989363e08f08": {
			"balance": "185000000000000000000"
		},
		"9f3497f5ef5fe63095836c004eb9ce02e9013b4b": {
			"balance": "633424000000000000000"
		},
		"0e6dfd553b2e873d2aec15bd5fbb3f8472d8d394": {
			"balance": "12000000000000000000000"
		},
		"74ebf4425646e6cf81b109ce7bf4a2a63d84815f": {
			"balance": "40000000000000000000"
		},
		"8ce5e3b5f591d5eca38abf228f2e3c35134bdac0": {
			"balance": "2319920000000000000000"
		},
		"90c41eba008e20cbe927f346603fc88698125969": {
			"balance": "42000000000000000000"
		},
)E" + R"E(
		"382ba76db41b75606dd48a48f0137e9174e031b6": {
			"balance": "20000000000000000000"
		},
		"5d24bdbc1c47f0eb83d128cae48ac33c4817e91f": {
			"balance": "1000000000000000000000"
		},
		"a64e5ffb704c2c9139d77ef61d8cdfa31d7a88e9": {
			"balance": "143000000000000000000"
		},
		"a18360e985f2062e8f8efe02ad2cbc91ad9a5aad": {
			"balance": "3000000000000000000000"
		},
		"d251f903ae18727259eee841a189a1f569a5fd76": {
			"balance": "10000000000000000000000"
		},
		"efa6b1f0db603537826891b8b4bc163984bb40cd": {
			"balance": "985000000000000000000"
		},
		"47fff42c678551d141eb75a6ee398117df3e4a8d": {
			"balance": "100010000000000000000"
		},
		"f2294adbb6f0dcc76e632ebef48ab49f124dbba4": {
			"balance": "1443690000000000000000"
		},
		"53700d53254d430f22781a4a76a463933b5d6b08": {
			"balance": "1970000000000000000000"
		},
		"b14a7aaa8f49f2fb9a8102d6bbe4c48ae7c06fb2": {
			"balance": "8000000000000000000000"
		},
		"9ed4e63f526542d44fddd34d59cd25388ffd6bda": {
			"balance": "3885000000000000000000"
		},
		"4cac91fb83a147d2f76c3267984b910a79933348": {
			"balance": "2167000000000000000000"
		},
		"9b32cf4f5115f4b34a00a64c617de06387354323": {
			"balance": "105501000000000000000"
		},
		"b8bedd576a4b4c2027da735a5bc3f533252a1808": {
			"balance": "2000000000000000000000"
		},
		"c5a3b98e4593fea0b38c4f455a5065f051a2f815": {
			"balance": "20309030000000000000000"
		},
		"eaf52388546ec35aca6f6c6393d8d609de3a4bf3": {
			"balance": "20000000000000000000"
		},
		"4c423c76930d07f93c47a5cc4f615745c45a9d72": {
			"balance": "100000000000000000000"
		},
		"9052f2e4a3e3c12dd1c71bf78a4ec3043dc88b7e": {
			"balance": "267400000000000000000"
		},
		"2bade91d154517620fd4b439ac97157a4102a9f7": {
			"balance": "4000000000000000000000"
		},
		"da698d64c65c7f2b2c7253059cd3d181d899b6b7": {
			"balance": "295500000000000000000"
		},
		"c6d8954e8f3fc533d2d230ff025cb4dce14f3426": {
			"balance": "400000000000000000000"
		},
		"349a816b17ab3d27bbc0ae0051f6a070be1ff29d": {
			"balance": "10000000000000000000000"
		},
		"ff4d9c8484c43c42ff2c5ab759996498d323994d": {
			"balance": "4000000000000000000000"
		},
		"22944fbca9b57963084eb84df7c85fb9bcdfb856": {
			"balance": "4649845000000000000000"
		},
		"bfd93c90c29c07bc5fb5fc49aeea55a40e134f35": {
			"balance": "28000000000000000000000"
		},
		"3caedb5319fe806543c56e5021d372f71be9062e": {
			"balance": "40000000000000000000000"
		},
		"9a079c92a629ca15c8cafa2eb28d5bc17af82811": {
			"balance": "500000000000000000000"
		},
		"7d2a52a7cf0c8436a8e007976b6c26b7229d1e15": {
			"balance": "438040000000000000000"
		},
		"cf89f7460ba3dfe83c5a1d3a019ee1250f242f0f": {
			"balance": "985177000000000000000"
		},
		"577bfe64e3a1e3800e94db1c6c184d8dc8aafc66": {
			"balance": "1498000000000000000000"
		},
		"7ffd02ed370c7060b2ae53c078c8012190dfbb75": {
			"balance": "10000000000000000000000"
		},
		"90b62f131a5f29b45571513ee7a74a8f0b232202": {
			"balance": "158000000000000000000"
		},
		"6e8212b722afd408a7a73ed3e2395ee6454a0330": {
			"balance": "159000000000000000000"
		},
		"515f30bc90cdf4577ee47d65d785fbe2e837c6bc": {
)E" + R"E(
			"balance": "10166128000000000000000"
		},
		"c27376f45d21e15ede3b26f2655fcee02ccc0f2a": {
			"balance": "20000000000000000000"
		},
		"3da39ce3ef4a7a3966b32ee7ea4ebc2335a8f11f": {
			"balance": "2000000000000000000000"
		},
		"25259d975a21d83ae30e33f800f53f37dfa01938": {
			"balance": "20000000000000000000"
		},
		"8ed143701f2f72280fd04a7b4164281979ea87c9": {
			"balance": "14000000000000000000"
		},
		"5ac99ad7816ae9020ff8adf79fa9869b7cea6601": {
			"balance": "21000000000000000000000"
		},
		"f51fded80acb502890e87369741f3722514cefff": {
			"balance": "20000042000000000000000"
		},
		"f657fcbe682eb4e8db152ecf892456000b513d15": {
			"balance": "1940000000000000000000"
		},
		"62c37c52b97f4b040b1aa391d6dec152893c4707": {
			"balance": "1000000000000000000000"
		},
		"89fc8e4d386b0d0bb4a707edf3bd560df1ad8f4e": {
			"balance": "2955000000000000000000"
		},
		"53c0bb7fc88ea422d2ef7e540e2d8f28b1bb8183": {
			"balance": "20000000000000000000"
		},
		"56f493a3d108aaa2d18d98922f8efe1662cfb73d": {
			"balance": "2020000000000000000000"
		},
		"e9458f68bb272cb5673a04f781b403556fd3a387": {
			"balance": "61000000000000000000"
		},
		"be525a33ea916177f17283fca29e8b350b7f530b": {
			"balance": "2638000000000000000000"
		},
		"4feb846be43041fd6b34202897943e3f21cb7f04": {
			"balance": "83226000000000000000"
		},
		"15aa530dc36958b4edb38eee6dd9e3c77d4c9145": {
			"balance": "2000000000000000000000"
		},
		"2458d6555ff98a129cce4037953d00206eff4287": {
			"balance": "197000000000000000000"
		},
		"8035fe4e6b6af27ae492a578515e9d39fa6fa65b": {
			"balance": "4000000000000000000000"
		},
		"296b71c0015819c242a7861e6ff7eded8a5f71e3": {
			"balance": "1999800000000000000000"
		},
		"8f1952eed1c548d9ee9b97d0169a07933be69f63": {
			"balance": "1000000000000000000000"
		},
		"a421dbb89b3a07419084ad10c3c15dfe9b32d0c2": {
			"balance": "20000000000000000000000"
		},
		"554336ee4ea155f9f24f87bca9ca72e253e12cd2": {
			"balance": "100000000000000000000"
		},
		"ffc5fc4b7e8a0293ff39a3a0f7d60d2646d37a74": {
			"balance": "2000000000000000000000"
		},
		"ea2c197d26e98b0da83e1b72c787618c979d3db0": {
			"balance": "19700000000000000000"
		},
		"96aa573fed2f233410dbae5180145b23c31a02f0": {
			"balance": "1730000000000000000000"
		},
		"c23b2f921ce4a37a259ee4ad8b2158d15d664f59": {
			"balance": "25403000000000000000"
		},
		"d874b9dfae456a929ba3b1a27e572c9b2cecdfb3": {
			"balance": "170000000000000000000"
		},
		"bf8b8005d636a49664f74275ef42438acd65ac91": {
			"balance": "200000000000000000000"
		},
		"441a52001661fac718b2d7b351b7c6fb521a7afd": {
			"balance": "400000000000000000000"
		},
		"812a55c43caedc597218379000ce510d548836fd": {
			"balance": "18200000000000000000"
		},
		"5e90c85877198756b0366c0e17b28e52b446505a": {
			"balance": "374288000000000000000"
		},
		"da3017c150dd0dce7fcf881b0a48d0d1c756c4c7": {
			"balance": "100014000000000000000"
		},
		"6baf7a2a02ae78801e8904ad7ac05108fc56cff6": {
			"balance": "1000000000000000000000"
		},
		"177dae78bc0113d8d39c4402f2a641ae2a105ab8": {
			"balance": "1818320000000000000000"
)E" + R"E(
		},
		"01b5b5bc5a117fa08b34ed1db9440608597ac548": {
			"balance": "200000000000000000000"
		},
		"aae732eda65988c3a00c7f472f351c463b1c968e": {
			"balance": "2000000000000000000000"
		},
		"d95342953c8a21e8b635eefac7819bea30f17047": {
			"balance": "94160000000000000000000"
		},
		"8d616b1eee77eef6f176e0698db3c0c141b2fc8f": {
			"balance": "500000000000000000000"
		},
		"12d20790b7d3dbd88c81a279b812039e8a603bd0": {
			"balance": "1604400000000000000000"
		},
		"3734cb187491ede713ae5b3b2d12284af46b8101": {
			"balance": "3000000000000000000000"
		},
		"dd967c4c5f8ae47e266fb416aad1964ee3e7e8c3": {
			"balance": "7750000000000000000000"
		},
		"3dcef19c868b15d34eda426ec7e04b18b6017002": {
			"balance": "1999800000000000000000"
		},
		"ce9d21c692cd3c01f2011f505f870036fa8f6cd2": {
			"balance": "400000000000000000000"
		},
		"d44f6ac3923b5fd731a4c45944ec4f7ec52a6ae4": {
			"balance": "10000000000000000000000"
		},
		"b424d68d9d0d00cec1938c854e15ffb880ba0170": {
			"balance": "200000000000000000000"
		},
		"1f2186ded23e0cf9521694e4e164593e690a9685": {
			"balance": "300000000000000000000"
		},
		"7f4b5e278578c046cceaf65730a0e068329ed5b6": {
			"balance": "1880000000000000000000"
		},
		"8c50aa2a9212bcde56418ae261f0b35e7a9dbb82": {
			"balance": "400000000000000000000"
		},
		"1953313e2ad746239cb2270f48af34d8bb9c4465": {
			"balance": "2000000000000000000000"
		},
		"a15025f595acdbf3110f77c5bf24477e6548f9e8": {
			"balance": "2000000000000000000000"
		},
		"53af32c22fef99803f178cf90b802fb571c61cb9": {
			"balance": "3880000000000000000000"
		},
		"d0a8abd80a199b54b08b65f01d209c27fef0115b": {
			"balance": "6525979000000000000000"
		},
		"2b68306ba7f8daaf73f4c644ef7d2743c0f26856": {
			"balance": "864800000000000000000"
		},
		"96924191b7df655b3319dc6d6137f481a73a0ff3": {
			"balance": "4020000000000000000000"
		},
		"6fa72015fa78696efd9a86174f7f1f21019286b1": {
			"balance": "1337000000000000000000"
		},
		"0b119df99c6b8de58a1e2c3f297a6744bf552277": {
			"balance": "2000000000000000000000"
		},
		"61733947fab820dbd351efd67855ea0e881373a0": {
			"balance": "20000000000000000000"
		},
		"8ae6f80b70e1f23c91fbd5a966b0e499d95df832": {
			"balance": "197000000000000000000"
		},
		"01a7d9fa7d0eb1185c67e54da83c2e75db69e39f": {
			"balance": "7623900000000000000000"
		},
		"9932ef1c85b75a9b2a80057d508734c51085becc": {
			"balance": "50170000000000000000"
		},
		"aefcfe88c826ccf131d54eb4ea9eb80e61e1ee25": {
			"balance": "340000000000000000000"
		},
		"c21fa6643a1f14c02996ad7144b75926e87ecb4b": {
			"balance": "20000000000000000000000"
		},
		"97d9e46a7604d7b5a4ea4ee61a42b3d2350fc3ed": {
			"balance": "2000000000000000000000"
		},
		"3cafaf5e62505615068af8eb22a13ad8a9e55070": {
			"balance": "1999600000000000000000"
		},
		"22f2dcff5ad78c3eb6850b5cb951127b659522e6": {
			"balance": "13700000000000000000"
		},
		"aaad1baade5af04e2b17439e935987bf8c2bb4b9": {
			"balance": "2000000000000000000000"
		},
		"298887bab57c5ba4f0615229d7525fa113b7ea89": {
			"balance": "40000000000000000000"
		},
)E" + R"E(
		"7539333046deb1ef3c4daf50619993f444e1de68": {
			"balance": "1182000000000000000000"
		},
		"9752d14f5e1093f071711c1adbc4e3eb1e5c57f3": {
			"balance": "2000000000000000000000"
		},
		"ed641e06368fb0efaa1703e01fe48f4a685309eb": {
			"balance": "200000000000000000000"
		},
		"d0ee4d02cf24382c3090d3e99560de3678735cdf": {
			"balance": "2400000000000000000000"
		},
		"47e25df8822538a8596b28c637896b4d143c351d": {
			"balance": "80500000000000000000000"
		},
		"559706c332d20779c45f8a6d046a699159b74921": {
			"balance": "380123000000000000000"
		},
		"3a4da78dce05aeb87de9aead9185726da1926798": {
			"balance": "200000000000000000000"
		},
		"3041445a33ba158741160d9c344eb88e5c306f94": {
			"balance": "60000000000000000000"
		},
		"08d4311c9c1bbaf87fabe1a1d01463828d5d98ce": {
			"balance": "90000000000000000000000"
		},
		"6bd3e59f239fafe4776bb9bddd6bee83ba5d9d9f": {
			"balance": "1000000000000000000000"
		},
		"29eaae82761762f4d2db53a9c68b0f6b0b6d4e66": {
			"balance": "2000000000000000000000"
		},
		"0b7d339371e5be6727e6e331b5821fa24bdb9d5a": {
			"balance": "857738000000000000000"
		},
		"4714cfa4f46bd6bd70737d75878197e08f88e631": {
			"balance": "11792000000000000000000"
		},
		"ad92ca066edb7c711dfc5b166192d1edf8e77185": {
			"balance": "36000000000000000000000"
		},
		"f97b56ebd5b77abc9fbacbabd494b9d2c221cd03": {
			"balance": "1970000000000000000000"
		},
		"591bef3171d1c5957717a4e98d17eb142c214e56": {
			"balance": "20000000000000000000000"
		},
		"899b3c249f0c4b81df75d212004d3d6d952fd223": {
			"balance": "2000000000000000000000"
		},
		"a819d2ece122e028c8e8a04a064d02b9029b08b9": {
			"balance": "1000000000000000000000"
		},
		"e341642d40d2afce2e9107c67079ac7a2660086c": {
			"balance": "400000000000000000000"
		},
		"0329188f080657ab3a2afa522467178279832085": {
			"balance": "216700000000000000000"
		},
		"03317826d1f70aa4bddfa09be0c4105552d2358b": {
			"balance": "38800000000000000000"
		},
		"3ac9dc7a436ae98fd01c7a9621aa8e9d0b8b531d": {
			"balance": "1790000000000000000000"
		},
		"93c88e2d88621e30f58a9586bed4098999eb67dd": {
			"balance": "31200000000000000000000"
		},
		"cd1e66ed539dd92fc40bbaa1fa16de8c02c14d45": {
			"balance": "230000000000000000000"
		},
		"e6c81ffcecb47ecdc55c0b71e4855f3e5e97fc1e": {
			"balance": "334250000000000000000"
		},
		"50f8fa4bb9e2677c990a4ee8ce70dd1523251e4f": {
			"balance": "26030000000000000000"
		},
		"4f64a85e8e9a40498c0c75fceb0337fb49083e5e": {
			"balance": "1000000000000000000000"
		},
		"4b29437c97b4a844be71cca3b648d4ca0fdd9ba4": {
			"balance": "150200000000000000000"
		},
		"1eee6cbee4fe96ad615a9cf5857a647940df8c78": {
			"balance": "19400000000000000000"
		},
		"29f0edc60338e7112085a1d114da8c42ce8f55d6": {
			"balance": "2958000000000000000000"
		},
		"23b1c4917fbd93ee3d48389306957384a5496cbf": {
			"balance": "4000086000000000000000"
		},
		"1767525c5f5a22ed80e9d4d7710f0362d29efa33": {
			"balance": "400000000000000000000"
		},
		"3064899a963c4779cbf613cd6980846af1e6ec65": {
			"balance": "6999908000000000000000"
		},
		"68531f4dda808f5320767a03113428ca0ce2f389": {
)E" + R"E(
			"balance": "19400000000000000000"
		},
		"1db9ac9a9eaeec0a523757050c71f47278c72d50": {
			"balance": "1337000000000000000000"
		},
		"7592c69d067b51b6cc639d1164d5578c60d2d244": {
			"balance": "20000000000000000000"
		},
		"cf3fbfa1fd32d7a6e0e6f8ef4eab57be34025c4c": {
			"balance": "1063120000000000000000"
		},
		"8efec058cc546157766a632775404a334aaada87": {
			"balance": "1999000000000000000000"
		},
		"faf5f0b7b6d558f5090d9ea1fb2d42259c586078": {
			"balance": "6401000000000000000000"
		},
		"19ecf2abf40c9e857b252fe1dbfd3d4c5d8f816e": {
			"balance": "2000000000000000000000"
		},
		"6e8a26689f7a2fdefd009cbaaa5310253450daba": {
			"balance": "2049982000000000000000"
		},
		"e2f40d358f5e3fe7463ec70480bd2ed398a7063b": {
			"balance": "20000000000000000000"
		},
		"fa19d6f7a50f4f079893d167bf14e21d0073d196": {
			"balance": "530000000000000000000"
		},
		"3e2ca0d234baf607ad466a1b85f4a6488ef00ae7": {
			"balance": "89505000000000000000"
		},
		"f8a49ca2390c1f6d5c0e62513b079571743f7cc6": {
			"balance": "3000000000000000000000"
		},
		"5d3f3b1f7130b0bb21a0fd32396239179a25657f": {
			"balance": "62474000000000000000000"
		},
		"f332c0f3e05a27d9126fd0b641a8c2d4060608fd": {
			"balance": "5001041000000000000000"
		},
		"e304a32f05a83762744a9542976ff9b723fa31ea": {
			"balance": "1576256000000000000000"
		},
		"f768f321fd6433d96b4f354d3cc1652c1732f57f": {
			"balance": "10000000000000000000000"
		},
		"147af46ae9ccd18bb35ca01b353b51990e49dce1": {
			"balance": "4000000000000000000000"
		},
		"21eae6feffa9fbf4cd874f4739ace530ccbe5937": {
			"balance": "5000000000000000000000"
		},
		"6994fb3231d7e41d491a9d68d1fa4cae2cc15960": {
			"balance": "4000000000000000000000"
		},
		"51126446ab3d8032557e8eba65597d75fadc815c": {
			"balance": "322000000000000000000"
		},
		"24daaaddf7b06bbcea9b80590085a88567682b4e": {
			"balance": "319008000000000000000"
		},
		"cd020f8edfcf524798a9b73a640334bbf72f80a5": {
			"balance": "133700000000000000000"
		},
		"56febf9e1003af15b1bd4907ec089a4a1b91d268": {
			"balance": "200000000000000000000"
		},
		"3c79c863c3d372b3ff0c6f452734a7f97042d706": {
			"balance": "176000000000000000000"
		},
		"e1203eb3a723e99c2220117ca6afeb66fa424f61": {
			"balance": "9461996000000000000000"
		},
		"18fb09188f27f1038e654031924f628a2106703d": {
			"balance": "2000000000000000000000"
		},
		"2eba0c6ee5a1145c1c573984963a605d880a7a20": {
			"balance": "500000000000000000000"
		},
		"4cefbe2398e47d52e78db4334c8b697675f193ae": {
			"balance": "4011000000000000000000"
		},
		"c02471e3fc2ea0532615a7571d493289c13c36ef": {
			"balance": "20000000000000000000"
		},
		"ba469aa5c386b19295d4a1b5473b540353390c85": {
			"balance": "2000000000000000000000"
		},
		"7b11673cc019626b290cbdce26046f7e6d141e21": {
			"balance": "500000000000000000000"
		},
		"26784ade91c8a83a8e39658c8d8277413ccc9954": {
			"balance": "6000000000000000000000"
		},
		"57d3df804f2beee6ef53ab94cb3ee9cf524a18d3": {
			"balance": "393606000000000000000"
		},
		"ccae0d3d852a7da3860f0636154c0a6ca31628d4": {
			"balance": "106560000000000000000"
)E" + R"E(
		},
		"bfe3a1fc6e24c8f7b3250560991f93cba2cf8047": {
			"balance": "80000000000000000000000"
		},
		"724ce858857ec5481c86bd906e83a04882e5821d": {
			"balance": "3000000000000000000000"
		},
		"fb37cf6b4f81a9e222fba22e9bd24b5098b733cf": {
			"balance": "38800000000000000000"
		},
		"9b22a80d5c7b3374a05b446081f97d0a34079e7f": {
			"balance": "3000000000000000000000"
		},
		"0a29a8a4d5fd950075ffb34d77afeb2d823bd689": {
			"balance": "200000000000000000000"
		},
		"d01af9134faf5257174e8b79186f42ee354e642d": {
			"balance": "1000000000000000000000"
		},
		"7f1619988f3715e94ff1d253262dc5581db3de1c": {
			"balance": "900000000000000000000"
		},
		"6f137a71a6f197df2cbbf010dcbd3c444ef5c925": {
			"balance": "2000000000000000000000"
		},
		"11efb8a20451161b644a8ccebbc1d343a3bbcb52": {
			"balance": "3200000000000000000000"
		},
		"46504e6a215ac83bccf956befc82ab5a679371c8": {
			"balance": "518898000000000000000"
		},
		"b523fff9749871b35388438837f7e6e0dea9cb6b": {
			"balance": "2000000000000000000000"
		},
		"c5c6a4998a33feb764437a8be929a73ba34a0764": {
			"balance": "50000000000000000000000"
		},
		"3cd7f7c7c2353780cde081eeec45822b25f2860c": {
			"balance": "200000000000000000000"
		},
		"b3050beff9de33c80e1fa15225e28f2c413ae313": {
			"balance": "700000000000000000000"
		},
		"59268171b833e0aa13c54b52ccc0422e4fa03aeb": {
			"balance": "3000000000000000000000"
		},
		"7169724ee72271c534cad6420fb04ee644cb86fe": {
			"balance": "410164000000000000000"
		},
		"6e6d5bbbb9053b89d744a27316c2a7b8c09b547d": {
			"balance": "909831000000000000000"
		},
		"3f3f46b75cabe37bfacc8760281f4341ca7f463d": {
			"balance": "602709000000000000000"
		},
		"7a33834e8583733e2d52aead589bd1affb1dd256": {
			"balance": "1000000000000000000000"
		},
		"e94ded99dcb572b9bb1dcba32f6dee91e057984e": {
			"balance": "394000000000000000000"
		},
		"19336a236ded755872411f2e0491d83e3e00159e": {
			"balance": "940000000000000000000"
		},
		"63ac545c991243fa18aec41d4f6f598e555015dc": {
			"balance": "600000000000000000000"
		},
		"cfee05c69d1f29e7714684c88de5a16098e91399": {
			"balance": "1970000000000000000000"
		},
		"77be6b64d7c733a436adec5e14bf9ad7402b1b46": {
			"balance": "1000000000000000000000"
		},
		"233bdddd5da94852f4ade8d212885682d9076bc6": {
			"balance": "4000000000000000000000"
		},
		"952c57d2fb195107d4cd5ca300774119dfad2f78": {
			"balance": "2000000000000000000000"
		},
		"e237baa4dbc9926e32a3d85d1264402d54db012f": {
			"balance": "2000000000000000000000"
		},
		"aa91237e740d25a92f7fa146faa18ce56dc6e1f3": {
			"balance": "925000000000000000000"
		},
		"2339e9492870afea2537f389ac2f838302a33c06": {
			"balance": "2000000000000000000000"
		},
		"1d45586eb803ca2190650bf748a2b174312bb507": {
			"balance": "1400000000000000000000"
		},
		"c61446b754c24e3b1642d9e51765b4d3e46b34b6": {
			"balance": "2000000000000000000000"
		},
		"ac28b5edea05b76f8c5f97084541277c96696a4c": {
			"balance": "1000000000000000000000"
		},
		"1a1c9a26e0e02418a5cf687da75a275c622c9440": {
			"balance": "5000000000000000000000"
		},
)E" + R"E(
		"299368609042a858d1ecdf1fc0ada5eaceca29cf": {
			"balance": "2000000000000000000000"
		},
		"095f5a51d06f6340d80b6d29ea2e88118ad730fe": {
			"balance": "2000200000000000000000"
		},
		"751a2ca34e7187c163d28e3618db28b13c196d26": {
			"balance": "500000000000000000000"
		},
		"75b0e9c942a4f0f6f86d3f95ff998022fa67963b": {
			"balance": "1490000000000000000000"
		},
		"d1b37f03cb107424e9c4dd575ccd4f4cee57e6cd": {
			"balance": "2000000000000000000000"
		},
		"7f993ddb7e02c282b898f6155f680ef5b9aff907": {
			"balance": "20000000000000000000000"
		},
		"a3d583a7b65b23f60b7905f3e4aa62aac87f4227": {
			"balance": "1046779000000000000000"
		},
		"526bb533b76e20c8ee1ebf123f1e9ff4148e40be": {
			"balance": "197000000000000000000"
		},
		"2160b4c02cac0a81de9108de434590a8bfe68735": {
			"balance": "1970000000000000000000"
		},
		"010007394b8b7565a1658af88ce463499135d6b7": {
			"balance": "100000000000000000000"
		},
		"64457fa33b0832506c4f7d1180dce48f46f3e0ff": {
			"balance": "2000000000000000000000"
		},
		"b51e558eb5512fbcfa81f8d0bd938c79ebb5242b": {
			"balance": "715000000000000000000"
		},
		"94f13f9f0836a3ee2437a84922d2984dc0f7d53b": {
			"balance": "2999916000000000000000"
		},
		"6bd457ade051795df3f2465c3839aed3c5dee978": {
			"balance": "999925000000000000000"
		},
		"f3dbcf135acb9dee1a489c593c024f03c2bbaece": {
			"balance": "2000000000000000000000"
		},
		"61b902c5a673885826820d1fe14549e4865fbdc2": {
			"balance": "334703000000000000000"
		},
		"2acc9c1a32240b4d5b2f777a2ea052b42fc1271c": {
			"balance": "41764000000000000000000"
		},
		"6ddfef639155daab0a5cb4953aa8c5afaa880453": {
			"balance": "1820000000000000000000"
		},
		"96ff6f509968f36cb42cba48db32f21f5676abf8": {
			"balance": "1970000000000000000000"
		},
		"b4c8170f7b2ab536d1d9a25bdd203ae1288dc3d5": {
			"balance": "200000000000000000000"
		},
		"78d4f8c71c1e68a69a98f52fcb45da8af56ea1a0": {
			"balance": "2000000000000000000000"
		},
		"dec99e972fca7177508c8e1a47ac22d768acab7c": {
			"balance": "2000000000000000000000"
		},
		"a07aa16d74aee8a9a3288d52db1551d593883297": {
			"balance": "600000000000000000000"
		},
		"cf1169041c1745e45b172435a2fc99b49ace2b00": {
			"balance": "31960000000000000000"
		},
		"526cb09ce3ada3672eec1deb46205be89a4b563e": {
			"balance": "2468000000000000000000"
		},
		"ee6959de2b67967b71948c891ab00d8c8f38c7dc": {
			"balance": "118200000000000000000"
		},
		"ca7ba3ff536c7e5f0e153800bd383db8312998e0": {
			"balance": "169600000000000000000"
		},
		"1ed06ee51662a86c634588fb62dc43c8f27e7c17": {
			"balance": "200000000000000000000"
		},
		"730447f97ce9b25f22ba1afb36df27f9586beb9b": {
			"balance": "820000000000000000000"
		},
		"ae5c9bdad3c5c8a1220444aea5c229c1839f1d64": {
			"balance": "477500000000000000000"
		},
		"a38306cb70baa8e49186bd68aa70a83d242f2907": {
			"balance": "2000000000000000000000"
		},
		"71213fca313404204ecba87197741aa9dfe96338": {
			"balance": "60000000000000000000"
		},
		"10e390ad2ba33d82b37388d09c4544c6b0225de5": {
			"balance": "200000000000000000000"
		},
		"3b6e814f770748a7c3997806347605480a3fd509": {
)E" + R"E(
			"balance": "2000000000000000000000"
		},
		"fd452c3969ece3801c542020f1cdcaa1c71ed23d": {
			"balance": "100000000000000000000000"
		},
		"e742b1e6069a8ffc3c4767235defb0d49cbed222": {
			"balance": "800000000000000000000"
		},
		"d7225738dcf3578438f8e7c8b3837e42e04a262f": {
			"balance": "445860000000000000000"
		},
		"cd0b0257e783a3d2c2e3ba9d6e79b75ef98024d4": {
			"balance": "2945500000000000000000"
		},
		"e80e7fef18a5db15b01473f3ad6b78b2a2f8acd9": {
			"balance": "500000000000000000000"
		},
		"261575e9cf59c8226fa7aaf91de86fb70f5ac3ae": {
			"balance": "300022000000000000000"
		},
		"7e71171f2949fa0c3ac254254b1f0440e5e6a038": {
			"balance": "40000000000000000000"
		},
		"96ea6ac89a2bac95347b51dba63d8bd5ebdedce1": {
			"balance": "2000000000000000000000"
		},
		"e6ec5cf0c49b9c317e1e706315ef9eb7c0bf11a7": {
			"balance": "17200000000000000000000"
		},
		"2b99b42e4f42619ee36baa7e4af2d65eacfcba35": {
			"balance": "40000000000000000000000"
		},
		"c6e4cc0c7283fc1c85bc4813effaaf72b49823c0": {
			"balance": "276926000000000000000"
		},
		"dbc1ce0e49b1a705d22e2037aec878ee0d75c703": {
			"balance": "250000000000000000000"
		},
		"806f44bdeb688037015e84ff218049e382332a33": {
			"balance": "1999000000000000000000"
		},
		"1a3a330e4fcb69dbef5e6901783bf50fd1c15342": {
			"balance": "4200000000000000000000"
		},
		"d2a84f75675c62d80c88756c428eee2bcb185421": {
			"balance": "1200000000000000000000"
		},
		"c593b546b7698710a205ad468b2c13152219a342": {
			"balance": "1550000000000000000000"
		},
		"3f627a769e6a950eb87017a7cd9ca20871136831": {
			"balance": "13790000000000000000000"
		},
		"f2d5763ce073127e2cedde6faba786c73ca94141": {
			"balance": "7900000000000000000000"
		},
		"162110f29eac5f7d02b543d8dcd5bb59a5e33b73": {
			"balance": "2000000000000000000000"
		},
		"59473cd300fffae240f5785626c65dfec792b9af": {
			"balance": "20000000000000000000"
		},
		"4dcd11815818ae29b85d01367349a8a7fb12d06b": {
			"balance": "7900000000000000000000"
		},
		"9329ffdc268babde8874b366406c81445b9b2d35": {
			"balance": "422415000000000000000"
		},
		"0ab4281ebb318590abb89a81df07fa3af904258a": {
			"balance": "500000000000000000000"
		},
		"875061ee12e820041a01942cb0e65bb427b00060": {
			"balance": "2800000000000000000000"
		},
		"c9b698e898d20d4d4f408e4e4d061922aa856307": {
			"balance": "40000000000000000000"
		},
		"ca49a5f58adbefae23ee59eea241cf0482622eaa": {
			"balance": "1430000000000000000000"
		},
		"196e85df7e732b4a8f0ed03623f4db9db0b8fa31": {
			"balance": "21165000000000000000"
		},
		"4c760cd9e195ee4f2d6bce2500ff96da7c43ee91": {
			"balance": "60000000000000000000000"
		},
		"024a098ae702bef5406c9c22b78bd4eb2cc7a293": {
			"balance": "4000000000000000000000"
		},
		"9d81aea69aed6ad07089d61445348c17f34bfc5b": {
			"balance": "300000000000000000000"
		},
		"76ab87dd5a05ad839a4e2fc8c85aa6ba05641730": {
			"balance": "2000000000000000000000"
		},
		"c6e2f5af979a03fd723a1b6efa728318cf9c1800": {
			"balance": "668500000000000000000"
		},
		"5db69fe93e6fb6fbd450966b97238b110ad8279a": {
			"balance": "40000000000000000000000"
)E" + R"E(
		},
		"a4259f8345f7e3a8b72b0fec2cf75e321fda4dc2": {
			"balance": "1910000000000000000000"
		},
		"095030e4b82692dcf8b8d0912494b9b378ec9328": {
			"balance": "1340000000000000000000"
		},
		"4b470f7ba030bc7cfcf338d4bf0432a91e2ea5ff": {
			"balance": "2000000000000000000000"
		},
		"99c9f93e45fe3c1418c353e4c5ac3894eef8121e": {
			"balance": "101870000000000000000"
		},
		"ffac3db879a6c7158e8dec603b407463ba0d31cf": {
			"balance": "1970000000000000000000"
		},
		"ac8e87ddda5e78fcbcb9fa7fc3ce038f9f7d2e34": {
			"balance": "2000000000000000000000"
		},
		"7a0589b143a8e5e107c9ac66a9f9f8597ab3e7ab": {
			"balance": "1510990000000000000000"
		},
		"b7d581fe0af1ec383f3b3c416783f385146a7612": {
			"balance": "20000000000000000000000"
		},
		"bb3fc0a29c034d710812dcc775c8cab9d28d6975": {
			"balance": "1066806000000000000000"
		},
		"2c603ff0fe93616c43573ef279bfea40888d6ae7": {
			"balance": "4740000000000000000000"
		},
		"15f2b7b16432ee50a5f55b41232f6334ed58bdc0": {
			"balance": "400000000000000000000"
		},
		"7f3d7203c8a447f7bf36d88ae9b6062a5eee78ae": {
			"balance": "6000000000000000000000"
		},
		"f067e1f1d683556a4cc4fd0c0313239f32c4cfd8": {
			"balance": "1000000000000000000000"
		},
		"52738c90d860e04cb12f498d96fdb5bf36fc340e": {
			"balance": "30000000000000000000"
		},
		"45781bbe7714a1c8f73b1c747921df4f84278b70": {
			"balance": "2000000000000000000000"
		},
		"4a97e8fcf4635ea7fc5e96ee51752ec388716b60": {
			"balance": "546000000000000000000"
		},
		"54939ff08921b467cf2946751d856378296c63ed": {
			"balance": "1000000000000000000000"
		},
		"6485470e61db110aebdbafd536769e3c599cc908": {
			"balance": "600000000000000000000"
		},
		"e20d1bcb71286dc7128a9fc7c6ed7f733892eef5": {
			"balance": "1003400000000000000000"
		},
		"d6eea898d4ae2b718027a19ce9a5eb7300abe3ca": {
			"balance": "27475000000000000000"
		},
		"014974a1f46bf204944a853111e52f1602617def": {
			"balance": "2000000000000000000000"
		},
		"6aa5732f3b86fb8c81efbe6b5b47b563730b06c8": {
			"balance": "1000000000000000000000"
		},
		"6107d71dd6d0eefb11d4c916404cb98c753e117d": {
			"balance": "2000000000000000000000"
		},
		"dd7bcda65924aaa49b80984ae173750258b92847": {
			"balance": "10000000000000000000000"
		},
		"4e7b54474d01fefd388dfcd53b9f662624418a05": {
			"balance": "8000000000000000000000"
		},
		"24fc73d20793098e09ddab5798506224fa1e1850": {
			"balance": "200000000000000000000"
		},
		"2b8488bd2d3c197a3d26151815b5a798d27168dc": {
			"balance": "6680000000000000000000"
		},
		"949131f28943925cfc97d41e0cea0b262973a730": {
			"balance": "2800000000000000000000"
		},
		"60b8d6b73b79534fb08bb8cbcefac7f393c57bfe": {
			"balance": "1760000000000000000000"
		},
		"d6acc220ba2e51dfcf21d443361eea765cbd35d8": {
			"balance": "20000000000000000000"
		},
		"c4c6cb723dd7afa7eb535615e53f3cef14f18118": {
			"balance": "1999999000000000000000"
		},
		"4c9a862ad115d6c8274ed0b944bdd6a5500510a7": {
			"balance": "100000000000000000000"
		},
		"85732c065cbd64119941aed430ac59670b6c51c4": {
			"balance": "731345000000000000000"
		},
)E" + R"E(
		"0126e12ebc17035f35c0e9d11dd148393c405d7a": {
			"balance": "1999600000000000000000"
		},
		"472048cc609aeb242165eaaa8705850cf3125de0": {
			"balance": "1000000000000000000000"
		},
		"d2edd1ddd6d86dc005baeb541d22b640d5c7cae5": {
			"balance": "20000000000000000000"
		},
		"4549b15979255f7e65e99b0d5604db98dfcac8bf": {
			"balance": "4000000000000000000000"
		},
		"c6c7c191379897dd9c9d9a33839c4a5f62c0890d": {
			"balance": "4000085000000000000000"
		},
		"d367009ab658263b62c2333a1c9e4140498e1389": {
			"balance": "2000000000000000000000"
		},
		"143f5f1658d9e578f4f3d95f80c0b1bd3933cbda": {
			"balance": "1490000000000000000000"
		},
		"1a09fdc2c7a20e23574b97c69e93deba67d37220": {
			"balance": "1998000000000000000000"
		},
		"ac8b509aefea1dbfaf2bb33500d6570b6fd96d51": {
			"balance": "1820000000000000000000"
		},
		"16ffac84032940f0121a09668b858a7e79ffa3bb": {
			"balance": "3879210000000000000000"
		},
		"f338459f32a159b23db30ac335769ab2351aa63c": {
			"balance": "30000000000000000000000"
		},
		"d82251456dc1380f8f5692f962828640ab9f2a03": {
			"balance": "4879980000000000000000"
		},
		"47f4696bd462b20da09fb83ed2039818d77625b3": {
			"balance": "149000000000000000000"
		},
		"3dde8b15b3ccbaa5780112c3d674f313bba68026": {
			"balance": "1773000000000000000000"
		},
		"f70d637a845c06db6cdc91e6371ce7c4388a628e": {
			"balance": "20000000000000000000"
		},
		"68295e8ea5afd9093fc0a465d157922b5d2ae234": {
			"balance": "19982000000000000000"
		},
		"614e8bef3dd2c59b59a4145674401018351884ea": {
			"balance": "20000000000000000000"
		},
		"4737d042dc6ae73ec73ae2517acea2fdd96487c5": {
			"balance": "1000000000000000000000"
		},
		"cec6fc65853f9cce5f8e844676362e1579015f02": {
			"balance": "2000000000000000000000"
		},
		"ae47e2609cfafe369d66d415d939de05081a9872": {
			"balance": "27060000000000000000000"
		},
		"09a928d528ec1b3e25ffc83e218c1e0afe8928c7": {
			"balance": "18200000000000000000"
		},
		"9b444fd337e5d75293adcfff70e1ea01db023222": {
			"balance": "100000000000000000000"
		},
		"168bdec818eafc6d2992e5ef54aa0e1601e3c561": {
			"balance": "1000110000000000000000"
		},
		"353dbec42f92b50f975129b93c4c997375f09073": {
			"balance": "1999000000000000000000"
		},
		"6fcc2c732bdd934af6ccd16846fb26ef89b2aa9b": {
			"balance": "10001242000000000000000"
		},
		"6f2576da4de283bbe8e3ee69ddd66e5e711db3f5": {
			"balance": "1260800000000000000000"
		},
		"3a3dd104cd7eb04f21932fd433ea7affd39369f5": {
			"balance": "357500000000000000000"
		},
		"d44f4ac5fad76bdc1537a3b3af6472319b410d9d": {
			"balance": "1600000000000000000000"
		},
		"3d9d6be57ff83e065985664f12564483f2e600b2": {
			"balance": "2041600000000000000000"
		},
		"88f1045f19f2d3191816b1df18bb6e1435ad1b38": {
			"balance": "240000000000000000000"
		},
		"ddab75fb2ff9fecb88f89476688e2b00e367ebf9": {
			"balance": "19400000000000000000000"
		},
		"092e815558402d67f90d6bfe6da0b2fffa91455a": {
			"balance": "60000000000000000000"
		},
		"a7024cfd742c1ec13c01fea18d3042e65f1d5dee": {
			"balance": "11272229000000000000000"
		},
		"7f46bb25460dd7dae4211ca7f15ad312fc7dc75c": {
)E" + R"E(
			"balance": "6685000000000000000000"
		},
		"93f18cd2526040761488c513174d1e7963768b2c": {
			"balance": "2416500000000000000000"
		},
		"352f25babf4a690673e35195efa8f79d05848aad": {
			"balance": "66800000000000000000000"
		},
		"f7b151cc5e571c17c76539dbe9964cbb6fe5de79": {
			"balance": "2148000000000000000000"
		},
		"ff3eee57c34d6dae970d8b311117c53586cd3502": {
			"balance": "1700000000000000000000"
		},
		"ae6f0c73fdd77c489727512174d9b50296611c4c": {
			"balance": "6000000000000000000000"
		},
		"7819b0458e314e2b53bfe00c38495fd4b9fdf8d6": {
			"balance": "20000000000000000000"
		},
		"7fdba031c78f9c096d62d05a369eeab0bccc55e5": {
			"balance": "2800000000000000000000"
		},
		"735e328666ed5637142b3306b77ccc5460e72c3d": {
			"balance": "1968682000000000000000"
		},
		"0bfbb6925dc75e52cf2684224bbe0550fea685d3": {
			"balance": "1970000000000000000000"
		},
		"6be16313643ebc91ff9bb1a2e116b854ea933a45": {
			"balance": "500000000000000000000"
		},
		"d6acffd0bfd99c382e7bd56ff0e6144a9e52b08e": {
			"balance": "160000000000000000000"
		},
		"276a006e3028ecd44cdb62ba0a77ce94ebd9f10f": {
			"balance": "1800000000000000000000"
		},
		"10711c3dda32317885f0a2fd8ae92e82069b0d0b": {
			"balance": "4000000000000000000000"
		},
		"43cb9652818c6f4d6796b0e89409306c79db6349": {
			"balance": "2000000000000000000000"
		},
		"7109dd011d15f3122d9d3a27588c10d77744508b": {
			"balance": "2000000000000000000000"
		},
		"3497dd66fd118071a78c2cb36e40b6651cc82598": {
			"balance": "109600000000000000000"
		},
		"9bf672d979b36652fc5282547a6a6bc212ae4368": {
			"balance": "656000000000000000000"
		},
		"eaed16eaf5daab5bf0295e5e077f59fb8255900b": {
			"balance": "4000000000000000000000"
		},
		"7ac58f6ffc4f8107ae6e30378e4e9f99c57fbb24": {
			"balance": "40000000000000000000"
		},
		"45a570dcc2090c86a6b3ea29a60863dde41f13b5": {
			"balance": "232500000000000000000"
		},
		"433a3b68e56b0df1862b90586bbd39c840ff1936": {
			"balance": "2000000000000000000000"
		},
		"e8eaf12944092dc3599b3953fa7cb1c9761cc246": {
			"balance": "1800000000000000000000"
		},
		"ec11362cec810985d0ebbd7b73451444985b369f": {
			"balance": "30000047000000000000000"
		},
		"78e83f80b3678c7a0a4e3e8c84dccde064426277": {
			"balance": "1790000000000000000000"
		},
		"0cc67f8273e1bae0867fd42e8b8193d72679dbf8": {
			"balance": "500000000000000000000"
		},
		"c70d856d621ec145303c0a6400cd17bbd6f5eaf7": {
			"balance": "20000000000000000000"
		},
		"f468906e7edf664ab0d8be3d83eb7ab3f7ffdc78": {
			"balance": "1700000000000000000000"
		},
		"3c286cfb30146e5fd790c2c8541552578de334d8": {
			"balance": "10203000000000000000000"
		},
		"c401c427cccff10decb864202f36f5808322a0a8": {
			"balance": "3329300000000000000000"
		},
		"afd019ff36a09155346b69974815a1c912c90aa4": {
			"balance": "2000000000000000000000"
		},
		"96fe59c3dbb3aa7cc8cb62480c65e56e6204a7e2": {
			"balance": "20000000000000000000000"
		},
		"a47779d8bc1c7bce0f011ccb39ef68b854f8de8f": {
			"balance": "2000000000000000000000"
		},
		"58c650ced40bb65641b8e8a924a039def46854df": {
			"balance": "18500000000000000000"
)E" + R"E(
		},
		"86f4f40ad984fbb80933ae626e0e42f9333fdd41": {
			"balance": "1000000000000000000000"
		},
		"b22d5055d9623135961e6abd273c90deea16a3e7": {
			"balance": "1400000000000000000000"
		},
		"ee3564f5f1ba0f94ec7bac164bddbf31c6888b55": {
			"balance": "100000000000000000000"
		},
		"cf26b47bd034bc508e6c4bcfd6c7d30034925761": {
			"balance": "1800000000000000000000"
		},
		"e87dbac636a37721df54b08a32ef4959b5e4ff82": {
			"balance": "2000000000000000000000"
		},
		"3bf86ed8a3153ec933786a02ac090301855e576b": {
			"balance": "450000000000000000000000"
		},
		"cfd2728dfb8bdbf3bf73598a6e13eaf43052ea2b": {
			"balance": "170000000000000000000"
		},
		"85b16f0b8b34dff3804f69e2168a4f7b24d1042b": {
			"balance": "317000000000000000000"
		},
		"84db1459bb00812ea67ecb3dc189b72187d9c501": {
			"balance": "148851000000000000000"
		},
		"8c3a9ee71f729f236cba3867b4d79d8ceee25dbc": {
			"balance": "100000000000000000000"
		},
		"e677c31fd9cb720075dca49f1abccd59ec33f734": {
			"balance": "7800000000000000000000"
		},
		"8889448316ccf14ed86df8e2f478dc63c4338340": {
			"balance": "15200000000000000000"
		},
		"b279c7d355c2880392aad1aa21ee867c3b3507df": {
			"balance": "1261000000000000000000"
		},
		"12b5e28945bb2969f9c64c63cc05b6f1f8d6f4d5": {
			"balance": "7722162000000000000000"
		},
		"8d2303341e1e1eb5e8189bde03f73a60a2a54861": {
			"balance": "100000000000000000000"
		},
		"94d81074db5ae197d2bb1373ab80a87d121c4bd3": {
			"balance": "9400000000000000000000"
		},
		"752c9febf42f66c4787bfa7eb17cf5333bba5070": {
			"balance": "1966448000000000000000"
		},
		"16816aac0ede0d2d3cd442da79e063880f0f1d67": {
			"balance": "2000000000000000000000"
		},
		"daac91c1e859d5e57ed3084b50200f9766e2c52b": {
			"balance": "400000000000000000000"
		},
		"32c2fde2b6aabb80e5aea2b949a217f3cb092283": {
			"balance": "5614827000000000000000"
		},
		"cdab46a5902080646fbf954204204ae88404822b": {
			"balance": "544942000000000000000"
		},
		"fdf42343019b0b0c6bf260b173afab7e45b9d621": {
			"balance": "1999944000000000000000"
		},
		"791f6040b4e3e50dcf3553f182cd97a90630b75d": {
			"balance": "4000000000000000000000"
		},
		"4b762166dd1118e84369f804c75f9cd657bf730c": {
			"balance": "500000000000000000000"
		},
		"a76d3f156251b72c0ccf4b47a3393cbd6f49a9c5": {
			"balance": "1337000000000000000000"
		},
		"c5eb42295e9cadeaf2af12dede8a8d53c579c469": {
			"balance": "3820000000000000000000"
		},
		"db9371b30c4c844e59e03e924be606a938d1d310": {
			"balance": "2000000000000000000000"
		},
		"2cd39334ac7eac797257abe3736195f5b4b5ce0f": {
			"balance": "99964000000000000000"
		},
		"ad44357e017e244f476931c7b8189efee80a5d0a": {
			"balance": "300000000000000000000"
		},
		"4ca7b717d9bc8793b04e051a8d23e1640f5ba5e3": {
			"balance": "1248980000000000000000"
		},
		"73e4a2b60cf48e8baf2b777e175a5b1e4d0c2d8f": {
			"balance": "100000000000000000000"
		},
		"5a1d2d2d1d520304b6208849570437eb3091bb9f": {
			"balance": "1970000000000000000000"
		},
		"53047dc8ac9083d90672e8b3473c100ccd278323": {
			"balance": "40000000000000000000"
		},
)E" + R"E(
		"26fe174cbf526650e0cd009bd6126502ce8e684d": {
			"balance": "11640000000000000000000"
		},
		"e2df23f6ea04becf4ab701748dc0963184555cdb": {
			"balance": "2000000000000000000000"
		},
		"c1170dbaadb3dee6198ea544baec93251860fda5": {
			"balance": "1200000000000000000000"
		},
		"8bbeacfc29cfe93402db3c41d99ab759662e73ec": {
			"balance": "2000000000000000000000"
		},
		"165305b787322e25dc6ad0cefe6c6f334678d569": {
			"balance": "2000000000000000000000"
		},
		"095457f8ef8e2bdc362196b9a9125da09c67e3ab": {
			"balance": "200000000000000000000"
		},
		"702802f36d00250fab53adbcd696f0176f638a49": {
			"balance": "2000000000000000000000"
		},
		"489334c2b695c8ee0794bd864217fb9fd8f8b135": {
			"balance": "18200000000000000000"
		},
		"fa8cf4e627698c5d5788abb7880417e750231399": {
			"balance": "4244640000000000000000"
		},
		"3329eb3baf4345d600ced40e6e9975656f113742": {
			"balance": "4999711000000000000000"
		},
		"b4dd5499daeb2507fb2de12297731d4c72b16bb0": {
			"balance": "20000000000000000000"
		},
		"88c2516a7cdb09a6276d7297d30f5a4db1e84b86": {
			"balance": "4000000000000000000000"
		},
		"612ced8dc0dc9e899ee46f7962333315f3f55e44": {
			"balance": "338830000000000000000"
		},
		"d71e43a45177ad51cbe0f72184a5cb503917285a": {
			"balance": "200000000000000000000"
		},
		"2fb566c94bbba4e3cb67cdda7d5fad7131539102": {
			"balance": "2000000000000000000000"
		},
		"03be5b4629aefbbcab9de26d39576cb7f691d764": {
			"balance": "200550000000000000000"
		},
		"025367960304beee34591118e9ac2d1358d8021a": {
			"balance": "2000000000000000000000"
		},
		"a5d5b8b62d002def92413710d13b6ff8d4fc7dd3": {
			"balance": "400000000000000000000"
		},
		"df3b72c5bd71d4814e88a62321a93d4011e3578b": {
			"balance": "4000000000000000000000"
		},
		"3588895ac9fbafec012092dc05c0c302d90740fa": {
			"balance": "3000000000000000000000"
		},
		"6021e85a8814fce1e82a41abd1d3b2dad2faefe0": {
			"balance": "2000000000000000000000"
		},
		"17ee9f54d4ddc84d670eff11e54a659fd72f4455": {
			"balance": "16000000000000000000000"
		},
		"873c6f70efb6b1d0f2bbc57eebcd70617c6ce662": {
			"balance": "1013478000000000000000"
		},
		"1fcc7ce6a8485895a3199e16481f72e1f762defe": {
			"balance": "1000000000000000000000"
		},
		"d0a7209b80cf60db62f57d0a5d7d521a69606655": {
			"balance": "160000000000000000000"
		},
		"a514d00edd7108a6be839a638db2415418174196": {
			"balance": "30000000000000000000000"
		},
		"046377f864b0143f282174a892a73d3ec8ec6132": {
			"balance": "191000000000000000000"
		},
		"c126573d87b0175a5295f1dd07c575cf8cfa15f2": {
			"balance": "10000000000000000000000"
		},
		"0e123d7da6d1e6fac2dcadd27029240bb39052fe": {
			"balance": "1000000000000000000000"
		},
		"ad5a8d3c6478b69f657db3837a2575ef8e1df931": {
			"balance": "36990000000000000000"
		},
		"db882eacedd0eff263511b312adbbc59c6b8b25b": {
			"balance": "9100000000000000000000"
		},
		"0b43bd2391025581d8956ce42a072579cbbfcb14": {
			"balance": "18800000000000000000"
		},
		"affea0473722cb7f0e0e86b9e11883bf428d8d54": {
			"balance": "1940000000000000000000"
		},
		"e32b1c4725a1875449e98f970eb3e54062d15800": {
)E" + R"E(
			"balance": "200000000000000000000"
		},
		"98f4af3af0aede5fafdc42a081ecc1f89e3ccf20": {
			"balance": "9400000000000000000000"
		},
		"3b4768fd71e2db2cbe7fa050483c27b4eb931df3": {
			"balance": "2000000000000000000000"
		},
		"d5f7c41e07729dfa6dfc64c4423160a22c609fd3": {
			"balance": "1790000000000000000000"
		},
		"d944c8a69ff2ca1249690c1229c7192f36251062": {
			"balance": "1970000000000000000000"
		},
		"5ae64e853ba0a51282cb8db52e41615e7c9f733f": {
			"balance": "2000000000000000000000"
		},
		"b13f93af30e8d7667381b2b95bc1a699d5e3e129": {
			"balance": "420000000000000000000"
		},
		"8a20e5b5cee7cd1f5515bace3bf4f77ffde5cc07": {
			"balance": "80000000000000000000"
		},
		"2448596f91c09baa30bc96106a2d37b5705e5d28": {
			"balance": "2000000000000000000000"
		},
		"ccca24d8c56d6e2c07db086ec07e585be267ac8d": {
			"balance": "200000000000000000000"
		},
		"f67bb8e2118bbcd59027666eedf6943ec9f880a5": {
			"balance": "4000000000000000000000"
		},
		"7ae659eb3bc46852fa86fac4e21c768d50388945": {
			"balance": "286000000000000000000"
		},
		"467e0ed54f3b76ae0636176e07420815a021736e": {
			"balance": "2000000000000000000000"
		},
		"a46cd237b63eea438c8e3b6585f679e4860832ac": {
			"balance": "1000000000000000000000"
		},
		"6b760d4877e6a627c1c967bee451a8507ddddbab": {
			"balance": "910000000000000000000"
		},
		"593044670faeff00a55b5ae051eb7be870b11694": {
			"balance": "133700000000000000000"
		},
		"533c06928f19d0a956cc28866bf6c8d8f4191a94": {
			"balance": "292320000000000000000"
		},
		"262dc1364ccf6df85c43268ee182554dae692e29": {
			"balance": "4927600000000000000000"
		},
		"e4368bc1420b35efda95fafbc73090521916aa34": {
			"balance": "4000000000000000000000"
		},
		"feb92d30bf01ff9a1901666c5573532bfa07eeec": {
			"balance": "1000000000000000000000"
		},
		"ee25b9a7032679b113588ed52c137d1a053a1e94": {
			"balance": "199820000000000000000"
		},
		"20134cbff88bfadc466b52eceaa79857891d831e": {
			"balance": "1000000000000000000000"
		},
		"07b1a306cb4312df66482c2cae72d1e061400fcd": {
			"balance": "20000000000000000000000"
		},
		"e791d585b89936b25d298f9d35f9f9edc25a2932": {
			"balance": "2000000000000000000000"
		},
		"2e6933543d4f2cc00b5350bd8068ba9243d6beb0": {
			"balance": "2000000000000000000000"
		},
		"dae0d33eaa341569fa9ff5982684854a4a328a6e": {
			"balance": "1000000000000000000000"
		},
		"125cc5e4d56b2bcc2ee1c709fb9e68fb177440bd": {
			"balance": "2000000000000000000000"
		},
		"ec99e95dece46ffffb175eb6400fbebb08ee9b95": {
			"balance": "100000000000000000000"
		},
		"c538a0ff282aaa5f4b75cfb62c70037ee67d4fb5": {
			"balance": "2000000000000000000000"
		},
		"60676d1fa21fca052297e24bf96389c5b12a70d7": {
			"balance": "241500000000000000000"
		},
		"4b3dfbdb454be5279a3b8addfd0ed1cd37a9420d": {
			"balance": "2000000000000000000000"
		},
		"cdb597299030183f6e2d238533f4642aa58754b6": {
			"balance": "400000000000000000000"
		},
		"1ef2dcbfe0a500411d956eb8c8939c3d6cfe669d": {
			"balance": "776000000000000000000"
		},
		"a7247c53d059eb7c9310f628d7fc6c6a0a773f08": {
			"balance": "500000000000000000000"
)E" + R"E(
		},
		"9799ca21dbcf69bfa1b3f72bac51b9e3ca587cf9": {
			"balance": "1700000000000000000000"
		},
		"ddf95c1e99ce2f9f5698057c19d5c94027ee4a6e": {
			"balance": "6000000000000000000000"
		},
		"83563bc364ed81a0c6da3b56ff49bbf267827a9c": {
			"balance": "17332000000000000000000"
		},
		"a192698007cc11aa603d221d5feea076bcf7c30d": {
			"balance": "2000000000000000000000"
		},
		"0134ff38155fabae94fd35c4ffe1d79de7ef9c59": {
			"balance": "985000000000000000000"
		},
		"80977316944e5942e79b0e3abad38da746086519": {
			"balance": "38800000000000000000"
		},
		"193d37ed347d1c2f4e35350d9a444bc57ca4db43": {
			"balance": "60000000000000000000"
		},
		"009a6d7db326679b77c90391a7476d238f3ba33e": {
			"balance": "200200000000000000000"
		},
		"337b3bdf86d713dbd07b5dbfcc022b7a7b1946ae": {
			"balance": "3980000000000000000000"
		},
		"7de7fe419cc61f91f408d234cc80d5ca3d054d99": {
			"balance": "20000000000000000000"
		},
		"f47bb134da30a812d003af8dccb888f44bbf5724": {
			"balance": "5190000000000000000000"
		},
		"fd920f722682afb5af451b0544d4f41b3b9d5742": {
			"balance": "2330200000000000000000"
		},
		"0a917f3b5cb0b883047fd9b6593dbcd557f453b9": {
			"balance": "1000000000000000000000"
		},
		"ce9786d3712fa200e9f68537eeaa1a06a6f45a4b": {
			"balance": "1790000000000000000000"
		},
		"9ab98d6dbb1eaae16d45a04568541ad3d8fe06cc": {
			"balance": "272451000000000000000"
		},
		"0b7bb342f01bc9888e6a9af4a887cbf4c2dd2caf": {
			"balance": "16000000000000000000000"
		},
		"4c0b1515dfced7a13e13ee12c0f523ae504f032b": {
			"balance": "50000000000000000000000"
		},
		"ac2889b5966f0c7f9edb42895cb69d1c04f923a2": {
			"balance": "5000000000000000000000"
		},
		"d008513b27604a89ba1763b6f84ce688b346945b": {
			"balance": "1000000000000000000000"
		},
		"a4b09de6e713dc69546e76ef0acf40b94f0241e6": {
			"balance": "322656000000000000000"
		},
		"b153f828dd076d4a7c1c2574bb2dee1a44a318a8": {
			"balance": "400000000000000000000"
		},
		"02ade5db22f8b758ee1443626c64ec2f32aa0a15": {
			"balance": "20000000000000000000000"
		},
		"0a0650861f785ed8e4bf1005c450bbd06eb48fb6": {
			"balance": "3066860000000000000000"
		},
		"b75149e185f6e3927057739073a1822ae1cf0df2": {
			"balance": "4000086000000000000000"
		},
		"84cb7da0502df45cf561817bbd2362f451be02da": {
			"balance": "1337000000000000000000"
		},
		"c91bb562e42bd46130e2d3ae4652b6a4eb86bc0f": {
			"balance": "540000000000000000000"
		},
		"b234035f7544463ce1e22bc553064684c513cd51": {
			"balance": "249750000000000000000"
		},
		"e5e33800a1b2e96bde1031630a959aa007f26e51": {
			"balance": "1337000000000000000000"
		},
		"ae5ce3355a7ba9b332760c0950c2bc45a85fa9a0": {
			"balance": "400000000000000000000"
		},
		"e6f5eb649afb99599c414b27a9c9c855357fa878": {
			"balance": "2674000000000000000000"
		},
		"7010be2df57bd0ab9ae8196cd50ab0c521aba9f9": {
			"balance": "1970000000000000000000"
		},
		"ca4288014eddc5632f5facb5e38517a8f8bc5d98": {
			"balance": "340000000000000000000"
		},
		"2784903f1d7c1b5cd901f8875d14a79b3cbe2a56": {
			"balance": "22388000000000000000000"
		},
)E" + R"E(
		"f8dce867f0a39c5bef9eeba609229efa02678b6c": {
			"balance": "2000000000000000000000"
		},
		"e020e86362b487752836a6de0bc02cd8d89a8b6a": {
			"balance": "6000000000000000000000"
		},
		"c4088c025f3e85013f5439fb3440a17301e544fe": {
			"balance": "2325000000000000000000"
		},
		"befb448c0c5f683fb67ee570baf0db5686599751": {
			"balance": "1970000000000000000000"
		},
		"2f187d5a704d5a338c5b2876a090dce964284e29": {
			"balance": "4000000000000000000000"
		},
		"ec0e18a01dc4dc5daae567c3fa4c7f8f9b590205": {
			"balance": "315900000000000000000"
		},
		"637f5869d6e4695f0eb9e27311c4878aff333380": {
			"balance": "1969212000000000000000"
		},
		"d1100dd00fe2ddf18163ad964d0b69f1f2e9658a": {
			"balance": "5959598000000000000000"
		},
		"17ef4acc1bf147e326749d10e677dcffd76f9e06": {
			"balance": "39980000000000000000000"
		},
		"200dfc0b71e359b2b465440a36a6cdc352773007": {
			"balance": "1500000000000000000000"
		},
		"efe0675da98a5dda70cd96196b87f4e726b43348": {
			"balance": "1164000000000000000000"
		},
		"d5bd5e8455c130169357c471e3e681b7996a7276": {
			"balance": "841500000000000000000"
		},
		"9c7b6dc5190fe2912963fcd579683ec7395116b0": {
			"balance": "776000000000000000000"
		},
		"b105dd3d987cffd813e9c8500a80a1ad257d56c6": {
			"balance": "1999944000000000000000"
		},
		"145250b06e4fa7cb2749422eb817bdda8b54de5f": {
			"balance": "219000000000000000000"
		},
		"d96db33b7b5a950c3efa2dc31b10ba10a532ef87": {
			"balance": "2000000000000000000000"
		},
		"af529bdb459cc185bee5a1c58bf7e8cce25c150d": {
			"balance": "197000000000000000000"
		},
		"185546e8768d506873818ac9751c1f12116a3bef": {
			"balance": "200000000000000000000"
		},
		"51d24bc3736f88dd63b7222026886630b6eb878d": {
			"balance": "2000000000000000000000"
		},
		"69af28b0746cac0da17084b9398c5e36bb3a0df2": {
			"balance": "1004700000000000000000"
		},
		"76f83ac3da30f7092628c7339f208bfc142cb1ee": {
			"balance": "2842600000000000000000"
		},
		"00f463e137dcf625fbf3bca39eca98d2b968cf7f": {
			"balance": "5910000000000000000000"
		},
		"2084fce505d97bebf1ad8c5ff6826fc645371fb2": {
			"balance": "30000000000000000000"
		},
		"53a714f99fa00fef758e23a2e746326dad247ca7": {
			"balance": "1490000000000000000000"
		},
		"0bf064428f83626722a7b5b26a9ab20421a7723e": {
			"balance": "133700000000000000000"
		},
		"ac6f68e837cf1961cb14ab47446da168a16dde89": {
			"balance": "1337000000000000000000"
		},
		"4b3c7388cc76da3d62d40067dabccd7ef0433d23": {
			"balance": "100076000000000000000"
		},
		"deb9a49a43873020f0759185e20bbb4cf381bb8f": {
			"balance": "211628000000000000000"
		},
		"5bf9f2226e5aeacf1d80ae0a59c6e38038bc8db5": {
			"balance": "6000000000000000000000"
		},
		"9d0e7d92fb305853d798263bf15e97c72bf9d7e0": {
			"balance": "1000000000000000000000"
		},
		"2b5c60e84535eeb4d580de127a12eb2677ccb392": {
			"balance": "20000000000000000000000"
		},
		"d8d65420c18c2327cc5af97425f857e4a9fd51b3": {
			"balance": "1760000000000000000000"
		},
		"30ec9392244a2108c987bc5cdde0ed9f837a817b": {
			"balance": "1560562000000000000000"
		},
		"56a1d60d40f57f308eebf087dee3b37f1e7c2cba": {
)E" + R"E(
			"balance": "1159600000000000000000"
		},
		"a9a1cdc33bfd376f1c0d76fb6c84b6b4ac274d68": {
			"balance": "5000000000000000000000"
		},
		"a67f38819565423aa85f3e3ab61bc763cbab89dd": {
			"balance": "2130000000000000000000"
		},
		"62d5cc7117e18500ac2f9e3c26c86b0a94b0de15": {
			"balance": "105000000000000000000"
		},
		"4970d3acf72b5b1f32a7003cf102c64ee0547941": {
			"balance": "140000000000000000000000"
		},
		"76628150e2995b5b279fc83e0dd5f102a671dd1c": {
			"balance": "40000000000000000000000"
		},
		"3d8f39881b9edfe91227c33fa4cdd91e678544b0": {
			"balance": "86111000000000000000"
		},
		"ff0b7cb71da9d4c1ea6ecc28ebda504c63f82fd1": {
			"balance": "1043000000000000000000"
		},
		"8d795c5f4a5689ad62da961671f028065286d554": {
			"balance": "2048000000000000000000"
		},
		"be2346a27ff9b702044f500deff2e7ffe6824541": {
			"balance": "20000000000000000000"
		},
		"0dbd417c372b8b0d01bcd944706bd32e60ae28d1": {
			"balance": "340000000000000000000"
		},
		"467fbf41441600757fe15830c8cd5f4ffbbbd560": {
			"balance": "10000000000000000000000"
		},
		"090cd67b60e81d54e7b5f6078f3e021ba65b9a1e": {
			"balance": "1000000000000000000000"
		},
		"55a4cac0cb8b582d9fef38c5c9fff9bd53093d1f": {
			"balance": "1970000000000000000000"
		},
		"3b7b4f53c45655f3dc5f017edc23b16f9bc536fa": {
			"balance": "100000000000000000000"
		},
		"d508d39c70916f6abc4cc7f999f011f077105802": {
			"balance": "100470000000000000000"
		},
		"037dd056e7fdbd641db5b6bea2a8780a83fae180": {
			"balance": "140000000000000000000"
		},
		"660557bb43f4be3a1b8b85e7df7b3c5bcd548057": {
			"balance": "6000000000000000000000"
		},
		"02089361a3fe7451fb1f87f01a2d866653dc0b07": {
			"balance": "39976000000000000000"
		},
		"c4bec96308a20f90cab18399c493fd3d065abf45": {
			"balance": "14000000000000000000000"
		},
		"cca07bb794571d4acf041dad87f0d1ef3185b319": {
			"balance": "2000000000000000000000"
		},
		"f2d0e986d814ea13c8f466a0538c53dc922651f0": {
			"balance": "1380000000000000000000"
		},
		"662cfa038fab37a01745a364e1b98127c503746d": {
			"balance": "3940000000000000000000"
		},
		"3336c3ef6e8b50ee90e037b164b7a8ea5faac65d": {
			"balance": "272712000000000000000"
		},
		"30e33358fc21c85006e40f32357dc8895940aaf0": {
			"balance": "1910000000000000000000"
		},
		"41a9a404fc9f5bfee48ec265b12523338e29a8bf": {
			"balance": "388000000000000000000"
		},
		"6af235d2bbe050e6291615b71ca5829658810142": {
			"balance": "3000000000000000000000"
		},
		"fd5a63157f914fd398eab19c137dd9550bb7715c": {
			"balance": "100000000000000000000"
		},
		"8a4314fb61cd938fc33e15e816b113f2ac89a7fb": {
			"balance": "432800000000000000000"
		},
		"b216dc59e27c3d7279f5cd5bb2becfb2606e14d9": {
			"balance": "400000000000000000000"
		},
		"f5a5459fcdd5e5b273830df88eea4cb77ddadfb9": {
			"balance": "74500000000000000000"
		},
		"df31025f5649d2c6eea41ed3bdd3471a790f759a": {
			"balance": "20000000000000000000"
		},
		"721f9d17e5a0e74205947aeb9bc6a7938961038f": {
			"balance": "51900000000000000000"
		},
		"08d0864dc32f9acb36bf4ea447e8dd6726906a15": {
			"balance": "2000200000000000000000"
)E" + R"E(
		},
		"54575c3114751e3c631971da6a2a02fd3ffbfcc8": {
			"balance": "1940000000000000000000"
		},
		"8f60895fbebbb5017fcbff3cdda397292bf25ba6": {
			"balance": "429177000000000000000"
		},
		"91fe8a4c6164df8fa606995d6ba7adcaf1c893ce": {
			"balance": "17000000000000000000000"
		},
		"889087f66ff284f8b5efbd29493b706733ab1447": {
			"balance": "9850000000000000000000"
		},
		"051633080d07a557adde319261b074997f14692d": {
			"balance": "5800000000000000000000"
		},
		"59a12df2e3ef857aceff9306b309f6a500f70134": {
			"balance": "1000000000000000000000"
		},
		"9f64a8e8dacf4ade30d10f4d59b0a3d5abfdbf74": {
			"balance": "1000060000000000000000"
		},
		"8846928d683289a2d11df8db7a9474988ef01348": {
			"balance": "10000000000000000000000"
		},
		"dff1b220de3d8e9ca4c1b5be34a799bcded4f61c": {
			"balance": "385428000000000000000"
		},
		"7e7c1e9a61a08a83984835c70ec31d34d3eaa87f": {
			"balance": "191000000000000000000"
		},
		"fe210b8f04dc6d4f76216acfcbd59ba83be9b630": {
			"balance": "20000000000000000000"
		},
		"dc8c2912f084a6d184aa73638513ccbc326e0102": {
			"balance": "1295000000000000000000"
		},
		"dddd7b9e6eab409b92263ac272da801b664f8a57": {
			"balance": "500000000000000000000000"
		},
		"86a5f8259ed5b09e188ce346ee92d34aa5dd93fa": {
			"balance": "200000000000000000000"
		},
		"dc1f1979615f082140b8bb78c67b27a1942713b1": {
			"balance": "60000000000000000000"
		},
		"ea66e7b84dcdbf36eea3e75b85382a75f1a15d96": {
			"balance": "1729135000000000000000"
		},
		"039e7a4ebc284e2ccd42b1bdd60bd6511c0f7706": {
			"balance": "17300000000000000000"
		},
		"36bfe1fa3b7b70c172eb042f6819a8972595413e": {
			"balance": "1000000000000000000000"
		},
		"039ef1ce52fe7963f166d5a275c4b1069fe3a832": {
			"balance": "400008000000000000000"
		},
		"f1df55dcc34a051012b575cb968bc9c458ea09c9": {
			"balance": "4000000000000000000000"
		},
		"168b5019b818691644835fe69bf229e17112d52c": {
			"balance": "28000000000000000000000"
		},
		"f60bd735543e6bfd2ea6f11bff627340bc035a23": {
			"balance": "2000000000000000000000"
		},
		"2cbb0c73df91b91740b6693b774a7d05177e8e58": {
			"balance": "1850000000000000000000"
		},
		"9ffcf5ef46d933a519d1d16c6ba3189b27496224": {
			"balance": "1000000000000000000000"
		},
		"0e11d77a8977fac30d268445e531149b31541a24": {
			"balance": "2000000000000000000000"
		},
		"dfb1626ef48a1d7d7552a5e0298f1fc23a3b482d": {
			"balance": "1713860000000000000000"
		},
		"cc943be1222cd1400a2399dd1b459445cf6d54a9": {
			"balance": "12530000000000000000000"
		},
		"b37c2b9f50637bece0ca959208aefee6463ba720": {
			"balance": "400000000000000000000"
		},
		"96b906ea729f4655afe3e57d35277c967dfa1577": {
			"balance": "1000000000000000000000"
		},
		"7995bd8ce2e0c67bf1c7a531d477bca1b2b97561": {
			"balance": "5945100000000000000000"
		},
		"96f820500b70f4a3e3239d619cff8f222075b135": {
			"balance": "200000000000000000000"
		},
		"ad3565d52b688added08168b2d3872d17d0a26ae": {
			"balance": "100000000000000000000"
		},
		"9e7c2050a227bbfd60937e268cea3e68fea8d1fe": {
			"balance": "100000000000000000000"
		},
)E" + R"E(
		"7e59dc60be8b2fc19abd0a5782c52c28400bce97": {
			"balance": "1000000000000000000000"
		},
		"01ed5fba8d2eab673aec042d30e4e8a611d8c55a": {
			"balance": "2000000000000000000000"
		},
		"59a087b9351ca42f58f36e021927a22988284f38": {
			"balance": "18500000000000000000"
		},
		"2fe0023f5722650f3a8ac01009125e74e3f82e9b": {
			"balance": "3000000000000000000000"
		},
		"bd1803370bddb129d239fd16ea8526a6188ae58e": {
			"balance": "500000000000000000000"
		},
		"c70527d444c490e9fc3f5cc44e66eb4f306b380f": {
			"balance": "4000000000000000000000"
		},
		"0f206e1a1da7207ea518b112418baa8b06260328": {
			"balance": "600000000000000000000"
		},
		"6e1a046caf5b4a57f4fd4bc173622126b4e2fd86": {
			"balance": "1790000000000000000000"
		},
		"84008a72f8036f3feba542e35078c057f32a8825": {
			"balance": "100000000000000000000"
		},
		"246291165b59332df5f18ce5c98856fae95897d6": {
			"balance": "1700000000000000000000"
		},
		"7e99dfbe989d3ba529d19751b7f4317f8953a3e2": {
			"balance": "400000000000000000000"
		},
		"748c285ef1233fe4d31c8fb1378333721c12e27a": {
			"balance": "2000000000000000000000"
		},
		"3dd12e556a603736feba4a6fa8bd4ac45d662a04": {
			"balance": "167450000000000000000000"
		},
		"d0ae735d915e946866e1fea77e5ea466b5cadd16": {
			"balance": "2000000000000000000000"
		},
		"4f767bc8794aef9a0a38fea5c81f14694ff21a13": {
			"balance": "512200000000000000000"
		},
		"0e2f8e28a681f77c583bd0ecde16634bdd7e00cd": {
			"balance": "95060000000000000000"
		},
		"d74a6e8d6aab34ce85976814c1327bd6ea0784d2": {
			"balance": "100000000000000000000000"
		},
		"629be7ab126a5398edd6da9f18447e78c692a4fd": {
			"balance": "2000000000000000000000"
		},
		"2e46fcee6a3bb145b594a243a3913fce5dad6fba": {
			"balance": "10000000000000000000000"
		},
		"e39b11a8ab1ff5e22e5ae6517214f73c5b9b55dc": {
			"balance": "2000000000000000000000"
		},
		"119aa64d5b7d181dae9d3cb449955c89c1f963fa": {
			"balance": "700000000000000000000"
		},
		"ce079f51887774d8021cb3b575f58f18e9acf984": {
			"balance": "180000000000000000000"
		},
		"550c306f81ef5d9580c06cb1ab201b95c748a691": {
			"balance": "665800000000000000000"
		},
		"06dc7f18cee7edab5b795337b1df6a9e8bd8ae59": {
			"balance": "400000000000000000000"
		},
		"e21c778ef2a0d7f751ea8c074d1f812243863e4e": {
			"balance": "5308559000000000000000"
		},
		"45d4b54d37a8cf599821235f062fa9d170ede8a4": {
			"balance": "324000000000000000000"
		},
		"893a6c2eb8b40ab096b4f67e74a897b840746e86": {
			"balance": "1730000000000000000000"
		},
		"d44d81e18f46e2cfb5c1fcf5041bc8569767d100": {
			"balance": "36381800000000000000000"
		},
		"c5de1203d3cc2cea31c82ee2de5916880799eafd": {
			"balance": "5000000000000000000000"
		},
		"7f0f04fcf37a53a4e24ede6e93104e78be1d3c9e": {
			"balance": "2000000000000000000000"
		},
		"3ce1dc97fcd7b7c4d3a18a49d6f2a5c1b1a906d7": {
			"balance": "200000000000000000000"
		},
		"ac4ee9d502e7d2d2e99e59d8ca7d5f00c94b4dd6": {
			"balance": "1000000000000000000000"
		},
		"7640a37f8052981515bce078da93afa4789b5734": {
			"balance": "2000000000000000000000"
		},
		"76cac488111a4fd595f568ae3a858770fc915d5f": {
)E" + R"E(
			"balance": "200000000000000000000"
		},
		"ff4a408f50e9e72146a28ce4fc8d90271f116e84": {
			"balance": "1970000000000000000000"
		},
		"249db29dbc19d1235da7298a04081c315742e9ac": {
			"balance": "1801800000000000000000"
		},
		"3a04572847d31e81f7765ca5bfc9d557159f3683": {
			"balance": "133031000000000000000"
		},
		"b6771b0bf3427f9ae7a93e7c2e61ee63941fdb08": {
			"balance": "18800000000000000000000"
		},
		"30c26a8e971baa1855d633ba703f028cc7873140": {
			"balance": "10000000000000000000000"
		},
		"167e3e3ae2003348459392f7dfce44af7c21ad59": {
			"balance": "500000000000000000000"
		},
		"43f16f1e75c3c06a9478e8c597a40a3cb0bf04cc": {
			"balance": "2914000000000000000000"
		},
		"056b1546894f9a85e203fb336db569b16c25e04f": {
			"balance": "169397000000000000000"
		},
		"70616e2892fa269705b2046b8fe3e72fa55816d3": {
			"balance": "20000000000000000000000"
		},
		"8f4d1d41693e462cf982fd81d0aa701d3a5374c9": {
			"balance": "4000000000000000000000"
		},
		"c518799a5925576213e21896e0539abb85b05ae3": {
			"balance": "1000000000000000000000"
		},
		"0e3a28c1dfafb0505bdce19fe025f506a6d01ceb": {
			"balance": "2000000000000000000000"
		},
		"e4a47e3933246c3fd62979a1ea19ffdf8c72ef37": {
			"balance": "148273000000000000000"
		},
		"d231929735132102471ba59007b6644cc0c1de3e": {
			"balance": "1000090000000000000000"
		},
		"555d8d3ce1798aca902754f164b8be2a02329c6c": {
			"balance": "10000000000000000000000"
		},
		"5ab1a5615348001c7c775dc75748669b8be4de14": {
			"balance": "690200000000000000000"
		},
		"2fee36a49ee50ecf716f1047915646779f8ba03f": {
			"balance": "1056230000000000000000"
		},
		"54db5e06b4815d31cb56a8719ba33af2d73e7252": {
			"balance": "670000000000000000000"
		},
		"7c8bb65a6fbb49bd413396a9d7e31053bbb37aa9": {
			"balance": "6000000000000000000000"
		},
		"c1384c6e717ebe4b23014e51f31c9df7e4e25b31": {
			"balance": "500000000000000000000"
		},
		"474158a1a9dc693c133f65e47b5c3ae2f773a86f": {
			"balance": "200200000000000000000"
		},
		"2934c0df7bbc172b6c186b0b72547ace8bf75454": {
			"balance": "60000000000000000000"
		},
		"6966063aa5de1db5c671f3dd699d5abe213ee902": {
			"balance": "8000000000000000000000"
		},
		"9225d46a5a80943924a39e5b84b96da0ac450581": {
			"balance": "40000000000000000000000"
		},
		"671bbca099ff899bab07ea1cf86965c3054c8960": {
			"balance": "50000000000000000000"
		},
		"f1f766b0e46d73fcd4d52e7a72e1b9190cc632b3": {
			"balance": "8000000000000000000000"
		},
		"ef0dc7dd7a53d612728bcbd2b27c19dd4d7d666f": {
			"balance": "705668000000000000000"
		},
		"38d2e9154964b41c8d50a7487d391e7ee2c3d3c2": {
			"balance": "3500000000000000000000"
		},
		"352a785f4a921632504ce5d015f83c49aa838d6d": {
			"balance": "4314800000000000000000"
		},
		"743de50026ca67c94df54f066260e1d14acc11ac": {
			"balance": "2000000000000000000000"
		},
		"b188078444027e386798a8ae68698919d5cc230d": {
			"balance": "267400000000000000000"
		},
		"53608105ce4b9e11f86bf497ffca3b78967b5f96": {
			"balance": "20000000000000000000000"
		},
		"3b159099075207c6807663b1f0f7eda54ac8cce3": {
			"balance": "1969543000000000000000"
)E" + R"E(
		},
		"141a5e39ee2f680a600fbf6fa297de90f3225cdd": {
			"balance": "10000000000000000000000"
		},
		"44fff37be01a3888d3b8b8e18880a7ddefeeead3": {
			"balance": "259145000000000000000"
		},
		"c5a629a3962552cb8eded889636aafbd0c18ce65": {
			"balance": "10000000000000000000000"
		},
		"fdba5359f7ec3bc770ac49975d844ec9716256f1": {
			"balance": "1000000000000000000000"
		},
		"7c1df24a4f7fb2c7b472e0bb006cb27dcd164156": {
			"balance": "1000000000000000000000"
		},
		"ab7d54c7c6570efca5b4b8ce70f52a5773e5d53b": {
			"balance": "279600000000000000000"
		},
		"3f173aa6edf469d185e59bd26ae4236b92b4d8e1": {
			"balance": "320000000000000000000"
		},
		"a3f4ad14e0bb44e2ce2c14359c75b8e732d37054": {
			"balance": "200000000000000000000"
		},
		"ac5f627231480d0d95302e6d89fc32cb1d4fe7e3": {
			"balance": "200000000000000000000"
		},
		"d0775dba2af4c30a3a78365939cd71c2f9de95d2": {
			"balance": "1940000000000000000000"
		},
		"ad94235fc3b3f47a2413af31e884914908ef0c45": {
			"balance": "500008000000000000000"
		},
		"eaedcc6b8b6962d5d9288c156c579d47c0a9fcff": {
			"balance": "85000000000000000000"
		},
		"7ac48d40c664cc9a6d89f1c5f5c80a1c70e744e6": {
			"balance": "3008000000000000000000"
		},
		"ec73114c5e406fdbbe09b4fa621bd70ed54ea1ef": {
			"balance": "24500000000000000000000"
		},
		"a690f1a4b20ab7ba34628620de9ca040c43c1963": {
			"balance": "4000000000000000000000"
		},
		"cad14f9ebba76680eb836b079c7f7baaf481ed6d": {
			"balance": "238600000000000000000"
		},
		"6c714a58fff6e97d14b8a5e305eb244065688bbd": {
			"balance": "4000000000000000000000"
		},
		"3e618350fa01657ab0ef3ebac8e37012f8fc2b6f": {
			"balance": "2804400000000000000000"
		},
		"c946d5acc1346eba0a7279a0ac1d465c996d827e": {
			"balance": "16385128000000000000000"
		},
		"1164caaa8cc5977afe1fad8a7d6028ce2d57299b": {
			"balance": "400000000000000000000"
		},
		"7917e5bd82a9790fd650d043cdd930f7799633db": {
			"balance": "3999800000000000000000"
		},
		"d52aecc6493938a28ca1c367b701c21598b6a02e": {
			"balance": "1100000000000000000000"
		},
		"98bed3a72eccfbafb923489293e429e703c7e25b": {
			"balance": "2000000000000000000000"
		},
		"42db0b902559e04087dd5c441bc7611934184b89": {
			"balance": "2014420000000000000000"
		},
		"43bc2d4ddcd6583be2c7bc094b28fb72e62ba83b": {
			"balance": "2000000000000000000000"
		},
		"85f0e7c1e3aff805a627a2aaf2cff6b4c0dbe9cb": {
			"balance": "20000000000000000000"
		},
		"581b9fd6eae372f3501f42eb9619eec820b78a84": {
			"balance": "19699015000000000000000"
		},
		"541db20a80cf3b17f1621f1b3ff79b882f50def3": {
			"balance": "1000000000000000000000"
		},
		"4e8a6d63489ccc10a57f885f96eb04ecbb546024": {
			"balance": "18500000000000000000000"
		},
		"28349f7ef974ea55fe36a1583b34cec3c45065f0": {
			"balance": "234490000000000000000"
		},
		"a3241d890a92baf52908dc4aa049726be426ebd3": {
			"balance": "19999560000000000000000"
		},
		"b4b11d109f608fa8edd3fea9f8c315649aeb3d11": {
			"balance": "5000000000000000000000"
		},
		"5f321b3daaa296cadf29439f9dab062a4bffedd6": {
			"balance": "81868000000000000000"
		},
)E" + R"E(
		"c5ae86b0c6c7e3900f1368105c56537faf8d743e": {
			"balance": "188000000000000000000"
		},
		"9a8eca4189ff4aa8ff7ed4b6b7039f0902219b15": {
			"balance": "20000000000000000000"
		},
		"a3facc50195c0b4933c85897fecc5bbd995c34b8": {
			"balance": "20000000000000000000"
		},
		"f07bd0e5c2ce69c7c4a724bd26bbfa9d2a17ca03": {
			"balance": "5910000000000000000000"
		},
		"640aba6de984d94517377803705eaea7095f4a11": {
			"balance": "10000000000000000000000"
		},
		"204ac98867a7c9c7ed711cb82f28a878caf69b48": {
			"balance": "6000000000000000000000"
		},
		"9d34dac25bd15828faefaaf28f710753b39e89dc": {
			"balance": "1090400000000000000000"
		},
		"fe418b421a9c6d373602790475d2303e11a75930": {
			"balance": "1015200000000000000000"
		},
		"3f472963197883bbda5a9b7dfcb22db11440ad31": {
			"balance": "481445000000000000000"
		},
		"1578bdbc371b4d243845330556fff2d5ef4dff67": {
			"balance": "100000000000000000000"
		},
		"dba4796d0ceb4d3a836b84c96f910afc103f5ba0": {
			"balance": "166666000000000000000"
		},
		"466fda6b9b58c5532750306a10a2a8c768103b07": {
			"balance": "199955000000000000000"
		},
		"2770f14efb165ddeba79c10bb0af31c31e59334c": {
			"balance": "3000000000000000000000"
		},
		"7c382c0296612e4e97e440e02d3871273b55f53b": {
			"balance": "197600000000000000000"
		},
		"1fb7bd310d95f2a6d9baaf8a8a430a9a04453a8b": {
			"balance": "3000000000000000000000"
		},
		"a9acf600081bb55bb6bfbab1815ffc4e17e85a95": {
			"balance": "200000000000000000000"
		},
		"f93d5bcb0644b0cce5fcdda343f5168ffab2877d": {
			"balance": "209978000000000000000"
		},
		"db0cc78f74d9827bdc8a6473276eb84fdc976212": {
			"balance": "2000000000000000000000"
		},
		"b66411e3a02dedb726fa79107dc90bc1cae64d48": {
			"balance": "2000000000000000000000"
		},
		"4d6e8fe109ccd2158e4db114132fe75fecc8be5b": {
			"balance": "25019000000000000000"
		},
		"6fd947d5a73b175008ae6ee8228163da289b167d": {
			"balance": "30000000000000000000000"
		},
		"32d950d5e93ea1d5b48db4714f867b0320b31c0f": {
			"balance": "1015200000000000000000"
		},
		"9c99b62606281b5cefabf36156c8fe62839ef5f3": {
			"balance": "4000000000000000000000"
		},
		"86c8d0d982b539f48f9830f9891f9d607a942659": {
			"balance": "13260000000000000000000"
		},
		"f2127d54188fedef0f338a5f38c7ff73ad9f6f42": {
			"balance": "20000000000000000000000"
		},
		"e864fec07ed1214a65311e11e329de040d04f0fd": {
			"balance": "1656353000000000000000"
		},
		"1d09ad2412691cc581c1ab36b6f9434cd4f08b54": {
			"balance": "7000000000000000000000"
		},
		"4ea70f04313fae65c3ff224a055c3d2dab28dddf": {
			"balance": "19999800000000000000000"
		},
		"e0668fa82c14d6e8d93a53113ef2862fa81581bc": {
			"balance": "870400000000000000000"
		},
		"f0d858105e1b648101ac3f85a0f8222bf4f81d6a": {
			"balance": "600000000000000000000"
		},
		"0f3a1023cac04dbf44f5a5fa6a9cf8508cd4fddf": {
			"balance": "1820000000000000000000"
		},
		"5793abe6f1533311fd51536891783b3f9625ef1c": {
			"balance": "827268000000000000000"
		},
		"8d667637e29eca05b6bfbef1f96d460eefbf9984": {
			"balance": "4000000000000000000000"
		},
		"d76dbaebc30d4ef67b03e6e6ecc6d84e004d502d": {
)E" + R"E(
			"balance": "2019250000000000000000"
		},
		"42d1a6399b3016a8597f8b640927b8afbce4b215": {
			"balance": "2980000000000000000000"
		},
		"21fd47c5256012198fa5abf131c06d6aa1965f75": {
			"balance": "7880000000000000000000"
		},
		"2f2bba1b1796821a766fce64b84f28ec68f15aea": {
			"balance": "20000000000000000000"
		},
		"d24bf12d2ddf457decb17874efde2052b65cbb49": {
			"balance": "14000000000000000000000"
		},
		"88de13b09931877c910d593165c364c8a1641bd3": {
			"balance": "3000000000000000000000"
		},
		"555ca9f05cc134ab54ae9bea1c3ff87aa85198ca": {
			"balance": "100000000000000000000"
		},
		"ae9ecd6bdd952ef497c0050ae0ab8a82a91898ce": {
			"balance": "30000000000000000000"
		},
		"ad8bfef8c68a4816b3916f35cb7bfcd7d3040976": {
			"balance": "40000000000000000000000"
		},
		"dad136b88178b4837a6c780feba226b98569a94c": {
			"balance": "200000000000000000000"
		},
		"800e7d631c6e573a90332f17f71f5fd19b528cb9": {
			"balance": "152000000000000000000"
		},
		"94a9a71691317c2064271b51c9353fbded3501a8": {
			"balance": "3340000000000000000000"
		},
		"80a0f6cc186cf6201400736e065a391f52a9df4a": {
			"balance": "10000000000000000000000"
		},
		"712ff7370a13ed360973fedc9ff5d2c93a505e9e": {
			"balance": "3940000000000000000000"
		},
		"42399659aca6a5a863ea2245c933fe9a35b7880e": {
			"balance": "2044000000000000000000"
		},
		"ae239acffd4ebe2e1ba5b4170572dc79cc6533ec": {
			"balance": "12000000000000000000000"
		},
		"007b9fc31905b4994b04c9e2cfdc5e2770503f42": {
			"balance": "1999000000000000000000"
		},
		"7480de62254f2ba82b578219c07ba5be430dc3cb": {
			"balance": "7040000000000000000000"
		},
		"917b8f9f3a8d09e9202c52c29e724196b897d35e": {
			"balance": "161000000000000000000"
		},
		"708ea707bae4357f1ebea959c3a250acd6aa21b3": {
			"balance": "500000000000000000000"
		},
		"6dc7053a718616cfc78bee6382ee51add0c70330": {
			"balance": "2000000000000000000000"
		},
		"c4dac5a8a0264fbc1055391c509cc3ee21a6e04c": {
			"balance": "6501000000000000000000"
		},
		"c1b2a0fb9cad45cd699192cd27540b88d3384279": {
			"balance": "500000000000000000000"
		},
		"b07cb9c12405b711807543c4934465f87f98bd2d": {
			"balance": "2000000000000000000000"
		},
		"c7f72bb758016b374714d4899bce22b4aec70a31": {
			"balance": "1072706000000000000000"
		},
		"0c480de9f7461002908b49f60fc61e2b62d3140b": {
			"balance": "10000000000000000000000"
		},
		"83d532d38d6dee3f60adc68b936133c7a2a1b0dd": {
			"balance": "500000000000000000000"
		},
		"12afbcba1427a6a39e7ba4849f7ab1c4358ac31b": {
			"balance": "20000000000000000000000"
		},
		"f8f6645e0dee644b3dad81d571ef9baf840021ad": {
			"balance": "2000000000000000000000"
		},
		"40cf890591eae4a18f812a2954cb295f633327e6": {
			"balance": "48132000000000000000"
		},
		"735b97f2fc1bd24b12076efaf3d1288073d20c8c": {
			"balance": "20000000000000000000"
		},
		"47c7e5efb48b3aed4b7c6e824b435f357df4c723": {
			"balance": "18200000000000000000"
		},
		"d34d708d7398024533a5a2b2309b19d3c55171bb": {
			"balance": "400000000000000000000"
		},
		"64370e87202645125a35b207af1231fb6072f9a7": {
			"balance": "200000000000000000000"
)E" + R"E(
		},
		"b055af4cadfcfdb425cf65ba6431078f07ecd5ab": {
			"balance": "100000000000000000000"
		},
		"c7de5e8eafb5f62b1a0af2195cf793c7894c9268": {
			"balance": "1000000000000000000000"
		},
		"c63cd7882118b8a91e074d4c8f4ba91851303b9a": {
			"balance": "260000000000000000000"
		},
		"164d7aac3eecbaeca1ad5191b753f173fe12ec33": {
			"balance": "744090000000000000000"
		},
		"e4fb26d1ca1eecba3d8298d9d148119ac2bbf580": {
			"balance": "400000000000000000000"
		},
		"613ac53be565d46536b820715b9b8d3ae68a4b95": {
			"balance": "3760000000000000000000"
		},
		"7f616c6f008adfa082f34da7d0650460368075fb": {
			"balance": "1000000000000000000000"
		},
		"9af100cc3dae83a33402051ce4496b16615483f6": {
			"balance": "2000000000000000000000"
		},
		"b45cca0d36826662683cf7d0b2fdac687f02d0c4": {
			"balance": "1000000000000000000000"
		},
		"93a6b3ab423010f981a7489d4aad25e2625c5741": {
			"balance": "20190033000000000000000"
		},
		"ee049af005974dd1c7b3a9ca8d9aa77175ba53aa": {
			"balance": "333333000000000000000"
		},
		"687927e3048bb5162ae7c15cf76bd124f9497b9e": {
			"balance": "2000000000000000000000"
		},
		"1aa40270d21e5cde86b6316d1ac3c533494b79ed": {
			"balance": "20000000000000000000"
		},
		"426259b0a756701a8b663528522156c0288f0f24": {
			"balance": "9900000000000000000000"
		},
		"91c75e3cb4aa89f34619a164e2a47898f5674d9c": {
			"balance": "2000000000000000000000"
		},
		"437983388ab59a4ffc215f8e8269461029c3f1c1": {
			"balance": "20000000000000000000000"
		},
		"272a131a5a656a7a3aca35c8bd202222a7592258": {
			"balance": "2674000000000000000000"
		},
		"bc0ca4f217e052753614d6b019948824d0d8688b": {
			"balance": "400000000000000000000"
		},
		"cc6c03bd603e09de54e9c4d5ac6d41cbce715724": {
			"balance": "98500000000000000000"
		},
		"d79aff13ba2da75d46240cac0a2467c656949823": {
			"balance": "1730000000000000000000"
		},
		"477b24eee8839e4fd19d1250bd0b6645794a61ca": {
			"balance": "8000000000000000000000"
		},
		"79fd6d48315066c204f9651869c1096c14fc9781": {
			"balance": "2000000000000000000000"
		},
		"1463a873555bc0397e575c2471cf77fa9db146e0": {
			"balance": "10000000000000000000000"
		},
		"89ab13ee266d779c35e8bb04cd8a90cc2103a95b": {
			"balance": "60000000000000000000000"
		},
		"90acced7e48c08c6b934646dfa0adf29dc94074f": {
			"balance": "56154000000000000000"
		},
		"31ea6eab19d00764e9a95e183f2b1b22fc7dc40f": {
			"balance": "20000000000000000000"
		},
		"87a53ea39f59a35bada8352521645594a1a714cb": {
			"balance": "1910000000000000000000"
		},
		"1e1aed85b86c6562cb8fa1eb6f8f3bc9dcae6e79": {
			"balance": "4516200000000000000000"
		},
		"e36a8ea87f1e99e8a2dc1b2608d166667c9dfa01": {
			"balance": "100000000000000000000"
		},
		"ec2cb8b9378dff31aec3c22e0e6dadff314ab5dd": {
			"balance": "2000000000000000000000"
		},
		"3cadeb3d3eed3f62311d52553e70df4afce56f23": {
			"balance": "4000000000000000000000"
		},
		"3ceca96bb1cdc214029cbc5e181d398ab94d3d41": {
			"balance": "80000000000000000000000"
		},
		"3283eb7f9137dd39bed55ffe6b8dc845f3e1a079": {
			"balance": "66224000000000000000"
		},
)E" + R"E(
		"0954a8cb5d321fc3351a7523a617d0f58da676a7": {
			"balance": "2506000000000000000000"
		},
		"de33d708a3b89e909eaf653b30fdc3a5d5ccb4b3": {
			"balance": "177300000000000000000"
		},
		"1c6702b3b05a5114bdbcaeca25531aeeb34835f4": {
			"balance": "26071500000000000000000"
		},
		"e5b96fc9ac03d448c1613ac91d15978145dbdfd1": {
			"balance": "200000000000000000000"
		},
		"fbf204c813f836d83962c7870c7808ca347fd33e": {
			"balance": "20000000000000000000"
		},
		"3b13631a1b89cb566548899a1d60915cdcc4205b": {
			"balance": "2000000000000000000000"
		},
		"a87f7abd6fa31194289678efb63cf584ee5e2a61": {
			"balance": "4000000000000000000000"
		},
		"c0a39308a80e9e84aaaf16ac01e3b01d74bd6b2d": {
			"balance": "136499000000000000000"
		},
		"ffd6da958eecbc016bab91058440d39b41c7be83": {
			"balance": "20000000000000000000000"
		},
		"0e3dd7d4e429fe3930a6414035f52bdc599d784d": {
			"balance": "40110000000000000000"
		},
		"e0663e8cd66792a641f56e5003660147880f018e": {
			"balance": "2000000000000000000000"
		},
		"5b78eca27fbdea6f26befba8972b295e7814364b": {
			"balance": "2000000000000000000000"
		},
		"ec9851bd917270610267d60518b54d3ca2b35b17": {
			"balance": "40000000000000000000000"
		},
		"bc9c95dfab97a574cea2aa803b5caa197cef0cff": {
			"balance": "420000000000000000000"
		},
		"100b4d0977fcbad4debd5e64a0497aeae5168fab": {
			"balance": "314500000000000000000"
		},
		"1b6610fb68bad6ed1cfaa0bbe33a24eb2e96fafb": {
			"balance": "152000000000000000000"
		},
		"b4524c95a7860e21840296a616244019421c4aba": {
			"balance": "8000000000000000000000"
		},
		"88975a5f1ef2528c300b83c0c607b8e87dd69315": {
			"balance": "83500000000000000000"
		},
		"853e6abaf44469c72f151d4e223819aced4e3728": {
			"balance": "2000000000000000000000"
		},
		"d604abce4330842e3d396ca73ddb5519ed3ec03f": {
			"balance": "163940000000000000000"
		},
		"d209482bb549abc4777bea6d7f650062c9c57a1c": {
			"balance": "320880000000000000000"
		},
		"590acbda37290c0d3ec84fc2000d7697f9a4b15d": {
			"balance": "500000000000000000000"
		},
		"571950ea2c90c1427d939d61b4f2de4cf1cfbfb0": {
			"balance": "20000000000000000000"
		},
		"cb94e76febe208116733e76e805d48d112ec9fca": {
			"balance": "1000000000000000000000"
		},
		"fa8e3b1f13433900737daaf1f6299c4887f85b5f": {
			"balance": "715000000000000000000"
		},
		"162d76c2e6514a3afb6fe3d3cb93a35c5ae783f1": {
			"balance": "2000000000000000000000"
		},
		"4bea288eea42c4955eb9faad2a9faf4783cbddac": {
			"balance": "28790618000000000000000"
		},
		"c8ab1a3cf46cb8b064df2e222d39607394203277": {
			"balance": "2000000000000000000000"
		},
		"318b2ea5f0aaa879c4d5e548ac9d92a0c67487b7": {
			"balance": "200000000000000000000"
		},
		"53c5fe0119e1e848640cee30adea96940f2a5d8b": {
			"balance": "21746000000000000000000"
		},
		"0701f9f147ec486856f5e1b71de9f117e99e2105": {
			"balance": "173360000000000000000"
		},
		"337cfe1157a5c6912010dd561533791769c2b6a6": {
			"balance": "1000000000000000000000"
		},
		"fd60d2b5af3d35f7aaf0c393052e79c4d823d985": {
			"balance": "56400000000000000000"
		},
		"0f049a8bdfd761de8ec02cee2829c4005b23c06b": {
)E" + R"E(
			"balance": "252000000000000000000"
		},
		"924bce7a853c970bb5ec7bb759baeb9c7410857b": {
			"balance": "13700000000000000000"
		},
		"16abb8b021a710bdc78ea53494b20614ff4eafe8": {
			"balance": "158000000000000000000"
		},
		"9e7f65a90e8508867bccc914256a1ea574cf07e3": {
			"balance": "1240000000000000000000"
		},
		"01d03815c61f416b71a2610a2daba59ff6a6de5b": {
			"balance": "9553100000000000000000"
		},
		"3df762049eda8ac6927d904c7af42f94e5519601": {
			"balance": "2000000000000000000000"
		},
		"5593c9d4b664730fd93ca60151c25c2eaed93c3b": {
			"balance": "200000000000000000000"
		},
		"e023f09b2887612c7c9cf1988e3a3a602b3394c9": {
			"balance": "2000000000000000000000"
		},
		"4c13980c32dcf3920b78a4a7903312907c1b123f": {
			"balance": "60024000000000000000"
		},
		"a282e969cac9f7a0e1c0cd90f5d0c438ac570da3": {
			"balance": "627760000000000000000"
		},
		"3b22da2a0271c8efe102532773636a69b1c17e09": {
			"balance": "502000000000000000000"
		},
		"1aa1021f550af158c747668dd13b463160f95a40": {
			"balance": "1470000000000000000000"
		},
		"f15178ffc43aa8070ece327e930f809ab1a54f9d": {
			"balance": "197600000000000000000"
		},
		"db1293a506e90cad2a59e1b8561f5e66961a6788": {
			"balance": "2000000000000000000000"
		},
		"88c361640d6b69373b081ce0c433bd590287d5ec": {
			"balance": "50000000000000000000000"
		},
		"3737216ee91f177732fb58fa4097267207e2cf55": {
			"balance": "1520000000000000000000"
		},
		"a16d9e3d63986159a800b46837f45e8bb980ee0b": {
			"balance": "2030400000000000000000"
		},
		"ec76f12e57a65504033f2c0bce6fc03bd7fa0ac4": {
			"balance": "3580000000000000000000"
		},
		"d9f1b26408f0ec67ad1d0d6fe22e8515e1740624": {
			"balance": "24000000000000000000"
		},
		"716ba01ead2a91270635f95f25bfaf2dd610ca23": {
			"balance": "44750000000000000000000"
		},
		"42a98bf16027ce589c4ed2c95831e2724205064e": {
			"balance": "10000000000000000000000"
		},
		"0f88aac9346cb0e7347fba70905475ba8b3e5ece": {
			"balance": "10000000000000000000000"
		},
		"2d8c52329f38d2a2fa9cbaf5c583daf1490bb11c": {
			"balance": "20000000000000000000"
		},
		"3cea302a472a940379dd398a24eafdbadf88ad79": {
			"balance": "3000000000000000000000"
		},
		"a29d5bda74e003474872bd5894b88533ff64c2b5": {
			"balance": "10000000000000000000000"
		},
		"2d23766b6f6b05737dad80a419c40eda4d77103e": {
			"balance": "3820000000000000000000"
		},
		"b07249e055044a9155359a402937bbd954fe48b6": {
			"balance": "100000000000000000000"
		},
		"f1e980c559a1a8e5e50a47f8fffdc773b7e06a54": {
			"balance": "30104784000000000000000"
		},
		"8275cd684c3679d5887d03664e338345dc3cdde1": {
			"balance": "15800000000000000000"
		},
		"b27c1a24204c1e118d75149dd109311e07c073ab": {
			"balance": "3100000000000000000000"
		},
		"451b3699475bed5d7905f8905aa3456f1ed788fc": {
			"balance": "2560000000000000000000"
		},
		"31ad4d9946ef09d8e988d946b1227f9141901736": {
			"balance": "22880000000000000000000"
		},
		"52b8a9592634f7300b7c5c59a3345b835f01b95c": {
			"balance": "2000000000000000000000"
		},
		"b161725fdcedd17952d57b23ef285b7e4b1169e8": {
			"balance": "50071000000000000000"
)E" + R"E(
		},
		"74fc5a99c0c5460503a13b0509459da19ce7cd90": {
			"balance": "200000000000000000000"
		},
		"d99df7421b9382e42c89b006c7f087702a0757c0": {
			"balance": "480000000000000000000"
		},
		"8a4f4a7f52a355ba105fca2072d3065fc8f7944b": {
			"balance": "500000000000000000000"
		},
		"12316fc7f178eac22eb2b25aedeadf3d75d00177": {
			"balance": "19999999000000000000000"
		},
		"f598db2e09a8a5ee7d720d2b5c43bb126d11ecc2": {
			"balance": "200000000000000000000"
		},
		"37b8beac7b1ca38829d61ab552c766f48a10c32f": {
			"balance": "400000000000000000000"
		},
		"851dc38adb4593729a76f33a8616dab6f5f59a77": {
			"balance": "100000000000000000000"
		},
		"bf4096bc547dbfc4e74809a31c039e7b389d5e17": {
			"balance": "3940000000000000000000"
		},
		"98d3731992d1d40e1211c7f735f2189afa0702e0": {
			"balance": "8000000000000000000000"
		},
		"0f4073c1b99df60a1549d69789c7318d9403a814": {
			"balance": "20000000000000000000000"
		},
		"a430995ddb185b9865dbe62539ad90d22e4b73c2": {
			"balance": "10000000000000000000000"
		},
		"898c72dd736558ef9e4be9fdc34fef54d7fc7e08": {
			"balance": "1000000000000000000000"
		},
		"f9b617f752edecae3e909fbb911d2f8192f84209": {
			"balance": "2674000000000000000000"
		},
		"e1ae029b17e373cde3de5a9152201a14cac4e119": {
			"balance": "99968000000000000000"
		},
		"d8e8474292e7a051604ca164c0707783bb2885e8": {
			"balance": "13370000000000000000000"
		},
		"f476f2cb7208a32e051fd94ea8662992638287a2": {
			"balance": "100000000000000000000"
		},
		"3a84e950ed410e51b7e8801049ab2634b285fea1": {
			"balance": "18690000000000000000000"
		},
		"5b7784caea01799ca30227827667ce207c5cbc76": {
			"balance": "2000000000000000000000"
		},
		"3af65b3e28895a4a001153391d1e69c31fb9db39": {
			"balance": "3940000000000000000000"
		},
		"95fb5afb14c1ef9ab7d179c5c300503fd66a5ee2": {
			"balance": "34225000000000000000"
		},
		"a8446c4781a737ac4328b1e15b8a0b3fbb0fd668": {
			"balance": "21390500000000000000000"
		},
		"4888fb25cd50dbb9e048f41ca47d78b78a27c7d9": {
			"balance": "17300000000000000000000"
		},
		"566c10d638e8b88b47d6e6a414497afdd00600d4": {
			"balance": "99960000000000000000"
		},
		"bd47f5f76e3b930fd9485209efa0d4763da07568": {
			"balance": "1000000000000000000000"
		},
		"1e1c6351776ac31091397ecf16002d979a1b2d51": {
			"balance": "1400000000000000000000"
		},
		"edf603890228d7d5de9309942b5cad4219ef9ad7": {
			"balance": "5000000000000000000000"
		},
		"1923cfc68b13ea7e2055803645c1e320156bd88d": {
			"balance": "1337000000000000000000"
		},
		"8f8f37d0ad8f335d2a7101b41156b688a81a9cbe": {
			"balance": "70000000000000000000"
		},
		"63334fcf1745840e4b094a3bb40bb76f9604c04c": {
			"balance": "3978000000000000000000"
		},
		"001762430ea9c3a26e5749afdb70da5f78ddbb8c": {
			"balance": "200000000000000000000"
		},
		"512116817ba9aaf843d1507c65a5ea640a7b9eec": {
			"balance": "50000000000000000000"
		},
		"2961fb391c61957cb5c9e407dda29338d3b92c80": {
			"balance": "999942000000000000000"
		},
		"fc2952b4c49fedd0bc0528a308495e6d6a1c71d6": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"13ec812284026e409bc066dfebf9d5a4a2bf801e": {
			"balance": "1610000000000000000000"
		},
		"ef463c2679fb279164e20c3d2691358773a0ad95": {
			"balance": "2000000000000000000000"
		},
		"3aadf98b61e5c896e7d100a3391d3250225d61df": {
			"balance": "234000000000000000000"
		},
		"e8137fc1b2ec7cc7103af921899b4a39e1d959a1": {
			"balance": "1490000000000000000000"
		},
		"b1a2b43a7433dd150bb82227ed519cd6b142d382": {
			"balance": "2738000000000000000000"
		},
		"c1f39bd35dd9cec337b96f47c677818160df37b7": {
			"balance": "20000000000000000000"
		},
		"b587b44a2ca79e4bc1dd8bfdd43a207150f2e7e0": {
			"balance": "630400000000000000000"
		},
		"41485612d03446ec4c05e5244e563f1cbae0f197": {
			"balance": "970000000000000000000"
		},
		"a12623e629df93096704b16084be2cd89d562da4": {
			"balance": "8500000000000000000000"
		},
		"3f2f381491797cc5c0d48296c14fd0cd00cdfa2d": {
			"balance": "804000000000000000000"
		},
		"9470cc36594586821821c5c996b6edc83b6d5a32": {
			"balance": "24000000000000000000"
		},
		"3605372d93a9010988018f9f315d032ed1880fa1": {
			"balance": "500066000000000000000"
		},
		"12632388b2765ee4452b50161d1fffd91ab81f4a": {
			"balance": "740000000000000000000"
		},
		"274a3d771a3d709796fbc4d5f48fce2fe38c79d6": {
			"balance": "20000000000000000000"
		},
		"d60a52580728520df7546bc1e283291788dbae0c": {
			"balance": "999910000000000000000"
		},
		"1ab53a11bcc63ddfaa40a02b9e186496cdbb8aff": {
			"balance": "1996800000000000000000"
		},
		"c282e6993fbe7a912ea047153ffd9274270e285b": {
			"balance": "139939000000000000000"
		},
		"a291e9c7990d552dd1ae16cebc3fca342cbaf1d1": {
			"balance": "20000000000000000000000"
		},
		"5547fdb4ae11953e01292b7807fa9223d0e4606a": {
			"balance": "98940000000000000000"
		},
		"bded11612fb5c6da99d1e30e320bc0995466141e": {
			"balance": "400000000000000000000"
		},
		"b73b4ff99eb88fd89b0b6d57a9bc338e886fa06a": {
			"balance": "32000000000000000000"
		},
		"b1c751786939bba0d671a677a158c6abe7265e46": {
			"balance": "10000000000000000000000"
		},
		"e881bbbe69722d81efecaa48d1952a10a2bfac8f": {
			"balance": "16000000000000000000000"
		},
		"fe96c4cd381562401aa32a86e65b9d52fa8aee27": {
			"balance": "2640000000000000000000"
		},
		"683dba36f7e94f40ea6aea0d79b8f521de55076e": {
			"balance": "140000000000000000000"
		},
		"5ac2908b0f398c0df5bac2cb13ca7314fba8fa3d": {
			"balance": "199800000000000000000"
		},
		"8914a680a5aec5226d4baaec2e5552b44dd7c874": {
			"balance": "100076000000000000000"
		},
		"041170f581de80e58b2a045c8f7c1493b001b7cb": {
			"balance": "889800000000000000000"
		},
		"4665e47396c7db97eb2a03d90863d5d4ba319a94": {
			"balance": "600000000000000000000"
		},
		"ed4be04a052d7accb3dcce90319dba4020ab2c68": {
			"balance": "37547947000000000000000"
		},
		"4b0619d9d8aa313a9531ac7dbe04ca0d6a5ad1b6": {
			"balance": "2000000000000000000000"
		},
		"a21442ab05340ade68c915f3c3399b9955f3f7eb": {
			"balance": "775000000000000000000"
		},
		"655934da8e744eaa3de34dbbc0894c4eda0b61f2": {
			"balance": "200000000000000000000"
		},
		"6038740ae28d66ba93b0be08482b3205a0f7a07b": {
)E" + R"E(
			"balance": "316000000000000000000"
		},
		"99924a9816bb7ddf3fec1844828e9ad7d06bf4e6": {
			"balance": "1760000000000000000000"
		},
		"6847825bdee8240e28042c83cad642f286a3bddc": {
			"balance": "1500000000000000000000"
		},
		"a718aaad59bf395cba2b23e09b02fe0c89816247": {
			"balance": "999600000000000000000"
		},
		"2c89f5fdca3d155409b638b98a742e55eb4652b7": {
			"balance": "98500000000000000000000"
		},
		"1a7044e2383f8708305b495bd1176b92e7ef043a": {
			"balance": "200000000000000000000"
		},
		"282e80a554875a56799fa0a97f5510e795974c4e": {
			"balance": "1000000000000000000000"
		},
		"ffb3bcc3196a8c3cb834cec94c34fed35b3e1054": {
			"balance": "1340000000000000000000"
		},
		"d135794b149a18e147d16e621a6931f0a40a969a": {
			"balance": "20000000000000000000000"
		},
		"6b94615db750656ac38c7e1cf29a9d13677f4e15": {
			"balance": "12000000000000000000000"
		},
		"ecbe425e670d39094e20fb5643a9d818eed236de": {
			"balance": "5000000000000000000000"
		},
		"511e0efb04ac4e3ff2e6550e498295bfcd56ffd5": {
			"balance": "668500000000000000000"
		},
		"ff65511cada259260c1ddc41974ecaecd32d6357": {
			"balance": "1760000000000000000000"
		},
		"9ffc5fe06f33f5a480b75aa94eb8556d997a16c0": {
			"balance": "20000000000000000000"
		},
		"57df23bebdc65eb75feb9cb2fad1c073692b2baf": {
			"balance": "4000000000000000000000"
		},
		"207ef80b5d60b6fbffc51f3a64b8c72036a5abbd": {
			"balance": "6685000000000000000000"
		},
		"c573e841fa08174a208b060ccb7b4c0d7697127f": {
			"balance": "668500000000000000000"
		},
		"411610b178d5617dfab934d293f512a93e5c10e1": {
			"balance": "170000000000000000000"
		},
		"9991614c5baa47dd6c96874645f97add2c3d8380": {
			"balance": "1970000000000000000000"
		},
		"2d3480bf0865074a72c7759ee5137b4d70c51ce9": {
			"balance": "200000000000000000000"
		},
		"9d40e012f60425a340d82d03a1c757bfabc706fb": {
			"balance": "169799000000000000000"
		},
		"47648bed01f3cd3249084e635d14daa9e7ec3c8a": {
			"balance": "194000000000000000000"
		},
		"a5ff62222d80c013cec1a0e8850ed4d354dac16d": {
			"balance": "207600000000000000000"
		},
		"f80d3619702fa5838c48391859a839fb9ce7160f": {
			"balance": "1992800000000000000000"
		},
		"7c0f5e072043c9ee740242197e78cc4b98cdf960": {
			"balance": "200000000000000000000"
		},
		"a40aa2bbce0c72b4d0dfffcc42715b2b54b01bfa": {
			"balance": "1000000000000000000000"
		},
		"2eeed50471a1a2bf53ee30b1232e6e9d80ef866d": {
			"balance": "20000000000000000000"
		},
		"0c2808b951ed9e872d7b32790fcc5994ae41ffdc": {
			"balance": "102000000000000000000000"
		},
		"7f06c89d59807fa60bc60136fcf814cbaf2543bd": {
			"balance": "10000000000000000000000"
		},
		"8d4b603c5dd4570c34669515fdcc665890840c77": {
			"balance": "18200000000000000000"
		},
		"d5e5c135d0c4c3303934711993d0d16ff9e7baa0": {
			"balance": "2000000000000000000000"
		},
		"241361559feef80ef137302153bd9ed2f25db3ef": {
			"balance": "20000000000000000000000"
		},
		"db63122de7037da4971531fae9af85867886c692": {
			"balance": "277000000000000000000"
		},
		"417e4e2688b1fd66d821529e46ed4f42f8b3db3d": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"127db1cadf1b771cbd7475e1b272690f558c8565": {
			"balance": "14000000000000000000000"
		},
		"48659d8f8c9a2fd44f68daa55d23a608fbe500dc": {
			"balance": "2000000000000000000000"
		},
		"b3a64b1176724f5409e1414a3523661baee74b4a": {
			"balance": "25610000000000000000"
		},
		"aa14422d6f0ae5a758194ed15780c838d67f1ee1": {
			"balance": "28503824000000000000000"
		},
		"a0a0e65204541fca9b2fb282cd95138fae16f809": {
			"balance": "10000000000000000000000"
		},
		"d2107b353726c3a2b46566eaa7d9f80b5d21dbe3": {
			"balance": "20000000000000000000"
		},
		"e4cafb727fb5c6b70bb27533b8a9ccc9ef6888e1": {
			"balance": "300443000000000000000"
		},
		"09f3f601f605441140586ce0656fa24aa5b1d9ae": {
			"balance": "1539400000000000000000"
		},
		"87fcbe7c4193ffcb08143779c9bec83fe7fda9fc": {
			"balance": "100275000000000000000"
		},
		"03ebc63fda6660a465045e235fbe6e5cf195735f": {
			"balance": "141840000000000000000"
		},
		"bdbaf6434d40d6355b1e80e40cc4ab9c68d96116": {
			"balance": "100000000000000000000"
		},
		"4e2225a1bb59bc88a2316674d333b9b0afca6655": {
			"balance": "155000000000000000000"
		},
		"4dc3da13b2b4afd44f5d0d3189f444d4ddf91b1b": {
			"balance": "2000000000000000000000"
		},
		"4ba8e0117fc0b6a3e56b24a3a58fe6cef442ff98": {
			"balance": "5640000000000000000000"
		},
		"27146913563aa745e2588430d9348e86ea7c3510": {
			"balance": "400000000000000000000"
		},
		"4c5afe40f18ffc48d3a1aec41fc29de179f4d297": {
			"balance": "2000000000000000000000"
		},
		"8a810114b2025db9fbb50099a6e0cb9e2efa6bdc": {
			"balance": "1910000000000000000000"
		},
		"2dee90a28f192d676a8773232b56f18f239e2fad": {
			"balance": "18587970000000000000000"
		},
		"60676e92d18b000509c61de540e6c5ddb676d509": {
			"balance": "1200000000000000000000"
		},
		"9bfc659c9c601ea42a6b21b8f17084ec87d70212": {
			"balance": "10000000000000000000000"
		},
		"5d5d6e821c6eef96810c83c491468560ef70bfb5": {
			"balance": "2000000000000000000000"
		},
		"d5787668c2c5175b01a8ee1ac3ecc9c8b2aba95a": {
			"balance": "1999944000000000000000"
		},
		"33b336f5ba5edb7b1ccc7eb1a0d984c1231d0edc": {
			"balance": "2000000000000000000000"
		},
		"3abb8adfc604f48d5984811d7f1d52fef6758270": {
			"balance": "4475000000000000000000"
		},
		"980a84b686fc31bdc83c221058546a71b11f838a": {
			"balance": "779471000000000000000"
		},
		"0b507cf553568daaf65504ae4eaa17a8ea3cdbf5": {
			"balance": "2000000000000000000000"
		},
		"896009526a2c7b0c09a6f63a80bdf29d9c87de9c": {
			"balance": "3462830000000000000000"
		},
		"9696052138338c722f1140815cf7749d0d3b3a74": {
			"balance": "500000000000000000000"
		},
		"3831757eae7557cb8a37a4b10644b63e4d3b3c75": {
			"balance": "200000000000000000000"
		},
		"62dc72729024375fc37cbb9c7c2393d10233330f": {
			"balance": "2000000000000000000000"
		},
		"44098866a69b68c0b6bc168229b9603587058967": {
			"balance": "188000000000000000000"
		},
		"25adb8f96f39492c9bb47c5edc88624e46075697": {
			"balance": "26740000000000000000000"
		},
		"fd4de8e3748a289cf7d060517d9d38388db01fb8": {
			"balance": "250000000000000000000"
		},
)E" + R"E(
		"6be7595ea0f068489a2701ec4649158ddc43e178": {
			"balance": "2000000000000000000000"
		},
		"d402b4f6a099ebe716cb14df4f79c0cd01c6071b": {
			"balance": "2000000000000000000000"
		},
		"a07682000b1bcf3002f85c80c0fa2949bd1e82fd": {
			"balance": "4000000000000000000000"
		},
		"eb4f00e28336ea09942588eeac921811c522143c": {
			"balance": "2000000000000000000000"
		},
		"8f31c7005197ec997a87e69bec48649ab94bb2a5": {
			"balance": "4000000000000000000000"
		},
		"e7fd8fd959aed2767ea7fa960ce1db53af802573": {
			"balance": "1000000000000000000000"
		},
		"a8ef9ad274436042903e413c3b0c62f5f52ed584": {
			"balance": "10000000000000000000000"
		},
		"d83ad260e9a6f432fb6ea28743299b4a09ad658c": {
			"balance": "2000000000000000000000"
		},
		"b5c816a8283ca4df68a1a73d63bd80260488df08": {
			"balance": "200000000000000000000"
		},
		"d7d3c75920590438b82c3e9515be2eb6ed7a8b1a": {
			"balance": "60000000000000000000000"
		},
		"af3cb5965933e7dad883693b9c3e15beb68a4873": {
			"balance": "2000000000000000000000"
		},
		"6e899e59a9b41ab7ea41df7517860f2acb59f4fd": {
			"balance": "20000000000000000000000"
		},
		"527a8ca1268633a6c939c5de1b929aee92aeac8d": {
			"balance": "900000000000000000000"
		},
		"1680cec5021ee93050f8ae127251839e74c1f1fd": {
			"balance": "13098657000000000000000"
		},
		"ff7843c7010aa7e61519b762dfe49124a76b0e4e": {
			"balance": "933580000000000000000000"
		},
		"140fba58dbc04803d84c2130f01978f9e0c73129": {
			"balance": "400000000000000000000"
		},
		"0261ad3a172abf1315f0ffec3270986a8409cb25": {
			"balance": "203500000000000000000"
		},
		"ab5a79016176320973e8cd38f6375530022531c0": {
			"balance": "1000000000000000000000"
		},
		"fca73eff8771c0103ba3cc1a9c259448c72abf0b": {
			"balance": "1000000000000000000000"
		},
		"07d41217badca5e0e60327d845a3464f0f27f84a": {
			"balance": "4000000000000000000000"
		},
		"2c1c19114e3d6de27851484b8d2715e50f8a1065": {
			"balance": "100000000000000000000"
		},
		"abd21eff954fc6a7de26912a7cbb303a6607804e": {
			"balance": "1517000000000000000000"
		},
		"f303d5a816affd97e83d9e4dac2f79072bb0098f": {
			"balance": "960000000000000000000"
		},
		"114cfefe50170dd97ae08f0a44544978c599548d": {
			"balance": "863000000000000000000"
		},
		"647b85044df2cf0b4ed4882e88819fe22ae5f793": {
			"balance": "1000032000000000000000"
		},
		"1b130d6fa51d5c48ec8d1d52dc8a227be8735c8a": {
			"balance": "2000000000000000000000"
		},
		"0d9d3f9bc4a4c6efbd59679b69826bc1f63d9916": {
			"balance": "600000000000000000000"
		},
		"c765e00476810947816af142d46d2ee7bca8cc4f": {
			"balance": "500000000000000000000"
		},
		"b57b04fa23d1203fae061eac4542cb60f3a57637": {
			"balance": "191000000000000000000"
		},
		"e192489b85a982c1883246d915b229cb13207f38": {
			"balance": "5000000000000000000000"
		},
		"5f483ffb8f680aedf2a38f7833afdcde59b61e4b": {
			"balance": "2000000000000000000000"
		},
		"b46d1182e5aacaff0d26b2fcf72f3c9ffbcdd97d": {
			"balance": "3139000000000000000000"
		},
		"59c7f785c93160e5807ed34e5e534bc6188647a7": {
			"balance": "640000000000000000000"
		},
		"18e4ce47483b53040adbab35172c01ef64506e0c": {
)E" + R"E(
			"balance": "9000000000000000000000"
		},
		"296d66b521571a4e4103a7f562c511e6aa732d81": {
			"balance": "668500000000000000000"
		},
		"bcd99edc2160f210a05e3a1fa0b0434ced00439b": {
			"balance": "2000000000000000000000"
		},
		"f14f0eb86db0eb68753f16918e5d4b807437bd3e": {
			"balance": "200000000000000000000"
		},
		"60d5667140d12614b21c8e5e8a33082e32dfcf23": {
			"balance": "20000000000000000000000"
		},
		"8ccabf25077f3aa41545344d53be1b2b9c339000": {
			"balance": "1695400000000000000000"
		},
		"8cc0d7c016fa7aa950114aa1db094882eda274ea": {
			"balance": "159800000000000000000"
		},
		"c71145e529c7a714e67903ee6206e4c3042b6727": {
			"balance": "1430000000000000000000"
		},
		"c5e9939334f1252ed2ba26814487dfd2982b3128": {
			"balance": "70000000000000000000"
		},
		"f09b3e87f913ddfd57ae8049c731dba9b636dfc3": {
			"balance": "608000000000000000000"
		},
		"4349225a62f70aea480a029915a01e5379e64fa5": {
			"balance": "2598000000000000000000"
		},
		"666b4f37d55d63b7d056b615bb74c96b3b01991a": {
			"balance": "4000000000000000000000"
		},
		"8bd6b1c6d74d010d1008dba6ef835d4430b35c32": {
			"balance": "50000000000000000000"
		},
		"7363cd90fbab5bb8c49ac20fc62c398fe6fb744c": {
			"balance": "2000000000000000000000"
		},
		"b7479dab5022c4d5dbaaf8de171b4e951dd1a457": {
			"balance": "80000000000000000000"
		},
		"5a5468fa5ca226c7532ecf06e1bc1c45225d7ec9": {
			"balance": "1910000000000000000000"
		},
		"32a20d028e2c6218b9d95b445c771524636a22ef": {
			"balance": "9500000000000000000000"
		},
		"1bd28cd5c78aee51357c95c1ef9235e7c18bc854": {
			"balance": "2000000000000000000000"
		},
		"693492a5c51396a482881669ccf6d8d779f00951": {
			"balance": "345827000000000000000"
		},
		"bd723b289a7367b6ece2455ed61edb49670ab9c4": {
			"balance": "4999995000000000000000"
		},
		"1be3542c3613687465f15a70aeeb81662b65cca8": {
			"balance": "2000000000000000000000"
		},
		"5803e68b34da121aef08b602badbafb4d12481ca": {
			"balance": "18000000000000000000000"
		},
		"9ac907ee85e6f3e223459992e256a43fa08fa8b2": {
			"balance": "10000000000000000000000"
		},
		"833b6a8ec8da408186ac8a7d2a6dd61523e7ce84": {
			"balance": "16000000000000000000000"
		},
		"64628c6fb8ec743adbd87ce5e018d531d9210437": {
			"balance": "26740000000000000000"
		},
		"566c28e34c3808d9766fe8421ebf4f2b1c4f7d77": {
			"balance": "1970000000000000000000"
		},
		"171ad9a04bedc8b861e8ed4bddf5717813b1bb48": {
			"balance": "400000000000000000000"
		},
		"4f85bc1fc5cbc9c001e8f1372e07505370d8c71f": {
			"balance": "940000000000000000000"
		},
		"6d2f976734b9d0070d1883cf7acab8b3e4920fc1": {
			"balance": "10000000000000000000000"
		},
		"357a02c0a9dfe287de447fb67a70ec5b62366647": {
			"balance": "26740000000000000000"
		},
		"44a01fb04ac0db2cce5dbe281e1c46e28b39d878": {
			"balance": "1999944000000000000000"
		},
		"3630c5e565ceaa8a0f0ffe32875eae2a6ce63c19": {
			"balance": "170016000000000000000"
		},
		"334340ee4b9cdc81f850a75116d50ee9b69825bf": {
			"balance": "2000000000000000000000"
		},
		"c0afb7d8b79370cfd663c68cc6b9702a37cd9eff": {
			"balance": "1000000000000000000000"
)E" + R"E(
		},
		"2016895df32c8ed5478269468423aea7b7fbce50": {
			"balance": "20000000000000000000"
		},
		"1e2fe4e4a77d141ff49a0c7fbc95b0a2b283eeeb": {
			"balance": "2000000000000000000000"
		},
		"260df8943a8c9a5dba7945327fd7e0837c11ad07": {
			"balance": "200000000000000000000"
		},
		"32fbeed6f626fcdfd51acafb730b9eeff612f564": {
			"balance": "2000000000000000000000"
		},
		"9bd88068e13075f3a8cac464a5f949d6d818c0f6": {
			"balance": "6000000000000000000000"
		},
		"ab4572fbb1d72b575d69ec6ad17333873e8552fc": {
			"balance": "1999942000000000000000"
		},
		"e44ea51063405154aae736be2bf1ee3b9be639ae": {
			"balance": "4000000000000000000000"
		},
		"617f20894fa70e94a86a49cd74e03238f64d3cd9": {
			"balance": "5000057000000000000000"
		},
		"3e914e3018ac00449341c49da71d04dfeeed6221": {
			"balance": "4000000000000000000000"
		},
		"590181d445007bd0875aaf061c8d51153900836a": {
			"balance": "2000000000000000000000"
		},
		"27987110221a880826adb2e7ab5eca78c6e31aec": {
			"balance": "4000000000000000000000"
		},
		"06618e9d5762df62028601a81d4487d6a0ecb80e": {
			"balance": "1337000000000000000000"
		},
		"8cc652dd13e7fe14dabbb36d5d320db9ffee8a54": {
			"balance": "1790000000000000000000"
		},
		"8973aefd5efaee96095d9e288f6a046c97374b43": {
			"balance": "141000000000000000000"
		},
		"dbd51cdf2c3bfacdff106221de2e19ad6d420414": {
			"balance": "1760000000000000000000"
		},
		"25697ef20cccaa70d32d376f8272d9c1070c3d78": {
			"balance": "200000000000000000000"
		},
		"0726c42e00f45404836eb1e280d073e7059687f5": {
			"balance": "1623331000000000000000"
		},
		"5e0785532c7723e4c0af9357d5274b73bdddddde": {
			"balance": "25000088000000000000000"
		},
		"38430e931d93be01b4c3ef0dc535f1e0a9610063": {
			"balance": "10000000000000000000000"
		},
		"143d536b8b1cb84f56a39e0bc81fd5442bcacce1": {
			"balance": "100000000000000000000"
		},
		"5c6d041da7af4487b9dc48e8e1f60766d0a56dbc": {
			"balance": "1457800000000000000000"
		},
		"f9bfb59d538afc4874d4f5941b08c9730e38e24b": {
			"balance": "40000000000000000000"
		},
		"83dbfd8eda01d0de8e158b16d0935fc2380a5dc7": {
			"balance": "600000000000000000000"
		},
		"0e6cd664ad9c1ed64bf98749f40644b626e3792c": {
			"balance": "60000000000000000000000"
		},
		"ce2e0da8934699bb1a553e55a0b85c169435bea3": {
			"balance": "4999962000000000000000"
		},
		"a39bfee4aec9bd75bd22c6b672898ca9a1e95d32": {
			"balance": "10000000000000000000000"
		},
		"1bc44c8761231ba1f11f5faa40fa669a013e12ce": {
			"balance": "203586000000000000000"
		},
		"68809af5d532a11c1a4d6e32aac75c4c52b08ead": {
			"balance": "10000000000000000000000"
		},
		"80cc21bd99f39005c58fe4a448909220218f66cb": {
			"balance": "1000072000000000000000"
		},
		"1080c1d8358a15bc84dac8253c6883319020df2c": {
			"balance": "2674000000000000000000"
		},
		"9eaf6a328a4076024efa6b67b48b21eedcc0f0b8": {
			"balance": "158000000000000000000"
		},
		"1e7b5e4d1f572becf2c00fc90cb4767b4a6e33d4": {
			"balance": "112970000000000000000"
		},
		"acbd185589f7a68a67aa4b1bd65077f8c64e4e21": {
			"balance": "200000000000000000000"
		},
)E" + R"E(
		"ff78541756ab2b706e0d70b18adb700fc4f1643d": {
			"balance": "43250000000000000000000"
		},
		"7f0ec3db804692d4d1ea3245365aab0590075bc4": {
			"balance": "4000000000000000000000"
		},
		"4a918032439159bb315b6725b6830dc83697739f": {
			"balance": "343800000000000000000"
		},
		"bc1b021a78fde42d9b5226d6ec26e06aa3670090": {
			"balance": "80000000000000000000"
		},
		"2f2523cc834f0086052402626296675186a8e582": {
			"balance": "16000000000000000000000"
		},
		"9db2e15ca681f4c66048f6f9b7941ed08b1ff506": {
			"balance": "4000000000000000000000"
		},
		"20b9a9e6bd8880d9994ae00dd0b9282a0beab816": {
			"balance": "500000000000000000000"
		},
		"3bddbc8134f77d55597fc97c26d26698090604eb": {
			"balance": "13700000000000000000"
		},
		"80c3a9f695b16db1597286d1b3a8b7696c39fa27": {
			"balance": "100000000000000000000"
		},
		"53194d8afa3e883502767edbc30586af33b114d3": {
			"balance": "2000000000000000000000"
		},
		"e2efd0a9bc407ece03d67e8ec8e9d283f48d2a49": {
			"balance": "12280000000000000000000"
		},
		"1cb450920078aab2317c7db3b38af7dd298b2d41": {
			"balance": "340000000000000000000"
		},
		"ca8276c477b4a07b80107b843594189607b53bec": {
			"balance": "6000000000000000000000"
		},
		"147f4210ab5804940a0b7db8c14c28396b62a6bf": {
			"balance": "2000000000000000000000"
		},
		"d3df3b53cb3b4755de54e180451cc44c9e8ae0aa": {
			"balance": "659801000000000000000"
		},
		"f7c708015071d4fb0a3a2a09a45d156396e3349e": {
			"balance": "3000000000000000000000"
		},
		"a8cafac32280d021020bf6f2a9782883d7aabe12": {
			"balance": "100000000000000000000"
		},
		"399aa6f5d078cb0970882bc9992006f8fbdf3471": {
			"balance": "1000000000000000000000"
		},
		"15669180dee29598869b08a721c7d24c4c0ee63f": {
			"balance": "1000000000000000000000"
		},
		"bba8ab22d2fedbcfc63f684c08afdf1c175090b5": {
			"balance": "99091000000000000000"
		},
		"5e5a441974a83d74c687ebdc633fb1a49e7b1ad7": {
			"balance": "3000000000000000000000"
		},
		"98b769cc305cecfb629a00c907069d7ef9bc3a12": {
			"balance": "26000000000000000000"
		},
		"c820c711f07705273807aaaa6de44d0e4b48be2e": {
			"balance": "155000000000000000000"
		},
		"12aa7d86ddfbad301692feac8a08f841cb215c37": {
			"balance": "137000000000000000000"
		},
		"6ff5d361b52ad0b68b1588607ec304ae5665fc98": {
			"balance": "1940000000000000000000"
		},
		"2382a9d48ec83ea3652890fd0ee79c907b5b2dc1": {
			"balance": "133700000000000000000"
		},
		"b2a144b1ea67b9510f2267f9da39d3f93de26642": {
			"balance": "2000000000000000000000"
		},
		"b3e20eb4de18bd060221689894bee5aeb25351ee": {
			"balance": "73535000000000000000"
		},
		"101a0a64f9afcc448a8a130d4dfcbee89537d854": {
			"balance": "15200000000000000000000"
		},
		"1b826fb3c012b0d159e294ba5b8a499ff3c0e03c": {
			"balance": "2000000000000000000000"
		},
		"aafb7b013aa1f8541c7e327bf650adbd194c208f": {
			"balance": "1358000000000000000000"
		},
		"96eb523e832f500a017de13ec27f5d366c560eff": {
			"balance": "307600000000000000000"
		},
		"c7bf17c4c11f98941f507e77084fffbd2dbd3db5": {
			"balance": "1000000000000000000000"
		},
		"840ec83ea93621f034e7bb3762bb8e29ded4c479": {
)E" + R"E(
			"balance": "2500000000000000000000"
		},
		"0e9c511864a177f49be78202773f60489fe04e52": {
			"balance": "6000000000000000000000"
		},
		"f6f1a44309051c6b25e47dff909b179bb9ab591c": {
			"balance": "1940000000000000000000"
		},
		"63fe6bcc4b8a9850abbe75803730c932251f145b": {
			"balance": "18200000000000000000"
		},
		"f88b58db37420b464c0be88b45ee2b95290f8cfa": {
			"balance": "40000000000000000000"
		},
		"9d4d321177256ebd9afbda304135d517c3dc5693": {
			"balance": "616000000000000000000"
		},
		"8c1fbe5f0aea359c5aa1fa08c8895412ca8e05a6": {
			"balance": "1000000000000000000000"
		},
		"cb0dd7cf4e5d8661f6028943a4b9b75c914436a7": {
			"balance": "120000000000000000000000"
		},
		"a3979a92760a135adf69d72f75e167755f1cb8c3": {
			"balance": "100000000000000000000"
		},
		"ca22cda3606da5cad013b8074706d7e9e721a50c": {
			"balance": "6816200000000000000000"
		},
		"157559adc55764cc6df79323092534e3d6645a66": {
			"balance": "6000000000000000000000"
		},
		"4f52ad6170d25b2a2e850eadbb52413ff2303e7f": {
			"balance": "3040000000000000000000"
		},
		"eed28c3f068e094a304b853c950a6809ebcb03e0": {
			"balance": "17300000000000000000000"
		},
		"2e47f287f498233713850d3126823cc67dcee255": {
			"balance": "14600000000000000000"
		},
		"6c359e58a13d4578a9338e335c67e7639f5fb4d7": {
			"balance": "218000000000000000000"
		},
		"4968a2cedb457555a139295aea28776e54003c87": {
			"balance": "10092310000000000000000"
		},
		"4041374b0feef4792e4b33691fb86897a4ff560c": {
			"balance": "365000000000000000000"
		},
		"83e48055327c28b5936fd9f4447e73bdb2dd3376": {
			"balance": "2674000000000000000000"
		},
		"32b7feebc5c59bf65e861c4c0be42a7611a5541a": {
			"balance": "2212000000000000000000"
		},
		"21a6db6527467bc6dad54bc16e9fe2953b6794ed": {
			"balance": "14000000000000000000000"
		},
		"e8ead1bb90ccc3aea2b0dcc5b58056554655d1d5": {
			"balance": "7760000000000000000000"
		},
		"7a94b19992ceb8ce63bc92ee4b5aded10c4d9725": {
			"balance": "16770000000000000000000"
		},
		"90e93e4dc17121487952333614002be42356498e": {
			"balance": "1910000000000000000000"
		},
		"aab00abf5828d7ebf26b47ceaccdb8ba03325166": {
			"balance": "10000000000000000000000"
		},
		"0a9ab2638b1cfd654d25dab018a0aebddf85fd55": {
			"balance": "21801000000000000000"
		},
		"b12ed07b8a38ad5506363fc07a0b6d799936bdaf": {
			"balance": "10000000000000000000000"
		},
		"f4a9d00cefa97b7a58ef9417fc6267a5069039ee": {
			"balance": "21800000000000000000"
		},
		"04a1cada1cc751082ff8da928e3cfa000820a9e9": {
			"balance": "40000000000000000000"
		},
		"9018cc1f48d2308e252ab6089fb99a7c1d569410": {
			"balance": "200000000000000000000"
		},
		"895d694e880b13ccd0848a86c5ce411f88476bbf": {
			"balance": "199955000000000000000"
		},
		"40a7f72867a7dc86770b162b7557a434ed50cce9": {
			"balance": "1000000000000000000000"
		},
		"467ea10445827ef1e502daf76b928a209e0d4032": {
			"balance": "2000000000000000000000"
		},
		"7553aa23b68aa5f57e135fe39fdc235eaca8c98c": {
			"balance": "1000000000000000000000"
		},
		"31b43b015d0081643c6cda46a7073a6dfdbca825": {
			"balance": "50019600000000000000000"
)E" + R"E(
		},
		"d82fd9fdf6996bedad2843159c06f37e0924337d": {
			"balance": "1688800000000000000000"
		},
		"24a4eb36a7e498c36f99975c1a8d729fd6b305d7": {
			"balance": "258000000000000000000"
		},
		"91d66ea6288faa4b3d606c2aa45c7b6b8a252739": {
			"balance": "2000000000000000000000"
		},
		"83a402438e0519773d5448326bfb61f8b20cf52d": {
			"balance": "1520000000000000000000"
		},
		"c2fafdd30acb6d6706e9293cb02641f9edbe07b5": {
			"balance": "1494224000000000000000"
		},
		"79dba256472db4e058f2e4cdc3ea4e8a42773833": {
			"balance": "1460000000000000000000"
		},
		"498abdeb14c26b7b7234d70fceaef361a76dff72": {
			"balance": "3000000000000000000000"
		},
		"7b73242d75ca9ad558d650290df17692d54cd8b8": {
			"balance": "2000200000000000000000"
		},
		"6ec3659571b11f889dd439bcd4d67510a25be57e": {
			"balance": "123000000000000000000"
		},
		"ab098633eeee0ccefdf632f9575456f6dd80fc86": {
			"balance": "200000000000000000000000"
		},
		"f4a51fce4a1d5b94b0718389ba4e7814139ca738": {
			"balance": "300000000000000000000"
		},
		"8f561b41b209f248c8a99f858788376250609cf3": {
			"balance": "1700000000000000000000"
		},
		"05d0f4d728ebe82e84bf597515ad41b60bf28b39": {
			"balance": "4200000000000000000000"
		},
		"dfdf43393c649caebe1bb18059decb39f09fb4e8": {
			"balance": "400000000000000000000"
		},
		"0089508679abf8c71bf6781687120e3e6a84584d": {
			"balance": "1800000000000000000000"
		},
		"80907f593148b57c46c177e23d25abc4aae18361": {
			"balance": "100000000000000000000"
		},
		"94fcceadfe5c109c5eaeaf462d43873142c88e22": {
			"balance": "4800000000000000000000"
		},
		"e89249738b7eced7cb666a663c49cbf6de8343ea": {
			"balance": "2000000000000000000000"
		},
		"23c99ba087448e19c9701df66e0cab52368331fa": {
			"balance": "2000000000000000000000"
		},
		"a68e0c30cba3bc5a883e540320f999c7cd558e5c": {
			"balance": "1799869000000000000000"
		},
		"88888a57bd9687cbf950aeeacf9740dcc4d1ef59": {
			"balance": "1820000000000000000000"
		},
		"e9b36fe9b51412ddca1a521d6e94bc901213dda8": {
			"balance": "10000000000000000000000"
		},
		"a9145046fa3628cf5fd4c613927be531e6db1fdd": {
			"balance": "112000000000000000000"
		},
		"e82c58c579431b673546b53a86459acaf1de9b93": {
			"balance": "1000000000000000000000"
		},
		"bd6a474d66345bcdd707594adb63b30c7822af54": {
			"balance": "4000000000000000000000"
		},
		"6a6159074ab573e0ee581f0f3df2d6a594629b74": {
			"balance": "310000000000000000000"
		},
		"2e7f465520ec35cc23d68e75651bb6689544a196": {
			"balance": "1050049000000000000000"
		},
		"ac6d02e9a46b379fac4ac9b1d7b5d47bc850ce16": {
			"balance": "1760000000000000000000"
		},
		"bd59094e074f8d79142ab1489f148e32151f2089": {
			"balance": "20000000000000000000"
		},
		"0ba6e46af25a13f57169255a34a4dac7ce12be04": {
			"balance": "500000000000000000000"
		},
		"35145f620397c69cb8e00962961f0f4886643989": {
			"balance": "6000000000000000000000"
		},
		"d84b922f7841fc5774f00e14604ae0df42c8551e": {
			"balance": "4011000000000000000000"
		},
		"44232ff66ddad1fd841266380036afd7cf7d7f42": {
			"balance": "200000000000000000000"
		},
)E" + R"E(
		"516954025fca2608f47da81c215eedfd844a09ff": {
			"balance": "382000000000000000000"
		},
		"e5aa0b833bb916dc19a8dd683f0ede241d988eba": {
			"balance": "3000000000000000000000"
		},
		"80ea1acc136eca4b68c842a95adf6b7fee7eb8a2": {
			"balance": "4000000000000000000000"
		},
		"98a0e54c6d9dc8be96276cebf4fec460f6235d85": {
			"balance": "1969803000000000000000"
		},
		"91620f3eb304e813d28b0297556d65dc4e5de5aa": {
			"balance": "3820000000000000000000"
		},
		"7bb984c6dbb9e279966afafda59c01d02627c804": {
			"balance": "8050000000000000000000"
		},
		"41f489a1ec747bc29c3e5f9d8db97877d4d1b4e9": {
			"balance": "133700000000000000000"
		},
		"8dbc3e6cb433e194f40f82b40faadb1f8b856116": {
			"balance": "1910000000000000000000"
		},
		"889da40fb1b60f9ea9bd7a453e584cf7b1b4d9f7": {
			"balance": "40000000000000000000"
		},
		"debbdd831e0f20ae6e378252decdf92f7cf0c658": {
			"balance": "2000000000000000000000"
		},
		"a22ade0ddb5c6ef8d0cd8de94d82b11082cb2e91": {
			"balance": "1020000000000000000000"
		},
		"823219a25976bb2aa4af8bad41ac3526b493361f": {
			"balance": "2000000000000000000000"
		},
		"6d39a9e98f81f769d73aad2cead276ac1387babe": {
			"balance": "394000000000000000000"
		},
		"751abcb6cc033059911815c96fd191360ab0442d": {
			"balance": "8000000000000000000000"
		},
		"64d80c3b8ba68282290b75e65d8978a15a87782c": {
			"balance": "1970000000000000000000"
		},
		"6ba8f7e25fc2d871618e24e40184199137f9f6aa": {
			"balance": "400020000000000000000"
		},
		"25a74c2ac75dc8baa8b31a9c7cb4b7829b2456da": {
			"balance": "2000000000000000000000"
		},
		"0f7b61c59b016322e8226cafaee9d9e76d50a1b3": {
			"balance": "4000000000000000000000"
		},
		"7526e482529f0a14eec98871dddd0e721b0cd9a2": {
			"balance": "20000000000000000000"
		},
		"071dd90d14d41f4ff7c413c24238d3359cd61a07": {
			"balance": "36400000000000000000000"
		},
		"a986762f7a4f294f2e0b173279ad2c81a2223458": {
			"balance": "20000000000000000000"
		},
		"e667f652f957c28c0e66d0b63417c80c8c9db878": {
			"balance": "601650000000000000000"
		},
		"7b98e23cb96beee80a168069ebba8f20edd55ccf": {
			"balance": "214500000000000000000"
		},
		"2d8e5bb8d3521695c77e7c834e0291bfacee7408": {
			"balance": "1970000000000000000000"
		},
		"f23d01589eb12d439f7448ff54307529f191858d": {
			"balance": "2000000000000000000000"
		},
		"abd9605b3e91acfd777830d16463478ae0fc7720": {
			"balance": "133700000000000000000"
		},
		"eabb90d37989aab31feae547e0e6f3999ce6a35d": {
			"balance": "2000000000000000000000"
		},
		"0abfb39b11486d79572866195ba26c630b6784db": {
			"balance": "121500000000000000000000"
		},
		"d56a144d7af0ae8df649abae535a15983aa04d02": {
			"balance": "5000000000000000000000"
		},
		"998c1f93bcdb6ff23c10d0dc924728b73be2ff9f": {
			"balance": "1002750000000000000000"
		},
		"bc62b3096a91e7dc11a1592a293dd2542150d751": {
			"balance": "1000000000000000000000"
		},
		"0c8f66c6017bce5b20347204b602b743bad78d60": {
			"balance": "2000000000000000000000"
		},
		"4c5b3dc0e2b9360f91289b1fe13ce12c0fbda3e1": {
			"balance": "2000000000000000000000"
		},
		"b44605552471a6eee4daab71ff3bb41326d473e0": {
)E" + R"E(
			"balance": "839200000000000000000"
		},
		"fc3d226bb36a58f526568857b0bb12d109ec9301": {
			"balance": "2000000000000000000000"
		},
		"adc8228ef928e18b2a807d00fb3c6c79cd1d9e96": {
			"balance": "22800000000000000000"
		},
		"9df32a501c0b781c0281022f42a1293ffd7b892a": {
			"balance": "9000000000000000000000"
		},
		"e7da609d40cde80f00ce5b4ffb6aa9d0b03494fc": {
			"balance": "1000000000000000000000"
		},
		"9b64d3cd8d2b73f66841b5c46bb695b88a9ab75d": {
			"balance": "20769000000000000000"
		},
		"8e9c08f738661f9676236eff82ba6261dd3f4822": {
			"balance": "100000000000000000000"
		},
		"deb97254474c0d2f5a7970dcdb2f52fb1098b896": {
			"balance": "1000000000000000000000"
		},
		"b4256273962bf631d014555cc1da0dcc31616b49": {
			"balance": "2000000000000000000000"
		},
		"23abd9e93e7957e5b636be6579051c15e5ce0b0e": {
			"balance": "17188400000000000000000"
		},
		"382591e7217b435e8e884cdbf415fe377a6fe29e": {
			"balance": "8022000000000000000000"
		},
		"f17adb740f45cbbde3094e7e13716f8103f563bd": {
			"balance": "2000000000000000000000"
		},
		"61ed5596c697207f3d55b2a51aa7d50f07fa09e8": {
			"balance": "2000000000000000000000"
		},
		"788e809741a3b14a22a4b1d937c82cfea489eebe": {
			"balance": "7000000000000000000000"
		},
		"992646ac1acaabf5ddaba8f9429aa6a94e7496a7": {
			"balance": "1000110000000000000000"
		},
		"51296f5044270d17707646129c86aad1645eadc1": {
			"balance": "1337133000000000000000"
		},
		"6ee8aad7e0a065d8852d7c3b9a6e5fdc4bf50c00": {
			"balance": "20000000000000000000"
		},
		"30db6b9b107e62102f434a9dd0960c2021f5ce4c": {
			"balance": "599742000000000000000"
		},
		"63fc93001305adfbc9b85d29d9291a05f8f1410b": {
			"balance": "1000000000000000000000"
		},
		"df6ed6006a6abe886ed33d95a4de28fc12183927": {
			"balance": "910000000000000000000"
		},
		"4745ab181a36aa8cbf2289d0c45165bc7ebe2381": {
			"balance": "39400000000000000000"
		},
		"7bb0fdf5a663b5fba28d9c902af0c811e252f298": {
			"balance": "200000000000000000000"
		},
		"e0ff0bd9154439c4a5b7233e291d7d868af53f33": {
			"balance": "396110000000000000000"
		},
		"09261f9acb451c3788844f0c1451a35bad5098e3": {
			"balance": "8664000000000000000000"
		},
		"2813d263fc5ff2479e970595d6b6b560f8d6d6d1": {
			"balance": "2000000000000000000000"
		},
		"2cd19694d1926a0fa9189edebafc671cf1b2caa5": {
			"balance": "1000000000000000000000"
		},
		"05336e9a722728d963e7a1cf2759fd0274530fca": {
			"balance": "915583000000000000000"
		},
		"e5b7af146986c0ff8f85d22e6cc334077d84e824": {
			"balance": "2000000000000000000000"
		},
		"3e4fbd661015f6461ed6735cefef01f31445de3a": {
			"balance": "16200000000000000000000"
		},
		"4f5df5b94357de948604c51b7893cddf6076baad": {
			"balance": "3760000000000000000000"
		},
		"9567a0de811de6ff095b7ee64e7f1b83c2615b80": {
			"balance": "267400000000000000000"
		},
		"955db3b74360b9a268677e73cea821668af6face": {
			"balance": "30000000000000000000000"
		},
		"3e040d40cb80ba0125f3b15fdefcc83f3005da1b": {
			"balance": "1038000000000000000000"
		},
		"43f470ed659e2991c375957e5ddec5bd1d382231": {
			"balance": "100000000000000000000"
)E" + R"E(
		},
		"047f9bf1529daf87d407175e6f171b5e59e9ff3e": {
			"balance": "650000000000000000000"
		},
		"15e3b584056b62c973cf5eb096f1733e54c15c91": {
			"balance": "936702000000000000000"
		},
		"c03de42a109b657a64e92224c08dc1275e80d9b2": {
			"balance": "20000000000000000000"
		},
		"e4fc13cfcbac1b17ce7783acd423a845943f6b3a": {
			"balance": "20000000000000000000"
		},
		"65ff874fafce4da318d6c93d57e2c38a0d73e820": {
			"balance": "1000160000000000000000"
		},
		"8b997dbc078ad02961355da0a159f2927ed43d64": {
			"balance": "197000000000000000000"
		},
		"2f5080b83f7e2dc0a1dd11b092ad042bff788f4c": {
			"balance": "3338355000000000000000"
		},
		"1b3920d001c43e72b24e7ca46f0fd6e0c20a5ff2": {
			"balance": "2000000000000000000000"
		},
		"5ade77fd81c25c0af713b10702768c1eb2f975e7": {
			"balance": "20000000000000000000"
		},
		"acaaddcbf286cb0e215dda55598f7ff0f4ada5c6": {
			"balance": "1000000000000000000000"
		},
		"64e0217a5b38aa40583625967fa9883690388b6f": {
			"balance": "200000000000000000000"
		},
		"ae648155a658370f929be384f7e001047e49dd46": {
			"balance": "13561000000000000000000"
		},
		"f7c1b443968b117b5dd9b755572fcd39ca5ec04b": {
			"balance": "456082000000000000000"
		},
		"de027efbb38503226ed871099cb30bdb02af1335": {
			"balance": "1000000000000000000000"
		},
		"49cf1e54be363106b920729d2d0ba46f0867989a": {
			"balance": "268000000000000000000"
		},
		"e7f4d7fe6f561f7fa1da3005fd365451ad89df89": {
			"balance": "200000000000000000000"
		},
		"b036916bdacf94b69e5a8a65602975eb026104dd": {
			"balance": "20000000000000000000"
		},
		"e923c06177b3427ea448c0a6ff019b54cc548d95": {
			"balance": "36281000000000000000"
		},
		"ad927e03d1599a78ca2bf0cad2a183dceb71eac0": {
			"balance": "1970000000000000000000"
		},
		"ef39ca9173df15531d73e6b72a684b51ba0f2bb4": {
			"balance": "1598000000000000000000"
		},
		"6443b8ae639de91cf73c5ae763eeeed3ddbb9253": {
			"balance": "2000000000000000000000"
		},
		"8026435aac728d497b19b3e7e57c28c563954f2b": {
			"balance": "1730000000000000000000"
		},
		"ed327a14d5cfadd98103fc0999718d7ed70528ea": {
			"balance": "1440000000000000000000"
		},
		"38a3dccf2fcfe0c91a2624bd0cbf88ee4a076c33": {
			"balance": "2000000000000000000000"
		},
		"f0b1f9e27832c6de6914d70afc238c749995ace4": {
			"balance": "2000000000000000000000"
		},
		"770d98d31b4353fceee8560c4ccf803e88c0c4e0": {
			"balance": "600000000000000000000"
		},
		"ba1f0e03cb9aa021f4dcebfa94e5c889c9c7bc9e": {
			"balance": "32200000000000000000000"
		},
		"233842b1d0692fd11140cf5acda4bf9630bae5f8": {
			"balance": "2000000000000000000000"
		},
		"b5dd50a15da34968890a53b4f13fe1af081baaaa": {
			"balance": "4000000000000000000000"
		},
		"72072a0ef1cff3d567cdd260e708ddc11cbc9a31": {
			"balance": "100000000000000000000"
		},
		"81a88196fac5f23c3e12a69dec4b880eb7d97310": {
			"balance": "2000000000000000000000"
		},
		"6c63f84556d290bfcd99e434ee9997bfd779577a": {
			"balance": "2000000000000000000000"
		},
		"5f167aa242bc4c189adecb3ac4a7c452cf192fcf": {
			"balance": "1999980000000000000000"
		},
)E" + R"E(
		"445cb8de5e3df520b499efc980f52bff40f55c76": {
			"balance": "2000000000000000000000"
		},
		"aec27ce2133e82d052520afb5c576d9f7eb93ed2": {
			"balance": "65232380000000000000000"
		},
		"07dc2bf83bc6af19a842ffea661af5b41b67fda1": {
			"balance": "1500000000000000000000"
		},
		"febd48d0ffdbd5656cd5e686363a61145228f279": {
			"balance": "2800000000000000000000"
		},
		"a86db07d9f812f4796622d40e03d135874a88a74": {
			"balance": "20000000000000000000"
		},
		"5413c97ffa4a6e2a7bba8961dc9fce8530a787d7": {
			"balance": "1000000000000000000000"
		},
		"e2ff9ee4b6ecc14141cc74ca52a9e7a2ee14d908": {
			"balance": "1400000000000000000000"
		},
		"2e8eb30a716e5fe15c74233e039bfb1106e81d12": {
			"balance": "100000000000000000000"
		},
		"fd88d114220f081cb3d5e15be8152ab07366576a": {
			"balance": "300000000000000000000"
		},
		"e408fceaa1b98f3c640f48fcba39f056066d6308": {
			"balance": "10000000000000000000000"
		},
		"057dd29f2d19aa3da42327ea50bce86ff5c911d9": {
			"balance": "4000000000000000000000"
		},
		"ed1065dbcf9d73c04ffc7908870d881468c1e132": {
			"balance": "2000000000000000000000"
		},
		"bbc9d8112e5beb02dd29a2257b1fe69b3536a945": {
			"balance": "2000000000000000000000"
		},
		"79c1be19711f73bee4e6316ae7549459aacea2e0": {
			"balance": "400000000000000000000"
		},
		"1bcf3441a866bdbe963009ce33c81cbb0261b02c": {
			"balance": "182000000000000000000"
		},
		"e2e26e4e1dcf30d048cc6ecf9d51ec1205a4e926": {
			"balance": "4000000000000000000000"
		},
		"77701e2c493da47c1b58f421b5495dee45bea39b": {
			"balance": "6068279000000000000000"
		},
		"37a05aceb9395c8635a39a7c5d266ae610d10bf2": {
			"balance": "30000000000000000000000"
		},
		"c6355ec4768c70a49af69513cd83a5bca7e3b9cd": {
			"balance": "6000000000000000000000"
		},
		"e3c0c128327a9ad80148139e269773428e638cb0": {
			"balance": "2000000000000000000000"
		},
		"f7f4898c4c526d955f21f055cb6e47b915e51964": {
			"balance": "2288000000000000000000"
		},
		"29824e94cc4348bc963279dcdf47391715324cd3": {
			"balance": "1940000000000000000000"
		},
		"eaa45cea02d87d2cc8fda9434e2d985bd4031584": {
			"balance": "1920750000000000000000"
		},
		"e08b9aba6bd9d28bc2056779d2fbf0f2855a3d9d": {
			"balance": "2000000000000000000000"
		},
		"87c498170934b8233d1ad1e769317d5c475f2f40": {
			"balance": "1015200000000000000000"
		},
		"352d29a26e8a41818181746467f582e6e84012e0": {
			"balance": "6000000000000000000000"
		},
		"403220600a36f73f24e190d1edb2d61be3f41354": {
			"balance": "304000000000000000000"
		},
		"0a48296f7631708c95d2b74975bc4ab88ac1392a": {
			"balance": "5000000000000000000000"
		},
		"ffe0e997f1977a615f5a315af413fd4869343ba0": {
			"balance": "100076000000000000000"
		},
		"ca66b2280fa282c5b67631ce552b62ee55ad8474": {
			"balance": "1969488000000000000000"
		},
		"2b6ed29a95753c3ad948348e3e7b1a251080ffb9": {
			"balance": "250000000000000000000000"
		},
		"492e70f04d18408cb41e25603730506b35a2876b": {
			"balance": "39400000000000000000"
		},
		"0e6baaa3deb989f289620076668618e9ac332865": {
			"balance": "200000000000000000000"
		},
		"b753a75f9ed10b21643a0a3dc0517ac96b1a4068": {
)E" + R"E(
			"balance": "401800000000000000000"
		},
		"3ad915d550b723415620f5a9b5b88a85f382f035": {
			"balance": "1000000000000000000000"
		},
		"c992be59c6721caf4e028f9e8f05c25c55515bd4": {
			"balance": "20000000000000000000"
		},
		"02b643d6fabd437a851accbe79abb7fde126dccf": {
			"balance": "7200000000000000000000"
		},
		"88797e58675ed5cc4c19980783dbd0c956085153": {
			"balance": "2000000000000000000000"
		},
		"ac142eda1157b9a9a64390df7e6ae694fac98905": {
			"balance": "200000000000000000000"
		},
		"656579daedd29370d9b737ee3f5cd9d84bc2b342": {
			"balance": "1430000000000000000000"
		},
		"9bb9b02a26bfe1ccc3f0c6219e261c397fc5ca78": {
			"balance": "1337000000000000000000"
		},
		"bee8d0b008421954f92d000d390fb8f8e658eaee": {
			"balance": "1000000000000000000000"
		},
		"7989d09f3826c3e5af8c752a8115723a84d80970": {
			"balance": "415554000000000000000"
		},
		"7cd5d81eab37e11e6276a3a1091251607e0d7e38": {
			"balance": "62856000000000000000"
		},
		"6ce1b0f6adc47051e8ab38b39edb4186b03babcc": {
			"balance": "1207800000000000000000"
		},
		"abfcf5f25091ce57875fc674dcf104e2a73dd2f2": {
			"balance": "19700000000000000000"
		},
		"1c3ef05dae9dcbd489f3024408669de244c52a02": {
			"balance": "20000000000000000000000"
		},
		"cfa8b37127149bdbfee25c34d878510951ea10eb": {
			"balance": "2000000000000000000000"
		},
		"74863acec75d03d53e860e64002f2c165e538377": {
			"balance": "1000000000000000000000"
		},
		"59b9e733cba4be00429b4bd9dfa64732053a7d55": {
			"balance": "20000000000000000000"
		},
		"aeadfcd0978edad74a32bd01a0a51d37f246e661": {
			"balance": "260000000000000000000"
		},
		"08090876baadfee65c3d363ba55312748cfa873d": {
			"balance": "1700170000000000000000"
		},
		"e589fa76984db5ec4004b46ee8a59492c30744ce": {
			"balance": "2800000000000000000000"
		},
		"3485361ee6bf06ef6508ccd23d94641f814d3e2f": {
			"balance": "2000000000000000000000"
		},
		"5cb731160d2e8965670bde925d9de5510935347d": {
			"balance": "40000000000000000000"
		},
		"8ef4d8a2c23c5279187b64e96f741404085385f3": {
			"balance": "299598000000000000000"
		},
		"e246683cc99db7c4a52bcbacaab0b32f6bfc93d7": {
			"balance": "2000000000000000000000"
		},
		"7d273e637ef1eac481119413b91c989dc5eac122": {
			"balance": "500000000000000000000"
		},
		"6efba8fb2ac5b6730729a972ec224426a287c3ad": {
			"balance": "283152000000000000000"
		},
		"0773eeacc050f74720b4a1bd57895b1cceeb495d": {
			"balance": "10000000000000000000000"
		},
		"88a122a2382c523931fb51a0ccad3beb5b7259c3": {
			"balance": "2000000000000000000000"
		},
		"b0b779b94bfa3c2e1f587bcc9c7e21789222378f": {
			"balance": "1550000000000000000000"
		},
		"86f95c5b11a293940e35c0b898d8b75f08aab06d": {
			"balance": "29605000000000000000000"
		},
		"cf2288ef4ebf88e86db13d8a0e0bf52a056582c3": {
			"balance": "2533000000000000000000"
		},
		"71ea5b11ad8d29b1a4cb67bf58ca6c9f9c338c16": {
			"balance": "1600000000000000000000"
		},
		"9917d68d4af341d651e7f0075c6de6d7144e7409": {
			"balance": "5660000000000000000000"
		},
		"1e5800227d4dcf75e30f5595c5bed3f72e341e3b": {
			"balance": "248300000000000000000"
)E" + R"E(
		},
		"123759f333e13e3069e2034b4f05398918119d36": {
			"balance": "20000000000000000000000"
		},
		"f798d16da4e460c460cd485fae0fa0599708eb82": {
			"balance": "1000000000000000000000"
		},
		"864bec5069f855a4fd5892a6c4491db07c88ff7c": {
			"balance": "1000000000000000000000"
		},
		"fa283299603d8758e8cab082125d2c8f7d445429": {
			"balance": "6415633000000000000000"
		},
		"c811c2e9aa1ac3462eba5e88fcb5120e9f6e2ca2": {
			"balance": "1400140000000000000000"
		},
		"61547d376e5369bcf978fc162c3c56ae453547e8": {
			"balance": "200000000000000000000"
		},
		"0d747ee5969bf79d57381d6fe3a2406cd0d8ce27": {
			"balance": "100000000000000000000000"
		},
		"f8962b75db5d24c7e8b7cef1068c3e67cebb30a5": {
			"balance": "280000000000000000000"
		},
		"35bf6688522f35467a7f75302314c02ba176800e": {
			"balance": "17400000000000000000000"
		},
		"05cb6c3b0072d3116761b532b218443b53e8f6c5": {
			"balance": "141722000000000000000000"
		},
		"91c80caa081b38351d2a0e0e00f80a34e56474c1": {
			"balance": "1000000000000000000000"
		},
		"d75a502a5b677287470f65c5aa51b87c10150572": {
			"balance": "907400000000000000000"
		},
		"3e194b4ecef8bb711ea2ff24fec4e87bd032f7d1": {
			"balance": "2575465000000000000000"
		},
		"736bf1402c83800f893e583192582a134eb532e9": {
			"balance": "9999996000000000000000"
		},
		"c2cb1ada5da9a0423873814793f16144ef36b2f3": {
			"balance": "1334326000000000000000"
		},
		"efcce06bd6089d0e458ef561f5a689480afe7000": {
			"balance": "600000000000000000000"
		},
		"bfe6bcb0f0c07852643324aa5df5fd6225abc3ca": {
			"balance": "74500000000000000000"
		},
		"9d799e943e306ba2e5b99c8a6858cbb52c0cf735": {
			"balance": "300000000000000000000"
		},
		"f45b1dcb2e41dc27ffa024daadf619c11175c087": {
			"balance": "19700000000000000000"
		},
		"08e38ee0ce48c9ca645c1019f73b5355581c56e6": {
			"balance": "1600000000000000000000"
		},
		"2cb4c3c16bb1c55e7c6b7a19b127a1ac9390cc09": {
			"balance": "3397053000000000000000"
		},
		"bdc02cd4330c93d6fbda4f6db2a85df22f43c233": {
			"balance": "2000000000000000000000"
		},
		"acec91ef6941cf630ba9a3e787a012f4a2d91dd4": {
			"balance": "80000000000000000000000"
		},
		"27ac073be79ce657a93aa693ee43bf0fa41fef04": {
			"balance": "50000000000000000000000"
		},
		"22fe884d9037291b4d52e6285ae68dea0be9ffb5": {
			"balance": "2000000000000000000000"
		},
		"c3107a9af3322d5238df0132419131629539577d": {
			"balance": "492650000000000000000"
		},
		"b5cac5ed03477d390bb267d4ebd46101fbc2c3da": {
			"balance": "197000000000000000000"
		},
		"58fb947364e7695765361ebb1e801ffb8b95e6d0": {
			"balance": "200000000000000000000"
		},
		"32860997d730b2d83b73241a25d3667d51c908ef": {
			"balance": "499938000000000000000"
		},
		"c79d5062c796dd7761f1f13e558d73a59f82f38b": {
			"balance": "8000000000000000000000"
		},
		"fa142fe47eda97e6503b386b18a2bedd73ccb5b1": {
			"balance": "850080000000000000000"
		},
		"6ca5de00817de0cedce5fd000128dede12648b3c": {
			"balance": "20000000000000000000"
		},
		"214b743955a512de6e0d886a8cbd0282bee6d2a2": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"ede79ae1ff4f1606d59270216fa46ab2ddd4ecaa": {
			"balance": "146000000000000000000"
		},
		"528101ce46b720a2214dcdae6618a53177ffa377": {
			"balance": "508876000000000000000"
		},
		"b5870ce342d43343333673038b4764a46e925f3e": {
			"balance": "1000000000000000000000"
		},
		"843bd3502f45f8bc4da370b323bdac3fcf5f19a6": {
			"balance": "1476000000000000000000"
		},
		"5067f4549afbfe884c59cbc12b96934923d45db0": {
			"balance": "1000000000000000000000"
		},
		"6f2a42e6e033d01061131929f7a6ee1538021e52": {
			"balance": "2000000000000000000000"
		},
		"e9e1f7cb00a110edd0ebf8b377ef8a7bb856117f": {
			"balance": "200000000000000000000"
		},
		"a387ecde0ee4c8079499fd8e03473bd88ad7522a": {
			"balance": "1970000000000000000000"
		},
		"6dff90e6dc359d2590882b1483edbcf887c0e423": {
			"balance": "1000000000000000000000"
		},
		"22e512149a18d369b73c71efa43e86c9edabaf1d": {
			"balance": "1455000000000000000000"
		},
		"a3203095edb7028e6871ce0a84f548459f83300a": {
			"balance": "4000000000000000000000"
		},
		"93b4bf3fdff6de3f4e56ba6d7799dc4b93a6548f": {
			"balance": "19100000000000000000"
		},
		"8c75956e8fed50f5a7dd7cfd27da200f6746aea6": {
			"balance": "1000000000000000000000"
		},
		"afc8ebe8988bd4105acc4c018e546a1e8f9c7888": {
			"balance": "500000000000000000000"
		},
		"bf9acd4445d9c9554689cabbbab18800ff1741c2": {
			"balance": "1000000000000000000000"
		},
		"603f2fab7afb6e017b94766069a4b43b38964923": {
			"balance": "1656954000000000000000"
		},
		"a1f765c44fe45f790677944844be4f2d42165fbd": {
			"balance": "3687750000000000000000"
		},
		"4dc9d5bb4b19cecd94f19ec25d200ea72f25d7ed": {
			"balance": "2000000000000000000000"
		},
		"48f60a35484fe7792bcc8a7b6393d0dda1f6b717": {
			"balance": "3600000000000000000000"
		},
		"588ed990a2aff44a94105d58c305257735c868ac": {
			"balance": "16100000000000000000000"
		},
		"710be8fd5e2918468be2aabea80d828435d79612": {
			"balance": "17600000000000000000"
		},
		"03ea6d26d080e57aee3926b18e8ed73a4e5b2826": {
			"balance": "200000000000000000000"
		},
		"20824ba1dbebbef9846ef3d0f6c1b017e6912ec4": {
			"balance": "7170194000000000000000"
		},
		"f7500c166f8bea2f82347606e5024be9e4f4ce99": {
			"balance": "20000000000000000000"
		},
		"9d369165fb70b81a3a765f188fd60cbe5e7b0968": {
			"balance": "2000000000000000000000"
		},
		"6fddbd9bca66e28765c2162c8433548c1052ed11": {
			"balance": "82720000000000000000000"
		},
		"8b81156e698639943c01a75272ad3d35851ab282": {
			"balance": "344946000000000000000"
		},
		"75804aac64b4199083982902994d9c5ed8828f11": {
			"balance": "557800000000000000000"
		},
		"d6e8e97ae9839b9ee507eedb28edfb7477031439": {
			"balance": "2000000000000000000000"
		},
		"6c808cabb8ff5fbb6312d9c8e84af8cf12ef0875": {
			"balance": "4000086000000000000000"
		},
		"afa539586e4719174a3b46b9b3e663a7d1b5b987": {
			"balance": "5000000000000000000000"
		},
		"f8a065f287d91d77cd626af38ffa220d9b552a2b": {
			"balance": "1910000000000000000000"
		},
		"30e60900cacc7203f314dc604347255167fc2a0f": {
			"balance": "2000000000000000000000"
		},
		"796f87ba617a2930b1670be92ed1281fb0b346e1": {
)E" + R"E(
			"balance": "128400000000000000000"
		},
		"f114ff0d0f24eff896edde5471dea484824a99b3": {
			"balance": "13700000000000000000"
		},
		"0b80fc70282cbdd5fde35bf78984db3bdb120188": {
			"balance": "1000160000000000000000"
		},
		"da7ad025ebde25d22243cb830ea1d3f64a566323": {
			"balance": "500000000000000000000"
		},
		"65a52141f56bef98991724c6e7053381da8b5925": {
			"balance": "60140000000000000000"
		},
		"bbc8eaff637e94fcc58d913c7770c88f9b479277": {
			"balance": "200000000000000000000"
		},
		"0469e8c440450b0e512626fe817e6754a8152830": {
			"balance": "2000000000000000000000"
		},
		"0727be0a2a00212048b5520fbefb953ebc9d54a0": {
			"balance": "10000000000000000000000"
		},
		"7d858493f07415e0912d05793c972113eae8ae88": {
			"balance": "1818000000000000000000"
		},
		"7091303116d5f2389b23238b4d656a8596d984d3": {
			"balance": "1094014000000000000000"
		},
		"3702e704cc21617439ad4ea27a5714f2fda1e932": {
			"balance": "1000000000000000000000"
		},
		"b87de1bcd29269d521b8761cc39cfb4319d2ead5": {
			"balance": "1000000000000000000000"
		},
		"f639ac31da9f67271bd10402b7654e5ce763bd47": {
			"balance": "399996000000000000000"
		},
		"e7735ec76518fc6aa92da8715a9ee3f625788f13": {
			"balance": "1997803000000000000000"
		},
		"51277fe7c81eebd252a03df69a6b9f326e272207": {
			"balance": "59965000000000000000"
		},
		"3b8098533f7d9bdcd307dbb23e1777ca18418936": {
			"balance": "2000000000000000000000"
		},
		"2cba6d5d0dc204ea8a25ada2e26f5675bd5f2fdc": {
			"balance": "1330755000000000000000"
		},
		"5c3c1c645b917543113b3e6c1c054da1fe742b9a": {
			"balance": "800000000000000000000"
		},
		"5ecdbaeab9106ffe5d7b519696609a05baeb85ad": {
			"balance": "20000000000000000000"
		},
		"45a820a0672f17dc74a08112bc643fd1167736c3": {
			"balance": "199943000000000000000"
		},
		"beef94213879e02622142bea61290978939a60d7": {
			"balance": "5728109000000000000000"
		},
		"6cd212aee04e013f3d2abad2a023606bfb5c6ac7": {
			"balance": "1999944000000000000000"
		},
		"92698e345378c62d8eda184d94366a144b0c105b": {
			"balance": "1400000000000000000000"
		},
		"2d5b42fc59ebda0dfd66ae914bc28c1b0a6ef83a": {
			"balance": "206764195000000000000000"
		},
		"b7a6791c16eb4e2162f14b6537a02b3d63bfc602": {
			"balance": "780700000000000000000"
		},
		"fa105f1a11b6e4b1f56012a27922e2ac2da4812f": {
			"balance": "9550000000000000000000"
		},
		"2306df931a940d58c01665fa4d0800802c02edfe": {
			"balance": "1000000000000000000000"
		},
		"f37bf78c5875154711cb640d37ea6d28cfcb1259": {
			"balance": "200000000000000000000"
		},
		"66201bd227ae6dc6bdfed5fbde811fecfe5e9dd9": {
			"balance": "594808000000000000000"
		},
		"2bafbf9e9ed2c219f7f2791374e7d05cb06777e7": {
			"balance": "220000000000000000000"
		},
		"8e9b35ad4a0a86f758446fffde34269d940ceacd": {
			"balance": "4000000000000000000000"
		},
		"1b43232ccd4880d6f46fa751a96cd82473315841": {
			"balance": "80000000000000000000"
		},
		"6eefdc850e87b715c72791773c0316c3559b58a4": {
			"balance": "4000000000000000000000"
		},
		"f2c03e2a38998c21648760f1e5ae7ea3077d8522": {
			"balance": "2642456000000000000000"
)E" + R"E(
		},
		"0625d06056968b002206ff91980140242bfaa499": {
			"balance": "1000000000000000000000"
		},
		"6158e107c5eb54cb7604e0cd8dc1e07500d91c3c": {
			"balance": "50000000000000000000"
		},
		"02477212ffdd75e5155651b76506b1646671a1eb": {
			"balance": "1760000000000000000000"
		},
		"fa44a855e404c86d0ca8ef3324251dfb349c539e": {
			"balance": "1552000000000000000000"
		},
		"49897fe932bbb3154c95d3bce6d93b6d732904dd": {
			"balance": "4000000000000000000000"
		},
		"9b6641b13e172fc072ca4b8327a3bc28a15b66a9": {
			"balance": "120000000000000000000"
		},
		"a46b4387fb4dcce011e76e4d73547d4481e09be5": {
			"balance": "1337000000000000000000"
		},
		"72bb27cb99f3e2c2cf90a98f707d30e4a201a071": {
			"balance": "1640000000000000000000"
		},
		"b6bfe1c3ef94e1846fb9e3acfe9b50c3e9069233": {
			"balance": "1999944000000000000000"
		},
		"e6cb3f3124c9c9cc3834b1274bc3336456a38bac": {
			"balance": "427382000000000000000"
		},
		"fcbc5c71ace79741450b012cf6b8d3f17db68a70": {
			"balance": "9550000000000000000000"
		},
		"15dbb48c98309764f99ced3692dcca35ee306bac": {
			"balance": "150000000000000000000000"
		},
		"2e10910ba6e0bc17e055556614cb87090f4d7e5b": {
			"balance": "200000000000000000000"
		},
		"e5fbe34984b637196f331c679d0c0c47d83410e1": {
			"balance": "2000050000000000000000"
		},
		"6d120f0caae44fd94bcafe55e2e279ef96ba5c7a": {
			"balance": "4000000000000000000000"
		},
		"aa5afcfd8309c2df9d15be5e6a504e7d706624c5": {
			"balance": "5846763000000000000000"
		},
		"37959c20b7e9931d72f5a8ae869dafddad3b6d5c": {
			"balance": "200000000000000000000"
		},
		"b041310fe9eed6864cedd4bee58df88eb4ed3cac": {
			"balance": "10000000000000000000000"
		},
		"986df47e76e4d7a789cdee913cc9831650936c9d": {
			"balance": "5000000000000000000000"
		},
		"35aaa0465d1c260c420fa30e2629869fb6559207": {
			"balance": "704976000000000000000"
		},
		"7f655c6789eddf455cb4b88099720639389eebac": {
			"balance": "6000000000000000000000"
		},
		"9e3eb509278fe0dcd8e0bbe78a194e06b6803943": {
			"balance": "940000000000000000000"
		},
		"3e9410d3b9a87ed5e451a6b91bb8923fe90fb2b5": {
			"balance": "200000000000000000000"
		},
		"9e960dcd03d5ba99cb115d17ff4c09248ad4d0be": {
			"balance": "200000000000000000000"
		},
		"f057aa66ca767ede124a1c5b9cc5fc94ef0b0137": {
			"balance": "2077730000000000000000"
		},
		"f38a6ca80168537e974d14e1c3d13990a44c2c1b": {
			"balance": "6000000000000000000000"
		},
		"229e430de2b74f442651ddcdb70176bc054cad54": {
			"balance": "13545000000000000000"
		},
		"27bf9f44ba7d05c33540c3a53bb02cbbffe7c3c6": {
			"balance": "2000000000000000000000"
		},
		"10389858b800e8c0ec32f51ed61a355946cc409b": {
			"balance": "200000000000000000000"
		},
		"fd2929271e9d2095a264767e7b0df52ea0d1d400": {
			"balance": "3000040000000000000000"
		},
		"44250d476e062484e9080a3967bf3a4a732ad73f": {
			"balance": "20000000000000000000"
		},
		"0c67033dd8ee7f0c8ae534d42a51f7d9d4f7978f": {
			"balance": "200000000000000000000"
		},
		"e083d34863e0e17f926b7928edff317e998e9c4b": {
			"balance": "400000000000000000000"
		},
)E" + R"E(
		"7f7192c0df1c7db6d9ed65d71184d8e4155a17ba": {
			"balance": "79800000000000000000"
		},
		"51e7b55c2f9820eed73884361b5066a59b6f45c6": {
			"balance": "2000000000000000000000"
		},
		"4fa983bb5e3073a8edb557effeb4f9fb1d60ef86": {
			"balance": "1599800000000000000000"
		},
		"5a5ee8e9bb0e8ab2fecb4b33d29478be50bbd44b": {
			"balance": "776000000000000000000"
		},
		"1f3959fc291110e88232c36b7667fc78a379613f": {
			"balance": "18200000000000000000"
		},
		"2d7d5c40ddafc450b04a74a4dabc2bb5d665002e": {
			"balance": "2000000000000000000000"
		},
		"5215183b8f80a9bc03d26ce91207832a0d39e620": {
			"balance": "1000000000000000000000"
		},
		"5607590059a9fec1881149a44b36949aef85d560": {
			"balance": "2000000000000000000000"
		},
		"f7c50f922ad16b61c6d1baa045ed816815bac48f": {
			"balance": "12566370000000000000000"
		},
		"da10978a39a46ff0bb848cf65dd9c77509a6d70e": {
			"balance": "2000000000000000000000"
		},
		"a7dcbba9b9bf6762c145416c506a71e3b497209c": {
			"balance": "1999944000000000000000"
		},
		"54e01283cc8b384538dd646770b357c960d6cacd": {
			"balance": "5000000000000000000000"
		},
		"78cf8336b328db3d87813a472b9e89b75e0cf3bc": {
			"balance": "1000000000000000000000"
		},
		"ba24fc436753a739db2c8d40e6d4d04c528e86fa": {
			"balance": "13000000000000000000000"
		},
		"dfe929a61c1b38eddbe82c25c2d6753cb1e12d68": {
			"balance": "402500000000000000000"
		},
		"2b49fba29830360fcdb6da23bbfea5c0bbac5281": {
			"balance": "20000000000000000000"
		},
		"76becae4a31d36f3cb577f2a43594fb1abc1bb96": {
			"balance": "24860000000000000000000"
		},
		"e0cf698a053327ebd16b7d7700092fe2e8542446": {
			"balance": "95275000000000000000"
		},
		"a3802d8a659e89a2c47e905430b2a827978950a7": {
			"balance": "1000000000000000000000"
		},
		"75636cdb109050e43d5d6ec47e359e218e857eca": {
			"balance": "22886800000000000000000"
		},
		"3d813ff2b6ed57b937dabf2b381d148a411fa085": {
			"balance": "100000000000000000000"
		},
		"a9252551a624ae513719dabe5207fbefb2fd7749": {
			"balance": "40000000000000000000"
		},
		"c749668042e71123a648975e08ed6382f83e05e2": {
			"balance": "14000000000000000000000"
		},
		"04eca501630abce35218b174956b891ba25efb23": {
			"balance": "1000060000000000000000"
		},
		"790f91bd5d1c5cc4739ae91300db89e1c1303c93": {
			"balance": "2000000000000000000000"
		},
		"009560a3de627868f91fa8bfe1c1b7afaf08186b": {
			"balance": "524000000000000000000"
		},
		"1329dd19cd4baa9fc64310efeceab22117251f12": {
			"balance": "200000000000000000000"
		},
		"7005a772282b1f62afda63f89b5dc6ab64c84cb9": {
			"balance": "18000000000000000000000"
		},
		"abfe936425dcc7b74b955082bbaaf2a11d78bc05": {
			"balance": "1400000000000000000000"
		},
		"97d0d9725e3b70e675843173938ed371b62c7fac": {
			"balance": "170000000000000000000"
		},
		"41ed2d8e7081482c919fc23d8f0091b3c82c4685": {
			"balance": "1295460000000000000000"
		},
		"992365d764c5ce354039ddfc912e023a75b8e168": {
			"balance": "18200000000000000000"
		},
		"e1c607c0a8a060da8f02a8eb38a013ea8cda5b8c": {
			"balance": "805000000000000000000"
		},
		"3b2c45990e21474451cf4f59f01955b331c7d7c9": {
)E" + R"E(
			"balance": "2000000000000000000000"
		},
		"29ac2b458454a36c7e96c73a8667222a12242c71": {
			"balance": "4000000000000000000000"
		},
		"b8555010776e3c5cb311a5adeefe9e92bb9a64b9": {
			"balance": "4000000000000000000000"
		},
		"30380087786965149e81423b15e313ba32c5c783": {
			"balance": "18200000000000000000"
		},
		"a2f86bc061884e9eef05640edd51a2f7c0596c69": {
			"balance": "2000050000000000000000"
		},
		"9f98eb34d46979b0a6de8b05aa533a89b825dcf1": {
			"balance": "86500000000000000000"
		},
		"c81fb7d20fd2800192f0aac198d6d6a37d3fcb7d": {
			"balance": "259500000000000000000"
		},
		"a4035ab1e5180821f0f380f1131b7387c8d981cd": {
			"balance": "20000000000000000000"
		},
		"782f52f0a676c77716d574c81ec4684f9a020a97": {
			"balance": "850055000000000000000"
		},
		"261e0fa64c51137465eecf5b90f197f7937fdb05": {
			"balance": "18000000000000000000000"
		},
		"276fd7d24f8f883f5a7a28295bf17151c7a84b03": {
			"balance": "2000000000000000000000"
		},
		"a1f5b840140d5a9acef402ac3cc3886a68cad248": {
			"balance": "2000000000000000000000"
		},
		"d2bf67a7f3c6ce56b7be41675dbbadfe7ea93a33": {
			"balance": "400000000000000000000"
		},
		"8ee584337ddbc80f9e3498df55f0a21eacb57fb1": {
			"balance": "20000000000000000000"
		},
		"34393c5d91b9de597203e75bac4309b5fa3d28c3": {
			"balance": "194000000000000000000"
		},
		"114cbbbf6fb52ac414be7ec61f7bb71495ce1dfa": {
			"balance": "3000000000000000000000"
		},
		"ab7c42c5e52d641a07ad75099c62928b7f86622f": {
			"balance": "335940000000000000000"
		},
		"80bf995ed8ba92701d10fec49f9e7d014dbee026": {
			"balance": "572153000000000000000"
		},
		"4a192035e2619b24b0709d56590e9183ccf2c1d9": {
			"balance": "10000000000000000000000"
		},
		"376cd7577383e902951b60a2017ba7ea29e33576": {
			"balance": "2000000000000000000000"
		},
		"f5437e158090b2a2d68f82b54a5864b95dd6dbea": {
			"balance": "4010732000000000000000"
		},
		"13a5eecb38305df94971ef2d9e179ae6cebab337": {
			"balance": "330000000000000000000"
		},
		"efc8cf1963c9a95267b228c086239889f4dfd467": {
			"balance": "10000000000000000000000"
		},
		"db77b88dcb712fd17ee91a5b94748d720c90a994": {
			"balance": "2000000000000000000000"
		},
		"9aaafa0067647ed999066b7a4ca5b4b3f3feaa6f": {
			"balance": "1000000000000000000000"
		},
		"ae36f7452121913e800e0fcd1a65a5471c23846f": {
			"balance": "164000000000000000000"
		},
		"b124bcb6ffa430fcae2e86b45f27e3f21e81ee08": {
			"balance": "2000000000000000000000"
		},
		"f2813a64c5265d020235cb9c319b6c96f906c41e": {
			"balance": "350000000000000000000"
		},
		"e848ca7ebff5c24f9b9c316797a43bf7c356292d": {
			"balance": "114000000000000000000"
		},
		"21a6feb6ab11c766fdd977f8df4121155f47a1c0": {
			"balance": "57200000000000000000"
		},
		"e95e92bbc6de07bf3a660ebf5feb1c8a3527e1c5": {
			"balance": "18200000000000000000"
		},
		"0b369e002e1b4c7913fcf00f2d5e19c58165478f": {
			"balance": "64520000000000000000"
		},
		"0909648c18a3ce5bae7a047ec2f868d24cdda81d": {
			"balance": "3820000000000000000000"
		},
		"d32b45564614516c91b07fa9f72dcf787cce4e1c": {
			"balance": "291000000000000000000"
)E" + R"E(
		},
		"cf1bdb799b2ea63ce134668bdc198b54840f180b": {
			"balance": "18200000000000000000"
		},
		"ae062c448618643075de7a0030342dced63dbad7": {
			"balance": "825982000000000000000"
		},
		"99dfd0504c06c743e46534fd7b55f1f9c7ec3329": {
			"balance": "2000000000000000000000"
		},
		"87fc4635263944ce14a46c75fa4a821f39ce7f72": {
			"balance": "20000000000000000000"
		},
		"27c2d7ca504daa3d9066dc09137dc42f3aaab452": {
			"balance": "600000000000000000000"
		},
		"cc60f836acdef3548a1fefcca13ec6a937db44a0": {
			"balance": "86500000000000000000"
		},
		"c910a970556c9716ea53af66ddef93143124913d": {
			"balance": "1580000000000000000000"
		},
		"8173c835646a672e0152be10ffe84162dd256e4c": {
			"balance": "492000000000000000000"
		},
		"e989733ca1d58d9e7b5029ba5d444858bec03172": {
			"balance": "581595000000000000000"
		},
		"86806474c358047d9406e6a07f40945bc8328e67": {
			"balance": "6884000000000000000000"
		},
		"5395a4455d95d178b4532aa4725b193ffe512961": {
			"balance": "1000000000000000000000"
		},
		"56397638bb3cebf1f62062794b5eb942f916171d": {
			"balance": "2000000000000000000000"
		},
		"6958f83bb2fdfb27ce0409cd03f9c5edbf4cbedd": {
			"balance": "20000000000000000000000"
		},
		"26ff0a51e7cece8400276978dbd6236ef162c0e6": {
			"balance": "100020000000000000000000"
		},
		"4ca783b556e5bf53aa13c8116613d65782c9b642": {
			"balance": "25200000000000000000000"
		},
		"15a0aec37ff9ff3d5409f2a4f0c1212aaccb0296": {
			"balance": "1000000000000000000000"
		},
		"50378af7ef54043f892ab7ce97d647793511b108": {
			"balance": "19700000000000000000"
		},
		"e7c6b5fc05fc748e5b4381726449a1c0ad0fb0f1": {
			"balance": "2000000000000000000000"
		},
		"5317ecb023052ca7f5652be2fa854cfe4563df4d": {
			"balance": "499986000000000000000"
		},
		"c94f7c35c027d47df8ef4f9df85a9248a17dd23b": {
			"balance": "29944000000000000000"
		},
		"6a63fc89abc7f36e282d80787b7b04afd6553e71": {
			"balance": "160000000000000000000"
		},
		"5fd3d6777ec2620ae83a05528ed425072d3ca8fd": {
			"balance": "2000000000000000000000"
		},
		"29adcf83b6b20ac6a434abb1993cbd05c60ea2e4": {
			"balance": "10000000000000000000000"
		},
		"8c6f9f4e5b7ae276bf58497bd7bf2a7d25245f64": {
			"balance": "2730000000000000000000"
		},
		"d94a57882a52739bbe2a0647c80c24f58a2b4f1c": {
			"balance": "1341230000000000000000"
		},
		"7286e89cd9de8f7a8a00c86ffdb53992dd9251d1": {
			"balance": "1940000000000000000000"
		},
		"5773b6026721a1dd04b7828cd62b591bfb34534c": {
			"balance": "27000000000000000000000"
		},
		"11fefb5dc1a4598aa712640c517775dfa1d91f8c": {
			"balance": "10000000000000000000000"
		},
		"c6e324beeb5b36765ecd464260f7f26006c5c62e": {
			"balance": "2000000000000000000000"
		},
		"118fbd753b9792395aef7a4d78d263cdcaabd4f7": {
			"balance": "999800000000000000000"
		},
		"f8298591523e50b103f0b701d623cbf0f74556f6": {
			"balance": "200000000000000000000"
		},
		"ab0ced762e1661fae1a92afb1408889413794825": {
			"balance": "1910000000000000000000"
		},
		"fa67b67b4f37a0150915110ede073b05b853bda2": {
			"balance": "647490000000000000000"
		},
)E" + R"E(
		"ca122cf0f2948896b74843f49afed0ba1618eed7": {
			"balance": "560000000000000000000"
		},
		"186b95f8e5effddcc94f1a315bf0295d3b1ea588": {
			"balance": "1999944000000000000000"
		},
		"2915624bcb679137b8dae9ab57d11b4905eaee4b": {
			"balance": "20000000000000000000"
		},
		"0c6845bf41d5ee273c3ee6b5b0d69f6fd5eabbf7": {
			"balance": "3000026000000000000000"
		},
		"cb7479109b43b26657f4465f4d18c6f974be5f42": {
			"balance": "1820000000000000000000"
		},
		"8dd6a9bae57f518549ada677466fea8ab04fd9b4": {
			"balance": "4000000000000000000000"
		},
		"34958a46d30e30b273ecc6e5d358a212e5307e8c": {
			"balance": "2000000000000000000000"
		},
		"2003717907a72560f4307f1beecc5436f43d21e7": {
			"balance": "500000000000000000000"
		},
		"55ab99b0e0e55d7bb874b7cfe834de631c97ec23": {
			"balance": "1031400000000000000000"
		},
		"79b48d2d6137c3854d611c01ea42427a0f597bb7": {
			"balance": "191000000000000000000"
		},
		"d609ec0be70d0ad26f6e67c9d4762b52ee51122c": {
			"balance": "1000000000000000000000"
		},
		"e8c3f045bb7d38c9d2f395b0ba8492b253230901": {
			"balance": "9000000000000000000000"
		},
		"aaca60d9d700e78596bbbbb1f1e2f70f4627f9d8": {
			"balance": "999996000000000000000"
		},
		"89d75b8e0831e46f80bc174188184e006fde0eae": {
			"balance": "1000000000000000000000"
		},
		"b3667894b7863c068ad344873fcff4b5671e0689": {
			"balance": "20000000000000000000000"
		},
		"bc1609d685b76b48ec909aa099219022f89b2ccd": {
			"balance": "1182000000000000000000"
		},
		"88ee7f0efc8f778c6b687ec32be9e7d6f020b674": {
			"balance": "2000000000000000000000"
		},
		"470ac5d1f3efe28f3802af925b571e63868b397d": {
			"balance": "2000000000000000000000"
		},
		"abf8ffe0708a99b528cc1ed4e9ce4b0d0630be8c": {
			"balance": "2263600000000000000000"
		},
		"8cee38d6595788a56e3fb94634b3ffe1fbdb26d6": {
			"balance": "20000000000000000000000"
		},
		"19798cbda715ea9a9b9d6aab942c55121e98bf91": {
			"balance": "1200000000000000000000"
		},
		"e25a167b031e84616d0f013f31bda95dcc6350b9": {
			"balance": "10560000000000000000000"
		},
		"6196c3d3c0908d254366b7bca55745222d9d4db1": {
			"balance": "4000000000000000000000"
		},
		"e8e9850586e94f5299ab494bb821a5f40c00bd04": {
			"balance": "3820000000000000000000"
		},
		"1059cbc63e36c43e88f30008aca7ce058eeaa096": {
			"balance": "100000000000000000000000"
		},
		"c4f2913b265c430fa1ab8adf26c333fc1d9b66f2": {
			"balance": "20000000000000000000"
		},
		"26e9e2ad729702626417ef25de0dc800f7a779b3": {
			"balance": "1000000000000000000000"
		},
		"0dfbd4817050d91d9d625c02053cf61a3ee28572": {
			"balance": "340000000000000000000"
		},
		"709fe9d2c1f1ce42207c9585044a60899f35942f": {
			"balance": "2000000000000000000000"
		},
		"7ad82caea1a8b4ed05319b9c9870173c814e06ee": {
			"balance": "616000000000000000000"
		},
		"2a595f16eee4cb0c17d9a2d939b3c10f6c677243": {
			"balance": "1100000000000000000000"
		},
		"a8f89dd5cc6e64d7b1eeace00702022cd7d2f03d": {
			"balance": "700000000000000000000"
		},
		"c0a6cbad77692a3d88d141ef769a99bb9e3c9951": {
			"balance": "100000000000000000000"
		},
		"868c23be873466d4c74c220a19b245d1787e807f": {
)E" + R"E(
			"balance": "1366481000000000000000"
		},
		"2905b192e83ce659aa355b9d0c204e3e95f9bb9a": {
			"balance": "2160817000000000000000"
		},
		"50b9fef0a1329b02d16506255f5a2db71ec92d1f": {
			"balance": "1325464000000000000000"
		},
		"fc10b7a67b3268d5331bfb6a14def5ea4a162ca3": {
			"balance": "200000000000000000000"
		},
		"85eb256b51c819d60ea61a82d12c9358d59c1cae": {
			"balance": "460000000000000000000"
		},
		"75de7e9352e90b13a59a5878ffecc7831cac4d82": {
			"balance": "2740000000000000000000"
		},
		"d32b2c79c36478c5431901f6d700b04dbe9b8810": {
			"balance": "396000000000000000000"
		},
		"2d0326b23f0409c0c0e9236863a133075a94ba18": {
			"balance": "210380000000000000000"
		},
		"d2e21ed56868fab28e0947927adaf29f23ebad6c": {
			"balance": "1994000000000000000000"
		},
		"2ad6c9d10c261819a1a0ca2c48d8c7b2a71728df": {
			"balance": "1000000000000000000000"
		},
		"7d445267c59ab8d2a2d9e709990e09682580c49f": {
			"balance": "1000000000000000000000"
		},
		"b6047cdf932db3e4045f4976122341537ed5961e": {
			"balance": "20000000000000000000"
		},
		"2b3cf97311ff30f460945a9d8099f4a88e26d456": {
			"balance": "2000000000000000000000"
		},
		"7f4f593b618c330ba2c3d5f41eceeb92e27e426c": {
			"balance": "2775000000000000000000"
		},
		"72a2fc8675feb972fa41b50dffdbbae7fa2adfb7": {
			"balance": "2853840000000000000000"
		},
		"076561a856455d7ef86e63f87c73dbb628a55f45": {
			"balance": "900000000000000000000"
		},
		"03d1724fd00e54aabcd2de2a91e8462b1049dd3a": {
			"balance": "2640000000000000000000"
		},
		"7ea0f96ee0a573a330b56897761f3d4c0130a8e3": {
			"balance": "1337000000000000000000"
		},
		"fe65c4188d7922576909642044fdc52395560165": {
			"balance": "4000000000000000000000"
		},
		"57883010b4ac857fedac03eab2551723a8447ffb": {
			"balance": "1000000000000000000000"
		},
		"0729a8a4a5ba23f579d0025b1ad0f8a0d35cdfd2": {
			"balance": "9700000000000000000000"
		},
		"e75c1fb177089f3e58b1067935a6596ef1737fb5": {
			"balance": "99910000000000000000"
		},
		"e0e978753d982f7f9d1d238a18bd4889aefe451b": {
			"balance": "9700000000000000000000"
		},
		"5620f46d1451c2353d6243a5d4b427130be2d407": {
			"balance": "60000000000000000000"
		},
		"f3d688f06bbdbf50f9932c4145cbe48ecdf68904": {
			"balance": "20000000000000000000"
		},
		"3aa948ea02397755effb2f9dc9392df1058f7e33": {
			"balance": "850000000000000000000"
		},
		"20d1417f99c569e3beb095856530fe12d0fceaaa": {
			"balance": "1182175000000000000000"
		},
		"ac77bdf00fd5985b5db12bbef800380abc2a0677": {
			"balance": "1000000000000000000000"
		},
		"267a7e6e82e1b91d51deddb644f0e96dbb1f7f7e": {
			"balance": "20000000000000000000"
		},
		"4bbcbf38b3c90163a84b1cd2a93b58b2a3348d87": {
			"balance": "8000000000000000000000"
		},
		"4c6b93a3bec16349540cbfcae96c9621d6645010": {
			"balance": "2000000000000000000000"
		},
		"c9308879056dfe138ef8208f79a915c6bc7e70a8": {
			"balance": "10000000000000000000000"
		},
		"c48b693cacefdbd6cb5d7895a42e3196327e261c": {
			"balance": "1000000000000000000000"
		},
		"a0951970dfd0832fb83bda12c23545e79041756c": {
			"balance": "600000000000000000000"
)E" + R"E(
		},
		"7cdf74213945953db39ad0e8a9781add792e4d1d": {
			"balance": "2000000000000000000000"
		},
		"75621865b6591365606ed378308c2d1def4f222c": {
			"balance": "3100000000000000000000"
		},
		"67d6a8aa1bf8d6eaf7384e993dfdf10f0af68a61": {
			"balance": "198067000000000000000"
		},
		"8f0af37566d152802f1ae8f928b25af9b139b448": {
			"balance": "200000000000000000000"
		},
		"2c6afcd4037c1ed14fa74ff6758e0945a185a8e8": {
			"balance": "17600000000000000000"
		},
		"c1b2aa8cb2bf62cdc13a47ecc4657facaa995f98": {
			"balance": "1000129000000000000000"
		},
		"9e8144e08e89647811fe6b72d445d6a5f80ad244": {
			"balance": "10000000000000000000000"
		},
		"e04ff5e5a7e2af995d8857ce0290b53a2b0eda5d": {
			"balance": "1000000000000000000000"
		},
		"03dedfcd0b3c2e17c705da248790ef98a6bd5751": {
			"balance": "1337000000000000000000"
		},
		"698a8a6f01f9ab682f637c7969be885f6c5302bf": {
			"balance": "19400000000000000000"
		},
		"d82c6fedbdac98af2eed10b00f32b00056ca5a6d": {
			"balance": "200000000000000000000"
		},
		"2697b339813b0c2d964b2471eb1c606f4ecb9616": {
			"balance": "1154000000000000000000"
		},
		"987c9bcd6e3f3990a52be3eda4710c27518f4f72": {
			"balance": "400000000000000000000"
		},
		"c5d48ca2db2f85d8c555cb0e9cfe826936783f9e": {
			"balance": "200000000000000000000"
		},
		"da214c023e2326ff696c00393168ce46ffac39ec": {
			"balance": "1000000000000000000000"
		},
		"86570ab259c9b1c32c9729202f77f590c07dd612": {
			"balance": "200000000000000000000"
		},
		"a646a95c6d6f59f104c6541d7760757ab392b08c": {
			"balance": "4200000000000000000000"
		},
		"1933e334c40f3acbad0c0b851158206924beca3a": {
			"balance": "7551541000000000000000"
		},
		"3552a496eba67f12be6eedab360cd13661dc7480": {
			"balance": "300000000000000000000"
		},
		"2a9c96c19151ffcbe29a4616d0c52b3933b4659f": {
			"balance": "69263000000000000000"
		},
		"3b7b8e27de33d3ce7961b98d19a52fe79f6c25be": {
			"balance": "100000000000000000000000"
		},
		"a1911405cf6e999ed011f0ddcd2a4ff7c28f2526": {
			"balance": "40000000000000000000"
		},
		"0cae108e6db99b9e637876b064c6303eda8a65c8": {
			"balance": "3000000000000000000000"
		},
		"3883becc08b9be68ad3b0836aac3b620dc0017ef": {
			"balance": "2000000000000000000000"
		},
		"d0abcc70c0420e0e172f97d43b87d5e80c336ea9": {
			"balance": "10000000000000000000000"
		},
		"cbf16a0fe2745258cd52db2bf21954c975fc6a15": {
			"balance": "300000000000000000000"
		},
		"1b23cb8663554871fbbe0d9e60397efb6faedc3e": {
			"balance": "200000000000000000000"
		},
		"fbede32c349f3300ef4cd33b4de7dc18e443d326": {
			"balance": "3160000000000000000000"
		},
		"5e806e845730f8073e6cc9018ee90f5c05f909a3": {
			"balance": "9480000000000000000000"
		},
		"425c338a1325e3a1578efa299e57d986eb474f81": {
			"balance": "2000000000000000000000"
		},
		"8bf297f8f453523ed66a1acb7676856337b93bf0": {
			"balance": "4000000000000000000000"
		},
		"38e8a31af2d265e31a9fff2d8f46286d1245a467": {
			"balance": "20000000000000000000"
		},
		"7edafba8984baf631a820b6b92bbc2c53655f6bd": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"aa0200f1d17e9c54da0647bb96395d57a78538d8": {
			"balance": "1056000000000000000000"
		},
		"433eb94a339086ed12d9bde9cd1d458603c97dd6": {
			"balance": "100000000000000000000000"
		},
		"cd7e47909464d871b9a6dc76a8e9195db3485e7a": {
			"balance": "9850000000000000000000"
		},
		"5975d78d974ee5bb9e4d4ca2ae77c84b9c3b4b82": {
			"balance": "1370000000000000000000"
		},
		"cea2896623f4910287a2bdc5be83aea3f2e6de08": {
			"balance": "9359000000000000000000"
		},
		"cb4ad0c723da46ab56d526da0c1d25c73daff10a": {
			"balance": "510000000000000000000"
		},
		"e2cf360aa2329eb79d2bf7ca04a27a17c532e4d8": {
			"balance": "102000000000000000000"
		},
		"ea60549ec7553f511d2149f2d4666cbd9243d93c": {
			"balance": "2000000000000000000000"
		},
		"cbb7be17953f2ccc93e1bc99805bf45511434e4c": {
			"balance": "50440000000000000000000"
		},
		"3549bd40bbbc2b30095cac8be2c07a0588e0aed6": {
			"balance": "20000000000000000000"
		},
		"6510df42a599bcb0a519cca961b488759a6f6777": {
			"balance": "2000000000000000000000"
		},
		"ed12a1ba1fb8adfcb20dfa19582e525aa3b74524": {
			"balance": "6685000000000000000000"
		},
		"135eb8c0e9e101deedec11f2ecdb66ae1aae8867": {
			"balance": "20000000000000000000000"
		},
		"ee906d7d5f1748258174be4cbc38930302ab7b42": {
			"balance": "200000000000000000000"
		},
		"253f1e742a2cec86b0d7b306e5eacb6ccb2f8554": {
			"balance": "20040000000000000000000"
		},
		"ecd1a62802351a41568d23033004acc6c005a5d3": {
			"balance": "50000000000000000000"
		},
		"558c54649a8a6e94722bd6d21d14714f71780534": {
			"balance": "2000000000000000000000"
		},
		"ca657ec06fe5bc09cf23e52af7f80cc3689e6ede": {
			"balance": "900000000000000000000"
		},
		"74bf7a5ab59293149b5c60cf364263e5ebf1aa0d": {
			"balance": "115800000000000000000"
		},
		"7a6d781c77c4ba1fcadf687341c1e31799e93d27": {
			"balance": "274000000000000000000"
		},
		"77028e409cc43a3bd33d21a9fc53ec606e94910e": {
			"balance": "3880000000000000000000"
		},
		"4781a10a4df5eebc82f4cfe107ba1d8a7640bd66": {
			"balance": "1790000000000000000000"
		},
		"78e08bc533413c26e291b3143ffa7cc9afb97b78": {
			"balance": "200000000000000000000"
		},
		"03ef6ad20ff7bd4f002bac58d47544cf879ae728": {
			"balance": "6895000000000000000000"
		},
		"0e3696cf1f4217b163d1bc12a5ea730f1c32a14a": {
			"balance": "4000000000000000000000"
		},
		"825135b1a7fc1605614c8aa4d0ac6dbad08f480e": {
			"balance": "1430000000000000000000"
		},
		"286b186d61ea1fd78d9930fe12b06537b05c3d51": {
			"balance": "1000000000000000000000"
		},
		"8d6657f59711b1f803c6ebef682f915b62f92dc9": {
			"balance": "2000000000000000000000"
		},
		"da8bbee182e455d2098acb338a6d45b4b17ed8b6": {
			"balance": "2000000000000000000000"
		},
		"3f2da093bb16eb064f8bfa9e30b929d15f8e1c4c": {
			"balance": "2000000000000000000000"
		},
		"f5d9cf00d658dd45517a48a9d3f5f633541a533d": {
			"balance": "116400000000000000000"
		},
		"c5f64babb7033142f20e46d7aa6201ed86f67103": {
			"balance": "2000000000000000000000"
		},
		"a2e2b5941e0c01944bfe1d5fb4e8a34b922ccfb1": {
			"balance": "200000000000000000000"
		},
		"6114b0eae5576903f80bfb98842d24ed92237f1e": {
)E" + R"E(
			"balance": "100000000000000000000"
		},
		"38df0c4abe7ded5fe068eadf154ac691774324a4": {
			"balance": "1790000000000000000000"
		},
		"1c2010bd662df417f2a271879afb13ef4c88a3ae": {
			"balance": "4000000000000000000000"
		},
		"918967918cd897dd0005e36dc6c883ef438fc8c7": {
			"balance": "140000000000000000000"
		},
		"a522de7eb6ae1250522a513133a93bd42849475c": {
			"balance": "20000000000000000000000"
		},
		"7de442c82386154d2e993cbd1280bb7ca6b12ada": {
			"balance": "4002000000000000000000"
		},
		"66424bd8785b8cb461102a900283c35dfa07ef6a": {
			"balance": "40221000000000000000"
		},
		"7bbbec5e70bdead8bb32b42805988e9648c0aa97": {
			"balance": "1000076000000000000000"
		},
		"fec06fe27b44c784b2396ec92f7b923ad17e9077": {
			"balance": "2000000000000000000000"
		},
		"95d550427b5a514c751d73a0f6d29fb65d22ed10": {
			"balance": "300000000000000000000"
		},
		"8dde60eb08a099d7daa356daaab2470d7b025a6b": {
			"balance": "197000000000000000000"
		},
		"81bccbff8f44347eb7fca95b27ce7c952492aaad": {
			"balance": "152240000000000000000"
		},
		"3995e096b08a5a726800fcd17d9c64c64e088d2b": {
			"balance": "200000000000000000000"
		},
		"4ee13c0d41200b46d19dee5c4bcec71d82bb8e38": {
			"balance": "7893915000000000000000"
		},
		"c41461a3cfbd32c9865555a4813137c076312360": {
			"balance": "999999000000000000000"
		},
		"3300fb149aded65bcba6c04e9cd6b7a03b893bb1": {
			"balance": "18200000000000000000"
		},
		"29f9286c0e738d1721a691c6b95ab3d9a797ede8": {
			"balance": "200000000000000000000000"
		},
		"34c8e5f1330fcb4b14ca75cb2580a4b93d204e36": {
			"balance": "2000000000000000000000"
		},
		"ec5df227bfa85d7ad76b426e1cee963bc7f519dd": {
			"balance": "1000000000000000000000"
		},
		"797510e386f56393ced8f477378a444c484f7dad": {
			"balance": "1000000000000000000000"
		},
		"0191eb547e7bf6976b9b1b577546761de65622e2": {
			"balance": "1999980000000000000000"
		},
		"615a6f36777f40d6617eb5819896186983fd3731": {
			"balance": "5910000000000000000000"
		},
		"17580b766f7453525ca4c6a88b01b50570ea088c": {
			"balance": "100000000000000000000"
		},
		"945d96ea573e8df7262bbfa572229b4b16016b0f": {
			"balance": "209300000000000000000"
		},
		"2de0964400c282bdd78a919c6bf77c6b5f796179": {
			"balance": "200000000000000000000"
		},
		"304ec69a74545721d7316aef4dcfb41ac59ee2f0": {
			"balance": "200000000000000000000"
		},
		"be2b326e78ed10e550fee8efa8f8070396522f5a": {
			"balance": "39400000000000000000000"
		},
		"1a0841b92a7f7075569dc4627e6b76cab05ade91": {
			"balance": "1520000000000000000000"
		},
		"5fa61f152de6123516c751242979285f796ac791": {
			"balance": "204000000000000000000"
		},
		"68c8791dc342c373769ea61fb7b510f251d32088": {
			"balance": "1000000000000000000000"
		},
		"4167cd48e733418e8f99ffd134121c4a4ab278c4": {
			"balance": "3640000000000000000000"
		},
		"598aaabae9ed833d7bc222e91fcaa0647b77580b": {
			"balance": "1800000000000000000000"
		},
		"979f30158b574b999aab348107b9eed85b1ff8c1": {
			"balance": "970000000000000000000"
		},
		"3ad06149b21c55ff867cc3fb9740d2bcc7101231": {
			"balance": "197000000000000000000000"
)E" + R"E(
		},
		"7133843a78d939c69d4486e10ebc7b602a349ff7": {
			"balance": "329000000000000000000"
		},
		"8bdfda6c215720eda2136f91052321af4e936c1f": {
			"balance": "1000008000000000000000"
		},
		"3e1c53300e4c168912163c7e99b95da268ad280a": {
			"balance": "1003200000000000000000"
		},
		"e07ebbc7f4da416e42c8d4f842aba16233c12580": {
			"balance": "2000000000000000000000"
		},
		"bac8922c4acc7d2cb6fd59a14eb45cf3e702214b": {
			"balance": "800000000000000000000"
		},
		"bb6c284aac8a69b75cddb00f28e145583b56bece": {
			"balance": "2000000000000000000000"
		},
		"0372ee5508bf8163ed284e5eef94ce4d7367e522": {
			"balance": "100000000000000000000"
		},
		"17125b59ac51cee029e4bd78d7f5947d1ea49bb2": {
			"balance": "22000000000000000000000"
		},
		"c88ca1e6e5f4d558d13780f488f10d4ad3130d34": {
			"balance": "1550000000000000000000"
		},
		"a825fd5abb7926a67cf36ba246a24bd27be6f6ed": {
			"balance": "17600000000000000000"
		},
		"04241b41ecbd0bfdf1295e9d4fa59ea09e6c6186": {
			"balance": "1870000000000000000000"
		},
		"6de4d15219182faf3aa2c5d4d2595ff23091a727": {
			"balance": "1580000000000000000000"
		},
		"b203d29e6c56b92699c4b92d1f6f84648dc4cfbc": {
			"balance": "400000000000000000000"
		},
		"80b42de170dbd723f454e88f7716452d92985092": {
			"balance": "300202000000000000000"
		},
		"0a5b79d8f23b6483dbe2bdaa62b1064cc76366ae": {
			"balance": "1969803000000000000000"
		},
		"32034e8581d9484e8af42a28df190132ec29c466": {
			"balance": "3460000000000000000000"
		},
		"7ee604c7a9dc2909ce321de6b9b24f5767577555": {
			"balance": "5533575000000000000000"
		},
		"a387ce4e961a7847f560075c64e1596b5641d21c": {
			"balance": "668500000000000000000"
		},
		"fcc9d4a4262e7a027ab7519110d802c495ceea39": {
			"balance": "6370000000000000000000"
		},
		"ff8a2ca5a81333f19998255f203256e1a819c0aa": {
			"balance": "224000000000000000000"
		},
		"f9811fa19dadbf029f8bfe569adb18228c80481a": {
			"balance": "200000000000000000000"
		},
		"0d1f2a57713ebc6e94de29846e8844d376665763": {
			"balance": "5000000000000000000000"
		},
		"eab0bd148309186cf8cbd13b7232d8095acb833a": {
			"balance": "10691800000000000000000"
		},
		"36928b55bc861509d51c8cf1d546bfec6e3e90af": {
			"balance": "1970000000000000000000"
		},
		"30480164bcd84974ebc0d90c9b9afab626cd1c73": {
			"balance": "800000000000000000000"
		},
		"36339f84a5c2b44ce53dfdb6d4f97df78212a7df": {
			"balance": "321600000000000000000"
		},
		"cfeacaaed57285e0ac7268ce6a4e35ecfdb242d7": {
			"balance": "1086400000000000000000"
		},
		"572dd8cd3fe399d1d0ec281231b7cefc20b9e4bb": {
			"balance": "10400000000000000000000"
		},
		"5dded049a6e1f329dc4b971e722c9c1f2ade83f0": {
			"balance": "1000000000000000000000"
		},
		"9756e176c9ef693ee1eec6b9f8b151d313beb099": {
			"balance": "1200000000000000000000"
		},
		"01e6415d587b065490f1ed7f21d6e0f386ee6747": {
			"balance": "2000000000000000000000"
		},
		"b4413576869c08f9512ad311fe925988a52d3414": {
			"balance": "10000000000000000000000"
		},
		"da9f55460946d7bfb570ddec757ca5773b58429a": {
			"balance": "507600000000000000000"
		},
)E" + R"E(
		"7180b83ee5574317f21c8072b191d895d46153c3": {
			"balance": "460000000000000000000"
		},
		"0aca9a5626913b08cfc9a66d40508dce52b60f87": {
			"balance": "1910000000000000000000"
		},
		"5cd0e475b54421bdfc0c12ea8e082bd7a5af0a6a": {
			"balance": "59000000000000000000"
		},
		"7edb02c61a227287611ad950696369cc4e647a68": {
			"balance": "274000000000000000000"
		},
		"b2676841ee9f2d31c172e82303b0fe9bbf9f1e09": {
			"balance": "200000000000000000000"
		},
		"a2222259dd9c3e3ded127084f808e92a1887302c": {
			"balance": "162000000000000000000"
		},
		"4b3a7cc3a7d7b00ed5282221a60259f25bf6538a": {
			"balance": "1000000000000000000000"
		},
		"e33ff987541dde5cdee0a8a96dcc3f33c3f24cc2": {
			"balance": "200000000000000000000000"
		},
		"1e1a4828119be309bd88236e4d482b504dc55711": {
			"balance": "2955000000000000000000"
		},
		"9b1811c3051f46e664ae4bc9c824d18592c4574a": {
			"balance": "199955000000000000000"
		},
		"59fe00696dbd87b7976b29d1156c8842a2e17914": {
			"balance": "2000000000000000000000"
		},
		"48010ef3b8e95e3f308f30a8cb7f4eb4bf60d965": {
			"balance": "2000000000000000000000"
		},
		"c90300cb1d4077e6a6d7e169a460468cf4a492d7": {
			"balance": "2000000000000000000000"
		},
		"6dedf62e743f4d2c2a4b87a787f5424a7aeb393c": {
			"balance": "180000000000000000000"
		},
		"fb744b951d094b310262c8f986c860df9ab1de65": {
			"balance": "52009000000000000000"
		},
		"193ac65183651800e23580f8f0ead3bb597eb8a4": {
			"balance": "50020000000000000000"
		},
		"bf05ff5ecf0df2df887759fb8274d93238ac267d": {
			"balance": "800000000000000000000"
		},
		"6c0e712f405c59725fe829e9774bf4df7f4dd965": {
			"balance": "57413800000000000000000"
		},
		"2744ff67464121e35afc2922177164fa2fcb0267": {
			"balance": "100000000000000000000"
		},
		"d09cb2e6082d693a13e8d2f68dd1dd8461f55840": {
			"balance": "1000000000000000000000"
		},
		"bc171e53d17ac9b61241ae436deec7af452e7496": {
			"balance": "5348000000000000000000"
		},
		"71fa22cc6d33206b7d701a163a0dab31ae4d31d6": {
			"balance": "1610000000000000000000"
		},
		"4da8030769844bc34186b85cd4c7348849ff49e9": {
			"balance": "10000000000000000000000"
		},
		"c8616b4ec09128cdff39d6e4b9ac86eec471d5f2": {
			"balance": "19400000000000000000"
		},
		"407295ebd94b48269c2d569c9b9af9aa05e83e5e": {
			"balance": "10000000000000000000000"
		},
		"d45d5daa138dd1d374c71b9019916811f4b20a4e": {
			"balance": "576000000000000000000"
		},
		"42c6edc515d35557808d13cd44dcc4400b2504e4": {
			"balance": "197876000000000000000"
		},
		"0bc95cb32dbb574c832fa8174a81356d38bc92ac": {
			"balance": "2000000000000000000000"
		},
		"5a6071bcebfcba4ab57f4db96fc7a68bece2ba5b": {
			"balance": "2000000000000000000000"
		},
		"54c93e03a9b2e8e4c3672835a9ee76f9615bc14e": {
			"balance": "19400000000000000000"
		},
		"3c03bbc023e1e93fa3a3a6e428cf0cd8f95e1ec6": {
			"balance": "1520000000000000000000"
		},
		"ba1531fb9e791896bcf3a80558a359f6e7c144bd": {
			"balance": "3940000000000000000000"
		},
		"aa56a65dc4abb72f11bae32b6fbb07444791d5c9": {
			"balance": "748600000000000000000"
		},
		"e437acbe0f6227b0e36f36e4bcf7cf613335fb68": {
)E" + R"E(
			"balance": "200000000000000000000"
		},
		"39d4a931402c0c79c457186f24df8729cf957031": {
			"balance": "4000000000000000000000"
		},
		"e22b20c77894463baf774cc256d5bddbbf7ddd09": {
			"balance": "1000000000000000000000"
		},
		"70a4067d448cc25dc8e70e651cea7cf84e92109e": {
			"balance": "176000000000000000000"
		},
		"aa3925dc220bb4ae2177b2883078b6dc346ca1b2": {
			"balance": "8000000000000000000000"
		},
		"ad57aa9d00d10c439b35efcc0becac2e3955c313": {
			"balance": "200000000000000000000"
		},
		"e93d47a8ca885d540c4e526f25d5c6f2c108c4b8": {
			"balance": "112640000000000000000000"
		},
		"232ce782506225fd9860a2edc14a7a3047736da2": {
			"balance": "20000000000000000000"
		},
		"49a645e0667dfd7b32d075cc2467dd8c680907c4": {
			"balance": "129560000000000000000"
		},
		"cf2e734042a355d05ffb2e3915b16811f45a695e": {
			"balance": "2000000000000000000000"
		},
		"39b1c471ae94e12164452e811fbbe2b3cd7275ac": {
			"balance": "2000000000000000000000"
		},
		"ffad3dd74e2c1f796ac640de56dc99b4c792a402": {
			"balance": "5000000000000000000000"
		},
		"a69d7cd17d4842fe03f62a90b2fbf8f6af7bb380": {
			"balance": "100000000000000000000"
		},
		"2001bef77b66f51e1599b02fb110194a0099b78d": {
			"balance": "2000000000000000000000"
		},
		"95e7616424cd0961a71727247437f0069272280e": {
			"balance": "400000000000000000000"
		},
		"c04f4bd4049f044685b883b62959ae631d667e35": {
			"balance": "5820000000000000000000"
		},
		"ede0147ec032c3618310c1ff25690bf172193dac": {
			"balance": "2000000000000000000000"
		},
		"66719c0682b2ac7f9e27abebec7edf8decf0ae0d": {
			"balance": "20000000000000000000"
		},
		"45272b8f62e9f9fa8ce04420e1aea3eba9686eac": {
			"balance": "4000000000000000000000"
		},
		"d1da0c8fb7c210e0f2ec618f85bdae7d3e734b1c": {
			"balance": "1970000000000000000000"
		},
		"e9133e7d31845d5f2b66a2618792e869311acf66": {
			"balance": "24050000000000000000000"
		},
		"ebb62cf8e22c884b1b28c6fa88fbbc17938aa787": {
			"balance": "798000000000000000000"
		},
		"6205c2d5647470848a3840f3887e9b015d34755c": {
			"balance": "1800000000000000000000"
		},
		"76ca22bcb8799e5327c4aa2a7d0949a1fcce5f29": {
			"balance": "1524180000000000000000"
		},
		"6b925dd5d8ed6132ab6d0860b82c44e1a51f1fee": {
			"balance": "1480000000000000000000"
		},
		"797bb7f157d9feaa17f76da4f704b74dc1038341": {
			"balance": "3340000000000000000000"
		},
		"ae8954f8d6166de507cf61297d0fc7ca6b9e7128": {
			"balance": "300000000000000000000"
		},
		"75c1ad23d23f24b384d0c3149177e86697610d21": {
			"balance": "6426082000000000000000"
		},
		"805d846fb0bc02a7337226d685be9ee773b9198a": {
			"balance": "19999800000000000000000"
		},
		"c3cb6b36af443f2c6e258b4a39553a818747811f": {
			"balance": "1610000000000000000000"
		},
		"cea43f7075816b60bbfce68b993af0881270f6c4": {
			"balance": "2000000000000000000000"
		},
		"e0388aeddd3fe2ad56f85748e80e710a34b7c92e": {
			"balance": "500000000000000000000"
		},
		"e131f87efc5ef07e43f0f2f4a747b551d750d9e6": {
			"balance": "19999000000000000000000"
		},
		"c2b2cbe65bc6c2ee7a3c75b2e47c189c062e8d8b": {
			"balance": "20000000000000000000000"
)E" + R"E(
		},
		"bd8765f41299c7f479923c4fd18f126d7229047d": {
			"balance": "4000000000000000000000"
		},
		"c83ba6dd9549be1d3287a5a654d106c34c6b5da2": {
			"balance": "7000000000000000000000"
		},
		"f870995fe1e522321d754337a45c0c9d7b38951c": {
			"balance": "20000000000000000000"
		},
		"0d8ed7d0d15638330ed7e4eaccab8a458d75737e": {
			"balance": "2000000000000000000000"
		},
		"36c510bf8d6e569bf2f37d47265dbcb502ff2bce": {
			"balance": "30000000000000000000000"
		},
		"0eccf617844fd61fba62cb0e445b7ac68bcc1fbe": {
			"balance": "387260000000000000000"
		},
		"ae10e27a014f0d306baf266d4897c89aeee2e974": {
			"balance": "20000000000000000000000"
		},
		"1827039f09570294088fddf047165c33e696a492": {
			"balance": "9550000000000000000000"
		},
		"23378f42926d0184b793b0c827a6dd3e3d334fcd": {
			"balance": "56000000000000000000"
		},
		"467124ae7f452f26b3d574f6088894fa5d1cfb3b": {
			"balance": "2700000000000000000000"
		},
		"aae61e43cb0d0c96b30699f77e00d711d0a3979b": {
			"balance": "1000000000000000000000"
		},
		"15c7edb8118ee27b342285eb5926b47a855bc7a5": {
			"balance": "20000000000000000000"
		},
		"0d5d98565c647ca5f177a2adb9d3022fac287f21": {
			"balance": "200000000000000000000"
		},
		"7222fec7711781d26eaa4e8485f7aa3fac442483": {
			"balance": "456000000000000000000"
		},
		"dc44275b1715baea1b0345735a29ac42c9f51b4f": {
			"balance": "1164000000000000000000"
		},
		"04d82af9e01a936d97f8f85940b970f9d4db9936": {
			"balance": "200000000000000000000"
		},
		"45533390e340fe0de3b3cf5fb9fc8ea552e29e62": {
			"balance": "1460000000000000000000"
		},
		"1284f0cee9d2ff2989b65574d06ffd9ab0f7b805": {
			"balance": "400000000000000000000"
		},
		"ed9ebccba42f9815e78233266dd6e835b6afc31b": {
			"balance": "6000000000000000000000"
		},
		"e4324912d64ea3aef76b3c2ff9df82c7e13ae991": {
			"balance": "2000000000000000000000"
		},
		"94c742fd7a8b7906b3bfe4f8904fc0be5c768033": {
			"balance": "20000000000000000000000"
		},
		"62fb8bd1f0e66b90533e071e6cbe6111fef0bc63": {
			"balance": "17600000000000000000000"
		},
		"2c83aeb02fcf067d65a47082fd977833ab1cec91": {
			"balance": "150400000000000000000"
		},
		"06cbfa08cdd4fba737bac407be8224f4eef35828": {
			"balance": "593459000000000000000"
		},
		"67ee406ea4a7ae6a3a381eb4edd2f09f174b4928": {
			"balance": "1036000000000000000000"
		},
		"83c23d8a502124ee150f08d71dc6727410a0f901": {
			"balance": "33999600000000000000000"
		},
		"f7c00cdb1f020310d5acab7b496aaa44b779085e": {
			"balance": "1670000000000000000000"
		},
		"d096565b7c7407d06536580355fdd6d239144aa1": {
			"balance": "250000000000000000000"
		},
		"f8d52dcc5f96cc28007b3ecbb409f7e22a646caa": {
			"balance": "149200000000000000000"
		},
		"0c222c7c41c9b048efcce0a232434362e12d673b": {
			"balance": "10007600000000000000000"
		},
		"503bdbd8bc421c32a443032deb2e3e4cd5ba8b4e": {
			"balance": "2000000000000000000000"
		},
		"77da5e6c72fb36bce1d9798f7bcdf1d18f459c2e": {
			"balance": "22380000000000000000"
		},
		"e62f98650712eb158753d82972b8e99ca3f61877": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"87a7c508ef71582dd9a54372f89cb01f252fb180": {
			"balance": "200000000000000000000"
		},
		"f61283b4bd8504058ca360e993999b62cbc8cd67": {
			"balance": "255000000000000000000"
		},
		"9ccddcb2cfc2b25b08729a0a98d9e6f0202ea2c1": {
			"balance": "100000000000000000000"
		},
		"d460a4b908dd2b056759b488850b66a838fc77a8": {
			"balance": "1970000000000000000000"
		},
		"5431b1d18751b98fc9e2888ac7759f1535a2db47": {
			"balance": "2000000000000000000000"
		},
		"da2a14f9724015d79014ed8e5909681d596148f1": {
			"balance": "48499000000000000000"
		},
		"c989434f825aaf9c552f685eba7c11db4a5fc73a": {
			"balance": "501000000000000000000"
		},
		"2b701d16c0d3cc1e4cd85445e6ad02eea4ac012d": {
			"balance": "600000000000000000000"
		},
		"78b978a9d7e91ee529ea4fc4b76feaf8762f698c": {
			"balance": "32000000000000000000000"
		},
		"c89cf504b9f3f835181fd8424f5ccbc8e1bddf7d": {
			"balance": "10000000000000000000000"
		},
		"e94941b6036019b4016a30c1037d5a6903babaad": {
			"balance": "780000000000000000000"
		},
		"95d98d0c1069908f067a52acac2b8b534da37afd": {
			"balance": "2054053000000000000000"
		},
		"8284923b62e68bbf7c2b9f3414d13ef6c812a904": {
			"balance": "3880000000000000000000"
		},
		"3e5a39fdda70df1126ab0dc49a7378311a537a1f": {
			"balance": "2400000000000000000000"
		},
		"a2ace4c993bb1e5383f8ac74e179066e814f0591": {
			"balance": "100000000000000000000"
		},
		"0609d83a6ce1ffc9b690f3e9a81e983e8bdc4d9d": {
			"balance": "70000000000000000000000"
		},
		"d119417c46732cf34d1a1afb79c3e7e2cd8eece4": {
			"balance": "2000000000000000000000"
		},
		"fdb33944f2360615e5be239577c8a19ba52d9887": {
			"balance": "601650000000000000000"
		},
		"dd95dbe30f1f1877c5dd7684aeef302ab6885192": {
			"balance": "8372000000000000000000"
		},
		"413f4b02669ccff6806bc826fcb7deca3b0ea9bc": {
			"balance": "20000000000000000000"
		},
		"5800cd8130839e94495d2d8415a8ea2c90e0c5cb": {
			"balance": "200000000000000000000"
		},
		"65053191319e067a25e6361d47f37f6318f83419": {
			"balance": "394000000000000000000"
		},
		"9bc573bcda23b8b26f9073d90c230e8e71e0270b": {
			"balance": "999544000000000000000"
		},
		"97f7760657c1e202759086963eb4211c5f8139b9": {
			"balance": "49770000000000000000000"
		},
		"126897a311a14ad43b78e0920100c4426bfd6bdd": {
			"balance": "973581000000000000000"
		},
		"d5276f0cd5ffd5ffb63f98b5703d5594ede0838b": {
			"balance": "400000000000000000000"
		},
		"e9c35c913ca1fceab461582fe1a5815164b4fd21": {
			"balance": "8000000000000000000000"
		},
		"b43067fe70d9b55973ba58dc64dd7f311e554259": {
			"balance": "200000000000000000000"
		},
		"6f8f0d15cc96fb7fe94f1065bc6940f8d12957b2": {
			"balance": "1000000000000000000000"
		},
		"b1dba5250ba9625755246e067967f2ad2f0791de": {
			"balance": "80000000000000000000000"
		},
		"72b7a03dda14ca9c661a1d469fd33736f673c8e8": {
			"balance": "2000000000000000000000"
		},
		"e792349ce9f6f14f81d0674096befa1f9221cdea": {
			"balance": "1685365000000000000000"
		},
		"1815279dff9952da3be8f77249dbe22243377be7": {
			"balance": "4749800000000000000000"
		},
		"33481e856ebed48ea708a27426ef28e867f57cd1": {
)E" + R"E(
			"balance": "200000000000000000000"
		},
		"8eb8c71982a00fb84275293253f8044544b66b49": {
			"balance": "400000000000000000000"
		},
		"65f5870f26bce089677dfc23b5001ee492483428": {
			"balance": "5067230000000000000000"
		},
		"8e23facd12c765c36ab81a6dd34d8aa9e68918ae": {
			"balance": "167310000000000000000"
		},
		"4912d902931676ff39fc34fe3c3cc8fb2182fa7a": {
			"balance": "20000000000000000000"
		},
		"c09a66172aea370d9a63da04ff71ffbbfcff7f94": {
			"balance": "2000000000000000000000"
		},
		"e969ea1595edc5c4a707cfde380929633251a2b0": {
			"balance": "200000000000000000000"
		},
		"4f2b47e2775a1fa7178dad92985a5bbe493ba6d6": {
			"balance": "200000000000000000000"
		},
		"cab9a97ada065c87816e6860a8f1426fe6b3d775": {
			"balance": "1000000000000000000000"
		},
		"cdfd8217339725d7ebac11a63655f265eff1cc3d": {
			"balance": "4999962000000000000000"
		},
		"ab4004c0403f7eabb0ea586f212156c4203d67f1": {
			"balance": "1999944000000000000000"
		},
		"1c7cb2fe6bf3e09cbcdc187af38fa8f5053a70b6": {
			"balance": "9970823000000000000000"
		},
		"a951b244ff50cfae591d5e1a148df6a938ef2a1a": {
			"balance": "1734000000000000000000"
		},
		"b158db43fa62d30e65f3d09bf781c7b67372ebaa": {
			"balance": "1999000000000000000000"
		},
		"25e037f00a18270ba5ec3420229ddb0a2ce38fa2": {
			"balance": "10000000000000000000000"
		},
		"2aaea1f1046f30f109faec1c63ef5c7594eb08da": {
			"balance": "4000000000000000000000"
		},
		"73d7269ff06c9ffd33754ce588f74a966abbbbba": {
			"balance": "6600000000000000000000"
		},
		"4c767b65fd91161f4fbdcc6a69e2f6ad711bb918": {
			"balance": "720000000000000000000"
		},
		"92ae5b7c7eb492ff1ffa16dd42ad9cad40b7f8dc": {
			"balance": "865000000000000000000"
		},
		"a04f2ae02add14c12faf65cb259022d0830a8e26": {
			"balance": "100000000000000000000000"
		},
		"63ef2fbc3daf5edaf4a295629ccf31bcdf4038e5": {
			"balance": "1460000000000000000000"
		},
		"749ad6f2b5706bbe2f689a44c4b640b58e96b992": {
			"balance": "100000000000000000000"
		},
		"4d836d9d3b0e2cbd4de050596faa490cffb60d5d": {
			"balance": "300000000000000000000"
		},
		"59f6247b0d582aaa25e5114765e4bf3c774f43c2": {
			"balance": "50000000000000000000"
		},
		"1293c78c7d6a443b9d74b0ba5ee7bb47fd418588": {
			"balance": "6685000000000000000000"
		},
		"67bc85e87dc34c4e80aafa066ba8d29dbb8e438e": {
			"balance": "402500000000000000000"
		},
		"a09f4d5eaa65a2f4cb750a49923401dae59090af": {
			"balance": "140000000000000000000"
		},
		"ebbd4db9019952d68b1b0f6d8cf0683c00387bb5": {
			"balance": "332330000000000000000"
		},
		"b16479ba8e7df8f63e1b95d149cd8529d735c2da": {
			"balance": "846477000000000000000"
		},
		"e1b2aca154b8e0766c4eba30bc10c7f35036f368": {
			"balance": "19980000000000000000"
		},
		"5c464197791c8a3da3c925436f277ab13bf2faa2": {
			"balance": "8000000000000000000000"
		},
		"170a88a8997f92d238370f1affdee6347050b013": {
			"balance": "3000800000000000000000"
		},
		"dadbfafd8b62b92a24efd75256dd83abdbd7bbdb": {
			"balance": "19700000000000000000"
		},
		"bb993b96ee925ada7d99d786573d3f89180ce3aa": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"f2c362b0ef991bc82fb36e66ff75932ae8dd8225": {
			"balance": "74000000000000000000"
		},
		"7f2382ffd8f83956467937f9ba72374623f11b38": {
			"balance": "600000000000000000000"
		},
		"74d1a4d0c7524e018d4e06ed3b648092b5b6af2c": {
			"balance": "50000000000000000000"
		},
		"24a750eae5874711116dd7d47b7186ce990d3103": {
			"balance": "200000000000000000000"
		},
		"a8e42a4e33d7526cca19d9a36dcd6e8040d0ea73": {
			"balance": "1080000000000000000000"
		},
		"3e1b2230afbbd310b4926a4c776d5ae7819c661d": {
			"balance": "30000000000000000000000"
		},
		"6af9f0dfeeaebb5f64bf91ab771669bf05295553": {
			"balance": "400000000000000000000"
		},
		"41e4a20275e39bdcefeb655c0322744b765140c2": {
			"balance": "10000000000000000000000"
		},
		"ceb089ec8a78337e8ef88de11b49e3dd910f748f": {
			"balance": "1000000000000000000000"
		},
		"e6bcd30a8fa138c5d9e5f6c7d2da806992812dcd": {
			"balance": "260000000000000000000000"
		},
		"e08c60313106e3f9334fe6f7e7624d211130c077": {
			"balance": "40000000000000000000"
		},
		"f5cffbba624e7eb321bc83c60ca68199b4e36671": {
			"balance": "2000000000000000000000"
		},
		"d7c2803ed7b0e0837351411a8e6637d168bc5b05": {
			"balance": "29549015000000000000000"
		},
		"0f3665d48e9f1419cd984fc7fa92788710c8f2e4": {
			"balance": "2000000000000000000000"
		},
		"b48921c9687d5510744584936e8886bdbf2df69b": {
			"balance": "1000000000000000000000"
		},
		"a94bbb8214cf8da0c2f668a2ac73e86248528d4b": {
			"balance": "960000000000000000000"
		},
		"be0c2a80b9de084b172894a76cf4737a4f529e1a": {
			"balance": "1999944000000000000000"
		},
		"fcf199f8b854222f182e4e1d099d4e323e2aae01": {
			"balance": "1000000000000000000000"
		},
		"b52dfb45de5d74e3df208332bc571c809b8dcf32": {
			"balance": "6000000000000000000000"
		},
		"704819d2e44d6ed1da25bfce84c49fcca25613e5": {
			"balance": "400000000000000000000"
		},
		"6ff6cc90d649de4e96cffee1077a5b302a848dcb": {
			"balance": "28600000000000000000"
		},
		"4d9c77d0750c5e6fbc247f2fd79274686cb353d6": {
			"balance": "20000000000000000000"
		},
		"68e8022740f4af29eb48db32bcecddfd148d3de3": {
			"balance": "1000000000000000000000"
		},
		"2cb615073a40dcdb99faa848572e987b3b056efb": {
			"balance": "799600000000000000000"
		},
		"64adcceec53dd9d9dd15c8cc1a9e736de4241d2c": {
			"balance": "56000000000000000000"
		},
		"2aec809df9325b9f483996e99f7331097f08aa0e": {
			"balance": "4000000000000000000000"
		},
		"438c2f54ff8e629bab36b1442b760b12a88f02ae": {
			"balance": "2000000000000000000000"
		},
		"9e35399071a4a101e9194daa3f09f04a0b5f9870": {
			"balance": "4000000000000000000000"
		},
		"a5c336083b04f9471b8c6ed73679b74d66c363ec": {
			"balance": "3014100000000000000000"
		},
		"7ad3f307616f19dcb143e6444dab9c3c33611f52": {
			"balance": "50000000000000000000"
		},
		"455cb8ee39ffbc752331e5aefc588ef0ee593454": {
			"balance": "999963000000000000000"
		},
		"c4c01afc3e0f045221da1284d7878574442fb9ac": {
			"balance": "7419944000000000000000"
		},
		"99268327c373332e06c3f6164287d455b9d5fa4b": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"4367ae4b0ce964f4a54afd4b5c368496db169e9a": {
			"balance": "2000000000000000000000"
		},
		"2cd79eb52027b12c18828e3eaab2969bfcd287e9": {
			"balance": "20000000000000000000"
		},
		"b96841cabbc7dbd69ef0cf8f81dff3c8a5e21570": {
			"balance": "12000000000000000000000"
		},
		"d7ebddb9f93987779b680155375438db65afcb6a": {
			"balance": "100600000000000000000"
		},
		"0631d18bbbbd30d9e1732bf36edae2ce8901ab80": {
			"balance": "3024800000000000000000"
		},
		"5fad960f6b2c84569c9f4d47bf1985fcb2c65da6": {
			"balance": "999972000000000000000"
		},
		"01d599ee0d5f8c38ab2d392e2c65b74c3ce31820": {
			"balance": "510000000000000000000"
		},
		"ff0cc8dac824fa24fc3caa2169e6e057cf638ad6": {
			"balance": "4000000000000000000000"
		},
		"c25266c7676632f13ef29be455ed948add567792": {
			"balance": "1337000000000000000000"
		},
		"9c344098ba615a398f11d009905b177c44a7b602": {
			"balance": "1000000000000000000000"
		},
		"3b0accaf4b607cfe61d17334c214b75cdefdbd89": {
			"balance": "2000000000000000000000"
		},
		"6d6634b5b8a40195d949027af4828802092ceeb6": {
			"balance": "3000000000000000000000"
		},
		"208c45732c0a378f17ac8324926d459ba8b658b4": {
			"balance": "2955000000000000000000"
		},
		"c24399b4bf86f7338fbf645e3b22b0e0b7973912": {
			"balance": "2000000000000000000000"
		},
		"29763dd6da9a7c161173888321eba6b63c8fb845": {
			"balance": "328000000000000000000"
		},
		"9c2fd54089af665df5971d73b804616039647375": {
			"balance": "1000000000000000000000"
		},
		"0e09646c99af438e99fa274cb2f9c856cb65f736": {
			"balance": "1910000000000000000000"
		},
		"be73274d8c5aa44a3cbefc8263c37ba121b20ad3": {
			"balance": "500000000000000000000"
		},
		"ecfd004d02f36cd4d8b4a8c1a9533b6af85cd716": {
			"balance": "5003800000000000000000"
		},
		"f978b025b64233555cc3c19ada7f4199c9348bf7": {
			"balance": "400000000000000000000000"
		},
		"705ddd38355482b8c7d3b515bda1500dd7d7a817": {
			"balance": "400000000000000000000"
		},
		"2b8a0dee5cb0e1e97e15cfca6e19ad21f995efad": {
			"balance": "504206000000000000000"
		},
		"1098cc20ef84bad5146639c4cd1ca6c3996cb99b": {
			"balance": "18200000000000000000"
		},
		"afdac5c1cb56e245bf70330066a817eaafac4cd1": {
			"balance": "20000000000000000000"
		},
		"910e996543344c6815fb97cda7af4b8698765a5b": {
			"balance": "103400000000000000000"
		},
		"94612781033b57b146ee74e753c672017f5385e4": {
			"balance": "3600000000000000000000"
		},
		"d03fc165576aaed525e5502c8e140f8b2e869639": {
			"balance": "6850000000000000000000"
		},
		"293384c42b6f8f2905ce52b7205c2274376c612b": {
			"balance": "1400000000000000000000"
		},
		"09ee12b1b42b05af9cf207d5fcac255b2ec411f2": {
			"balance": "58929000000000000000"
		},
		"dbd71efa4b93c889e76593de609c3b04cbafbe08": {
			"balance": "20000000000000000000"
		},
		"fa86ca27bf2854d98870837fb6f6dfe4bf6453fc": {
			"balance": "322061000000000000000"
		},
		"61ff8e67b34d9ee6f78eb36ffea1b9f7c15787af": {
			"balance": "1640000000000000000000"
		},
		"6d4cbf3d8284833ae99344303e08b4d614bfda3b": {
			"balance": "12000000000000000000000"
		},
		"2ff160c44f72a299b5ec2d71e28ce5446d2fcbaf": {
)E" + R"E(
			"balance": "360000000000000000000"
		},
		"94a7cda8f481f9d89d42c303ae1632b3b709db1d": {
			"balance": "300000000000000000000"
		},
		"7566496162ba584377be040a4f87777a707acaeb": {
			"balance": "4000000000000000000000"
		},
		"bdc461462b6322b462bdb33f22799e8108e2417d": {
			"balance": "668500000000000000000"
		},
		"7e47637e97c14622882be057bea229386f4052e5": {
			"balance": "440000000000000000000"
		},
		"3b5c251d7fd7893ba209fe541cecd0ce253a990d": {
			"balance": "30000000000000000000000"
		},
		"0e498800447177b8c8afc3fdfa7f69f4051bb629": {
			"balance": "2140234000000000000000"
		},
		"b71623f35107cf7431a83fb3d204b29ee0b1a7f4": {
			"balance": "19700000000000000000"
		},
		"1d395b30adda1cf21f091a4f4a7b753371189441": {
			"balance": "100000000000000000000000"
		},
		"2c2428e4a66974edc822d5dbfb241b2728075158": {
			"balance": "2000000000000000000000"
		},
		"a575f2891dcfcda83c5cf01474af11ee01b72dc2": {
			"balance": "100076000000000000000"
		},
		"ad728121873f0456d0518b80ab6580a203706595": {
			"balance": "500000000000000000000"
		},
		"48669eb5a801d8b75fb6aa58c3451b7058c243bf": {
			"balance": "30940000000000000000000"
		},
		"b3ae54fba09d3ee1d6bdd1e957923919024c35fa": {
			"balance": "65513000000000000000"
		},
		"0d35408f226566116fb8acdaa9e2c9d59b76683f": {
			"balance": "940000000000000000000"
		},
		"df211cd21288d6c56fae66c3ff54625dd4b15427": {
			"balance": "2500024000000000000000"
		},
		"8a746c5d67064711bfca685b95a4fe291a27028e": {
			"balance": "40000000000000000000"
		},
		"1cf105ab23023b554c583e86d7921179ee83169f": {
			"balance": "1970000000000000000000"
		},
		"8cfedef198db0a9143f09129b3fd64dcbb9b4956": {
			"balance": "2000000000000000000000"
		},
		"1e381adcf801a3bf9fd7bfac9ccc2b8482ad5e66": {
			"balance": "600200000000000000000"
		},
		"e74608f506866ada6bfbfdf20fea440be76989ef": {
			"balance": "1999944000000000000000"
		},
		"27e63989ca1e903bc620cf1b9c3f67b9e2ae6581": {
			"balance": "1337000000000000000000"
		},
		"bb0857f1c911b24b86c8a70681473fe6aaa1cce2": {
			"balance": "100000000000000000000"
		},
		"4f8e8d274fb22a3fd36a47fe72980471544b3434": {
			"balance": "200000000000000000000"
		},
		"127d3fc5003bf63c0d83e93957836515fd279045": {
			"balance": "111890000000000000000"
		},
		"95809e8da3fbe4b7f281f0b8b1715f420f7d7d63": {
			"balance": "2000000000000000000000"
		},
		"28904bb7c4302943b709b14d7970e42b8324e1a1": {
			"balance": "10027500000000000000000"
		},
		"c07e3867ada096807a051a6c9c34cc3b3f4ad34a": {
			"balance": "1788210000000000000000"
		},
		"f0b469eae89d400ce7d5d66a9695037036b88903": {
			"balance": "20000000000000000000000"
		},
		"7445202f0c74297a004eb3726aa6a82dd7c02fa1": {
			"balance": "2000000000000000000000"
		},
		"c58f62fee9711e6a05dc0910b618420aa127f288": {
			"balance": "3980000000000000000000"
		},
		"801d65c518b11d0e3f4f470221417013c8e53ec5": {
			"balance": "4000000000000000000000"
		},
		"41010fc8baf8437d17a04369809a168a17ca56fb": {
			"balance": "100000000000000000000"
		},
		"a1998144968a5c70a6415554cefec2824690c4a5": {
			"balance": "20000000000000000000"
)E" + R"E(
		},
		"e9559185f166fc9513cc71116144ce2deb0f1d4b": {
			"balance": "20000000000000000000000"
		},
		"ed5b4c41e762d942404373caf21ed4615d25e6c1": {
			"balance": "2013960000000000000000"
		},
		"665b000f0b772750cc3c217a5ef429a92bf1ccbb": {
			"balance": "4000000000000000000000"
		},
		"febd9f81cf78bd5fb6c4b9a24bd414bb9bfa4c4e": {
			"balance": "1990019000000000000000"
		},
		"a072691c8dd7cd4237ff72a75c1a9506d0ce5b9e": {
			"balance": "370000000000000000000"
		},
		"6765df25280e8e4f38d4b1cf446fc5d7eb659e34": {
			"balance": "100000000000000000000"
		},
		"524fb210522c5e23bb67dfbf8c26aa616da49955": {
			"balance": "999971000000000000000"
		},
		"e987e6139e6146a717fef96bc24934a5447fe05d": {
			"balance": "2000000000000000000000"
		},
		"d6110276cfe31e42825a577f6b435dbcc10cf764": {
			"balance": "1000000000000000000000"
		},
		"5e51b8a3bb09d303ea7c86051582fd600fb3dc1a": {
			"balance": "20000000000000000000"
		},
		"5c4f24e994ed8f850ea7818f471c8fac3bcf0452": {
			"balance": "1724800000000000000000"
		},
		"85b2998d0c73302cb2ba13f489313301e053be15": {
			"balance": "10000000000000000000000"
		},
		"0af6c8d539c96d50259e1ba6719e9c8060f388c2": {
			"balance": "1000000000000000000000"
		},
		"7d901b28bf7f88ef73d8f73cca97564913ea8a24": {
			"balance": "955000000000000000000"
		},
		"e01859f242f1a0ec602fa8a3b0b57640ec89075e": {
			"balance": "555000000000000000000"
		},
		"c66ae4cee87fb3353219f77f1d6486c580280332": {
			"balance": "29550000000000000000"
		},
		"2d40558b06f90a3923145592123b6774e46e31f4": {
			"balance": "1000000000000000000000"
		},
		"ccf43975b76bfe735fec3cb7d4dd24f805ba0962": {
			"balance": "60000000000000000000"
		},
		"1703b4b292b8a9deddede81bb25d89179f6446b6": {
			"balance": "19690000000000000000000"
		},
		"0e9096d343c060db581a120112b278607ec6e52b": {
			"balance": "20000000000000000000"
		},
		"f65819ac4cc14c137f05dd7977c7dae08d1a4ab5": {
			"balance": "102000000000000000000"
		},
		"ca373fe3c906b8c6559ee49ccd07f37cd4fb5266": {
			"balance": "1790000000000000000000"
		},
		"d28298524df5ec4b24b0ffb9df85170a145a9eb5": {
			"balance": "287700000000000000000"
		},
		"5fcda847aaf8d7fa8bca08029ca2849166aa15a3": {
			"balance": "623350000000000000000"
		},
		"bdc739a699700b2e8e2c4a4c7b058a0e513ddebe": {
			"balance": "2000000000000000000000"
		},
		"0bb05f7224bb5804856556c07eeadbed87ba8f7c": {
			"balance": "401100000000000000000"
		},
		"ab416fe30d58afe5d9454c7fce7f830bcc750356": {
			"balance": "114515000000000000000"
		},
		"3eee6f1e96360b7689b3069adaf9af8eb60ce481": {
			"balance": "1000000000000000000000"
		},
		"9a0d3cee3d9892ea3b3700a27ff84140d9025493": {
			"balance": "60000000000000000000"
		},
		"5dc36de5359450a1ec09cb0c44cf2bb42b3ae435": {
			"balance": "1117500000000000000000"
		},
		"35c8adc11125432b3b77acd64625fe58ebee9d66": {
			"balance": "2000000000000000000000"
		},
		"a5e9cd4b74255d22b7d9b27ae8dd43ed6ed0252b": {
			"balance": "766527000000000000000"
		},
		"31ea12d49a35a740780ddeeaece84c0835b26270": {
			"balance": "200000000000000000000"
		},
)E" + R"E(
		"7aef7b551f0b9c46e755c0f38e5b3a73fe1199f5": {
			"balance": "1490000000000000000000"
		},
		"cc6d7b12061bc96d104d606d65ffa32b0036eb07": {
			"balance": "10000000000000000000000"
		},
		"322021022678a0166d204b3aaa7ad4ec4b88b7d0": {
			"balance": "400000000000000000000"
		},
		"b31196714a48dff726ea9433cd2912f1a414b3b3": {
			"balance": "2680000000000000000000"
		},
		"0f2fb884c8aaff6f543ac6228bd08e4f60b0a5fd": {
			"balance": "3145000000000000000000"
		},
		"7d9d221a3df89ddd7b5f61c1468c6787d6b333e6": {
			"balance": "138000000000000000000"
		},
		"367f59cc82795329384e41e1283115e791f26a01": {
			"balance": "2000000000000000000000"
		},
		"fd9579f119bbc819a02b61e38d8803c942f24d32": {
			"balance": "105600000000000000000"
		},
		"3e2f26235e137a7324e4dc154b5df5af46ea1a49": {
			"balance": "22458000000000000000"
		},
		"4c1579af3312e4f88ae93c68e9449c2e9a68d9c4": {
			"balance": "2000000000000000000000"
		},
		"ffb04726dfa41afdc819168418610472970d7bfc": {
			"balance": "4000000000000000000000"
		},
		"403c64896a75cad816a9105e18d8aa5bf80f238e": {
			"balance": "985000000000000000000"
		},
		"5cd588a14ec648ccf64729f9167aa7bf8be6eb3d": {
			"balance": "1000000000000000000000"
		},
		"24b2be118b16d8b2174769d17b4cf84f07ca946d": {
			"balance": "2000000000000000000000"
		},
		"d3bb59fa31258be62f8ed232f1a7d47b4a0b41ee": {
			"balance": "100000000000000000000"
		},
		"cc9ac715cd6f2610c52b58676456884297018b29": {
			"balance": "13370000000000000000"
		},
		"6f2a31900e240395b19f159c1d00dfe4d898ebdf": {
			"balance": "1999600000000000000000"
		},
		"d60b247321a32a5affb96b1e279927cc584de943": {
			"balance": "2265500000000000000000"
		},
		"f7a1ade2d0f529123d1055f19b17919f56214e67": {
			"balance": "500000000000000000000"
		},
		"bea00df17067a43a82bc1daecafb6c14300e89e6": {
			"balance": "1820000000000000000000"
		},
		"a2968fc1c64bac0b7ae0d68ba949874d6db253f4": {
			"balance": "20000000000000000000000"
		},
		"92d8ad9a4d61683b80d4a6672e84c20d62421e80": {
			"balance": "20000000000000000000"
		},
		"6ed2a12b02f8c688c7b5d3a6ea14d63687dab3b6": {
			"balance": "2000000000000000000000"
		},
		"7a63869fc767a4c6b1cd0e0649f3634cb121d24b": {
			"balance": "77500000000000000000"
		},
		"84f522f0520eba52dd18ad21fa4b829f2b89cb97": {
			"balance": "4949566000000000000000"
		},
		"d6234aaf45c6f22e66a225ffb93add629b4ef80f": {
			"balance": "1000000000000000000000"
		},
		"e3d8bf4efe84b1616d1b89e427ddc6c8830685ae": {
			"balance": "2000000000000000000000"
		},
		"a3db364a332d884ba93b2617ae4d85a1489bea47": {
			"balance": "1700000000000000000000"
		},
		"9f7986924aeb02687cd64189189fb167ded2dd5c": {
			"balance": "985000000000000000000"
		},
		"2eaf4e2a46b789ccc288c8d1d9294e3fb0853896": {
			"balance": "2000000000000000000000"
		},
		"a02dc6aa328b880de99eac546823fccf774047fb": {
			"balance": "1970000000000000000000"
		},
		"873b7f786d3c99ff012c4a7cae2677270240b9c5": {
			"balance": "1730000000000000000000"
		},
		"1d69c83d28ff0474ceebeacb3ad227a144ece7a3": {
			"balance": "5474937000000000000000"
		},
		"7b827cae7ff4740918f2e030ab26cb98c4f46cf5": {
)E" + R"E(
			"balance": "7460000000000000000000"
		},
		"3083ef0ed4c4401196774a95cf4edc83edc1484f": {
			"balance": "170000000000000000000000"
		},
		"40ad74bc0bce2a45e52f36c3debb1b3ada1b7619": {
			"balance": "6790000000000000000000"
		},
		"05423a54c8d0f9707e704173d923b946edc8e700": {
			"balance": "127543000000000000000"
		},
		"22eb7db0ba56b0f8b816ccb206e615d929185b0d": {
			"balance": "80500000000000000000"
		},
		"66082c75a8de31a53913bbd44de3a0374f7faa41": {
			"balance": "1460000000000000000000"
		},
		"e3d3eaa299887865569e88be219be507189be1c9": {
			"balance": "456156000000000000000"
		},
		"ae57cc129a96a89981dac60d2ffb877d5dc5e432": {
			"balance": "1110994000000000000000"
		},
		"1a2434cc774422d48d53d59c5d562cce8407c94b": {
			"balance": "30000000000000000000"
		},
		"21546914dfd3af2add41b0ff3e83ffda7414e1e0": {
			"balance": "5969100000000000000000"
		},
		"4dcf62a3de3f061db91498fd61060f1f6398ff73": {
			"balance": "1999944000000000000000"
		},
		"6fd98e563d12ce0fd60f4f1f850ae396a9823c02": {
			"balance": "1261000000000000000000"
		},
		"edf8a3e1d40f13b79ec8e3e1ecf262fd92116263": {
			"balance": "158000000000000000000"
		},
		"c09e3cfc19f605ff3ec9c9c70e2540d7ee974366": {
			"balance": "500000000000000000000"
		},
		"953572f0ea6df9b197cae40e4b8ecc056c4371c5": {
			"balance": "1000000000000000000000"
		},
		"163cc8be227646cb09719159f28ed09c5dc0dce0": {
			"balance": "1337000000000000000000"
		},
		"a3932a31d6ff75fb3b1271ace7caa7d5e1ff1051": {
			"balance": "20000000000000000000000"
		},
		"f9a94bd56198da245ed01d1e6430b24b2708dcc0": {
			"balance": "749938000000000000000"
		},
		"3eb8b33b21d23cda86d8288884ab470e164691b5": {
			"balance": "500000000000000000000"
		},
		"84bcbf22c09607ac84341d2edbc03bfb1739d744": {
			"balance": "500000000000000000000"
		},
		"961c59adc74505d1864d1ecfcb8afa0412593c93": {
			"balance": "40000000000000000000000"
		},
		"f068dfe95d15cd3a7f98ffa688b4346842be2690": {
			"balance": "1255160000000000000000"
		},
		"291efe0081dce8c14799f7b2a43619c0c3b3fc1f": {
			"balance": "1200000000000000000000"
		},
		"be4fd073617022b67f5c13499b827f763639e4e3": {
			"balance": "2000000000000000000000"
		},
		"e40a7c82e157540a0b00901dbb86c716e1a062da": {
			"balance": "49800000000000000000"
		},
		"6635b46f711d2da6f0e16370cd8ee43efb2c2d52": {
			"balance": "2000000000000000000000"
		},
		"43748928e8c3ec4436a1d092fbe43ac749be1251": {
			"balance": "400000000000000000000"
		},
		"b557ab9439ef50d237b553f02508364a466a5c03": {
			"balance": "200000000000000000000"
		},
		"11928378d27d55c520ceedf24ceb1e822d890df0": {
			"balance": "8000000000000000000000"
		},
		"61518464fdd8b73c1bb6ac6db600654938dbf17a": {
			"balance": "200000000000000000000"
		},
		"004bfbe1546bc6c65b5c7eaa55304b38bbfec6d3": {
			"balance": "2000000000000000000000"
		},
		"a5e0fc3c3affed3db6710947d1d6fb017f3e276d": {
			"balance": "2000000000000000000000"
		},
		"8ecbcfacbfafe9f00c3922a24e2cf0026756ca20": {
			"balance": "5640000000000000000000"
		},
		"fb5ffaa0f7615726357891475818939d2037cf96": {
			"balance": "20000000000000000000"
)E" + R"E(
		},
		"ae222865799079aaf4f0674a0cdaab02a6d570ff": {
			"balance": "2000000000000000000000"
		},
		"9edc90f4be210865214ab5b35e5a8dd77415279d": {
			"balance": "4000000000000000000000"
		},
		"9d7831e834c20b1baa697af1d8e0c621c5afff9a": {
			"balance": "86500000000000000000"
		},
		"046d274b1af615fb505a764ad8dda770b1db2f3d": {
			"balance": "2000000000000000000000"
		},
		"eaea23aa057200e7c9c15e8ff190d0e66c0c0e83": {
			"balance": "2000000000000000000000"
		},
		"417a3cd19496530a6d4204c3b5a17ce0f207b1a5": {
			"balance": "8000000000000000000000"
		},
		"a035a3652478f82dbd6d115faa8ca946ec9e681d": {
			"balance": "109880000000000000000"
		},
		"4f5801b1eb30b712d8a0575a9a71ff965d4f34eb": {
			"balance": "300000000000000000000"
		},
		"91dbb6aaad149585be47375c5d6de5ff09191518": {
			"balance": "20000000000000000000000"
		},
		"d043a011ec4270ee7ec8b968737515e503f83028": {
			"balance": "500000000000000000000"
		},
		"bb371c72c9f0316cea2bd9c6fbb4079e775429ef": {
			"balance": "1760000000000000000000"
		},
		"aa1df92e51dff70b1973e0e924c66287b494a178": {
			"balance": "534400000000000000000"
		},
		"bd5f46caab2c3d4b289396bbb07f203c4da82530": {
			"balance": "80000000000000000000"
		},
		"4d29fc523a2c1629532121da9998e9b5ab9d1b45": {
			"balance": "15800000000000000000"
		},
		"addb26317227f45c87a2cb90dc4cfd02fb23caf8": {
			"balance": "1000000000000000000000"
		},
		"52e46783329a769301b175009d346768f4c87ee4": {
			"balance": "2000000000000000000000"
		},
		"caad9dc20d589ce428d8fda3a9d53a607b7988b5": {
			"balance": "4000000000000000000000"
		},
		"95034e1621865137cd4739b346dc17da3a27c34e": {
			"balance": "1580000000000000000000"
		},
		"0c3239e2e841242db989a61518c22247e8c55208": {
			"balance": "263656000000000000000"
		},
		"5a0d609aae2332b137ab3b2f26615a808f37e433": {
			"balance": "160000000000000000000000"
		},
		"2334c590c7a48769103045c5b6534c8a3469f44a": {
			"balance": "17443200000000000000000"
		},
		"ddfcca13f934f0cfbe231da13039d70475e6a1d0": {
			"balance": "1000169000000000000000"
		},
		"ee7288d91086d9e2eb910014d9ab90a02d78c2a0": {
			"balance": "2000000000000000000000"
		},
		"fb91fb1a695553f0c68e21276decf0b83909b86d": {
			"balance": "100016000000000000000"
		},
		"38695fc7e1367ceb163ebb053751f9f68ddb07a0": {
			"balance": "2000000000000000000000"
		},
		"65093b239bbfba23c7775ca7da5a8648a9f54cf7": {
			"balance": "400000000000000000000"
		},
		"73d8fee3cb864dce22bb26ca9c2f086d5e95e63b": {
			"balance": "1000000000000000000000"
		},
		"f7155213449892744bc60f2e04400788bd041fdd": {
			"balance": "66850000000000000000"
		},
		"d1a71b2d0858e83270085d95a3b1549650035e23": {
			"balance": "14900000000000000000000"
		},
		"eac17b81ed5191fb0802aa54337313834107aaa4": {
			"balance": "8000000000000000000000"
		},
		"bb076aac92208069ea318a31ff8eeb14b7e996e3": {
			"balance": "149000000000000000000"
		},
		"9f46e7c1e9078cae86305ac7060b01467d6685ee": {
			"balance": "668500000000000000000"
		},
		"1598127982f2f8ad3b6b8fc3cf27bf617801ba2b": {
			"balance": "173000000000000000000"
		},
)E" + R"E(
		"e91dac0195b19e37b59b53f7c017c0b2395ba44c": {
			"balance": "1880000000000000000000"
		},
		"a436c75453ccca4a1f1b62e5c4a30d86dde4be68": {
			"balance": "2000000000000000000000"
		},
		"11001b89ed873e3aaec1155634b4681643986323": {
			"balance": "1000000000000000000000"
		},
		"ab93b26ece0a0aa21365afed1fa9aea31cd54468": {
			"balance": "1608000000000000000000"
		},
		"e77febabdf080f0f5dca1d3f5766f2a79c0ffa7c": {
			"balance": "1386000000000000000000"
		},
		"1c4af0e863d2656c8635bc6ffec8dd9928908cb5": {
			"balance": "2000000000000000000000"
		},
		"0c48ae62d1539788eba013d75ea60b64eeba4e80": {
			"balance": "2213311000000000000000"
		},
		"423cc4594cf4abb6368de59fd2b1230734612143": {
			"balance": "2000000000000000000000"
		},
		"7f6b28c88421e4857e459281d78461692489d3fb": {
			"balance": "2000000000000000000000"
		},
		"806854588ecce541495f81c28a290373df0274b2": {
			"balance": "582000000000000000000"
		},
		"dc76e85ba50b9b31ec1e2620bce6e7c8058c0eaf": {
			"balance": "20000000000000000000"
		},
		"b00996b0566ecb3e7243b8227988dcb352c21899": {
			"balance": "12000000000000000000000"
		},
		"f5d14552b1dce0d6dc1f320da6ffc8a331cd6f0c": {
			"balance": "1337000000000000000000"
		},
		"55a61b109480b5b2c4fcfdef92d90584160c0d35": {
			"balance": "44700000000000000000"
		},
		"b8947822d5ace7a6ad8326e95496221e0be6b73d": {
			"balance": "20000000000000000000"
		},
		"492de46aaf8f1d708d59d79af1d03ad2cb60902f": {
			"balance": "2000000000000000000000"
		},
		"0e0d6633db1e0c7f234a6df163a10e0ab39c200f": {
			"balance": "200000000000000000000"
		},
		"f8bf9c04874e5a77f38f4c38527e80c676f7b887": {
			"balance": "2000000000000000000000"
		},
		"15528350e0d9670a2ea27f7b4a33b9c0f9621d21": {
			"balance": "4000086000000000000000"
		},
		"eccf7a0457b566b346ca673a180f444130216ac3": {
			"balance": "100000000000000000000"
		},
		"10cf560964ff83c1c9674c783c0f73fcd89943fc": {
			"balance": "40000000000000000000000"
		},
		"e7f06f699be31c440b43b4db0501ec0e25261644": {
			"balance": "500000000000000000000"
		},
		"b6ce4dc560fc73dc69fb7a62e388db7e72ea764f": {
			"balance": "966000000000000000000"
		},
		"f456055a11ab91ff668e2ec922961f2a23e3db25": {
			"balance": "18200000000000000000"
		},
		"8dfbafbc0e5b5c86cd1ad697feea04f43188de96": {
			"balance": "390060000000000000000"
		},
		"085b4ab75d8362d914435cedee1daa2b1ee1a23b": {
			"balance": "3880000000000000000000"
		},
		"e400d651bb3f2d23d5f849e6f92d9c5795c43a8a": {
			"balance": "2674000000000000000000"
		},
		"851aa91c82f42fad5dd8e8bb5ea69c8f3a5977d1": {
			"balance": "148607000000000000000"
		},
		"4c935bb250778b3c4c7f7e07fc251fa630314aab": {
			"balance": "1500000000000000000000"
		},
		"ebd356156a383123343d48843bffed6103e866b3": {
			"balance": "1970000000000000000000"
		},
		"da0b48e489d302b4b7bf204f957c1c9be383b0df": {
			"balance": "2000000000000000000000"
		},
		"7085ae7e7e4d932197b5c7858c00a3674626b7a5": {
			"balance": "6000000000000000000000"
		},
		"5b06d1e6930c1054692b79e3dbe6ecce53966420": {
			"balance": "205400000000000000000"
		},
		"8df53d96191471e059de51c718b983e4a51d2afd": {
)E" + R"E(
			"balance": "32000000000000000000000"
		},
		"0678654ac6761db904a2f7e8595ec1eaac734308": {
			"balance": "878000000000000000000"
		},
		"89fee30d1728d96cecc1dab3da2e771afbcfaa41": {
			"balance": "1999944000000000000000"
		},
		"59c5d06b170ee4d26eb0a0eb46cb7d90c1c91019": {
			"balance": "10000000000000000000000"
		},
		"2b129c26b75dde127f8320bd0f63410c92a9f876": {
			"balance": "2200000000000000000000"
		},
		"3d6ae053fcbc318d6fd0fbc353b8bf542e680d27": {
			"balance": "14300000000000000000"
		},
		"755a60bf522fbd8fff9723446b7e343a7068567e": {
			"balance": "20000000000000000000000"
		},
		"947e11e5ea290d6fc3b38048979e0cd44ec7c17f": {
			"balance": "2000000000000000000000"
		},
		"711ecf77d71b3d0ea95ce4758afecdb9c131079d": {
			"balance": "760000000000000000000"
		},
		"de9eff4c798811d968dccb460d9b069cf30278e0": {
			"balance": "400000000000000000000"
		},
		"4e892e8081bf36e488fddb3b2630f3f1e8da30d2": {
			"balance": "12003800000000000000000"
		},
		"8ede7e3dc50749c6c50e2e28168478c34db81946": {
			"balance": "19999800000000000000000"
		},
		"0c30cacc3f72269f8b4f04cf073d2b05a83d9ad1": {
			"balance": "2001000000000000000000"
		},
		"e51eb87e7fb7311f5228c479b48ec9878831ac4c": {
			"balance": "2000000000000000000000"
		},
		"8b01da34d470c1d115acf4d8113c4dd8a8c338e4": {
			"balance": "25220000000000000000000"
		},
		"4329fc0931cbeb033880fe4c9398ca45b0e2d11a": {
			"balance": "2000400000000000000000"
		},
		"540c072802014ef0d561345aec481e8e11cb3570": {
			"balance": "8000000000000000000000"
		},
		"21e5d2bae995ccfd08a5c16bb524e1f630448f82": {
			"balance": "2800000000000000000000"
		},
		"5cf8c03eb3e872e50f7cfd0c2f8d3b3f2cb5183a": {
			"balance": "200000000000000000000"
		},
		"5c0f2e51378f6b0d7bab617331580b6e39ad3ca5": {
			"balance": "9600000000000000000000"
		},
		"d2f241255dd7c3f73c07043071ec08ddd9c5cde5": {
			"balance": "500000000000000000000"
		},
		"cbe1b948864d8474e765145858fca4550f784b92": {
			"balance": "10000000000000000000000"
		},
		"30742ccdf4abbcd005681f8159345c9e79054b1a": {
			"balance": "668500000000000000000"
		},
		"6aeb9f74742ea491813dbbf0d6fcde1a131d4db3": {
			"balance": "440800000000000000000"
		},
		"821eb90994a2fbf94bdc3233910296f76f9bf6e7": {
			"balance": "10000000000000000000000"
		},
		"25c1a37ee5f08265a1e10d3d90d5472955f97806": {
			"balance": "1820000000000000000000"
		},
		"7ef98b52bee953bef992f305fda027f8911c5851": {
			"balance": "514717000000000000000"
		},
		"8adc53ef8c18ed3051785d88e996f3e4b20ecd51": {
			"balance": "42000000000000000000000"
		},
		"007f4a23ca00cd043d25c2888c1aa5688f81a344": {
			"balance": "773658000000000000000"
		},
		"4a735d224792376d331367c093d31c8794341582": {
			"balance": "1900000000000000000000"
		},
		"05440c5b073b529b4829209dff88090e07c4f6f5": {
			"balance": "1288000000000000000000"
		},
		"5e772e27f28800c50dda973bb33e10762e6eea20": {
			"balance": "1790000000000000000000"
		},
		"a429fa88731fdd350e8ecd6ea54296b6484fe695": {
			"balance": "1969606000000000000000"
		},
		"e0d76b7166b1f3a12b4091ee2b29de8caa7d07db": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"7ebd95e9c470f7283583dc6e9d2c4dce0bea8f84": {
			"balance": "14000000000000000000000"
		},
		"883a78aeabaa50d8ddd8570bcd34265f14b19363": {
			"balance": "3879951000000000000000"
		},
		"51f9c432a4e59ac86282d6adab4c2eb8919160eb": {
			"balance": "530000000000000000000000"
		},
		"b86607021b62d340cf2652f3f95fd2dc67698bdf": {
			"balance": "5000000000000000000000"
		},
		"acc0909fda2ea6b7b7a88db7a0aac868091ddbf6": {
			"balance": "22155000000000000000"
		},
		"69b80ed90f84834afa3ff82eb964703b560977d6": {
			"balance": "26740000000000000000"
		},
		"ca4ca9e4779d530ecbacd47e6a8058cfde65d98f": {
			"balance": "800000000000000000000"
		},
		"5d6c5c720d66a6abca8397142e63d26818eaab54": {
			"balance": "40000000000000000000"
		},
		"c2c13e72d268e7150dc799e7c6cf03c88954ced7": {
			"balance": "700000000000000000000"
		},
		"6bbd1e719390e6b91043f8b6b9df898ea8001b34": {
			"balance": "2000053000000000000000"
		},
		"a9ba6f413b82fcddf3affbbdd09287dcf50415ca": {
			"balance": "4000000000000000000000"
		},
		"ced3c7be8de7585140952aeb501dc1f876ecafb0": {
			"balance": "4000000000000000000000"
		},
		"1c63fa9e2cbbf23c49fcdef1cbabfe6e0d1e14c1": {
			"balance": "1000000000000000000000"
		},
		"7d6e990daa7105de2526339833f77b5c0b85d84f": {
			"balance": "20000000000000000000000"
		},
		"68addf019d6b9cab70acb13f0b3117999f062e12": {
			"balance": "49941000000000000000"
		},
		"a77428bcb2a0db76fc8ef1e20e461a0a32c5ac15": {
			"balance": "401100000000000000000"
		},
		"26048fe84d9b010a62e731627e49bc2eb73f408f": {
			"balance": "4000000000000000000000"
		},
		"ff26138330274df4e0a3081e6df7dd983ec6e78f": {
			"balance": "2000000000000000000000"
		},
		"b7382d37db0398ac72410cf9813de9f8e1ec8dad": {
			"balance": "1000070000000000000000"
		},
		"44f62f2aaabc29ad3a6b04e1ff6f9ce452d1c140": {
			"balance": "17000000000000000000000"
		},
		"47fef58584465248a0810d60463ee93e5a6ee8d3": {
			"balance": "283100000000000000000"
		},
		"bd2b70fecc37640f69514fc7f3404946aad86b11": {
			"balance": "1200000000000000000000"
		},
		"649a85b93653075fa6562c409a565d087ba3e1ba": {
			"balance": "2000000000000000000000"
		},
		"55866486ec168f79dbe0e1abb18864d98991ae2c": {
			"balance": "16100000000000000000"
		},
		"d7e74afdbad55e96cebc5a374f2c8b768680f2b0": {
			"balance": "99000000000000000000"
		},
		"a8c1d6aa41fe3d65f67bd01de2a866ed1ed9ae52": {
			"balance": "30000000000000000000"
		},
		"744c0c77ba7f236920d1e434de5da33e48ebf02c": {
			"balance": "1970000000000000000000"
		},
		"9445ba5c30e98961b8602461d0385d40fbd80311": {
			"balance": "10000000000000000000000"
		},
		"eb835c1a911817878a33d167569ea3cdd387f328": {
			"balance": "1000000000000000000000"
		},
		"761a6e362c97fbbd7c5977acba2da74687365f49": {
			"balance": "183840000000000000000"
		},
		"38202c5cd7078d4f887673ab07109ad8ada89720": {
			"balance": "1000000000000000000000"
		},
		"5abfec25f74cd88437631a7731906932776356f9": {
			"balance": "11901484239480000000000000"
		},
		"28e4af30cd93f686a122ad7bb19f8a8785eee342": {
			"balance": "2101000000000000000000"
		},
)E" + R"E(
		"3a9b111029ce1f20c9109c7a74eeeef34f4f2eb2": {
			"balance": "4000000000000000000000"
		},
		"7bb9571f394b0b1a8eba5664e9d8b5e840677bea": {
			"balance": "19700000000000000000"
		},
		"50fb36c27107ee2ca9a3236e2746cca19ace6b49": {
			"balance": "2000000000000000000000"
		},
		"a3bc979b7080092fa1f92f6e0fb347e28d995045": {
			"balance": "2800000000000000000000"
		},
		"d04b861b3d9acc563a901689941ab1e1861161a2": {
			"balance": "20000000000000000000"
		},
		"58c555bc293cdb16c6362ed97ae9550b92ea180e": {
			"balance": "20000000000000000000"
		},
		"8bf02bd748690e1fd1c76d270833048b66b25fd3": {
			"balance": "11800000000000000000000"
		},
		"fbc01db54e47cdc3c438694ab717a856c23fe6e9": {
			"balance": "8456774000000000000000"
		},
		"9c9a07a8e57c3172a919ef64789474490f0d9f51": {
			"balance": "10000000000000000000000"
		},
		"fc7e22a503ec5abe9b08c50bd14999f520fa4884": {
			"balance": "6387725000000000000000"
		},
		"9b773669e87d76018c090f8255e54409b9dca8b2": {
			"balance": "20000000000000000000"
		},
		"ffe8cbc1681e5e9db74a0f93f8ed25897519120f": {
			"balance": "1507000000000000000000"
		},
		"4d4cf5807429615e30cdface1e5aae4dad3055e6": {
			"balance": "600000000000000000000"
		},
		"cfde0fc75d6f16c443c3038217372d99f5d907f7": {
			"balance": "2419000000000000000000"
		},
		"818ffe271fc3973565c303f213f6d2da89897ebd": {
			"balance": "5734655000000000000000"
		},
		"ba1fcaf223937ef89e85675503bdb7ca6a928b78": {
			"balance": "640000000000000000000"
		},
		"a30a45520e5206d9004070e6af3e7bb2e8dd5313": {
			"balance": "400000000000000000000"
		},
		"a747439ad0d393b5a03861d77296326de8bb9db9": {
			"balance": "1000000000000000000000"
		},
		"14d00aad39a0a7d19ca05350f7b03727f08dd82e": {
			"balance": "500000000000000000000"
		},
		"551999ddd205563327b9b530785acff9bc73a4ba": {
			"balance": "6000000000000000000000"
		},
		"a4670731175893bbcff4fa85ce97d94fc51c4ba8": {
			"balance": "8000000000000000000000"
		},
		"f858171a04d357a13b4941c16e7e55ddd4941329": {
			"balance": "41984000000000000000"
		},
		"a6484cc684c4c91db53eb68a4da45a6a6bda3067": {
			"balance": "6000000000000000000000"
		},
		"00d75ed60c774f8b3a5a5173fb1833ad7105a2d9": {
			"balance": "2005500000000000000000"
		},
		"bf92418a0c6c31244d220260cb3e867dd7b4ef49": {
			"balance": "99800000000000000000"
		},
		"716d50cca01e938500e6421cc070c3507c67d387": {
			"balance": "2000000000000000000000"
		},
		"82a8b96b6c9e13ebec1e9f18ac02a60ea88a48ff": {
			"balance": "1999998000000000000000"
		},
		"5a565285374a49eedd504c957d510874d00455bc": {
			"balance": "100000000000000000000"
		},
		"778c79f4de1953ebce98fe8006d53a81fb514012": {
			"balance": "999800000000000000000"
		},
		"41b2d34fde0b1029262b4172c81c1590405b03ae": {
			"balance": "1000000000000000000000"
		},
		"4039bd50a2bde15ffe37191f410390962a2b8886": {
			"balance": "200000000000000000000"
		},
		"c033be10cb48613bd5ebcb33ed4902f38b583003": {
			"balance": "3000000000000000000000"
		},
		"5d5751819b4f3d26ed0c1ac571552735271dbefa": {
			"balance": "1000000000000000000000"
		},
		"b600429752f399c80d0734744bae0a022eca67c6": {
)E" + R"E(
			"balance": "20000000000000000000"
		},
		"f875619d8a23e45d8998d184d480c0748970822a": {
			"balance": "4000000000000000000000"
		},
		"71c7230a1d35bdd6819ed4b9a88e94a0eb0786dd": {
			"balance": "4365000000000000000000"
		},
		"b2f9c972c1e9737755b3ff1b3088738396395b26": {
			"balance": "20000000000000000000000"
		},
		"a66a4963b27f1ee1932b172be5964e0d3ae54b51": {
			"balance": "173000000000000000000"
		},
		"53ce88e66c5af2f29bbd8f592a56a3d15f206c32": {
			"balance": "140840000000000000000"
		},
		"433e3ba1c51b810fc467d5ba4dea42f7a9885e69": {
			"balance": "40000000000000000000000"
		},
		"c7837ad0a0bf14186937ace06c5546a36aa54f46": {
			"balance": "4000000000000000000000"
		},
		"c3f8f67295a5cd049364d05d23502623a3e52e84": {
			"balance": "6000000000000000000000"
		},
		"3fd0bb47798cf44cdfbe4d333de637df4a00e45c": {
			"balance": "100040000000000000000"
		},
		"a1ae8d4540d4db6fdde7146f415b431eb55c7983": {
			"balance": "197000000000000000000"
		},
		"5cccf1508bfd35c20530aa642500c10dee65eaed": {
			"balance": "850000000000000000000"
		},
		"a53ead54f7850af21438cbe07af686279a315b86": {
			"balance": "10000000000000000000000"
		},
		"8cf6da0204dbc4860b46ad973fc111008d9e0c46": {
			"balance": "200000000000000000000"
		},
		"8e7936d592008fdc7aa04edeeb755ab513dbb89d": {
			"balance": "20000000000000000000"
		},
		"4a53dcdb56ce4cdce9f82ec0eb13d67352e7c88b": {
			"balance": "4200000000000000000000"
		},
		"2b4f4507bb6b9817942ce433781b708fbcd166fd": {
			"balance": "18200000000000000000"
		},
		"026432af37dc5113f1f46d480a4de0b28052237e": {
			"balance": "355800000000000000000"
		},
		"e780a56306ba1e6bb331952c22539b858af9f77d": {
			"balance": "50000000000000000000000"
		},
		"d1f1694d22671b5aad6a94995c369fbe6133676f": {
			"balance": "1000000000000000000000"
		},
		"7c45f0f8442a56dbd39dbf159995415c52ed479b": {
			"balance": "2000000000000000000000"
		},
		"b65941d44c50d24666670d364766e991c02e11c2": {
			"balance": "600000000000000000000"
		},
		"45e68db8dbbaba5fc2cb337c62bcd0d61b059189": {
			"balance": "2000000000000000000000"
		},
		"05f3631f5664bdad5d0132c8388d36d7d8920918": {
			"balance": "20000000000000000000"
		},
		"5475d7f174bdb1f789017c7c1705989646079d49": {
			"balance": "9400000000000000000000"
		},
		"c7bf2ed1ed312940ee6aded1516e268e4a604856": {
			"balance": "6000000000000000000000"
		},
		"39aaf0854db6eb39bc7b2e43846a76171c0445de": {
			"balance": "1850000000000000000000"
		},
		"c817df1b91faf30fe3251571727c9711b45d8f06": {
			"balance": "1999944000000000000000"
		},
		"7d13d6705884ab2157dd8dcc7046caf58ee94be4": {
			"balance": "137200000000000000000000"
		},
		"478dc09a1311377c093f9cc8ae74111f65f82f39": {
			"balance": "4000000000000000000000"
		},
		"8043ed22f997e5a2a4c16e364486ae64975692c4": {
			"balance": "1130513000000000000000"
		},
		"b9a985501ee950829b17fae1c9cf348c3156542c": {
			"balance": "294100000000000000000"
		},
		"d5cba5b26bea5d73fabb1abafacdef85def368cc": {
			"balance": "200000000000000000000"
		},
		"6776e133d9dc354c12a951087b639650f539a433": {
			"balance": "120000000000000000000"
)E" + R"E(
		},
		"804ca94972634f633a51f3560b1d06c0b293b3b1": {
			"balance": "200000000000000000000"
		},
		"0be1fdf626ee6189102d70d13b31012c95cd1cd6": {
			"balance": "2000000000000000000000"
		},
		"f848fce9ab611c7d99206e23fac69ad488b94fe1": {
			"balance": "48500000000000000000"
		},
		"f01195d657ef3c942e6cb83949e5a20b5cfa8b1e": {
			"balance": "25760000000000000000000"
		},
		"78a5e89900bd3f81dd71ba869d25fec65261df15": {
			"balance": "51900000000000000000000"
		},
		"d6f1e55b1694089ebcb4fe7d7882aa66c8976176": {
			"balance": "19998846000000000000000"
		},
		"d5294b666242303b6df0b1c88d37429bc8c965aa": {
			"balance": "300700000000000000000"
		},
		"3171877e9d820cc618fc0919b29efd333fda4934": {
			"balance": "1000000000000000000000"
		},
		"2901f8077f34190bb47a8e227fa29b30ce113b31": {
			"balance": "100000000000000000000"
		},
		"6b2284440221ce16a8382de5ff0229472269deec": {
			"balance": "1000000000000000000000"
		},
		"1bba03ff6b4ad5bf18184acb21b188a399e9eb4a": {
			"balance": "1790000000000000000000"
		},
		"80744618de396a543197ee4894abd06398dd7c27": {
			"balance": "2000000000000000000000"
		},
		"1b799033ef6dc7127822f74542bb22dbfc09a308": {
			"balance": "100000000000000000000"
		},
		"d513a45080ff2febe62cd5854abe29ee4467f996": {
			"balance": "153200000000000000000"
		},
		"e761d27fa3502cc76bb1a608740e1403cf9dfc69": {
			"balance": "280000000000000000000"
		},
		"53989ed330563fd57dfec9bd343c3760b0799390": {
			"balance": "6208000000000000000000"
		},
		"ccf7110d1bd9a74bfd1d7d7d2d9d55607e7b837d": {
			"balance": "900000000000000000000"
		},
		"f373e9daac0c8675f53b797a160f6fc034ae6b23": {
			"balance": "100000000000000000000"
		},
		"abc9a99e8a2148a55a6d82bd51b98eb5391fdbaf": {
			"balance": "6000000000000000000000"
		},
		"ffec0913c635baca2f5e57a37aa9fb7b6c9b6e26": {
			"balance": "805000000000000000000"
		},
		"581a3af297efa4436a29af0072929abf9826f58b": {
			"balance": "2000000000000000000000"
		},
		"924efa6db595b79313277e88319625076b580a10": {
			"balance": "2000000000000000000000"
		},
		"65d8dd4e251cbc021f05b010f2d5dc520c3872e0": {
			"balance": "834956000000000000000"
		},
		"6c67d6db1d03516c128b8ff234bf3d49b26d2941": {
			"balance": "100000000000000000000000"
		},
		"496d365534530a5fc1577c0a5241cb88c4da7072": {
			"balance": "1790000000000000000000"
		},
		"b85ff03e7b5fc422981fae5e9941dacbdaba7584": {
			"balance": "1337000000000000000000"
		},
		"e13540ecee11b212e8b775dc8e71f374aae9b3f8": {
			"balance": "2000000000000000000000"
		},
		"a02e3f8f5959a7aab7418612129b701ca1b80010": {
			"balance": "20000000000000000000"
		},
		"a7a3f153cdc38821c20c5d8c8241b294a3f82b24": {
			"balance": "500000000000000000000"
		},
		"366175403481e0ab15bb514615cbb989ebc68f82": {
			"balance": "2000000000000000000000"
		},
		"5104ecc0e330dd1f81b58ac9dbb1a9fbf88a3c85": {
			"balance": "100000000000000000000000"
		},
		"a466d770d898d8c9d405e4a0e551efafcde53cf9": {
			"balance": "492500000000000000000"
		},
		"5fa8a54e68176c4fe2c01cf671c515bfbdd528a8": {
			"balance": "330000000000000000000000"
		},
)E" + R"E(
		"e2e15c60dd381e3a4be25071ab249a4c5c5264da": {
			"balance": "2350502000000000000000"
		},
		"0628bfbe5535782fb588406bc96660a49b011af5": {
			"balance": "1520000000000000000000"
		},
		"04d6b8d4da867407bb997749debbcdc0b358538a": {
			"balance": "1000000000000000000000"
		},
		"0e6ec313376271dff55423ab5422cc3a8b06b22b": {
			"balance": "4000000000000000000000"
		},
		"8787d12677a5ec291e57e31ffbfad105c3324b87": {
			"balance": "12438777000000000000000"
		},
		"58e2f11223fc8237f69d99c6289c148c0604f742": {
			"balance": "24000000000000000000000"
		},
		"5600730a55f6b20ebd24811faa3de96d1662abab": {
			"balance": "1880000000000000000000"
		},
		"fce089635ce97abac06b44819be5bb0a3e2e0b37": {
			"balance": "92491000000000000000"
		},
		"fa0c1a988c8a17ad3528eb28b3409daa58225f26": {
			"balance": "200000000000000000000"
		},
		"7ae1c19e53c71cee4c73fae2d7fc73bf9ab5e392": {
			"balance": "1000000000000000000000"
		},
		"bd17eed82b9a2592019a1b1b3c0fbad45c408d22": {
			"balance": "250000000000000000000"
		},
		"884a7a39d0916e05f1c242df55607f37df8c5fda": {
			"balance": "23400000000000000000000"
		},
		"ca70f4ddbf069d2143bd6bbc7f696b52789b32e7": {
			"balance": "3000000000000000000000"
		},
		"7b25bb9ca8e702217e9333225250e53c36804d48": {
			"balance": "1880000000000000000000"
		},
		"ea8317197959424041d9d7c67a3ece1dbb78bb55": {
			"balance": "394000000000000000000"
		},
		"5cb953a0e42f5030812226217fffc3ce230457e4": {
			"balance": "100000000000000000000"
		},
		"d1f4dc1ddb8abb8848a8b14e25f3b55a8591c266": {
			"balance": "250000000000000000000"
		},
		"6a42ca971c6578d5ade295c3e7f4ad331dd3424e": {
			"balance": "6000000000000000000000"
		},
		"07e1162ceae3cf21a3f62d105990302e307f4e3b": {
			"balance": "1530000000000000000000"
		},
		"5d1dc3387b47b8451e55106c0cc67d6dc72b7f0b": {
			"balance": "2000000000000000000000"
		},
		"5d2819e8d57821922ee445650ccaec7d40544a8d": {
			"balance": "200000000000000000000"
		},
		"4c24b78baf2bafc7fcc69016426be973e20a50b2": {
			"balance": "3000000000000000000000"
		},
		"630c5273126d517ce67101811cab16b8534cf9a8": {
			"balance": "9422595000000000000000"
		},
		"291f929ca59b54f8443e3d4d75d95dee243cef78": {
			"balance": "499938000000000000000"
		},
		"2dd325fdffb97b19995284afa5abdb574a1df16a": {
			"balance": "500000000000000000000"
		},
		"4fce8429ba49caa0369d1e494db57e89eab2ad39": {
			"balance": "200000000000000000000000"
		},
		"712b76510214dc620f6c3a1dd29aa22bf6d214fb": {
			"balance": "6000000000000000000000"
		},
		"266f2da7f0085ef3f3fa09baee232b93c744db2e": {
			"balance": "60000000000000000000000"
		},
		"0770c61be78772230cb5a3bb2429a72614a0b336": {
			"balance": "6767695000000000000000"
		},
		"02dfcb17a1b87441036374b762a5d3418b1cb4d4": {
			"balance": "1340860000000000000000"
		},
		"5e67df8969101adabd91accd6bb1991274af8df2": {
			"balance": "500000000000000000000"
		},
		"7d9c59631e2ba2e8e82891f3979922aaa3b567a1": {
			"balance": "8000000000000000000000"
		},
		"949f8c107bc7f0aceaa0f17052aadbd2f9732b2e": {
			"balance": "2000000000000000000000"
		},
		"ea4e809e266ae5f13cdbe38f9d0456e6386d1274": {
)E" + R"E(
			"balance": "4500000000000000000000"
		},
		"cd5510a242dfb0183de925fba866e312fabc1657": {
			"balance": "2400000000000000000000"
		},
		"a36e0d94b95364a82671b608cb2d373245612909": {
			"balance": "150011000000000000000"
		},
		"0ec46696ffac1f58005fa8439824f08eed1df89b": {
			"balance": "10000000000000000000000"
		},
		"c6fb1ee37417d080a0d048923bdabab095d077c6": {
			"balance": "200000000000000000000"
		},
		"53c9eca40973f63bb5927be0bc6a8a8be1951f74": {
			"balance": "2000000000000000000000"
		},
		"ea14bfda0a6e76668f8788321f07df37824ec5df": {
			"balance": "200000000000000000000000"
		},
		"dfb4d4ade52fcc818acc7a2c6bb2b00224658f78": {
			"balance": "7750000000000000000000"
		},
		"5997ffefb3c1d9d10f1ae2ac8ac3c8e2d2292783": {
			"balance": "1000000000000000000000"
		},
		"8eceb2e124536c5b5ffc640ed14ff15ed9a8cb71": {
			"balance": "2000000000000000000000"
		},
		"8f02bda6c36922a6be6a509be51906d393f7b99b": {
			"balance": "1019835000000000000000"
		},
		"530077c9f7b907ff9cec0c77a41a70e9029add4a": {
			"balance": "2000000000000000000000"
		},
		"08936a37df85b3a158cafd9de021f58137681347": {
			"balance": "18200000000000000000"
		},
		"8e9c429266df057efa78dd1d5f77fc40742ad466": {
			"balance": "300061000000000000000"
		},
		"acc59f3b30ceffc56461cc5b8df48902240e0e7b": {
			"balance": "2000000000000000000000"
		},
		"f5534815dc635efa5cc84b2ac734723e21b29372": {
			"balance": "1580000000000000000000"
		},
		"f873e57a65c93b6e18cb75f0dc077d5b8933dc5c": {
			"balance": "197000000000000000000"
		},
		"25b78c9fad85b43343f0bfcd0fac11c9949ca5eb": {
			"balance": "2000000000000000000000"
		},
		"aad2b7f8106695078e6c138ec81a7486aaca1eb2": {
			"balance": "200000000000000000000"
		},
		"509c8668036d143fb8ae70b11995631f3dfcad87": {
			"balance": "1000000000000000000000"
		},
		"3602458da86f6d6a9d9eb03daf97fe5619d442fa": {
			"balance": "2000000000000000000000"
		},
		"9f607b3f12469f446121cebf3475356b71b4328c": {
			"balance": "4000000000000000000000"
		},
		"fe3827d57630cf8761d512797b0b858e478bbd12": {
			"balance": "20000000000000000000"
		},
		"9d9c4efe9f433989e23be94049215329fa55b4cb": {
			"balance": "256215000000000000000"
		},
		"9bd905f1719fc7acd0159d4dc1f8db2f21472338": {
			"balance": "1000000000000000000000"
		},
		"7d82e523cc2dc591da3954e8b6bb2caf6461e69c": {
			"balance": "2316058000000000000000"
		},
		"74afe54902d615782576f8baac13ac970c050f6e": {
			"balance": "177670000000000000000"
		},
		"aff11ccf699304d5f5862af86083451c26e79ae5": {
			"balance": "1999000000000000000000"
		},
		"3885fee67107dc3a3c741ee290c98918c9b99397": {
			"balance": "20000000000000000000"
		},
		"36343aeca07b6ed58a0e62fa4ecb498a124fc971": {
			"balance": "300000000000000000000"
		},
		"c94a28fb3230a9ddfa964e770f2ce3c253a7be4f": {
			"balance": "200000000000000000000"
		},
		"9882967cee68d2a839fad8ab4a7c3dddf6c0adc8": {
			"balance": "1336866000000000000000"
		},
		"95df4e3445d7662624c48eba74cf9e0a53e9f732": {
			"balance": "56000000000000000000000"
		},
		"ca9faa17542fafbb388eab21bc4c94e8a7b34788": {
			"balance": "1999999000000000000000"
)E" + R"E(
		},
		"c8b1850525d946f2ae84f317b15188c536a5dc86": {
			"balance": "2685000000000000000000"
		},
		"39bac68d947859f59e9226089c96d62e9fbe3cde": {
			"balance": "40000000000000000000"
		},
		"a9bfc410dddb20711e45c07387eab30a054e19ac": {
			"balance": "1154750000000000000000"
		},
		"540a1819bd7c35861e791804e5fbb3bc97c9abb1": {
			"balance": "1454400000000000000000"
		},
		"667b61c03bb937a9f5d0fc5a09f1ea3363c77035": {
			"balance": "4250000000000000000000"
		},
		"010df1df4bed23760d2d1c03781586ddf7918e54": {
			"balance": "60000000000000000000"
		},
		"bd51ee2ea143d7b1d6b77e7e44bdd7da12f485ac": {
			"balance": "1318800000000000000000"
		},
		"fb5125bf0f5eb0b6f020e56bfc2fdf3d402c097e": {
			"balance": "5910000000000000000000"
		},
		"3f0c83aac5717962734e5ceaeaecd39b28ad06be": {
			"balance": "2000000000000000000000"
		},
		"f10661ff94140f203e7a482572437938bec9c3f7": {
			"balance": "20000000000000000000000"
		},
		"bd3097a79b3c0d2ebff0e6e86ab0edadbed47096": {
			"balance": "1670000000000000000000"
		},
		"edeb4894aadd0081bbddd3e8846804b583d19f27": {
			"balance": "2000000000000000000000"
		},
		"49c9771fca19d5b9d245c891f8158fe49f47a062": {
			"balance": "10000000000000000000000"
		},
		"6405dd13e93abcff377e700e3c1a0086eca27d29": {
			"balance": "18200000000000000000"
		},
		"ce5e04f0184369bcfa06aca66ffa91bf59fa0fb9": {
			"balance": "40000000000000000000"
		},
		"4364309a9fa07095600f79edc65120cdcd23dc64": {
			"balance": "10000000000000000000000"
		},
		"b749b54e04d5b19bdcedfb84da7701ab478c27ae": {
			"balance": "2680000000000000000000"
		},
		"f593c65285ee6bbd6637f3be8f89ad40d489f655": {
			"balance": "3000000000000000000000"
		},
		"d224f880f9479a89d32f09e52be990b288135cef": {
			"balance": "17300000000000000000000"
		},
		"85bb51bc3bfe9a1b2a2f6b1cda95bca8b38c8d5e": {
			"balance": "321750000000000000000"
		},
		"caf4481d9db78dc4f25f7b4ac8bd3b1ca0106b31": {
			"balance": "5000000000000000000000"
		},
		"51ca8bd4dc644fac47af675563d5804a0da21eeb": {
			"balance": "788000000000000000000"
		},
		"19f643e1a8fa04ae16006028138333a59a96de87": {
			"balance": "20000000000000000000"
		},
		"58b808a65b51e6338969afb95ec70735e451d526": {
			"balance": "39998000000000000000000"
		},
		"574921838cc77d6c98b17d903a3ae0ee0da95bd0": {
			"balance": "53480000000000000000000"
		},
		"7c6924d07c3ef5891966fe0a7856c87bef9d2034": {
			"balance": "2000000000000000000000"
		},
		"f9767e4ecb4a5980527508d7bec3d45e4c649c13": {
			"balance": "1910000000000000000000"
		},
		"f3be99b9103ce7550aa74ff1db18e09dfe32e005": {
			"balance": "2000000000000000000000"
		},
		"625644c95a873ef8c06cdb9e9f6d8d7680043d62": {
			"balance": "1800000000000000000000"
		},
		"6a44af96b3f032ae641beb67f4b6c83342d37c5d": {
			"balance": "29000000000000000000"
		},
		"d3a10ec7a5c9324999dd9e9b6bde7c911e584bda": {
			"balance": "600000000000000000000"
		},
		"e8ddbed732ebfe754096fde9086b8ea4a4cdc616": {
			"balance": "2000000000000000000000"
		},
		"235fa66c025ef5540070ebcf0d372d8177c467ab": {
			"balance": "33400000000000000000000"
		},
)E" + R"E(
		"4d08471d68007aff2ae279bc5e3fe4156fbbe3de": {
			"balance": "40000000000000000000000"
		},
		"dadc00ab7927603c2fcf31cee352f80e6c4d6351": {
			"balance": "1999664000000000000000"
		},
		"7393cbe7f9ba2165e5a7553500b6e75da3c33abf": {
			"balance": "100000000000000000000"
		},
		"77617ebc4bebc5f5ddeb1b7a70cdeb6ae2ffa024": {
			"balance": "1970000000000000000000"
		},
		"7fea1962e35d62059768c749bedd96cab930d378": {
			"balance": "2000000000000000000000"
		},
		"243b3bca6a299359e886ce33a30341fafe4d573d": {
			"balance": "20000000000000000000000"
		},
		"b94d47b3c052a5e50e4261ae06a20f45d8eee297": {
			"balance": "2000000000000000000000"
		},
		"e727e67ef911b81f6cf9c73fcbfebc2b02b5bfc6": {
			"balance": "2000000000000000000000"
		},
		"e510d6797fba3d6693835a844ea2ad540691971b": {
			"balance": "17381000000000000000000"
		},
		"0cdc960b998c141998160dc179b36c15d28470ed": {
			"balance": "500038000000000000000"
		},
		"3e76a62db187aa74f63817533b306cead0e8cebe": {
			"balance": "31200000000000000000000"
		},
		"495b641b1cdea362c3b4cbbd0f5cc50b1e176b9c": {
			"balance": "1000000000000000000000"
		},
		"5126460d692c71c9af6f05574d93998368a23799": {
			"balance": "52000000000000000000"
		},
		"a008019863c1a77c1499eb39bbd7bf2dd7a31cb9": {
			"balance": "137000000000000000000"
		},
		"65ee20b06d9ad589a7e7ce04b9f5f795f402aece": {
			"balance": "2000000000000000000000"
		},
		"f432b9dbaf11bdbd73b6519fc0a904198771aac6": {
			"balance": "152000000000000000000"
		},
		"85946d56a4d371a93368539690b60ec825107454": {
			"balance": "1730000000000000000000"
		},
		"26f9f7cefd7e394b9d3924412bf2c2831faf1f85": {
			"balance": "4000000000000000000000"
		},
		"d4ebb1929a23871cf77fe049ab9602be08be0a73": {
			"balance": "1910000000000000000000"
		},
		"4fdac1aa517007e0089430b3316a1badd12c01c7": {
			"balance": "500000000000000000000"
		},
		"05e671de55afec964b074de574d5158d5d21b0a3": {
			"balance": "3940000000000000000000"
		},
		"20181c4b41f6f972b66958215f19f570c15ddff1": {
			"balance": "1600000000000000000000"
		},
		"cc9519d1f3985f6b255eaded12d5624a972721e1": {
			"balance": "1000000000000000000000"
		},
		"169bbefc41cfd7d7cbb8dfc63020e9fb06d49546": {
			"balance": "2000000000000000000000"
		},
		"175a183a3a235ffbb03ba835675267229417a091": {
			"balance": "16000000000000000000000"
		},
		"8dde3cb8118568ef4503fe998ccdf536bf19a098": {
			"balance": "4000000000000000000000"
		},
		"6a05b21c4f17f9d73f5fb2b0cb89ff5356a6cc7e": {
			"balance": "1500000000000000000000"
		},
		"5cc4cba621f220637742057f6055b80dffd77e13": {
			"balance": "39997692000000000000000"
		},
		"ecb94c568bfe59ade650645f4f26306c736cace4": {
			"balance": "267400000000000000000"
		},
		"dfa6b8b8ad3184e357da282951d79161cfb089bc": {
			"balance": "400000000000000000000"
		},
		"a3058c51737a4e96c55f2ef6bd7bb358167ec2a7": {
			"balance": "606093000000000000000"
		},
		"051d424276b21239665186133d653bb8b1862f89": {
			"balance": "1000000000000000000000"
		},
		"d05ffb2b74f867204fe531653b0248e21c13544e": {
			"balance": "1000000000000000000000"
		},
		"e1f63ebbc62c7b7444040eb99623964f7667b376": {
)E" + R"E(
			"balance": "20000000000000000000"
		},
		"e5a3d7eb13b15c100177236d1beb30d17ee15420": {
			"balance": "2000000000000000000000"
		},
		"18fa8625c9dc843c78c7ab259ff87c9599e07f10": {
			"balance": "1000000000000000000000"
		},
		"64264aedd52dcae918a012fbcd0c030ee6f71821": {
			"balance": "1000000000000000000000"
		},
		"6f1f4907b8f61f0c51568d692806b382f50324f5": {
			"balance": "2000000000000000000000"
		},
		"becef61c1c442bef7ce04b73adb249a8ba047e00": {
			"balance": "1000400000000000000000"
		},
		"7b893286427e72db219a21fc4dcd5fbf59283c31": {
			"balance": "10000000000000000000000"
		},
		"ce5eb63a7bf4fbc2f6e4baa0c68ab1cb4cf98fb4": {
			"balance": "2000000000000000000000"
		},
		"66ec16ee9caab411c55a6629e318de6ee216491d": {
			"balance": "865000000000000000000"
		},
		"30b66150f1a63457023fdd45d0cc6cb54e0c0f06": {
			"balance": "1000000000000000000000"
		},
		"87183160d172d2e084d327b86bcb7c1d8e6784ef": {
			"balance": "4000086000000000000000"
		},
		"c420388fbee84ad656dd68cdc1fbaa9392780b34": {
			"balance": "187767000000000000000"
		},
		"90f774c9147dde90853ddc43f08f16d455178b8c": {
			"balance": "4000000000000000000000"
		},
		"1e1d7a5f2468b94ea826982dbf2125793c6e4a5a": {
			"balance": "999940000000000000000"
		},
		"8043fdd0bc4c973d1663d55fc135508ec5d4f4fa": {
			"balance": "20000000000000000000"
		},
		"7bca1da6c80a66baa5db5ac98541c4be276b447d": {
			"balance": "679000000000000000000"
		},
		"73550beb732ba9ddafda7ae406e18f7feb0f8bb2": {
			"balance": "2800000000000000000000"
		},
		"adc19ec835afe3e58d87dc93a8a9213c90451326": {
			"balance": "1971200000000000000000"
		},
		"821d798af19989c3ae5b84a7a7283cd7fda1fabe": {
			"balance": "20000000000000000000000"
		},
		"4c4e6f13fb5e3f70c3760262a03e317982691d10": {
			"balance": "100000000000000000000"
		},
		"664e43119870af107a448db1278b044838ffcdaf": {
			"balance": "400000000000000000000"
		},
		"8da1178f55d97772bb1d24111a404a4f8715b95d": {
			"balance": "878149000000000000000"
		},
		"5e6e9747e162f8b45c656e0f6cae7a84bac80e4e": {
			"balance": "2000000000000000000000"
		},
		"c7eac31abce6d5f1dea42202b6a674153db47a29": {
			"balance": "591000000000000000000"
		},
		"d96711540e2e998343d4f590b6fc8fac3bb8b31d": {
			"balance": "1758944000000000000000"
		},
		"9da4ec407077f4b9707b2d9d2ede5ea5282bf1df": {
			"balance": "4000000000000000000000"
		},
		"f60c1b45f164b9580e20275a5c39e1d71e35f891": {
			"balance": "2000000000000000000000"
		},
		"eb6394a7bfa4d28911d5a5b23e93f35e340c2294": {
			"balance": "78000000000000000000"
		},
		"a89ac93b23370472daac337e9afdf642543f3e57": {
			"balance": "10000000000000000000000"
		},
		"bb618e25221ad9a740b299ed1406bc3934b0b16d": {
			"balance": "1000000000000000000000"
		},
		"817ac33bd8f847567372951f4a10d7a91ce3f430": {
			"balance": "200015000000000000000"
		},
		"fe6a895b795cb4bf85903d3ce09c5aa43953d3bf": {
			"balance": "3400000000000000000000"
		},
		"3673954399f6dfbe671818259bb278e2e92ee315": {
			"balance": "200000000000000000000000"
		},
		"df0ff1f3d27a8ec9fb8f6b0cb254a63bba8224a5": {
			"balance": "4367636000000000000000"
)E" + R"E(
		},
		"ff12e49d8e06aa20f886293c0b98ed7eff788805": {
			"balance": "4000000000000000000000"
		},
		"5aef16a226dd68071f2483e1da42598319f69b2c": {
			"balance": "2000000000000000000000"
		},
		"0266ab1c6b0216230b9395443d5fa75e684568c6": {
			"balance": "1000000000000000000000"
		},
		"14a7352066364404db50f0d0d78d754a22198ef4": {
			"balance": "1880000000000000000000"
		},
		"444caf79b71338ee9aa7c733b02acaa7dc025948": {
			"balance": "40000000000000000000"
		},
		"64e2de21200b1899c3a0c0653b5040136d0dc842": {
			"balance": "20000000000000000000000"
		},
		"36e156610cd8ff64e780d89d0054385ca76755aa": {
			"balance": "14000000000000000000000"
		},
		"0a6ebe723b6ed1f9a86a69ddda68dc47465c2b1b": {
			"balance": "1185000000000000000000"
		},
		"38bf2a1f7a69de0e2546adb808b36335645da9ff": {
			"balance": "2000320000000000000000"
		},
		"39f44663d92561091b82a70dcf593d754005973a": {
			"balance": "199999000000000000000"
		},
		"24b9e6644f6ba4cde126270d81f6ab60f286dff4": {
			"balance": "133700000000000000000"
		},
		"9b59eb213b1e7565e45047e04ea0374f10762d16": {
			"balance": "2000000000000000000000"
		},
		"309544b6232c3dd737f945a03193d19b5f3f65b9": {
			"balance": "1087440000000000000000"
		},
		"b28bb39f3466517cd46f979cf59653ee7d8f152e": {
			"balance": "450000000000000000000"
		},
		"9da8e22ca10e67fea44e525e4751eeac36a31194": {
			"balance": "260000000000000000000"
		},
		"4f8ae80238e60008557075ab6afe0a7f2e74d729": {
			"balance": "100000000000000000000"
		},
		"74ed33acf43f35b98c9230b9e6642ecb5330839e": {
			"balance": "681872000000000000000"
		},
		"22842ab830da509913f81dd1f04f10af9edd1c55": {
			"balance": "2000000000000000000000"
		},
		"a8f37f0ab3a1d448a9e3ce40965f97a646083a34": {
			"balance": "329800000000000000000"
		},
		"582b70669c97aab7d68148d8d4e90411e2810d56": {
			"balance": "999972000000000000000"
		},
		"d5e55100fbd1956bbed2ca518d4b1fa376032b0b": {
			"balance": "100000000000000000000"
		},
		"b7cc6b1acc32d8b295df68ed9d5e60b8f64cb67b": {
			"balance": "300000000000000000000"
		},
		"e081ca1f4882db6043d5a9190703fde0ab3bf56d": {
			"balance": "400000000000000000000"
		},
		"c02077449a134a7ad1ef7e4d927affeceeadb5ae": {
			"balance": "18200000000000000000"
		},
		"e09fea755aee1a44c0a89f03b5deb762ba33006f": {
			"balance": "1100070000000000000000"
		},
		"b3717731dad65132da792d876030e46ac227bb8a": {
			"balance": "1000000000000000000000"
		},
		"157eb3d3113bd3b597714d3a954edd018982a5cb": {
			"balance": "2000000000000000000000"
		},
		"dc57345b38e0f067c9a31d9deac5275a10949321": {
			"balance": "200000000000000000000"
		},
		"40ea5044b204b23076b1a5803bf1d30c0f88871a": {
			"balance": "14000000000000000000000"
		},
		"2bab0fbe28d58420b52036770a12f9952aea6911": {
			"balance": "3820000000000000000000"
		},
		"adaa0e548c035affed64ca678a963fabe9a26bfd": {
			"balance": "70000000000000000000"
		},
		"bb48eaf516ce2dec3e41feb4c679e4957641164f": {
			"balance": "3820000000000000000000"
		},
		"7693bdeb6fc82b5bca721355223175d47a084b4d": {
			"balance": "22000000000000000000000"
		},
)E" + R"E(
		"03cb98d7acd817de9d886d22fab3f1b57d92a608": {
			"balance": "1600000000000000000000"
		},
		"f88900db737955b1519b1a7d170a18864ce590eb": {
			"balance": "18200000000000000000"
		},
		"757fa55446c460968bb74b5ebca96c4ef2c709c5": {
			"balance": "1015200000000000000000"
		},
		"da855d53477f505ec4c8d5e8bb9180d38681119c": {
			"balance": "5600000000000000000000"
		},
		"e41aea250b877d423a63ba2bce2f3a61c0248d56": {
			"balance": "260000000000000000000"
		},
		"8262169b615870134eb4ac6c5f471c6bf2f789fc": {
			"balance": "462500000000000000000"
		},
		"66b0c100c49149935d14c0dc202cce907cea1a3d": {
			"balance": "1970000000000000000000"
		},
		"854c0c469c246b83b5d1b3eca443b39af5ee128a": {
			"balance": "1600000000000000000000"
		},
		"eb6810691d1ae0d19e47bd22cebee0b3ba27f88a": {
			"balance": "2499922000000000000000"
		},
		"24dcc24bd9c7210ceacfb30da98ae04a4d7b8ab9": {
			"balance": "1000000000000000000000"
		},
		"e31b4eef184c24ab098e36c802714bd4743dd0d4": {
			"balance": "200000000000000000000"
		},
		"99b8c824869de9ed24f3bff6854cb6dd45cc3f9f": {
			"balance": "1880000000000000000000"
		},
		"2ae73a79aea0278533accf21070922b1613f8f32": {
			"balance": "3097417000000000000000"
		},
		"ddbd2b932c763ba5b1b7ae3b362eac3e8d40121a": {
			"balance": "10000000000000000000000"
		},
		"1b4bbcb18165211b265b280716cb3f1f212176e8": {
			"balance": "472325000000000000000"
		},
		"e177e0c201d335ba3956929c571588b51c5223ae": {
			"balance": "2000000000000000000000"
		},
		"1945fe377fe6d4b71e3e791f6f17db243c9b8b0f": {
			"balance": "2185500000000000000000"
		},
		"3e9b34a57f3375ae59c0a75e19c4b641228d9700": {
			"balance": "17900000000000000000"
		},
		"a4d6c82eddae5947fbe9cdfbd548ae33d91a7191": {
			"balance": "8000000000000000000000"
		},
		"bad4425e171c3e72975eb46ac0a015db315a5d8f": {
			"balance": "2000000000000000000000"
		},
		"a2d2aa626b09d6d4e4b13f7ffc5a88bd7ad36742": {
			"balance": "4639390000000000000000"
		},
		"b61c34fcacda701a5aa8702459deb0e4ae838df8": {
			"balance": "35000000000000000000000"
		},
		"145e0600e2a927b2dd8d379356b45a2e7d51d3ae": {
			"balance": "2545843000000000000000"
		},
		"8df339214b6ad1b24663ce716034749d6ef838d9": {
			"balance": "11000000000000000000000"
		},
		"8fd9a5c33a7d9edce0997bdf77ab306424a11ea9": {
			"balance": "2000000000000000000000"
		},
		"097da12cfc1f7c1a2464def08c29bed5e2f851e9": {
			"balance": "20000000000000000000"
		},
		"ddabf13c3c8ea4e3d73d78ec717afafa430e5479": {
			"balance": "41600000000000000000000"
		},
		"9eeb07bd2b7890195e7d46bdf2071b6617514ddb": {
			"balance": "2000000000000000000000"
		},
		"819af9a1c27332b1c369bbda1b3de1c6e933d640": {
			"balance": "314308000000000000000"
		},
		"d7d2c6fca8ad1f75395210b57de5dfd673933909": {
			"balance": "340000000000000000000"
		},
		"cdd5d881a7362c9070073bdfbc75e72453ac510e": {
			"balance": "842000000000000000000"
		},
		"e9ac36376efa06109d40726307dd1a57e213eaa9": {
			"balance": "194000000000000000000"
		},
		"1bea4df5122fafdeb3607eddda1ea4ffdb9abf2a": {
			"balance": "346000000000000000000"
		},
		"3e5e93fb4c9c9d1246f8f247358e22c3c5d17b6a": {
)E" + R"E(
			"balance": "150000000000000000000"
		},
		"6c1ddd33c81966dc8621776071a4129482f2c65f": {
			"balance": "40000000000000000000000"
		},
		"2ccb66494d0af689abf9483d365d782444e7dead": {
			"balance": "1000000000000000000000"
		},
		"19571a2b8f81c6bcf66ab3a10083295617150003": {
			"balance": "492500000000000000000"
		},
		"38ac664ee8e0795e4275cb852bcba6a479ad9c8d": {
			"balance": "20000000000000000000"
		},
		"c4803bb407c762f90b7596e6fde194931e769590": {
			"balance": "4000000000000000000000"
		},
		"93507e9e8119cbceda8ab087e7ecb071383d6981": {
			"balance": "14000000000000000000000"
		},
		"b672734afcc224e2e609fc51d4f059732744c948": {
			"balance": "295500000000000000000"
		},
		"fbbbebcfbe235e57dd2306ad1a9ec581c7f9f48f": {
			"balance": "40000000000000000000"
		},
		"8c81410ea8354cc5c65c41be8bd5de733c0b111d": {
			"balance": "9550000000000000000000"
		},
		"942c6b8c955bc0d88812678a236725b32739d947": {
			"balance": "1550000000000000000000"
		},
		"d2e817738abf1fb486583f80c350318bed860c80": {
			"balance": "240010000000000000000"
		},
		"bff5df769934b8943ca9137d0efef2fe6ebbb34e": {
			"balance": "100000000000000000000"
		},
		"6c4e426e8dc005dfa3516cb8a680b02eea95ae8e": {
			"balance": "1337000000000000000000"
		},
		"f645dd7c890093e8e4c8aa92a6bb353522d3dc98": {
			"balance": "134000000000000000000"
		},
		"4bac846af4169f1d95431b341d8800b22180af1a": {
			"balance": "20000000000000000000"
		},
		"0514954c3c2fb657f9a06f510ea22748f027cdd3": {
			"balance": "400000000000000000000"
		},
		"163dca73d7d6ea3f3e6062322a8734180c0b78ef": {
			"balance": "2941400000000000000000"
		},
		"feaca2ac74624bf348dac9985143cfd652a4be55": {
			"balance": "26148245000000000000000"
		},
		"fe80e9232deaff19baf99869883a4bdf0004e53c": {
			"balance": "855680000000000000000"
		},
		"17108dab2c50f99de110e1b3b3b4cd82f5df28e7": {
			"balance": "980000000000000000000"
		},
		"837a645dc95c49549f899c4e8bcf875324b2f57c": {
			"balance": "600400000000000000000"
		},
		"762998e1d75227fced7a70be109a4c0b4ed86414": {
			"balance": "20000000000000000000"
		},
		"c0a7e8435dff14c25577739db55c24d5bf57a3d9": {
			"balance": "49250000000000000000000"
		},
		"aead88d689416b1c91f2364421375b7d3c70fb2e": {
			"balance": "2000000000000000000000"
		},
		"9279b2228cec8f7b4dda3f320e9a0466c2f585ca": {
			"balance": "5000000000000000000000"
		},
		"36726f3b885a24f92996da81625ec8ad16d8cbe6": {
			"balance": "1543723000000000000000"
		},
		"3951e48e3c869e6b72a143b6a45068cdb9d466d0": {
			"balance": "20000000000000000000"
		},
		"f5d61ac4ca95475e5b7bffd5f2f690b316759615": {
			"balance": "31040000000000000000000"
		},
		"158a0d619253bf4432b5cd02c7b862f7c2b75636": {
			"balance": "135733000000000000000"
		},
		"e56d431324c92911a1749df292709c14b77a65cd": {
			"balance": "8200000000000000000000"
		},
		"9976947eff5f6ae5da08dd541192f378b428ff94": {
			"balance": "8000000000000000000000"
		},
		"83210583c16a4e1e1dac84ebd37e3d0f7c57eba4": {
			"balance": "2000000000000000000000"
		},
		"dcb64df43758c7cf974fa660484fbb718f8c67c1": {
			"balance": "20000000000000000000000"
)E" + R"E(
		},
		"d4205592844055b3c7a1f80cefe3b8eb509bcde7": {
			"balance": "178973000000000000000"
		},
		"d0648a581b3508e135a2935d12c9657045d871ca": {
			"balance": "8022000000000000000000"
		},
		"e7d17524d00bad82497c0f27156a647ff51d2792": {
			"balance": "20000000000000000000"
		},
		"21582e99e502cbf3d3c23bdffb76e901ac6d56b2": {
			"balance": "100000000000000000000"
		},
		"e61f280915c774a31d223cf80c069266e5adf19b": {
			"balance": "880000000000000000000"
		},
		"03c91d92943603e752203e05340e566013b90045": {
			"balance": "802200000000000000000"
		},
		"22561c5931143536309c17e832587b625c390b9a": {
			"balance": "4000000000000000000000"
		},
		"e399c81a1d701b44f0b66f3399e66b275aaaf8c1": {
			"balance": "1000000000000000000000"
		},
		"7f8dbce180ed9c563635aad2d97b4cbc428906d9": {
			"balance": "2674000000000000000000"
		},
		"9f61beb46f5e853d0a8521c7446e68e34c7d0973": {
			"balance": "560000000000000000000"
		},
		"6d3f2ba856ccbb0237fa7661156b14b013f21240": {
			"balance": "1000000000000000000000"
		},
		"5f742e487e3ab81af2f94afdbe1b9b8f5ccc81bc": {
			"balance": "2172412000000000000000"
		},
		"b600feab4aa96c537504d96057223141692c193a": {
			"balance": "400000000000000000000"
		},
		"fab487500df20fb83ebed916791d561772adbebf": {
			"balance": "1999980000000000000000"
		},
		"f8704c16d2fd5ba3a2c01d0eb20484e6ecfa3109": {
			"balance": "200000000000000000000"
		},
		"3f1bc420c53c002c9e90037c44fe6a8ef4ddc962": {
			"balance": "173000000000000000000"
		},
		"82e577b515cb2b0860aafe1ce09a59e09fe7d040": {
			"balance": "600000000000000000000"
		},
		"bc999e385c5aebcac8d6f3f0d60d5aa725336d0d": {
			"balance": "2000000000000000000000"
		},
		"e16ce35961cd74bd590d04c4ad4a1989e05691c6": {
			"balance": "146000000000000000000"
		},
		"eb76424c0fd597d3e341a9642ad1ee118b2b579d": {
			"balance": "4000000000000000000000"
		},
		"c440c7ca2f964b6972ef664a2261dde892619d9c": {
			"balance": "20000000000000000000000"
		},
		"460d5355b2ceeb6e62107d81e51270b26bf45620": {
			"balance": "2005500000000000000000"
		},
		"fcada300283f6bcc134a91456760b0d77de410e0": {
			"balance": "2000000000000000000000"
		},
		"be8d7f18adfe5d6cc775394989e1930c979d007d": {
			"balance": "1000000000000000000000"
		},
		"a7f9220c8047826bd5d5183f4e676a6d77bfed36": {
			"balance": "153368000000000000000"
		},
		"98d204f9085f8c8e7de23e589b64c6eff692cc63": {
			"balance": "2000000000000000000000"
		},
		"5a2916b8d2e8cc12e207ab464d433e2370d823d9": {
			"balance": "2000000000000000000000"
		},
		"c42d6aeb710e3a50bfb44d6c31092969a11aa7f3": {
			"balance": "150052000000000000000"
		},
		"04ce45f600db18a9d0851b29d9393ebdaafe3dc5": {
			"balance": "20000000000000000000"
		},
		"7a1370a742ec2687e761a19ac5a794329ee67404": {
			"balance": "2999988000000000000000"
		},
		"da2ad58e77deddede2187646c465945a8dc3f641": {
			"balance": "660000000000000000000"
		},
		"ec58bc0d0c20d8f49465664153c5c196fe59e6be": {
			"balance": "400000000000000000000"
		},
		"f8063af4cc1dd9619ab5d8bff3fcd1faa8488221": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"b9231eb26e5f9e4b4d288f03906704fab96c87d6": {
			"balance": "19700000000000000000000"
		},
		"6e5c2d9b1c546a86eefd5d0a5120c9e4e730190e": {
			"balance": "199600000000000000000"
		},
		"e49936a92a8ccf710eaac342bc454b9b14ebecb1": {
			"balance": "2000000000000000000000"
		},
		"21dbdb817a0d8404c6bdd61504374e9c43c9210e": {
			"balance": "9999917000000000000000"
		},
		"5cebe30b2a95f4aefda665651dc0cf7ef5758199": {
			"balance": "18200000000000000000"
		},
		"597038ff91a0900cbbab488af483c790e6ec00a0": {
			"balance": "10000000000000000000000"
		},
		"0fa5d8c5b3f294efd495ab69d768f81872508548": {
			"balance": "2000000000000000000000"
		},
		"feef3b6eabc94affd3310c1c4d0e65375e131119": {
			"balance": "20000000000000000000"
		},
		"1ce81d31a7923022e125bf48a3e03693b98dc9dd": {
			"balance": "2000000000000000000000"
		},
		"5887dc6a33dfed5ac1edefe35ef91a216231ac96": {
			"balance": "250000000000000000000"
		},
		"4e8e47ae3b1ef50c9d54a38e14208c1abd3603c2": {
			"balance": "2235000000000000000000"
		},
		"e845e387c4cbdf982280f6aa01c40e4be958ddb2": {
			"balance": "25000000000000000000000"
		},
		"71d9494e50c5dd59c599dba3810ba1755e6537f0": {
			"balance": "4000000000000000000000"
		},
		"6eb5578a6bb7c32153195b0d8020a6914852c059": {
			"balance": "660000000000000000000000"
		},
		"543f8c674e2462d8d5daa0e80195a8708e11a29e": {
			"balance": "63940000000000000000"
		},
		"a0459ef3693aacd1647cd5d8929839204cef53be": {
			"balance": "1000000000000000000000"
		},
		"dda371e600d30688d4710e088e02fdf2b9524d5f": {
			"balance": "6920000000000000000000"
		},
		"dd4dd6d36033b0636fcc8d0938609f4dd64f4a86": {
			"balance": "60000000000000000000"
		},
		"3bd624b548cb659736907ed8aa3c0c705e24b575": {
			"balance": "2000000000000000000000"
		},
		"414599092e879ae25372a84d735af5c4e510cd6d": {
			"balance": "400000000000000000000"
		},
		"3d66cd4bd64d5c8c1b5eea281e106d1c5aad2373": {
			"balance": "1951100000000000000000"
		},
		"5948bc3650ed519bf891a572679fd992f8780c57": {
			"balance": "197000000000000000000"
		},
		"8b74a7cb1bb8c58fce267466a30358adaf527f61": {
			"balance": "13620000000000000000000"
		},
		"3f10800282d1b7ddc78fa92d8230074e1bf6aeae": {
			"balance": "4925000000000000000000"
		},
		"32dbb6716c54e83165829a4abb36757849b6e47d": {
			"balance": "1000000000000000000000"
		},
		"e6b3ac3f5d4da5a8857d0b3f30fc4b2b692b77d7": {
			"balance": "1460000000000000000000"
		},
		"052a58e035f1fe9cdd169bcf20970345d12b9c51": {
			"balance": "1490000000000000000000"
		},
		"581bdf1bb276dbdd86aedcdb397a01efc0e00c5b": {
			"balance": "1000000000000000000000"
		},
		"604e9477ebf4727c745bcabbedcb6ccf29994022": {
			"balance": "1000060000000000000000"
		},
		"59b96deb8784885d8d3b4a166143cc435d2555a1": {
			"balance": "1337000000000000000000"
		},
		"37d980a12ee3bf23cc5cdb63b4ae45691f74c837": {
			"balance": "2000000000000000000000"
		},
		"3bfbd3847c17a61cf3f17b52f8eba1b960b3f39f": {
			"balance": "3000000000000000000000"
		},
		"49c941e0e5018726b7290fc473b471d41dae80d1": {
			"balance": "500000000000000000000"
		},
		"f26bcedce3feadcea3bc3e96eb1040dfd8ffe1a0": {
)E" + R"E(
			"balance": "775000000000000000000"
		},
		"d0944aa185a1337061ae20dc9dd96c83b2ba4602": {
			"balance": "200000000000000000000"
		},
		"904caa429c619d940f8e6741826a0db692b19728": {
			"balance": "1000000000000000000000"
		},
		"b95c9b10aa981cf4a67a71cc52c504dee8cf58bd": {
			"balance": "4000000000000000000000"
		},
		"15874686b6733d10d703c9f9bec6c52eb8628d67": {
			"balance": "2000000000000000000000"
		},
		"1374facd7b3f8d68649d60d4550ee69ff0484133": {
			"balance": "269700000000000000000"
		},
		"b0e469c886593815b3495638595daef0665fae62": {
			"balance": "1940000000000000000000"
		},
		"47ff6feb43212060bb1503d7a397fc08f4e70352": {
			"balance": "2000000000000000000000"
		},
		"c60b04654e003b4683041f1cbd6bc38fda7cdbd6": {
			"balance": "2000000000000000000000"
		},
		"3ecdb532e397579662b2a46141e78f8235936a5f": {
			"balance": "66850000000000000000"
		},
		"b3a8c2cb7d358e5739941d945ba9045a023a8bbb": {
			"balance": "1000000000000000000000"
		},
		"32ef5cdc671df5562a901aee5db716b9be76dcf6": {
			"balance": "2000000000000000000000"
		},
		"c94110e71afe578aa218e4fc286403b0330ace8d": {
			"balance": "2000000000000000000000"
		},
		"9b43dcb95fde318075a567f1e6b57617055ef9e8": {
			"balance": "3940000000000000000000"
		},
		"efeea010756f81da4ba25b721787f058170befbd": {
			"balance": "32470000000000000000"
		},
		"c88255eddcf521c6f81d97f5a42181c9073d4ef1": {
			"balance": "290793000000000000000"
		},
		"dd47189a3e64397167f0620e484565b762bfbbf4": {
			"balance": "1850000000000000000000"
		},
		"82f39b2758ae42277b86d69f75e628d958ebcab0": {
			"balance": "40000000000000000000000"
		},
		"e37f5fdc6ec97d2f866a1cfd0d3a4da4387b22b5": {
			"balance": "10000000000000000000000"
		},
		"62331df2a3cbee3520e911dea9f73e905f892505": {
			"balance": "2000000000000000000000"
		},
		"8c5d16ed65e3ed7e8b96ca972bc86173e3500b03": {
			"balance": "2000000000000000000000"
		},
		"8b9841862e77fbbe919470935583a93cf027e450": {
			"balance": "2000054000000000000000"
		},
		"c8dd27f16bf22450f5771b9fe4ed4ffcb30936f4": {
			"balance": "197000000000000000000"
		},
		"dec8a1a898f1b895d8301fe64ab3ad5de941f689": {
			"balance": "787803000000000000000"
		},
		"61c4ee7c864c4d6b5e37ea1331c203739e826b2f": {
			"balance": "30063000000000000000"
		},
		"3250e3e858c26adeccadf36a5663c22aa84c4170": {
			"balance": "5000000000000000000000"
		},
		"299e0bca55e069de8504e89aca6eca21d38a9a5d": {
			"balance": "55500000000000000000"
		},
		"d50f7fa03e389876d3908b60a537a6706304fb56": {
			"balance": "100000000000000000000"
		},
		"69073269729e6414b26ec8dc0fd935c73b579f1e": {
			"balance": "30000000000000000000000"
		},
		"14fcd1391e7d732f41766cdacd84fa1deb9ffdd2": {
			"balance": "2000000000000000000000"
		},
		"823768746737ce6da312d53e54534e106f967cf3": {
			"balance": "20000000000000000000"
		},
		"882f75708386653c80171d0663bfe30b017ed0ad": {
			"balance": "2000000000000000000000"
		},
		"a25b086437fd2192d0a0f64f6ed044f38ef3da32": {
			"balance": "335000000000000000000"
		},
		"5a9c8b69fc614d69564999b00dcb42db67f97e90": {
			"balance": "3429227000000000000000"
)E" + R"E(
		},
		"a2b701f9f5cdd09e4ba62baebae3a88257105885": {
			"balance": "1000000000000000000000"
		},
		"5e7b8c54dc57b0402062719dee7ef5e37ea35d62": {
			"balance": "2877224000000000000000"
		},
		"7ffabfbc390cbe43ce89188f0868b27dcb0f0cad": {
			"balance": "6370000000000000000000"
		},
		"b5cdbc4115406f52e5aa85d0fea170d2979cc7ba": {
			"balance": "1337000000000000000000"
		},
		"263814309de4e635cf585e0d365477fc40e66cf7": {
			"balance": "146000000000000000000"
		},
		"24cff0e9336a9f80f9b1cb968caf6b1d1c4932a4": {
			"balance": "200200000000000000000"
		},
		"d3a941c961e8ca8b1070f23c6d6d0d2a758a4444": {
			"balance": "200000000000000000000"
		},
		"a97beb3a48c45f1528284cb6a95f7de453358ec6": {
			"balance": "31000000000000000000000"
		},
		"4dd131c74a068a37c90aded4f309c2409f6478d3": {
			"balance": "400008000000000000000"
		},
		"653675b842d7d8b461f722b4117cb81dac8e639d": {
			"balance": "31000000000000000000"
		},
		"561be9299b3e6b3e63b79b09169d1a948ae6db01": {
			"balance": "500000000000000000000"
		},
		"dc067ed3e12d711ed475f5156ef7e71a80d934b9": {
			"balance": "9550000000000000000000"
		},
		"08d97eadfcb7b064e1ccd9c8979fbee5e77a9719": {
			"balance": "266063000000000000000"
		},
		"6e4c2ab7db026939dbd3bc68384af660a61816b2": {
			"balance": "167000000000000000000"
		},
		"bf4c73a7ede7b164fe072114843654e4d8781dde": {
			"balance": "2000000000000000000000"
		},
		"f504943aaf16796e0b341bbcdf21d11cc586cdd1": {
			"balance": "9000000000000000000000"
		},
		"ea81ca8638540cd9d4d73d060f2cebf2241ffc3e": {
			"balance": "1970000000000000000000"
		},
		"9944fee9d34a4a880023c78932c00b59d5c82a82": {
			"balance": "750022000000000000000"
		},
		"12f460ae646cd2780fd35c50a6af4b9accfa85c6": {
			"balance": "1000000000000000000000"
		},
		"4e232d53b3e6be8f895361d31c34d4762b12c82e": {
			"balance": "1760000000000000000000"
		},
		"6bb2aca23fa1626d18efd6777fb97db02d8e0ae4": {
			"balance": "40000000000000000000000"
		},
		"bc4e471560c99c8a2a4b1b1ad0c36aa6502b7c4b": {
			"balance": "12000000000000000000000"
		},
		"2e2cbd7ad82547b4f5ff8b3ab56f942a6445a3b0": {
			"balance": "200000000000000000000"
		},
		"21ecb2dfa65779c7592d041cd2105a81f4fd4e46": {
			"balance": "1000000000000000000000"
		},
		"34318625818ec13f11835ae97353ce377d6f590a": {
			"balance": "1520000000000000000000"
		},
		"a7ef35ce87eda6c28df248785815053ec97a5045": {
			"balance": "4999998000000000000000"
		},
		"6a514e6242f6b68c137e97fea1e78eb555a7e5f7": {
			"balance": "20000000000000000000"
		},
		"9340b5f678e45ee05eb708bb7abb6ec8f08f1b6b": {
			"balance": "6000000000000000000000"
		},
		"43cc08d0732aa58adef7619bed46558ad7774173": {
			"balance": "4443926000000000000000"
		},
		"12e9a4ad2ad57484dd700565bddb46423bd9bd31": {
			"balance": "19999800000000000000000"
		},
		"ebbeeb259184a6e01cccfc2207bbd883785ac90a": {
			"balance": "619966000000000000000"
		},
		"704ab1150d5e10f5e3499508f0bf70650f028d4b": {
			"balance": "4000000000000000000000"
		},
		"fc361105dd90f9ede566499d69e9130395f12ac8": {
			"balance": "395000000000000000000000"
		},
)E" + R"E(
		"c1b9a5704d351cfe983f79abeec3dbbbae3bb629": {
			"balance": "20000000000000000000"
		},
		"66f50406eb1b11a946cab45927cca37470e5a208": {
			"balance": "2000000000000000000000"
		},
		"53942e7949d6788bb780a7e8a0792781b1614b84": {
			"balance": "15899600000000000000000"
		},
		"32ba9a7d0423e03a525fe2ebeb661d2085778bd8": {
			"balance": "20000000000000000000000"
		},
		"11c0358aa6479de21866fe21071924b65e70f8b9": {
			"balance": "36400000000000000000000"
		},
		"76cb9c8b69f4387675c48253e234cb7e0d74a426": {
			"balance": "7396300000000000000000"
		},
		"9f5f44026b576a4adb41e95961561d41039ca391": {
			"balance": "250000000000000000000"
		},
		"533a73a4a2228eee05c4ffd718bbf3f9c1b129a7": {
			"balance": "6000000000000000000000"
		},
		"dcc52d8f8d9fc742a8b82767f0555387c563efff": {
			"balance": "500000000000000000000"
		},
		"f456a75bb99655a7412ce97da081816dfdb2b1f2": {
			"balance": "200000000000000000000"
		},
		"d0c101fd1f01c63f6b1d19bc920d9f932314b136": {
			"balance": "20000000000000000000000"
		},
		"dabc225042a6592cfa13ebe54efa41040878a5a2": {
			"balance": "259550000000000000000"
		},
		"38eec6e217f4d41aa920e424b9525197041cd4c6": {
			"balance": "4428166000000000000000"
		},
		"8a247d186510809f71cffc4559471c3910858121": {
			"balance": "1790000000000000000000"
		},
		"4f152b2fb8659d43776ebb1e81673aa84169be96": {
			"balance": "2000000000000000000000"
		},
		"b4496ddb27799a222457d73979116728e8a1845b": {
			"balance": "2610331000000000000000"
		},
		"4a4053b31d0ee5dbafb1d06bd7ac7ff3222c47d6": {
			"balance": "1400000000000000000000"
		},
		"0f7bea4ef3f73ae0233df1e100718cbe29310bb0": {
			"balance": "2000000000000000000000"
		},
		"c836e24a6fcf29943b3608e662290a215f6529ea": {
			"balance": "292000000000000000000"
		},
		"1765361c2ec2f83616ce8363aae21025f2566f40": {
			"balance": "5000000000000000000000"
		},
		"b6e6c3222b6b6f9be2875d2a89f127fb64100fe2": {
			"balance": "8008000000000000000000"
		},
		"01bbc14f67af0639aab1441e6a08d4ce7162090f": {
			"balance": "1309500000000000000000"
		},
		"af2058c7282cf67c8c3cf930133c89617ce75d29": {
			"balance": "6920000000000000000000"
		},
		"464d9c89cce484df000277198ed8075fa63572d1": {
			"balance": "20000000000000000000"
		},
		"50cd97e9378b5cf18f173963236c9951ef7438a5": {
			"balance": "1400000000000000000000"
		},
		"cb47bd30cfa8ec5468aaa6a94642ced9c819c8d4": {
			"balance": "4000000000000000000000"
		},
		"6b10f8f8b3e3b60de90aa12d155f9ff5ffb22c50": {
			"balance": "2000000000000000000000"
		},
		"09b7a988d13ff89186736f03fdf46175b53d16e0": {
			"balance": "6000000000000000000000"
		},
		"5bfafe97b1dd1d712be86d41df79895345875a87": {
			"balance": "500000000000000000000"
		},
		"a06cd1f396396c0a64464651d7c205efaf387ca3": {
			"balance": "1999944000000000000000"
		},
		"fc0096b21e95acb8d619d176a4a1d8d529badbef": {
			"balance": "384601000000000000000"
		},
		"a74444f90fbb54e56f3ac9b6cfccaa4819e4614a": {
			"balance": "20000000000000000000"
		},
		"3c15b3511df6f0342e7348cc89af39a168b7730f": {
			"balance": "1000000000000000000000"
		},
		"3d6ff82c9377059fb30d9215723f60c775c891fe": {
)E" + R"E(
			"balance": "250066000000000000000"
		},
		"a524a8cccc49518d170a328270a2f88133fbaf5d": {
			"balance": "294500000000000000000"
		},
		"8a7a06be199a3a58019d846ac9cbd4d95dd757de": {
			"balance": "3000200000000000000000"
		},
		"d744ac7e5310be696a63b003c40bd039370561c6": {
			"balance": "1670000000000000000000"
		},
		"fe362688845fa244cc807e4b1130eb3741a8051e": {
			"balance": "1000000000000000000000"
		},
		"b2d0360515f17daba90fcbac8205d569b915d6ac": {
			"balance": "6000000000000000000000"
		},
		"c53594c7cfb2a08f284cc9d7a63bbdfc0b319732": {
			"balance": "49200000000000000000000"
		},
		"b3c228731d186d2ded5b5fbe004c666c8e469b86": {
			"balance": "29000000000000000000"
		},
		"63e414603e80d4e5a0f5c18774204642258208e4": {
			"balance": "5000000000000000000000"
		},
		"826ce5790532e0548c6102a30d3eac836bd6388f": {
			"balance": "18000000000000000000000"
		},
		"c5e812f76f15f2e1f2f9bc4823483c8804636f67": {
			"balance": "73000000000000000000"
		},
		"116fef5e601642c918cb89160fc2293ba71da936": {
			"balance": "802200000000000000000"
		},
		"08b84536b74c8c01543da88b84d78bb95747d822": {
			"balance": "200000000000000000000"
		},
		"04a80afad53ef1f84165cfd852b0fdf1b1c24ba8": {
			"balance": "58000000000000000000"
		},
		"2b0362633614bfcb583569438ecc4ea57b1d337e": {
			"balance": "20000000000000000000000"
		},
		"e95179527deca5916ca9a38f215c1e9ce737b4c9": {
			"balance": "10000000000000000000000"
		},
		"2c5df866666a194b26cebb407e4a1fd73e208d5e": {
			"balance": "1000000000000000000000"
		},
		"529e824fa072582b4032683ac7eecc1c04b4cac1": {
			"balance": "2000000000000000000000"
		},
		"78634371e17304cbf339b1452a4ce438dc764cce": {
			"balance": "10000000000000000000000"
		},
		"e172dfc8f80cd1f8cd8539dc26082014f5a8e3e8": {
			"balance": "3000000000000000000000"
		},
		"b07618328a901307a1b7a0d058fcd5786e9e72fe": {
			"balance": "30239500000000000000000"
		},
		"b0571153db1c4ed7acaefe13ecdfdb72e7e4f06a": {
			"balance": "80520000000000000000000"
		},
		"ad910a23d6850613654af786337ad2a70868ac6d": {
			"balance": "1999800000000000000000"
		},
		"4da5edc688b0cb62e1403d1700d9dcb99ffe3fd3": {
			"balance": "2000000000000000000000"
		},
		"be2471a67f6047918772d0e36839255ed9d691ae": {
			"balance": "4000000000000000000000"
		},
		"28868324337e11ba106cb481da962f3a8453808d": {
			"balance": "2000000000000000000000"
		},
		"d8f94579496725b5cb53d7985c989749aff849c0": {
			"balance": "17000000000000000000000"
		},
		"4981c5ff66cc4e9680251fc4cd2ff907cb327865": {
			"balance": "750000000000000000000"
		},
		"fd2872d19e57853cfa16effe93d0b1d47b4f93fb": {
			"balance": "4000000000000000000000"
		},
		"63c8dfde0b8e01dadc2e748c824cc0369df090b3": {
			"balance": "3880000000000000000000"
		},
		"c4dd048bfb840e2bc85cb53fcb75abc443c7e90f": {
			"balance": "3716000000000000000000"
		},
		"f579714a45eb8f52c3d57bbdefd2c15b2e2f11df": {
			"balance": "1560000000000000000000"
		},
		"cc7b0481cc32e6faef2386a07022bcb6d2c3b4fc": {
			"balance": "3160000000000000000000"
		},
		"a0aa5f0201f04d3bbeb898132f7c11679466d901": {
			"balance": "36600000000000000000"
)E" + R"E(
		},
		"f3df63a97199933330383b3ed7570b96c4812334": {
			"balance": "2000000000000000000000"
		},
		"42732d8ef49ffda04b19780fd3c18469fb374106": {
			"balance": "425068000000000000000"
		},
		"6f92d6e4548c78996509ee684b2ee29ba3c532b4": {
			"balance": "1000000000000000000000"
		},
		"fff4bad596633479a2a29f9a8b3f78eefd07e6ee": {
			"balance": "100000000000000000000"
		},
		"ac4460a76e6db2b9fcd152d9c7718d9ac6ed8c6f": {
			"balance": "200000000000000000000"
		},
		"553b6b1c57050e88cf0c31067b8d4cd1ff80cb09": {
			"balance": "400000000000000000000"
		},
		"84b6b6adbe2f5b3e2d682c66af1bc4905340c3ed": {
			"balance": "619333000000000000000"
		},
		"9f4a7195ac7c151ca258cafda0cab083e049c602": {
			"balance": "1537100000000000000000"
		},
		"2955c357fd8f75d5159a3dfa69c5b87a359dea8c": {
			"balance": "2000000000000000000000"
		},
		"11d7844a471ef89a8d877555583ceebd1439ea26": {
			"balance": "10098000000000000000000"
		},
		"34b454416e9fb4274e6addf853428a0198d62ee1": {
			"balance": "407000000000000000000"
		},
		"308dd21cebe755126704b48c0f0dc234c60ba9b1": {
			"balance": "200000000000000000000"
		},
		"381db4c8465df446a4ce15bf81d47e2f17c980bf": {
			"balance": "32000000000000000000000"
		},
		"1abc4e253b080aeb437984ab05bca0979aa43e1c": {
			"balance": "1000000000000000000000"
		},
		"53e35b12231f19c3fd774c88fec8cbeedf1408b2": {
			"balance": "512000000000000000000"
		},
		"69e2e2e704307ccc5b5ca3f164fece2ea7b2e512": {
			"balance": "7000000000000000000000"
		},
		"1914f1eb95d1277e93b6e61b668b7d77f13a11a1": {
			"balance": "970000000000000000000"
		},
		"50e13023bd9ca96ad4c53fdfd410cb6b1f420bdf": {
			"balance": "200000000000000000000"
		},
		"46224f32f4ece5c8867090d4409d55e50b18432d": {
			"balance": "6000000000000000000000"
		},
		"ff83855051ee8ffb70b4817dba3211ed2355869d": {
			"balance": "400000000000000000000"
		},
		"fb39189af876e762c71d6c3e741893df226cedd6": {
			"balance": "4000000000000000000000"
		},
		"9875623495a46cdbf259530ff838a1799ec38991": {
			"balance": "2000000000000000000000"
		},
		"e1b39b88d9900dbc4a6cdc481e1060080a8aec3c": {
			"balance": "2000000000000000000000"
		},
		"5baf6d749620803e8348af3710e5c4fbf20fc894": {
			"balance": "5003680000000000000000"
		},
		"9c54e4ed479a856829c6bb42da9f0b692a75f728": {
			"balance": "7520000000000000000000"
		},
		"486a6c8583a84484e3df43a123837f8c7e2317d0": {
			"balance": "323378000000000000000"
		},
		"d235d15cb5eceebb61299e0e827fa82748911d89": {
			"balance": "4000000000000000000000"
		},
		"47d792a756779aedf1343e8883a6619c6c281184": {
			"balance": "2000000000000000000000"
		},
		"70c213488a020c3cfb39014ef5ba6404724bcaa3": {
			"balance": "1940000000000000000000"
		},
		"133c490fa5bf7f372888e607d958fab7f955bae1": {
			"balance": "1580000000000000000000"
		},
		"a9e194661aac704ee9dea043974e9692ded84a5d": {
			"balance": "482400000000000000000"
		},
		"bc6b58364bf7f1951c309e0cba0595201cd73f9a": {
			"balance": "1812400000000000000000"
		},
		"2309d34091445b3232590bd70f4f10025b2c9509": {
			"balance": "10000000000000000000000"
		},
)E" + R"E(
		"d89bc271b27ba3ab6962c94a559006ae38d5f56a": {
			"balance": "2000000000000000000000"
		},
		"ff0e2fec304207467e1e3307f64cbf30af8fd9cd": {
			"balance": "2000000000000000000000"
		},
		"c0b0b7a8a6e1acdd05e47f94c09688aa16c7ad8d": {
			"balance": "64234000000000000000"
		},
		"b66f92124b5e63035859e390628869dbdea9485e": {
			"balance": "9850000000000000000000"
		},
		"a9e6e25e656b762558619f147a21985b8874edfe": {
			"balance": "2000000000000000000000"
		},
		"a43e1947a9242b355561c30a829dfeeca2815af8": {
			"balance": "3878255000000000000000"
		},
		"8b20ad3b94656dbdc0dd21a393d8a7d9e02138cb": {
			"balance": "3000000000000000000000"
		},
		"aca2a838330b17302da731d30db48a04f0f207c1": {
			"balance": "1337000000000000000000"
		},
		"fa60868aafd4ff4c5c57914b8ed58b425773dfa9": {
			"balance": "8557400000000000000000"
		},
		"1848003c25bfd4aa90e7fcb5d7b16bcd0cffc0d8": {
			"balance": "1000000000000000000000"
		},
		"b4b185d943ee2b58631e33dff5af6854c17993ac": {
			"balance": "1000000000000000000000"
		},
		"7719888795ad745924c75760ddb1827dffd8cda8": {
			"balance": "1999980000000000000000"
		},
		"ccd521132d986cb96869842622a7dda26c3ed057": {
			"balance": "2000000000000000000000"
		},
		"253e32b74ea4490ab92606fda0aa257bf23dcb8b": {
			"balance": "10000000000000000000000"
		},
		"3712367e5e55a96d5a19168f6eb2bc7e9971f869": {
			"balance": "1000000000000000000000"
		},
		"8f29a14a845ad458f2d108b568d813166bcdf477": {
			"balance": "10000000000000000000000"
		},
		"51a8c2163602a32ee24cf4aa97fd9ea414516941": {
			"balance": "62904000000000000000"
		},
		"61cea71fa464d62a07063f920b0cc917539733d8": {
			"balance": "1670000000000000000000"
		},
		"6f81f3abb1f933b1df396b8e9cc723a89b7c9806": {
			"balance": "280000000000000000000"
		},
		"61b1b8c012cd4c78f698e470f90256e6a30f48dd": {
			"balance": "200000000000000000000"
		},
		"4f3f2c673069ac97c2023607152981f5cd6063a0": {
			"balance": "600000000000000000000"
		},
		"e2efa5fca79538ce6068bf31d2c516d4d53c08e5": {
			"balance": "131200000000000000000"
		},
		"2383c222e67e969190d3219ef14da37850e26c55": {
			"balance": "2000000000000000000000"
		},
		"eac3af5784927fe9a598fc4eec38b8102f37bc58": {
			"balance": "1000000000000000000000"
		},
		"4fe56ab3bae1b0a44433458333c4b05a248f8241": {
			"balance": "2180000000000000000000"
		},
		"fe9cfc3bb293ddb285e625f3582f74a6b0a5a6cd": {
			"balance": "1970000000000000000000"
		},
		"f48e1f13f6af4d84b371d7de4b273d03a263278e": {
			"balance": "600000000000000000000"
		},
		"1ba9228d388727f389150ea03b73c82de8eb2e09": {
			"balance": "7258000000000000000000"
		},
		"37a7a6ff4ea3d60ec307ca516a48d3053bb79cbb": {
			"balance": "2000000000000000000000"
		},
		"e33840d8bca7da98a6f3d096d83de78b70b71ef8": {
			"balance": "2000000000000000000000"
		},
		"8e7fd23848f4db07906a7d10c04b21803bb08227": {
			"balance": "1000000000000000000000"
		},
		"07d4334ec385e8aa54eedaeadb30022f0cdfa4ab": {
			"balance": "2629946000000000000000"
		},
		"d4b085fb086f3d0d68bf12926b1cc3142cae8770": {
			"balance": "3700000000000000000000"
		},
		"5a87f034e6f68f4e74ffe60c64819436036cf7d7": {
)E" + R"E(
			"balance": "20000000000000000000"
		},
		"c00ab080b643e1c2bae363e0d195de2efffc1c44": {
			"balance": "500000000000000000000"
		},
		"22f3c779dd79023ea92a78b65c1a1780f62d5c4a": {
			"balance": "1970000000000000000000"
		},
		"c7d5c7054081e918ec687b5ab36e973d18132935": {
			"balance": "182000000000000000000"
		},
		"9662ee021926682b31c5f200ce457abea76c6ce9": {
			"balance": "670500000000000000000"
		},
		"116a09df66cb150e97578e297fb06e13040c893c": {
			"balance": "2000000000000000000000"
		},
		"b7240af2af90b33c08ae9764103e35dce3638428": {
			"balance": "8464547000000000000000"
		},
		"e8b28acda971725769db8f563d28666d41ddab6c": {
			"balance": "10000000000000000000000"
		},
		"17d4918dfac15d77c47f9ed400a850190d64f151": {
			"balance": "2000000000000000000000"
		},
		"c42250b0fe42e6b7dcd5c890a6f0c88f5f5fb574": {
			"balance": "149800000000000000000"
		},
		"5da2a9a4c2c0a4a924cbe0a53ab9d0c627a1cfa0": {
			"balance": "733202000000000000000"
		},
		"5869fb867d71f1387f863b698d09fdfb87c49b5c": {
			"balance": "3666000000000000000000"
		},
		"d49a75bb933fca1fca9aa1303a64b6cb44ea30e1": {
			"balance": "10000000000000000000000"
		},
		"76331e30796ce664b2700e0d4153700edc869777": {
			"balance": "2000000000000000000000"
		},
		"8a5fb75793d043f1bcd43885e037bd30a528c927": {
			"balance": "356500000000000000000"
		},
		"fc0ee6f7c2b3714ae9916c45566605b656f32441": {
			"balance": "1760000000000000000000"
		},
		"bf50ce2e264b9fe2b06830617aedf502b2351b45": {
			"balance": "1000000000000000000000"
		},
		"0f6000de1578619320aba5e392706b131fb1de6f": {
			"balance": "499986000000000000000"
		},
		"c953f934c0eb2d0f144bdab00483fd8194865ce7": {
			"balance": "2000000000000000000000"
		},
		"24fd9a6c874c2fab3ff36e9afbf8ce0d32c7de92": {
			"balance": "1337000000000000000000"
		},
		"c6cd68ec35362c5ad84c82ad4edc232125912d99": {
			"balance": "27750000000000000000000"
		},
		"2a67660a1368efcd626ef36b2b1b601980941c05": {
			"balance": "133700000000000000000"
		},
		"9deb39027af877992b89f2ec4a1f822ecdf12693": {
			"balance": "2000000000000000000000"
		},
		"c12f881fa112b8199ecbc73ec4185790e614a20f": {
			"balance": "2000000000000000000000"
		},
		"d58a52e078a805596b0d56ea4ae1335af01c66eb": {
			"balance": "267400000000000000000"
		},
		"4d7cfaa84cb33106800a8c802fb8aa463896c599": {
			"balance": "1790000000000000000000"
		},
		"0ee391f03c765b11d69026fd1ab35395dc3802a0": {
			"balance": "200000000000000000000"
		},
		"a192f06ab052d5fd7f94eea8318e827815fe677a": {
			"balance": "131400000000000000000"
		},
		"8f0ab894bd3f4e697dbcfb859d497a9ba195994a": {
			"balance": "39501652000000000000000"
		},
		"387eeafd6b4009deaf8bd5b85a72983a8dcc3487": {
			"balance": "4000000000000000000000"
		},
		"03b0f17cd4469ddccfb7da697e82a91a5f9e7774": {
			"balance": "20000000000000000000"
		},
		"11172b278ddd44eea2fdf4cb1d16962391c453d9": {
			"balance": "935900000000000000000000"
		},
		"33d172ab075c51db1cd40a8ca8dbff0d93b843bb": {
			"balance": "5727139000000000000000"
		},
		"909b5e763a39dcc795223d73a1dbb7d94ca75ac8": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"0ca12ab0b9666cf0cec6671a15292f2653476ab2": {
			"balance": "210000600000000000000000"
		},
		"6b5ae7bf78ec75e90cb503c778ccd3b24b4f1aaf": {
			"balance": "800000000000000000000"
		},
		"d9e3857efd1e202a441770a777a49dcc45e2e0d3": {
			"balance": "223500000000000000000"
		},
		"d703c6a4f11d60194579d58c2766a7ef16c30a29": {
			"balance": "2000000000000000000000"
		},
		"838bd565f99fde48053f7917fe333cf84ad548ab": {
			"balance": "200000000000000000000"
		},
		"8168edce7f2961cf295b9fcd5a45c06cdeda6ef5": {
			"balance": "200000000000000000000"
		},
		"de50868eb7e3c71937ec73fa89dd8b9ee10d45aa": {
			"balance": "1000000000000000000000"
		},
		"087498c0464668f31150f4d3c4bcdda5221ba102": {
			"balance": "20000000000000000000"
		},
		"613fab44b16bbe554d44afd178ab1d02f37aeaa5": {
			"balance": "2000000000000000000000"
		},
		"e2ee691f237ee6529b6557f2fcdd3dcf0c59ec63": {
			"balance": "5450048000000000000000"
		},
		"a9ed377b7d6ec25971c1a597a3b0f3bead57c98f": {
			"balance": "400000000000000000000"
		},
		"175feeea2aa4e0efda12e1588d2f483290ede81a": {
			"balance": "200000000000000000000"
		},
		"b51ddcb4dd4e8ae6be336dd9654971d9fec86b41": {
			"balance": "421133000000000000000"
		},
		"92c0f573eccf62c54810ee6ba8d1f113542b301b": {
			"balance": "3384000000000000000000"
		},
		"a109e18bb0a39c9ef82fa19597fc5ed8e9eb6d58": {
			"balance": "1640000000000000000000"
		},
		"f74e6e145382b4db821fe0f2d98388f45609c69f": {
			"balance": "100000000000000000000"
		},
		"378f37243f3ff0bef5e1dc85eb4308d9340c29f9": {
			"balance": "2000200000000000000000"
		},
		"84e9949680bece6841b9a7e5250d08acd87d16cd": {
			"balance": "200000000000000000000"
		},
		"882bd3a2e9d74110b24961c53777f22f1f46dc5d": {
			"balance": "13370000000000000000000"
		},
		"acce01e0a70610dc70bb91e9926fa9957f372fba": {
			"balance": "537000000000000000000"
		},
		"c5f687717246da8a200d20e5e9bcac60b67f3861": {
			"balance": "28650000000000000000"
		},
		"e14617f6022501e97e7b3e2d8836aa61f0ff2dba": {
			"balance": "200000000000000000000"
		},
		"076ee99d3548623a03b5f99859d2d785a1778d48": {
			"balance": "200000000000000000000"
		},
		"2c424ee47f583cdce07ae318b6fad462381d4d2b": {
			"balance": "4000000000000000000000"
		},
		"f98250730c4c61c57f129835f2680894794542f3": {
			"balance": "4000000000000000000000"
		},
		"ed1b24b6912d51b334ac0de6e771c7c0454695ea": {
			"balance": "40000000000000000000"
		},
		"ffd5170fd1a8118d558e7511e364b24906c4f6b3": {
			"balance": "60085000000000000000"
		},
		"bf49c14898316567d8b709c2e50594b366c6d38c": {
			"balance": "733202000000000000000"
		},
		"65ea26eabbe2f64ccccfe06829c25d4637520225": {
			"balance": "700000000000000000000"
		},
		"5c5419565c3aad4e714e0739328e3521c98f05cc": {
			"balance": "528000000000000000000"
		},
		"c53b50fd3b2b72bc6c430baf194a515585d3986d": {
			"balance": "20000000000000000000"
		},
		"2b74c373d04bfb0fd60a18a01a88fbe84770e58c": {
			"balance": "40000000000000000000"
		},
		"d97f4526dea9b163f8e8e33a6bcf92fb907de6ec": {
			"balance": "284000000000000000000"
		},
)E" + R"E(
		"a4a49f0bc8688cc9e6dc04e1e08d521026e65574": {
			"balance": "200000000000000000000"
		},
		"575c00c2818210c28555a0ff29010289d3f82309": {
			"balance": "10000000000000000000000"
		},
		"3f1233714f204de9de4ee96d073b368d8197989f": {
			"balance": "38606000000000000000"
		},
		"f964d98d281730ba35b2e3a314796e7b42fedf67": {
			"balance": "1543800000000000000000"
		},
		"1deec01abe5c0d952de9106c3dc30639d85005d6": {
			"balance": "2000000000000000000000"
		},
		"12d60d65b7d9fc48840be5f891c745ce76ee501e": {
			"balance": "21359400000000000000000"
		},
		"5c6136e218de0a61a137b2b3962d2a6112b809d7": {
			"balance": "294273000000000000000"
		},
		"cd43258b7392a930839a51b2ef8ad23412f75a9f": {
			"balance": "2000000000000000000000"
		},
		"db3f258ab2a3c2cf339c4499f75a4bd1d3472e9e": {
			"balance": "1500000000000000000000"
		},
		"0edd4b580ff10fe06c4a03116239ef96622bae35": {
			"balance": "197000000000000000000"
		},
		"1d157c5876c5cad553c912caf6ce2d5277e05c73": {
			"balance": "2000000000000000000000"
		},
		"cda1b886e3a795c9ba77914e0a2fe5676f0f5ccf": {
			"balance": "106024000000000000000"
		},
		"f50cbafd397edd556c0678988cb2af5c2617e0a2": {
			"balance": "716000000000000000000"
		},
		"327bb49e754f6fb4f733c6e06f3989b4f65d4bee": {
			"balance": "20000000000000000000"
		},
		"c44bdec8c36c5c68baa2ddf1d431693229726c43": {
			"balance": "100000000000000000000000"
		},
		"34e2849bea583ab0cc37975190f322b395055582": {
			"balance": "7780340000000000000000"
		},
		"9221c9ce01232665741096ac07235903ad1fe2fc": {
			"balance": "126489000000000000000"
		},
		"ff3ded7a40d3aff0d7a8c45fa6136aa0433db457": {
			"balance": "1999800000000000000000"
		},
		"10b5b34d1248fcf017f8c8ffc408ce899ceef92f": {
			"balance": "267400000000000000000"
		},
		"f1a1f320407964fd3c8f2e2cc8a4580da94f01ea": {
			"balance": "2000040000000000000000"
		},
		"6c800d4b49ba07250460f993b8cbe00b266a2553": {
			"balance": "492500000000000000000"
		},
		"f827d56ed2d32720d4abf103d6d0ef4d3bcd559b": {
			"balance": "26265000000000000000"
		},
		"ffb9c7217e66743031eb377af65c77db7359dcda": {
			"balance": "40000000000000000000"
		},
		"530319db0a8f93e5bb7d4dbf4816314fbed8361b": {
			"balance": "2000000000000000000000"
		},
		"9c28a2c4086091cb5da226a657ce3248e8ea7b6f": {
			"balance": "280000000000000000000"
		},
		"db23a6fef1af7b581e772cf91882deb2516fc0a7": {
			"balance": "200000000000000000000"
		},
		"6636d7ac637a48f61d38b14cfd4865d36d142805": {
			"balance": "500000000000000000000"
		},
		"b3c260609b9df4095e6c5dff398eeb5e2df49985": {
			"balance": "254030000000000000000"
		},
		"58e5c9e344c806650dacfc904d33edba5107b0de": {
			"balance": "19100000000000000000"
		},
		"4f67396d2553f998785f704e07a639197dd1948d": {
			"balance": "300080000000000000000"
		},
		"510d8159cc945768c7450790ba073ec0d9f89e30": {
			"balance": "2560000000000000000000"
		},
		"593c48935beaff0fde19b04d309cd530a28e52ce": {
			"balance": "4000000000000000000000"
		},
		"c27f4e08099d8cf39ee11601838ef9fc06d7fc41": {
			"balance": "1790000000000000000000"
		},
		"07723e3c30e8b731ee456a291ee0e798b0204a77": {
)E" + R"E(
			"balance": "2000000000000000000000"
		},
		"0a652e2a8b77bd97a790d0e91361c98890dbb04e": {
			"balance": "1000000000000000000000"
		},
		"671015b97670b10d5e583f3d62a61c1c79c5143f": {
			"balance": "400000000000000000000"
		},
		"7cc24a6a958c20c7d1249660f7586226950b0d9a": {
			"balance": "1970000000000000000000"
		},
		"6ef9e8c9b6217d56769af97dbb1c8e1b8be799d2": {
			"balance": "182000000000000000000"
		},
		"5c4368918ace6409c79eca80cdaae4391d2b624e": {
			"balance": "4000000000000000000000"
		},
		"043707071e2ae21eed977891dc79cd5d8ee1c2da": {
			"balance": "2000000000000000000000"
		},
		"39bfd978689bec048fc776aa15247f5e1d7c39a2": {
			"balance": "20000000000000000000000"
		},
		"05915d4e225a668162aee7d6c25fcfc6ed18db03": {
			"balance": "66348000000000000000"
		},
		"3f551ba93cd54693c183fb9ad60d65e1609673c9": {
			"balance": "2000000000000000000000"
		},
		"a8c0b02faf02cb5519dda884de7bbc8c88a2da81": {
			"balance": "16700000000000000000"
		},
		"bd0c5cd799ebc48642ef97d74e8e429064fee492": {
			"balance": "326000000000000000000"
		},
		"0a931b449ea8f12cdbd5e2c8cc76bad2c27c0639": {
			"balance": "23031000000000000000"
		},
		"2ea5fee63f337a376e4b918ea82148f94d48a626": {
			"balance": "1864242000000000000000"
		},
		"cc6c2df00e86eca40f21ffda1a67a1690f477c65": {
			"balance": "3160000000000000000000"
		},
		"e5e37e19408f2cfbec83349dd48153a4a795a08f": {
			"balance": "4200000000000000000000"
		},
		"f555a27bb1e2fd4e2cc784caee92939fc06e2fc9": {
			"balance": "2000000000000000000000"
		},
		"dcf9719be87c6f46756db4891db9b611d2469c50": {
			"balance": "1000000000000000000000"
		},
		"8e2f9034c9254719c38e50c9aa64305ed696df1e": {
			"balance": "4728000000000000000000"
		},
		"a01f12d70f44aa7b113b285c22dcdb45873454a7": {
			"balance": "18200000000000000000"
		},
		"bce40475d345b0712dee703d87cd7657fc7f3b62": {
			"balance": "7750000000000000000000"
		},
		"bb19bf91cbad74cceb5f811db27e411bc2ea0656": {
			"balance": "17600000000000000000"
		},
		"acc062702c59615d3444ef6214b8862b009a02ed": {
			"balance": "1499936000000000000000"
		},
		"449ac4fbe383e36738855e364a57f471b2bfa131": {
			"balance": "197000000000000000000000"
		},
		"ad59a78eb9a74a7fbdaefafa82eada8475f07f95": {
			"balance": "500000000000000000000"
		},
		"6b6577f3909a4d6de0f411522d4570386400345c": {
			"balance": "1880000000000000000000"
		},
		"79bf2f7b6e328aaf26e0bb093fa22da29ef2f471": {
			"balance": "1790000000000000000000"
		},
		"940f715140509ffabf974546fab39022a41952d2": {
			"balance": "1400000000000000000000"
		},
		"1d572edd2d87ca271a6714c15a3b37761dcca005": {
			"balance": "127674000000000000000"
		},
		"d78ecd25adc86bc2051d96f65364866b42a426b7": {
			"balance": "3877300000000000000000"
		},
		"f9729d48282c9e87166d5eef2d01eda9dbf78821": {
			"balance": "99981000000000000000"
		},
		"17762560e82a93b3f522e0e524adb8612c3a7470": {
			"balance": "1000000000000000000000"
		},
		"d500e4d1c9824ba9f5b635cfa3a8c2c38bbd4ced": {
			"balance": "400000000000000000000"
		},
		"a11effab6cf0f5972cffe4d56596e98968144a8f": {
			"balance": "1670000000000000000000"
)E" + R"E(
		},
		"f64ecf2117931c6d535a311e4ffeaef9d49405b8": {
			"balance": "2674000000000000000000"
		},
		"229cc4711b62755ea296445ac3b77fc633821cf2": {
			"balance": "39481000000000000000"
		},
		"fc989cb487bf1a7d17e4c1b7c4b7aafdda6b0a8d": {
			"balance": "20000000000000000000"
		},
		"ea8527febfa1ade29e26419329d393b940bbb7dc": {
			"balance": "1999944000000000000000"
		},
		"bce13e22322acfb355cd21fd0df60cf93add26c6": {
			"balance": "200000000000000000000"
		},
		"19ff244fcfe3d4fa2f4fd99f87e55bb315b81eb6": {
			"balance": "200000000000000000000"
		},
		"d2581a55ce23ab10d8ad8c44378f59079bd6f658": {
			"balance": "8800000000000000000000"
		},
		"4073fa49b87117cb908cf1ab512da754a932d477": {
			"balance": "1970000000000000000000"
		},
		"b6a82933c9eadabd981e5d6d60a6818ff806e36b": {
			"balance": "400000000000000000000"
		},
		"c79806032bc7d828f19ac6a640c68e3d820fa442": {
			"balance": "20000000000000000000"
		},
		"577b2d073c590c50306f5b1195a4b2ba9ecda625": {
			"balance": "373600000000000000000"
		},
		"7f13d760498d7193ca6859bc95c901386423d76c": {
			"balance": "5000000000000000000000"
		},
		"416784af609630b070d49a8bcd12235c6428a408": {
			"balance": "20000000000000000000000"
		},
		"fbe71622bcbd31c1a36976e7e5f670c07ffe16de": {
			"balance": "400000000000000000000"
		},
		"a5698035391e67a49013c0002079593114feb353": {
			"balance": "240000000000000000000"
		},
		"ab2871e507c7be3965498e8fb462025a1a1c4264": {
			"balance": "775000000000000000000"
		},
		"9c78fbb4df769ce2c156920cfedfda033a0e254a": {
			"balance": "1970000000000000000000"
		},
		"95e6f93dac228bc7585a25735ac2d076cc3a4017": {
			"balance": "6000000000000000000000"
		},
		"3c1f91f301f4b565bca24751aa1f761322709ddd": {
			"balance": "1790000000000000000000"
		},
		"f77f9587ff7a2d7295f1f571c886bd33926a527c": {
			"balance": "1999800000000000000000"
		},
		"755f587e5efff773a220726a13d0f2130d9f896b": {
			"balance": "1000000000000000000000"
		},
		"8c6aa882ee322ca848578c06cb0fa911d3608305": {
			"balance": "600000000000000000000"
		},
		"492cb5f861b187f9df21cd4485bed90b50ffe22d": {
			"balance": "499928000000000000000"
		},
		"95a577dc2eb3ae6cb9dfc77af697d7efdfe89a01": {
			"balance": "136000000000000000000"
		},
		"4173419d5c9f6329551dc4d3d0ceac1b701b869e": {
			"balance": "88000000000000000000"
		},
		"456ae0aca48ebcfae166060250525f63965e760f": {
			"balance": "300000000000000000000"
		},
		"81f8de2c283d5fd4afbda85dedf9760eabbbb572": {
			"balance": "3000000000000000000000"
		},
		"cd0af3474e22f069ec3407870dd770443d5b12b0": {
			"balance": "2626262000000000000000"
		},
		"283c2314283c92d4b064f0aef9bb5246a7007f39": {
			"balance": "200000000000000000000"
		},
		"29b3f561ee7a6e25941e98a5325b78adc79785f3": {
			"balance": "100000000000000000000"
		},
		"cd4306d7f6947ac1744d4e13b8ef32cb657e1c00": {
			"balance": "499986000000000000000"
		},
		"d9ec2efe99ff5cf00d03a8317b92a24aef441f7e": {
			"balance": "2000000000000000000000"
		},
		"83dbf8a12853b40ac61996f8bf1dc8fdbaddd329": {
			"balance": "970000000000000000000"
		},
)E" + R"E(
		"9d93fab6e22845f8f45a07496f11de71530debc7": {
			"balance": "1998000000000000000000"
		},
		"fd204f4f4aba2525ba728afdf78792cbdeb735ae": {
			"balance": "2000000000000000000000"
		},
		"99fad50038d0d9d4c3fbb4bce05606ecadcd5121": {
			"balance": "2000000000000000000000"
		},
		"d206aaddb336d45e7972e93cb075471d15897b5d": {
			"balance": "600000000000000000000"
		},
		"428a1ee0ed331d7952ccbe1c7974b2852bd1938a": {
			"balance": "2208370000000000000000"
		},
		"690228e4bb12a8d4b5e0a797b0c5cf2a7509131e": {
			"balance": "1880000000000000000000"
		},
		"fa3a1aa4488b351aa7560cf5ee630a2fd45c3222": {
			"balance": "878850000000000000000"
		},
		"0372e852582e0934344a0fed2178304df25d4628": {
			"balance": "20000000000000000000000"
		},
		"35ea2163a38cdf9a123f82a5ec00258dae0bc767": {
			"balance": "4000000000000000000000"
		},
		"d1fed0aee6f5dfd7e25769254c3cfad15adeccaa": {
			"balance": "730000000000000000000"
		},
		"c05b740620f173f16e52471dc38b9c514a0b1526": {
			"balance": "140000000000000000000"
		},
		"87e3062b2321e9dfb0875ce3849c9b2e3522d50a": {
			"balance": "10000000000000000000000"
		},
		"303fbaebbe46b35b6e5b74946a5f99bc1585cae7": {
			"balance": "878148000000000000000"
		},
		"e7a8e471eafb798f4554cc6e526730fd56e62c7d": {
			"balance": "1000000000000000000000"
		},
		"ad7dd053859edff1cb6f9d2acbed6dd5e332426f": {
			"balance": "1970000000000000000000"
		},
		"dc4345d6812e870ae90c568c67d2c567cfb4f03c": {
			"balance": "6700000000000000000000"
		},
		"a6a08252c8595177cc2e60fc27593e2379c81fb1": {
			"balance": "20055000000000000000"
		},
		"a9af21acbe482f8131896a228036ba51b19453c3": {
			"balance": "49999000000000000000"
		},
		"86e3fe86e93da486b14266eadf056cbfa4d91443": {
			"balance": "2000000000000000000000"
		},
		"744b03bba8582ae5498e2dc22d19949467ab53fc": {
			"balance": "500000000000000000000"
		},
		"d3118ea3c83505a9d893bb67e2de142d537a3ee7": {
			"balance": "20000000000000000000"
		},
		"b32f1c2689a5ce79f1bc970b31584f1bcf2283e7": {
			"balance": "20000000000000000000"
		},
		"4828e4cbe34e1510afb72c2beeac8a4513eaebd9": {
			"balance": "3940000000000000000000"
		},
		"b07bcc085ab3f729f24400416837b69936ba8873": {
			"balance": "2000140000000000000000"
		},
		"bdc74873af922b9df474853b0fa7ff0bf8c82695": {
			"balance": "3999000000000000000000"
		},
		"15ebd1c7cad2aff19275c657c4d808d010efa0f5": {
			"balance": "200550000000000000000"
		},
		"cbc04b4d8b82caf670996f160c362940d66fcf1a": {
			"balance": "6000000000000000000000"
		},
		"8197948121732e63d9c148194ecad46e30b749c8": {
			"balance": "4000000000000000000000"
		},
		"69797bfb12c9bed682b91fbc593591d5e4023728": {
			"balance": "10000000000000000000000"
		},
		"be9b8c34b78ee947ff81472eda7af9d204bc8466": {
			"balance": "150000000000000000000"
		},
		"df3f57b8ee6434d047223def74b20f63f9e4f955": {
			"balance": "250500000000000000000"
		},
		"a3ae1879007d801cb5f352716a4dd8ba2721de3d": {
			"balance": "200000000000000000000000"
		},
		"cb4bb1c623ba28dc42bdaaa6e74e1d2aa1256c2a": {
			"balance": "1999944000000000000000"
		},
		"e03c00d00388ecbf4f263d0ac778bb41a57a40d9": {
)E" + R"E(
			"balance": "1000072000000000000000"
		},
		"fc2c1f88961d019c3e9ea33009152e0693fbf88a": {
			"balance": "8000000000000000000000"
		},
		"8599cbd5a6a9dcd4b966be387d69775da5e33c6f": {
			"balance": "58180000000000000000000"
		},
		"b7a31a7c38f3db09322eae11d2272141ea229902": {
			"balance": "2000000000000000000000"
		},
		"231a15acc199c89fa9cb22441cc70330bdcce617": {
			"balance": "500000000000000000000"
		},
		"3fbed6e7e0ca9c84fbe9ebcf9d4ef9bb49428165": {
			"balance": "2000000000000000000000"
		},
		"92cfd60188efdfb2f8c2e7b1698abb9526c1511f": {
			"balance": "2000000000000000000000"
		},
		"5c936f3b9d22c403db5e730ff177d74eef42dbbf": {
			"balance": "75000000000000000000"
		},
		"931fe712f64207a2fd5022728843548bfb8cbb05": {
			"balance": "2000000000000000000000"
		},
		"08d54e83ad486a934cfaeae283a33efd227c0e99": {
			"balance": "1039000000000000000000"
		},
		"a339a3d8ca280e27d2415b26d1fc793228b66043": {
			"balance": "1013600000000000000000"
		},
		"581f34b523e5b41c09c87c298e299cbc0e29d066": {
			"balance": "1131607000000000000000"
		},
		"caaa68ee6cdf0d34454a769b0da148a1faaa1865": {
			"balance": "7216000000000000000000"
		},
		"0838a7768d9c2aca8ba279adfee4b1f491e326f1": {
			"balance": "200000000000000000000"
		},
		"dde77a4740ba08e7f73fbe3a1674912931742eeb": {
			"balance": "19867021000000000000000"
		},
		"cbe810fe0fecc964474a1db97728bc87e973fcbd": {
			"balance": "10000000000000000000000"
		},
		"86c28b5678af37d727ec05e4447790f15f71f2ea": {
			"balance": "200000000000000000000"
		},
		"dd6c062193eac23d2fdbf997d5063a346bb3b470": {
			"balance": "20000000000000000000"
		},
		"5975b9528f23af1f0e2ec08ac8ebaa786a2cb8e0": {
			"balance": "345827000000000000000"
		},
		"e29d8ae452dcf3b6ac645e630409385551faae0a": {
			"balance": "80276000000000000000"
		},
		"2fbc85798a583598b522166d6e9dda121d627dbc": {
			"balance": "200000000000000000000"
		},
		"7a36aba5c31ea0ca7e277baa32ec46ce93cf7506": {
			"balance": "20000000000000000000000"
		},
		"dbcbcd7a57ea9db2349b878af34b1ad642a7f1d1": {
			"balance": "200000000000000000000"
		},
		"92aae59768eddff83cfe60bb512e730a05a161d7": {
			"balance": "1708015000000000000000"
		},
		"a5e93b49ea7c509de7c44d6cfeddef5910deaaf2": {
			"balance": "2000000000000000000000"
		},
		"e33d980220fab259af6a1f4b38cf0ef3c6e2ea1a": {
			"balance": "2000000000000000000000"
		},
		"8ed0af11ff2870da0681004afe18b013f7bd3882": {
			"balance": "4000000000000000000000"
		},
		"f23e5c633221a8f7363e65870c9f287424d2a960": {
			"balance": "1380000000000000000000"
		},
		"96334bfe04fffa590213eab36514f338b864b736": {
			"balance": "400000000000000000000"
		},
		"fa1f1971a775c3504fef5079f640c2c4bce7ac05": {
			"balance": "2000000000000000000000"
		},
		"df44c47fc303ac76e74f97194cca67b5bb3c023f": {
			"balance": "591000000000000000000"
		},
		"4b74f5e58e2edf76daf70151964a0b8f1de0663c": {
			"balance": "324020000000000000000"
		},
		"e38b91b35190b6d9deed021c30af094b953fdcaa": {
			"balance": "33340000000000000000"
		},
		"6b38de841fad7f53fe02da115bd86aaf662466bd": {
			"balance": "1730000000000000000000"
)E" + R"E(
		},
		"11675a25554607a3b6c92a9ee8f36f75edd3e336": {
			"balance": "159800000000000000000"
		},
		"0ba8705bf55cf219c0956b5e3fc01c4474a6cdc1": {
			"balance": "94963000000000000000"
		},
		"0f05f120c89e9fbc93d4ab0c5e2b4a0df092b424": {
			"balance": "30000000000000000000000"
		},
		"fdd1195f797d4f35717d15e6f9810a9a3ff55460": {
			"balance": "18200000000000000000"
		},
		"63a61dc30a8e3b30a763c4213c801cbf98738178": {
			"balance": "1000000000000000000000"
		},
		"e5bdf34f4ccc483e4ca530cc7cf2bb18febe92b3": {
			"balance": "126260000000000000000"
		},
		"d6e09e98fe1300332104c1ca34fbfac554364ed9": {
			"balance": "2000000000000000000000"
		},
		"5bd6862d517d4de4559d4eec0a06cad05e2f946e": {
			"balance": "200000000000000000000"
		},
		"7294ec9da310bc6b4bbdf543b0ef45abfc3e1b4d": {
			"balance": "22000000000000000000000"
		},
		"ae34861d342253194ffc6652dfde51ab44cad3fe": {
			"balance": "466215000000000000000"
		},
		"f50ae7fab4cfb5a646ee04ceadf9bf9dd5a8e540": {
			"balance": "3999952000000000000000"
		},
		"dd2bdfa917c1f310e6fa35aa8af16939c233cd7d": {
			"balance": "400000000000000000000"
		},
		"e0060462c47ff9679baef07159cae08c29f274a9": {
			"balance": "2000000000000000000000"
		},
		"b7d12e84a2e4c4a6345af1dd1da9f2504a2a996e": {
			"balance": "200000000000000000000"
		},
		"f5500178cb998f126417831a08c2d7abfff6ab5f": {
			"balance": "1308923000000000000000"
		},
		"fd377a385272900cb436a3bb7962cdffe93f5dad": {
			"balance": "2000000000000000000000"
		},
		"a4a83a0738799b971bf2de708c2ebf911ca79eb2": {
			"balance": "600000000000000000000"
		},
		"52a5e4de4393eeccf0581ac11b52c683c76ea15d": {
			"balance": "19999800000000000000000"
		},
		"b07fdeaff91d4460fe6cd0e8a1b0bd8d22a62e87": {
			"balance": "5260000000000000000000"
		},
		"35f5860149e4bbc04b8ac5b272be55ad1aca58e0": {
			"balance": "200000000000000000000"
		},
		"fb135eb15a8bac72b69915342a60bbc06b7e077c": {
			"balance": "20000000000000000000000"
		},
		"02d4a30968a39e2b3498c3a6a4ed45c1c6646822": {
			"balance": "2000000000000000000000"
		},
		"e44b7264dd836bee8e87970340ed2b9aed8ed0a5": {
			"balance": "5772100000000000000000"
		},
		"e90a354cec04d69e5d96ddc0c5138d3d33150aa0": {
			"balance": "499971000000000000000"
		},
		"693d83be09459ef8390b2e30d7f7c28de4b4284e": {
			"balance": "2000000000000000000000"
		},
		"87bf7cd5d8a929e1c785f9e5449106ac232463c9": {
			"balance": "77800000000000000000"
		},
		"e5f8ef6d970636b0dcaa4f200ffdc9e75af1741c": {
			"balance": "2000000000000000000000"
		},
		"fef09d70243f39ed8cd800bf9651479e8f4aca3c": {
			"balance": "200000000000000000000"
		},
		"e98c91cadd924c92579e11b41217b282956cdaa1": {
			"balance": "135800000000000000000"
		},
		"c2836188d9a29253e0cbda6571b058c289a0bb32": {
			"balance": "2000000000000000000000"
		},
		"afa6946effd5ff53154f82010253df47ae280ccc": {
			"balance": "1970000000000000000000"
		},
		"43c7ebc5b3e7af16f47dc5617ab10e0f39b4afbb": {
			"balance": "1910000000000000000000"
		},
		"097ecda22567c2d91cb03f8c5215c22e9dcda949": {
			"balance": "20055000000000000000"
		},
)E" + R"E(
		"3e66b84769566ab67945d5fa81373556bcc3a1fa": {
			"balance": "152000000000000000000"
		},
		"56373daab46316fd7e1576c61e6affcb6559ddd7": {
			"balance": "215340000000000000000"
		},
		"faaeba8fc0bbda553ca72e30ef3d732e26e82041": {
			"balance": "1338337000000000000000"
		},
		"f54c19d9ef3873bfd1f7a622d02d86249a328f06": {
			"balance": "44284729000000000000000"
		},
		"825309a7d45d1812f51e6e8df5a7b96f6c908887": {
			"balance": "2365000000000000000000"
		},
		"89009e3c6488bd5e570d1da34eabe28ed024de1b": {
			"balance": "20000000000000000000000"
		},
		"63977cad7d0dcdc52b9ac9f2ffa136e8642882b8": {
			"balance": "75000000000000000000"
		},
		"c239abdfae3e9af5457f52ed2b91fd0ab4d9c700": {
			"balance": "2000000000000000000000"
		},
		"1a4ec6a0ae7f5a9427d23db9724c0d0cffb2ab2f": {
			"balance": "179000000000000000000"
		},
		"a12a6c2d985daf0e4f5f207ae851aaf729b332cd": {
			"balance": "100000000000000000000000"
		},
		"cbe52fc533d7dd608c92a260b37c3f45deb4eb33": {
			"balance": "1000000000000000000000"
		},
		"abb2e6a72a40ba6ed908cdbcec3c5612583132fe": {
			"balance": "1460000000000000000000"
		},
		"6503860b191008c15583bfc88158099301762828": {
			"balance": "1000000000000000000000"
		},
		"a0228240f99e1de9cb32d82c0f2fa9a3d44b0bf3": {
			"balance": "1600000000000000000000"
		},
		"e154daeadb545838cbc6aa0c55751902f528682a": {
			"balance": "4925000000000000000000"
		},
		"8e92aba38e72a098170b92959246537a2e5556c0": {
			"balance": "267400000000000000000"
		},
		"d23d7affacdc3e9f3dae7afcb4006f58f8a44600": {
			"balance": "3600000000000000000000"
		},
		"00d78d89b35f472716eceafebf600527d3a1f969": {
			"balance": "27750000000000000000000"
		},
		"120f9de6e0af7ec02a07c609ca8447f157e6344c": {
			"balance": "267400000000000000000"
		},
		"e0352fdf819ba265f14c06a6315c4ac1fe131b2e": {
			"balance": "1000000000000000000000"
		},
		"8f47328ee03201c9d35ed2b5412b25decc859362": {
			"balance": "2000000000000000000000"
		},
		"453e359a3397944c5a275ab1a2f70a5e5a3f6989": {
			"balance": "240000000000000000000"
		},
		"9bf58efbea0784eb068adecfa0bb215084c73a35": {
			"balance": "5800000000000000000000"
		},
		"21bfe1b45cacde6274fd8608d9a178bf3eeb6edc": {
			"balance": "2009400000000000000000"
		},
		"d1d5b17ffe2d7bbb79cc7d7930bcb2e518fb1bbf": {
			"balance": "3000000000000000000000"
		},
		"20a29c5079e26b3f18318bb2e50e8e8b346e5be8": {
			"balance": "499986000000000000000"
		},
		"7d392852f3abd92ff4bb5bb26cb60874f2be6795": {
			"balance": "1000070000000000000000"
		},
		"55852943492970f8d629a15366cdda06a94f4513": {
			"balance": "2000000000000000000000"
		},
		"ab5dfc1ea21adc42cf8c3f6e361e243fd0da61e5": {
			"balance": "300000000000000000000"
		},
		"9d2bfc36106f038250c01801685785b16c86c60d": {
			"balance": "380000000000000000000000"
		},
		"6e60aee1a78f8eda8b424c73e353354ae67c3042": {
			"balance": "3490300000000000000000"
		},
		"7e29290038493559194e946d4e460b96fc38a156": {
			"balance": "309072000000000000000"
		},
		"6006e36d929bf45d8f16231b126a011ae283d925": {
			"balance": "176000000000000000000"
		},
		"d6d03572a45245dbd4368c4f82c95714bd2167e2": {
)E" + R"E(
			"balance": "1162200000000000000000"
		},
		"d1432538e35b7664956ae495a32abdf041a7a21c": {
			"balance": "19700000000000000000000"
		},
		"2276264bec8526c0c0f270677abaf4f0e441e167": {
			"balance": "1000000000000000000000"
		},
		"c8814e34523e38e1f927a7dce8466a447a093603": {
			"balance": "10000000000000000000000"
		},
		"688a569e965524eb1d0ac3d3733eab909fb3d61e": {
			"balance": "1320000000000000000000"
		},
		"90dc09f717fc2a5b69fd60ba08ebf40bf4e8246c": {
			"balance": "4000086000000000000000"
		},
		"239a733e6b855ac592d663156186a8a174d2449e": {
			"balance": "1637020000000000000000"
		},
		"bcdfacb9d9023c3417182e9100e8ea1d373393a3": {
			"balance": "59100000000000000000"
		},
		"ba6440aeb3737b8ef0f1af9b0c15f4c214ffc7cf": {
			"balance": "1000000000000000000000"
		},
		"322e5c43b0f524389655a9b3ff24f2d4db3da10f": {
			"balance": "4650000000000000000000"
		},
		"be5a60689998639ad75bc105a371743eef0f7940": {
			"balance": "501700000000000000000"
		},
		"b727a9fc82e1cffc5c175fa1485a9befa2cdbdd1": {
			"balance": "999000000000000000000"
		},
		"a3883a24f7f166205f1a6a9949076c26a76e7178": {
			"balance": "1820000000000000000000"
		},
		"5e95fe5ffcf998f9f9ac0e9a81dab83ead77003d": {
			"balance": "539766000000000000000"
		},
		"e60955dc0bc156f6c41849f6bd776ba44b0ef0a1": {
			"balance": "299982000000000000000"
		},
		"af203e229d7e6d419df4378ea98715515f631485": {
			"balance": "1970000000000000000000"
		},
		"86499a1228ff2d7ee307759364506f8e8c8307a5": {
			"balance": "1970000000000000000000"
		},
		"1a04cec420ad432215246d77fe178d339ed0b595": {
			"balance": "316000000000000000000"
		},
		"cc2b5f448f3528d3fe41cc7d1fa9c0dc76f1b776": {
			"balance": "60000000000000000000"
		},
		"cb50587412822304ebcba07dab3a0f09fffee486": {
			"balance": "1370000000000000000000"
		},
		"4ae2a04d3909ef454e544ccfd614bfefa71089ae": {
			"balance": "442800000000000000000"
		},
		"c8a2c4e59e1c7fc54805580438aed3e44afdf00e": {
			"balance": "44000000000000000000"
		},
		"5792814f59a33a1843faa01baa089eb02ffb5cf1": {
			"balance": "499986000000000000000"
		},
		"a1f2854050f872658ed82e52b0ad7bbc1cb921f6": {
			"balance": "2010918000000000000000"
		},
		"92dca5e102b3b81b60f1a504634947c374a88ccb": {
			"balance": "2000000000000000000000"
		},
		"732fead60f7bfdd6a9dec48125e3735db1b6654f": {
			"balance": "20000000000000000000"
		},
		"6bf7b3c065f2c1e7c6eb092ba0d15066f393d1b8": {
			"balance": "400000000000000000000"
		},
		"cde36d81d128c59da145652193eec2bfd96586ef": {
			"balance": "4000000000000000000000"
		},
		"40eddb448d690ed72e05c225d34fc8350fa1e4c5": {
			"balance": "7000000000000000000000"
		},
		"454b61b344c0ef965179238155f277c3829d0b38": {
			"balance": "2000000000000000000000"
		},
		"ac3da526cfce88297302f34c49ca520dc271f9b2": {
			"balance": "800000000000000000000"
		},
		"c989eec307e8839b9d7237cfda08822962abe487": {
			"balance": "400000000000000000000"
		},
		"e99de258a4173ce9ac38ede26c0b3bea3c0973d5": {
			"balance": "1656800000000000000000"
		},
		"ff0cb06c42e3d88948e45bd7b0d4e291aefeea51": {
			"balance": "1910000000000000000000"
)E" + R"E(
		},
		"0990e81cd785599ea236bd1966cf526302c35b9c": {
			"balance": "1000000000000000000000"
		},
		"6da0ed8f1d69339f059f2a0e02471cb44fb8c3bb": {
			"balance": "935900000000000000000"
		},
		"5d958a9bd189c2985f86c58a8c69a7a78806e8da": {
			"balance": "10200000000000000000000"
		},
		"98be696d51e390ff1c501b8a0f6331b628ddc5ad": {
			"balance": "2000000000000000000000"
		},
		"09d0b8cd077c69d9f32d9cca43b3c208a21ed48b": {
			"balance": "150011000000000000000"
		},
		"96e7c0c9d5bf10821bf140c558a145b7cac21397": {
			"balance": "1056000000000000000000"
		},
		"5b736eb18353629bde9676dadd165034ce5ecc68": {
			"balance": "1970000000000000000000"
		},
		"e5a365343cc4eb1e770368e1f1144a77b832d7e0": {
			"balance": "20000000000000000000"
		},
		"4cf5537b85842f89cfee359eae500fc449d2118f": {
			"balance": "1000000000000000000000"
		},
		"c71f1d75873f33dcb2dd4b3987a12d0791a5ce27": {
			"balance": "1015200000000000000000"
		},
		"9bf703b41c3624e15f4054962390bcba3052f0fd": {
			"balance": "6055000000000000000000"
		},
		"145e1de0147911ccd880875fbbea61f6a142d11d": {
			"balance": "4000000000000000000000"
		},
		"68419c6dd2d3ce6fcbb3c73e2fa079f06051bde6": {
			"balance": "1970000000000000000000"
		},
		"d8eb78503ec31a54a90136781ae109004c743257": {
			"balance": "1000000000000000000000"
		},
		"f25e4c70bc465632c89e5625a832a7722f6bffab": {
			"balance": "4488000000000000000000"
		},
		"7b4d2a38269069c18557770d591d24c5121f5e83": {
			"balance": "700000000000000000000"
		},
		"27d158ac3d3e1109ab6e570e90e85d3892cd7680": {
			"balance": "100000000000000000000"
		},
		"d3679a47df2d99a49b01c98d1c3e0c987ce1e158": {
			"balance": "280000000000000000000"
		},
		"095b949de3333a377d5019d893754a5e4656ff97": {
			"balance": "340000000000000000000"
		},
		"6b17598a8ef54f797ae515ccb6517d1859bf8011": {
			"balance": "100000000000000000000"
		},
		"3eaf0879b5b6db159b589f84578b6a74f6c10357": {
			"balance": "7253657000000000000000"
		},
		"40d45d9d7625d15156c932b771ca7b0527130958": {
			"balance": "100000000000000000000000"
		},
		"0392549a727f81655429cb928b529f25df4d1385": {
			"balance": "26248000000000000000"
		},
		"c5b009baeaf788a276bd35813ad65b400b849f3b": {
			"balance": "1000000000000000000000"
		},
		"6ed884459f809dfa1016e770edaf3e9fef46fa30": {
			"balance": "3400170000000000000000"
		},
		"439d2f2f5110a4d58b1757935015408740fec7f8": {
			"balance": "3830421000000000000000"
		},
		"dc46c13325cd8edf0230d068896486f007bf4ef1": {
			"balance": "1337000000000000000000"
		},
		"8c54c7f8b9896e75d7d5f5c760258699957142ad": {
			"balance": "40000000000000000000"
		},
		"61c8f1fa43bf846999ecf47b2b324dfb6b63fe3a": {
			"balance": "800000000000000000000"
		},
		"935069444a6a984de2084e46692ab99f671fc727": {
			"balance": "9000000000000000000000"
		},
		"fc49c1439a41d6b3cf26bb67e0365224e5e38f5f": {
			"balance": "1000076000000000000000"
		},
		"e1dfb5cc890ee8b2877e885d267c256187d019e6": {
			"balance": "100000000000000000000"
		},
		"ee7c3ded7c28f459c92fe13b4d95bafbab02367d": {
			"balance": "700000000000000000000"
		},
)E" + R"E(
		"a5874d754635a762b381a5c4c792483af8f23d1d": {
			"balance": "50000000000000000000"
		},
		"cfbb32b7d024350e3321fa20c9a914035372ffc6": {
			"balance": "401100000000000000000"
		},
		"2bc429d618a66a4cf82dbb2d824e9356effa126a": {
			"balance": "1999944000000000000000"
		},
		"db244f97d9c44b158a40ed9606d9f7bd38913331": {
			"balance": "102000000000000000000"
		},
		"55e220876262c218af4f56784798c7e55da09e91": {
			"balance": "133566000000000000000"
		},
		"ca41ccac30172052d522cd2f2f957d248153409f": {
			"balance": "1970000000000000000000"
		},
		"b11fa7fb270abcdf5a2eab95aa30c4b53636efbf": {
			"balance": "800000000000000000000"
		},
		"0ffea06d7113fb6aec2869f4a9dfb09007facef4": {
			"balance": "225416000000000000000"
		},
		"646628a53c2c4193da88359ce718dadd92b7a48d": {
			"balance": "200032000000000000000"
		},
		"ca8409083e01b397cf12928a05b68455ce6201df": {
			"balance": "1600000000000000000000"
		},
		"dbbcbb79bf479a42ad71dbcab77b5adfaa872c58": {
			"balance": "1730000000000000000000"
		},
		"db7d4037081f6c65f9476b0687d97f1e044d0a1d": {
			"balance": "660000000000000000000"
		},
		"4be90d412129d5a4d0424361d6649d4e47a62316": {
			"balance": "1015200000000000000000"
		},
		"e3ab3ca9b870e3f548517306bba4de2591afafc2": {
			"balance": "1200062000000000000000"
		},
		"5c61ab79b408dd3229f662593705d72f1e147bb8": {
			"balance": "22729000000000000000000"
		},
		"4f177f9d56953ded71a5611f393322c30279895c": {
			"balance": "246000000000000000000"
		},
		"e6cb260b716d4c0ab726eeeb07c8707204e276ae": {
			"balance": "1000000000000000000000"
		},
		"44355253b27748e3f34fe9cae1fb718c8f249529": {
			"balance": "200000000000000000000"
		},
		"a309df54cabce70c95ec3033149cd6678a6fd4cf": {
			"balance": "223600000000000000000"
		},
		"ec4867d2175ab5b9469361595546554684cda460": {
			"balance": "3000000000000000000000"
		},
		"8d06e464245cad614939e0af0845e6d730e20374": {
			"balance": "200359000000000000000"
		},
		"9810e34a94db6ed156d0389a0e2b80f4fd6b0a8a": {
			"balance": "2000000000000000000000"
		},
		"dcfff3e8d23c2a34b56bd1b3bd45c79374432239": {
			"balance": "5000000000000000000000"
		},
		"7d7dd5ee614dbb6fbfbcd26305247a058c41faa1": {
			"balance": "2000000000000000000000"
		},
		"8a9eca9c5aba8e139f8003edf1163afb70aa3aa9": {
			"balance": "660000000000000000000"
		},
		"d942de4784f7a48716c0fd4b9d54a6e54c5f2f3e": {
			"balance": "20000000000000000000000"
		},
		"07dae622630d1136381933d2ad6b22b839d82102": {
			"balance": "200000000000000000000"
		},
		"abf12fa19e82f76c718f01bdca0003674523ef30": {
			"balance": "2000000000000000000000"
		},
		"411c831cc6f44f1965ec5757ab4e5b3ca4cffd1f": {
			"balance": "425000000000000000000"
		},
		"99129d5b3c0cde47ea0def4dfc070d1f4a599527": {
			"balance": "2000000000000000000000"
		},
		"c5cdcee0e85d117dabbf536a3f4069bf443f54e7": {
			"balance": "1969606000000000000000"
		},
		"f218bd848ee7f9d38bfdd1c4eb2ed2496ae4305f": {
			"balance": "500000000000000000000"
		},
		"fe549bbfe64740189892932538daaf46d2b61d4f": {
			"balance": "40000000000000000000"
		},
		"dc3f0e7672f71fe7525ba30b9755183a20b9166a": {
)E" + R"E(
			"balance": "9603617000000000000000"
		},
		"0e83b850481ab44d49e0a229a2e464902c69539b": {
			"balance": "100000000000000000000"
		},
		"07ddd0422c86ef65bf0c7fc3452862b1228b08b8": {
			"balance": "2065302000000000000000"
		},
		"a68c313445c22d919ee46cc2d0cdff043a755825": {
			"balance": "75189000000000000000"
		},
		"a9e9dbce7a2cb03694799897bed7c54d155fdaa8": {
			"balance": "197559000000000000000"
		},
		"18fccf62d2c3395453b7587b9e26f5cff9eb7482": {
			"balance": "1000000000000000000000"
		},
		"ff41d9e1b4effe18d8b0d1f63fc4255fb4e06c3d": {
			"balance": "1337000000000000000000"
		},
		"8f69eafd0233cadb4059ab779c46edf2a0506e48": {
			"balance": "1788210000000000000000"
		},
		"9aa48c66e4fb4ad099934e32022e827427f277ba": {
			"balance": "10000000000000000000000"
		},
		"f46980e3a4a9d29a6a6e90604537a3114bcb2897": {
			"balance": "500000000000000000000"
		},
		"801732a481c380e57ed62d6c29de998af3fa3b13": {
			"balance": "100000000000000000000"
		},
		"0cd6a141918d126b106d9f2ebf69e102de4d3277": {
			"balance": "20000000000000000000"
		},
		"17589a6c006a54cad70103123aae0a82135fdeb4": {
			"balance": "4000000000000000000000"
		},
		"8725e8c753b3acbfdca55f3c62dfe1a59454968a": {
			"balance": "1000090000000000000000"
		},
		"d20dcb0b78682b94bc3000281448d557a20bfc83": {
			"balance": "895000000000000000000"
		},
		"e84f8076a0f2969ecd333eef8de41042986291f2": {
			"balance": "432000000000000000000"
		},
		"b3145b74506d1a8d047cdcdc55392a7b5350799a": {
			"balance": "129314663000000000000000"
		},
		"0d9a825ff2bcd397cbad5b711d9dcc95f1cc112d": {
			"balance": "12800000000000000000000"
		},
		"0ca670eb2c8b96cba379217f5929c2b892f39ef6": {
			"balance": "2000000000000000000000"
		},
		"25cfc4e25c35c13b69f7e77dbfb08baf58756b8d": {
			"balance": "40000000000000000000000"
		},
		"182db85293f606e88988c3704cb3f0c0bbbfca5a": {
			"balance": "133700000000000000000"
		},
		"bd73c3cbc26a175062ea0320dd84b253bce64358": {
			"balance": "394000000000000000000"
		},
		"2680713d40808e2a50ed013150a2a694b96a7f1d": {
			"balance": "1790000000000000000000"
		},
		"51e32f14f4ca5e287cdac057a7795ea9e0439953": {
			"balance": "500000000000000000000"
		},
		"b1e9c5f1d21e61757a6b2ee75913fc5a1a4101c3": {
			"balance": "2000000000000000000000"
		},
		"d4c4d1a7c3c74984f6857b2f5f07e8face68056d": {
			"balance": "2000000000000000000000"
		},
		"4651dc420e08c3293b27d2497890eb50223ae2f4": {
			"balance": "20000000000000000000000"
		},
		"c74a3995f807de1db01a2eb9c62e97d0548f696f": {
			"balance": "1000000000000000000000"
		},
		"0505a08e22a109015a22f685305354662a5531d5": {
			"balance": "2600000000000000000000"
		},
		"39c773367c8825d3596c686f42bf0d14319e3f84": {
			"balance": "133700000000000000000"
		},
		"0f929cf895db017af79f3ead2216b1bd69c37dc7": {
			"balance": "2000000000000000000000"
		},
		"bdd3254e1b3a6dc6cc2c697d45711aca21d516b2": {
			"balance": "2000000000000000000000"
		},
		"ae5d221afcd3d29355f508eadfca408ce33ca903": {
			"balance": "100000000000000000000000"
		},
		"916cf17d71412805f4afc3444a0b8dd1d9339d16": {
			"balance": "14300000000000000000"
)E" + R"E(
		},
		"4319263f75402c0b5325f263be4a5080651087f0": {
			"balance": "983086000000000000000"
		},
		"0f1c249cd962b00fd114a9349f6a6cc778d76c4d": {
			"balance": "2000000000000000000000"
		},
		"54febcce20fe7a9098a755bd90988602a48c089e": {
			"balance": "640000000000000000000"
		},
		"2c1800f35fa02d3eb6ff5b25285f5e4add13b38d": {
			"balance": "906400000000000000000"
		},
		"72b904440e90e720d6ac1c2ad79c321dcc1c1a86": {
			"balance": "1550000000000000000000"
		},
		"b0aa00950c0e81fa3210173e729aaf163a27cd71": {
			"balance": "40000000000000000000000"
		},
		"663604b0503046e624cd26a8b6fb4742dce02a6f": {
			"balance": "65400000000000000000"
		},
		"3c98594bf68b57351e8814ae9e6dfd2d254aa06f": {
			"balance": "300000000000000000000"
		},
		"9c45202a25f6ad0011f115a5a72204f2f2198866": {
			"balance": "5014000000000000000000"
		},
		"b02d062873334545cea29218e4057760590f7423": {
			"balance": "3186000000000000000000"
		},
		"7bddb2ee98de19ee4c91f661ee8e67a91d054b97": {
			"balance": "1000000000000000000000"
		},
		"9cf2928beef09a40f9bfc953be06a251116182fb": {
			"balance": "6000000000000000000000"
		},
		"51b4758e9e1450e7af4268c3c7b1e7bd6f5c7550": {
			"balance": "1000000000000000000000"
		},
		"eb570dba975227b1c42d6e8dea2c56c9ad960670": {
			"balance": "2000000000000000000000"
		},
		"970d8b8a0016d143054f149fb3b8e550dc0797c7": {
			"balance": "1000000000000000000000"
		},
		"c7b39b060451000ca1049ba154bcfa00ff8af262": {
			"balance": "100000000000000000000000"
		},
		"945e18769d7ee727c7013f92de24d117967ff317": {
			"balance": "2000000000000000000000"
		},
		"d18eb9e1d285dabe93e5d4bae76beefe43b521e8": {
			"balance": "668500000000000000000"
		},
		"c618521321abaf5b26513a4a9528086f220adc6f": {
			"balance": "27000000000000000000"
		},
		"dd65f6e17163b5d203641f51cc7b24b00f02c8fb": {
			"balance": "200000000000000000000"
		},
		"131faed12561bb7aee04e5185af802b1c3438d9b": {
			"balance": "219000000000000000000"
		},
		"1ced6715f862b1ff86058201fcce5082b36e62b2": {
			"balance": "6684522000000000000000"
		},
		"a0ff5b4cf016027e8323497d4428d3e5a83b8795": {
			"balance": "6596500000000000000000"
		},
		"02e816afc1b5c0f39852131959d946eb3b07b5ad": {
			"balance": "1000000000000000000000"
		},
		"153cf2842cb9de876c276fa64767d1a8ecf573bb": {
			"balance": "2000000000000000000000"
		},
		"3bc6e3ee7a56ce8f14a37532590f63716b9966e8": {
			"balance": "2000000000000000000000"
		},
		"f6d25d3f3d846d239f525fa8cac97bc43578dbac": {
			"balance": "896000000000000000000"
		},
		"2066774d822793ff25f1760909479cf62491bf88": {
			"balance": "55160000000000000000000"
		},
		"46779a5656ff00d73eac3ad0c38b6c853094fb40": {
			"balance": "230752000000000000000"
		},
		"22eed327f8eb1d1338a3cb7b0f8a4baa5907cd95": {
			"balance": "23445000000000000000"
		},
		"ff88ebacc41b3687f39e4b59e159599b80cba33f": {
			"balance": "400000000000000000000"
		},
		"2874f3e2985d5f7b406627e17baa772b01abcc9e": {
			"balance": "6014000000000000000000"
		},
		"eb10458daca79e4a6b24b29a8a8ada711b7f2eb6": {
			"balance": "3998000000000000000000"
		},
)E" + R"E(
		"541060fc58c750c40512f83369c0a63340c122b6": {
			"balance": "1970000000000000000000"
		},
		"fd2757cc3551a095878d97875615fe0c6a32aa8a": {
			"balance": "598200000000000000000"
		},
		"be659d85e7c34f8833ea7f488de1fbb5d4149bef": {
			"balance": "9072500000000000000000"
		},
		"e149b5726caf6d5eb5bf2acc41d4e2dc328de182": {
			"balance": "1940000000000000000000"
		},
		"2fe0cc424b53a31f0916be08ec81c50bf8eab0c1": {
			"balance": "600000000000000000000"
		},
		"e3712701619ca7623c55db3a0ad30e867db0168b": {
			"balance": "20000000000000000000"
		},
		"f8ca336c8e91bd20e314c20b2dd4608b9c8b9459": {
			"balance": "846000000000000000000"
		},
		"68acdaa9fb17d3c309911a77b05f5391fa034ee9": {
			"balance": "8950000000000000000000"
		},
		"e77d7deab296c8b4fa07ca3be184163d5a6d606c": {
			"balance": "92538000000000000000"
		},
		"e6b9545f7ed086e552924639f9a9edbbd5540b3e": {
			"balance": "3760000000000000000000"
		},
		"2866b81decb02ee70ae250cee5cdc77b59d7b679": {
			"balance": "2000000000000000000000"
		},
		"60e3cc43bcdb026aad759c7066f555bbf2ac66f5": {
			"balance": "2000000000000000000000"
		},
		"fcbd85feea6a754fcf3449449e37ff9784f7773c": {
			"balance": "3086000000000000000000"
		},
		"38a744efa6d5c2137defef8ef9187b649eee1c78": {
			"balance": "4000000000000000000000"
		},
		"9d7655e9f3e5ba5d6e87e412aebe9ee0d49247ee": {
			"balance": "2620100000000000000000"
		},
		"2020b81ae53926ace9f7d7415a050c031d585f20": {
			"balance": "341200000000000000000"
		},
		"4244f1331158b9ce26bbe0b9236b9203ca351434": {
			"balance": "10000000000000000000000"
		},
		"99c236141daec837ece04fdaee1d90cf8bbdc104": {
			"balance": "2184000000000000000000"
		},
		"943d37864a4a537d35c8d99723cd6406ce2562e6": {
			"balance": "2000000000000000000000"
		},
		"d79483f6a8444f2549d611afe02c432d15e11051": {
			"balance": "20000000000000000000"
		},
		"9fd64373f2fbcd9c0faca60547cad62e26d9851f": {
			"balance": "1000000000000000000000"
		},
		"b89c036ed7c492879921be41e10ca1698198a74c": {
			"balance": "1820000000000000000000"
		},
		"7462c89caa9d8d7891b2545def216f7464d5bb21": {
			"balance": "109162000000000000000"
		},
		"bb0366a7cfbd3445a70db7fe5ae34885754fd468": {
			"balance": "6160000000000000000000"
		},
		"6c52cf0895bb35e656161e4dc46ae0e96dd3e62c": {
			"balance": "4000086000000000000000"
		},
		"b9cf71b226583e3a921103a5316f855a65779d1b": {
			"balance": "24000000000000000000000"
		},
		"016b60bb6d67928c29fd0313c666da8f1698d9c5": {
			"balance": "2000000000000000000000"
		},
		"9454b3a8bff9709fd0e190877e6cb6c89974dbd6": {
			"balance": "2674000000000000000000"
		},
		"84aac7fa197ff85c30e03b7a5382b957f41f3afb": {
			"balance": "157600000000000000000"
		},
		"db6e560c9bc620d4bea3a94d47f7880bf47f2d5f": {
			"balance": "89500000000000000000"
		},
		"eefd05b0e3c417d55b3343060486cdd5e92aa7a6": {
			"balance": "1430000000000000000000"
		},
		"3a59a08246a8206f8d58f70bb1f0d35c5bcc71bd": {
			"balance": "185000000000000000000"
		},
		"9bfff50db36a785555f07652a153b0c42b1b8b76": {
			"balance": "2000000000000000000000"
		},
		"d44f5edf2bcf2433f211dadd0cc450db1b008e14": {
)E" + R"E(
			"balance": "267400000000000000000"
		},
		"2378fd4382511e968ed192106737d324f454b535": {
			"balance": "1000000000000000000000"
		},
		"c94089553ae4c22ca09fbc98f57075cf2ec59504": {
			"balance": "4000000000000000000000"
		},
		"08ef3fa4c43ccdc57b22a4b9b2331a82e53818f2": {
			"balance": "4000000000000000000000"
		},
		"e48e65125421880d42bdf1018ab9778d96928f3f": {
			"balance": "4200000000000000000000"
		},
		"67518e5d02b205180f0463a32004471f753c523e": {
			"balance": "1984289000000000000000"
		},
		"0da7401262384e2e8b4b26dd154799b55145efa0": {
			"balance": "300000000000000000000"
		},
		"0b6920a64b363b8d5d90802494cf564b547c430d": {
			"balance": "1200000000000000000000"
		},
		"a5ab4bd3588f46cb272e56e93deed386ba8b753d": {
			"balance": "1332989000000000000000"
		},
		"1788da9b57fd05edc4ff99e7fef301519c8a0a1e": {
			"balance": "2000000000000000000000"
		},
		"17b2d6cf65c6f4a347ddc6572655354d8a412b29": {
			"balance": "2000000000000000000000"
		},
		"d0319139fbab2e8e2accc1d924d4b11df6696c5a": {
			"balance": "200000000000000000000"
		},
		"4c377bb03ab52c4cb79befa1dd114982924c4ae9": {
			"balance": "1827814000000000000000"
		},
		"fb949c647fdcfd2514c7d58e31f28a532d8c5833": {
			"balance": "20000000000000000000000"
		},
		"70e5e9da735ff077249dcb9aaf3db2a48d9498c0": {
			"balance": "1000000000000000000000"
		},
		"fe6f5f42b6193b1ad16206e4afb5239d4d7db45e": {
			"balance": "1730000000000000000000"
		},
		"bda4be317e7e4bed84c0495eee32d607ec38ca52": {
			"balance": "2309457000000000000000"
		},
		"5910106debd291a1cd80b0fbbb8d8d9e93a7cc1e": {
			"balance": "2000000000000000000000"
		},
		"ba42f9aace4c184504abf5425762aca26f71fbdc": {
			"balance": "37400000000000000000"
		},
		"beb4fd315559436045dcb99d49dcec03f40c42dc": {
			"balance": "2000000000000000000000"
		},
		"452b64db8ef7d6df87c788639c2290be8482d575": {
			"balance": "8000000000000000000000"
		},
		"66e09427c1e63deed7e12b8c55a6a19320ef4b6a": {
			"balance": "170000000000000000000"
		},
		"faad905d847c7b23418aeecbe3addb8dd3f8924a": {
			"balance": "1970000000000000000000"
		},
		"a29319e81069e5d60df00f3de5adee3505ecd5fb": {
			"balance": "2000000000000000000000"
		},
		"cf348f2fe47b7e413c077a7baf3a75fbf8428692": {
			"balance": "2000000000000000000000"
		},
		"e1e8c50b80a352b240ce7342bbfdf5690cc8cb14": {
			"balance": "394000000000000000000"
		},
		"131c792c197d18bd045d7024937c1f84b60f4438": {
			"balance": "4000000000000000000000"
		},
		"e49af4f34adaa2330b0e49dc74ec18ab2f92f827": {
			"balance": "2000000000000000000000"
		},
		"f2e99f5cbb836b7ad36247571a302cbe4b481c69": {
			"balance": "1970000000000000000000"
		},
		"c93fbde8d46d2bcc0fa9b33bd8ba7f8042125565": {
			"balance": "1400000000000000000000"
		},
		"038779ca2dbe663e63db3fe75683ea0ec62e2383": {
			"balance": "1670000000000000000000"
		},
		"a33cb450f95bb46e25afb50fe05feee6fb8cc8ea": {
			"balance": "776000000000000000000"
		},
		"40ab66fe213ea56c3afb12c75be33f8e32fd085d": {
			"balance": "4000000000000000000000"
		},
		"6403d062549690c8e8b63eae41d6c109476e2588": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"bfb0ea02feb61dec9e22a5070959330299c43072": {
			"balance": "20000000000000000000000"
		},
		"99c475bf02e8b9214ada5fad02fdfd15ba365c0c": {
			"balance": "591000000000000000000"
		},
		"904966cc2213b5b8cb5bd6089ef9cddbef7edfcc": {
			"balance": "2000000000000000000000"
		},
		"767a03655af360841e810d83f5e61fb40f4cd113": {
			"balance": "985000000000000000000"
		},
		"ab209fdca979d0a647010af9a8b52fc7d20d8cd1": {
			"balance": "9129000000000000000000"
		},
		"6294eae6e420a3d5600a39c4141f838ff8e7cc48": {
			"balance": "2955000000000000000000"
		},
		"9777cc61cf756be3b3c20cd4491c69d275e7a120": {
			"balance": "10000000000000000000000"
		},
		"bcbf6ba166e2340db052ea23d28029b0de6aa380": {
			"balance": "3880000000000000000000"
		},
		"9f10f2a0463b65ae30b070b3df18cf46f51e89bd": {
			"balance": "1910000000000000000000"
		},
		"8d9952d0bb4ebfa0efd01a3aa9e8e87f0525742e": {
			"balance": "3460000000000000000000"
		},
		"4f23b6b817ffa5c664acdad79bb7b726d30af0f9": {
			"balance": "1760000000000000000000"
		},
		"b4c20040ccd9a1a3283da4d4a2f365820843d7e2": {
			"balance": "1000000000000000000000"
		},
		"7f49e7a4269882bd8722d4a6f566347629624079": {
			"balance": "2000000000000000000000"
		},
		"33629bd52f0e107bc071176c64df108f64777d49": {
			"balance": "33425000000000000000"
		},
		"6a7b2e0d88867ff15d207c222bebf94fa6ce8397": {
			"balance": "60000000000000000000000"
		},
		"b7ce684b09abda53389a875369f71958aeac3bdd": {
			"balance": "2000000000000000000000"
		},
		"ffbc3da0381ec339c1c049eb1ed9ee34fdcea6ca": {
			"balance": "4000000000000000000000"
		},
		"849ab80790b28ff1ffd6ba394efc7463105c36f7": {
			"balance": "34600000000000000000"
		},
		"b0b36af9aeeedf97b6b02280f114f13984ea3260": {
			"balance": "985000000000000000000"
		},
		"4d57e716876c0c95ef5eaebd35c8f41b069b6bfe": {
			"balance": "2000000000000000000000"
		},
		"2d2b032359b363964fc11a518263bfd05431e867": {
			"balance": "149600000000000000000"
		},
		"2ccc1f1cb5f4a8002e186b20885d9dbc030c0894": {
			"balance": "2000000000000000000000"
		},
		"016c85e1613b900fa357b8283b120e65aefcdd08": {
			"balance": "799954000000000000000"
		},
		"710b0274d712c77e08a5707d6f3e70c0ce3d92cf": {
			"balance": "6400000000000000000000"
		},
		"3cd3a6e93579c56d494171fc533e7a90e6f59464": {
			"balance": "2000000000000000000000"
		},
		"fe0e30e214290d743dd30eb082f1f0a5225ade61": {
			"balance": "200000000000000000000"
		},
		"d0718520eae0a4d62d70de1be0ca431c5eea2482": {
			"balance": "2000000000000000000000"
		},
		"af7f79cb415a1fb8dbbd094607ee8d41fb7c5a3b": {
			"balance": "10000000000000000000000"
		},
		"b7d252ee9402b0eef144295f0e69f0db586c0871": {
			"balance": "660000000000000000000"
		},
		"c3b928a76fad6578f04f0555e63952cd21d1520a": {
			"balance": "2000000000000000000000"
		},
		"a7a517d7ad35820b09d497fa7e5540cde9495853": {
			"balance": "2000000000000000000000"
		},
		"e6e886317b6a66a5b4f81bf164c538c264351765": {
			"balance": "2000000000000000000000"
		},
		"0770b43dbae4b1f35a927b4fa8124d3866caf97b": {
			"balance": "1016390000000000000000"
		},
)E" + R"E(
		"52b4257cf41b6e28878d50d57b99914ffa89873a": {
			"balance": "3930150000000000000000"
		},
		"e08bc29c2b48b169ff2bdc16714c586e6cb85ccf": {
			"balance": "20000000000000000000"
		},
		"2372c4c1c9939f7aaf6cfac04090f00474840a09": {
			"balance": "10000000000000000000000"
		},
		"ab6b65eab8dfc917ec0251b9db0ecfa0fa032849": {
			"balance": "500000000000000000000"
		},
		"582e7cc46f1d7b4e6e9d95868bfd370573178f4c": {
			"balance": "2000000000000000000000"
		},
		"f167f5868dcf4233a7830609682caf2df4b1b807": {
			"balance": "2396150000000000000000"
		},
		"ec82f50d06475f684df1b392e00da341aa145444": {
			"balance": "2000000000000000000000"
		},
		"0968ee5a378f8cadb3bafdbed1d19aaacf936711": {
			"balance": "1000000000000000000000"
		},
		"a86613e6c4a4c9c55f5c10bcda32175dcbb4af60": {
			"balance": "10696140000000000000000"
		},
		"a5cd123992194b34c4781314303b03c54948f4b9": {
			"balance": "2010462000000000000000"
		},
		"52f058d46147e9006d29bf2c09304ad1cddd6e15": {
			"balance": "1500000000000000000000"
		},
		"160226efe7b53a8af462d117a0108089bdecc2d1": {
			"balance": "200550000000000000000"
		},
		"256292a191bdda34c4da6b6bd69147bf75e2a9ab": {
			"balance": "14051000000000000000"
		},
		"1b8aa0160cd79f005f88510a714913d70ad3be33": {
			"balance": "201760000000000000000"
		},
		"d4b2ff3bae1993ffea4d3b180231da439f7502a2": {
			"balance": "2000000000000000000000"
		},
		"e408aa99835307eea4a6c5eb801fe694117f707d": {
			"balance": "500000000000000000000"
		},
		"e60a55f2df996dc3aedb696c08dde039b2641de8": {
			"balance": "2000000000000000000000"
		},
		"73df3c3e7955f4f2d859831be38000b1076b3884": {
			"balance": "1970000000000000000000"
		},
		"6228ade95e8bb17d1ae23bfb0518414d497e0eb8": {
			"balance": "400000000000000000000"
		},
		"0f46c81db780c1674ac73d314f06539ee56ebc83": {
			"balance": "9850000000000000000000"
		},
		"762d6f30dab99135e4eca51d5243d6c8621102d5": {
			"balance": "282000000000000000000"
		},
		"4ba0d9e89601772b496847a2bb4340186787d265": {
			"balance": "1000000000000000000000"
		},
		"ca747576446a4c8f30b08340fee198de63ec92cf": {
			"balance": "7020000000000000000000"
		},
		"99c31fe748583787cdd3e525b281b218961739e3": {
			"balance": "1015200000000000000000"
		},
		"1210f80bdb826c175462ab0716e69e46c24ad076": {
			"balance": "100000000000000000000"
		},
		"3f75ae61cc1d8042653b5baec4443e051c5e7abd": {
			"balance": "95500000000000000000"
		},
		"5c4892907a0720df6fd3413e63ff767d6b398023": {
			"balance": "13189467000000000000000"
		},
		"17f14632a7e2820be6e8f6df823558283dadab2d": {
			"balance": "2000000000000000000000"
		},
		"1dc7f7dad85df53f1271152403f4e1e4fdb3afa0": {
			"balance": "200000000000000000000"
		},
		"5a30feac37ac9f72d7b4af0f2bc73952c74fd5c3": {
			"balance": "2000000000000000000000"
		},
		"136d4b662bbd1080cfe4445b0fa213864435b7f1": {
			"balance": "4000000000000000000000"
		},
		"c1ec81dd123d4b7c2dd9b4d438a7072c11dc874c": {
			"balance": "2000000000000000000000"
		},
		"09f9575be57d004793c7a4eb84b71587f97cbb6a": {
			"balance": "200000000000000000000"
		},
		"2c4b470307a059854055d91ec3794d80b53d0f4a": {
)E" + R"E(
			"balance": "20000000000000000000000"
		},
		"6af6c7ee99df271ba15bf384c0b764adcb4da182": {
			"balance": "999972000000000000000"
		},
		"0dae3ee5b915b36487f9161f19846d101433318a": {
			"balance": "1910000000000000000000"
		},
		"0dcf9d8c9804459f647c14138ed50fad563b4154": {
			"balance": "173000000000000000000"
		},
		"bfa8c858df102cb12421008b0a31c4c7190ad560": {
			"balance": "200000000000000000000"
		},
		"c2fd0bf7c725ef3e047e5ae1c29fe18f12a7299c": {
			"balance": "1337000000000000000000"
		},
		"d70a612bd6dda9eab0dddcff4aaf4122d38feae4": {
			"balance": "540000000000000000000"
		},
		"e07137ae0d116d033533c4eab496f8a9fb09569c": {
			"balance": "1400000000000000000000"
		},
		"7f49f20726471ac1c7a83ef106e9775ceb662566": {
			"balance": "5910000000000000000000"
		},
		"1e706655e284dcf0bb37fe075d613a18dc12ff4a": {
			"balance": "4376760000000000000000"
		},
		"03af7ad9d5223cf7c8c13f20df67ebe5ffc5bb41": {
			"balance": "200000000000000000000"
		},
		"228242f8336eecd8242e1f000f41937e71dffbbf": {
			"balance": "5000000000000000000000"
		},
		"e8ed51bbb3ace69e06024b33f86844c47348db9e": {
			"balance": "165170600000000000000000"
		},
		"3b566a8afad19682dc2ce8679a3ce444a5b0fd4f": {
			"balance": "2000000000000000000000"
		},
		"dc738fb217cead2f69594c08170de1af10c419e3": {
			"balance": "100000000000000000000000"
		},
		"13032446e7d610aa00ec8c56c9b574d36ca1c016": {
			"balance": "2000000000000000000000"
		},
		"6ca6a132ce1cd288bee30ec7cfeffb85c1f50a54": {
			"balance": "2000000000000000000000"
		},
		"b85f26dd0e72d9c29ebaf697a8af77472c2b58b5": {
			"balance": "11900000000000000000000"
		},
		"055bd02caf19d6202bbcdc836d187bd1c01cf261": {
			"balance": "100000000000000000000"
		},
		"3c322e611fdb820d47c6f8fc64b6fad74ca95f5e": {
			"balance": "242514000000000000000"
		},
		"8daddf52efbd74da95b969a5476f4fbbb563bfd2": {
			"balance": "835000000000000000000"
		},
		"c63ac417992e9f9b60386ed953e6d7dff2b090e8": {
			"balance": "4000086000000000000000"
		},
		"27f03cf1abc5e1b51dbc444b289e542c9ddfb0e6": {
			"balance": "5000000000000000000000"
		},
		"d8f4bae6f84d910d6d7d5ac914b1e68372f94135": {
			"balance": "100000000000000000000"
		},
		"9f83a293c324d4106c18faa8888f64d299054ca0": {
			"balance": "200000000000000000000"
		},
		"39ee4fe00fbced647068d4f57c01cb22a80bccd1": {
			"balance": "6000000000000000000000"
		},
		"404100db4c5d0eec557823b58343758bcc2c8083": {
			"balance": "20000000000000000000"
		},
		"02751dc68cb5bd737027abf7ddb77390cd77c16b": {
			"balance": "20000000000000000000"
		},
		"d10302faa1929a326904d376bf0b8dc93ad04c4c": {
			"balance": "1790000000000000000000"
		},
		"cc419fd9912b85135659e77a93bc3df182d45115": {
			"balance": "10000000000000000000000"
		},
		"10097198b4e7ee91ff82cc2f3bd95fed73c540c0": {
			"balance": "2000000000000000000000"
		},
		"7e24d9e22ce1da3ce19f219ccee523376873f367": {
			"balance": "5900150000000000000000"
		},
		"2e4ee1ae996aa0a1d92428d06652a6bea6d2d15d": {
			"balance": "2000000000000000000000"
		},
		"91a4149a2c7b1b3a67ea28aff34725e0bf8d7524": {
			"balance": "1940000000000000000000"
)E" + R"E(
		},
		"ead65262ed5d122df2b2751410f98c32d1238f51": {
			"balance": "101680000000000000000"
		},
		"e20954d0f4108c82d4dcb2148d26bbd924f6dd24": {
			"balance": "10000000000000000000000"
		},
		"ebb7d2e11bc6b58f0a8d45c2f6de3010570ac891": {
			"balance": "26740000000000000000"
		},
		"ef115252b1b845cd857f002d630f1b6fa37a4e50": {
			"balance": "1970000000000000000000"
		},
		"01a818135a414210c37c62b625aca1a54611ac36": {
			"balance": "260000000000000000000"
		},
		"ea1ea0c599afb9cd36caacbbb52b5bbb97597377": {
			"balance": "1069600000000000000000"
		},
		"7a7a4f807357a4bbe68e1aa806393210c411ccb3": {
			"balance": "30000000000000000000000"
		},
		"6d40ca27826d97731b3e86effcd7b92a4161fe89": {
			"balance": "2000000000000000000000"
		},
		"8431277d7bdd10457dc017408c8dbbbd414a8df3": {
			"balance": "39400000000000000000"
		},
		"69b81d5981141ec7a7141060dfcf8f3599ffc63e": {
			"balance": "5000000000000000000000"
		},
		"47688410ff25d654d72eb2bc06e4ad24f833b094": {
			"balance": "160440000000000000000"
		},
		"6c101205b323d77544d6dc52af37aca3cec6f7f1": {
			"balance": "10000000000000000000000"
		},
		"fb685c15e439965ef626bf0d834cd1a89f2b5695": {
			"balance": "3940000000000000000000"
		},
		"673706b1b0e4dc7a949a7a796258a5b83bb5aa83": {
			"balance": "16100000000000000000000"
		},
		"ecdaf93229b45ee672f65db506fb5eca00f7fce6": {
			"balance": "1605009000000000000000"
		},
		"ec6904bae1f69790591709b0609783733f2573e3": {
			"balance": "500000000000000000000"
		},
		"812ea7a3b2c86eed32ff4f2c73514cc63bacfbce": {
			"balance": "1000000000000000000000"
		},
		"196c02210a450ab0b36370655f717aa87bd1c004": {
			"balance": "259456000000000000000"
		},
		"d96ac2507409c7a383ab2eee1822a5d738b36b56": {
			"balance": "200000000000000000000"
		},
		"ae2f9c19ac76136594432393b0471d08902164d3": {
			"balance": "698600000000000000000"
		},
		"9d32962ea99700d93228e9dbdad2cc37bb99f07e": {
			"balance": "3327560000000000000000"
		},
		"17e584e810e567702c61d55d434b34cdb5ee30f6": {
			"balance": "5000000000000000000000"
		},
		"a3a93ef9dbea2636263d06d8492f6a41de907c22": {
			"balance": "60000000000000000000"
		},
		"2b5016e2457387956562587115aa8759d8695fdf": {
			"balance": "200000000000000000000000"
		},
		"140129eaa766b5a29f5b3af2574e4409f8f6d3f1": {
			"balance": "6400000000000000000000"
		},
		"7025965d2b88da197d4459be3dc9386344cc1f31": {
			"balance": "2005500000000000000000"
		},
		"388bdcdae794fc44082e667501344118ea96cd96": {
			"balance": "1670000000000000000000"
		},
		"eee9d0526eda01e43116a395322dda8970578f39": {
			"balance": "9999980000000000000000"
		},
		"6ec89b39f9f5276a553e8da30e6ec17aa47eefc7": {
			"balance": "447500000000000000000"
		},
		"7e236666b2d06e63ea4e2ab84357e2dfc977e50e": {
			"balance": "999972000000000000000"
		},
		"68df947c495bebaeb8e889b3f953d533874bf106": {
			"balance": "546000000000000000000"
		},
		"d40ed66ab3ceff24ca05ecd471efb492c15f5ffa": {
			"balance": "500000000000000000000"
		},
		"f0c70d0d6dab7663aa9ed9ceea567ee2c6b02765": {
			"balance": "2089349000000000000000"
		},
)E" + R"E(
		"b589676d15a04448344230d4ff27c95edf122c49": {
			"balance": "1000000000000000000000"
		},
		"a0347f0a98776390165c166d32963bf74dcd0a2f": {
			"balance": "1000000000000000000000"
		},
		"d47d8685faee147c520fd986709175bf2f886bef": {
			"balance": "2000000000000000000000"
		},
		"a1dcd0e5b05a977c9623e5ae2f59b9ada2f33e31": {
			"balance": "100000000000000000000"
		},
		"4979194ec9e97db9bee8343b7c77d9d7f3f1dc9f": {
			"balance": "20000000000000000000"
		},
		"7cd20eccb518b60cab095b720f571570caaa447e": {
			"balance": "500000000000000000000"
		},
		"2ff830cf55fb00d5a0e03514fecd44314bd6d9f1": {
			"balance": "10000000000000000000000"
		},
		"0bb25ca7d188e71e4d693d7b170717d6f8f0a70a": {
			"balance": "336870000000000000000"
		},
		"e9a2b4914e8553bf0d7c00ca532369b879f931bf": {
			"balance": "2000000000000000000000"
		},
		"720e6b22bf430966fa32b6acb9a506eebf662c61": {
			"balance": "152000000000000000000"
		},
		"7ade5d66b944bb860c0efdc86276d58f4653f711": {
			"balance": "2000000000000000000000"
		},
		"2eaff9f8f8113064d3957ac6d6e11eee42c8195d": {
			"balance": "1970000000000000000000"
		},
		"0c8fd7775e54a6d9c9a3bf890e761f6577693ff0": {
			"balance": "9850000000000000000000"
		},
		"290a56d41f6e9efbdcea0342e0b7929a8cdfcb05": {
			"balance": "344000000000000000000"
		},
		"d73ed2d985b5f21b55b274643bc6da031d8edd8d": {
			"balance": "49250000000000000000000"
		},
		"80156d10efa8b230c99410630d37e269d4093cea": {
			"balance": "2000000000000000000000"
		},
		"0989c200440b878991b69d6095dfe69e33a22e70": {
			"balance": "1910000000000000000000"
		},
		"ec8014efc7cbe5b0ce50f3562cf4e67f8593cd32": {
			"balance": "17300000000000000000"
		},
		"de612d0724e84ea4a7feaa3d2142bd5ee82d3201": {
			"balance": "20000000000000000000"
		},
		"0f832a93df9d7f74cd0fb8546b7198bf5377d925": {
			"balance": "143000000000000000000"
		},
		"aa2c670096d3f939305325427eb955a8a60db3c5": {
			"balance": "2003010000000000000000"
		},
		"25287b815f5c82380a73b0b13fbaf982be24c4d3": {
			"balance": "40000000000000000000"
		},
		"e75c3b38a58a3f33d55690a5a59766be185e0284": {
			"balance": "500000000000000000000"
		},
		"1940dc9364a852165f47414e27f5002445a4f143": {
			"balance": "10850000000000000000000"
		},
		"e5b826196c0e1bc1119b021cf6d259a610c99670": {
			"balance": "200000000000000000000"
		},
		"82a15cef1d6c8260eaf159ea3f0180d8677dce1c": {
			"balance": "2000000000000000000000"
		},
		"da06044e293c652c467fe74146bf185b21338a1c": {
			"balance": "1000000000000000000000"
		},
		"f815c10a032d13c34b8976fa6e3bd2c9131a8ba9": {
			"balance": "1337000000000000000000"
		},
		"cd95fa423d6fc120274aacde19f4eeb766f10420": {
			"balance": "200000000000000000000"
		},
		"e3a4f83c39f85af9c8b1b312bfe5fc3423afa634": {
			"balance": "28650000000000000000"
		},
		"768ce0daa029b7ded022e5fc574d11cde3ecb517": {
			"balance": "322000000000000000000"
		},
		"e3ec18a74ed43855409a26ade7830de8e42685ef": {
			"balance": "19700000000000000000"
		},
		"b2bdbedf95908476d7148a370cc693743628057f": {
			"balance": "4000000000000000000000"
		},
		"bbb8ffe43f98de8eae184623ae5264e424d0b8d7": {
)E" + R"E(
			"balance": "107600000000000000000"
		},
		"090cebef292c3eb081a05fd8aaf7d39bf07b89d4": {
			"balance": "4000000000000000000000"
		},
		"dd2a233adede66fe1126d6c16823b62a021feddb": {
			"balance": "2000000000000000000000"
		},
		"d8cd64e0284eec53aa4639afc4750810b97fab56": {
			"balance": "20000000000000000000"
		},
		"e5953fea497104ef9ad2d4e5841c271f073519c2": {
			"balance": "704000000000000000000"
		},
		"967d4142af770515dd7062af93498dbfdff29f20": {
			"balance": "20200000000000000000"
		},
		"fd191a35157d781373fb411bf9f25290047c5eef": {
			"balance": "1000000000000000000000"
		},
		"8967d7b9bdb7b4aed22e65a15dc803cb7a213f10": {
			"balance": "400000000000000000000"
		},
		"51e43fe0d25c782860af81ea89dd793c13f0cbb1": {
			"balance": "60000000000000000000"
		},
		"a38476691d34942eea6b2f76889223047db4617a": {
			"balance": "2000000000000000000000"
		},
		"1321ccf29739b974e5a516f18f3a843671e39642": {
			"balance": "4000000000000000000000"
		},
		"4d71a6eb3d7f327e1834278e280b039eddd31c2f": {
			"balance": "6000000000000000000000"
		},
		"dc2d15a69f6bb33b246aef40450751c2f6756ad2": {
			"balance": "1996000000000000000000"
		},
		"ec89f2b678a1a15b9134ec5eb70c6a62071fbaf9": {
			"balance": "200000000000000000000"
		},
		"27bf943c1633fe32f8bcccdb6302b407a5724e44": {
			"balance": "940229000000000000000"
		},
		"d0a6c6f9e9c4b383d716b31de78d56414de8fa91": {
			"balance": "300000000000000000000"
		},
		"7b6175ec9befc738249535ddde34688cd36edf25": {
			"balance": "10000000000000000000000"
		},
		"41ce79950935cff55bf78e4ccec2fe631785db95": {
			"balance": "2000000000000000000000"
		},
		"5598b3a79a48f32b1f5fc915b87b645d805d1afe": {
			"balance": "500000000000000000000"
		},
		"5c4881165cb42bb82e97396c8ef44adbf173fb99": {
			"balance": "110600000000000000000"
		},
		"25b0533b81d02a617b9229c7ec5d6f2f672e5b5a": {
			"balance": "1000000000000000000000"
		},
		"015f097d9acddcddafaf2a107eb93a40fc94b04c": {
			"balance": "20000000000000000000000"
		},
		"b84b53d0bb125656cddc52eb852ab71d7259f3d5": {
			"balance": "16000000000000000000000"
		},
		"1a79c7f4039c67a39d7513884cdc0e2c34222490": {
			"balance": "20000000000000000000"
		},
		"926209b7fda54e8ddb9d9e4d3d19ebdc8e88c29f": {
			"balance": "2000000000000000000000"
		},
		"c2fe7d75731f636dcd09dbda0671393ba0c82a7d": {
			"balance": "2200000000000000000000"
		},
		"30248d58e414b20fed3a6c482b59d9d8f5a4b7e2": {
			"balance": "60000000000000000000"
		},
		"d0e194f34b1db609288509ccd2e73b6131a2538b": {
			"balance": "999972000000000000000"
		},
		"e8f29969e75c65e01ce3d86154207d0a9e7c76f2": {
			"balance": "2991807000000000000000"
		},
		"cb93199b9c90bc4915bd859e3d42866dc8c18749": {
			"balance": "231800000000000000000"
		},
		"e6fe0afb9dcedd37b2e22c451ba6feab67348033": {
			"balance": "10000000000000000000000"
		},
		"82f854c9c2f087dffa985ac8201e626ca5467686": {
			"balance": "100000000000000000000000"
		},
		"63bb664f9117037628594da7e3c5089fd618b5b5": {
			"balance": "20000000000000000000"
		},
		"f8d17424c767bea31205739a2b57a7277214eebe": {
			"balance": "42000000000000000000"
)E" + R"E(
		},
		"4ca8db4a5efefc80f4cd9bbcccb03265931332b6": {
			"balance": "200000000000000000000"
		},
		"c56e6b62ba6e40e52aab167d21df025d0055754b": {
			"balance": "2000000000000000000000"
		},
		"0d8c40a79e18994ff99ec251ee10d088c3912e80": {
			"balance": "114600000000000000000"
		},
		"40a331195b977325c2aa28fa2f42cb25ec3c253c": {
			"balance": "2000000000000000000000"
		},
		"a2c5854ff1599f98892c5725d262be1da98aadac": {
			"balance": "314315000000000000000"
		},
		"23ab09e73f87aa0f3be0139df0c8eb6be5634f95": {
			"balance": "8000000000000000000000"
		},
		"b8040536958d5998ce4bec0cfc9c2204989848e9": {
			"balance": "24472420000000000000000"
		},
		"42d6b263d9e9f4116c411424fc9955783c763030": {
			"balance": "2000000000000000000000"
		},
		"c496cbb0459a6a01600fc589a55a32b454217f9d": {
			"balance": "274000000000000000000"
		},
		"48302c311ef8e5dc664158dd583c81194d6e0d58": {
			"balance": "3364760000000000000000"
		},
		"d5b284040130abf7c1d163712371cc7e28ad66da": {
			"balance": "1970000000000000000000"
		},
		"d22f0ca4cd479e661775053bcc49e390f670dd8a": {
			"balance": "1000000000000000000000"
		},
		"e597f083a469c4591c3d2b1d2c772787befe27b2": {
			"balance": "280000000000000000000"
		},
		"668b6ba8ab08eace39c502ef672bd5ccb6a67a20": {
			"balance": "31135320000000000000000"
		},
		"a3bff1dfa9971668360c0d82828432e27bf54e67": {
			"balance": "200000000000000000000"
		},
		"ee655bb4ee0e8d5478526fb9f15e4064e09ff3dd": {
			"balance": "200000000000000000000"
		},
		"121f855b70149ac83473b9706fb44d47828b983b": {
			"balance": "1400000000000000000000"
		},
		"20a15256d50ce058bf0eac43aa533aa16ec9b380": {
			"balance": "20000000000000000000"
		},
		"69bcfc1d43b4ba19de7b274bdffb35139412d3d7": {
			"balance": "985000000000000000000"
		},
		"db288f80ffe232c2ba47cc94c763cf6fc9b82b0d": {
			"balance": "85000000000000000000"
		},
		"e1cb83ec5eb6f1eeb85e99b2fc63812fde957184": {
			"balance": "20000000000000000000000"
		},
		"a419a984142363267575566089340eea0ea20819": {
			"balance": "1999944000000000000000"
		},
		"8489f6ad1d9a94a297789156899db64154f1dbb5": {
			"balance": "358849000000000000000"
		},
		"d609bf4f146eea6b0dc8e06ddcf4448a1fccc9fa": {
			"balance": "2000000000000000000000"
		},
		"df1fa2e20e31985ebe2c0f0c93b54c0fb67a264b": {
			"balance": "200000000000000000000"
		},
		"efe8ff87fc260e0767638dd5d02fc4672e0ec06d": {
			"balance": "2000000000000000000000"
		},
		"eef1bbb1e5a83fde8248f88ee3018afa2d1332eb": {
			"balance": "200000000000000000000"
		},
		"4b3aab335ebbfaa870cc4d605e7d2e74c668369f": {
			"balance": "60000000000000000000000"
		},
		"8f4fb1aea7cd0f570ea5e61b40a4f4510b6264e4": {
			"balance": "4000000000000000000000"
		},
		"0b0b3862112aeec3a03492b1b05f440eca54256e": {
			"balance": "4000000000000000000000"
		},
		"dff4007931786593b229efe5959f3a4e219e51af": {
			"balance": "4925000000000000000000"
		},
		"fec14e5485de2b3eef5e74c46146db8e454e0335": {
			"balance": "179000000000000000000"
		},
		"ac21c1e5a3d7e0b50681679dd6c792dbca87decb": {
			"balance": "100000000000000000000000"
		},
)E" + R"E(
		"796ebbf49b3e36d67694ad79f8ff36767ac6fab0": {
			"balance": "60800000000000000000"
		},
		"ae7739124ed153052503fc101410d1ffd8cd13b7": {
			"balance": "999942000000000000000"
		},
		"86026cad3fe4ea1ce7fca260d3d45eb09ea6a364": {
			"balance": "200000000000000000000"
		},
		"b2fc84a3e50a50af02f94da0383ed59f71ff01d7": {
			"balance": "30000000000000000000000"
		},
		"bbab000b0408ed015a37c04747bc461ab14e151b": {
			"balance": "6000000000000000000000"
		},
		"c4ff6fbb1f09bd9e102ba033d636ac1c4c0f5304": {
			"balance": "1000000000000000000000"
		},
		"cc606f511397a38fc7872bd3b0bd03c71bbd768b": {
			"balance": "1000000000000000000000"
		},
		"f346d7de92741c08fc58a64db55b062dde012d14": {
			"balance": "295106000000000000000"
		},
		"33f15223310d44de8b6636685f3a4c3d9c5655a5": {
			"balance": "250500000000000000000"
		},
		"3c860e2e663f46db53427b29fe3ea5e5bf62bbcc": {
			"balance": "98500000000000000000"
		},
		"acb94338554bc488cc88ae2d9d94080d6bdf8410": {
			"balance": "1000000000000000000000"
		},
		"9c5cc111092c122116f1a85f4ee31408741a7d2f": {
			"balance": "492500000000000000000"
		},
		"5f76f0a306269c78306b3d650dc3e9c37084db61": {
			"balance": "2400000000000000000000"
		},
		"2c0cc3f951482cc8a2925815684eb9f94e060200": {
			"balance": "6000000000000000000000"
		},
		"b74372dbfa181dc9242f39bf1d3731dffe2bdacf": {
			"balance": "2000000000000000000000"
		},
		"3bab4b01a7c84ba13feea9b0bb191b77a3aadca3": {
			"balance": "200000000000000000000"
		},
		"39aa05e56d7d32385421cf9336e90d3d15a9f859": {
			"balance": "26000000000000000000"
		},
		"4a52bad20357228faa1e996bed790c93674ba7d0": {
			"balance": "1337000000000000000000"
		},
		"ff128f4b355be1dc4a6f94fa510d7f15d53c2aff": {
			"balance": "2720000000000000000000"
		},
		"92793ac5b37268774a7130de2bbd330405661773": {
			"balance": "40110000000000000000"
		},
		"db19a3982230368f0177219cb10cb259cdb2257c": {
			"balance": "2000000000000000000000"
		},
		"8d1794da509cb297053661a14aa892333231e3c1": {
			"balance": "199600000000000000000"
		},
		"9b7c8810cc7cc89e804e6d3e38121850472877fe": {
			"balance": "2000000000000000000000"
		},
		"ed3cbc3782cebd67989b305c4133b2cde32211eb": {
			"balance": "400000000000000000000"
		},
		"8532490897bbb4ce8b7f6b837e4cba848fbe9976": {
			"balance": "100000000000000000000"
		},
		"c384ac6ee27c39e2f278c220bdfa5baed626d9d3": {
			"balance": "600000000000000000000"
		},
		"b1459285863ea2db3759e546ceb3fb3761f5909c": {
			"balance": "1122309000000000000000"
		},
		"634efc24371107b4cbf03f79a93dfd93e431d5fd": {
			"balance": "1221341000000000000000"
		},
		"ef9f59aeda418c1494682d941aab4924b5f4929a": {
			"balance": "100000000000000000000000"
		},
		"e7311c9533f0092c7248c9739b5b2c864a34b1ce": {
			"balance": "2803436000000000000000"
		},
		"e6e621eaab01f20ef0836b7cad47464cb5fd3c96": {
			"balance": "316014000000000000000"
		},
		"cd102cd6db3df14ad6af0f87c72479861bfc3d24": {
			"balance": "2000000000000000000000"
		},
		"005a9c03f69d17d66cbb8ad721008a9ebbb836fb": {
			"balance": "2000000000000000000000"
		},
		"a072cebe62a9e9f61cc3fbf88a9efbfe3e9a8d70": {
)E" + R"E(
			"balance": "400000000000000000000"
		},
		"f2ab1161750244d0ecd048ee0d3e51abb143a2fd": {
			"balance": "1235800000000000000000"
		},
		"f686785b89720b61145fea80978d6acc8e0bc196": {
			"balance": "4000000000000000000000"
		},
		"0a2b4fc5d81ace67dc4bba03f7b455413d46fe3d": {
			"balance": "197000000000000000000"
		},
		"c32ec7e42ad16ce3e2555ad4c54306eda0b26758": {
			"balance": "2000000000000000000000"
		},
		"f3fa723552a5d0512e2b62f48dca7b2b8105305b": {
			"balance": "137000000000000000000"
		},
		"6dc3f92baa1d21dab7382b893261a0356fa7c187": {
			"balance": "1730000000000000000000"
		},
		"4627c606842671abde8295ee5dd94c7f549534f4": {
			"balance": "286600000000000000000"
		},
		"e39e46e15d22ce56e0c32f1877b7d1a264cf94f3": {
			"balance": "20000000000000000000000"
		},
		"d7d157e4c0a96437a6d285741dd23ec4361fa36b": {
			"balance": "2000000000000000000000"
		},
		"68f8f45155e98c5029a4ebc5b527a92e9fa83120": {
			"balance": "4436101000000000000000"
		},
		"9aba2b5e27ff78baaab5cdc988b7be855cebbdce": {
			"balance": "9999000000000000000000"
		},
		"66b39837cb3cac8a802afe3f12a258bbca62dacd": {
			"balance": "400000000000000000000"
		},
		"d39b7cbc94003fc948f0cde27b100db8ccd6e063": {
			"balance": "400000000000000000000"
		},
		"3db9ed7f024c7e26372feacf2b050803445e3810": {
			"balance": "1285600000000000000000"
		},
		"3fbc1e4518d73400c6d046359439fb68ea1a49f4": {
			"balance": "16400000000000000000000"
		},
		"e3da4f3240844c9b6323b4996921207122454399": {
			"balance": "11539639000000000000000"
		},
		"09afa73bc047ef46b977fd9763f87286a6be68c6": {
			"balance": "501500000000000000000"
		},
		"1dbe8e1c2b8a009f85f1ad3ce80d2e05350ee39c": {
			"balance": "135400000000000000000"
		},
		"2c5a2d0abda03bbe215781b4ff296c8c61bdbaf6": {
			"balance": "30617000000000000000"
		},
		"9a9d1dc0baa77d6e20c3d849c78862dd1c054c87": {
			"balance": "880000000000000000000"
		},
		"3ccef88679573947e94997798a1e327e08603a65": {
			"balance": "807700000000000000000"
		},
		"850b9db18ff84bf0c7da49ea3781d92090ad7e64": {
			"balance": "2600000000000000000000"
		},
		"361c75931696bc3d427d93e76c77fd13b241f6f4": {
			"balance": "549212000000000000000"
		},
		"c8f2b320e6dfd70906c597bad2f9501312c78259": {
			"balance": "1504800000000000000000"
		},
		"8dc1d5111d09af25fdfcac455c7cec283e6d6775": {
			"balance": "2000000000000000000000"
		},
		"cd7ece086b4b619b3b369352ee38b71ddb06439a": {
			"balance": "200000000000000000000"
		},
		"f607c2150d3e1b99f24fa1c7d540add35c4ebe1e": {
			"balance": "3098020000000000000000"
		},
		"32485c818728c197fea487fbb6e829159eba8370": {
			"balance": "1053893000000000000000"
		},
		"8e670815fb67aeaea57b86534edc00cdf564fee5": {
			"balance": "3300000000000000000000"
		},
		"10df681506e34930ac7a5c67a54c3e89ce92b981": {
			"balance": "2153800000000000000000"
		},
		"1cf2eb7a8ccac2adeaef0ee87347d535d3b94058": {
			"balance": "2000000000000000000000"
		},
		"f0dc43f205619127507b2b1c1cfdf32d28310920": {
			"balance": "301973000000000000000"
		},
		"f2c2904e9fa664a11ee25656d8fd2cc0d9a522a0": {
			"balance": "13370000000000000000"
)E" + R"E(
		},
		"70670fbb05d33014444b8d1e8e7700258b8caa6d": {
			"balance": "2000000000000000000000"
		},
		"5160ed612e1b48e73f3fc15bc4321b8f23b8a24b": {
			"balance": "562800000000000000000"
		},
		"54a62bf9233e146ffec3876e45f20ee8414adeba": {
			"balance": "10000000000000000000000"
		},
		"26d4ec17d5ceb2c894bdc59d0a6a695dad2b43cc": {
			"balance": "2935300000000000000000"
		},
		"205fc843e19a4913d1881eb69b69c0fa3be5c50b": {
			"balance": "9700000000000000000000"
		},
		"e001aba77c02e172086c1950fffbcaa30b83488f": {
			"balance": "1970000000000000000000"
		},
		"21efbca09b3580b98e73f5b2f7f4dc0bf02c529c": {
			"balance": "2000000000000000000000"
		},
		"c4d916574e68c49f7ef9d3d82d1638b2b7ee0985": {
			"balance": "1580000000000000000000"
		},
		"cab0d32cf3767fa6b3537c84328baa9f50458136": {
			"balance": "8960000000000000000000"
		},
		"7ce4686446f1949ebed67215eb0d5a1dd72c11b8": {
			"balance": "2217776000000000000000"
		},
		"7837fcb876da00d1eb3b88feb3df3fa4042fac82": {
			"balance": "1760000000000000000000"
		},
		"71e38ff545f30fe14ca863d4f5297fd48c73a5ce": {
			"balance": "3580000000000000000000"
		},
		"e528a0e5a267d667e9393a6584e19b34dc9be973": {
			"balance": "5600000000000000000000"
		},
		"c5374928cdf193705443b14cc20da423473cd9cf": {
			"balance": "138139000000000000000"
		},
		"e406f5dd72cab66d8a6ecbd6bfb494a7b6b09afe": {
			"balance": "100000000000000000000"
		},
		"d7ef340e66b0d7afcce20a19cb7bfc81da33d94e": {
			"balance": "3000000000000000000000"
		},
		"e012db453827a58e16c1365608d36ed658720507": {
			"balance": "2000000000000000000000"
		},
		"d59638d3c5faa7711bf085745f9d5bdc23d498d8": {
			"balance": "2000000000000000000000"
		},
		"008fc7cbadffbd0d7fe44f8dfd60a79d721a1c9c": {
			"balance": "1000000000000000000000"
		},
		"8a3470282d5e2a2aefd7a75094c822c4f5aeef8a": {
			"balance": "242743000000000000000"
		},
		"38b3965c21fa893931079beacfffaf153678b6eb": {
			"balance": "170374000000000000000"
		},
		"57dd9471cbfa262709f5f486bcb774c5f527b8f8": {
			"balance": "197000000000000000000"
		},
		"5a60c924162873fc7ea4da7f972e350167376031": {
			"balance": "83583000000000000000"
		},
		"b9013c51bd078a098fae05bf2ace0849c6be17a5": {
			"balance": "80000000000000000000"
		},
		"dc23b260fcc26e7d10f4bd044af794579460d9da": {
			"balance": "500038000000000000000"
		},
		"45db03bccfd6a5f4d0266b82a22a368792c77d83": {
			"balance": "8000000000000000000000"
		},
		"3e0cbe6a6dcb61f110c45ba2aa361d7fcad3da73": {
			"balance": "8022000000000000000000"
		},
		"42d3a5a901f2f6bd9356f112a70180e5a1550b60": {
			"balance": "925000000000000000000"
		},
		"47219229e8cd56659a65c2a943e2dd9a8f4bfd89": {
			"balance": "1520000000000000000000"
		},
		"a20d071b1b003063497d7990e1249dabf36c35f7": {
			"balance": "1000000000000000000000"
		},
		"6835c8e8b74a2ca2ae3f4a8d0f6b954a3e2a8392": {
			"balance": "60140000000000000000"
		},
		"0c2d5c920538e953caaf24f0737f554cc6927742": {
			"balance": "1000000000000000000000"
		},
		"eedf6c4280e6eb05b934ace428e11d4231b5905b": {
			"balance": "200000000000000000000"
		},
)E" + R"E(
		"ffa696ecbd787e66abae4fe87b635f07ca57d848": {
			"balance": "1337000000000000000000"
		},
		"3e81772175237eb4cbe0fe2dcafdadffeb6a1999": {
			"balance": "8800000000000000000000"
		},
		"b44783c8e57b480793cbd69a45d90c7b4f0c48ac": {
			"balance": "20000000000000000000"
		},
		"f84f090adf3f8db7e194b350fbb77500699f66fd": {
			"balance": "1970000000000000000000"
		},
		"2e9824b5c132111bca24ddfba7e575a5cd7296c1": {
			"balance": "17201900000000000000000"
		},
		"5cce72d068c7c3f55b1d2819545e77317cae8240": {
			"balance": "1940000000000000000000"
		},
		"d815e1d9f4e2b5e57e34826b7cfd8881b8546890": {
			"balance": "17300000000000000000"
		},
		"f901c00fc1db88b69c4bc3252b5ca70ea6ee5cf6": {
			"balance": "400000000000000000000"
		},
		"a960b1cadd3b5c1a8e6cb3abcaf52ee7c3d9fa88": {
			"balance": "1522704000000000000000"
		},
		"f7e45a12aa711c709acefe95f33b78612d2ad22a": {
			"balance": "66230000000000000000000"
		},
		"c332df50b13c013490a5d7c75dbfa366da87b6d6": {
			"balance": "4000000000000000000000"
		},
		"d467cf064c0871989b90d8b2eb14ccc63b360823": {
			"balance": "200000000000000000000"
		},
		"b9144b677c2dc614ceefdf50985f1183208ea64c": {
			"balance": "2000000000000000000000"
		},
		"ea7c4d6dc729cd6b157c03ad237ca19a209346c3": {
			"balance": "2000000000000000000000"
		},
		"9c9de44724a4054da0eaa605abcc802668778bea": {
			"balance": "200020000000000000000"
		},
		"d7140c8e5a4307fab0cc27badd9295018bf87970": {
			"balance": "109600000000000000000"
		},
		"c33acdb3ba1aab27507b86b15d67faf91ecf6293": {
			"balance": "2000000000000000000000"
		},
		"db2a0c9ab64df58ddfb1dbacf8ba0d89c85b31b4": {
			"balance": "4000000000000000000000"
		},
		"bfcb9730246304700da90b4153e71141622e1c41": {
			"balance": "1000000000000000000000"
		},
		"07dc8c8b927adbedfa8f5d639b4352351f2f36d2": {
			"balance": "314382000000000000000"
		},
		"2d5391e938b34858cf965b840531d5efda410b09": {
			"balance": "1400000000000000000000"
		},
		"0b5e2011ebc25a007f21362960498afb8af280fb": {
			"balance": "2000000000000000000000"
		},
		"ed9fb1f5af2fbf7ffc5029cee42b70ff5c275bf5": {
			"balance": "280000000000000000000"
		},
		"a3232d068d50064903c9ebc563b515acc8b7b097": {
			"balance": "2002000000000000000000"
		},
		"66274fea82cd30b6c29b23350e4f4f3d310a5899": {
			"balance": "2070000000000000000000"
		},
		"dbfb1bb464b8a58e500d2ed8de972c45f5f1c0fb": {
			"balance": "1600000000000000000000"
		},
		"a1f8d8bcf90e777f19b3a649759ad95027abdfc3": {
			"balance": "200000000000000000000"
		},
		"5bd23547477f6d09d7b2a005c5ee650c510c56d7": {
			"balance": "10000000000000000000000"
		},
		"ec3b8b58a12703e581ce5ffd7e21c57d1e5c663f": {
			"balance": "1700000000000000000000"
		},
		"54310b3aa88703a725dfa57de6e646935164802c": {
			"balance": "1910000000000000000000"
		},
		"8f41b1fbf54298f5d0bc2d122f4eb95da4e5cd3d": {
			"balance": "354200000000000000000"
		},
		"c80b36d1beafba5fcc644d60ac6e46ed2927e7dc": {
			"balance": "13370000000000000000"
		},
		"1ea492bce1ad107e337f4bd4a7ac9a7babcccdab": {
			"balance": "100000000000000000000"
		},
		"aaf023fef290a49bb78bb7abc95d669c50d528b0": {
)E" + R"E(
			"balance": "200000000000000000000"
		},
		"80b79f338390d1ba1b3737a29a0257e5d91e0731": {
			"balance": "20000000000000000000"
		},
		"f382e4c20410b951089e19ba96a2fee3d91cce7e": {
			"balance": "5054000000000000000000"
		},
		"0748713145ef83c3f0ef4d31d823786f7e9cc689": {
			"balance": "4500000000000000000000"
		},
		"21e219c89ca8ac14ae4cba6130eeb77d9e6d3962": {
			"balance": "789580000000000000000"
		},
		"ca9a042a6a806ffc92179500d24429e8ab528117": {
			"balance": "1100000000000000000000"
		},
		"bcc9593b2da6df6a34d71b1aa38dacf876f95b88": {
			"balance": "20000000000000000000"
		},
		"d1438267231704fc7280d563adf4763844a80722": {
			"balance": "200000000000000000000"
		},
		"4989e1ab5e7cd00746b3938ef0f0d064a2025ba5": {
			"balance": "2000000000000000000000"
		},
		"bd4b60faec740a21e3071391f96aa534f7c1f44e": {
			"balance": "182000000000000000000"
		},
		"8c7cb4e48b25031aa1c4f92925d631a8c3edc761": {
			"balance": "1000000000000000000000"
		},
		"322788b5e29bf4f5f55ae1ddb32085fda91b8ebe": {
			"balance": "200000000000000000000"
		},
		"f15e182c4fbbad79bd93342242d4dccf2be58925": {
			"balance": "1940000000000000000000"
		},
		"1548b770a5118ede87dba2f690337f616de683ab": {
			"balance": "527558000000000000000"
		},
		"69c2d835f13ee90580408e6a3283c8cca6a434a2": {
			"balance": "656000000000000000000"
		},
		"a1e4380a3b1f749673e270229993ee55f35663b4": {
			"balance": "2000000000000000000000"
		},
		"c7675e5647b9d8daf4d3dff1e552f6b07154ac38": {
			"balance": "180000000000000000000"
		},
		"a02c1e34064f0475f7fa831ccb25014c3aa31ca2": {
			"balance": "60000000000000000000"
		},
		"517c75430de401c341032686112790f46d4d369e": {
			"balance": "388000000000000000000"
		},
		"29681d9912ddd07eaabb88d05d90f766e862417d": {
			"balance": "1000000000000000000000"
		},
		"544dda421dc1eb73bb24e3e56a248013b87c0f44": {
			"balance": "1970000000000000000000"
		},
		"2ab97e8d59eee648ab6caf8696f89937143864d6": {
			"balance": "3820000000000000000000"
		},
		"79c130c762b8765b19d2abc9a083ab8f3aad7940": {
			"balance": "3940000000000000000000"
		},
		"f9650d6989f199ab1cc479636ded30f241021f65": {
			"balance": "850000000000000000000"
		},
		"d1c96e70f05ae0e6cd6021b2083750a7717cde56": {
			"balance": "500000000000000000000"
		},
		"88106c27d20b74b4b98ca62b232bd5c97411171f": {
			"balance": "197000000000000000000"
		},
		"37ab66083a4fa23848b886f9e66d79cdc150cc70": {
			"balance": "88510000000000000000000"
		},
		"8e6156336be2cdbe32140df08a2ba55fd0a58463": {
			"balance": "74480000000000000000"
		},
		"2982d76a15f847dd41f1922af368fe678d0e681e": {
			"balance": "100000000000000000000"
		},
		"209e8e29d33beae8fb6baa783d133e1d9ec1bc0b": {
			"balance": "835000000000000000000"
		},
		"b325674c01e3f7290d5226339fbeac67d221279f": {
			"balance": "2800000000000000000000"
		},
		"f20c9a99b74759d782f25c1ceca802a27e0b436c": {
			"balance": "1670000000000000000000"
		},
		"61bf84d5ab026f58c873f86ff0dfca82b55733ae": {
			"balance": "2000000000000000000000"
		},
		"0734a0a81c9562f4d9e9e10a8503da15db46d76e": {
			"balance": "18200000000000000000"
)E" + R"E(
		},
		"0521bc3a9f8711fecb10f50797d71083e341eb9d": {
			"balance": "20000000000000000000"
		},
		"3301d9ca2f3bfe026279cd6819f79a293d98156e": {
			"balance": "50000000000000000000000"
		},
		"549d51af29f724c967f59423b85b2681e7b15136": {
			"balance": "3760000000000000000000"
		},
		"2053ac97548a0c4e8b80bc72590cd6a098fe7516": {
			"balance": "187000000000000000000"
		},
		"aa321fdbd449180db8ddd34f0fe906ec18ee0914": {
			"balance": "685000000000000000000"
		},
		"697f55536bf85ada51841f0287623a9f0ed09a17": {
			"balance": "10000000000000000000000"
		},
		"df57353aaff2aadb0a04f9014e8da7884e86589c": {
			"balance": "152800000000000000000"
		},
		"6807ddc88db489b033e6b2f9a81553571ab3c805": {
			"balance": "29944000000000000000"
		},
		"90057af9aa66307ec9f033b29724d3b2f41eb6f9": {
			"balance": "121930000000000000000000"
		},
		"3ff836b6f57b901b440c30e4dbd065cf37d3d48c": {
			"balance": "200000000000000000000"
		},
		"91051764af6b808e4212c77e30a5572eaa317070": {
			"balance": "1000000000000000000000"
		},
		"7faa30c31519b584e97250ed2a3cf3385ed5fd50": {
			"balance": "2000000000000000000000"
		},
		"fb842ca2c5ef133917a236a0d4ac40690110b038": {
			"balance": "306000000000000000000"
		},
		"aa167026d39ab7a85635944ed9edb2bfeba11850": {
			"balance": "8298000000000000000000"
		},
		"57beea716cbd81700a73d67f9ff039529c2d9025": {
			"balance": "200000000000000000000"
		},
		"654b7e808799a83d7287c67706f2abf49a496404": {
			"balance": "1970000000000000000000"
		},
		"dde8f0c31b7415511dced1cd7d46323e4bd12232": {
			"balance": "1610000000000000000000"
		},
		"8667fa1155fed732cfb8dca5a0d765ce0d0705ed": {
			"balance": "81770000000000000000"
		},
		"905526568ac123afc0e84aa715124febe83dc87c": {
			"balance": "17900000000000000000"
		},
		"8e98766524b0cf2747c50dd43b9567594d9731de": {
			"balance": "1997200000000000000000"
		},
		"c6df2075ebd240d44869c2be6bdf82e63d4ef1f5": {
			"balance": "20000000000000000000"
		},
		"2ff5cab12c0d957fd333f382eeb75107a64cb8e8": {
			"balance": "10000000000000000000000"
		},
		"3055efd26029e0d11b930df4f53b162c8c3fd2ce": {
			"balance": "499938000000000000000"
		},
		"b2c53efa33fe4a3a1a80205c73ec3b1dbcad0602": {
			"balance": "1918595000000000000000"
		},
		"766b3759e8794e926dac473d913a8fb61ad0c2c9": {
			"balance": "86500000000000000000"
		},
		"882aa798bf41df179f85520130f15ccdf59b5e58": {
			"balance": "2000000000000000000000"
		},
		"80b23d380b825c46e0393899a85556462da0e18c": {
			"balance": "2000000000000000000000"
		},
		"51f4663ab44ff79345f427a0f6f8a6c8a53ff234": {
			"balance": "20000000000000000000000"
		},
		"8d5ef172bf77315ea64e85d0061986c794c6f519": {
			"balance": "3940000000000000000000"
		},
		"75ac547017134c04ae1e11d60e63ec04d18db4ef": {
			"balance": "6000000000000000000000"
		},
		"ce1b0cb46aaecfd79b880cad0f2dda8a8dedd0b1": {
			"balance": "20000000000000000000"
		},
		"21408b4d7a2c0e6eca4143f2cacdbbccba121bd8": {
			"balance": "20000000000000000000000"
		},
		"9c526a140683edf1431cfaa128a935e2b614d88b": {
			"balance": "111000000000000000000"
		},
)E" + R"E(
		"599728a78618d1a17b9e34e0fed8e857d5c40622": {
			"balance": "14000000000000000000000"
		},
		"6ac4d4be2db0d99da3faaaf7525af282051d6a90": {
			"balance": "80185000000000000000"
		},
		"785c8ea774d73044a734fa790a1b1e743e77ed7c": {
			"balance": "238750000000000000000"
		},
		"ff2726294148b86c78a9372497e459898ed3fee3": {
			"balance": "1970000000000000000000"
		},
		"68a86c402388fddc59028fec7021e98cbf830eac": {
			"balance": "19100000000000000000"
		},
		"6121af398a5b2da69f65c6381aec88ce9cc6441f": {
			"balance": "640000000000000000000"
		},
		"5a6686b0f17e07edfc59b759c77d5bef164d3879": {
			"balance": "1490000000000000000000"
		},
		"a2d38de1c73906f6a7ca6efeb97cf6f69cc421be": {
			"balance": "1000000000000000000000"
		},
		"ae3f98a443efe00f3e711d525d9894dc9a61157b": {
			"balance": "295500000000000000000"
		},
		"5f1c8a04c90d735b8a152909aeae636fb0ce1665": {
			"balance": "6999974000000000000000"
		},
		"d687cec0059087fdc713d4d2d65e77daefedc15f": {
			"balance": "60000000000000000000"
		},
		"845203750f7148a9aa262921e86d43bf641974fd": {
			"balance": "100000000000000000000"
		},
		"64464a6805b462412a901d2db8174b06c22deea6": {
			"balance": "475600000000000000000"
		},
		"053471cd9a41925b3904a5a8ffca3659e034be23": {
			"balance": "199600000000000000000"
		},
		"911ff233e1a211c0172c92b46cf997030582c83a": {
			"balance": "1970000000000000000000"
		},
		"d930b27a78876485d0f48b70dd5336549679ca8f": {
			"balance": "40000000000000000000"
		},
		"6ba9b21b35106be159d1c1c2657ac56cd29ffd44": {
			"balance": "4480000000000000000000"
		},
		"ebac2b4408ef5431a13b8508e86250982114e145": {
			"balance": "4000000000000000000000"
		},
		"931df34d1225bcd4224e63680d5c4c09bce735a6": {
			"balance": "68000000000000000000"
		},
		"23eb6fd85671a9063ab7678ebe265a20f61a02b3": {
			"balance": "2000000000000000000000"
		},
		"b32af3d3e8d075344926546f2e32887bf93b16bd": {
			"balance": "200000000000000000000"
		},
		"8261fa230c901d43ff579f4780d399f31e6076bc": {
			"balance": "2000000000000000000000"
		},
		"84a74ceecff65cb93b2f949d773ef1ad7fb4a245": {
			"balance": "92998000000000000000"
		},
		"da982e9643ffece723075a40fe776e5ace04b29b": {
			"balance": "160884000000000000000"
		},
		"ba70e8b4759c0c3c82cc00ac4e9a94dd5bafb2b8": {
			"balance": "890342000000000000000"
		},
		"82f2e991fd324c5f5d17768e9f61335db6319d6c": {
			"balance": "500000000000000000000"
		},
		"3e84b35c5b2265507061d30b6f12da033fe6f8b9": {
			"balance": "1790000000000000000000"
		},
		"2895e80999d406ad592e2b262737d35f7db4b699": {
			"balance": "1940000000000000000000"
		},
		"65f534346d2ffb787fa9cf185d745ba42986bd6e": {
			"balance": "500000000000000000000"
		},
		"c7368b9709a5c1b51c0adf187a65df14e12b7dba": {
			"balance": "9489681000000000000000"
		},
		"ba176dbe3249e345cd4fa967c0ed13b24c47e586": {
			"balance": "399990000000000000000"
		},
		"cff6a6fe3e9a922a12f21faa038156918c4fcb9c": {
			"balance": "78800000000000000000"
		},
		"bcbd31252ec288f91e298cd812c92160e738331a": {
			"balance": "1975802000000000000000"
		},
		"5543dd6d169eec8a213bbf7a8af9ffd15d4ff759": {
)E" + R"E(
			"balance": "18200000000000000000"
		},
		"b65bd780c7434115162027565223f44e5498ff8c": {
			"balance": "19999800000000000000000"
		},
		"4cadf573ce4ceec78b8e1b21b0ed78eb113b2c0e": {
			"balance": "2000000000000000000000"
		},
		"04aafc8ae5ce6f4903c89d7fac9cb19512224777": {
			"balance": "500000000000000000000"
		},
		"fdc4d4765a942f5bf96931a9e8cc7ab8b757ff4c": {
			"balance": "87000000000000000000000"
		},
		"38c7851f5ffd4cee98df30f3b25597af8a6ca263": {
			"balance": "2631920000000000000000"
		},
		"0e320219838e859b2f9f18b72e3d4073ca50b37d": {
			"balance": "2000000000000000000000"
		},
		"bbbf39b1b67995a42241504f9703d2a14a515696": {
			"balance": "1580000000000000000000"
		},
		"5b800bfd1b3ed4a57d875aed26d42f1a7708d72a": {
			"balance": "6392000000000000000000"
		},
		"5b85e60e2af0544f2f01c64e2032900ebd38a3c7": {
			"balance": "2000000000000000000000"
		},
		"c9ac01c3fb0929033f0ccc7e1acfeaaba7945d47": {
			"balance": "12459235000000000000000"
		},
		"f355d3ec0cfb907d8dbb1bf3464e458128190bac": {
			"balance": "4925600000000000000000"
		},
		"69c08d744754de709ce96e15ae0d1d395b3a2263": {
			"balance": "1000000000000000000000"
		},
		"cef77451dfa2c643e00b156d6c6ff84e2373eb66": {
			"balance": "188000000000000000000"
		},
		"f3034367f87d24d3077fa9a2e38a8b0ccb1104ef": {
			"balance": "1000000000000000000000"
		},
		"73473e72115110d0c3f11708f86e77be2bb0983c": {
			"balance": "20000000000000000000"
		},
		"761e6caec189c230a162ec006530193e67cf9d19": {
			"balance": "2000000000000000000000"
		},
		"e9caf827be9d607915b365c83f0d3b7ea8c79b50": {
			"balance": "3000000000000000000000"
		},
		"eda4b2fa59d684b27a810df8978a73df308a63c2": {
			"balance": "4000000000000000000000"
		},
		"065ff575fd9c16d3cb6fd68ffc8f483fc32ec835": {
			"balance": "200000000000000000000"
		},
		"a72ee666c4b35e82a506808b443cebd5c632c7dd": {
			"balance": "800000000000000000000"
		},
		"5b30608c678e1ac464a8994c3b33e5cdf3497112": {
			"balance": "400000000000000000000"
		},
		"b0c7ce4c0dc3c2bbb99cc1857b8a455f611711ce": {
			"balance": "4000000000000000000000"
		},
		"d7274d50804d9c77da93fa480156efe57ba501de": {
			"balance": "1940000000000000000000"
		},
		"a609c26dd350c235e44b2b9c1dddccd0a9d9f837": {
			"balance": "1000000000000000000000"
		},
		"bddfa34d0ebf1b04af53b99b82494a9e3d8aa100": {
			"balance": "12000000000000000000000"
		},
		"fd40242bb34a70855ef0fd90f3802dec2136b327": {
			"balance": "1930600000000000000000"
		},
		"58aed6674affd9f64233272a578dd9386b99c263": {
			"balance": "3400000000000000000000"
		},
		"24434a3e32e54ecf272fe3470b5f6f512f675520": {
			"balance": "5910000000000000000000"
		},
		"a379a5070c503d2fac89b8b3afa080fd45ed4bec": {
			"balance": "19700000000000000000000"
		},
		"37e169a93808d8035698f815c7235613c1e659f2": {
			"balance": "1000000000000000000000"
		},
		"849b116f596301c5d8bb62e0e97a8248126e39f3": {
			"balance": "300000000000000000000"
		},
		"fe7011b698bf3371132d7445b19eb5b094356aee": {
			"balance": "2000000000000000000000"
		},
		"f16de1891d8196461395f9b136265b3b9546f6ef": {
			"balance": "31313000000000000000"
)E" + R"E(
		},
		"6c6564e5c9c24eaaa744c9c7c968c9e2c9f1fbae": {
			"balance": "1357800000000000000000"
		},
		"8bb0212f3295e029cab1d961b04133a1809e7b91": {
			"balance": "2000000000000000000000"
		},
		"408a69a40715e1b313e1354e600800a1e6dc02a5": {
			"balance": "35144000000000000000"
		},
		"ddf0cce1fe996d917635f00712f4052091dff9ea": {
			"balance": "2000000000000000000000"
		},
		"50fef296955588caae74c62ec32a23a454e09ab8": {
			"balance": "1201200000000000000000"
		},
		"d913f0771949753c4726acaa2bd3619c5c20ff77": {
			"balance": "3000000000000000000000"
		},
		"9d6ecfa03af2c6e144b7c4692a86951e902e9e1f": {
			"balance": "3000310000000000000000"
		},
		"ecbe5e1c9ad2b1dccf0a305fc9522f4669dd3ae7": {
			"balance": "5000000000000000000000"
		},
		"33e9b71823952e1f66958c278fc28b1196a6c5a4": {
			"balance": "100000000000000000000"
		},
		"9de20bc37e7f48a80ffd7ad84ffbf1a1abe1738c": {
			"balance": "200000000000000000000"
		},
		"16f313cf8ad000914a0a176dc6a4342b79ec2538": {
			"balance": "2000000000000000000000"
		},
		"991ac7ca7097115f26205eee0ef7d41eb4e311ae": {
			"balance": "20000000000000000000"
		},
		"ddfafdbc7c90f1320e54b98f374617fbd01d109f": {
			"balance": "13370000000000000000"
		},
		"26b11d066588ce74a572a85a6328739212aa8b40": {
			"balance": "2000000000000000000000"
		},
		"ef2c34bb487d3762c3cca782ccdd7a8fbb0a9931": {
			"balance": "180000000000000000000"
		},
		"a9be88ad1e518b0bbb024ab1d8f0e73f790e0c76": {
			"balance": "2800000000000000000000"
		},
		"4a7494cce44855cc80582842be958a0d1c0072ee": {
			"balance": "2400000000000000000000"
		},
		"23569542c97d566018c907acfcf391d14067e87e": {
			"balance": "2000000000000000000000"
		},
		"d252960b0bf6b2848fdead80136db5f507f8be02": {
			"balance": "2000000000000000000000"
		},
		"2c0f5b9df43625798e7e03c1a5fd6a6d091af82b": {
			"balance": "31200000000000000000"
		},
		"a7c9d388ebd873e66b1713448397d0f37f8bd3a8": {
			"balance": "5000000000000000000000"
		},
		"3259bd2fddfbbc6fbad3b6e874f0bbc02cda18b5": {
			"balance": "11886645000000000000000"
		},
		"f287ff52f461117adb3e1daa71932d1493c65f2e": {
			"balance": "3640000000000000000000"
		},
		"c852428d2b586497acd30c56aa13fb5582f84402": {
			"balance": "945600000000000000000"
		},
		"296f00de1dc3bb01d47a8ccd1e5d1dd9a1eb7791": {
			"balance": "1000000000000000000000"
		},
		"817493cd9bc623702a24a56f9f82e3fd48f3cd31": {
			"balance": "2920000000000000000000"
		},
		"7adfedb06d91f3cc7390450b85550270883c7bb7": {
			"balance": "322312000000000000000"
		},
		"8d544c32c07fd0842c761d53a897d6c950bb7599": {
			"balance": "200000000000000000000"
		},
		"86297d730fe0f7a9ee24e08fb1087b31adb306a7": {
			"balance": "2000000000000000000000"
		},
		"f64fe0939a8d1eea2a0ecd9a9730fd7958e33109": {
			"balance": "20600000000000000000"
		},
		"b06eab09a610c6a53d56a946b2c43487ac1d5b2d": {
			"balance": "1000000000000000000000"
		},
		"bae9b82f7299631408659dd74e891cb8f3860fe5": {
			"balance": "1970000000000000000000"
		},
		"0eda80f4ed074aea697aeddf283b63dbca3dc4da": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"ea686c5057093c171c66db99e01b0ececb308683": {
			"balance": "384907000000000000000"
		},
		"425725c0f08f0811f5f006eec91c5c5c126b12ae": {
			"balance": "150000000000000000000"
		},
		"b18e67a5050a1dc9fb190919a33da838ef445014": {
			"balance": "20000000000000000000"
		},
		"8dd484ff8a307364eb66c525a571aac701c5c318": {
			"balance": "4000000000000000000000"
		},
		"6671b182c9f741a0cd3c356c73c23126d4f9e6f4": {
			"balance": "200000000000000000000"
		},
		"ba0249e01d945bef93ee5ec61925e03c5ca509fd": {
			"balance": "4000000000000000000000"
		},
		"b2968f7d35f208871631c6687b3f3daeabc6616c": {
			"balance": "156060000000000000000"
		},
		"a6f62b8a3d7f11220701ab9ffffcb327959a2785": {
			"balance": "506000000000000000000"
		},
		"c885a18aabf4541b7b7b7ecd30f6fae6869d9569": {
			"balance": "2000000000000000000000"
		},
		"33fb577a4d214fe010d32cca7c3eeda63f87ceef": {
			"balance": "1000000000000000000000"
		},
		"be86d0b0438419ceb1a038319237ba5206d72e46": {
			"balance": "999942000000000000000"
		},
		"466292f0e80d43a78774277590a9eb45961214f4": {
			"balance": "970000000000000000000"
		},
		"b33c0323fbf9c26c1d8ac44ef74391d0804696da": {
			"balance": "20000000000000000000"
		},
		"f7bc4c44910d5aedd66ed2355538a6b193c361ec": {
			"balance": "96980000000000000000"
		},
		"d0f04f52109aebec9a7b1e9332761e9fe2b97bb5": {
			"balance": "4000000000000000000000"
		},
		"cb4a914d2bb029f32e5fef5c234c4fec2d2dd577": {
			"balance": "1800000000000000000000"
		},
		"2e619f57abc1e987aa936ae3a2264962e7eb2d9a": {
			"balance": "756000000000000000000"
		},
		"166bf6dab22d841b486c38e7ba6ab33a1487ed8c": {
			"balance": "20000000000000000000000"
		},
		"c3a046e3d2b2bf681488826e32d9c061518cfe8c": {
			"balance": "2600000000000000000000"
		},
		"d082275f745a2cac0276fbdb02d4b2a3ab1711fe": {
			"balance": "30000000000000000000"
		},
		"a701df79f594901afe1444485e6b20c3bda2b9b3": {
			"balance": "1000000000000000000000"
		},
		"dec3eec2640a752c466e2b7e7ee685afe9ac41f4": {
			"balance": "1324245000000000000000"
		},
		"8134dd1c9df0d6c8a5812426bb55c761ca831f08": {
			"balance": "122360000000000000000"
		},
		"bfc57aa666fae28e9f107a49cb5089a4e22151dd": {
			"balance": "1000000000000000000000"
		},
		"c3c2297329a6fd99117e54fc6af379b4d556547e": {
			"balance": "6000000000000000000000"
		},
		"40585200683a403901372912a89834aadcb55fdb": {
			"balance": "2000000000000000000000"
		},
		"cd49bf185e70d04507999f92a4de4455312827d0": {
			"balance": "1000000000000000000000"
		},
		"9c6bc9a46b03ae5404f043dfcf21883e4110cc33": {
			"balance": "200000000000000000000"
		},
		"1f49b86d0d3945590698a6aaf1673c37755ca80d": {
			"balance": "700000000000000000000"
		},
		"efeb1997aad277cc33430e6111ed0943594048b8": {
			"balance": "2000000000000000000000"
		},
		"7c0883054c2d02bc7a852b1f86c42777d0d5c856": {
			"balance": "500000000000000000000"
		},
		"ff49a775814ec00051a795a875de24592ea400d4": {
			"balance": "200000000000000000000000"
		},
		"f039683d7b3d225bc7d8dfadef63163441be41e2": {
			"balance": "34380000000000000000"
		},
		"a3ba0d3a3617b1e31b4e422ce269e873828d5d69": {
)E" + R"E(
			"balance": "850000000000000000000"
		},
		"d116f3dcd5db744bd008887687aa0ec9fd7292aa": {
			"balance": "1000000000000000000000"
		},
		"5719f49b720da68856f4b9e708f25645bdbc4b41": {
			"balance": "640000000000000000000"
		},
		"870796abc0db84af82da52a0ed68734de7e636f5": {
			"balance": "300000000000000000000"
		},
		"68b6854788a7c6496cdbf5f84b9ec5ef392b78bb": {
			"balance": "19700000000000000000000"
		},
		"8c2fbeee8eacc5c5d77c16abd462ee9c8145f34b": {
			"balance": "1940000000000000000000"
		},
		"421684baa9c0b4b5f55338e6f6e7c8e146d41cb7": {
			"balance": "1500000000000000000000"
		},
		"dd26b429fd43d84ec179825324bad5bfb916b360": {
			"balance": "5142000000000000000000"
		},
		"3821862493242c0aeb84b90de05d250c1e50c074": {
			"balance": "322200000000000000000"
		},
		"68a7425fe09eb28cf86eb1793e41b211e57bd68d": {
			"balance": "668500000000000000000"
		},
		"da875e4e2f3cabe4f37e0eaed7d1f6dcc6ffef43": {
			"balance": "2000000000000000000000"
		},
		"c2663f8145dbfec6c646fc5c49961345de1c9f11": {
			"balance": "690000000000000000000"
		},
		"e89c22f1a4e1d4746ecfaa59ed386fee12d51e37": {
			"balance": "44932000000000000000"
		},
		"eff86b5123bcdc17ed4ce8e05b7e12e51393a1f7": {
			"balance": "500000000000000000000"
		},
		"6c3d18704126aa99ee3342ce60f5d4c85f1867cd": {
			"balance": "50000000000000000000"
		},
		"b8d531a964bcea13829620c0ced72422dadb4cca": {
			"balance": "169990000000000000000"
		},
		"7c29d47d57a733f56b9b217063b513dc3b315923": {
			"balance": "4000000000000000000000"
		},
		"bc1e80c181616342ebb3fb3992072f1b28b802c6": {
			"balance": "4000000000000000000000"
		},
		"31313ffd635bf2f3324841a88c07ed146144ceeb": {
			"balance": "1970000000000000000000"
		},
		"cc4feb72df98ff35a138e01761d1203f9b7edf0a": {
			"balance": "7000000000000000000000"
		},
		"741693c30376508513082020cc2b63e9fa92131b": {
			"balance": "1200000000000000000000"
		},
		"aa3135cb54f102cbefe09e96103a1a796718ff54": {
			"balance": "57800000000000000000"
		},
		"ef61155ba009dcdebef10b28d9da3d1bc6c9ced4": {
			"balance": "59100000000000000000"
		},
		"b3c94811e7175b148b281c1a845bfc9bb6fbc115": {
			"balance": "200000000000000000000"
		},
		"96d9cca8f55eea0040ec6eb348a1774b95d93ef4": {
			"balance": "4000000000000000000000"
		},
		"ce62125adec3370ac52110953a4e760be9451e3b": {
			"balance": "152000000000000000000"
		},
		"aca1e6bc64cc3180f620e94dc5b1bcfd8158e45d": {
			"balance": "2000000000000000000000"
		},
		"bc237148d30c13836ffa2cad520ee4d2e5c4eeff": {
			"balance": "1970000000000000000000"
		},
		"0e024e7f029c6aaf3a8b910f5e080873b85795aa": {
			"balance": "1000000000000000000000"
		},
		"7283cd4675da58c496556151dafd80c7f995d318": {
			"balance": "760000000000000000000"
		},
		"39b299327490d72f9a9edff11b83afd0e9d3c450": {
			"balance": "200000000000000000000"
		},
		"5f333a3b2310765a0d1832b9be4c0a03704c1c09": {
			"balance": "1000000000000000000000"
		},
		"5aaf1c31254a6e005fba7f5ab0ec79d7fc2b630e": {
			"balance": "5910000000000000000000"
		},
		"833db42c14163c7be4cab86ac593e06266d699d5": {
			"balance": "174212000000000000000000"
)E" + R"E(
		},
		"f32d25eb0ea2b8b3028a4c7a155dc1aae865784d": {
			"balance": "5710684000000000000000"
		},
		"1fa2319fed8c2d462adf2e17feec6a6f30516e95": {
			"balance": "125300000000000000000"
		},
		"c49cfaa967f3afbf55031061fc4cef88f85da584": {
			"balance": "2000000000000000000000"
		},
		"43db7ff95a086d28ebbfb82fb8fb5f230a5ebccd": {
			"balance": "16100000000000000000"
		},
		"cf3f9128b07203a3e10d7d5755c0c4abc6e2cac2": {
			"balance": "5000000000000000000000"
		},
		"8f4d1e7e4561284a34fef9673c0d34e12af4aa03": {
			"balance": "2000000000000000000000"
		},
		"934af21b7ebfa467e2ced65aa34edd3a0ec71332": {
			"balance": "35420000000000000000000"
		},
		"5d231a70c1dfeb360abd97f616e2d10d39f3cab5": {
			"balance": "400000000000000000000"
		},
		"2d5d7335acb0362b47dfa3a8a4d3f5949544d380": {
			"balance": "200000000000000000000"
		},
		"d1e1f2b9c16c309874dee7fac32675aff129c398": {
			"balance": "72800000000000000000"
		},
		"a43b6da6cb7aac571dff27f09d39f846f53769b1": {
			"balance": "380000000000000000000"
		},
		"779274bf1803a336e4d3b00ddd93f2d4f5f4a62e": {
			"balance": "1000000000000000000000"
		},
		"a644ed922cc237a3e5c4979a995477f36e50bc62": {
			"balance": "583900000000000000000"
		},
		"ee6c03429969ca1262cb3f0a4a54afa7d348d7f5": {
			"balance": "256100000000000000000"
		},
		"4f06246b8d4bd29661f43e93762201d286935ab1": {
			"balance": "4818730000000000000000"
		},
		"e04972a83ca4112bc871c72d4ae1616c2f0728db": {
			"balance": "267606000000000000000"
		},
		"df098f5e4e3dffa51af237bda8652c4f73ed9ca6": {
			"balance": "502000000000000000000"
		},
		"dfded2574b27d1613a7d98b715159b0d00baab28": {
			"balance": "20000000000000000000000"
		},
		"17d931d4c56294dcbe77c8655be4695f006d4a3c": {
			"balance": "2000000000000000000000"
		},
		"3ccb71aa6880cb0b84012d90e60740ec06acd78f": {
			"balance": "2000000000000000000000"
		},
		"e57d2995b0ebdf3f3ca6c015eb04260dbb98b7c6": {
			"balance": "2000000000000000000000"
		},
		"fb3860f4121c432ebdc8ec6a0331b1b709792e90": {
			"balance": "600400000000000000000"
		},
		"fa00c376e89c05e887817a9dd0748d96f341aa89": {
			"balance": "300700000000000000000"
		},
		"c7a018f0968a51d1f6603c5c49dc545bcb0ff293": {
			"balance": "4000000000000000000000"
		},
		"7d73863038ccca22f96affda10496e51e1e6cd48": {
			"balance": "20000000000000000000"
		},
		"38ea6f5b5a7b88417551b4123dc127dfe9342da6": {
			"balance": "400000000000000000000"
		},
		"014b7f67b14f5d983d87014f570c8b993b9872b5": {
			"balance": "200000000000000000000"
		},
		"8ac89bd9b8301e6b0677fa25fcf0f58f0cc7b611": {
			"balance": "20000000000000000000"
		},
		"7eb4b0185c92b6439a08e7322168cb353c8a774a": {
			"balance": "10165988000000000000000"
		},
		"d29dc08efbb3d72e263f78ab7610d0226de76b00": {
			"balance": "12000000000000000000000"
		},
		"72a8260826294726a75bf39cd9aa9e07a3ea14cd": {
			"balance": "2000000000000000000000"
		},
		"4cb5c6cd713ca447b848ae2f56b761ca14d7ad57": {
			"balance": "267400000000000000000"
		},
		"49185dd7c23632f46c759473ebae966008cd3598": {
			"balance": "254030000000000000000"
		},
)E" + R"E(
		"13d67a7e25f2b12cdb85585009f8acc49b967301": {
			"balance": "1999944000000000000000"
		},
		"9d913b5d339c95d87745562563fea98b23c60cc4": {
			"balance": "170718000000000000000"
		},
		"abdc9f1bcf4d19ee96591030e772c334302f7d83": {
			"balance": "40110000000000000000000"
		},
		"e9a5ae3c9e05977dd1069e9fd9d3aefbae04b8df": {
			"balance": "1970000000000000000000"
		},
		"1fd296be03ad737c92f9c6869e8d80a71c5714aa": {
			"balance": "13370000000000000000"
		},
		"2f13657526b177cad547c3908c840eff647b45d9": {
			"balance": "1170685000000000000000"
		},
		"e69fcc26ed225f7b2e379834c524d70c1735e5bc": {
			"balance": "2000000000000000000000"
		},
		"bade43599e02f84f4c3014571c976b13a36c65ab": {
			"balance": "4000000000000000000000"
		},
		"184a4f0beb71ffd558a6b6e8f228b78796c4cf3e": {
			"balance": "12000000000000000000000"
		},
		"d1de5aad3a5fd803f1b1aeb6103cb8e14fe723b7": {
			"balance": "20000000000000000000"
		},
		"0bd67dbde07a856ebd893b5edc4f3a5be4202616": {
			"balance": "2000000000000000000000"
		},
		"6b30f1823910b86d3acb5a6afc9defb6f3a30bf8": {
			"balance": "4200000000000000000000"
		},
		"9a63d185a79129fdab19b58bb631ea36a420544e": {
			"balance": "42000000000000000000"
		},
		"df660a91dab9f730f6190d50c8390561500756ca": {
			"balance": "2000000000000000000000"
		},
		"a1a1f0fa6d20b50a794f02ef52085c9d036aa6ca": {
			"balance": "1000000000000000000000"
		},
		"4ec768295eeabafc42958415e22be216cde77618": {
			"balance": "59600000000000000000"
		},
		"c348fc5a461323b57be303cb89361b991913df28": {
			"balance": "100000000000000000000000"
		},
		"3a7db224acae17de7798797d82cdf8253017dfa8": {
			"balance": "5000000000000000000000"
		},
		"8bea40379347a5c891d59a6363315640f5a7e07a": {
			"balance": "1999992000000000000000"
		},
		"2257fca16a6e5c2a647c3c29f36ce229ab93b17e": {
			"balance": "4000000000000000000000"
		},
		"e492818aa684e5a676561b725d42f3cc56ae5198": {
			"balance": "800000000000000000000"
		},
		"c841884fa4785fb773b28e9715fae99a5134305d": {
			"balance": "2000000000000000000000"
		},
		"0d9443a79468a5bbf7c13c6e225d1de91aee07df": {
			"balance": "70000000000000000000"
		},
		"6d4008b4a888a826f248ee6a0b0dfde9f93210b9": {
			"balance": "5460000000000000000000"
		},
		"884980eb4565c1048317a8f47fdbb461965be481": {
			"balance": "3999922000000000000000"
		},
		"985d70d207892bed398590024e2421b1cc119359": {
			"balance": "20000000000000000000000"
		},
		"d9ec8fe69b7716c0865af888a11b2b12f720ed33": {
			"balance": "4000000000000000000000"
		},
		"49b74e169265f01a89ec4c9072c5a4cd72e4e835": {
			"balance": "16100000000000000000000"
		},
		"4c3e95cc3957d252ce0bf0c87d5b4f2234672e70": {
			"balance": "2500000000000000000000"
		},
		"d9ff115d01266c9f73b063c1c238ef3565e63b36": {
			"balance": "680000000000000000000"
		},
		"48c5c6970b9161bb1c7b7adfed9cdede8a1ba864": {
			"balance": "4000000000000000000000"
		},
		"ea6afe2cc928ac8391eb1e165fc40040e37421e7": {
			"balance": "2997569000000000000000"
		},
		"08ccda50e4b26a0ffc0ef92e9205310706bec2c7": {
			"balance": "6077440000000000000000"
		},
		"e6e9a39d750fe994394eb68286e5ea62a6997882": {
)E" + R"E(
			"balance": "600000000000000000000"
		},
		"4b58101f44f7e389e12d471d1635b71614fdd605": {
			"balance": "160000000000000000000"
		},
		"8d93dac785f88f1a84bf927d53652b45a154ccdd": {
			"balance": "158000000000000000000"
		},
		"415d096ab06293183f3c033d25f6cf7178ac3bc7": {
			"balance": "40000000000000000000"
		},
		"c3e387b03ce95ccfd7fa51dd840183bc43532809": {
			"balance": "2000000000000000000000"
		},
		"da34b2eae30bafe8daeccde819a794cd89e09549": {
			"balance": "2000000000000000000000"
		},
		"fa279bfd8767f956bf7fa0bd5660168da75686bd": {
			"balance": "2674000000000000000000"
		},
		"b98ca31785ef06be49a1e47e864f60d076ca472e": {
			"balance": "4000000000000000000000"
		},
		"b768b5234eba3a9968b34d6ddb481c8419b3655d": {
			"balance": "14974000000000000000"
		},
		"31047d703f63b93424fbbd6e2f1f9e74de13e709": {
			"balance": "2850123000000000000000"
		},
		"9a24ce8d485cc4c86e49deb39022f92c7430e67e": {
			"balance": "1300000000000000000000"
		},
		"e62f9d7c64e8e2635aeb883dd73ba684ee7c1079": {
			"balance": "8000000000000000000000"
		},
		"f15d9d5a21b1929e790371a17f16d95f0c69655c": {
			"balance": "2000000000000000000000"
		},
		"285ae51b9500c58d541365d97569f14bb2a3709b": {
			"balance": "2000000000000000000000"
		},
		"09c177f1ae442411ddacf187d46db956148360e7": {
			"balance": "8950000000000000000000"
		},
		"12173074980153aeaa4b0dcbc7132eadcec21b64": {
			"balance": "240000000000000000000"
		},
		"351f16e5e0735af56751b0e225b2421171394090": {
			"balance": "13370000000000000000000"
		},
		"ac52b77e15664814f39e4f271be641308d91d6cc": {
			"balance": "220000000000000000000"
		},
		"99c883258546cc7e4e971f522e389918da5ea63a": {
			"balance": "4000000000000000000000"
		},
		"aa16269aac9c0d803068d82fc79151dadd334b66": {
			"balance": "4000000000000000000000"
		},
		"7c9a110cb11f2598b2b20e2ca400325e41e9db33": {
			"balance": "26000000000000000000000"
		},
		"583e83ba55e67e13e0e76f8392d873cd21fbf798": {
			"balance": "20000000000000000000"
		},
		"555ebe84daa42ba256ea789105cec4b693f12f18": {
			"balance": "100000000000000000000"
		},
		"978c430ce4359b06bc2cdf5c2985fc950e50d5c8": {
			"balance": "480000000000000000000"
		},
		"dc1eb9b6e64351f56424509645f83e79eee76cf4": {
			"balance": "4000000000000000000000"
		},
		"5b290c01967c812e4dc4c90b174c1b4015bae71e": {
			"balance": "149946000000000000000"
		},
		"e7d213947fcb904ad738480b1eed2f5c329f27e8": {
			"balance": "18718000000000000000"
		},
		"c517d0315c878813c717e18cafa1eab2654e01da": {
			"balance": "10000000000000000000000"
		},
		"7e972a8a7c2a44c93b21436c38d21b9252c345fe": {
			"balance": "1790000000000000000000"
		},
		"9cb28ac1a20a106f7f373692c5ce4c73f13732a1": {
			"balance": "1000000000000000000000"
		},
		"14ab164b3b524c82d6abfbc0de831126ae8d1375": {
			"balance": "2000000000000000000000"
		},
		"d46f8223452982a1eea019a8816efc2d6fc00768": {
			"balance": "137000000000000000000"
		},
		"5cdc4708f14f40dcc15a795f7dc8cb0b7faa9e6e": {
			"balance": "537000000000000000000"
		},
		"66fdc9fee351fa1538eb0d87d819fcf09e7c106a": {
			"balance": "6016500000000000000000"
)E" + R"E(
		},
		"e7be82c6593c1eeddd2ae0b15001ff201ab57b2f": {
			"balance": "19100000000000000000"
		},
		"47d20e6ae4cad3f829eac07e5ac97b66fdd56cf5": {
			"balance": "1000000000000000000000"
		},
		"0f2d8daf04b5414a0261f549ff6477b80f2f1d07": {
			"balance": "200000000000000000000000"
		},
		"84bfcef0491a0ae0694b37ceac024584f2aa0467": {
			"balance": "1999944000000000000000"
		},
		"ec5feafe210c12bfc9a5d05925a123f1e73fbef8": {
			"balance": "456000000000000000000000"
		},
		"7023c70956e04a92d70025aad297b539af355869": {
			"balance": "2000000000000000000000"
		},
		"d66ddf1159cf22fd8c7a4bc8d5807756d433c43e": {
			"balance": "2200000000000000000000"
		},
		"d0638ea57189a6a699024ad78c71d939c1c2ff8c": {
			"balance": "2632000000000000000000"
		},
		"70d25ed2c8ada59c088cf70dd22bf2db93acc18a": {
			"balance": "1056600000000000000000"
		},
		"a4875928458ec2005dbb578c5cd33580f0cf1452": {
			"balance": "1000000000000000000000"
		},
		"b5ad5157dda921e6bafacd9086ae73ae1f611d3f": {
			"balance": "2000000000000000000000"
		},
		"c493489e56c3bdd829007dc2f956412906f76bfa": {
			"balance": "48968000000000000000"
		},
		"c57612de91110c482e6f505bcd23f3c5047d1d61": {
			"balance": "3580000000000000000000"
		},
		"9b18478655a4851cc906e660feac61f7f4c8bffc": {
			"balance": "4174120000000000000000"
		},
		"b21b7979bf7c5ca01fa82dd640b41c39e6c6bc75": {
			"balance": "1999944000000000000000"
		},
		"a9d4a2bcbe5b9e0869d70f0fe2e1d6aacd45edc5": {
			"balance": "198800000000000000000"
		},
		"6f29bb375be5ed34ed999bb830ee2957dde76d16": {
			"balance": "2000000000000000000000"
		},
		"a006268446643ec5e81e7acb3f17f1c351ee2ed9": {
			"balance": "4000000000000000000000"
		},
		"42ddd014dc52bfbcc555325a40b516f4866a1dd3": {
			"balance": "2000000000000000000000"
		},
		"d6d6776958ee23143a81adadeb08382009e996c2": {
			"balance": "3000000000000000000000"
		},
		"d34e03d36a2bd4d19a5fa16218d1d61e3ffa0b15": {
			"balance": "320000000000000000000"
		},
		"dac0c177f11c5c3e3e78f2efd663d13221488574": {
			"balance": "1000000000000000000000"
		},
		"814135da8f9811075783bf1ab67062af8d3e9f40": {
			"balance": "20000000000000000000"
		},
		"7c3eb713c4c9e0381cd8154c7c9a7db8645cde17": {
			"balance": "200000000000000000000"
		},
		"f49c47b3efd86b6e6a5bc9418d1f9fec814b69ef": {
			"balance": "20000000000000000000000"
		},
		"35f1da127b83376f1b88c82a3359f67a5e67dd50": {
			"balance": "1910000000000000000000"
		},
		"44dfba50b829becc5f4f14d1b04aab3320a295e5": {
			"balance": "1000000000000000000000"
		},
		"0b924df007e9c0878417cfe63b976ea1a382a897": {
			"balance": "40000000000000000000"
		},
		"82438fd2b32a9bdd674b49d8cc5fa2eff9781847": {
			"balance": "20000000000000000000"
		},
		"794529d09d017271359730027075b87ad83dae6e": {
			"balance": "310000000000000000000"
		},
		"f4b49100757772f33c177b9a76ba95226c8f3dd8": {
			"balance": "6700000000000000000000"
		},
		"8563c49361b625e768771c96151dbfbd1c906976": {
			"balance": "2000000000000000000000"
		},
		"0b9df80fbe232009dacf0aa8cac59376e2476203": {
			"balance": "2000000000000000000000"
		},
)E" + R"E(
		"149b6dbde632c19f5af47cb493114bebd9b03c1f": {
			"balance": "12000000000000000000000"
		},
		"d7a1431ee453d1e49a0550d1256879b4f5d10201": {
			"balance": "1670000000000000000000"
		},
		"1d37616b793f94911838ac8e19ee9449df921ec4": {
			"balance": "1500000000000000000000"
		},
		"d6670c036df754be43dadd8f50feea289d061fd6": {
			"balance": "5988459000000000000000"
		},
		"02778e390fa17510a3428af2870c4273547d386c": {
			"balance": "16163700000000000000000"
		},
		"b89f4632df5909e58b2a9964f74feb9a3b01e0c5": {
			"balance": "21406707000000000000000"
		},
		"76c27535bcb59ce1fa2d8c919cabeb4a6bba01d1": {
			"balance": "2000000000000000000000"
		},
		"36bf43ff35df90908824336c9b31ce33067e2f50": {
			"balance": "346837200000000000000000"
		},
		"b53bcb174c2518348b818aece020364596466ba3": {
			"balance": "2000000000000000000000"
		},
		"b4dd460cd016725a64b22ea4f8e06e06674e033e": {
			"balance": "5370000000000000000000"
		},
		"cda1741109c0265b3fb2bf8d5ec9c2b8a3346b63": {
			"balance": "20000000000000000000"
		},
		"feb8b8e2af716ae41fc7c04bcf29540156461e6b": {
			"balance": "1555396000000000000000"
		},
		"a49f523aa51364cbc7d995163d34eb590ded2f08": {
			"balance": "2659160000000000000000"
		},
		"a7e74f0bdb278ff0a805a648618ec52b166ff1be": {
			"balance": "100000000000000000000"
		},
		"5ead29037a12896478b1296ab714e9cb95428c81": {
			"balance": "71500000000000000000"
		},
		"cdecf5675433cdb0c2e55a68db5d8bbe78419dd2": {
			"balance": "20000000000000000000"
		},
		"c24ccebc2344cce56417fb684cf81613f0f4b9bd": {
			"balance": "1550000000000000000000"
		},
		"5a70106f20d63f875265e48e0d35f00e17d02bc9": {
			"balance": "20000000000000000000"
		},
		"2606c3b3b4ca1b091498602cb1978bf3b95221c0": {
			"balance": "400000000000000000000"
		},
		"1ad4563ea5786be1159935abb0f1d5879c3e7372": {
			"balance": "6000000000000000000000"
		},
		"b782bfd1e2de70f467646f9bc09ea5b1fcf450af": {
			"balance": "267400000000000000000"
		},
		"649a2b9879cd8fb736e6703b0c7747849796f10f": {
			"balance": "7358102000000000000000"
		},
		"1cc1d3c14f0fb8640e36724dc43229d2ea7a1e48": {
			"balance": "1700000000000000000000"
		},
		"824b3c3c443e19295d7ef6faa7f374a4798486a8": {
			"balance": "20000000000000000000"
		},
		"a7758cecb60e8f614cce96137ef72b4fbd07774a": {
			"balance": "500000000000000000000"
		},
		"981f712775c0dad97518ffedcb47b9ad1d6c2762": {
			"balance": "6685000000000000000000"
		},
		"26e801b62c827191dd68d31a011990947fd0ebe0": {
			"balance": "20000000000000000000"
		},
		"95447046313b2f3a5e19b948fd3b8bedc82c717c": {
			"balance": "500000000000000000000"
		},
		"0b701101a4109f9cb360dc57b77442673d5e5983": {
			"balance": "2000000000000000000000"
		},
		"5b25cae86dcafa2a60e7723631fc5fa49c1ad87d": {
			"balance": "2491200000000000000000"
		},
		"f73ac46c203be1538111b151ec8220c786d84144": {
			"balance": "294515000000000000000"
		},
		"e8c3d3b0e17f97d1e756e684f94e1470f99c95a1": {
			"balance": "400000000000000000000"
		},
		"8c900a8236b08c2b65405d39d75f20062a7561fd": {
			"balance": "1640000000000000000000"
		},
		"43898c49a34d509bfed4f76041ee91caf3aa6aa5": {
)E" + R"E(
			"balance": "300000000000000000000"
		},
		"c85325eab2a59b3ed863c86a5f2906a04229ffa9": {
			"balance": "465600000000000000000"
		},
		"4a430170152de5172633dd8262d107a0afd96a0f": {
			"balance": "3160000000000000000000"
		},
		"6e0ee70612c976287d499ddfa6c0dcc12c06deea": {
			"balance": "129980000000000000000"
		},
		"21c07380484f6cbc8724ad32bc864c3b5ad500b7": {
			"balance": "1000000000000000000000"
		},
		"ff5162f2354dc492c75fd6e3a107268660eecb47": {
			"balance": "1700000000000000000000"
		},
		"8845e9f90e96336bac3c616be9d88402683e004c": {
			"balance": "2000000000000000000000"
		},
		"f23c7b0cb8cd59b82bd890644a57daf40c85e278": {
			"balance": "50038000000000000000"
		},
		"1784948bf99848c89e445638504dd698271b5924": {
			"balance": "6037580000000000000000"
		},
		"b39f4c00b2630cab7db7295ef43d47d501e17fd7": {
			"balance": "4000000000000000000000"
		},
		"3fb7d197b3ba4fe045efc23d50a14585f558d9b2": {
			"balance": "20000000000000000000"
		},
		"bd043b67c63e60f841ccca15b129cdfe6590c8e3": {
			"balance": "200000000000000000000"
		},
		"86ca0145957e6b0dfe36875fbe7a0dec55e17a28": {
			"balance": "10000000000000000000000"
		},
		"dae7201eab8c063302930d693929d07f95e71962": {
			"balance": "2687370000000000000000"
		},
		"cc034985d3f28c2d39b1a34bced4d3b2b6ca234e": {
			"balance": "182000000000000000000"
		},
		"40e0dbf3efef9084ea1cd7e503f40b3b4a8443f6": {
			"balance": "4000000000000000000000"
		},
		"b1896a37e5d8825a2d01765ae5de629977de8352": {
			"balance": "200000000000000000000"
		},
		"d9f547f2c1de0ed98a53d161df57635dd21a00bd": {
			"balance": "98500000000000000000"
		},
		"2fea1b2f834f02fc54333f8a809f0438e5870aa9": {
			"balance": "20200000000000000000"
		},
		"68b31836a30a016ada157b638ac15da73f18cfde": {
			"balance": "26000000000000000000"
		},
		"bc967fe4418c18b99858966d870678dca2b88879": {
			"balance": "8740000000000000000000"
		},
		"16bae5d24eff91778cd98b4d3a1cc3162f44aa77": {
			"balance": "401100000000000000000"
		},
		"f476e1267f86247cc908816f2e7ad5388c952db0": {
			"balance": "4000000000000000000000"
		},
		"0203ae01d4c41cae1865e04b1f5b53cdfaecae31": {
			"balance": "1006054000000000000000"
		},
		"bd4bd5b122d8ef7b7c8f0667450320db2116142e": {
			"balance": "600000000000000000000"
		},
		"a394ad4fd9e6530e6f5c53faecbede81cb172da1": {
			"balance": "5600000000000000000000"
		},
		"3a9960266df6492063538a99f487c950a3a5ec9e": {
			"balance": "24000000000000000000000"
		},
		"d8069f84b521493f4715037f3226b25f33b60586": {
			"balance": "1910000000000000000000"
		},
		"136c834bf111326d207395295b2e583ea7f33572": {
			"balance": "100000000000000000000"
		},
		"c5c73d61cce7c8fe4c8fce29f39092cd193e0fff": {
			"balance": "8000000000000000000000"
		},
		"3cfbf066565970639e130df2a7d16b0e14d6091c": {
			"balance": "1700000000000000000000"
		},
		"61b905de663fc17386523b3a28e2f7d037a655cd": {
			"balance": "500000000000000000000"
		},
		"fda0ce15330707f10bce3201172d2018b9ddea74": {
			"balance": "51900000000000000000"
		},
		"f7fc45abf76f5088e2e5b5a8d132f28a4d4ec1c0": {
			"balance": "2000000000000000000000"
)E" + R"E(
		},
		"c3db9fb6f46c480af34465d79753b4e2b74a67ce": {
			"balance": "20000000000000000000000"
		},
		"ebe46cc3c34c32f5add6c3195bb486c4713eb918": {
			"balance": "1000000000000000000000"
		},
		"91d2a9ee1a6db20f5317cca7fbe2313895db8ef8": {
			"balance": "8499600000000000000000"
		},
		"c4cc45a2b63c27c0b4429e58cd42da59be739bd6": {
			"balance": "1000000000000000000000"
		},
		"a43b81f99356c0af141a03010d77bd042c71c1ee": {
			"balance": "2000000000000000000000"
		},
		"4c45d4c9a725d11112bfcbca00bf31186ccaadb7": {
			"balance": "400000000000000000000"
		},
		"bf9f271f7a7e12e36dd2fe9facebf385fe6142bd": {
			"balance": "62760000000000000000"
		},
		"e0ce80a461b648a501fd0b824690c8868b0e4de8": {
			"balance": "500000000000000000000"
		},
		"a1f7dde1d738d8cd679ea1ee965bee224be7d04d": {
			"balance": "1127000000000000000000"
		},
		"7f1c81ee1697fc144b7c0be5493b5615ae7fddca": {
			"balance": "500200000000000000000"
		},
		"b508f987b2de34ae4cf193de85bff61389621f88": {
			"balance": "6000000000000000000000"
		},
		"5f26cf34599bc36ea67b9e7a9f9b4330c9d542a3": {
			"balance": "1000000000000000000000"
		},
		"d02108d2ae3cab10cbcf1657af223e027c8210f6": {
			"balance": "2000140000000000000000"
		},
		"952183cfd38e352e579d36decec5b18450f7fba0": {
			"balance": "2000000000000000000000"
		},
		"eb90c793b3539761e1c814a29671148692193eb4": {
			"balance": "12000000000000000000000"
		},
		"1076212d4f758c8ec7121c1c7d74254926459284": {
			"balance": "35000056000000000000000"
		},
		"f05ceeab65410564709951773c8445ad9f4ec797": {
			"balance": "299982000000000000000"
		},
		"05361d8eb6941d4e90fb7e1418a95a32d5257732": {
			"balance": "20000000000000000000"
		},
		"a5783bf33432ff82ac498985d7d460ae67ec3673": {
			"balance": "1820000000000000000000"
		},
		"b1cd4bdfd104489a026ec99d597307a04279f173": {
			"balance": "20000000000000000000000"
		},
		"876c3f218b4776df3ca9dbfb270de152d94ed252": {
			"balance": "100000000000000000000"
		},
		"8a36869ad478997cbf6d8924d20a3c8018e9855b": {
			"balance": "20000000000000000000"
		},
		"fb3fe09bb836861529d7518da27635f538505615": {
			"balance": "1399904000000000000000"
		},
		"d093e829819fd2e25b973800bb3d5841dd152d05": {
			"balance": "4000000000000000000000"
		},
		"126d91f7ad86debb0557c612ca276eb7f96d00a1": {
			"balance": "100000000000000000000"
		},
		"2a81d27cb6d4770ff4f3c4a3ba18e5e57f07517c": {
			"balance": "2000000000000000000000"
		},
		"c4f7b13ac6d4eb4db3d4e6a252af8a07bd5957da": {
			"balance": "200000000000000000000"
		},
		"305d26c10bdc103f6b9c21272eb7cb2d9108c47e": {
			"balance": "500000000000000000000"
		},
		"d0d0a2ad45f59a9dccc695d85f25ca46ed31a5a3": {
			"balance": "840000000000000000000"
		},
		"522323aad71dbc96d85af90f084b99c3f09decb7": {
			"balance": "6000000000000000000000"
		},
		"f43da3a4e3f5fab104ca9bc1a0f7f3bb4a56f351": {
			"balance": "1999944000000000000000"
		},
		"a2dc65ee256b59a5bd7929774f904b358df3ada1": {
			"balance": "21319600000000000000000"
		},
		"f382df583155d8548f3f93440cd5f68cb79d6026": {
			"balance": "266619800000000000000000"
		},
)E" + R"E(
		"0c967e3061b87a753e84507eb60986782c8f3013": {
			"balance": "100000000000000000000"
		},
		"a3a262afd2936819230892fde84f2d5a594ab283": {
			"balance": "1880000000000000000000"
		},
		"93868ddb2a794d02ebda2fa4807c76e3609858dc": {
			"balance": "2027851000000000000000"
		},
		"cd35ff010ec501a721a1b2f07a9ca5877dfcf95a": {
			"balance": "4011000000000000000000"
		},
		"5824a7e22838277134308c5f4b50dab65e43bb31": {
			"balance": "6000000000000000000000"
		},
		"7f7a3a21b3f5a65d81e0fcb7d52dd00a1aa36dba": {
			"balance": "100000000000000000000"
		},
		"30513fca9f36fd788cfea7a340e86df98294a244": {
			"balance": "447000000000000000000"
		},
		"283e6252b4efcf4654391acb75f903c59b78c5fb": {
			"balance": "12000000000000000000000"
		},
		"eddbaafbc21be8f25562f1ed6d05d6afb58f02c2": {
			"balance": "2000000000000000000000"
		},
		"0dcfe837ea1cf28c65fccec3bef1f84e59d150c0": {
			"balance": "200000000000000000000"
		},
		"828ba651cb930ed9787156299a3de44cd08b7212": {
			"balance": "1337000000000000000000"
		},
		"cfd47493c9f89fe680bda5754dd7c9cfe7cb5bbe": {
			"balance": "54508000000000000000"
		},
		"0e89eddd3fa0d71d8ab0ff8da5580686e3d4f74f": {
			"balance": "2000000000000000000000"
		},
		"205f5166f12440d85762c967d3ae86184f8f4d98": {
			"balance": "432500000000000000000"
		},
		"25dad495a11a86b9eeece1eeec805e57f157faff": {
			"balance": "16000000000000000000000"
		},
		"6c84cba77c6db4f7f90ef13d5ee21e8cfc7f8314": {
			"balance": "2000000000000000000000"
		},
		"91a787bc5196f34857fe0c372f4df376aaa76613": {
			"balance": "2000000000000000000000"
		},
		"b0d3c9872b85056ea0c0e6d1ecf7a77e3ce6ab85": {
			"balance": "4999711000000000000000"
		},
		"6e4d2e39c8836629e5b487b1918a669aebdd9536": {
			"balance": "1000000000000000000000"
		},
		"dc703a5f3794c84d6cb3544918cae14a35c3bd4f": {
			"balance": "1850000000000000000000"
		},
		"47beb20f759100542aa93d41118b3211d664920e": {
			"balance": "2000000000000000000000"
		},
		"5a7735007d70b06844da9901cdfadb11a2582c2f": {
			"balance": "6000000000000000000000"
		},
		"aff107960b7ec34ed690b665024d60838c190f70": {
			"balance": "500000000000000000000"
		},
		"563a03ab9c56b600f6d25b660c21e16335517a75": {
			"balance": "1000000000000000000000"
		},
		"a106465bbd19e1b6bce50d1b1157dc59095a3630": {
			"balance": "2000000000000000000000"
		},
		"ca9dec02841adf5cc920576a5187edd2bd434a18": {
			"balance": "500000000000000000000"
		},
		"572ac1aba0de23ae41a7cae1dc0842d8abfc103b": {
			"balance": "1910000000000000000000"
		},
		"5f74ed0e24ff80d9b2c4a44baa9975428cd6b935": {
			"balance": "2980000000000000000000"
		},
		"f2049532fd458a83ca1bff2eebacb6d5ca63f4a4": {
			"balance": "3625693000000000000000"
		},
		"cee699c0707a7836252b292f047ce8ad289b2f55": {
			"balance": "324700000000000000000"
		},
		"8b3696f3c60de32432a2e4c395ef0303b7e81e75": {
			"balance": "30000000000000000000000"
		},
		"13dee03e3799952d0738843d4be8fc0a803fb20e": {
			"balance": "2000000000000000000000"
		},
		"c853215b9b9f2d2cd0741e585e987b5fb80c212e": {
			"balance": "1550000000000000000000"
		},
		"851c0d62be4635d4777e8035e37e4ba8517c6132": {
)E" + R"E(
			"balance": "500000000000000000000"
		},
		"a76b743f981b693072a131b22ba510965c2fefd7": {
			"balance": "18200000000000000000"
		},
		"69bd25ade1a3346c59c4e930db2a9d715ef0a27a": {
			"balance": "4000000000000000000000"
		},
		"0fec4ee0d7ca180290b6bd20f9992342f60ff68d": {
			"balance": "334383000000000000000"
		},
		"ccfd725760a68823ff1e062f4cc97e1360e8d997": {
			"balance": "399800000000000000000"
		},
		"9f017706b830fb9c30efb0a09f506b9157457534": {
			"balance": "2000000000000000000000"
		},
		"420fb86e7d2b51401fc5e8c72015decb4ef8fc2e": {
			"balance": "1000000000000000000000"
		},
		"cb7d2b8089e9312cc9aeaa2773f35308ec6c2a7b": {
			"balance": "10000000000000000000000"
		},
		"6c822029218ac8e98a260c1e064029348839875b": {
			"balance": "5010000000000000000000"
		},
		"1c68a66138783a63c98cc675a9ec77af4598d35e": {
			"balance": "50100000000000000000"
		},
		"f270792576f05d514493ffd1f5e84bec4b2df810": {
			"balance": "1000000000000000000000"
		},
		"9191f94698210516cf6321a142070e20597674ed": {
			"balance": "17194000000000000000"
		},
		"c0ca3277942e7445874be31ceb902972714f1823": {
			"balance": "250000000000000000000"
		},
		"35e096120deaa5c1ecb1645e2ccb8b4edbd9299a": {
			"balance": "500000000000000000000"
		},
		"e2bbf84641e3541f6c33e6ed683a635a70bde2ec": {
			"balance": "502763000000000000000"
		},
		"d12d77ae01a92d35117bac705aacd982d02e74c1": {
			"balance": "1000000000000000000000"
		},
		"dabb0889fc042926b05ef57b2520910abc4b4149": {
			"balance": "2000000000000000000000"
		},
		"5a1a336962d6e0c63031cc83c6a5c6a6f4478ecb": {
			"balance": "1000000000000000000000"
		},
		"abd154903513b8da4f019f68284b0656a1d0169b": {
			"balance": "1000000000000000000000"
		},
		"ad377cd25eb53e83ae091a0a1d2b4516f484afde": {
			"balance": "1940000000000000000000"
		},
		"08c2f236ac4adcd3fda9fbc6e4532253f9da3bec": {
			"balance": "20000000000000000000"
		},
		"71135d8f05963c905a4a07922909235a896a52ea": {
			"balance": "3000000000000000000000"
		},
		"080546508a3d2682c8b9884f13637b8847b44db3": {
			"balance": "2000000000000000000000"
		},
		"2d61bfc56873923c2b00095dc3eaa0f590d8ae0f": {
			"balance": "20760000000000000000000"
		},
		"cbfa6af6c283b046e2772c6063b0b21553c40106": {
			"balance": "2000000000000000000000"
		},
		"ccabc6048a53464424fcf76eeb9e6e1801fa23d4": {
			"balance": "49250000000000000000"
		},
		"60cc3d445ebdf76a7d7ae571c6971dff68cc8585": {
			"balance": "1000000000000000000000"
		},
		"fff33a3bd36abdbd412707b8e310d6011454a7ae": {
			"balance": "8000000000000000000000"
		},
		"d2dbebe89b0357aea98bbe8e496338debb28e805": {
			"balance": "4000000000000000000000"
		},
		"5f521282e9b278dc8c034c72af53ee29e5443d78": {
			"balance": "6520000000000000000000"
		},
		"c5a48a8500f9b4e22f0eb16c6f4649687674267d": {
			"balance": "812721000000000000000"
		},
		"8cb3aa3fcd212854d7578fcc30fdede6742a312a": {
			"balance": "300000000000000000000"
		},
		"90d2809ae1d1ffd8f63eda01de49dd552df3d1bc": {
			"balance": "3998000000000000000000"
		},
		"96a55f00dff405dc4de5e58c57f6f6f0cac55d2f": {
			"balance": "1962711000000000000000"
)E" + R"E(
		},
		"ae842e81858ecfedf6506c686dc204ac15bf8b24": {
			"balance": "40000000000000000000"
		},
		"0be6a09e4307fe48d412b8d1a1a8284dce486261": {
			"balance": "19180000000000000000000"
		},
		"c9c7ac0bdd9342b5ead4360923f68c72a6ba633a": {
			"balance": "500000000000000000000"
		},
		"ea8f30b6e4c5e65290fb9864259bc5990fa8ee8a": {
			"balance": "20000000000000000000"
		},
		"74d37a51747bf8b771bfbf43943933d100d21483": {
			"balance": "1000000000000000000000"
		},
		"1a04d5389eb006f9ce880c30d15353f8d11c4b31": {
			"balance": "17072800000000000000000"
		},
		"726a14c90e3f84144c765cffacba3e0df11b48be": {
			"balance": "10000000000000000000000"
		},
		"86b7bd563ceab686f96244f9ddc02ad7b0b14bc2": {
			"balance": "10000000000000000000000"
		},
		"2bbe672a1857508f630f2a5edb563d9e9de92815": {
			"balance": "2000000000000000000000"
		},
		"a17070c2e9c5a940a4ec0e4954c4d7d643be8f49": {
			"balance": "1999965000000000000000"
		},
		"f2d1b7357724ec4c03185b879b63f57e26589153": {
			"balance": "6000000000000000000000"
		},
		"d6a7ac4de7b510f0e8de519d973fa4c01ba83400": {
			"balance": "1880000000000000000000"
		},
		"593b45a1864ac5c7e8f0caaeba0d873cd5d113b2": {
			"balance": "6000000000000000000000"
		},
		"0837539b5f6a522a482cdcd3a9bb7043af39bdd2": {
			"balance": "6000000000000000000000"
		},
		"b927abd2d28aaaa24db31778d27419df8e1b04bb": {
			"balance": "27531000000000000000"
		},
		"b2e085fddd1468ba07415b274e734e11237fb2a9": {
			"balance": "100000000000000000000"
		},
		"970938522afb5e8f994873c9fbdc26e3b37e314c": {
			"balance": "1000000000000000000000"
		},
		"f3de5f26ef6aded6f06d3b911346ee70401da4a0": {
			"balance": "354718000000000000000"
		},
		"bffb6929241f788693273e7022e60e3eab1fe84f": {
			"balance": "2000000000000000000000"
		},
		"b56ad2aec6c8c3f19e1515bbb7dd91285256b639": {
			"balance": "1000000000000000000000"
		},
		"47730f5f8ebf89ac72ef80e46c12195038ecdc49": {
			"balance": "3160000000000000000000"
		},
		"f39a9d7aa3581df07ee4279ae6c312ef21033658": {
			"balance": "4000000000000000000000"
		},
		"36227cdfa0fd3b9d7e6a744685f5be9aa366a7f0": {
			"balance": "198479000000000000000"
		},
		"89e3b59a15864737d493c1d23cc53dbf8dcb1362": {
			"balance": "4000000000000000000000"
		},
		"bd08e0cddec097db7901ea819a3d1fd9de8951a2": {
			"balance": "20000000000000000000"
		},
		"533444584082eba654e1ad30e149735c6f7ba922": {
			"balance": "1730000000000000000000"
		},
		"6a8a4317c45faa0554ccdb482548183e295a24b9": {
			"balance": "1000000000000000000000"
		},
		"22ce349159eeb144ef06ff2636588aef79f62832": {
			"balance": "188000000000000000000"
		},
		"3cd1d9731bd548c1dd6fcea61beb75d91754f7d3": {
			"balance": "5130285000000000000000"
		},
		"8b7056f6abf3b118d026e944d5c073433ca451d7": {
			"balance": "999999000000000000000"
		},
		"15f1b352110d68901d8f67aac46a6cfafe031477": {
			"balance": "200000000000000000000"
		},
		"0f789e30397c53bf256fc364e6ef39f853504114": {
			"balance": "3640000000000000000000"
		},
		"750bbb8c06bbbf240843cc75782ee02f08a97453": {
			"balance": "835000000000000000000"
		},
)E" + R"E(
		"fff7ac99c8e4feb60c9750054bdc14ce1857f181": {
			"balance": "1000000000000000000000"
		},
		"5c6f36af90ab1a656c6ec8c7d521512762bba3e1": {
			"balance": "1999800000000000000000"
		},
		"6811b54cd19663b11b94da1de2448285cd9f68d9": {
			"balance": "1100000000000000000000"
		},
		"6f50929777824c291a49c46dc854f379a6bea080": {
			"balance": "360000000000000000000"
		},
		"e83604e4ff6be7f96f6018d3ec3072ec525dff6b": {
			"balance": "182000000000000000000"
		},
		"d731bb6b5f3c37395e09ceaccd14a918a6060789": {
			"balance": "3940000000000000000000"
		},
		"372e453a6b629f27678cc8aeb5e57ce85ec0aef9": {
			"balance": "200000000000000000000"
		},
		"86924fb211aad23cf5ce600e0aae806396444087": {
			"balance": "10000000000000000000000"
		},
		"18c6723a6753299cb914477d04a3bd218df8c775": {
			"balance": "1000000000000000000000"
		},
		"e00484788db50fc6a48e379d123e508b0f6e5ab1": {
			"balance": "1000000000000000000000"
		},
		"150e3dbcbcfc84ccf89b73427763a565c23e60d0": {
			"balance": "40000000000000000000"
		},
		"8ffa062122ac307418821adb9311075a3703bfa3": {
			"balance": "1000000000000000000000"
		},
		"21206ce22ea480e85940d31314e0d64f4e4d3a04": {
			"balance": "1000000000000000000000"
		},
		"ac024f594f9558f04943618eb0e6b2ee501dc272": {
			"balance": "2000000000000000000000"
		},
		"b2b7cdb4ff4b61d5b7ce0b2270bbb5269743ec04": {
			"balance": "2000000000000000000000"
		},
		"abc74706964960dfe0dca3dca79e9216056f1cf4": {
			"balance": "40000000000000000000000"
		},
		"d7eb903162271c1afa35fe69e37322c8a4d29b11": {
			"balance": "10000000000000000000000"
		},
		"d7c6265dea11876c903b718e4cd8ab24fe265bde": {
			"balance": "2000000000000000000000"
		},
		"cba288cd3c1eb4d59ddb06a6421c14c345a47b24": {
			"balance": "4000000000000000000000"
		},
		"8c22426055b76f11f0a2de1a7f819a619685fe60": {
			"balance": "1980000000000000000000"
		},
		"f463a90cb3f13e1f0643423636beab84c123b06d": {
			"balance": "40000000000000000000"
		},
		"2b5ced9987c0765f900e49cf9da2d9f9c1138855": {
			"balance": "400000000000000000000"
		},
		"9bb760d5c289a3e1db18db095345ca413b9a43c2": {
			"balance": "197000000000000000000"
		},
		"d66ab79294074c8b627d842dab41e17dd70c5de5": {
			"balance": "1000000000000000000000"
		},
		"0bdd58b96e7c916dd2fb30356f2aebfaaf1d8630": {
			"balance": "2000000000000000000000"
		},
		"d612597bc31743c78633f633f239b1e9426bd925": {
			"balance": "76000000000000000000000"
		},
		"140518a3194bad1350b8949e650565debe6db315": {
			"balance": "2000000000000000000000"
		},
		"daedd4ad107b271e89486cbf80ebd621dd974578": {
			"balance": "2000000000000000000000"
		},
		"c36c0b63bfd75c2f8efb060883d868cccd6cbdb4": {
			"balance": "3000000000000000000000"
		},
		"e646665872e40b0d7aa2ff82729caaba5bc3e89e": {
			"balance": "400000000000000000000"
		},
		"b5fb7ea2ddc1598b667a9d57dd39e85a38f35d56": {
			"balance": "500000000000000000000"
		},
		"e51421f8ee2210c71ed870fe618276c8954afbe9": {
			"balance": "1337000000000000000000"
		},
		"08a9a44e1f41de3dbba7a363a3ab412c124cd15e": {
			"balance": "200000000000000000000"
		},
		"562bced38ab2ab6c080f3b0541b8456e70824b3f": {
)E" + R"E(
			"balance": "641760000000000000000"
		},
		"1e484d0621f0f5331b35d5408d9aae4eb1acf21e": {
			"balance": "20000000000000000000"
		},
		"3a476bd2c9e664c63ab266aa4c6e4a4825f516c3": {
			"balance": "200000000000000000000"
		},
		"8d6df209484d7b94702b03a53e56b9fb0660f6f0": {
			"balance": "2000000000000000000000"
		},
		"5970fb1b144dd751e4ce2eca7caa20e363dc4da3": {
			"balance": "10000000000000000000000"
		},
		"d1dd79fb158160e5b4e8e23f312e6a907fbc4d4e": {
			"balance": "500000000000000000000"
		},
		"7ee5ca805dce23af89c2d444e7e40766c54c7404": {
			"balance": "240660000000000000000"
		},
		"93e0f37ecdfb0086e3e862a97034447b1e4dec1a": {
			"balance": "30000000000000000000"
		},
		"e10ac19c546fc2547c61c139f5d1f45a6666d5b0": {
			"balance": "4775000000000000000000"
		},
		"1c73d00b6e25d8eb9c1ff4ad827b6b9e9cf6d20c": {
			"balance": "200000000000000000000"
		},
		"d771d9e0ca8a08a113775731434eb3270599c40d": {
			"balance": "20000000000000000000"
		},
		"e69d1c378b771e0feff051db69d966ac6779f4ed": {
			"balance": "553000000000000000000"
		},
		"0ef85b49d08a75198692914eddb4b22cf5fa4450": {
			"balance": "2004800000000000000000"
		},
		"ed70a37cdd1cbda9746d939658ae2a6181288578": {
			"balance": "9600000000000000000000"
		},
		"eee761847e33fd61d99387ee14628694d1bfd525": {
			"balance": "2000000000000000000000"
		},
		"271d3d481cb88e7671ad216949b6365e06303de0": {
			"balance": "4000000000000000000000"
		},
		"5255dc69155a45b970c604d30047e2f530690e7f": {
			"balance": "20000000000000000000"
		},
		"cabab6274ed15089737e287be878b757934864e2": {
			"balance": "20000000000000000000000"
		},
		"9defe56a0ff1a1947dba0923f7dd258d8f12fa45": {
			"balance": "26880000000000000000000"
		},
		"b7a2c103728b7305b5ae6e961c94ee99c9fe8e2b": {
			"balance": "50000000000000000000000"
		},
		"b498bb0f520005b6216a4425b75aa9adc52d622b": {
			"balance": "4000000000000000000000"
		},
		"c1132878235c5ddba5d9f3228b5236e47020dc6f": {
			"balance": "1000000000000000000000"
		},
		"f81622e55757daea6675975dd93538da7d16991e": {
			"balance": "2000000000000000000000"
		},
		"ce2deab51c0a9ae09cd212c4fa4cc52b53cc0dec": {
			"balance": "2000000000000000000000"
		},
		"86a1eadeeb30461345d9ef6bd05216fa247c0d0c": {
			"balance": "2000000000000000000000"
		},
		"7b1fe1ab4dfd0088cdd7f60163ef59ec2aee06f5": {
			"balance": "2000000000000000000000"
		},
		"6bbc3f358a668dd1a11f0380f3f73108426abd4a": {
			"balance": "4000000000000000000000"
		},
		"b1e6e810c24ab0488de9e01e574837829f7c77d0": {
			"balance": "400000000000000000000"
		},
		"03eb3cb860f6028da554d344a2bb5a500ae8b86f": {
			"balance": "2000000000000000000000"
		},
		"e5481a7fed42b901bbed20789bd4ade50d5f83b9": {
			"balance": "2000000000000000000000"
		},
		"1f3da68fe87eaf43a829ab6d7ec5a6e009b204fb": {
			"balance": "554988000000000000000"
		},
		"30037988702671acbe892c03fe5788aa98af287a": {
			"balance": "2800000000000000000000"
		},
		"edb473353979a206879de144c10a3c51d7d7081a": {
			"balance": "6000000000000000000000"
		},
		"22bdffc240a88ff7431af3bff50e14da37d5183e": {
			"balance": "1000000000000000000000"
)E" + R"E(
		},
		"9374869d4a9911ee1eaf558bc4c2b63ec63acfdd": {
			"balance": "1000000000000000000000"
		},
		"b756ad52f3bf74a7d24c67471e0887436936504c": {
			"balance": "20000000000000000000000"
		},
		"8bd0b65a50ef5cef84fec420be7b89ed1470ceb9": {
			"balance": "11999000000000000000000"
		},
		"af26f7c6bf453e2078f08953e4b28004a2c1e209": {
			"balance": "100000000000000000000"
		},
		"7c532db9e0c06c26fd40acc56ac55c1ee92d3c3a": {
			"balance": "300000000000000000000000"
		},
		"dde670d01639667576a22dd05d3246d61f06e083": {
			"balance": "26740000000000000000"
		},
		"5cf44e10540d65716423b1bcb542d21ff83a94cd": {
			"balance": "10000000000000000000000"
		},
		"f96b4c00766f53736a8574f822e6474c2f21da2d": {
			"balance": "400000000000000000000"
		},
		"8d89170b92b2be2c08d57c48a7b190a2f146720f": {
			"balance": "19700000000000000000000"
		},
		"142b87c5043ffb5a91df18c2e109ced6fe4a71db": {
			"balance": "200000000000000000000"
		},
		"42d34940edd2e7005d46e2188e4cfece8311d74d": {
			"balance": "158000000000000000000"
		},
		"562105e82b099735de49f62692cc87cd38a8edcd": {
			"balance": "6000000000000000000000"
		},
		"457bcef37dd3d60b2dd019e3fe61d46b3f1e7252": {
			"balance": "20000000000000000000"
		},
		"cf8882359c0fb23387f5674074d8b17ade512f98": {
			"balance": "6000000000000000000000"
		},
		"f0c081da52a9ae36642adf5e08205f05c54168a6": {
			"balance": "111000000000000000000"
		},
		"551e7784778ef8e048e495df49f2614f84a4f1dc": {
			"balance": "600000000000000000000"
		},
		"3c869c09696523ced824a070414605bb76231ff2": {
			"balance": "1000000000000000000000"
		},
		"7e7f18a02eccaa5d61ab8fbf030343c434a25ef7": {
			"balance": "66850000000000000000"
		},
		"9328d55ccb3fce531f199382339f0e576ee840a3": {
			"balance": "4000000000000000000000"
		},
		"9d0f347e826b7dceaad279060a35c0061ecf334b": {
			"balance": "4000000000000000000000"
		},
		"680640838bd07a447b168d6d923b90cf6c43cdca": {
			"balance": "1730000000000000000000"
		},
		"c951900c341abbb3bafbf7ee2029377071dbc36a": {
			"balance": "327600000000000000000"
		},
		"ddf5810a0eb2fb2e32323bb2c99509ab320f24ac": {
			"balance": "17900000000000000000000"
		},
		"2489ac126934d4d6a94df08743da7b7691e9798e": {
			"balance": "1000000000000000000000"
		},
		"f42f905231c770f0a406f2b768877fb49eee0f21": {
			"balance": "197000000000000000000"
		},
		"756f45e3fa69347a9a973a725e3c98bc4db0b5a0": {
			"balance": "200000000000000000000"
		}
	}
}
)E";

std::string const& dev::eth::genesisInfo(Network _n)
{
	switch (_n)
	{
	case Network::Olympic: return c_genesisInfoOlympic;
	case Network::Frontier: return c_genesisInfoFrontier;
	case Network::Morden: return c_genesisInfoMorden;
	case Network::Test: return c_genesisInfoTest;
	case Network::FrontierTest: return c_genesisInfoFrontierTest;
	case Network::HomesteadTest: return c_genesisInfoHomesteadTest;
	case Network::EIP150Test: return c_genesisInfoEIP150Test;
	case Network::EIP158Test: return c_genesisInfoEIP158Test;
	default:
		throw std::invalid_argument("Invalid network value");
	}
}

h256 const& dev::eth::genesisStateRoot(Network _n)
{
	switch (_n)
	{
	case Network::Olympic: return c_genesisStateRootOlympic;
	case Network::Frontier: return c_genesisStateRootFrontier;
	case Network::Morden: return c_genesisStateRootMorden;
	case Network::Test: return c_genesisStateRootTest;
	case Network::FrontierTest: return c_genesisStateRootFrontierTest;
	case Network::HomesteadTest: return c_genesisStateRootHomesteadTest;
	case Network::EIP150Test: return c_genesisStateRootEIP150Test;
	case Network::EIP158Test: return c_genesisStateRootEIP158Test;
	default:
		throw std::invalid_argument("Invalid network value");
	}
}
