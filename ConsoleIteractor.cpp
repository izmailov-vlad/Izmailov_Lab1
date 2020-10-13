#include "ContainerException.h"
#include "ConsoleIteractor.h"
#include <iostream>


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

//void ConsoleIteractor::TestForConstructors()
//{
//	std::string* elements = new std::string[5];
//	Container* container1 = new StackList();
//
//	for (int i = 0; i < 5; i++) {
//		cin >> elements[i];
//	}
//
//	container1->MultiPush(5, elements);
//
//	cout << container1->ToString() << endl;
//
//	Container* container2 = container1->Clone();
//	
//	cout << container2->ToString() << endl;
//
//	delete container1;
//	delete container2;
//}

//void ConsoleIteractor::TestForOperators() {
//
//	std::string* elements1 = new std::string[5];
//
//	Queue container1(5);
//	for (int i = 0; i < 5; i++) {
//		cin >> elements1[i];
//	}
//	container1.MultiPush(5, elements1);
//
//	Queue container2(5);
//	
//	std::string* elements2 = new std::string[5];
//	for (int i = 0; i < 5; i++) {
//		cin >> elements2[i];
//	}
//	container2.MultiPush(5, elements2);
//
//
//	cout << container1.ToString() << endl;
//	cout << container2.ToString() << endl;
//	
//	container1 = container2;
//
//	cout << container1.ToString() << endl;
//	cout << container2.ToString() << endl;
//
//}



Container* ConsoleIteractor::CreateContainer(Container *container, Factory factory) {

	int choose = -1;
	int type = 0;
	int size = 0;

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
					cout << "  ������� ����� �������: ";
					cin >> choose;
					switch (choose) {
						case 1: {
							type = 1;
							break;
						}
						case 2:{
							size = InputSize();
							type = 2;

							break;
						}
						default: {
							cout << "  �������� �������, ���������� ��� ���" << endl;
						}
					}
					
				} while (choose != 1 && choose != 2);
				break;
			}
			case 2:
			{
				type = 3;
				size = InputSize();
				break;
			}
		}
		container = factory.CreateContainer(type, size);
	}
	return container;
}

void ConsoleIteractor::PrintAllContainers(Container **container) {
	if (_containerSize) {
		for (int i = 0; i < _containerSize; i++) {
			cout << endl << i <<"# " << container[i]->GetType() << ": ";
			if (!container[i]->Empty()) {
				cout << container[i]->ToString();
			}
			else {
				cout << "��������� ����" << endl;
			}
			cout << endl << endl;
		}
		return;
	}
	throw std::exception("��� �� ������ ����������");
}

void ConsoleIteractor::InputAction() {
	setlocale(LC_ALL, "Russian");

	Factory factory;
	Container* container[_CONTAINER_SIZE];
	
	string element;
	
	int action = -1;
	int count;


	for (int i = 0; i < _CONTAINER_SIZE; i++) {
		container[i] = nullptr;
	}
	
	Actions();

	while (action != 0) {

		try {
			cout << endl << "#" << _indexOfContainer << ": ������� �������: ";
			cin >> action;

			if ((action > 0 && action < 8) && _containerSize == 0) {
				throw std::exception("��� �� ������ ����������");
			}

			switch (action) {

				case -1:
				{
					container[_containerSize] = CreateContainer(*container, factory);
					_containerSize++;
					break;
				}
				case -2:
				{
					if (_containerSize) {
						PrintAllContainers(container);
					}
					else throw std::exception("��� �� ������ ����������");
					
					break;
				}
				case -3:
				{
					int last_index = _indexOfContainer;
					cout << "������� ������ ����������: ";
					cin >> _indexOfContainer;

					if (container[_indexOfContainer] == nullptr) {
						_indexOfContainer = last_index;
						throw std::exception("���������� � ����� �������� �� ����������");
					}
					break;
				}
				
				case 1:
				{
						cout << "������� ������� : ";
						cin >> element;
						cout << endl;
						container[_indexOfContainer]->Push(element);
					
					
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
						container[_indexOfContainer]->MultiPush(count, elements);
					
					break;
				}
				case 3:
				{
					cout << endl;

					container[_indexOfContainer]->Pop();
					cout << endl;
					break;
				}
				case 4:
				{
					cout << "������� ���������� ��������� ���������: ";
					cin >> count;

					container[_indexOfContainer]->MultiPop(count);

					break;
				}
				case 5:
				{
					if (container[_indexOfContainer]) {
						if (container[_indexOfContainer]->Empty()) {
							cout << endl << "��������� ����" << endl << endl;
						}
						else {
							cout << endl << "��������� �� ����" << endl << endl;
						} 
					}
					else {
						throw std::exception("���������� �� ����������");
					}
					
					break;
				}
				case 6:
				{
					if (container[_indexOfContainer]) {
						if (!container[_indexOfContainer]->Empty()) {
							cout << endl << container[_indexOfContainer]->GetType() << ": " << container[_indexOfContainer]->ToString() << endl;
						}
						else {
							cout << "���� ����" << endl;
						}
					}
					
					break;

				}
				case 7:
				{
					if (container[_indexOfContainer]) {
						cout << endl << "[" << container[_indexOfContainer]->Back() << "]" << endl << endl;
					}
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
		catch (std:: exception& ex) {
			cout << ex.what() << endl;
		}
	}

	for (int i = 0; i < _containerSize; i++) {
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
