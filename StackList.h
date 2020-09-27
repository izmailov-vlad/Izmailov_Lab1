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

	Node* getHead() const {
		return head;
	}

	void push(const std::string new_element) override;

	void MultiPush(int& count, std::string *elements) override;

	void MultiPop(int& count) override;

	void pop() override;

	std::string const ToString() override;

	bool isEmpty() override;

	std::string back() override;

	


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