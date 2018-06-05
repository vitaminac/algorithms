#ifndef IndexOutOfBoundsException_H
#define IndexOutOfBoundsException_H
#include "Exception.h"

class IndexOutOfBoundsException final : public Exception {
private:
	const int index;
public:
	IndexOutOfBoundsException (int index): index(index) {
	}

	inline int getIndex () const {
		return index;
	}
};
#endif
