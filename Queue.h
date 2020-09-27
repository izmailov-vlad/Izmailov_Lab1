#pragma once
#include <string>
#include <sstream>
class Queue {
public:

	Queue(int sizeQueue) {
		queue = new std::string[sizeQueue];
		queueMemory = sizeQueue;
	}

	void MultiPush(int count, std::string *elements);
	void Push(const std::string& element);
	void MultiPop(int count);
	void Pop();

	std::string ToString();
	std::string Front();
	std::string Back();

	bool Empty();

	~Queue() {
		delete[] queue;
	}
private:
	std::string* queue;
	int queueSize = 0;
	int queueMemory;
};