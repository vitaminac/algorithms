#ifndef Sequence_H
#define Sequence_H
#include "behavior/RandomAccess.h"
#include "function/Comparator.h"
#include "exception/NoSuchElementException.h"
#include "sort/sorting.h"

/*
 * A linear sequence of elements that 
 * support for adding or removing elements at arbitrary positions
 */
template <class E>
class Sequence : public RandomAccess <E> {
public:
	virtual ~Sequence () = default;

	// Returns the number of elements
	virtual int size () const = 0;

	void sort (Comparator <E> compare) {
		int size = this->size();
		auto ar = this->toArray();
		Sorting <E>::timsort(ar, 0, size, compare);
		for (int i = 0; i < size; i++) {
			this->set(i, ar[i]);
		}
		delete[] ar;
	}

	// Inserts a new element e into the list so that it has index i, 
	// moving all subsequent elements one index later in the list;
	virtual void insert (int index, const E & e) = 0;

	// Removes and returns the element at index i
	virtual E remove (int index) = 0;

	// Returns the index of the first occurrence of the specified element
	int indexOf (const E & e) {
		auto size = this->size();
		for (auto i = 0; i < size; i++) {
			if (this->get(i) == e) {
				return i;
			}
		}
		throw NoSuchElementException();
	}

	// Returns the index of the last occurrence of the specified element
	int lastIndexOf (const E & e) {
		auto size = this->size();
		for (auto i = size - 1; i >= 0; --i) {
			if (this->get(i) == e) {
				return i;
			}
		}
		throw NoSuchElementException();
	}
};
#endif
