#ifndef Locker_H
#define Locker_H
#include "abstract/ThreadSafe.h"

class Locker final {
public:
	//the default constructor
	Locker (const ThreadSafe * o) : o(o) {
		o->lock();
	}

	~Locker () {
		o->unlock();
	}

	//report the state of locking when used as a boolean
	operator bool () const {
		return finished;
	}

	//unlock
	void finish () {
		finished = true;
	}

private:
	const ThreadSafe * o;
	bool finished = false;
};

#define synchronized(O)  for(Locker O##_locker = O; !O##_locker; O##_locker.finish())
#endif
