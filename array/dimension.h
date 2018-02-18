#ifndef dimension_h
#define dimension_h
#include "vector.h"

class Dimension : private Vector <int> {
private:
public:
	Dimension (const int * dims, const int cardinality): Vector <int>(dims, cardinality) {
	}

	virtual ~Dimension () {
	}

	inline int cardinality () const {
		return this->dim;
	}

	inline const int * dims () const {
		return this->elements;
	}

	inline int size () const {
		return this->product();
	}

	const int * begin () const {
		return this->dims();
	}

	const int * end () const {
		return &this->dims()[this->cardinality() - 1];
	}

	inline virtual bool operator== (const Dimension & right) const {
		return Vector <int>::operator==(right);
	}

	inline virtual const int & operator[] (const int index) const override {
		return Vector <int>::operator[](index);
	}
};
#endif
