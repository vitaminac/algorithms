#ifndef Collection_H
#define Collection_H
#include "base/Object.h"
#include "iterate/Iterable.h"
#include "behavior/Cloneable.h"

// An iterator over a collection.
template <class E>
class Collection : public Object, public Iterable <E> {
public:
	Collection () = default;
	virtual ~Collection () = default;

	// if this contains no elements
	virtual bool isEmpty () const = 0;

	// Returns the number of elements
	virtual int size () const = 0;

	// posible object slicing
	// Ensures that this collection contains the specified element
	virtual void add (const E & e) = 0;

	// Removes a single instance of the specified element from this collection
	virtual bool remove (const E & e) = 0;

	// Removes all of the elements from this collection
	virtual void clear () = 0;

	virtual Collection <E> * clone () override = 0;

	void merge (Iterable <E> & iterable) {
		iterable.stream().forEach([this] (const E & e)
		{
			this->add(e);
		});
	}

	// if this collection contains the specified element
	virtual bool contains (const E & key) {
		return this->stream().anyMatch([&key] (const E & e)
		{
			return key == e;
		});
	}

	virtual E * toArray () {
		const auto length = this->size();
		E * arr = static_cast <E *>(operator new[](length * sizeof(E)));
		auto index = 0;
		return this->stream().template collect <E *>(arr, [&index] (E * collection, const E & e)
		{
			collection[index++] = e;
			return collection;
		});
	}
};
#endif
