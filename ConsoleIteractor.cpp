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

void ConsoleIteractor::TestForConstructors()
{
	std::string* elements = new std::string[5];
	Container* container1 = new StackList();

	for (int i = 0; i < 5; i++) {
		cin >> elements[i];
	}

	container1->MultiPush(5, elements);

	cout << container1->ToString() << endl;

	Container* container2 = container1->Clone();
	
	cout << container2->ToString() << endl;

	delete container1;
	delete container2;
}

void ConsoleIteractor::TestForOperators() {

	std::string* elements1 = new std::string[5];

	Queue container1(5);
	for (int i = 0; i < 5; i++) {
		cin >> elements1[i];
	}
	container1.MultiPush(5, elements1);

	Queue container2(5);
	
	std::string* elements2 = new std::string[5];
	for (int i = 0; i < 5; i++) {
		cin >> elements2[i];
	}
	container2.MultiPush(5, elements2);


	cout << container1.ToString() << endl;
	cout << container2.ToString() << endl;
	
	container1 = container2;

	cout << container1.ToString() << endl;
	cout << container2.ToString() << endl;

}



Container* ConsoleIteractor::CreateContainer(Container *container, Factory factory) {
	int choose = -1;
	cout << "1. Stack" << endl;
	cout << "2. Queue" << endl;
	while (choose != 1 && choose != 2) {
		
		cin >> choose;
		switch (choose) {
			case 1:
			{
				cout << "  1. List -> ���� �� ������ ������" << endl;
				cout << "  2. Massive -> ���� �� ������ �������" << endl;
				
				do {
					cout << "������� ����� �������: ";
					cin >> choose;
					switch (choose) {
						case 1: {
							container = factory.CreateStackList();
							break;
						}
						case 2:{
							container = factory.CreateStackMassive(InputSize());
							break;
						}
						default: {
							cout << "�������� �������, ���������� ��� ���" << endl;
						}
					}
					
				} while (choose != 1 && choose != 2);
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
	if (containerSize) {
		for (int i = 0; i < containerSize; i++) {
			cout << endl << container[i]->GetType() << ": ";
			cout << container[i]->ToString();
			cout << endl << endl;
		}
		return;
	}
	throw ContainerException("��� �� ������ ����������");
}

void ConsoleIteractor::InputAction() {
	setlocale(LC_ALL, "Russian");

	Factory factory;
	Container* container[CONTAINER_SIZE];
	
	string element;
	
	int action = -1;
	int count;


	for (int i = 0; i < CONTAINER_SIZE; i++) {
		container[i] = nullptr;
	}
	
	Actions();

	while (action != 0) {

		try {
			cout << endl << "#" << indexOfContainer << ": ������� �������: ";
			cin >> action;

			if ((action > 0 && action < 8) && containerSize == 0) {
				throw ContainerException("��� �� ������ ����������");
			}

			switch (action) {

				case -1:
				{
					container[containerSize] = CreateContainer(*container, factory);
					containerSize++;
					break;
				}
				case -2:
				{
					if (containerSize) {
						PrintAllContainers(container);
					}
					else throw ContainerException("��� �� ������ ����������");
					
					break;
				}
				case -3:
				{
					int last_index = indexOfContainer;
					cout << "������� ������ ����������: ";
					cin >> indexOfContainer;

					if (container[indexOfContainer] == nullptr) {
						indexOfContainer = last_index;
						throw ContainerException("���������� � ����� �������� �� ����������");
					}
					break;
				}
				
				case 1:
				{
						cout << "������� ������� : ";
						cin >> element;
						cout << endl;
						container[indexOfContainer]->Push(element);
					
					
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

					container[indexOfContainer]->Pop();
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
					else {
						throw ContainerException("���������� �� ����������");
					}
					
					break;
				}
				case 6:
				{
					if (container[indexOfContainer]) {
						if (!container[indexOfContainer]->Empty()) {
							cout << endl << container[indexOfContainer]->GetType() << ": " << container[indexOfContainer]->ToString() << endl;
						}
						else {
							cout << "���� ����" << endl;
						}
					}
					
					break;

				}
				case 7:
				{
					cout << endl << "[" << container[indexOfContainer]->Back() << "]" << endl << endl;
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
