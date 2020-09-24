#pragma once
#include "Stack.h"
#include <sstream>
#include <string>

class StackMassive : public Stack {
public:
	StackMassive(int massiveSize) {
		sizeOfStack = 0;
		stackMemory = massiveSize;
		this->array = new std::string[massiveSize];
	}

	void push( const std::string new_element) override;

	void MultiPush(int& count, std::string *elements) override;

	void pop() override;

	void MultiPop(int& count) override;

	bool isEmpty() override;

	std::string const ToString() override;

	std::string back() override;


	

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