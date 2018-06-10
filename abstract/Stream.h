#ifndef Stream_H
#define Stream_H
#include "Iterator.h"
#include "function/Predicate.h"
#include "function/Mapper.h"
#include "function/Consumer.h"
#include "function/BinaryOperator.h"
#include "function/Collector.h"
#include "function/Creator.h"
#include "function/Comparator.h"

template <class E>
class Stream final {
private:
	Iterator <E> * it;

public:
	~Stream () {
		delete this->it;
	};

	explicit Stream (Iterator <E> * it): it(it) {
	}

	Stream <E> filter (Predicate <E> test) {
		struct filteredIterator : Iterator <E> {
			Iterator <E> & it;
			Predicate <E> test;
			E * nextElement;

			explicit filteredIterator (Iterator <E> & it, Predicate <E> test) : it(it), test(test) {
				nextElement = this->findNext();
			}

			E * findNext () {
				while (it.hasNext()) {
					auto & next = it.next();
					if (test(next)) {
						return &next;
					}
				}
				return nullptr;
			}

			virtual bool hasNext () const override {
				return nextElement != nullptr;
			}

			virtual E & next () override {
				auto & result = *nextElement;
				nextElement = this->findNext();
				return result;
			}
		};
		return Stream <E>(filteredIterator(this->it, test));
	}

	bool anyMatch (Predicate <E> test) {
		while (it->hasNext()) {
			if (test(it->next())) {
				return true;
			}
		}
		return false;
	}

	bool allMatch (Predicate <E> test) {

	}

	bool noneMatch (Predicate <E> test) {

	}

	template <class R>
	Stream <R> map (Mapper <E, R> f) {
		struct MappedIterator : Iterator <E> {
			Iterator <E> & it;
			Mapper <E, R> map;
			R * e = nullptr;

			explicit MappedIterator (Iterator <E> & it, Mapper <E, R> map) : it(it), map(map) {
			}

			virtual bool hasNext () const override {
				return this->it.hasNext();
			}

			virtual R & next () override {
				e = map(this->it.next());
				return *e;
			}
		};
		return Stream <R>(this->it, map);
	}

	Stream <E> limit (int n) {

	}

	Stream <E> skip (int n) {

	}

	E reduce (E identity, BinaryOperator <E> operate) {
		return this->template collect <E>(identity, operate);
	}

	template <class R>
	R collect (R collection, Collector <R, E> add) {
		while (it->hasNext()) {
			collection = add(collection, it->next());
		}
		return collection;
	}

	E min (Comparator <E> compare) {

	}

	E max (Comparator <E> compare) {
	}

	// Returns the count of elements in this stream
	int count () {
		int count = 0;
		while (it->hasNext()) {
			count += 1;
			it->next();
		}
		return count;
	}

	void forEach (Consumer <E> consume) {
		while (it->hasNext()) {
			consume(it->next());
		}
	}
};

#endif
