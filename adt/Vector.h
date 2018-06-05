#ifndef Vector_H
#define Vector_H
#include "behavior/RandomAccess.h"
#include "exception/NoSuchElementException.h"
#include "function/sort/SortingAlgorithm.h"

/*
 * A linear sequence of elements that 
 * support for adding or removing elements at arbitrary positions
 */
template <class E>
class Vector : public RandomAccess <E> {
public:
	virtual ~Vector () = default;

	// Returns the cardinality of the basis
	virtual int size () const = 0;

	// Test if the dimension is zero
	inline bool isZeroVector () const {
		return this->size() == 0;
	}

	void sort (const SortingAlgorithm <E> & sorter) {
		const auto size = this->size();
		auto arr = this->toArray();
		sorter.sort(arr, size);
		for (int i = 0; i < size; i++) {
			this->operator[](i) = arr[i];
		}
		delete[] arr;
	}

	// Inserts a new element e into the list so that it has index i, 
	// moving all subsequent elements one index later in the list;
	virtual void insert (int index, const E & e) = 0;

	// Removes and returns the element at index i
	virtual E remove (int index) = 0;

	// Returns the index of the first occurrence of the specified element
	int indexOf (const E & e) {
		const auto size = this->size();
		for (auto i = 0; i < size; i++) {
			if (this->operator[](i) == e) {
				return i;
			}
		}
		throw NoSuchElementException();
	}

	// Returns the index of the last occurrence of the specified element
	int lastIndexOf (const E & e) {
		const auto size = this->size();
		for (auto i = size - 1; i >= 0; --i) {
			if (this->operator[](i) == e) {
				return i;
			}
		}
		throw NoSuchElementException();
	}

	E * toArray () const {
		const auto size = this->size();
		auto arr = static_cast <E *>(operator new[](size * sizeof(E)));
		auto index = 0;
		for (auto i = 0; i < size; i++) {
			arr[i] = this->operator[](i);
		}
		return arr;
	}
};
#endif
