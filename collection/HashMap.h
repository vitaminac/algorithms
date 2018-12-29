#ifndef HashMap_H
#define HashMap_H
#include "abstract/Iterable.h"
#include "base/Object.h"

// An iterator over a collection.
template <class Key, class Value>
class HashMap : public Object, public Iterable <Key> {
private:
	unsigned int(*hash)(Key);
public:
	HashMap(unsigned int(*hash)(Key)) :hash(hash) {}

	HashMap() :(Key::hash) {}

	virtual ~HashMap() = default;
};
#endif
