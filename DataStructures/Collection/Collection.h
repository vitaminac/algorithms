#pragma once
#pragma once
#ifndef Collection_H
#define Collection_H

template <class E>
class Collection {
public:
	virtual ~Collection () = default;

	virtual void add (const E & e) = 0;

	virtual int size () const = 0;

	virtual bool isEmpty () const {
		return this->size() == 0;
	}

	virtual void clear () = 0;
};
#endif
