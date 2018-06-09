#ifndef PositionalList_H
#define PositionalList_H
#include "Position.h"

template <class E>
class PositionalList {
public:
	virtual ~PositionalList () = default;
	virtual E & operator () () const = 0;

	virtual E & operator[] (Position <E> & p) const = 0;
};
#endif
