#include "ADTTest.h"
#include "abstract/adt/Stack.h"

void testStackADT (Stack <int> * stack) {
	for (int i = 1; i <= 100; i++) {
		stack->push(i);
	}
	for (int i = 100; i > 0; i--) {
		BOOST_CHECK_EQUAL(i, stack->last());
		BOOST_CHECK_EQUAL(i, stack->pop());
	}
}
