#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>
#include "adt/Queue.h"
#include "collection/LinkedList.h"

using std::vector;
using std::make_unique;
using std::unique_ptr;

struct FQueue {
	FQueue () {
		BOOST_TEST_MESSAGE("setup fixture");
		this->queues.push_back(make_unique <LinkedList <int>>());
	}

	~FQueue () {
		BOOST_TEST_MESSAGE("teardown fixture");
	}

	vector <unique_ptr <Queue <int>>> queues = vector <unique_ptr <Queue <int>>>();
};

BOOST_FIXTURE_TEST_SUITE(QueueTest, FQueue)

	BOOST_AUTO_TEST_CASE(QueueADT) {
		for (const auto & queue : this->queues) {
			for (int i = 1; i <= 100; i++) {
				queue->enqueue(i);
			}
			for (int i = 1; i <= 100; i++) {
				BOOST_CHECK_EQUAL(i, queue->first());
				BOOST_CHECK_EQUAL(i, queue->dequeue());
			}
		}
	}

BOOST_AUTO_TEST_SUITE_END()
