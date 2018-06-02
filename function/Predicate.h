#ifndef Predicate_H
#define Predicate_H
#include <functional>
using std::function;

template <typename E>
using Predicate = function <bool  (const E &)>;

#endif
