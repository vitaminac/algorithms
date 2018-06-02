#ifndef BiFunction_H
#define BiFunction_H
#include <functional>
using std::function;

template <typename U, typename V, typename R>
using BiFunction = function <R  (const U & left, const V & right)>;

#endif
