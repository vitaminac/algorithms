#ifndef node_h
#define node_h

template <class E>
class Node {
private:
	E item;
	Node * next;
public:
	explicit Node (E item, Node <E> * next) : item(item), next(next) {
	}

	explicit Node (E item) : item(item) {
	}

	inline static void linkNode (Node <E> * newNode, Node <E> * nextNode) {
		newNode->next = nextNode;
	}

	inline static E & getItem (Node <E> * const node) {
		return node->item;
	}

	inline static void setItem (Node <E> * const node, const E & item) {
		node->item = item;
	}

	inline static Node <E> * nextNode (Node <E> * node) {
		return node->next;
	}

	inline static Node <E> * setNextNode (Node <E> * node, Node <E> * nextNode) {
		return node->next = nextNode;
	}
};
#endif
