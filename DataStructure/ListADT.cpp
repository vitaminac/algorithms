#include "listADT.h"

template <class T>
List<T>& List<T>::append(const T& e)
{
	insert(e, this->len);
	return *this;
}

template <class T>
List<T>& List<T>::insert(const T& e, position pos)
{
	movetoPos(pos);
	insert(e);
	return *this;
}

template <class T>
List<T>& List<T>::insert(const T& e) { return insertAfter(e); }
