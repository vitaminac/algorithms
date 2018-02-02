#ifndef Iterable_H
#define Iterable_H
#include <memory>
#include "Iterator.h"
#include "function/function.h"

template <class E>
class Iterable {
public:
	Iterable () = default;
	virtual ~Iterable () = default;

	// you should use smart pointer wrapper
	virtual Iterator <E> * iterator () = 0;

	virtual void forEach (Consumer <E> consume) {
		auto it = std::unique_ptr <Iterator <E>>(this->iterator());
		while (it->hasNext()) {
			consume(it->next());
		}
	}
};
#endif
