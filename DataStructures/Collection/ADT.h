#ifndef ADT_H
#define ADT_H
#include <functional>
#include "Iterable.h"
#include "../function.h"

using namespace std::placeholders;

template <class E>
class ADT {
public:
	ADT () = default;
	virtual ~ADT () = default;

	// posible object slicing
	virtual void add (const E & e) = 0;

	virtual void addAll (Iterable <E> & iterable) {
		iterable.forEach(std::bind(&ADT::add, this, _1));
	}

	virtual int size () const = 0;

	virtual bool isEmpty () const {
		return this->size() == 0;
	}

	virtual void clear (Consumer <E> consume) = 0;
};
#endif
