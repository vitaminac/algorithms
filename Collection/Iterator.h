#pragma once
#ifndef Iterator_H
#define Iterator_H

// An iterator over a collection.
template <class E>
class Iterator {
public:
	Iterator () = default;

	virtual ~Iterator () = default;

	virtual bool hasNext () const = 0;

	virtual E & next () = 0;

	// Removes from the underlying collection the last element returned by this iterator
	virtual E remove () = 0;
};
#endif
