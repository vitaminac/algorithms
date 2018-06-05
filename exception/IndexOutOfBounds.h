#ifndef IndexOutOfBounds_H
#define IndexOutOfBounds_H
#include "Exception.h"

class IndexOutOfBounds final : public Exception {
private:
	int index;
public:
	explicit IndexOutOfBounds (int index) : index(index) {
	}


	virtual string toString () override {
		std::ostringstream oss;
		oss << "index " << index << " out of bounds";
		return oss.str();
	}
};
#endif
