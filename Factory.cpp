#include "Factory.h"
#include "Queue.h"
#include "StackList.h"
#include "StackMassive.h"

Container* Factory::CreateContainer(int type, int size) {
	if (type == 1) {
		return new StackList();
	}
	else if (type == 2) {
		return new StackMassive(size);
	}
	else if (type == 3) {
		return new Queue(size);
	}
}