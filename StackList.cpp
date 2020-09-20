#include "StackList.h"
#include "StackConsole.h"
#include "StackException.h"
#include <iostream>
using namespace std;

void StackList::push(const std::string new_element) noexcept { //O(1)
		Node* node = new Node(new_element, head);
		sizeOfStack++;
		head = node;
}

void StackList::MultiPush(int& count, std::string* elements) noexcept {
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

bool StackList::isEmpty() { //O(1)
	if (head) {
		return true;
	}
	else {
		return false;
	}
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

