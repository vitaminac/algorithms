#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include "collection/Collection.h"
#include "collection/ArrayList.h"
#include "collection/LinkedList.h"
#include "exception/CollectionIsEmptyException.h"
#include "function/Predicate.h"
using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FCollection {
	FCollection () {
		this->collections.push_back(make_unique <LinkedList <int>>());
		this->collections.push_back(make_unique <ArrayList <int>>());
	}

	~FCollection () = default;

	vector <unique_ptr <Collection <int>>> collections = vector <unique_ptr <Collection <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(CollectionTest, FCollection)
	BOOST_AUTO_TEST_CASE(TestingSizeAndIsEmpty) {
		for (const auto & collection : this->collections) {
			auto c = collection->clone();
			BOOST_CHECK_EQUAL(0, c->stream().count());
			BOOST_CHECK(c->isEmpty());
			for (int i = 1; i <= 100; i++) {
				c->add(i);
				BOOST_CHECK_MESSAGE(!c->isEmpty(), "failed in iteration " << i);
				BOOST_CHECK_MESSAGE(i == c->stream().count(), "failed in iteration " << i);
			}
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingAdd) {
		for (const auto & collection : this->collections) {
			auto c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			BOOST_CHECK_EQUAL(100, c->stream().count());
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(TestingClear) {
		for (const auto & collection : this->collections) {
			auto c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			BOOST_CHECK_EQUAL(100, c->stream().count());
			c->clear();
			BOOST_CHECK_EQUAL(0, c->stream().count());
			delete c;
		}
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

	BOOST_AUTO_TEST_CASE(AnyMatch) {
		for (auto & collection : collections) {
			auto c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			int key;
			Predicate <int> search = [&key] (const int & e)
			{
				return key == e;
			};
			key = 50;
			BOOST_CHECK(c->stream().anyMatch(search));
			key = 100;
			BOOST_CHECK(!c->stream().anyMatch(search));
			key = 0;
			BOOST_CHECK(c->stream().anyMatch(search));
			key = -1;
			BOOST_CHECK(!c->stream().anyMatch(search));
			delete c;
		}
	}

	BOOST_AUTO_TEST_CASE(Collect) {
		for (auto & collection : collections) {
			auto c = collection->clone();
			for (int i = 0; i < 100; i++) {
				c->add(i);
			}
			BOOST_CHECK_EQUAL((0 + 99) * 50, c->stream().template collect <double>(0, [](double ac, const int & e)
			{
				ac += e;
				return ac;
			}));
			delete c;
		}
	}

BOOST_AUTO_TEST_SUITE_END()
