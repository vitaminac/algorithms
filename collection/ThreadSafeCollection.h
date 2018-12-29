#ifndef ThreadSafeWrapper_H
#define ThreadSafeWrapper_H
#include "abstract/ThreadSafe.h"

template <class C>
class ThreadSafeWrapper final : ThreadSafe {
private:
	C * collection;
public:
	explicit ThreadSafeWrapper (): ThreadSafeWrapper(new C()) {
	}

	explicit ThreadSafeWrapper (C * collection): collection(collection) {
	}

	virtual ~ThreadSafeWrapper () {
		delete this->collection;
	}


};
#endif
