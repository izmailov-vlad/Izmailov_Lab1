#include "StackList.h"
#include <iostream>
#include <sstream>

void StackList::push(const std::string new_element) { //O(1)
		Node* node = new Node(new_element, head);
		sizeOfStack++;
		head = node;
}

void StackList::MultiPush(int& count, std::string* elements) {
	for (int i = 0; i < count; i++) {
		push(elements[i]);
	}
	delete[]elements;
}

void StackList::pop() {
	if (sizeOfStack) {//O(1)
		sizeOfStack--;
		Node* node = head;
		head = head->next;
		delete node;
	}
	else {
		throw StackException("Стек пуст");
	}
}

std::string const StackList::ToString()
{
	std::ostringstream out;
	Node* var = head;
	out << "\n";
	while (var->next != nullptr) {
		out << "[" << var->element << "] ";
		var = var->next;
	}
	out << "[" << var->element << "] \n\n";

	return out.str();
}


void StackList::MultiPop(int& count) {
	for (int i = 0; i < count; i++) {
		if (sizeOfStack) {
			pop();
		}
		else {
			throw StackException("Все элементы удалены");
		}
	}
}

bool StackList::isEmpty(){ //O(1)
	return head != NULL;
}


std::string StackList::back() { 
	if (sizeOfStack > 0) {
		Node* node = head;
		while (node->next != nullptr) {
			node = node->next;
		}
		return node->element;
	}
	else {
		throw StackException("Последний элемент не найден");
	}
}


