#include "ADTTest.h"

void testDequeADT (Deque <int> * deque) {
	BOOST_CHECK_THROW(deque->first(), CollectionIsEmptyException);
	BOOST_CHECK_THROW(deque->last(), CollectionIsEmptyException);
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
