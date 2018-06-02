#ifndef DeNode_H
#define DeNode_H
#include "Node.h"

template <class E>
struct DeNode : public Node <E> {
	DeNode * prev;

	explicit DeNode (const E & item, DeNode <E> * const prevNode, DeNode <E> * const nextNode) : DeNode <E>(item) {
		this->link(prevNode, nextNode);
	}

	explicit DeNode (const E & item) : Node <E>(item), prev(nullptr) {
	}

	inline E unlinkNode () {
		auto prevNode = this->prev;
		auto nextNode = static_cast <DeNode <E>*>(this->next);
		if (prevNode != nullptr) {
			prevNode->next = nextNode;
		}
		if (nextNode != nullptr) {
			nextNode->prev = prevNode;
		}
		return this->getItem();
	}

	inline void link (DeNode <E> * const prevNode, DeNode <E> * const nextNode) {
		this->prev = prevNode;
		this->next = nextNode;
		if (prevNode != nullptr) {
			prevNode->next = this;
		}
		if (nextNode != nullptr) {
			nextNode->prev = this;
		}
	}

	inline DeNode <E> * getNextNode () {
		return static_cast <DeNode *>(this->next);
	}

	inline DeNode <E> * getPrevNode () {
		return this->prev;
	}

	inline static DeNode <E> * create (DeNode <E> * const prevNode, const E & item, DeNode <E> * const nextNode) {
		auto node = new DeNode(item);
		node->link(prevNode, nextNode);
		return node;
	}
};
#endif
