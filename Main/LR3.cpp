#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include "functions.h"

using namespace std;

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
			cout << "Некорректное значение.\n";
		}
	}
	cout << "Таблица умножения числа " << num << ".\n";
	for (int i = 1; i <= 10; i++) {
		cout << num << " * " << i << " = " << num * i << endl;

	}
}

void sum3() {
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
			cout << "Некорректное значение\n";
		}
	}
	int s = 0;
	for (int i = 1; i <= num; i++) {
		s = s + i;
	}
	cout << "Сумма чисел от 1 до " << num << " = " << s << endl;
}

void isPrime3() {
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
			cout << "Некорректное значение\n";
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

void factorial3() {
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
			cout << "Некорректное значение\n";
		}
	}

	long long s = 1;
	for (int i = 2; i <= num; i++) {
		s *= i;
	}

	cout << "Факториал " << num << " = " << s << endl;
}

void hepl3() {
	cout << "Список команд:\n1. Таблица умножения -- при вводе числа пользователем, функция выводит число умноженное на числа от 1 до 10." << endl;
	cout << "2. Сумма -- при вводе числа пользователем, функция выводит сумму всех чисел от 1 до N, где N -- ввод пользователя." << endl;
	cout << "3. Простое число -- при вводе числа пользователем, функция выводит, является ли число простым." << endl;
	cout << "4. Факториал -- при вводе числа пользователем, функция находит факториал введенного числа." << endl;
	cout << "5. Помощь -- " << endl;
}

int ThirdLaba() {
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	while (true) {

		cout << "Вы запустили сборник функций лабораторной номер 3." << endl;
		cout << "Введите:" << endl;
		cout << "1. 'Таблица умножения'" << endl;
		cout << "2. 'Сумма'" << endl;
		cout << "3. 'Простое число'" << endl;
		cout << "4. 'Факториал'" << endl;
		cout << "5. Спарвка" << endl;
		cout << "0. Выход." << endl;

		int forSwitch = autoInput();

		switch (forSwitch) {
		case 0:
			cout << "Выход из программы...";
			return 0;
		case 1:
			cout << "Таблица умножения" << endl;
			multiplication();
			break;
		case 2:
			cout << "Сумма" << endl;
			sum3();
			break;
		case 3:
			cout << "Простое число" << endl;
			isPrime3();
			break;
		case 4:
			cout << "Факториал" << endl;
			factorial3();
			break;
		case 5:
			cout << "Справка" << endl;
			hepl3();
			break;

		default:
			cout << "Введите корректную команду.\n";
			break;
		}

	}

	return 0;
}
