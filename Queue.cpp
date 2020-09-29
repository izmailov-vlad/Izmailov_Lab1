#include "Queue.h"
#include <iostream>
#include "ContainerException.h"



void Queue::push (const std::string& element) {
	if (queueSize < queueMemory) {
		queue[queueSize] = element;
		queueSize++;
	}
}

void Queue::MultiPush(const int &count, std::string *elements) {
	if (count + queueSize <= queueMemory) {

		for (int i = 0; i < count; i++) {
			push(elements[i]);
		}

		delete[]elements;
	}
	else {
		throw ContainerException("���������� �������� ����� ���������� ���������");
	}
}

void Queue::MultiPop(const int &count) {
	for (int i = 0; i < count; i++) {
		if (queueSize) {
			pop();
		}
		else {
			throw ContainerException("��� �������� �������");
		}
	}
}

std::string Queue::ToString() const {
	std::ostringstream out;
	std::string* array = Queue::queue;
	out << "\n";

	for (int begin = 0; begin < queueSize; begin++) {
		out << "[" << array[begin] << "] ";
	}
	out << "\n";

	return out.str();
}

void Queue::pop() {
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

	throw ContainerException("���� ����");
}

std::string Queue::back() const {
	if (queueSize != 0) {
		return queue[queueSize - 1];
	}

	throw ContainerException("���� ����");
}

bool Queue::isEmpty() const {
	return queueSize == 0;
}