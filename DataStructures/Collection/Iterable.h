#pragma once
#ifndef Iterable_H
#define Iterable_H
#include "Iterator.h"
#include <functional>

template <class E>
class Iterable {
public:
	virtual ~Iterable () = default;

	virtual Iterator <E> & iterator () const = 0;

	virtual void forEach (std::function <void  (const E &)> consumer) const {
		Iterator <E> & it = this->iterator();
		while (it.hasNext()) {
			consumer(it.next());
		}
	}
};
#endif
//void (*consumer) (const E &)
