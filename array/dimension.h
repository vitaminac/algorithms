#ifndef dimension_h
#define dimension_h

class Dimension {
private:
	const int * const dims;
	const int cardinality;
public:
	Dimension (const int * dims, const int cardinality): dims(dims), cardinality(cardinality) {
	}

	Dimension (const Dimension & dim) : dims(dim.dims), cardinality(dim.cardinality) {
	}

	virtual ~Dimension () {
		delete[] dims;
	}

	int size () const {
		int dim = 1;
		for (int i = 0; i < this->cardinality; i++) {
			dim *= this->dims[i];
		}
		return dim;
	}

	const int * begin () const {
		return this->dims;
	}

	const int * end () const {
		return &this->dims[this->cardinality - 1];
	}
};
#endif
