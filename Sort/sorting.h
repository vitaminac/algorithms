#ifndef Sorting_Algorithms_H
#define  Sorting_Algorithms_H
#include "../function.h"

template <class E>
class Sorting {
private:
	inline static void swap (E * left, E * right) {
		E tmp = *left;
		*left = *right;
		*right = tmp;
	}

public:
	static void inplacesort (E * arr, int length) {
		// when array is length of 1, then it is already sorted
		if (length <= 1) {
			return;
		}
		// Initialization, the loop invariant holds before the firsst loop iteration
		// array of single element is always sorted
		for (int i = 1; i < length; i++) {
			// Maintenance, each iteration maintains the loop invariant
			// The subarray [0...j-1] consists of the elements in sorted order
			// we move by one position to the right until it find the proper position
			// incrementing i for the next iteration of the for loop 
			// then perserve the loop invariant
			for (int j = i - 1; (j >= 0) && (arr[j] > arr[j + 1]); j--) {
				swap(arr + j, arr + j + 1);
			}
		}
		// Termination, increments i in each iteration until i equals to length
		// and in each iteration the loop invariant perserve
		// we conclude that the entire array is sorted
	}

	static void timsort (E * array, int low, int high, Comparator <E> compare) {

	}
};

#endif
