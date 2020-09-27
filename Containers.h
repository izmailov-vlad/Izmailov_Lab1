#pragma once
#include "IConsole.h"
#include "QueueConsole.h"
#include "StackConsole.h"
class Containers {
public:

	void ChooseContainer();

	QueueConsole* CreateQueueContainer() {
		return new QueueConsole();
	}

	StackConsole* CreateStackContainer() {
		return new StackConsole();
	}
	
};