#ifndef Observer_H
#define Observer_H
#include "Subject.h"

template <class E>
class Observer {
	// support for observing more than one subject
	virtual void push (const Subject <Observer <E>> & source, const E & event) = 0;
};
#endif
