#ifndef matrix
#define matrix
#include "vector.h"
#include "dimension.h"

template <class E>
class Matrix : Vector <E> {
private:
	const Dimension dim;

	Matrix (E * elements, Dimension dim): Vector <E>(elements, dim.size()), dim(dim) {
	}
};
#endif
