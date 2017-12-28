#pragma once
#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H
#include "../../Exception/CollectionEmptyException.h"
#include "../../Exception/ConcurrentModificationException.h"

template <class E>
class DoublyLinkedList {
	typedef struct Node {
		E item;
		struct Node * prev;
		struct Node * next;

		explicit Node (E item, Node * prev, Node * next) : item(item), prev(prev), next(next) {
		}

		explicit Node () : prev(nullptr), next(nullptr) {
		}
	} Node;

private:
	int size_ = 0;
	Node head = Node();

	Node * getFirstNodeUncheck () const {
		return this->head.next;
	}

	Node * getFirstNode () const {
		Node * f = this->getFirstNodeUncheck();
		if (f == &(this->head)) {
			throw CollectionEmptyException();
		}
		return f;
	}

	Node * getLastNodeUncheck () const {
		return this->head.prev;
	}

	Node * getLastNode () const {
		Node * l = this->getLastNodeUncheck();
		if (l == &(this->head)) {
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
		Node * newNode = new Node(element, prevNode, nextNode);
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
	explicit DoublyLinkedList () {
		head.next = &head;
		head.prev = &head;
	}

	virtual ~DoublyLinkedList () {
		this->clear();
	}

	virtual int size () const {
		return this->size_;
	}

	virtual E & getFirst () const {
		return this->getFirstNode()->item;
	}

	virtual E & getLast () const {
		return this->getLastNode()->item;
	}

	virtual void addFirst (const E & e) {
		insertBefore(this->getFirstNodeUncheck(), e);
	}

	virtual void addLast (const E & e) {
		insertAfter(this->getLastNodeUncheck(), e);
	}

	virtual E removeFirst () {
		return this->unlinkNode(this->getFirstNode());
	}

	virtual E removeLast () {
		return this->unlinkNode(this->getLastNode());
	}

	virtual void clear () {
		Node * cursor = this->getFirstNodeUncheck();
		Node * oldNode = cursor;
		while (cursor != &(this->head)) {
			cursor = cursor->next;
			delete oldNode;
			oldNode = cursor;
			--(this->size_);
		}
		if (this->size_ != 0) {
			throw ConcurrentModificationException();
		}
	}
};
#endif
