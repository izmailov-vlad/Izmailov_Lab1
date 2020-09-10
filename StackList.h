#pragma once
#include "Stack.h"
#include <string>

struct Node {
	std::string element;
	Node* next;

	Node(std::string new_el, Node* nextNode) {
		element = new_el;
		next = nextNode;
	}
};
class StackList : public Stack {
public:

	StackList() {
		head = NULL;
	}

	Node* getHead() {
		return head;
	}

	virtual void push(const std::string new_element);

	virtual void pop();

	virtual bool isEmpty();

	virtual std::string back();

	


	void setHead(Node* head) {
		this->head = head;
	}

	int size() {
		return sizeOfStack;
	}

	~StackList() {
		while (size())
			pop();
	}
private:
	int sizeOfStack = 0;
	Node* head;
};