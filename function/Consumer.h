#ifndef Consumer_H
#define Consumer_H
#include <functional>
using std::function;

template <typename E>
using Consumer = function <void  (const E &)>;

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
