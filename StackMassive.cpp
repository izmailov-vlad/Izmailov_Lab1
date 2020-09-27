#include "StackMassive.h"
#include "ContainerException.h"
#include <iostream>

void StackMassive::push(std::string new_element) { // O(1)
	if (sizeOfStack < stackMemory) {
		array[sizeOfStack] = new_element;
		sizeOfStack++;
	}
	else {
		throw ContainerException("Выход за пределы массива");
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
		throw ContainerException("Невозможно добавить такое количество элементов");
	}


	
}

void StackMassive::pop() { // O(1)
	if (sizeOfStack > 0) {
		sizeOfStack--;
	}
	else {
		throw ContainerException("Стек пуст");
	}
}

void StackMassive::MultiPop(int &count) {
	for (int i = 0; i < count; i++) {
		if (sizeOfStack) {
			pop();
		}
		else {
			throw ContainerException("Все элементы удалены");
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

std::string const StackMassive::ToString()
{
	std::ostringstream out;
	std::string* array = StackMassive::array;
	out << "\n";
	
	for (int begin = 0; begin < sizeOfStack; begin++) {
		out << "[" << array[begin] << "] ";
	}
	out << "\n";

	return out.str();
}


std::string StackMassive::back() { // O(1)
	if (sizeOfStack > 0) {
		return array[0];
	}
	else {
		throw ContainerException("Последний элемент не найден");
	}
}

