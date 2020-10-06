#include "ContainerException.h"
#include "ConsoleIteractor.h"
#include <iostream>
#define CONTAINER_SIZE 100

using namespace std;

void ConsoleIteractor::Actions()
{
	setlocale(LC_ALL, "Russian");
	cout << "-1 -> ������� ����� ���������" << endl;
	cout << "-2 -> ������� ��� ����������" << endl;
	cout << "-3 -> ������� ���������" << endl;
	cout << "1. push -> ���������� �������� � ����� ����������" << endl;
	cout << "2. multi_push -> ���������� ���������� ��������� � ����� ����������" << endl;
	cout << "3. pop -> �������� ������� �������� ����������" << endl;
	cout << "4. multi_pop -> ���������� �������� � ����� ����������" << endl;
	cout << "5. Empty -> �������� ���������� �� ������� ���������" << endl;
	cout << "6. printContainer -> ����� ��������� ����������" << endl;
	cout << "7. back -> ��������� ���������� �������� ����������" << endl;
	cout << "8. cls -> �������� ��������� ����" << endl;
	cout << "9. help -> ������ ������" << endl;
	cout << "0. exit -> ����� �� ���������" << endl;
}



Container* ConsoleIteractor::CreateContainer(Container *container, Factory factory) {
	int choose = -1;
	string type = "";
	cout << "1. Stack" << endl;
	cout << "2. Queue" << endl;
	while (choose != 1 && choose != 2) {
		
		cin >> choose;
		switch (choose) {
			case 1:
			{
				cout << "List -> ���� �� ������ ������" << endl;
				cout << "Massive -> ���� �� ������ �������" << endl;

				while (type != "List" && type != "Massive") {
					cin >> type;
					if (type == "List") {
						container = factory.CreateStackList();
					}
					else if (type == "Massive") {
						container = factory.CreateStackMassive(InputSize());
					}
					else {
						cout << "�������� �������, ���������� ��� ���" << endl;
					}
				}
				break;
			}
			case 2:
			{
				container = factory.CreateQueue(InputSize());
				break;
			}
		}
	}
	return container;
}

void ConsoleIteractor::PrintAllContainers(Container **container) {
	for (int i = 0; i < containerSize; i++) {
		cout << container[i]->ToString();
		cout << endl << endl;
	}
}

void ConsoleIteractor::InputAction() {
	setlocale(LC_ALL, "Russian");

	Factory factory;
	int count;
	std::string syscomand = "";
	int action = -1;

	string element;
	

	Container* container[CONTAINER_SIZE];
	

	for (int i = 0; i < CONTAINER_SIZE; i++) {
		container[i] = nullptr;
	}
	
	Actions();

	while (action != 0) {

		try {
			cout << endl << "������� �������: ";
			cin >> action;

			switch (action) {
			
			case -1: 
			{
				container[containerSize] = CreateContainer(*container, factory);
				containerSize++;
				break;
			}
			case -2: 
			{
				PrintAllContainers(container);
				/*for (int i = 0; i < containerSize; i++) {
					if (container[i]) {
						cout << container[i]->ToString();
						cout << endl;
					}
				}*/
				break;
			}
			case -3: 
			{
				cout << "������� ������ ����������: ";
				cin >> indexOfContainer;
				if (container[indexOfContainer] == nullptr) {
					throw ("���������� � ����� �������� �� ����������");
				}
				break;
			}
			case 1:
			{
				cout << "������� ������� : ";
				cin >> element;
				cout << endl;
				container[indexOfContainer]->push(element);
				break;
			}

			case 2:
			{
				cout << "������� ���������� ���������: ";
				cin >> count;
				std::string* elements = new std::string[count];
				for (int i = 0; i < count; i++) {
					cin >> elements[i];
				}
				container[indexOfContainer]->MultiPush(count, elements);
				break;
			}
			case 3:
			{
				cout << endl;

				container[indexOfContainer]->pop();
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "������� ���������� ��������� ���������: ";
				cin >> count;

				container[indexOfContainer]->MultiPop(count);

				break;
			}
			case 5:
			{
				if (container[indexOfContainer]) {
					if (container[indexOfContainer]->Empty()) {
						cout << endl << "��������� ����" << endl << endl;
					}
					else {
						cout << endl << "��������� �� ����" << endl << endl;
					}
				}
				break;
			}
			case 6:
			{
				if (container[indexOfContainer]) {
					if (!container[indexOfContainer]->Empty()) {
						cout << container[indexOfContainer]->ToString() << endl;
					}
					else {
						cout << "���� ����" << endl;
					}
				}
				break;

			}
			case 7:
			{
				cout << endl << "[" << container[indexOfContainer]->back() << "]" << endl << endl;
				break;
			}
			case 8:
			{
				system("cls");
				Actions();
				break;
			}
			case 9:
			{
				Actions();
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{
				cout << "�������� �������, ���������� ��� ���" << endl;
			}
			}
		}
		catch (ContainerException& ex) {
			cout << ex.GetError() << endl;
		}
	}

	for (int i = 0; i < containerSize; i++) {
		delete container[i];
	}
}

int ConsoleIteractor::InputSize()
{
	int size;
	cout << "������� ������ ���������� :";
	cin >> size;

	return size;
}
