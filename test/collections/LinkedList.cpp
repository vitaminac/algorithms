#include "test/UnitTest.h"
#include "collection/LinkedList.h"
#include "test/adt/ADTTest.h"

BOOST_AUTO_TEST_SUITE(LinkedListTest)

	BOOST_AUTO_TEST_CASE(StackADT) {
		auto * stack = new LinkedList <int>();
		testStackADT(stack);
		delete stack;
	}

	BOOST_AUTO_TEST_CASE(QueueADT) {
		auto * queue = new LinkedList <int>();
		testQueueADT(queue);
		delete queue;
	}

	BOOST_AUTO_TEST_CASE(DequeADT) {
		auto * deque = new LinkedList <int>();
		testQueueADT(deque);
		delete deque;
	}

BOOST_AUTO_TEST_SUITE_END()
