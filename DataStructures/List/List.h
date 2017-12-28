#pragma once
#ifndef List_ADT
#define List_ADT
#include "../Collection/Collection.h"
#include "ListIterator.h"

template <class E>
class ListIterator;

// An iterator over a collection.
template <class E>
class List : public virtual Collection <E> {
protected:
	bool isElementIndex (int index);
public:
	List () {
	}

	virtual ~List () {
	}

	virtual void add (const E & e) override;

	virtual void sort (int (*compare) (const E &, const E &));

	virtual E & get (int index) const = 0;

	virtual E set (int index, const E & e) = 0;

	virtual void insert (int index, const E & e) = 0;

	using Collection <E>::remove;

	virtual E remove (int index) = 0;

	virtual int indexOf (const E & e) const;

	virtual int lastIndexOf (const E & e) const;

	virtual List <E> & subList (int fromIndex, int toIndex) = 0;

	virtual Iterator <E> iterator () const override;

	virtual ListIterator <E> listIterator () const;
};
#endif
