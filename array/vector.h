#ifndef vector_h
#define vector_h
#include <cassert>
#include <algorithm>

template <class E>
class Vector {
private:
	E * const elements;
	const int dim;
public:
	Vector (E * elements, int dim) : elements(elements), dim(dim) {
	}

	virtual ~Vector () {
		delete this->elements;
	}

	virtual Vector <E> operator* (const Vector <E> & right) const {
		assert(right.dim == this->dim);
		E * elements = new E[this->dim];
		for (int i = 0; i < this->dim; i++) {
			elements[i] = this->elements[i] * right.elements[i];
		}
		return Vector <E>(elements, this->dim);
	}

	virtual bool operator== (const Vector <E> & right) const {
		if (this->dim == right.dim) {
			for (int i = 0; i < this->dim; i++) {
				if (this->elements[i] != right.elements[i]) {
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}

	friend std::ostream & operator<< (std::ostream & os, const Vector <E> & vector) {
		for (int i = 0; i < vector.dim; i++) {
			os << vector.elements[i];
		}
		return os;
	}
};
#endif
