#ifndef Closeable_H
#define Closeable_H

class Closeable {
public:
	virtual ~Closeable () = default;
	virtual void close () = 0;
};

#endif
