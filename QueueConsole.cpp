#include <iostream>
#include <iterator>
#include <string>
#include "Queue.h"
#include "QueueConsole.h"
#include "ContainerException.h"

using namespace std;

void QueueConsole::Actions() {
	setlocale(LC_ALL, "Russian");
	cout << "1. push -> ���������� �������� � ����� �����" << endl;
	cout << "2. multi_push -> ���������� ���������� ��������� � ����� �����" << endl;
	cout << "3. pop -> �������� ������� �������� �����" << endl;
	cout << "4. multi_pop -> ���������� �������� � ����� �����" << endl;
	cout << "5. Empty -> �������� ����� �� ������� ���������" << endl;
	cout << "6. printQueue -> ����� �����" << endl;
	cout << "7. back -> ��������� ���������� �������� �����" << endl;
	cout << "8. front -> ������ �������" << endl;
	cout << "9. cls -> �������� ��������� ����" << endl;
	cout << "10. help -> ������ ������" << endl;
	cout << "0. exit -> ����� �� ���������" << endl;
}


int QueueConsole::InputSize() {
	int size;
	cout << "������ �������: ";
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
			cout << endl << "������� �������: ";
			cin >> action;

			switch (action) {
			case 1:
			{
				cout << "������� ������� : ";
				cin >> element;
				cout << endl;
				queue.Push(element);
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
				cout << "������� ���������� ��������� ���������: ";
				cin >> count;

				queue.MultiPop(count);

				break;
			}
			case 5:
			{
				if (queue.Empty()) {
					cout << endl << "���� ����" << endl << endl;
				}
				else {
					cout << endl << "���� �� ����" << endl << endl;
				}
				break;
			}
			case 6:
			{
				if (!queue.Empty()) {
					cout << queue.ToString() << endl;
				}
				else {
					cout << "���� ����" << endl;
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
				cout << "�������� �������, ���������� ��� ���" << endl;
			}
			}
		}
		catch (ContainerException& ex) {
			cout << ex.GetError() << endl;
		}
	}
}



