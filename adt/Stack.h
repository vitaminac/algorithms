#ifndef Stack_H
#define Stack_H

/*
 * The Stack abstract data type defines a collection that
 * inserted and removed according to the last-in, first-out (LIFO) principle.
 */
template <class E>
class Stack {
public:
	virtual ~Stack () = default;

	// Returns the top element of the stack, without removing it
	virtual E & last () const = 0;

	// Adds element e to the top of the stack
	virtual void push (const E & e) = 0;

	// Removes and returns the top element from the stack
	virtual E pop () = 0;
};

#endif
