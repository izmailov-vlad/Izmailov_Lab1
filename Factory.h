#pragma once
#include "Container.h"

class Factory {
public:

	Container* CreateContainer(int type, int size = 0);
};