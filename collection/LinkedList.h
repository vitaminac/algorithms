#ifndef LinkedList_H
#define LinkedList_H
#include "abstract/adt/Deque.h"
#include "abstract/adt/Queue.h"
#include "abstract/adt/Stack.h"
#include "abstract/adt/PositionalList.h"
#include "base/Locker.h"
#include "collection/Collection.h"
#include "exception/CollectionIsEmptyException.h"
#include "exception/ConcurrentModificationException.h"

template <class E>
class LinkedList : public Collection <E>,
                   public PositionalList <E>,
                   public Deque <E>,
                   public Queue <E>,
                   public Stack <E> {

	struct Node : Position <E> {
		E item;
		Node * prev;
		Node * next;

		inline explicit Node (const E & item, Node * const prevNode, Node * const nextNode) : item(item) {
			this->link(prevNode, nextNode);
		}

		inline explicit Node (const E & item) : Node(item, nullptr, nullptr) {
		}

		inline E unlinkNode () {
			auto prevNode = this->prev;
			auto nextNode = this->next;
			if (prevNode != nullptr) {
				prevNode->next = nextNode;
			}
			if (nextNode != nullptr) {
				nextNode->prev = prevNode;
			}
			return this->item;
		}

		inline void link (Node * const prevNode, Node * const nextNode) {
			this->prev = prevNode;
			this->next = nextNode;
			if (prevNode != nullptr) {
				prevNode->next = this;
			}
			if (nextNode != nullptr) {
				nextNode->prev = this;
			}
		}
	};

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
			E & item = this->node->item;
			node = node->next;
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
				return node->item;
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
				return node->item;
			}
		}
		throw ConcurrentModificationException();
	}

	virtual void addFirst (const E & e) override {
		synchronized(this) {
			if (this->head == nullptr) {
				this->head = new Node(e);
				this->tail = this->head;
			} else {
				this->head = new Node(e, nullptr, this->head);
			}
		}
	}

	virtual void addLast (const E & e) override {
		synchronized(this) {
			if (this->tail == nullptr) {
				this->head = new Node(e);
				this->tail = this->head;
			} else {
				this->tail = new Node(e, this->tail, nullptr);
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
					this->head = node->next;
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
					this->tail = node->prev;
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

	virtual E & operator[] (Position <E> & p) const override {
		return static_cast <Node &>(p).item;
	}
};
#endif
