#include "Containers.h"
#include <iostream>
using namespace std;
void Containers::ChooseContainer()
{
	setlocale(LC_ALL, "Russian");

	IConsole* console = nullptr;
	int container;

	cout << "1. Queue -> Создать очередь" << endl;
	cout << "2. Stack -> Создать стек" << endl;

	cin >> container;

	switch (container) {
		case 1: 
		{
			console = CreateQueueContainer();
			break;
		}
		case 2: 
		{
			console = CreateStackContainer();
			break;
		}
	}

	console->Actions();
	console->InputAction();

	delete console;
}

