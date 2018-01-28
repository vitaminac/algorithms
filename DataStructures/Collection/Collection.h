#ifndef Collection_ADT_H
#define Collection_ADT_H
#include "Iterable.h"
#include "ADT.h"

using std::unique_ptr;

// An iterator over a collection.
template <class E>
class Collection : public Iterable <E>, public virtual ADT <E> {
public:
	Collection () = default;
	virtual ~Collection () = default;

	virtual bool contains (const E & e) {
		auto it = unique_ptr <Iterator <E>>(this->iterator());
		while (it->hasNext()) {
			if (e == it->next()) {
				return true;
			}
		}
		return false;
	}

	virtual bool containsAll (const Collection <E> & c) {
		bool modified = false;
		unique_ptr <Iterator <E>> it = unique_ptr <Iterator <E>>(this->iterator());
		while (it->hasNext())
			if (!this->contains(it->next())) {
				return false;
			}
		return true;
	}

	virtual bool remove (const E & e) {
		unique_ptr <Iterator <E>> it = unique_ptr <Iterator <E>>(this->iterator());
		while (it->hasNext()) {
			if (e == it->next()) {
				it->remove();
				return true;
			}
		}
		return false;
	}

	virtual void removeAll (Collection <E> & c) {
		c.forEach([this] (const E & e)
		{
			this->add(e);
		});
	}

	virtual void clear (Consumer <E> consume) override {
		unique_ptr <Iterator <E>> it = unique_ptr <Iterator <E>>(this->iterator());
		while (it->hasNext()) {
			it->next();
			consume(it->remove());
		}
	}

	virtual E * toArray () {
		const int length = this->size();
		auto elements = static_cast <E *>(operator new[](length * sizeof(E)));
		unique_ptr <Iterator <E>> it = unique_ptr <Iterator <E>>(this->iterator());
		for (int i = 0; i < length; i++) {
			elements[i] = it->next();
		}
		return elements;
	}
};
#endif
