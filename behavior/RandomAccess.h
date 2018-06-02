#ifndef RandomAccess_H
#define RandomAccess_H

/*
 * Indicate that it support fast random access in constant time
 */
template <class E>
class RandomAccess {
public:
	virtual ~RandomAccess () = default;

	// Returns the element of the container having index;
	virtual E get (int index) = 0;

	// Replaces the element at index i with e, and returns the old element that was replaced
	virtual E set (int index, const E & e) = 0;
};

#endif
