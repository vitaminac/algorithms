#pragma once
#ifndef IndexOutOfBoundsException_H
#define IndexOutOfBoundsException_H
#include <exception>

class IndexOutOfBoundsException final : std::exception {
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
