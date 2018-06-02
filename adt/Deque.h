#ifndef Deque_H
#define Deque_H

// A linear collection that supports element insertion and removal at both ends.
template <class E>
class Deque {
public:
	virtual ~Deque () = default;

	// Returns the first element of the deque, without removing it
	virtual E & first () const = 0;

	// Returns the top element of the deque, without removing it
	virtual E & last () const = 0;

	// Insert a new element e at the front of the deque
	virtual void addFirst (const E & e) = 0;

	// Insert a new element e at the back of the deque.
	virtual void addLast (const E & e) = 0;

	// Remove and return the first element of the deque
	virtual E removeFirst () = 0;

	// Remove and return the last element of the deque
	virtual E removeLast () = 0;
};
#endif
