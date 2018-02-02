#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Collection/Collection.h"
#include "List/LinkedList.h"

using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FCollection {
	FCollection () {
		this->collections.push_back(make_unique <LinkedList <int>>());
		for (auto & collection : this->collections) {
			for (int i = 0; i < 100; i++) {
				collection->add(i);
			}
		}
	}

	~FCollection () {
	}

	vector <unique_ptr <Collection <int>>> collections = vector <unique_ptr <Collection <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(CollectionTest, FCollection)
	BOOST_AUTO_TEST_CASE(TestingIterator) {
		for (unique_ptr <Collection <int>> & collection : this->collections) {
			auto it = unique_ptr <Iterator <int>>(collection->iterator());
			int i = 0;
			while (it->hasNext()) {
				BOOST_CHECK_EQUAL(i++, it->next());
			}
			BOOST_CHECK_EQUAL(i, collection->size());
			BOOST_CHECK_EQUAL(100, collection->size());
		}
	}

	BOOST_AUTO_TEST_CASE(TestingForEach) {
		for (unique_ptr <Collection <int>> & collection : this->collections) {
			int ac = 0;
			collection->forEach([&ac] (int i)
			{
				ac += i;
			});
			BOOST_CHECK_EQUAL((0 + 99) * 50, ac);
		}
	}

	BOOST_AUTO_TEST_CASE(TestingContains) {
		for (unique_ptr <Collection <int>> & collection : this->collections) {
			BOOST_CHECK(collection->contains(0));
			BOOST_CHECK(collection->contains(99));
			BOOST_CHECK(!collection->contains(100));
		}
	}

BOOST_AUTO_TEST_SUITE_END()
