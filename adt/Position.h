#ifndef Position_H
#define Position_H

template <class E>
class Position {
public:
	virtual ~Position () = default;
	virtual E & operator () () const = 0;
};
#endif
