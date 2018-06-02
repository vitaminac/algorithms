#ifndef Collector_H
#define Collector_H
#include <functional>
using std::function;

template <class U, class E>
using Collector = function <U  (const U & collection, const E & e)>;

#endif
