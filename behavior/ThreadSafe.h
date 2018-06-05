#ifndef ThreadSafe_H
#define ThreadSafe_H
#include <mutex>

class ThreadSafe {
public:
	virtual ~ThreadSafe () {
		delete mtx;
	}

	inline void lock () const {
		this->mtx->lock();
	}

	inline void unlock () const {
		this->mtx->unlock();
	}

private:
	std::recursive_mutex * mtx = new std::recursive_mutex();
};

#endif
