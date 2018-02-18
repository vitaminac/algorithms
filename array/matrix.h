#ifndef matrix_h
#define matrix_h
#include "vector.h"
#include "dimension.h"
#include <iostream>

template <class E>
class Matrix : public Vector <E> {
private:
	const Dimension * const dim;

	Matrix (E * elements, Dimension * dim): Vector <E>(elements, dim->size()), dim(dim) {
	}

public:
	virtual ~Matrix () {
		delete dim;
	}

	friend std::ostream & operator<< (std::ostream & os, const Matrix <E> & m) {
		const Dimension & dim = *m.dim;
		for (int i = 0; i < dim.size(); i++) {
			os << m.elements[i] << " ";
			for (int d : dim) {
				if (i % d == d - 1) {
					os << std::endl;
				}
			}
		}
		return os;
	}

	static Matrix <E> * eye (int n) {
		auto elements = new E[n * n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					elements[i * n + j] = 1;
				} else {
					elements[i * n + j] = 0;
				}
			}
		}
		return new Matrix(elements, new Dimension(new int[2] {n, n}, 2));
	}
};
#endif
