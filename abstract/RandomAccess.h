#ifndef RandomAccess_H
#define RandomAccess_H

/*
 * Indicate that it support fast random access in constant time
 */
template <class E>
class RandomAccess {
public:
	virtual ~RandomAccess () = default;

	virtual E & operator[] (int index) const = 0;
};

#endif
