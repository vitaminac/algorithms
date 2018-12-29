#ifndef Subject_H
#define Subject_H
#include "Observer.h"
#include "abstract/adt/Set.h"
#include "collection/HashSet.h"

template <class E>
class Subject {
private:
	auto observers = HashSet <Observer <E> &>();
public:
	void subscribe (Observer <E> & observer) {
		this->observers.add(observer);
	}

	void unsubscribe (Observer <E> & observer) {
		this->observers.remove(observer);
	}

	void publish (E event) const {
		this->observers.stream().forEach([&event] (const Observer <E> & observer)
		{
			observer.push(event);
		});
	}
};
#endif
