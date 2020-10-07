#pragma once
#include "Container.h"
#include <string>

struct Node {
	std::string element;
	Node* next;
	Node* prev;
	Node(std::string new_el, Node* nextNode) {
		element = new_el;
		next = nextNode;
		if (nextNode) {
			nextNode->prev = this;
		}
	}
};

class StackList : public Container {
public:

	StackList() {
		_head = NULL;
	}
	

	StackList(const StackList& object) : StackList() {
		if (object._head != nullptr) {

			Node* tmp1 = object._head;
			Node* tmp2 = _head;
			while (tmp1->next != nullptr) {
				tmp1 = tmp1->next;
			}

			while (tmp1 != object._head) {
				this->Push(tmp1->element);
				tmp1 = tmp1->prev;
			}


			this->Push(tmp1->element);

		}
	}

	StackList& operator = (const StackList& object) {
		
		if (&object == this) {
			return *this;
		}

		if (_head != nullptr) {
			while(_sizeOfStack) {
				Pop();
			}
		}

		if (object._head != nullptr) {
			
			Node* tmp1 = object._head;
			Node* tmp2 = _head;
			while (tmp1->next != nullptr) {
				tmp1 = tmp1->next;
			}

			while (tmp1 != object._head) {
				this->Push(tmp1->element);
				tmp1 = tmp1->prev;
			}


			this->Push(tmp1->element);

		}

		return *this;
	}

	Node* GetHead() const {
		return _head;
	}

	void Push(const std::string new_element) override;

	void MultiPush(const int count, std::string *elements) override;

	void MultiPop(const int count) override;

	void Pop() override;

	std::string ToString() const override;

	bool Empty() const override;

	std::string Back() const override;

	Container* Clone() const override;

	std::string GetType() const override {
		return _type;
	}
	


	void SetHead(Node* head) {
		this->_head = head;
	}

	int Size() const {
		return _sizeOfStack;
	}

	~StackList() {
		while (Size())
			Pop();
	}
private:
	std::string _type = "StackList";
	int _sizeOfStack = 0;
	Node* _head;
};