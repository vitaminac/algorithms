#ifndef SortingAlgorithm_H
#define SortingAlgorithm_H

template <class E>
class SortingAlgorithm {
public:
	virtual ~SortingAlgorithm () = default;
	virtual void sort (E * arr, int length) const = 0;
};
#endif
