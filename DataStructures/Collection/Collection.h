#pragma once
#ifndef Collection_ADT_H
#define Collection_ADT_H
#include "Iterable.h"

// An iterator over a collection.
template <class E>
class Collection : public Iterable <E> {
public:
	Collection () {
	}

	virtual ~Collection ();

	virtual int size () const = 0;

	virtual bool isEmpty () const;

	virtual bool contains (const E & e) const;

	virtual bool containsAll (const Collection <E> & c) const;

	virtual void add (const E & e) = 0;

	virtual void addAll (const Collection <E> & c);

	virtual bool remove (const E & e);

	virtual void removeAll (const Collection <E> & c);

	virtual void clear ();

	virtual E * toArray () const;
};
#endif
