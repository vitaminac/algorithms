#pragma once
#pragma once
#ifndef Collection_H
#define Collection_H
#include "Iterable.h"

template <class E>
class Collection {
public:
	virtual ~Collection () = default;

	virtual void add (const E e) = 0;

	virtual void addAll (const Iterable <E> & iterable) {
		iterable.forEach([this] (const E & e)
		{
			this->add(e);
		});
	}

	virtual int size () const = 0;

	virtual bool isEmpty () const {
		return this->size() == 0;
	}

	virtual void clear () = 0;
};
#endif
