#pragma once
#include <string>

class Container {
public:

	virtual void MultiPush(const int count, std::string *elements) = 0;

	virtual void Push(const std::string& new_element) = 0;

	virtual void MultiPop(const int count) = 0;

	virtual std::string ToString() const = 0;

	virtual std::string& Back() const = 0;

	virtual Container* Clone() const = 0;

	virtual const std::string& GetType() const = 0;

	virtual bool Empty() const = 0;

	virtual void Pop() = 0;

	virtual ~Container() = default;
	
};