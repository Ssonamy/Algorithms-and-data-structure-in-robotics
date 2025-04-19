#include <iostream>
#include <windows.h> //Для изменения кодировки Windows 
#include <string>
#include <cmath>
#include "functions.h"

using namespace std;

void name() {
	string name;
	std::cout << "Введите свое имя : ...\n"; //Вывод на экран
	cin >> name;
	std::cout << "Привет, " << name << "!\n";
} // Функция ввода и вывода имени 

void arithmetic() {

	float a, b;
	string input;

	// Ввод первого числа
	while (true) {

		std::cout << "Введите первое число: ";
		cin >> input;

		if (isInt(input)) {
			a = stringToInt(input);
		}
		else {
			cout << "Некорректное значение.\n";
		}
	}

	// Ввод второго числа
	while (true) {

		std::cout << "Введите второе число: ";
		cin >> input;

		if (isInt(input)) {
			b = stringToInt(input);
		}
		else {
			cout << "Некорректное значение.\n";
		}
	}

	// Вывод результатов
	std::cout << "Результат сложения: " << a + b << ";\n";
	std::cout << "Результат вычитания: " << a - b << ";\n";
	std::cout << "Результат умножения: " << a * b << ";\n";

	// Проверка деления на ноль
	if (b != 0) {
		std::cout << "Результат деления: " << a / b << '\n';
	}
	else {
		std::cout << "Ошибка: деление на ноль невозможно.\n";
	}
} // Нахождение всех возможных случаев вычислений а и б 

void equation() {
	float b, c;
	string initialC, initialB;

	// Ввод b
	while (true) {
		std::cout << "Введите 'b':";
		cin >> initialB;
		try {
			b = stof(initialB);
			break;
		}
		catch (...) {
			std::cout << "Некорректное значение.\n";
		}
	}

	// Ввод c
	while (true) {
		std::cout << "Введите 'c':";
		cin >> initialC;
		try {
			c = stof(initialC);
			break;
		}
		catch (...) {
			std::cout << "Некорректное значение.\n";
		}
	}
	if (b != 0) {
		std::cout << "x = " << -c / b;
	}
	else {
		std::cout << "х невозможно определить.\n";
	}

}

void oneMoreEquation() {

	float a, b, c, d, x1, x2;
	string initialA, initialB, initialC;

	// Ввод а
	while (true) {
		std::cout << "Введите 'a':";
		cin >> initialA;
		try {
			a = stof(initialA);
			break;
		}
		catch (...) {
			std::cout << "Некорректное значение\n";
		}
	}

	// Ввод b
	while (true) {
		std::cout << "Введите 'b':";
		cin >> initialB;
		try {
			b = stof(initialB);
			break;
		}
		catch (...) {
			std::cout << "Некорректное значение\n";
		}
	}

	// Ввод c
	while (true) {
		std::cout << "Введите 'c':";
		cin >> initialC;
		try {
			c = stof(initialC);
			break;
		}
		catch (...) {
			std::cout << "Некорректное значение\n";
		}
	}

	d = pow(b, 2) - 4 * a * c;
	if (d < 0) {
		std::cout << "Нет рациональных корней.\n";
	}
	else {
		x1 = (-b + sqrt(d)) / 2 * a;
		x2 = (-b - sqrt(d)) / 2 * a;
		if (x1 == x2) {
			std::cout << "Оба корня равны: " << x1 << endl;
		}
		else {
			std::cout << "Первый корень равен: " << x1 << endl;
			std::cout << "Второй корень равен: " << x2 << endl;
		}
	}

}

void lampWithCurtain() {
	bool isDay, curtainsCondition, lampCondition;
	string d, c, l;

	while (true) {
		std::cout << "На улице день? \n"; //Проверка, день ли на улице
		cin >> d;
		if ((d == "Да") or (d == "да") or (d == "Д") or (d == "д") or (d == "Нет") or (d == "нет") or (d == "Н") or (d == "н")) {
			if ((d == "Да") or (d == "да") or (d == "Д") or (d == "д")) {
				isDay = 1;
			}
			else {
				isDay = 0;
			}
			break;
		}
		else {
			std::cout << "Введите Да/Нет\n";
		}
	}

	while (true) {
		std::cout << "Задёрнуты ли шторы? (да/нет)\n"; //Проверка закрыты ли шторы
		cin >> c;
		if ((c == "да") or (c == "нет")) {
			if ((c == "да")) {
				curtainsCondition = 1;
			}
			else {
				curtainsCondition = 0;
			}
			break;
		}
		else {
			std::cout << "Некорректное значение.\n";
		}
	}

	while (true) {
		std::cout << "Лампа включена? (да/нет)\n"; //Проверка включена ли лампа
		cin >> l;
		if ((l == "да") or (l == "нет")) {
			if ((l == "да")) {
				lampCondition = 1;
			}
			else {
				lampCondition = 0;
			}
			break;
		}
		else {
			std::cout << "Некорректное значение.\n";
		}
	}

	if ((isDay == 1 and curtainsCondition == 0) or lampCondition == 1) {
		std::cout << "В комнате светло!\n";
	}
	else {
		std::cout << "В комнате темно\n";
	}
}

int ZeroLaba()
{
	SetConsoleOutputCP(1251); //Позволяет выводить консоли русский текст адекватно
	SetConsoleCP(1251); //Делает ввод с клавиатуры на русском адекватным 
	std::cout << "Добро пожаловать в набор программ нулевой лабораторной!\n";


	while (true) {
		cout << "Введите:\n";
		cout << "1. 'Имя'\n";
		cout << "2. 'Арифметика'\n";
		cout << "3. 'Уравнение'\n";
		cout << "4. 'Еще уравнение'\n";
		cout << "5. 'Лампа со шторой'\n";
		cout << "6. Справка \n";
		cout << "0. Выход.\n";


		int forSwitch = autoInput();

		switch (forSwitch) {
		case 0:
			std::cout << "Выход из программы...";
			return 0;

		case 1: // Первая функция
			std::cout << "Вы вызвали функцию 'Имя'\n";
			name();
			break;

		case 2: // Вторая функция
			std::cout << "Вы вызвали функцию 'Арифметика'\n";
			arithmetic();
			break;

		case 3: // Третья функция
			std::cout << "Вы вызвали функцию 'Уравнение'\n";
			equation();
			break;

		case 4: // Четвертая функция
			std::cout << "Вы вызвали функцию 'Ещё Уравнение'\n";
			oneMoreEquation();
			break;

		case 5: // Пятая функция
			std::cout << "Вы вызвали функцию 'Лампа со шторой\n'";
			lampWithCurtain();
			break;

		case 6: // Помощь
			std::cout << "Справка: \nФункция 'Имя' запрашивает Ваше имя, затем приветствует Вас. \nФункция 'Арифметика' запрашивает на ввод два числа, затем выводит сумму, разность, произведение и, если возможно частное.";
			std::cout << "Функция 'Уравнение' запрашивает на ввод два числа, b и c, затем находит x в уравнении bx + c = 0. \nФункция 'Ещё уравнение' запрашивает на ввод три числа, a, b, c, затем, находит корни уравнения ax^2 + bx + c = 0.";
			std::cout << "Функция 'Лампа со шторой' спрашивает день ли на улице, закрыты ли шторы, включена ли лампа, после чего отвечает на вопрос светло ли в комнате\n";
			break;

		default:
			std::cout << "Некорректное значение.\n\n";
			break;
		}
	}
}

