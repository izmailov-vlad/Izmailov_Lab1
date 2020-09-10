#include "StackConsole.h"
#include "StackList.h"
#include <iostream>
#include <string>
using namespace std;

void StackConsole::Actions() {
	setlocale(LC_ALL, "Russian");
	cout << "push -> Добавление элемента в конец стека" << endl;
	cout << "pop -> Удаление первого элемента стека" << endl;
	cout << "isEmpty -> Проверка стека на наличие элементов" << endl;
	cout << "back -> Получение последнего элемента стека" << endl;
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

void StackConsole::InputAction() {
	setlocale(LC_ALL, "Russian");
	string action = "";
	string element;


	
	int size;
	cout << "Размер стека: ";
	cin >> size;
	cout << endl;
	StackMassive stack(size);
	//StackList stack;
	
	while (action != "exit") {
		cin >> action;
		if (action == "push") {
			cout << "Введите элемент : ";
			cin >> element;
			cout << endl;
			stack.push(element);
		}
		else if (action == "pop") {
			cout << endl;
			stack.pop();
			cout << endl;
		}
		else if (action == "isEmpty") {
			if (stack.isEmpty()) {
				cout << endl << "Стек не пуст" << endl << endl;
			}
			else{
				cout << "Стек не пуст" << endl << endl;
			}
		}
		else if (action == "printStack") {
			if (stack.isEmpty()) {
				PrintStackMassive(stack);
			}
			else {
				cout << "Стек пуст" << endl;
			}
		}
		else if (action == "back") {
			cout << endl << "[" << stack.back() << "]" << endl << endl;
		}
	}
}
