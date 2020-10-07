#include "Test.h"
#include "ContainerException.h"
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool Test::RunTest()
{
	try {
		TestQueue();
		TestStackList();
		TestStackMassive();
	}
	catch (ContainerException& ex) {
		cout << ex.GetError() << endl;
		return false;
	}
}

void Test::TestQueue()
{

		cout << "Waiting for the Test1..." << endl;
		Factory factory;
		Container* container = factory.CreateQueue(100);
		for (int i = 0; i < 50; i++) {
			container->Push("q");
		}
		std::string* elements = new std::string[50];
		for (int i = 0; i < 50; i++) {
			elements[i] = "q";
		}

		container->Back();
		container->Empty();

		container->MultiPush(50, elements);

		for (int i = 0; i < 50; i++) {
			container->Pop();
		}

		container->MultiPop(50);
		cout << "Test1 done" << endl;

		delete container;
}
	


void Test::TestStackList()
{
	cout << "Waiting for the Test2..." << endl;
	Factory factory;
	Container* container = factory.CreateStackMassive(100);

	for (int i = 0; i < 50; i++) {
		container->Push("q");
	}
	std::string* elements = new std::string[50];
	for (int i = 0; i < 50; i++) {
		elements[i] = "q";
	}

	container->Back();
	container->Empty();

	container->MultiPush(50, elements);

	for (int i = 0; i < 50; i++) {
		container->Pop();
	}

	container->MultiPop(50);
	cout << "Test2 done" << endl;

	delete container;
}

void Test::TestStackMassive()
{
	cout << "Waiting for the Test3..." << endl;
	Factory factory;
	Container* container = factory.CreateQueue(100);
	for (int i = 0; i < 50; i++) {
		container->Push("q");
	}
	std::string* elements = new std::string[50];
	for (int i = 0; i < 50; i++) {
		elements[i] = "q";
	}

	container->Back();
	container->Empty();

	container->MultiPush(50, elements);

	for (int i = 0; i < 50; i++) {
		container->Pop();
	}

	container->MultiPop(50);
	cout << "Test3 done" << endl;

	delete container;
}
