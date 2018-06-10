#ifndef InplaceSort_H
#define InplaceSort_H
#include "SortingAlgorithm.h"
#include "function/Comparator.h"

template <class E>
class InplaceSort : public SortingAlgorithm <E> {
private:
	const Comparator <E> compare;

	inline static void swap (E * arr, int left, int right) {
		E tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
	}

public:
	explicit InplaceSort (const Comparator <E> compare = DefaultComparator<E>) : compare(compare) {
	}

	virtual ~InplaceSort () = default;

	virtual void sort (E * arr, int length) const override {
		// when array is length of 1, then it is already sorted
		if (length <= 1) {
			return;
		}
		// Initialization, the loop invariant holds before the firsst loop iteration
		// array of single element is always sorted
		int j;
		for (int i = 1; i < length; i++) {
			// Maintenance, each iteration maintains the loop invariant
			// The subarray [0...j-1] consists of the elements in sorted order
			// we move by one position to the right until it find the proper position
			// incrementing i for the next iteration of the for loop 
			// then perserve the loop invariant
			j = i - 1;
			while (j >= 0 && compare(arr[j], arr[j + 1]) > 0) {
				swap(arr, j, j + 1);
				j--;
			}
		}
		// Termination, increments i in each iteration until i equals to length
		// and in each iteration the loop invariant perserve
		// we conclude that the entire array is sorted
	}
};
#endif
