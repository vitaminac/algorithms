#ifndef Creator_H
#define Creator_H
#include <functional>
using std::function;

template <class E>
using Creator = function <E  ()>;

#endif
