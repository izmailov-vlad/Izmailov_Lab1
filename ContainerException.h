#pragma once
#include <string>
#include <exception>
class ContainerException : public std::exception {
public:
	ContainerException(std::string error) {
		_error = error;
	}

	std::string& GetError() {
		return _error;
	}


private:
	std::string _error;
};