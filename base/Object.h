#ifndef Object_H
#define Object_H
#include <iostream>
#include <string>
#include <sstream>
#include <mutex>
#include "behavior/Cloneable.h"
#include "behavior/Hashable.h"
#include "behavior/Serializable.h"
#include "behavior/HumanReadable.h"
#include "behavior/ThreadSafe.h"

class Object : public HumanReadable, public Cloneable, public Hashable, public Serializable, public ThreadSafe {
public:
	explicit Object ();
	virtual ~Object ();
	virtual string toString () const override;
	virtual inline bool operator == (const Object & other) const;
	virtual inline bool operator != (const Object & other) const;
	virtual inline bool operator < (const Object & other) const;
	virtual Object * clone () const override;
	virtual unsigned long long hash () const override;
};
#endif
