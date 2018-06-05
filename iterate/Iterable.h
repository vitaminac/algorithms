#ifndef Iterable_H
#define Iterable_H
#include "Iterator.h"
#include "Stream.h"

template <class E>
class Iterable {
public:
	Iterable () = default;
	virtual ~Iterable () = default;

	// you should use smart pointer wrapper
	virtual Iterator <E> * iterator () const = 0;

	Stream <E> stream () const {
		return Stream <E>(this->iterator());
	};
};
#endif
