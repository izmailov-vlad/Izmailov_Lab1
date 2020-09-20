#pragma once
#include <string>
class StackException {
public:
	StackException(std::string error) {
		_error = error;
	}

	std::string GetError() {
		return _error;
	}

private:
	std::string _error;
};