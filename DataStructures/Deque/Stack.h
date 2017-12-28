#pragma once
#ifndef Stack_ADT_H
#define Stack_ADT_H
#include "../Collection/Collection.h"

template <class E>
class Stack : public virtual Collection <E> {
public:
	Stack () {
	};

	virtual ~Stack () {
	}

	virtual void add (const E & e) override;

	// Pushes an element onto the stack
	virtual void push (const E & e) = 0;

	// Pops an element from the stack
	virtual E pop () = 0;

	// Retrieves, but does not remove, the top of this stack
	virtual E & peek () = 0;

	virtual E & top ();
};

#endif
