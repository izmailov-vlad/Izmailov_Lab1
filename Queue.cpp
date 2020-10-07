#include "Queue.h"
#include <iostream>
#include "ContainerException.h"



void Queue::Push (const std::string element) {
	if (queueSize < queueMemory) {
		queue[queueSize] = element;
		queueSize++;
	}
	else {
		throw ContainerException("Переполнение");
	}
}

void Queue::MultiPush(const int count, std::string *elements) {
	if (count + queueSize <= queueMemory) {

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
		if (queueSize) {
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
	std::string* array = queue;
	

	for (int begin = 0; begin < queueSize; begin++) {
		out << "[" << array[begin] << "] ";
	}

	return out.str();
}

void Queue::Pop() {
	for (int i = 1; i < queueSize; i++) {
		queue[i - 1] = queue[i];
	}
	queue[queueSize - 1] = "";
	queueSize--;
}

std::string Queue::Front() const {
	if (queueSize != 0) {
		return queue[0];
	}

	throw ContainerException("Стек пуст");
}

std::string Queue::Back() const {
	if (queueSize != 0) {
		return queue[queueSize - 1];
	}

	throw ContainerException("Стек пуст");
}

bool Queue::Empty() const {
	return queueSize == 0;
}