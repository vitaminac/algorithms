#ifndef Node_H
#define Node_H

template <class E>
struct Node {
	E item;
	Node * next;

	explicit Node (const E & item, Node <E> * const nextNode) : item(item), next(nextNode) {
	}

	explicit Node (const E & item) : Node(item, nullptr) {
	}

	inline void link (Node <E> * const nextNode) {
		nextNode->next = this->next;
		this->next = nextNode;
	}

	inline E & getItem () {
		return this->item;
	}

	inline void setItem (const E & item) {
		this->item = item;
	}

	inline Node <E> * getNextNode () {
		return this->next;
	}
};
#endif
