#include "des.h"

block divide_block (uint64_t fullBlock)
{
	return block {
		static_cast <uint32_t> (fullBlock >> 32),
		static_cast <uint32_t> (fullBlock)
	};
}

uint64_t combine_block (const block & block)
{
	return (static_cast <int64_t> (block.lBlock) << 32) | static_cast <int64_t> (block.rBlock);
}

// assuring that each byte is of odd parity 8,16,,64,
class KeySchedule
{
private:
	static constexpr unsigned char pc1C[28] = {
		57,49,41,33,25,17, 9,
		1,58,50,42,34,26,18,
		10, 2,59,51,43,35,27,
		19,11, 3,60,52,44,36,
	};
	static constexpr unsigned char pc1D[28] = {
		63,55,47,39,31,23,15,
		7,62,54,46,38,30,22,
		14, 6,61,53,45,37,29,
		21,13, 5,28,20,12, 4
	};
	uint64_t __key;
	char _key56[7];
	block key;
public:
	/* The bits of KEY are numbered 1 through 64. The bits of C0 are respectively bits 57, 49, 41,..., 44 
	 * and 36 of KEY, with the bits of D0 being bits 63, 55, 47,..., 12 and 4 of KEY */
	explicit KeySchedule (uint64_t key) : __key (key)
	{
		this->key.lBlock = divide_block (permutate (this->__key, pc1C, 28)).lBlock;
		this->key.rBlock = divide_block (permutate (this->__key, pc1D, 28)).rBlock;
	};

	/* With C0 and D0 defined, we now define how the blocks Cn and
	 * Dn are obtained from the blocks Cn­-1 and Dn-1, respectively, for
	 * n=  1,  2,...,  16.  */
	virtual char * nextKey ()
	{
		return "c";
	}

	virtual ~KeySchedule ()
	{
		//delete msg;
	}
};

uint32_t feistel (uint32_t halfBlock , uint64_t key_48bit)
{
	// Expansion

	// Key mixing

	// Substitution

	// Permutation

	return halfBlock;
}


// Let K be a block of 48 bits chosen from the 64 - bit key.Then the output L'R'
// of an iteration with input LRis defined by :
// L' = R; R'= L xor f(R, K)
const block & round (block & _64Block , uint64_t key)
{
	_64Block.rBlock = _64Block.lBlock ^ feistel (_64Block.rBlock, key);
	_64Block.lBlock = _64Block.rBlock;
	return _64Block;
}

uint64_t permutate_v2 (uint64_t fullblock , bool first)
{
	uint32_t temp;
	auto b = divide_block (fullblock);
	auto left = b.lBlock;
	auto right = b.rBlock;
	if (first)
	{
		temp = ((left >> 4) ^ right) & 0x0f0f0f0f;
		right ^= temp;
		left ^= (temp << 4);
		temp = ((left >> 16) ^ right) & 0x0000ffff;
		right ^= temp;
		left ^= (temp << 16);
		temp = ((right >> 2) ^ left) & 0x33333333;
		left ^= temp;
		right ^= (temp << 2);
		temp = ((right >> 8) ^ left) & 0x00ff00ff;
		left ^= temp;
		right ^= (temp << 8);
		temp = ((left >> 1) ^ right) & 0x55555555;
		right ^= temp;
		left ^= (temp << 1);
	} else
	{
		temp = ((left >> 1) ^ right) & 0x55555555;
		right ^= temp;
		left ^= (temp << 1);
		temp = ((right >> 8) ^ left) & 0x00ff00ff;
		left ^= temp;
		right ^= (temp << 8);
		temp = ((right >> 2) ^ left) & 0x33333333;
		left ^= temp;
		right ^= (temp << 2);
		temp = ((left >> 16) ^ right) & 0x0000ffff;
		right ^= temp;
		left ^= (temp << 16);
		temp = ((left >> 4) ^ right) & 0x0f0f0f0f;
		right ^= temp;
		left ^= (temp << 4);
	}
	b.lBlock = left;
	b.rBlock = right;
	return combine_block (b);
}

// Let the 64 bits of the input block to an iteration consist of a 32 bit block L followed 
// by a 32 bit block R .Using the notation defined in the introduction, the input block is then LR.
uint64_t des (uint64_t fullBlock)
{
	auto block = permutate (fullBlock, initialMessagePermutation);
	// key-dependent computation
	auto b = divide_block (block);
	for (auto i = 0 ; i < 16 ; i++)
	{
		// round (b);
	}
	block = combine_block (b);
	// terminate key-dependent computation
	block = permutate (block, finalMessagePermutation);
	return block;
}

std::string des (const std::string input)
{
	return input;
}
