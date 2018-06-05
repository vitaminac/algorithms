#ifndef ArrayList_H
#define ArrayList_H
#include "Collection.h"
#include "adt/Vector.h"
#include "exception/IndexOutOfBoundsException.h"

template <class E>
class ArrayList : public Collection <E>, public Vector <E> {
	struct ArrayListIterator : public Iterator <E> {
		int index = 0;
		const ArrayList <E> & list;

		explicit ArrayListIterator (const ArrayList <E> & list): list(list) {
		};

		virtual ~ArrayListIterator () = default;

		virtual bool hasNext () const override {
			return list.size() > index;
		}

		virtual E & next () override {
			return list[index++];
		}
	};

private:
	const int InitialCapacity;
	E * elements;
	int capacity;
	int dimension = 0;
	int start = 0;

	void resize (int newCapacity) {
		E * oldArray = this->elements;
		E * newArray = new E[newCapacity];
		const int size = this->size();
		for (int i = 0; i < size; i++) {
			newArray[i] = oldArray[this->calculatePosition(i)];
		}
		start = 0;
		this->elements = newArray;
		capacity = newCapacity;
		delete[] oldArray;
	}

	int calculatePosition (int index) const {
		return (index + start + capacity) % capacity;
	}

public:
	explicit ArrayList () : ArrayList(DEFAULT_CAPACITY) {
	}

	explicit ArrayList (int capacity) : InitialCapacity(capacity), capacity(capacity) {
		this->elements = new E[capacity];
	}

	virtual ~ArrayList () {
		this->ArrayList <E>::clear();
		delete[] elements;
	}

	virtual Iterator <E> * iterator () const override {
		return new ArrayListIterator(*this);
	}

	virtual bool isEmpty () const override {
		return this->isZeroVector();
	}

	inline virtual int size () const override {
		return this->dimension;
	}

	virtual void add (const E & e) override {
		this->insert(this->size(), e);
	}

	virtual void clear () override {
		start = 0;
		dimension = 0;
	}

	virtual ArrayList <E> * clone () const override {
		const int size = this->size();
		auto copy = new ArrayList(capacity);
		for (int i = 0; i < size; i++) {
			copy->insert(0, this->operator[](i));
		}
		return copy;
	}

	virtual E & operator[] (int index) const override {
		const int size = this->size();
		if (index >= -size && index < size) {
			return elements[this->calculatePosition(index)];
		} else {
			throw IndexOutOfBoundsException(index);
		}
	}

	virtual void insert (int index, const E & e) override {
		const int size = this->size();
		if (size == capacity) {
			this->resize(capacity * 2);
		}
		if (index == 0) {
			start = this->calculatePosition(-1);
			elements[start] = e;
		} else if (index == size) {
			elements[this->calculatePosition(size)] = e;
		} else {
			// shift by one position
			for (int i = index; i < size; i++) {
				elements[this->calculatePosition(i + 1)] = elements[this->calculatePosition(i)];
			}
			elements[this->calculatePosition(index)] = e;
		}
		++this->dimension;
	}

	virtual E remove (int index) override {
		const int size = this->size();
		if (size > InitialCapacity && size < capacity / 4) {
			this->resize(capacity / 2);
		}
		if (index <= 0) {
			index = -index - 1;
		}
		if (index < size) {
			E e = this->operator[](index);
			if (index < size / 2) {
				for (int i = index - 1; i >= 0; i--) {
					this->operator[](i + 1) = this->operator[](i);
				}
				start = this->calculatePosition(1);
			} else {
				for (int i = index + 1; i < size; i++) {
					this->operator[](i - 1) = this->operator[](i);
				}
			}
			return e;
		} else {
			throw IndexOutOfBoundsException(index);
		}
	}

	static const int DEFAULT_CAPACITY = 8;
};
#endif
