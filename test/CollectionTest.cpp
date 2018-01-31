#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Collection/Collection.h"
#include "List/LinkedList.h"

using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FADT {
	FADT () {
		BOOST_TEST_MESSAGE("setup fixture");
		this->collections.push_back(make_unique <LinkedList <int>>());
		for (auto & collection : this->collections) {
			for (int i = 0; i < 100; i++) {
				collection->add(i);
			}
		}
	}

	~FADT () {
		BOOST_TEST_MESSAGE("teardown fixture");
	}

	vector <unique_ptr <Collection <int>>> collections = vector <unique_ptr <Collection <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(CollectionTest, FADT)
	BOOST_AUTO_TEST_CASE(TestingContains) {
		for (unique_ptr <Collection <int>> & collection : this->collections) {
			BOOST_CHECK(collection->contains(0));
			BOOST_CHECK(collection->contains(99));
			BOOST_CHECK(!collection->contains(100));
		}
	}

BOOST_AUTO_TEST_SUITE_END()
