#pragma once
#include "Container.h"
#include "Factory.h"
class ConsoleIteractor {
public:

	Container* CreateContainer(Container *container, Factory factory);
	void PrintAllContainers(Container** container);
	void InputAction();
	void Actions();
	void TestForConstructors();
	void TestForOperators();
	int InputSize();
	
private:
	int _indexOfContainer = 0;
	int _containerSize = 0;
	static const int _CONTAINER_SIZE = 100;
	
};