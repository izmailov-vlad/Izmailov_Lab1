#include "StackMassive.h"
#include "ContainerException.h"
#include <iostream>

void StackMassive::Push(const std::string new_element) { // O(1)
	if (_sizeOfStack < _stackMemory) {
		_array[_sizeOfStack] = new_element;
		_sizeOfStack++;
	}
	else {
		throw ContainerException("Выход за пределы массива");
	}
}


void StackMassive::MultiPush(const int count, std::string *elements) {

	if (count + _sizeOfStack <= _stackMemory) {

		for (int i = 0; i < count; i++) {
			Push(elements[i]);
		}

		delete[]elements;
	}
	else {
		throw ContainerException("Невозможно добавить такое количество элементов");
	}


	
}

void StackMassive::Pop() { // O(1)
	if (_sizeOfStack > 0) {
		_sizeOfStack--;
	}
	else {
		throw ContainerException("Стек пуст");
	}
}

void StackMassive::MultiPop(const int count) {
	for (int i = 0; i < count; i++) {
		if (_sizeOfStack) {
			Pop();
		}
		else {
			throw ContainerException("Все элементы удалены");
		}
	}
}

bool StackMassive::Empty() const { // O(1)
	return _sizeOfStack == 0;
}

std::string StackMassive::ToString() const
{
	std::ostringstream out;
	std::string* array = StackMassive::_array;
	
	
	for (int begin = 0; begin < _sizeOfStack; begin++) {
		out << "[" << array[begin] << "] ";
	}

	return out.str();
}


std::string StackMassive::Back() const { // O(1)
	if (_sizeOfStack > 0) {
		return _array[0];
	}
	else {
		throw ContainerException("Последний элемент не найден");
	}
}

Container* StackMassive::Clone() const
{
	return new StackMassive(*this);
}

