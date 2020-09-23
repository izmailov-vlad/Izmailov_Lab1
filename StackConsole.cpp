#include "StackException.h"
#include "StackConsole.h"
#include "Factory.h"
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

void StackConsole::Actions() {
	setlocale(LC_ALL, "Russian");
	cout << "1. push -> ���������� �������� � ����� �����" << endl;
	cout << "2. multi_push -> ���������� ���������� ��������� � ����� �����" << endl;
	cout << "3. pop -> �������� ������� �������� �����" << endl;
	cout << "4. multi_pop -> ���������� �������� � ����� �����" << endl;
	cout << "5. isEmpty -> �������� ����� �� ������� ���������" << endl;
	cout << "6. printStack -> ����� �����" << endl;
	cout << "7. back -> ��������� ���������� �������� �����" << endl;
	cout << "8. cls -> �������� ��������� ����" << endl;
	cout << "9. help -> ������ ������" << endl;
	cout << "0. exit -> ����� �� ���������" << endl;
}
//
void StackConsole::PrintStackList(StackList *stack) {
	
	Node* var = stack->getHead();
	cout << endl;
	while (var->next != nullptr) {
		cout << "[" << var->element << "] ";
		var = var->next;
	}
	cout << "[" << var->element << "] " << endl << endl;
}

void StackConsole::PrintStackMassive(StackMassive *stack) {
	std::string *array = stack->getArray();
	cout << endl;

	for (int begin = 0; begin < stack->getSize(); begin++) {
		cout << "[" << array[begin] << "] ";
	}
	cout << endl;
}

int StackConsole::InputSize() {
	int size;
	cout << "������ �����: ";
	cin >> size;
	cout << endl;
	return size;
}



void StackConsole::InputAction() {
	setlocale(LC_ALL, "Russian");
	int count;
	int action = -1;
	string element;
	string type = "";
	Factory factory;
	Stack* stack;

	cout << endl << "List -> ���� �� ������ ������" << endl;
	cout << "Massive -> ���� �� ������ �������" << endl;
	cin >> type;

	if (type == "List") {
		stack = factory.CreateStackList();
	}
	else {
		stack = factory.CreateStackMassive(InputSize());
	}
	
	
	while (action != 0) {

		try {
			cout << endl << "������� �������: ";
			cin >> action;

			switch (action) {
				case 1:
				{
					cout << "������� ������� : ";
					cin >> element;
					cout << endl;
					stack->push(element);
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
					stack->MultiPush(count, elements);
					break;
				}
				case 3:
				{
					cout << endl;

					stack->pop();
					cout << endl;
					break;
				}
				case 4:
				{
					cout << "������� ���������� ��������� ���������: ";
					cin >> count;

					stack->MultiPop(count);

					break;
				}
				case 5:
				{
					if (stack->isEmpty()) {
						cout << endl << "���� �� ����" << endl << endl;
					}
					else {
						cout << endl << "���� ����" << endl << endl;
					}
					break;
				}
				case 6: 
				{
					if (stack->isEmpty()) {

						if (type == "List") {
							PrintStackList(dynamic_cast<StackList*>(stack));
						}
						else {
							PrintStackMassive(dynamic_cast<StackMassive*>(stack));
						}
					}
					else {
						cout << "���� ����" << endl;
					}
					break;

				}
				case 7: 
				{
					cout << endl << "[" << stack->back() << "]" << endl << endl;
					break;
				}
				case 8: 
				{
					system("cls");
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
		catch (StackException& ex) {
			cout << ex.GetError() << endl;
		}
	}

	delete stack;
}
