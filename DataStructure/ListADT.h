#pragma once
#ifndef ListADT_H
#define ListADT_H
typedef unsigned long long position;
typedef unsigned long long lenght;
const position noPostion = -1;

template <class T>
class List // List ADT
{
private:
	lenght len = 0;
	position currentPostion = noPostion;
	void operator = (const List&) {}	// Protect assignment
	List(const List&)
	{
	} // Protect copy constructor

public:
	List()
	{
	} // Default constructor
	virtual ~List()
	{
	} // Base destructor

	// Reinitialize the list.  The client is responsible for
	// reclaiming the storage used by the list elements.
	virtual void clear() = 0;

	// Insert an element at the front of the right partition.
	// Return true if the insert was successful, false otherwise.
	virtual List& insert(const T& e) final;
	virtual List& insertBefore(const T&) = 0;
	virtual List& insertAfter(const T&) = 0;
	virtual List& insert(const T& e, position pos);

	// Append an element at the end of the right partition.
	// Return true if the append was successful, false otherwise.
	virtual List& append(const T& e);

	// Remove and return the first element of right partition.
	virtual T remove() = 0;

	// Set fence so that left partition has "pos" elements.
	virtual T& movetoPos(position pos) = 0;

	// Move fence one step left; no change if at beginning.
	virtual T& next() = 0;
	virtual T& prev() = 0;

	// Place fence at list start, making left partition empty.
	virtual T& first() = 0;
	// Place fence at list end, making right partition empty.
	virtual T& last() = 0;

	// Return length of left or right partition, respectively.
	virtual lenght leftLength() const = 0;
	virtual lenght rightLength() const = 0;

	// Return the first element of the right partition.
	virtual const T& getValue() const = 0;
};

#endif
