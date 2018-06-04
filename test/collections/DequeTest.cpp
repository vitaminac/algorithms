#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include "adt/Deque.h"
#include "collection/LinkedList.h"
#include "exception/CollectionIsEmptyException.h"

using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FDeque {
	FDeque () {
		BOOST_TEST_MESSAGE("setup fixture");
		this->deques.push_back(make_unique <LinkedList <int>>());
	}

	~FDeque () {
		BOOST_TEST_MESSAGE("teardown fixture");
	}

	vector <unique_ptr <Deque <int>>> deques = vector <unique_ptr <Deque <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(DequeTest, FDeque)

	BOOST_AUTO_TEST_CASE(DequeADT) {
		for (const auto & deque : this->deques) {
			for (int i = 0; i <= 100; i++) {
				if (i % 2 == 0) {
					deque->addLast(i);
				} else {
					deque->addFirst(i);
				}
			}
			for (int i = 99; i >= 0; i = i - 2) {
				BOOST_CHECK_EQUAL(i, deque->first());
				BOOST_CHECK_EQUAL(i, deque->removeFirst());
			}
			for (int i = 100; i >= 0; i = i - 2) {
				BOOST_CHECK_EQUAL(i, deque->last());
				BOOST_CHECK_EQUAL(i, deque->removeLast());
			}
		}
	}

	BOOST_AUTO_TEST_CASE(TestingGetWhenEmpty) {
		for (const auto & deque : this->deques) {
			BOOST_CHECK_THROW(deque->first(), CollectionIsEmptyException);
			BOOST_CHECK_THROW(deque->last(), CollectionIsEmptyException);
		}
	}

BOOST_AUTO_TEST_SUITE_END()
