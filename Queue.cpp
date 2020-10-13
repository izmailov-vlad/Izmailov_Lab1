#include "Queue.h"
#include <iostream>
#include <ostream>
#include "ContainerException.h"



void Queue::Push (const std::string& element) {
	if (_queueSize < _queueMemory) {
		_queue[_queueSize] = element;
		_queueSize++;
	}
	else {
		throw ContainerException("Переполнение");
	}
}

void Queue::MultiPush(const int count, std::string *elements) {
	if (count + _queueSize <= _queueMemory) {

		for (int i = 0; i < count; i++) {
			Push(elements[i]);
		}

		delete[]elements;
	}
	else {
		throw ContainerException("Невозможно добавить такое количество элементов");
	}
}

void Queue::MultiPop(const int count) {
	for (int i = 0; i < count; i++) {
		if (_queueSize) {
			Pop();
		}
		else {
			throw ContainerException("Все элементы удалены");
		}
	}
}

Container* Queue::Clone() const
{
	return new Queue(*this);
}

std::string Queue::ToString() const {
	std::ostringstream out;
	std::string* array = _queue;
	std::string ans;
	
	

	for (int begin = 0; begin < _queueSize; begin++) {
		out << "[" << array[begin] << "] ";
	}

	ans = out.str();
	return ans;
}

void Queue::Pop() {
	for (int i = 1; i < _queueSize; i++) {
		_queue[i - 1] = _queue[i];
	}
	_queue[_queueSize - 1] = "";
	_queueSize--;
}

std::string& Queue::Front() const {
	if (_queueSize != 0) {
		return _queue[0];
	}

	throw ContainerException("Стек пуст");
}

std::string& Queue::Back() const {
	if (_queueSize != 0) {
		return _queue[_queueSize - 1];
	}

	throw ContainerException("Стек пуст");
}

bool Queue::Empty() const {
	return _queueSize == 0;
}