#ifndef function_ADT
#define function_ADT
#include <functional>
template <typename E>
using Consumer = std::function <void  (const E &)>;

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
