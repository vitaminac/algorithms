#include <boost/test/unit_test.hpp>
#include "List/LinkedList/DoublyLinkedList.h"

BOOST_AUTO_TEST_SUITE(DoublyLinkedListTest)

	BOOST_AUTO_TEST_CASE(TestingSizeInitialZero) {
		DoublyLinkedList <int> list = DoublyLinkedList <int>();
		BOOST_CHECK_EQUAL(list.size(), 0);
	}

	BOOST_AUTO_TEST_CASE (TestingSizeIncrement) {
		DoublyLinkedList <int> list = DoublyLinkedList <int>();
		list.addFirst(2);
		BOOST_CHECK_EQUAL(list.size(), 1);
		int temp = list.removeFirst();
		BOOST_CHECK_EQUAL(list.size(), 0);
		BOOST_CHECK_EQUAL(temp, 2);
	}

	BOOST_AUTO_TEST_CASE(TestingIf2x2equals4) {
		BOOST_CHECK_EQUAL(2 * 2, 4);
	}

BOOST_AUTO_TEST_SUITE_END()
