#pragma once
#ifndef Collection_ADT_H
#define Collection_ADT_H
#include "Iterable.h"

// An iterator over a collection.
template <class E>
class CollectionADT : public Iterable <E> {
public:
	CollectionADT () {
	}

	virtual bool contains (const E & e) const {
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

	virtual bool containsAll (const CollectionADT <E> & c) const {
		bool modified = false;
		Iterator <E> & it = c->iterator();
		while (it.hasNext())
			if (!this->contains(it.next())) {
				return false;
			}
		return true;
	}

	virtual bool remove (const E & e) {
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

	virtual void removeAll (const CollectionADT <E> & c) {
		c.forEach(this.remove);
	}

	virtual void clear () {
		Iterator <E> it = this->iterator();
		while (it.hasNext()) {
			it.next();
			it.remove();
		}
	}

	virtual E * toArray () const {
		int length = this->size();
		Iterator <E> it = this->iterator();
		auto elements = new E[length];
		for (int i = 0; i < length; i++) {
			elements[i] = it.next();
		}
		return elements;
	}
};
#endif
