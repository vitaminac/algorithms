#ifndef Object_H
#define Object_H
#include <iostream>
#include <string>
#include <sstream>
#include <mutex>
#include "abstract/Cloneable.h"
#include "abstract/Hashable.h"
#include "abstract/Serializable.h"
#include "abstract/HumanReadable.h"
#include "abstract/ThreadSafe.h"

class Object : public HumanReadable, public Cloneable, public Hashable, public Serializable {
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
