#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include "adt/Stack.h"
#include "collection/LinkedList.h"

using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FStack {
	FStack () {
		BOOST_TEST_MESSAGE("setup fixture");
		this->stacks.push_back(make_unique <LinkedList <int>>());
	}

	~FStack () {
		BOOST_TEST_MESSAGE("teardown fixture");
	}

	vector <unique_ptr <Stack <int>>> stacks = vector <unique_ptr <Stack <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(StackTesting, FStack)

	BOOST_AUTO_TEST_CASE(TestingStackMethod) {
		for (const auto & stack : this->stacks) {
			for (int i = 1; i <= 100; i++) {
				stack->push(i);
			}
			for (int i = 100; i > 0; i--) {
				BOOST_CHECK_EQUAL(i, stack->last());
				BOOST_CHECK_EQUAL(i, stack->pop());
			}
		}
	}

BOOST_AUTO_TEST_SUITE_END()
