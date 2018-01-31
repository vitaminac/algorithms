#ifndef function_ADT
#define function_ADT
#include <functional>
using std::function;

template <typename E>
using Consumer = function <void  (const E &)>;

template <typename E>
using Comparator = function <int  (const E &, const E &)>;

template <class E>
inline void freeMemory (const E & e) {
	if (e != nullptr) {
		delete e;
	}
}

template <class E>
inline void doNothing (const E & e) {
}
#endif
