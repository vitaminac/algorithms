#pragma once
#ifndef Queue_ADT_H
#define Queue_ADT_H
#include "../Collection/Collection.h"

template <class E>
class Queue : public virtual Collection <E> {
public:

	virtual ~Queue () = default;

	virtual void add (const E & e) override {
		this->enqueue(e);
	}

	// Inserts the specified element into this queue
	virtual void enqueue (const E & e) = 0;

	// Retrieves and removes the head of this queue
	virtual E dequeue () = 0;

	// Retrieves, but does not remove, the head of this queue
	virtual E & peek () = 0;
};

#endif
