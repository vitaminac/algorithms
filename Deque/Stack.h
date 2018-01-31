#ifndef Stack_ADT_H
#define Stack_ADT_H
#include "../Collection/ADT.h"

template <class E>
class Stack : virtual public ADT <E> {
public:

	virtual ~Stack () = default;

	virtual void add (const E & e) override {
		this->push(e);
	}

	// Pushes an element onto the stack
	virtual void push (const E & e) = 0;

	// Pops an element from the stack
	virtual E pop () = 0;

	// Retrieves, but does not remove, the top of this stack
	virtual E & peek () = 0;
};

#endif
