#ifndef ThreadSafeCollection_H
#define ThreadSafeCollection_H
#include "abstract/ThreadSafe.h"

template <class C>
class ThreadSafeCollection final : ThreadSafe {
private:
	C * collection;
public:
	explicit ThreadSafeCollection (): ThreadSafeCollection(new C()) {
	}

	explicit ThreadSafeCollection (C * collection): collection(collection) {
	}

	~ThreadSafeCollection () {
		delete this->collection;
	}


};
#endif
