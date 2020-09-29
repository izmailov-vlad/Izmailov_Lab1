#pragma once
#include "Container.h"
#include <string>

struct Node {
	std::string element;
	Node* next;

	Node(std::string new_el, Node* nextNode) {
		element = new_el;
		next = nextNode;
	}
};

class StackList : public Container {
public:

	StackList() {
		head = NULL;
	}

	Node* getHead() const {
		return head;
	}

	void push(const std::string &new_element) override;

	void MultiPush(const int& count, std::string *elements) override;

	void MultiPop(const int& count) override;

	void pop() override;

	std::string ToString() const override;

	bool isEmpty() const override;

	std::string back() const override;

	


	void setHead(Node* head) {
		this->head = head;
	}

	int size() const {
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