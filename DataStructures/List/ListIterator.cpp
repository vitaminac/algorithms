#include "ListIterator.h"
#include "../Exception/IndexOutOfBoundsException.h"
#include "../Exception/NoSuchElementException.h"
#include "../Exception/ConcurrentModificationException.h"

template <class E>
bool ListIterator <E>::hasNext () const {
	return cursor < list.size();
}

template <class E>
bool ListIterator <E>::hasPrevious () const {
	return cursor > 0;
}

template <class E>
E & ListIterator <E>::next () {
	try {
		int index = this->cursor;
		E next = this->list.get(index);
		lastRet = index;
		cursor = index++;
		return next;
	} catch (const IndexOutOfBoundsException & e) {
		throw NoSuchElementException();
	}
}

template <class E>
E & ListIterator <E>::previous () {
	try {
		int index = cursor - 1;
		E previous = list.get(index);
		lastRet = index;
		cursor = index;
		return previous;
	} catch (const IndexOutOfBoundsException & e) {
		throw NoSuchElementException();
	}
}

template <class E>
void ListIterator <E>::remove () {
	try {
		list.remove(lastRet);
		if (lastRet < cursor) {
			cursor--;
			lastRet = -1;
		}
	} catch (const IndexOutOfBoundsException & e) {
		throw ConcurrentModificationException();
	}

}

template <class E>
int ListIterator <E>::nextIndex () {
	return cursor;
}

template <class E>
int ListIterator <E>::previousIndex () {
	return cursor - 1;
}

template <class E>
void ListIterator <E>::set (const E & e) {
	try {
		list.set(lastRet, e);
	} catch (const IndexOutOfBoundsException & e) {
		throw ConcurrentModificationException();
	}
}

template <class E>
void ListIterator <E>::add (const E & e) {
	try {
		int index = cursor;
		list.insert(index, e);
		lastRet = -1;
		cursor = index + 1;
	} catch (const IndexOutOfBoundsException & e) {
		throw ConcurrentModificationException();
	}
}
