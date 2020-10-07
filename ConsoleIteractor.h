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
	int indexOfContainer = 0;
private:
	int containerSize = 0;
	
};