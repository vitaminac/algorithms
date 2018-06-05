#ifndef Object_H
#define Object_H

#include <iostream>
#include <string>
using std::string;

typedef struct Base {
private:
	int attribute;
public:
	explicit Base (const int b) : attribute(b) {
		// std::cout << "create Base class with " << b << std::endl;
	}

	virtual ~Base () {
		// std::cout << "Base class's" << this->attribute << " destructor" << std::endl;
	}

	virtual string toString () {
		return "i'm Base class " + std::to_string(this->attribute);
	}

	inline void print () {
		std::cout << this->toString() << std::endl;
	}

	inline int getB () const {
		return this->attribute;
	}

	virtual inline bool operator == (const Base & other) const {
		return this->getB() == other.getB();
	}

	virtual inline bool operator != (const Base & other) const {
		return !this->operator==(other);
	}

	virtual inline bool operator < (const Base & other) const {
		return this->getB() < other.getB();
	}
} Object;

typedef struct Derived : Base {
public:
	int d;

	explicit Derived (const int b, const int d) : Base(b), d(d) {
		std::cout << "Constructor " << b << " " << d << std::endl;
	}

	virtual ~Derived () {
		std::cout << "Derived class's destructor" << std::endl;
	}

	virtual string toString () override {
		return Base::toString() + " and also i'm Derived class " + std::to_string(this->d);
	}

	inline int getD () const {
		return this->d;
	}

	virtual inline bool operator == (const Derived & other) const {
		return Base::operator==(other) && (this->getD() == other.getD());
	}

	virtual inline bool operator < (const Derived & other) const {

		return Base::operator<(other) || (this->getD() < other.getD());
	}
} ConcreteObject;
#endif
