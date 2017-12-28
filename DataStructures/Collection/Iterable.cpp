#include "Iterable.h"

template <class E>
void Iterable <E>::forEach (void (*consumer) (E &)) {
	Iterator <E> iterator = this->iterator();
	while (iterator.hasNext()) {
		consumer(iterator.next());
	}
}
