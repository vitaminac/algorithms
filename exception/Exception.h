#ifndef Exception_H
#define Exception_H
#include <exception>
#include "abstract/HumanReadable.h"
#include "base/Object.h"

class Exception : public std::exception, public Object {

};
#endif
