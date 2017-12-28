#include "Deque.h"

template <class E>
void Deque <E>::enqueue (const E & e) {
	this->addLast(e);
}

template <class E>
E Deque <E>::dequeue () {
	return this->removeFirst();
}

template <class E>
void Deque <E>::push (const E & e) {
	this->addFirst(e);
}

template <class E>
E Deque <E>::pop () {
	return this->removeFirst();
}

template <class E>
E & Deque <E>::peek () {
	return this->getFirst();
}

template <class E>
void Deque <E>::add (const E & e) {
	this.addLast(e);
}
