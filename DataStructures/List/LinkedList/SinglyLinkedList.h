#pragma once
#ifndef SinglyLinkedList_H
#define SinglyLinkedList_H
#include "../../Collection/Collection.h"

template <class E>
class SinglyLinkedList : Collection <E> {
	typedef struct Node {
		E item;
		struct Node * next;

		explicit Node (E item, Node * next) : item(item), next(next) {
		}
	} Node;

private:
	int size_ = 0;
	Node * head = nullptr;
	Node * tail = nullptr;
public:
	~SinglyLinkedList () {

	}

	int size () const override {
		return this->size_;
	}


};
#endif
