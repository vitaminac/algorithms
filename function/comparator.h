#ifndef comparator_h
#define comparator_h
#include <functional>
using std::function;

template <typename E>
using Comparator = function <int  (const E &, const E &)>;

template <typename T>
int DefaultComparator (const T & lhs, const T & rhs) {
	if (lhs < rhs) {
		return -1;
	} else if (rhs < lhs) {
		return 1;
	} else {
		return 0;
	}
}
#endif
