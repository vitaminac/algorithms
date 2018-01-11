#pragma once
#ifndef List_Iterator
#define List_Iterator
#include "List.h"

template <class E>
class List;

// An iterator over a collection.
template <class E>
class ListIterator : Iterator <E> {
public:
	ListIterator () = default;

	virtual ~ListIterator () = default;

	virtual bool hasPrevious () const = 0;

	virtual E & previous () = 0;

	virtual int nextIndex () const = 0;

	virtual int previousIndex () const = 0;

	virtual void set (const E & e) = 0;

	virtual void add (const E & e) = 0;
};
#endif
