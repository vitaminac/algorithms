#include "List.h"
#include "../Exception/NoSuchElementException.h"
#include "../Exception/IndexOutOfBoundsException.h"

template <class E>
bool List <E>::isElementIndex (int index) {
	if (index < 0 || index >= this.size()) {
		throw IndexOutOfBoundsException(index);
	}
	return true;
}

template <class E>
void List <E>::add (const E & e) {
	this->insert(this.size(), e);
}

template <class E>
void List <E>::sort (int (* compare) (const E &, const E &)) {
	int size = this->size();
	E ar[] = this.toArray();
	timsort(ar, 0, size, compare());
	ListIterator <E> it = this->iterator();
	for (int i = 0; i < size; i++) {
		it.next();
		it.set(ar[i]);
	}
	delete [] ar;
}

template <class E>
int List <E>::indexOf (const E & e) const {
	ListIterator <E> it = iterator();
	if (e == nullptr) {
		while (it.hasNext())
			if (it.next() == nullptr)
				return it.previousIndex();
	} else {
		while (it.hasNext())
			if (e == it.next())
				return it.previousIndex();
	}
	throw NoSuchElementException();
}

template <class E>
int List <E>::lastIndexOf (const E & e) const {
	ListIterator <E> it = ListIterator <E>(this, this.size());
	if (e == nullptr) {
		while (it.hasPrevious())
			if (it.previous() == nullptr)
				return it.nextIndex();
	} else {
		while (it.hasPrevious())
			if (e == it.previous())
				return it.nextIndex();
	}
	throw NoSuchElementException();
}

template <class E>
Iterator <E> List <E>::iterator () const {
	return this->listIterator();
}

template <class E>
ListIterator <E> List <E>::listIterator () const {
	return ListIterator <E>(this);
}
