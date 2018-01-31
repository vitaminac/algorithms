#ifndef List_ADT
#define List_ADT
#include "../Collection/Collection.h"
#include "ListIterator.h"
#include "../function.h"
#include "../Exception/NoSuchElementException.h"
#include "../Exception/IndexOutOfBoundsException.h"
#include "../Sort/Timsort.h"

using std::unique_ptr;

// An iterator over a collection.
template <class E>
class List : public Collection <E> {
protected:
	bool isElementIndex (int index) const {
		return !(index < 0 || index >= this->size());
	}

public:
	List () = default;

	virtual ~List () = default;

	virtual void add (const E & e) override {
		this->insert(this->size(), e);
	}

	virtual void sort (Comparator <E> compare) {
		int size = this->size();
		auto ar = this->toArray();
		timsort(ar, 0, size, compare);
		auto it = unique_ptr <ListIterator <E>>(this->iterator());
		for (int i = 0; i < size; i++) {
			it->next();
			it->set(ar[i]);
		}
		delete[] ar;
	}

	virtual E & get (int index) const = 0;

	virtual E set (int index, const E & e) = 0;

	virtual void insert (int index, const E & e) = 0;

	using Collection <E>::remove;

	virtual E remove (int index) = 0;

	virtual int indexOf (const E & e) {
		auto it = unique_ptr <ListIterator <E>>(this->iterator());
		while (it->hasNext()) {
			if (e == it->next()) {
				return it->previousIndex();
			}
		}
		throw NoSuchElementException();
	}

	virtual int lastIndexOf (const E & e) {
		auto it = unique_ptr <ListIterator <E>>(this->iterator());
		while (it->hasPrevious()) {
			if (e == it->previous()) {
				return it->nextIndex();
			}
		}
		throw NoSuchElementException();
	}

	virtual List <E> * subList (int fromIndex, int toIndex) const
	=
	0;

	virtual ListIterator <E> * iterator () override = 0;
};
#endif
