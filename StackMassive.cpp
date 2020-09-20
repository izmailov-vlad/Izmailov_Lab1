#include "StackMassive.h"
#include "StackException.h"

void StackMassive::push(std::string new_element) { // O(1)
	if (sizeOfStack < stackMemory) {
		array[sizeOfStack] = new_element;
		sizeOfStack++;
	}
	else {
		throw StackException("Выход за пределы массива");
	}
}

void StackMassive::MultiPush(int& count, std::string *elements) {

	if (count + sizeOfStack <= stackMemory) {

		for (int i = 0; i < count; i++) {
			push(elements[i]);
		}

		delete[]elements;
	}
	else {
		throw StackException("Невозможно добавить такое количество элементов");
	}


	
}

void StackMassive::pop() { // O(1)
	if (sizeOfStack > 0) {
		sizeOfStack--;
	}
	else {
		throw StackException("Стек пуст");
	}
}

void StackMassive::MultiPop(int &count) {
	for (int i = 0; i < count; i++) {
		if (sizeOfStack) {
			pop();
		}
		else {
			throw StackException("Все элементы удалены");
		}
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
	if (sizeOfStack > 0) {
		return array[0];
	}
	else {
		throw StackException("Последний элемент не найден");
	}
}
