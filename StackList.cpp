#include "StackList.h"
#include "StackConsole.h"
#include <iostream>
using namespace std;

void StackList::push(const std::string new_element) { //O(1)
	Node* node = new Node(new_element, head);
	sizeOfStack++;
	head = node;
}

void StackList::pop() { //O(1)
	sizeOfStack--;
	Node* node = head;
	head = head->next;
	delete node;
}
//as
bool StackList::isEmpty() { //O(1)
	if (head) {
		return true;
	}
	else {
		return false;
	}
}


std::string StackList::back() { // O(n)
	Node* node = head;
	while (node->next != nullptr) {
		node = node->next;
	}
	return node->element;
}

