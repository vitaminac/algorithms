#ifndef Hashable_H
#define Hashable_H

class Hashable {
public:
	virtual ~Hashable () = default;
	// map object to a int
	virtual int hash () = 0;
};

#endif
