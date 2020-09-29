#pragma once
#include <string>

class Container {
public:

	virtual void push(const std::string &new_element) = 0;

	virtual void MultiPush(const int& count, std::string *elements) = 0;

	virtual void MultiPop(const int& count) = 0;

	virtual void pop() = 0;

	virtual bool isEmpty() const = 0;

	virtual std::string ToString() const = 0;

	virtual std::string back() const = 0;

	virtual ~Container() = default;
	
};