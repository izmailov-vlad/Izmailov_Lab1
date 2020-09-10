#include "StackConsole.h"
#include "StackList.h"
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
void StackConsole::PrintStackList(StackList &stack) {
	
	Node* var = stack.getHead();
	cout << endl;
	while (var->next != nullptr) {
		cout << "[" << var->element << "] ";
		var = var->next;
	}
	cout << "[" << var->element << "] " << endl << endl;
}

void StackConsole::PrintStackMassive(StackMassive &stack) {
	std::string *array = stack.getArray();
	cout << endl;
	for (int begin = 0; begin < stack.getSize(); begin++) {
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

	StackMassive stack(InputSize());
	//StackList stack;
	
	while (action != "exit") {
		
		cout << endl << "������� �������: ";
		cin >> action;

		if (action == "push") {
			if (stack.getSize() < stack.GetSizeArray()) {
				cout << "������� ������� : ";
				cin >> element;
				cout << endl;
				stack.push(element);
			}
			else {
				cout << "��������� ������ �����, ������ �������� ��������� ������" << endl;
			}
		}

		else if (action == "multi_push") {
			cout << "������� ���������� ���������: ";
			cin >> count;
			if (count + stack.getSize() <= stack.GetSizeArray()) {
				std::string* elements = new std::string[count];
				for (int i = 0; i < count; i++) {
					cin >> elements[i];
				}
				stack.MultiPush(count, elements);
			}
			else {
				cout << "������ �������� ����� " << count << " ���������, �.�. ��� ��������� ������ �����" << endl;
			}
		}

		else if (action == "pop") {
			cout << endl;
			if (stack.isEmpty()) {
				stack.pop();
			}
			else {
				cout << "���� ����" << endl;
			}
			cout << endl;
		}
		else if(action == "multi_pop") {
			cout << "������� ���������� ��������� ���������: ";
			cin >> count;

			if (stack.getSize() - count >= 0) {
				stack.MultiPop(count);
			}
			else {
				int size = stack.getSize();
				stack.MultiPop(size);
			}
		}

		else if (action == "isEmpty") {
			if (stack.isEmpty()) {
				cout << endl << "���� �� ����" << endl << endl;
			}
			else{
				cout << "���� ����" << endl << endl;
			}
		}

		else if (action == "printStack") {
			if (stack.isEmpty()) {
				//PrintStackList(stack);
				PrintStackMassive(stack);
			}
			else {
				cout << "���� ����" << endl;
			}
		}


		else if (action == "back") {
			cout << endl << "[" << stack.back() << "]" << endl << endl;
		}
	}
}
