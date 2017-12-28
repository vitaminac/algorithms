#pragma once
#ifndef Iterable_H
#define Iterable_H
#include "Iterator.h"

template <class E>
class Iterable {
public:
	Iterable () {
	}

	virtual ~Iterable () {
	}

	virtual Iterator <E> iterator () const = 0;

	virtual void forEach (void (*consumer) (E &));
};
#endif
