#pragma once
#include "IConsole.h"
class QueueConsole : public IConsole{
public:
	virtual void Actions() override;
	virtual void InputAction() override;
	int InputSize();
};