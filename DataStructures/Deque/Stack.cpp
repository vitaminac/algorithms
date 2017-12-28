#include "Stack.h"

template <class E>
void Stack <E>::add (const E & e) {
	this->push(e);
}

template <class E>
E & Stack <E>::top () {
	return this->peek();
}
