#include "StackMassive.h"

void StackMassive::push(std::string new_element) { // O(1)
		array[sizeOfStack] = new_element;
		sizeOfStack++;
}

void StackMassive::MultiPush(int& count, std::string *elements) {
	for (int i = 0; i < count; i++) {
		push(elements[i]);
	}

	delete[]elements;
}

void StackMassive::pop() { // O(1)
	sizeOfStack--;
}

void StackMassive::MultiPop(int &count) {
	for (int i = 0; i < count; i++) {
		pop();
	}
}

bool StackMassive::isEmpty() { // O(1)
	if (sizeOfStack != 0) {
		return true;
	}
	else {
		return false;
	}
}


std::string StackMassive::back() { // O(1)
	return array[0];
}
