#pragma once
#ifndef Queue_ADT_H
#define Queue_ADT_H
#include "../Collection/Collection.h"

template <class E>
class Queue : public virtual Collection <E> {
public:
	Queue () {
	}

	virtual ~Queue () {
	}

	virtual void add (const E & e) override;

	// Inserts the specified element into this queue
	virtual void enqueue (const E & e) = 0;

	// Retrieves and removes the head of this queue
	virtual E dequeue () = 0;

	// Retrieves, but does not remove, the head of this queue
	virtual E & peek () = 0;

	virtual E & first ();
};

#endif
