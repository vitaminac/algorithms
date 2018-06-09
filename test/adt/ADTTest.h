#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "adt/Stack.h"
#include "adt/Queue.h"
#include "adt/Deque.h"
#include "exception/CollectionIsEmptyException.h"

void testStackADT (Stack <int> * stack);
void testQueueADT (Queue <int> * queue);
void testDequeADT (Deque <int> * deque);
