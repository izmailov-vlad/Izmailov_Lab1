#pragma once
#include "Container.h"
#include <sstream>
#include <string>

class StackMassive : public Container {
public:
	StackMassive(int massiveSize) {
		_sizeOfStack = 0;
		_stackMemory = massiveSize;
		this->_array = new std::string[massiveSize];
	}

	StackMassive(const StackMassive& object) : StackMassive(object._stackMemory) {
		if (object._array != nullptr) {
			this->_array = new std::string[object._stackMemory];
			this->_stackMemory = object._stackMemory;
			this->_sizeOfStack = object._sizeOfStack;
		}
	}

	StackMassive& operator = (const StackMassive& object) {

		if (&object == this) {
			return *this;
		}

		if (_array != nullptr) {
			delete[] _array;
		}
		if (object._array != nullptr) {
			_array = new std::string[_stackMemory];
			std::copy(object._array, object._array + object._stackMemory, _array);
		}

		return *this;
	}

	void Push( const std::string& new_element) override;

	void MultiPush(int count, std::string *elements) override;

	void Pop() override;
	 
	void MultiPop(int count) override;

	bool Empty() const override;

	std::string ToString() const override;

	std::string& Back() const override;

	Container* Clone() const override;

	const std::string& GetType() const override {
		return _type;
	}

	

	int GetSize() const {
		return _sizeOfStack;
	}

	std::string* GetArray() const {
		return _array;
	}

	int GetSizeArray() {
		return _stackMemory;
	}

	~StackMassive() {
		delete[] _array;
	}

private:
	const std::string _type = "StackMassive";
	int _sizeOfStack = 0;
	int _stackMemory;
	std::string* _array;
};