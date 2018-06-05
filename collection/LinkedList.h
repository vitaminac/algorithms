#ifndef LinkedList_H
#define LinkedList_H
#include "collection/Collection.h"
#include "adt/Deque.h"
#include "adt/Queue.h"
#include "adt/Stack.h"
#include "node/DeNode.h"
#include "exception/CollectionIsEmptyException.h"
#include "exception/ConcurrentModificationException.h"
#include "base/Locker.h"

template <class E>
class LinkedList : public Collection <E>, public Deque <E>, public Queue <E>, public Stack <E> {

	using Node = DeNode <E>;

	struct LinkedListIterator : public Iterator <E> {
		Node * node;

		explicit LinkedListIterator (const LinkedList <E> * const list) {
			this->node = list->getFirstNode();
		};

		virtual ~LinkedListIterator () = default;

		virtual bool hasNext () const override {
			return this->node != nullptr;
		}

		virtual E & next () override {
			E & item = this->node->getItem();
			node = node->getNextNode();
			return item;
		}
	};

private:
	Node * head = nullptr;
	Node * tail = nullptr;
public:
	virtual ~LinkedList () {
		this->LinkedList <E>::clear();
	}

	Node * getFirstNode () const {
		synchronized(this) {
			return this->head;
		}
		throw ConcurrentModificationException();
	}

	Node * getLastNode () const {
		synchronized(this) {
			return this->tail;
		}
		throw ConcurrentModificationException();
	}

	virtual void add (const E & e) override {
		this->addLast(e);
	}

	virtual E & first () const override {
		synchronized(this) {
			Node * node = this->getFirstNode();
			if (node == nullptr) {
				throw CollectionIsEmptyException();
			} else {
				return node->getItem();
			}
		}
		throw ConcurrentModificationException();
	}

	virtual E & last () const override {
		synchronized(this) {
			Node * node = this->getLastNode();
			if (node == nullptr) {
				throw CollectionIsEmptyException();
			} else {
				return node->getItem();
			}
		}
		throw ConcurrentModificationException();
	}

	virtual void addFirst (const E & e) override {
		synchronized(this) {
			if (this->head == nullptr) {
				this->head = new DeNode <E>(e);
				this->tail = this->head;
			} else {
				this->head = new DeNode <E>(e, nullptr, this->head);
			}
		}
	}

	virtual void addLast (const E & e) override {
		synchronized(this) {
			if (this->tail == nullptr) {
				this->head = new DeNode <E>(e);
				this->tail = this->head;
			} else {
				this->tail = new DeNode <E>(e, this->tail, nullptr);
			}
		}
	}

	virtual E removeFirst () override {
		synchronized(this) {
			if (this->isEmpty()) {
				throw CollectionIsEmptyException();
			} else {
				auto node = this->getFirstNode();
				if (node == this->getLastNode()) {
					this->head = nullptr;
					this->tail = nullptr;
				} else {
					this->head = node->getNextNode();
				}
				auto item = node->unlinkNode();
				delete node;
				return item;
			}
		}
		throw ConcurrentModificationException();
	}

	virtual E removeLast () override {
		synchronized(this) {
			if (this->isEmpty()) {
				throw CollectionIsEmptyException();
			} else {
				auto node = this->getLastNode();
				if (node == this->getFirstNode()) {
					this->head = nullptr;
					this->tail = nullptr;
				} else {
					this->tail = node->getPrevNode();
				}
				auto item = node->unlinkNode();
				delete node;
				return item;
			}
		}
		throw ConcurrentModificationException();
	}

	virtual void clear () override {
		synchronized(this) {
			try {
				while (!this->isEmpty()) {
					this->removeLast();
				}
			} catch (CollectionIsEmptyException & e) {
				throw ConcurrentModificationException();
			}
		}
	}

	virtual Iterator <E> * iterator () const override {
		return new LinkedListIterator(this);
	}

	virtual LinkedList <E> * clone () const override {
		synchronized(this) {
			LinkedList <E> * copy = new LinkedList <E>();
			this->stream().forEach([&copy] (const E & e)
			{
				copy->add(e);
			});
			return copy;
		}
		throw ConcurrentModificationException();
	}

	virtual void push (const E & e) override {
		this->addLast(e);
	}

	virtual E pop () override {
		return this->removeLast();
	}

	virtual void enqueue (const E & e) override {
		this->addLast(e);
	}

	virtual E dequeue () override {
		return this->removeFirst();
	}

	virtual bool isEmpty () const override {
		synchronized(this) {
			return this->head == nullptr;
		}
		throw ConcurrentModificationException();
	}
};
#endif
