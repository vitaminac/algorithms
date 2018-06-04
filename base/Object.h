#ifndef Object_H
#define Object_H
#include <iostream>
#include <string>
#include <sstream>
#include <mutex>
#include "behavior/Cloneable.h"
#include "behavior/Hashable.h"
#include "behavior/Serializable.h"
using std::string;

class Object : public Cloneable, public Hashable, public Serializable {
public:
	explicit Object ();
	virtual ~Object ();
	virtual string toString ();
	virtual inline bool operator == (const Object & other) const;
	virtual inline bool operator != (const Object & other) const;
	virtual inline bool operator < (const Object & other) const;
	virtual Object * clone () override;
	virtual unsigned long long hash () override;

	inline void print () {
		std::cout << this->toString() << std::endl;
	}

	inline void lock () {
		this->mtx.lock();
	}

	inline void unlock () {
		this->mtx.unlock();
	}

private:
	std::recursive_mutex mtx;
};
#endif
