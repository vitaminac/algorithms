#ifndef QuickSort_H
#define QuickSort_H
#include "SortingAlgorithm.h"
#include "function/Comparator.h"

template <class E>
class QuickSort : public SortingAlgorithm <E> {
private:
	const Comparator <E> compare;

	void sort (E * arr, int head, int pivot) const {
		if (head < pivot) {
			int left = head;
			int right = pivot - 1;
			E tmp;
			while (right >= left) {
				if (compare(arr[left], arr[pivot]) > 0) {
					tmp = arr[right];
					arr[right--] = arr[left];
					arr[left] = tmp;
				} else {
					left += 1;
				}
			}
			tmp = arr[left];
			arr[left] = arr[pivot];
			arr[pivot] = tmp;
			sort(arr, head, right);
			sort(arr, left + 1, pivot);
		}
	}

public:
	explicit QuickSort (const Comparator <E> compare): compare(compare) {
	}

	virtual ~QuickSort () = default;

	virtual void sort (E * arr, int length) const override {
		sort(arr, 0, length - 1);
	}
};
#endif
