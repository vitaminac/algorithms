#include "ADTTest.h"

void testQueueADT(Queue <int> * queue) {
	for (int i = 1; i <= 100; i++) {
		queue->enqueue(i);
	}
	for (int i = 1; i <= 100; i++) {
		BOOST_CHECK_EQUAL(i, queue->first());
		BOOST_CHECK_EQUAL(i, queue->dequeue());
	}
}