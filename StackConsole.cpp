#include <iostream>
#include <iterator>
#include <string>
#include "StackConsole.h"
#include "ContainerException.h"
#include "Factory.h"

using namespace std;

void StackConsole::Actions() {
	setlocale(LC_ALL, "Russian");
	cout << "1. push -> Добавление элемента в конец стека" << endl;
	cout << "2. multi_push -> Добавление нескольких элементов в конец стека" << endl;
	cout << "3. pop -> Удаление первого элемента стека" << endl;
	cout << "4. multi_pop -> Добавление элемента в конец стека" << endl;
	cout << "5. isEmpty -> Проверка стека на наличие элементов" << endl;
	cout << "6. printStack -> Вывод стека" << endl;
	cout << "7. back -> Получение последнего элемента стека" << endl;
	cout << "8. cls -> Очистить командное окно" << endl;
	cout << "9. help -> Список команд" << endl;
	cout << "0. exit -> Выход из программы" << endl;
}


int StackConsole::InputSize() {
	int size;
	cout << "Размер стека: ";
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
	Stack *stack = nullptr;

	cout << endl << "List -> Стек на основе списка" << endl;
	cout << "Massive -> Стек на основе массива" << endl;
	
	while (type != "List" || type != "Massive") {
		cin >> type;
		if (type == "List") {
			stack = factory.CreateStackList();
		}
		else {
			stack = factory.CreateStackMassive(InputSize());
		}
	} 
	
	
	while (action != 0) {

		try {
			cout << endl << "Введите команду: ";
			cin >> action;

			switch (action) {
				case 1:
				{
					cout << "Введите элемент : ";
					cin >> element;
					cout << endl;
					stack->push(element);
					break; 
				}

				case 2: 
				{
					cout << "Введите количество элементов: ";
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
					cout << "Введите количество удаляемых элементов: ";
					cin >> count;

					stack->MultiPop(count);

					break;
				}
				case 5:
				{
					if (stack->isEmpty()) {
						cout << endl << "Стек не пуст" << endl << endl;
					}
					else {
						cout << endl << "Стек пуст" << endl << endl;
					}
					break;
				}
				case 6: 
				{
					if (stack->isEmpty()) {
						cout << stack->ToString() << endl;
					}
					else {
						cout << "Стек пуст" << endl;
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
					cout << "Неверная команда, попробуйте еще раз" << endl; 
				}
			}
		}
		catch (ContainerException& ex) {
			cout << ex.GetError() << endl;
		}
	}

	delete stack;
}



