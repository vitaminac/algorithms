#pragma once
#ifndef List_Iterator
#define List_Iterator
#include "List.h"

template <class E>
class List;

// An iterator over a collection.
template <class E>
class ListIterator : Iterator <E> {
protected:
	// Index of element returned by most recent call to next or previous
	int lastRet = -1;
	List <E> & list;
	int cursor = 0;
public:
	explicit ListIterator (List <E> & list) : list(list) {
	};

	explicit ListIterator (List <E> & list, int index) : list(list), cursor(index) {
	}

	virtual ~ListIterator () {
	}

	virtual bool hasNext () const override;

	virtual bool hasPrevious () const;

	virtual E & next () override;

	virtual E & previous ();

	virtual void remove () override;

	virtual int nextIndex ();

	virtual int previousIndex ();

	virtual void set (const E & e);

	virtual void add (const E & e);
};
#endif
