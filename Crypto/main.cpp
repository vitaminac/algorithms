#include <iostream>
#include <random>
#include <cmath>
#include <exception>
#include "des.h"
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::exception;
const unsigned int testNumber = 10;

class TestFailed:public exception
{
private:
	const char * msg;
public:
	TestFailed (): TestFailed("test Error without specified")
	{
	}

	explicit TestFailed (const char * errMessage) : msg(errMessage)
	{
	};
	const char * what () const override;

	virtual ~TestFailed ()
	{
		//delete msg;
	}
};

inline const char * TestFailed::what () const
{
	return msg;
}

typedef void (*testFunc) (uint64_t);

void randomNumberTest (testFunc test)
{
	std::random_device rd;
	std::mt19937_64 e2(rd());
	std::uniform_int_distribution <long long int> dist(std::llround(std::pow(2, 61)), std::llround(std::pow(2, 62)));

	cout << std::llround(std::pow(2, 61)) << endl;
	cout << std::llround(std::pow(2, 62)) << endl;
	for (auto i = 0; i < testNumber; i++)
	{
		uint64_t testNumber = dist(e2);
		test(testNumber);
		cout << testNumber << "  ";
		auto k = combine_block(divide_block(testNumber));
		cout << k << endl;
		if (!(k == testNumber))
		{
			throw TestFailed("combine and divide block into 32bit failed");
		};
	}
}

void testKeySchedule (uint64_t testKey)
{
}

void testDesCombineDivide (uint64_t testNumber)
{
	cout << testNumber << "  ";
	auto k = combine_block(divide_block(testNumber));
	cout << k << endl;
	if (!(k == testNumber))
	{
		throw TestFailed("combine and divide block into 32bit failed");
	};
}

void testPermutation (uint64_t testNumber)
{
	auto afterInitialPermutated = permutate(-1, initialMessagePermutation);
	auto afterFinalPermutated = permutate(afterInitialPermutated, finalMessagePermutation);
	if (afterFinalPermutated != -1 || afterInitialPermutated != -1)
	{
		throw TestFailed("Permutation test failed with number -1 tested case");
	}
	afterInitialPermutated = permutate(0, initialMessagePermutation);
	afterFinalPermutated = permutate(afterInitialPermutated, finalMessagePermutation);
	if (afterFinalPermutated != 0 || afterInitialPermutated != 0)
	{
		throw TestFailed("Permutation test failed with number 0 tested case");
	}
	auto afterInitialPermutatedv2 = permutate_v2(testNumber, true);
	auto afterFinalPermutatedv2 = permutate_v2(afterInitialPermutatedv2, false);
	afterInitialPermutated = permutate(testNumber, initialMessagePermutation);
	afterFinalPermutated = permutate(afterInitialPermutated, finalMessagePermutation);
	cout << testNumber << " " << afterInitialPermutated << " " << afterInitialPermutatedv2 << " " << afterFinalPermutated << " " << afterFinalPermutatedv2;
	if (testNumber != afterFinalPermutated || testNumber != afterFinalPermutatedv2 || afterInitialPermutated != afterInitialPermutatedv2)
	{
		throw TestFailed("Permutation test failed ");
	}
}

void unexpectedThrow (void)
{
	cout << "Terminated with unknown error, probably an exception occurs during the unwinding process" << endl;
	getchar();
	exit(1);
}

int main ()
{
	set_terminate(unexpectedThrow);
	cout << "test begin" << endl;
	auto testFunctions = {testDesCombineDivide,testPermutation};
	try
	{
		for (auto f : testFunctions)
		{
			randomNumberTest(f);
		}
	}
	catch (exception & e)
	{
		cout << &typeid(e) << ":";
		cout << e.what();
		return 1;
	} catch (...)
	{
		cout << "exiting due to uncaught exception" << endl;
		// throw; // rethrow
		return 1;
	}
	getchar();
	return 0;
}
