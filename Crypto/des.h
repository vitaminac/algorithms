#pragma once
#include <cstdint>
#include <string>
#define __IN__
#define __OUT__
#define __IN_OUT__

struct block
{
	uint_fast32_t lBlock;
	uint_fast32_t rBlock;
};

const unsigned short blockLen = 64;

// initial permutation IP before than key-encryption
constexpr const unsigned char initialMessagePermutation[8][8] = {
	{58,50,42,34,26,18,10,2},
	{60,52,44,36,28,20,12,4},
	{62,54,46,38,30,22,14,6},
	{64,56,48,40,32,24,16,8},
	{57,49,41,33,25,17, 9,1},
	{59,51,43,35,27,19,11,3},
	{61,53,45,37,29,21,13,5},
	{63,55,47,39,31,23,15,7}
};

constexpr const unsigned char finalMessagePermutation[8][8] = {
	{40,8,48,16,56,24,64,32},
	{39,7,47,15,55,23,63,31},
	{38,6,46,14,54,22,62,30},
	{37,5,45,13,53,21,61,29},
	{36,4,44,12,52,20,60,28},
	{35,3,43,11,51,19,59,27},
	{34,2,42,10,50,18,58,26},
	{33,1,41, 9,49,17,57,25}
};

uint64_t des (uint64_t fullBlock);
block divide_block (uint64_t fullBlock);
uint_fast64_t combine_block (const block & block);

// initial and final message permutate function
uint64_t permutate_v2 (uint64_t fullblock , bool first);

template <typename T>
uint64_t permutate (__IN__ uint64_t block , T p , __IN__ int arraySize = blockLen)
{
	// cast to single index
	auto permutation = reinterpret_cast <const unsigned char*> (p);
	uint64_t newBlock = 0x0;
	uint64_t startMark = 0x1;
	for (auto i = 0 ; i <= arraySize ; i++)
	{
		auto from_bit_position = permutation[i];
		auto mark = startMark << (64 - from_bit_position);
		auto getBit = mark & block;
		auto shift_position = from_bit_position - i - 1;
		auto thatBit = (shift_position < 0) ? getBit >> -shift_position : getBit << shift_position;
		newBlock |= thatBit;
	}
	return newBlock;
}
