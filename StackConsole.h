#pragma once
#include "StackList.h"
#include "StackMassive.h"

class StackConsole {
public:
	void Actions();
	void InputAction();
	void PrintStackList(StackList &stack);
	void PrintStackMassive(StackMassive &stack);
	int InputSize();
};