#include "Queue.h"

template <class E>
void Queue <E>::add (const E & e) {
	this->enqueue(e);
}

template <class E>
E & Queue <E>::first () {
	return this->peek();
}
