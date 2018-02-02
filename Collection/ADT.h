#ifndef ADT_H
#define ADT_H
#include "Iterable.h"
#include "function/function.h"

template <class E>
class ADT {
public:
	ADT () = default;
	virtual ~ADT () = default;

	// posible object slicing
	virtual void add (const E & e) = 0;

	virtual void addAll (Iterable <E> & iterable) {
		iterable.forEach([this] (const E & e)
		{
			this->add(e);
		});
	}

	virtual int size () const = 0;

	virtual bool isEmpty () const {
		return this->size() == 0;
	}

	virtual void clear (Consumer <E> consume) = 0;

	inline void clear () {
		this->clear(doNothing <E>);
	}
};
#endif
