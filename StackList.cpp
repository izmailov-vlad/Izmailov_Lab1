#include "StackList.h"
#include "ContainerException.h"
#include <iostream>
#include <sstream>

void StackList::Push(const std::string new_element) { //O(1)
		Node* node = new Node(new_element, head);
		sizeOfStack++;
		head = node;
}

void StackList::MultiPush(const int count, std::string* elements) {
	for (int i = 0; i < count; i++) {
		Push(elements[i]);
	}
	delete[]elements;
}

void StackList::Pop() {
	if (sizeOfStack) {//O(1)
		sizeOfStack--;
		Node* node = head;
		head = head->next;
		delete node;
	}
	else {
		throw ContainerException("���� ����");
	}
}

std::string StackList::ToString() const
{
	std::ostringstream out;
	Node* var = head;
	
	while (var->next != nullptr) {
		out << "[" << var->element << "] ";
		var = var->next;
	}
	out << "[" << var->element << "] \n";

	return out.str();
}


void StackList::MultiPop(const int count) {
	for (int i = 0; i < count; i++) {
		if (sizeOfStack) {
			Pop();
		}
		else {
			throw ContainerException("��� �������� �������");
		}
	}
}

bool StackList::Empty() const{ //O(1)
	return head == NULL;
}


std::string StackList::Back() const{ 
	if (sizeOfStack > 0) {
		Node* node = head;
		while (node->next != nullptr) {
			node = node->next;
		}
		return node->element;
	}
	else {
		throw ContainerException("��������� ������� �� ������");
	}
}

Container* StackList::Clone() const
{
	return new StackList(*this);
}


