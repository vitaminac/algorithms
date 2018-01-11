#pragma once
#include <iostream>
using std::string;

typedef struct Base {
private:
	int b;
public:
	explicit Base (const int b) : b(b) {
		std::cout << "create Base class with " << b << std::endl;
	}

	virtual ~Base () {
		std::cout << "Base class's destructor" << std::endl;
	}

	virtual string toString () {
		return "i'm Base class " + std::to_string(this->b);
	}

	virtual void print () {
		std::cout << this->toString() << std::endl;
	}

	int getB () const {
		return this->b;
	}

	inline bool operator == (const Base & b) const {
		return this->getB() == b.getB();
	}
} Base;

typedef struct derived : Base {
public:
	int d;

	explicit derived (const int b, const int d) : Base(b), d(d) {
		std::cout << "Constructor " << b << " " << d << std::endl;
	}

	virtual ~derived () {
		std::cout << "derived class's destructor" << std::endl;
	}

	virtual string toString () override {
		return Base::toString() + "and also i'm derived class " + std::to_string(this->d);
	}
} DerivedObject;
