#include <iostream>
#include <iterator>
#include <string>
#include "Queue.h"
#include "QueueConsole.h"
#include "ContainerException.h"

using namespace std;

void QueueConsole::Actions() {
	setlocale(LC_ALL, "Russian");
	cout << "1. push -> Добавление элемента в конец стека" << endl;
	cout << "2. multi_push -> Добавление нескольких элементов в конец стека" << endl;
	cout << "3. pop -> Удаление первого элемента стека" << endl;
	cout << "4. multi_pop -> Добавление элемента в конец стека" << endl;
	cout << "5. Empty -> Проверка стека на наличие элементов" << endl;
	cout << "6. printQueue -> Вывод стека" << endl;
	cout << "7. back -> Получение последнего элемента стека" << endl;
	cout << "8. front -> Первый элемент" << endl;
	cout << "9. cls -> Очистить командное окно" << endl;
	cout << "10. help -> Список команд" << endl;
	cout << "0. exit -> Выход из программы" << endl;
}


int QueueConsole::InputSize() {
	int size;
	cout << "Размер очереди: ";
	cin >> size;
	cout << endl;
	return size;
}

void QueueConsole::InputAction() {
	setlocale(LC_ALL, "Russian");
	int count;
	int action = -1;
	string element;
	string type = "";
	
	Queue queue(InputSize());

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
				queue.Push(element);
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
				queue.MultiPush(count, elements);
				break;
			}
			case 3:
			{
				cout << endl;

				queue.Pop();
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "Введите количество удаляемых элементов: ";
				cin >> count;

				queue.MultiPop(count);

				break;
			}
			case 5:
			{
				if (queue.Empty()) {
					cout << endl << "Стек пуст" << endl << endl;
				}
				else {
					cout << endl << "Стек не пуст" << endl << endl;
				}
				break;
			}
			case 6:
			{
				if (!queue.Empty()) {
					cout << queue.ToString() << endl;
				}
				else {
					cout << "Стек пуст" << endl;
				}
				break;

			}
			case 7:
			{
				cout << endl << "[" << queue.Back() << "]" << endl << endl;
				break;
			}
			case 8:
			{
				cout << endl << "[" << queue.Front() << "]" << endl << endl;
				break;
			}
			case 9:
			{
				system("cls");
				break;
			}
			case 10:
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
}



