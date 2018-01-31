#ifndef List_Iterator
#define List_Iterator

template <class E>
class List;

// An iterator over a collection.
template <class E>
class ListIterator : public Iterator <E> {
public:
	ListIterator () = default;

	virtual ~ListIterator () = default;

	virtual bool hasPrevious () const = 0;

	virtual E & previous () = 0;

	virtual int nextIndex () const = 0;

	virtual int previousIndex () const = 0;

	virtual void set (const E & e) = 0;

	// Inserts the specified element into the list immediately before the element that would be returned by #next
	virtual void add (const E & e) = 0;
};
#endif
