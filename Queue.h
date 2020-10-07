#pragma once
#include <string>
#include <sstream>
#include <algorithm>
#include "Container.h"
class Queue : public Container {
public:

	Queue(int sizeQueue) {
		queue = new std::string[sizeQueue];
		queueMemory = sizeQueue;
	}

	Queue(const Queue& object) : Queue(object.queueMemory) {
		if (object.queue != nullptr) {
			this->queue = new std::string[object.queueMemory];
			this->queueMemory = object.queueMemory;
			this->queueSize = object.queueSize;
			std::copy(object.queue, object.queue + object.queueMemory, queue);
		}
	}

	Queue& operator = (const Queue& object) {

		if (&object == this) {
			return *this;
		}

		if (queue != nullptr) {
			delete[] queue;
		}

		if (object.queue != nullptr) {
			queue = new std::string[object.queueMemory];
			this->queueMemory = object.queueMemory;
			this->queueSize = object.queueSize;
			std::copy(object.queue, object.queue + object.queueMemory, queue);
		}

		return *this;
	}

	void MultiPush(const int count, std::string *elements) override;
	void Push(const std::string element) override;
	void MultiPop(const int count) override;
	Container* Clone() const override;
	void Pop() override;

	std::string ToString() const override;
	std::string Front() const;
	std::string Back() const override;
	std::string GetType() const override {
		return type;
	}

	bool Empty() const override;

	~Queue() {
		delete[] queue;
	}
private:
	std::string type = "Queue";
	std::string* queue;
	int queueSize = 0;
	int queueMemory;
};