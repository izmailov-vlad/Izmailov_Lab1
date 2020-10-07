#pragma once
#include "Container.h"
#include <sstream>
#include <string>

class StackMassive : public Container {
public:
	StackMassive(int massiveSize) {
		sizeOfStack = 0;
		stackMemory = massiveSize;
		this->array = new std::string[massiveSize];
	}

	StackMassive(const StackMassive& object) : StackMassive(object.stackMemory) {
		if (object.array != nullptr) {
			this->array = new std::string[object.stackMemory];
			this->stackMemory = object.stackMemory;
			this->sizeOfStack = object.sizeOfStack;
		}
	}

	StackMassive& operator = (const StackMassive& object) {

		if (&object == this) {
			return *this;
		}

		if (array != nullptr) {
			delete[] array;
		}
		if (object.array != nullptr) {
			array = new std::string[stackMemory];
			std::copy(object.array, object.array + object.stackMemory, array);
		}

		return *this;
	}

	void Push( const std::string new_element) override;

	void MultiPush(const int count, std::string *elements) override;

	void Pop() override;
	 
	void MultiPop(const int count) override;

	bool Empty() const override;

	std::string ToString() const override;

	std::string Back() const override;

	Container* Clone() const override;

	std::string GetType() const override {
		return type;
	}

	

	int getSize() const {
		return sizeOfStack;
	}

	std::string* getArray() const {
		return array;
	}

	int GetSizeArray() {
		return stackMemory;
	}

	~StackMassive() {
		delete[] array;
	}

private:
	std::string type = "StackMassive";
	int sizeOfStack = 0;
	int stackMemory;
	std::string* array;
};