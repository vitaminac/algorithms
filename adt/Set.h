#ifndef Set_H
#define Set_H

/*
 * An unordered collection of elements,
 * without duplicates, that typically supports efficient membership tests.
 */
template <class E>
class Set {
public:
	virtual ~Set () = default;

	// Return the cardinality, the number of members of this set
	virtual int size () const = 0;

	// Test if this is a empty set
	virtual bool isEmpty () const = 0;

	// Ensures that this set contains the specified element
	virtual void add (const E & e) = 0;

	// Add all elements of that set to this set
	virtual void add (const Set <E> & that) = 0;

	// Removes a specified element from this set
	virtual bool remove (const E & e) = 0;

	// Test if e is an element of this set
	virtual bool contains (const E & e) const = 0;

	// Test if every member of this set is also a member of that set 
	virtual bool belongsTo (const Set <E> & that) const = 0;

	// result a set that contains all things of this set and that set
	virtual Set <E> * unions (const Set <E> & that) const = 0;
};
#endif
