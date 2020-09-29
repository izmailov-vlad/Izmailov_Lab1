#pragma once
#include <string>
#include <sstream>
#include "Container.h"
class Queue : public Container {
public:

	Queue(int sizeQueue) {
		queue = new std::string[sizeQueue];
		queueMemory = sizeQueue;
	}

	void MultiPush(const int &count, std::string *elements) override;
	void push(const std::string& element) override;
	void MultiPop(const int &count) override;
	void pop() override;

	std::string ToString() const override;
	std::string Front() const;
	std::string back() const override;

	bool isEmpty() const override;

	~Queue() {
		delete[] queue;
	}
private:
	std::string* queue;
	int queueSize = 0;
	int queueMemory;
};