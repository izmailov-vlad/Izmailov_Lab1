#pragma once
#include <string>
class ContainerException {
public:
	ContainerException(std::string error) {
		_error = error;
	}

	std::string GetError() {
		return _error;
	}

private:
	std::string _error;
};