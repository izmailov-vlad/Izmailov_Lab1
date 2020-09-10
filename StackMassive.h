#pragma once
#include "Stack.h"
#include <string>
class StackMassive : public Stack {
public:
	StackMassive(int massiveSize) {
		sizeOfStack = 0;
		this->array = new std::string[massiveSize];
	}

	virtual void push( const std::string new_element);

	virtual void pop();

	virtual bool isEmpty();

	virtual std::string back();


	

	int getSize() {
		return sizeOfStack;
	}

	std::string* getArray() {
		return array;
	}

	~StackMassive() {
		delete[] array;
	}

private:
	int sizeOfStack;
	std::string* array;
};