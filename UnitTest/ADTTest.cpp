#include <boost/test/unit_test.hpp>
#include <memory>
#include "Collection/ADT.h"
#include "List/LinkedList.h"

using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FADT {
	FADT () {
		BOOST_TEST_MESSAGE("setup fixture");
		this->adts.push_back(make_unique <LinkedList <int>>());
	}

	~FADT () {
		BOOST_TEST_MESSAGE("teardown fixture");
	}

	vector <unique_ptr <ADT <int>>> adts = vector <unique_ptr <ADT <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(ADTTest, FADT)
	BOOST_AUTO_TEST_CASE(TestingSizeInitialZero) {
		for (auto & adt : adts) {
			BOOST_CHECK_EQUAL(0, adt->size());
		}
	}

	BOOST_AUTO_TEST_CASE(TestingisEmpty) {
		for (auto & adt : adts) {
			BOOST_CHECK(adt->isEmpty());
		}
	}

BOOST_AUTO_TEST_SUITE_END()
