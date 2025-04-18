#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
using namespace std;

bool isInt(string x) {
	bool e;
	try {
		int num = stoi(x);
		return e = 1;
	}
	catch (...) {
		return e = 0;
	}

} // функция, определяющая является ли ввод числом 

void multiplication() {
	int num;
	while (true) {
		string number;

		cout << "Введите число:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}
	cout << "Таблица умножения числа " << num << ".\n";
	for (int i = 1; i <= 10; i++) {
		cout << num << " * " << i << " = " << num * i << endl;

	}
}

void sum() {
	int num;
	while (true) {
		string number;

		cout << "Введите число:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}
	int s = 0;
	for (int i = 1; i <= num; i++) {
		s = s + i;
	}
	cout << "Сумма чисел от 1 до " << num << " = " << s << endl;
}

void isPrime() {
	int num;
	while (true) {
		string number;

		cout << "Введите число:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			if (num > 0) {
				break;
			}
			else {
				"Введите число больше нуля.\n";
			}
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}
	switch (num) {
	case 1:
		cout << "Число не является простым.\n";
	case 2:
		cout << "Число является простым.\n";
	case 3:
		cout << "Число является простым.\n";
	default:
		for (int i = 2; i < sqrt(num); i++)
		{
			if (num % i == 0) {
				cout << "Число не является простым." << endl;
				break;
			}
			else {
				cout << "Число является простым." << endl;
				break;
			}
		}

	}
}

void factorial() {
	int num;
	while (true) {
		string number;
		cout << "Введите число:" << endl;
		cin >> number;

		if (isInt(number)) {
			num = stoi(number);
			if (num < 0) {
				cout << "Ошибка: Факториал не определён для отрицательных чисел.\n";
			}
			else if (num > 20) {
				cout << "Ошибка: Число слишком большое для расчёта факториала.\n";
			}
			else {
				break;
			}
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}

	long long s = 1;
	for (int i = 2; i <= num; i++) {
		s *= i;
	}

	cout << "Факториал " << num << " = " << s << endl;
}

void hepl() {
	cout << "Список команд:\n1. Таблица умножения -- при вводе числа пользователем, функция выводит число умноженное на числа от 1 до 10." << endl;
	cout << "2. Сумма -- при вводе числа пользователем, функция выводит сумму всех чисел от 1 до N, где N -- ввод пользователя." << endl;
	cout << "3. Простое число -- при вводе числа пользователем, функция выводит, является ли число простым." << endl;
	cout << "4. Факториал -- при вводе числа пользователем, функция находит факториал введенного числа." << endl;
	cout << "5. Помощь -- " << endl;
}

int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		return num = stoi(input);
	}
	else {
		if (input == "Умножение") {
			return num = 1;
		}
		else if (input == "Сумма") {
			return num = 2;
		}
		else if (input == "Простое") {
			return num = 3;
		}
		else if (input == "Факториал") {
			return num = 4;
		}
		else if (input == "Помощь") {
			return num = 5;
		}
		else if (input == "Выход") {
			return num = 0;
		}
	}
}

int ThirdLaba() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Вы запустили сборник функций лабораторной №2.\nДля обращения к функциям наберите порядковый номер задачи или укажите её название.\nДля вызова справки введите 'Помощь'.\nДля выхода введите 'Выход'." << endl;
	while (true) {

		string input;
		int* newInput = new int;
		getline(cin, input);
		*newInput = forSwitch(input);

		switch (*newInput) {
		case 0:
			cout << "Выход из программы...";
			return 0;
		case 1:
			cout << "Таблица умножения" << endl;
			multiplication();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 2:
			cout << "Сумма" << endl;
			sum();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 3:
			cout << "Простое число" << endl;
			isPrime();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 4:
			cout << "Факториал" << endl;
			factorial();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 5:
			cout << "Помощь" << endl;
			hepl();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;

		default:
			cout << "Введите корректную команду.\n";
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		}

	}

	return 0;
}
