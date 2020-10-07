#include "StackList.h"
#include "ContainerException.h"
#include <iostream>
#include <sstream>

void StackList::Push(const std::string new_element) { //O(1)
		Node* node = new Node(new_element, _head);
		_sizeOfStack++;
		_head = node;
}

void StackList::MultiPush(const int count, std::string* elements) {
	for (int i = 0; i < count; i++) {
		Push(elements[i]);
	}
	delete[]elements;
}

void StackList::Pop() {
	if (_sizeOfStack) {//O(1)
		_sizeOfStack--;
		Node* node = _head;
		_head = _head->next;
		delete node;
	}
	else {
		throw ContainerException("Стек пуст");
	}
}

std::string StackList::ToString() const
{
	std::ostringstream out;
	Node* var = _head;
	
	while (var->next != nullptr) {
		out << "[" << var->element << "] ";
		var = var->next;
	}
	out << "[" << var->element << "] \n";

	return out.str();
}


void StackList::MultiPop(const int count) {
	for (int i = 0; i < count; i++) {
		if (_sizeOfStack) {
			Pop();
		}
		else {
			throw ContainerException("Все элементы удалены");
		}
	}
}

bool StackList::Empty() const{ //O(1)
	return _head == NULL;
}


std::string StackList::Back() const{ 
	if (_sizeOfStack > 0) {
		Node* node = _head;
		while (node->next != nullptr) {
			node = node->next;
		}
		return node->element;
	}
	else {
		throw ContainerException("Последний элемент не найден");
	}
}

Container* StackList::Clone() const
{
	return new StackList(*this);
}


