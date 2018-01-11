#ifndef Collection_ADT_H
#define Collection_ADT_H
#include "Iterable.h"
#include "ADT.h"

// An iterator over a collection.
template <class E>
class Collection : public Iterable <E>, public ADT <E> {
public:
	Collection () = default;
	virtual ~Collection () = default;

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

	virtual bool containsAll (const Collection <E> & c) const {
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

	virtual void removeAll (const Collection <E> & c) {
		c.forEach(this.remove);
	}

	virtual void clear (Consumer <E> consume) override {
		Iterator <E> it = this->iterator();
		while (it.hasNext()) {
			it.next();
			consume(it.remove());
		}
	}

	virtual E * toArray () const {
		const int length = this->size();
		Iterator <E> it = this->iterator();
		auto elements = new E[length];
		for (int i = 0; i < length; i++) {
			elements[i] = it.next();
		}
		return elements;
	}
};
#endif
