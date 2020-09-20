#include "StackConsole.h"
#include "StackList.h"
#include "StackException.h"
#include <iostream>
#include <string>
using namespace std;

void StackConsole::Actions() {
	setlocale(LC_ALL, "Russian");
	cout << "push -> ���������� �������� � ����� �����" << endl;
	cout << "multi_push -> ���������� ���������� ��������� � ����� �����" << endl;
	cout << "pop -> �������� ������� �������� �����" << endl;
	cout << "multi_pop -> ���������� �������� � ����� �����" << endl;
	cout << "isEmpty -> �������� ����� �� ������� ���������" << endl;
	cout << "back -> ��������� ���������� �������� �����" << endl;
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
	string action = "";
	string element;
	string type = "";
	Stack* stack;

	cout << endl << "List -> ���� �� ������ ������" << endl;
	cout << "Massive -> ���� �� ������ �������" << endl;
	cin >> type;

	if (type == "List") {
		stack = new StackList();
	}
	else {
		stack = new StackMassive(InputSize());
	}
	
	
	while (action != "exit") {
		try {
			cout << endl << "������� �������: ";
			cin >> action;

			if (action == "push") {

				cout << "������� ������� : ";
				cin >> element;
				cout << endl;
				stack->push(element);

			}

			else if (action == "multi_push") {
				cout << "������� ���������� ���������: ";
				cin >> count;

				std::string* elements = new std::string[count];

				for (int i = 0; i < count; i++) {
					cin >> elements[i];
				}

				stack->MultiPush(count, elements);


			}

			else if (action == "pop") {
				cout << endl;

				stack->pop();

				cout << endl;
			}
			else if (action == "multi_pop") {

				cout << "������� ���������� ��������� ���������: ";
				cin >> count;

				stack->MultiPop(count);

			}

			else if (action == "isEmpty") {
				if (stack->isEmpty()) {
					cout << endl << "���� �� ����" << endl << endl;
				}
				else {
					cout << endl << "���� ����" << endl << endl;
				}
			}

			else if (action == "printStack") {
				if (stack->isEmpty()) {

					if (type == "List") {
						PrintStackList(static_cast<StackList*>(stack));
					}
					else {
						PrintStackMassive(static_cast<StackMassive*>(stack));
					}
				}
				else {
					cout << "���� ����" << endl;
				}
			}


			else if (action == "back") {
				cout << endl << "[" << stack->back() << "]" << endl << endl;
			}
		} 
		catch (StackException& ex) {
			cout << ex.GetError() << endl;
		}
	}

	delete stack;
}
