#include "Factory.h"
#include <iostream>
using namespace std;

StackList* Factory::createStackList() {
	return new StackList();
}

StackMassive* Factory::createStackMassive() {
	int size;
	cout << "������ �����: ";
	cin >> size;
	cout << endl;
	return new StackMassive(size);
}