#ifndef Queue_ADT_H
#define Queue_ADT_H
#include "../Collection/ADT.h"

template <class E>
class Queue : virtual public ADT <E> {
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
