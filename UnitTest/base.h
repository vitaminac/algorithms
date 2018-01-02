#pragma once
#include <iostream>
using std::string;

typedef struct base {
public:
	int b;

	explicit base (const int b) : b(b) {
		std::cout << "create base class with " << b << std::endl;
	}

	virtual ~base () {
		std::cout << "base class's destructor" << std::endl;
	}

	virtual string toString () {
		return "i'm base class " + std::to_string(this->b);
	}

	virtual void print () {
		std::cout << this->toString() << std::endl;
	}
} Object;

typedef struct derived : Object {
public:
	int d;

	explicit derived (const int b, const int d) : base(b), d(d) {
		std::cout << "Constructor " << b << " " << d << std::endl;
	}

	virtual ~derived () {
		std::cout << "derived class's destructor" << std::endl;
	}

	virtual string toString () override {
		return Object::toString() + "and also i'm derived class " + std::to_string(this->d);
	}
} DerivedObject;
