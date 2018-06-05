#ifndef Collection_H
#define Collection_H
#include "iterate/Iterable.h"
#include "base/Object.h"

// An iterator over a collection.
template <class E>
class Collection : public Object, public Iterable <E> {
public:
	Collection () = default;
	virtual ~Collection () = default;

	virtual void add (const E & e) = 0;

	virtual bool isEmpty () const = 0;

	// Removes all of the elements from this collection
	virtual void clear () = 0;

	virtual Collection <E> * clone () const override = 0;
};
#endif
