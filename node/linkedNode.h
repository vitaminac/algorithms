#ifndef linkedNode_h
#define linkedNode_h
#include "node.h"

template <class E>
class LinkedNode : public Node <E> {
private:
	LinkedNode * prev;
public:
	explicit LinkedNode (E item, LinkedNode <E> * prev, LinkedNode <E> * next) : Node <E>(item, next), prev(next) {
	}

	explicit LinkedNode (E item) : Node <E>(item) {
	}

	using Node <E>::setNextNode;

	inline static E unlinkNode (LinkedNode <E> * node) {
		LinkedNode * prvNode = prevNode(node);
		LinkedNode * nxtNode = nextNode(node);
		E element = Node <E>::getItem(node);
		setNextNode(prvNode, nxtNode);
		setPrevNode(nxtNode, prvNode);
		delete node;
		return element;
	}

	inline static void linkNode (LinkedNode <E> * prevNode, const E & element, LinkedNode <E> * nextNode) {
		auto newNode = new LinkedNode <E>(element);
		linkNode(prevNode, newNode, nextNode);
	}

	inline static void linkNode (LinkedNode <E> * prevNode, LinkedNode <E> * newNode, LinkedNode <E> * nextNode) {
		setNextNode(prevNode, newNode);
		setPrevNode(newNode, prevNode);
		Node <E>::linkNode(newNode, nextNode);
		setPrevNode(nextNode, newNode);
	}

	inline static LinkedNode <E> * nextNode (LinkedNode <E> * node) {
		return static_cast <LinkedNode <E> *>(Node <E>::nextNode(node));
	}

	inline static LinkedNode <E> * prevNode (LinkedNode <E> * node) {
		return node->prev;
	}

	inline static LinkedNode <E> * setPrevNode (LinkedNode <E> * node, LinkedNode <E> * prevNode) {
		return node->prev = prevNode;
	}
};
#endif
