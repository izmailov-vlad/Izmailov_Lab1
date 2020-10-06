#pragma once
#include "StackList.h"
#include "StackMassive.h"
#include "Queue.h"

class Factory {
public:

	StackList* CreateStackList() const {
		return new StackList();
	}

	StackMassive* CreateStackMassive(int size) const {
		return new StackMassive(size);
	}

	Queue* CreateQueue(int size) const {
		return new Queue(size);
	}


};