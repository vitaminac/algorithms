#ifndef object_h
#define object_h

#include <iostream>
#include <string>
using std::string;

typedef struct Base {
private:
	int attribute;
public:
	explicit Base (const int b) : attribute(b) {
		std::cout << "create Base class with " << b << std::endl;
	}

	virtual ~Base () {
		std::cout << "Base class's" << this->attribute << " destructor" << std::endl;
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

	inline bool operator == (const Base & b) const {
		return this->getB() == b.getB();
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
		return Base::toString() + "and also i'm Derived class " + std::to_string(this->d);
	}
} ConcreteObject;
#endif
