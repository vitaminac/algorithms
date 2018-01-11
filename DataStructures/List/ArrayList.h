#ifndef ArrayList_H
#define ArrayList_H
#include "ListIterator.h"
#include "../Exception/IndexOutOfBoundsException.h"
#include "../Exception/NoSuchElementException.h"
#include "../Exception/ConcurrentModificationException.h"

template <class E>
class ArrayList {
	template <class E>
	class ArrayListListIterator : public ListIterator <E> {
	private:
		// Index of element returned by most recent call to next or previous
		int lastRet = -1;
		List <E> & list;
		int cursor = 0;
	public:
		virtual ~ArrayListListIterator () = default;

		bool hasNext () const override {
			return cursor < list.size();
		}

		bool hasPrevious () const {
			return cursor > 0;
		}

		E & next () override {
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

		E & previous () override {
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

		void remove () override {
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

		int nextIndex () const override {
			return cursor;
		}

		int previousIndex () const override {
			return cursor - 1;
		}

		void set (const E & e) override {
			try {
				list.set(lastRet, e);
			} catch (const IndexOutOfBoundsException & e) {
				throw ConcurrentModificationException();
			}
		}

		void add (const E & e) override {
			try {
				int index = cursor;
				list.insert(index, e);
				lastRet = -1;
				cursor = index + 1;
			} catch (const IndexOutOfBoundsException & e) {
				throw ConcurrentModificationException();
			}
		}
	};
};
#endif
