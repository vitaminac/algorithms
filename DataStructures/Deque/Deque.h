#pragma once
#ifndef Deque_ADT_H
#define Deque_ADT_H
#include "Queue.h"
#include "Stack.h"

// A linear collection that supports element insertion and removal at both ends.
template <class E>
class Deque : public virtual Queue <E>, public virtual Stack <E> {
public:
	Deque () {
	}

	virtual ~Deque () {
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

	// Removes the first occurrence of the specified element from this deque
	virtual bool removeFirstOccurrence (const E & e) = 0;

	// Removes the last occurrence of the specified element from this deque
	virtual bool removeLastOccurrence (const E & e) = 0;

	virtual Iterator <E> descendingIterator () const = 0;

	virtual void enqueue (const E & e) override;

	virtual E dequeue () override;

	virtual E & peek () override;

	// alias of addLast
	virtual void add (const E & e) override;

	virtual void push (const E & e) override;

	virtual E pop () override;
};
#endif
