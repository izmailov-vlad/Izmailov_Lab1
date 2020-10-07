#pragma once
#include <string>
#include <sstream>
#include <algorithm>
#include "Container.h"
class Queue : public Container {
public:

	Queue(int sizeQueue) {
		_queue = new std::string[sizeQueue];
		_queueMemory = sizeQueue;
	}

	Queue(const Queue& object) : Queue(object._queueMemory) {
		if (object._queue != nullptr) {
			this->_queue = new std::string[object._queueMemory];
			this->_queueMemory = object._queueMemory;
			this->_queueSize = object._queueSize;
			std::copy(object._queue, object._queue + object._queueMemory, _queue);
		}
	}

	Queue& operator = (const Queue& object) {

		if (&object == this) {
			return *this;
		}

		if (_queue != nullptr) {
			delete[] _queue;
		}

		if (object._queue != nullptr) {
			_queue = new std::string[object._queueMemory];
			this->_queueMemory = object._queueMemory;
			this->_queueSize = object._queueSize;
			std::copy(object._queue, object._queue + object._queueMemory, _queue);
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
		return _type;
	}

	bool Empty() const override;

	~Queue() {
		delete[] _queue;
	}
private:
	std::string _type = "Queue";
	std::string* _queue;
	int _queueSize = 0;
	int _queueMemory;
};