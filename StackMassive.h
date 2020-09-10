#pragma once
#include "Stack.h"
#include <string>

class StackMassive : public Stack {
public:
	StackMassive(int massiveSize) {
		sizeOfStack = 0;
		stackMemory = massiveSize;
		this->array = new std::string[massiveSize];
	}

	virtual void push( const std::string new_element);

	virtual void MultiPush(int& count, std::string *elements);

	virtual void pop();

	virtual void MultiPop(int& count);

	virtual bool isEmpty();

	virtual std::string back();


	

	int getSize() {
		return sizeOfStack;
	}

	std::string* getArray() {
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