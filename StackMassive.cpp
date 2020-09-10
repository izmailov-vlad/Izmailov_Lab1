#include "StackMassive.h"

void StackMassive::push(std::string new_element) { // O(1)
	array[sizeOfStack] = new_element;
	sizeOfStack++;
}


void StackMassive::pop() { // O(1)
	sizeOfStack--;
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
