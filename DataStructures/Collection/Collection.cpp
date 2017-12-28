#include "Collection.h"


template <class E>
Collection <E>::~Collection () {
	this->clear();
}

template <class E>
bool Collection <E>::isEmpty () const {
	return this->size() == 0;
}


template <class E>
bool Collection <E>::contains (const E & e) const {
	Iterator <E> & it = this->iterator();
	if (e == nullptr) {
		while (it.hasNext())
			if (it.next() == nullptr)
				return true;
	} else {
		while (it.hasNext())
			if (e == it.next())
				return true;
	}
	return false;
}

template <class E>
bool Collection <E>::containsAll (const Collection <E> & c) const {
	bool modified = false;
	Iterator <E> & it = c->iterator();
	while (it.hasNext())
		if (!this->contains(it.next())) {
			return false;
		}
	return true;
}

template <class E>
void Collection <E>::addAll (const Collection <E> & c) {
	c.forEach(this.add);
}

template <class E>
bool Collection <E>::remove (const E & e) {
	Iterator <E> & it = this->iterator();
	if (e == nullptr) {
		while (it.hasNext())
			if (it.next() == nullptr) {
				it.remove();
				return true;
			}
	} else {
		while (it.hasNext())
			if (e == it.next()) {
				it.remove();
				return true;
			}
	}
	return false;
}

template <class E>
void Collection <E>::removeAll (const Collection <E> & c) {
	c.forEach(this.remove);
}

template <class E>
void Collection <E>::clear () {
	Iterator <E> it = this->iterator();
	while (it.hasNext()) {
		it.next();
		it.remove();
	}
}

template <class E>
E * Collection <E>::toArray () const {
	int length = this->size();
	Iterator <E> it = this->iterator();
	auto elements = new E[length];
	for (int i = 0; i < length; i++) {
		elements[i] = it.next();
	}
	return elements;
}
