#ifndef Queue_H
#define Queue_H

/* 
 * The Queue abstract data type defines a collection that
 * keeps objects in a sequence, where element access and deletion
 * are restricted to the first element in the queue,
 * and element insertion is restricted to the back of the sequence.
 * This restriction enforces the rule of the first-in, first-out (FIFO)
*/
template <class E>
class Queue {
public:
	virtual ~Queue () = default;

	// Returns the first element of the queue, without removing it
	virtual E & first () const = 0;

	// Adds element e to the back of queue
	virtual void enqueue (const E & e) = 0;

	// Removes and returns the first element from the queue
	virtual E dequeue () = 0;
};

#endif
