#ifndef HumanReadable_H
#define HumanReadable_H
#include <string>
#include <iostream>
using std::string;

class HumanReadable {
	virtual string toString () = 0;

	inline void display () {
		std::cout << this->toString() << std::endl;
	}
};
#endif
