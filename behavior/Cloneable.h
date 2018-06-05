#ifndef Cloneable_H
#define Cloneable_H

class Cloneable {
public:
	virtual ~Cloneable () = default;

	// Type Erasure to return type of signature
	// return a pointer to a deep copy of this instance of the same type
	virtual Cloneable * clone () const = 0;
};

#endif
