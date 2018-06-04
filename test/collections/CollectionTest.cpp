#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include "collection/Collection.h"
#include "collection/LinkedList.h"
#include "exception/CollectionIsEmptyException.h"
using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FCollection {
	FCollection () {
		this->collections.push_back(make_unique <LinkedList <int>>());
	}

	~FCollection () = default;

	vector <unique_ptr <Collection <int>>> collections = vector <unique_ptr <Collection <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(CollectionTest, FCollection)
	BOOST_AUTO_TEST_CASE(TestingSizeAndIsEmpty) {
		for (const auto & collection : this->collections) {
			auto c = collection->clone();
			BOOST_CHECK_EQUAL(0, c->size());
			BOOST_CHECK(c->isEmpty());
			for (int i = 1; i <= 100; i++) {
				c->add(i);
				BOOST_CHECK(!c->isEmpty());
				BOOST_CHECK_EQUAL(i, c->size());
			}
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingRemoveWhenEmpty) {
		for (const auto & c : this->collections) {
			BOOST_CHECK(!c->remove(0));
		}
	}

	BOOST_AUTO_TEST_CASE(TestingAddAndRemove) {
		for (const auto & collection : this->collections) {
			auto c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			BOOST_CHECK_EQUAL(100, c->size());
			for (int i = 100 - 1; i >= 0; i--) {
				BOOST_CHECK(c->remove(i));
			}
			BOOST_CHECK(c->isEmpty());
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingClear) {
		for (const auto & collection : this->collections) {
			auto c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			BOOST_CHECK_EQUAL(100, c->size());
			c->clear();
			BOOST_CHECK_EQUAL(0, c->size());
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingMergeAndContains) {
		auto origin = collections.front()->clone();
		for (int i = 0; i < 100; i++) {
			origin->add(i);
		}
		for (const auto & collection : this->collections) {
			auto c = collection->clone();
			c->merge(*origin);
			BOOST_CHECK_EQUAL(100, c->size());
			for (int i = 0; i < 100; i++) {
				c->contains(i);
			}
			delete c;
		}
		delete origin;
	}

	/*
	 * Iterable Interface
	 */
	BOOST_AUTO_TEST_CASE(TestingIterator) {
		for (auto & collection : collections) {
			auto c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			auto it = c->iterator();
			int i = 0;
			for (int i = 0; i < 100; i++) {
				BOOST_CHECK(it->hasNext());
				BOOST_CHECK_EQUAL(i, it->next());
			}
			delete it;
			delete c;
		}
	}
	/*
	* Stream Interface
	*/
	BOOST_AUTO_TEST_CASE(TestingForEach) {
		for (auto & collection : collections) {
			auto c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			int ac = 0;
			c->stream().forEach([&ac] (const int i)
			{
				ac += i;
			});
			BOOST_CHECK_EQUAL((0 + 99) * 50, ac);
			delete c;
		}
	}

BOOST_AUTO_TEST_SUITE_END()
