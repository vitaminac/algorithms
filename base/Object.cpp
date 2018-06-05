#include "Object.h"
#include <cstdint>

inline Object::Object () {
	std::cout << "Creating " << this->Object::toString() << std::endl;
}

Object::~Object () {
	std::cout << "Disposing " << this->Object::toString() << std::endl;
}

string Object::toString () const {
	std::ostringstream oss;
	oss << std::hex << this->hash();
	return "Object@" + oss.str();
}

bool Object::operator== (const Object & other) const {
	return this == &other;
}

bool Object::operator!= (const Object & other) const {
	return !this->operator==(other);
}

bool Object::operator< (const Object & other) const {
	return this < &other;
}

Object * Object::clone () const {
	return new Object();
}

unsigned long long Object::hash () const {
	return reinterpret_cast <uintptr_t>(this);
}
