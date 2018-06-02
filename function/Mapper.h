#ifndef Mapper_H
#define Mapper_H
#include <functional>
using std::function;

template <class E, class R>
using Mapper = function <R  (const E &)>;

#endif
