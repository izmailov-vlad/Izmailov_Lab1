#pragma once
#include <string>
#include <exception>
class ContainerException : public std::exception {
public:
	ContainerException(const char* error) {
		_error = error;
	}

	const char* what() const noexcept override {
		return _error;
	}


private:
	const char* _error;
};

