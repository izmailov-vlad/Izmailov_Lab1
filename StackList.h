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
		head = NULL;
	}
	

	StackList(const StackList& object) : StackList() {
		if (object.head != nullptr) {

			Node* tmp1 = object.head;
			Node* tmp2 = head;
			while (tmp1->next != nullptr) {
				tmp1 = tmp1->next;
			}

			while (tmp1 != object.head) {
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

		if (head != nullptr) {
			while(sizeOfStack) {
				Pop();
			}
		}

		if (object.head != nullptr) {
			
			Node* tmp1 = object.head;
			Node* tmp2 = head;
			while (tmp1->next != nullptr) {
				tmp1 = tmp1->next;
			}

			while (tmp1 != object.head) {
				this->Push(tmp1->element);
				tmp1 = tmp1->prev;
			}


			this->Push(tmp1->element);

		}

		return *this;
	}

	Node* getHead() const {
		return head;
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
		return type;
	}
	


	void setHead(Node* head) {
		this->head = head;
	}

	int size() const {
		return sizeOfStack;
	}

	~StackList() {
		while (size())
			Pop();
	}
private:
	std::string type = "StackList";
	int sizeOfStack = 0;
	Node* head;
};