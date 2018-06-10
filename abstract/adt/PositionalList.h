#ifndef PositionalList_H
#define PositionalList_H

template <class E>
class Position {
public:
	virtual ~Position () = default;
};

template <class E>
class PositionalList {
public:
	virtual ~PositionalList () = default;

	virtual E & operator[] (Position <E> & p) const = 0;
};
#endif
