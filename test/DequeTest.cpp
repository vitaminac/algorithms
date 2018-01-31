#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "List/LinkedList.h"
#include "Exception/CollectionEmptyException.h"
#include "Exception/ConcurrentModificationException.h"
#include "base.h"

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
		BOOST_CHECK_THROW(list.getFirst(), CollectionEmptyException);
		BOOST_CHECK_THROW(list.getLast(), CollectionEmptyException);
	}

	BOOST_AUTO_TEST_CASE(TestingGetFirst) {
		LinkedList <int> list = LinkedList <int>();
		list.addFirst(2);
		BOOST_CHECK_EQUAL(2, list.getFirst());
		list.addFirst(3);
		BOOST_CHECK_EQUAL(3, list.getFirst());
		list.addFirst(4);
		BOOST_CHECK_EQUAL(4, list.getFirst());
		list.addLast(1);
		BOOST_CHECK_EQUAL(4, list.getFirst());
	}

	BOOST_AUTO_TEST_CASE(TestingGetLast) {
		LinkedList <int> list = LinkedList <int>();
		list.addLast(2);
		BOOST_CHECK_EQUAL(2, list.getLast());
		list.addLast(3);
		BOOST_CHECK_EQUAL(3, list.getLast());
		list.addLast(4);
		BOOST_CHECK_EQUAL(4, list.getLast());
		list.addFirst(1);
		BOOST_CHECK_EQUAL(4, list.getLast());
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
		BOOST_CHECK_THROW(list.getFirst(), CollectionEmptyException);
		BOOST_CHECK_THROW(list.getLast(), CollectionEmptyException);
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingQueueMethod) {
		LinkedList <int> list = LinkedList <int>();
		for (int i = 0; i < 100; i++) {
			list.enqueue(i);
		}
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.peek());
			BOOST_CHECK_EQUAL(i, list.dequeue());
		}
	}

	BOOST_AUTO_TEST_CASE(TestingAddAll) {
		// also concurrent test
		BOOST_CHECK(false); // leave for future
	}

	BOOST_AUTO_TEST_CASE(TestingAddDerivedClass) {
		Base b = Base(1);
		DerivedObject d = DerivedObject(2, 3);
		Base & baseRef1 = b;
		Base & baseRef2 = d;
		baseRef1.print();
		baseRef2.print();
		Base baseValue1 = baseRef1;
		Base baseValue2 = baseRef2;
		baseValue1.print();
		baseValue2.print();
		LinkedList <Base> list = LinkedList <Base>();
		list.add(b);
		// object slicing
		list.add(d);
		Base b1 = list.removeFirst();
		Base b2 = list.removeFirst();
		b1.print();
		b2.print();
		BOOST_CHECK(false); // leave for future
	}

BOOST_AUTO_TEST_SUITE_END()
