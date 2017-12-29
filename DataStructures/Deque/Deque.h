#pragma once
#ifndef Deque_H
#define Deque_H
#include "../Exception/CollectionEmptyException.h"
#include "../Exception/ConcurrentModificationException.h"
#include "DequeADT.h"

template <class E>
class Deque : public DequeADT <E> {
	typedef struct Node {
		E item;
		struct Node * prev;
		struct Node * next;

		explicit Node (E item, Node * prev, Node * next) : item(item), prev(prev), next(next) {
		}
	} Node;

private:
	int size_ = 0;
	Node * const head = reinterpret_cast <Node *>(malloc(sizeof(Node)));

	Node * getFirstNodeUncheck () const {
		return this->head->next;
	}

	Node * getFirstNode () const {
		Node * f = this->getFirstNodeUncheck();
		if (f == this->head) {
			throw CollectionEmptyException();
		}
		return f;
	}

	Node * getLastNodeUncheck () const {
		return this->head->prev;
	}

	Node * getLastNode () const {
		Node * l = this->getLastNodeUncheck();
		if (l == this->head) {
			throw CollectionEmptyException();
		}
		return l;
	}

	E unlinkNode (Node * node) {
		Node * prevNode = node->prev;
		Node * nextNode = node->next;
		E element = node->item;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		delete node;
		--(this->size_);
		return element;
	}

	void linkNode (Node * prevNode, const E & element, Node * nextNode) {
		auto newNode = new Node(element, prevNode, nextNode);
		prevNode->next = newNode;
		nextNode->prev = newNode;
		++(this->size_);
	}

	void insertBefore (Node * node, const E & element) {
		this->linkNode(node->prev, element, node);
	}

	void insertAfter (Node * node, const E & element) {
		this->linkNode(node, element, node->next);
	}

public:
	explicit Deque () {
		this->head->next = this->head;
		this->head->prev = this->head;
	}

	virtual ~Deque () {
		Deque <E>::clear();
		free(const_cast <Node *>(this->head));
	}

	virtual int size () const override {
		return this->size_;
	}

	virtual E & getFirst () const override {
		return this->getFirstNode()->item;
	}

	virtual E & getLast () const override {
		return this->getLastNode()->item;
	}

	virtual void addFirst (const E & e) override {
		insertBefore(this->getFirstNodeUncheck(), e);
	}

	virtual void addLast (const E & e) override {
		insertAfter(this->getLastNodeUncheck(), e);
	}

	virtual E removeFirst () override {
		return this->unlinkNode(this->getFirstNode());
	}

	virtual E removeLast () override {
		return this->unlinkNode(this->getLastNode());
	}

	virtual void clear () override {
		try {
			while (this->size_ > 0) {
				this->removeLast();
			}
		} catch (CollectionEmptyException & e) {
			throw ConcurrentModificationException();
		}
	}
};
#endif
