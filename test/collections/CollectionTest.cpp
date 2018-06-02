#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "collection/Collection.h"
#include "collection/LinkedList.h"

using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FCollection {
	FCollection () {
		this->collections.push_back(make_unique <LinkedList <int>>());
	}

	~FCollection () {
	}

	vector <unique_ptr <Collection <int>>> collections = vector <unique_ptr <Collection <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(CollectionTest, FCollection)
	BOOST_AUTO_TEST_CASE(TestingSizeInitialZero) {
		for (auto & collection : collections) {
			Collection <int> * c = collection->clone();
			BOOST_CHECK_EQUAL(0, c->size());
			c->add(1);
			BOOST_CHECK_EQUAL(1, c->size());
			c->clear();
			BOOST_CHECK_EQUAL(0, c->size());
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingisEmpty) {
		for (auto & collection : collections) {
			Collection <int> * c = collection->clone();
			BOOST_CHECK(c->isEmpty());
			c->add(1);
			BOOST_CHECK(!c->isEmpty());
			c->clear();
			BOOST_CHECK(c->isEmpty());
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingAdd) {
		for (auto & collection : collections) {
			Collection <int> * c = collection->clone();
			for (int i = 0; i < 100; i++) {
				BOOST_CHECK_EQUAL(i, c->size());
				c->add(i);
				BOOST_CHECK_EQUAL(i + 1, c->size());
			}
			c->clear();
			BOOST_CHECK(c->isEmpty());
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingAddAll) {
		auto list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.add(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (auto & collection : collections) {
			Collection <int> * c = collection->clone();
			BOOST_CHECK(c->isEmpty());
			c->merge(list);
			BOOST_CHECK_EQUAL(100, c->size());
			c->clear();
			BOOST_CHECK(c->isEmpty());
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingIterator) {
		for (auto & collection : collections) {
			Collection <int> * c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			auto it = unique_ptr <Iterator <int>>(c->iterator());
			int i = 0;
			while (it->hasNext()) {
				BOOST_CHECK_EQUAL(i++, it->next());
			}
			BOOST_CHECK_EQUAL(i, c->size());
			BOOST_CHECK_EQUAL(100, c->size());
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingForEach) {
		for (auto & collection : collections) {
			Collection <int> * c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			int ac = 0;
			c->stream().forEach([&ac] (int i)
			{
				ac += i;
			});
			BOOST_CHECK_EQUAL((0 + 99) * 50, ac);
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingContains) {
		for (auto & collection : collections) {
			Collection <int> * c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			BOOST_CHECK(c->contains(0));
			BOOST_CHECK(c->contains(99));
			BOOST_CHECK(!c->contains(100));
			delete c;
		}
	}

BOOST_AUTO_TEST_SUITE_END()
