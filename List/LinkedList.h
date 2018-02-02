#ifndef LinkedList_H
#define LinkedList_H
#include "Exception/CollectionEmptyException.h"
#include "Exception/ConcurrentModificationException.h"
#include "Deque/Deque.h"
#include "List.h"
#include "node/linkedNode.h"

template <class E>
class LinkedList : public Deque <E>, public List <E> {

	using Node = LinkedNode <E>;

	class LinkedListIterator : public ListIterator <E> {
	private:
		Node * lastRetNode = nullptr;
		Node * nextNode;
		int nextNodeIndex = 0;
		int lastRetIndex = -1;
		LinkedList <E> * const list;
	public:
		explicit LinkedListIterator (LinkedList <E> * const list) : list(list) {
			this->nextNode = this->list->getFirstNode();
		};

		virtual ~LinkedListIterator () = default;

		virtual bool hasNext () const override {
			return this->nextNodeIndex < list->size();
		}

		virtual bool hasPrevious () const override {
			return this->nextNodeIndex > 0;
		}

		virtual E & next () override {
			if (!this->hasNext()) {
				throw NoSuchElementException();
			}
			this->lastRetNode = this->nextNode;
			this->nextNode = Node::nextNode(this->nextNode);
			this->lastRetIndex = (this->nextNodeIndex)++;
			return Node::getItem(this->lastRetNode);
		}

		virtual E & previous () override {
			if (!this->hasPrevious())
				throw new NoSuchElementException();
			this->lastRetNode = this->nextNode = Node::prevNode(this->nextNode);
			this->lastRetIndex = --(this->nextNodeIndex);
			return Node::getItem(this->nextNode);
		}

		virtual E remove () override {
			if (this->lastRetNode == nullptr) {
				throw ConcurrentModificationException();
			}
			if (this->nextNode == this->lastRetNode) {
				this->nextNode = Node::nextNode(this->lastRetNode);
			} else if (this->lastRetIndex < this->nextNodeIndex) {
				--(this->nextNodeIndex);
			}
			auto removedNode = this->lastRetNode;
			this->lastRetNode = nullptr;
			this->lastRetIndex = -1;
			return this->list->unlinkNode(removedNode);
		}

		virtual int nextIndex () const override {
			return this->nextNodeIndex;
		}

		virtual int previousIndex () const override {
			return this->nextIndex() - 1;
		}

		virtual void set (const E & e) override {
			if (this->lastRetNode == nullptr) {
				throw NoSuchElementException();
			}
			Node::setItem(this->lastRetNode, e);
		}

		virtual void add (const E & e) override {
			if (this->lastRetNode == nullptr) {
				throw ConcurrentModificationException();
			}
			this->list->insertAfter(lastRetNode, e);
			++(this->nextNodeIndex);
			this->lastRetNode = nullptr;
			this->lastRetIndex = -1;
		}
	};

private:
	int size_ = 0;
	Node * const head = reinterpret_cast <Node *>(malloc(sizeof(Node)));

	Node * getFirstNodeUncheck () const {
		return Node::nextNode(this->head);
	}

	Node * getFirstNode () const {
		Node * f = this->getFirstNodeUncheck();
		if (f == this->head) {
			throw CollectionEmptyException();
		}
		return f;
	}

	Node * getLastNodeUncheck () const {
		return Node::prevNode(this->head);
	}

	Node * getLastNode () const {
		Node * l = this->getLastNodeUncheck();
		if (l == this->head) {
			throw CollectionEmptyException();
		}
		return l;
	}

	E unlinkNode (Node * node) {
		--(this->size_);
		return Node::unlinkNode(node);
	}

	void linkNode (Node * prevNode, const E & element, Node * nextNode) {
		Node::linkNode(prevNode, element, nextNode);
		++(this->size_);
	}

	void insertBefore (Node * node, const E & element) {
		this->linkNode(Node::prevNode(node), element, node);
	}

	void insertAfter (Node * node, const E & element) {
		this->linkNode(node, element, Node::nextNode(node));
	}

	Node * node (int index) const {
		if (this->isElementIndex(index)) {
			Node * node;
			if (index < (this->size() >> 1)) {
				node = this->getFirstNode();
				for (int i = 0; i < index; i++)
					node = Node::nextNode(node);
			} else {
				node = this->getLastNode();
				for (int i = size() - 1; i > index; i--)
					node = Node::prevNode(node);
			}
			return node;
		} else {
			throw IndexOutOfBoundsException(index);
		}
	}

public:
	explicit LinkedList () {
		Node::linkNode(this->head, this->head, this->head);
	}

	virtual void add (const E & e) override {
		this->Deque <E>::add(e);
	}

	virtual ~LinkedList () {
		this->LinkedList <E>::clear();
		free(const_cast <Node *>(this->head));
	}

	virtual int size () const override {
		return this->size_;
	}

	virtual E & getFirst () const override {
		return Node::getItem(this->getFirstNode());
	}

	virtual E & getLast () const override {
		return Node::getItem(this->getLastNode());
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

	virtual E & get (int index) const override {
		return Node::getItem(this->node(index));
	}

	virtual E set (int index, const E & e) override {
		Node * node = this->node(index);
		E oldVal = Node::getItem(node);
		Node::setItem(node, e);
		return oldVal;
	}

	virtual void insert (int index, const E & e) override {
		this->insertBefore(this->node(index), e);
	}

	virtual E remove (int index) override {
		return this->unlinkNode(this->node(index));
	}

	virtual void clear (Consumer <E> consume = doNothing <E>) override {
		try {
			while (this->size() > 0) {
				consume(this->removeLast());
			}
		} catch (CollectionEmptyException & e) {
			throw ConcurrentModificationException();
		}
	}

	virtual ListIterator <E> * iterator () override {
		return new LinkedListIterator(this);
	}

	virtual LinkedList <E> * subList (int fromIndex, int toIndex) const override {
		auto list = new LinkedList <E>();
		for (int i = fromIndex; i < toIndex; i++) {
			list->add(this->get(i));
		}
		return list;
	}
};
#endif
