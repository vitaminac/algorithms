#ifndef dimension_h
#define dimension_h

class Dimension {
private:
	const int * const dims;
	const int cardinality;
public:
	Dimension (int * dims, int cardinality): dims(dims), cardinality(cardinality) {
	}

	int size () const {
		int sum = 0;
		for (int i = 0; i < this->cardinality; i++) {
			sum += *(dims + i);
		}
		return sum;
	}
};
#endif
