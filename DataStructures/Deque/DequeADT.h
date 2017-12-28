#pragma once
#ifndef Deque_ADT_H
#define Deque_ADT_H
#include "../Collection/Collection.h"

// A linear collection that supports element insertion and removal at both ends.
template <class E>
class DequeADT : public virtual Collection <E> {
public:
	virtual ~DequeADT () = default;

	virtual void add (const E & e) override {
		this->addLast(e);
	}

	// Inserts the specified element at the front of this deque
	virtual void addFirst (const E & e) = 0;

	// Inserts the specified element at the end of this deque
	virtual void addLast (const E & e) = 0;

	// Retrieves and removes the first element of this deque
	virtual E removeFirst () = 0;

	// Retrieves and removes the last element of this deque
	virtual E removeLast () = 0;

	// Retrieves, but does not remove, the first element of this deque
	virtual E & getFirst () const = 0;

	// Retrieves, but does not remove, the last element of this deque
	virtual E & getLast () const = 0;
};
#endif
