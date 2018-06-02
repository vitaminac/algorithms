#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "collection/LinkedList.h"
#include "exception/CollectionIsEmptyException.h"
#include "exception/ConcurrentModificationException.h"
#include "test/Object.h"

BOOST_AUTO_TEST_SUITE(DoublyLinkedListTest)

	BOOST_AUTO_TEST_CASE (TestingSizeIncrement) {
		LinkedList <int> list = LinkedList <int>();
		list.addFirst(2);
		BOOST_CHECK_EQUAL(list.size(), 1);
		const int temp = list.removeFirst();
		BOOST_CHECK_EQUAL(list.size(), 0);
		BOOST_CHECK_EQUAL(2, temp);
	}

	BOOST_AUTO_TEST_CASE(TestingGetWhenEmpty) {
		LinkedList <int> list = LinkedList <int>();
		BOOST_CHECK_THROW(list.first(), CollectionIsEmptyException);
		BOOST_CHECK_THROW(list.last(), CollectionIsEmptyException);
	}

	BOOST_AUTO_TEST_CASE(TestingGetFirst) {
		LinkedList <int> list = LinkedList <int>();
		list.addFirst(2);
		BOOST_CHECK_EQUAL(2, list.first());
		list.addFirst(3);
		BOOST_CHECK_EQUAL(3, list.first());
		list.addFirst(4);
		BOOST_CHECK_EQUAL(4, list.first());
		list.addLast(1);
		BOOST_CHECK_EQUAL(4, list.first());
	}

	BOOST_AUTO_TEST_CASE(TestingGetLast) {
		LinkedList <int> list = LinkedList <int>();
		list.addLast(2);
		BOOST_CHECK_EQUAL(2, list.last());
		list.addLast(3);
		BOOST_CHECK_EQUAL(3, list.last());
		list.addLast(4);
		BOOST_CHECK_EQUAL(4, list.last());
		list.addFirst(1);
		BOOST_CHECK_EQUAL(4, list.last());
	}

	BOOST_AUTO_TEST_CASE(TestingAddFirst) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.addFirst(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddLast) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.addLast(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAdd) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.add(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.removeFirst());
		}
	}

	BOOST_AUTO_TEST_CASE(TestingADDFirstAddLast) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			if ((i % 2) == 0) {
				list.addFirst(-i);
			} else {
				list.addLast(i);
			}
		}
		int prev = -5000;
		for (int i = 0; i < 100; i++) {
			int x = list.removeFirst();
			BOOST_CHECK_GT(x, prev);
			prev = x;
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddFirstAndRemoveFirst) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.addFirst(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 99; i >= 0; i--) {
			BOOST_CHECK_EQUAL(i, list.removeFirst());
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddFirstAndRemoveLast) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.addFirst(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.removeLast());
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddLastAndRemoveFirst) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.addLast(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.removeFirst());
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddLastAndRemoveLast) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.addLast(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 99; i >= 0; i--) {
			BOOST_CHECK_EQUAL(i, list.removeLast());
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingClear) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.add(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		list.clear();
		BOOST_CHECK_THROW(list.first(), CollectionIsEmptyException);
		BOOST_CHECK_THROW(list.last(), CollectionIsEmptyException);
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingQueueMethod) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.enqueue(i);
		}
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.first());
			BOOST_CHECK_EQUAL(i, list.dequeue());
		}
	}

	BOOST_AUTO_TEST_CASE(TestingAddAll) {
		// also concurrent test
		BOOST_CHECK(false); // leave for future
	}

	BOOST_AUTO_TEST_CASE(TestingAddDerivedClass) {
		Object b = Object(1);
		ConcreteObject d = ConcreteObject(2, 3);
		Object & baseRef1 = b;
		Object & baseRef2 = d;
		baseRef1.print();
		baseRef2.print();
		Object baseValue1 = baseRef1;
		Object baseValue2 = baseRef2;
		baseValue1.print();
		baseValue2.print();
		LinkedList <Object> list = LinkedList <Object>();
		list.add(b);
		// object slicing
		list.add(d);
		Object b1 = list.removeFirst();
		Object b2 = list.removeFirst();
		b1.print();
		b2.print();
		BOOST_CHECK(false); // leave for future
	}

BOOST_AUTO_TEST_SUITE_END()
