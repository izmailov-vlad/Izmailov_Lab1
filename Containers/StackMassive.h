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

	void push( const std::string &new_element) override;

	void MultiPush(const int& count, std::string *elements) override;

	void pop() override;

	void MultiPop(const int& count) override;

	bool isEmpty() const override;

	std::string ToString() const override;

	std::string back() const override;


	

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
	int sizeOfStack;
	int stackMemory;
	std::string* array;
};