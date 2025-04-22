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
	std::cout << endl << "Привет, " << name << "!\n";
} // Функция ввода и вывода имени 

void arithmetic() {

	float a, b;
	string input;

	// Ввод первого числа
	while (true) {

		std::cout << endl << "Введите первое число: ";
		cin >> input;

		if (isInt(input)) {
			a = stringToInt(input);
			break;
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
			break;
		}
		else {
			cout << "Некорректное значение.\n";
		}
	}

	// Вывод результатов
	std::cout << endl << "Результат сложения: " << a + b << ";\n";
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
		std::cout << "Введите 'b': ";
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
		std::cout << endl << "Введите 'c': ";
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
		std::cout << "x = " << -c / b << endl;
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
		std::cout << "Введите 'a': ";
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
		std::cout << "Введите 'b': ";
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
		std::cout << "Введите 'c': ";
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
		std::cout << endl << "Нет рациональных корней.\n";
	}
	else {
		x1 = (-b + sqrt(d)) / 2 * a;
		x2 = (-b - sqrt(d)) / 2 * a;
		if (x1 == x2) {
			std::cout << endl << "Оба корня равны: " << x1 << endl;
		}
		else {
			std::cout << endl << "Первый корень равен: " << x1 << endl;
			std::cout << endl << "Второй корень равен: " << x2 << endl;
		}
	}

}

void lampWithCurtain() {
	bool isDay, curtainsCondition, lampCondition;
	string d, c, l;

	while (true) {
		std::cout << endl << "На улице день? (да/нет) \n"; //Проверка, день ли на улице
		cin >> d;
		if ((d == "да")(d == "нет")) {
			if ((d == "да")) {
				isDay = 1;
			}
			else {
				isDay = 0;
			}
			break;
		}
		else {
			std::cout << endl << "Введите Да/Нет\n";
		}
	}

	while (true) {
		std::cout << endl << "Задёрнуты ли шторы? (да/нет) \n"; //Проверка закрыты ли шторы
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
		std::cout << endl << "Лампа включена? (да/нет)\n"; //Проверка включена ли лампа
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
		std::cout << endl << "В комнате светло!\n";
	}
	else {
		std::cout << endl << "В комнате темно\n";
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
		cout << "5. 'Лампа со шторой' \n";
		cout << "6. Справка \n";
		cout << "0. Выход.\n" << endl;


		int forSwitch = autoInput();

		switch (forSwitch) {
		case 0:
			cout << endl;
			std::cout << "Выход из программы...";
			return 0;

		case 1: // Первая функция
			cout << endl;
			std::cout << "Вы вызвали функцию 'Имя'\n";
			name();
			cout << endl;
			break;

		case 2: // Вторая функция
			cout << endl;
			std::cout << "Вы вызвали функцию 'Арифметика'\n";
			arithmetic();		
			cout << endl;
			break;

		case 3: // Третья функция
			cout << endl;
			std::cout << "Вы вызвали функцию 'Уравнение'\n";
			equation();
			cout << endl;

			break;

		case 4: // Четвертая функция
			cout << endl;
			std::cout << "Вы вызвали функцию 'Ещё Уравнение'\n";
			oneMoreEquation();
			cout << endl;

			break;

		case 5: // Пятая функция
			cout << endl;
			std::cout << "Вы вызвали функцию 'Лампа со шторой\n'";
			lampWithCurtain();
			cout << endl;

			break;

		case 6: // Помощь
			cout << endl;

			std::cout << "Справка: \nФункция 'Имя' запрашивает Ваше имя, затем приветствует Вас. \nФункция 'Арифметика' запрашивает на ввод два числа, затем выводит сумму, разность, произведение и, если возможно частное.";
			std::cout << "Функция 'Уравнение' запрашивает на ввод два числа, b и c, затем находит x в уравнении bx + c = 0. \nФункция 'Ещё уравнение' запрашивает на ввод три числа, a, b, c, затем, находит корни уравнения ax^2 + bx + c = 0.";
			std::cout << "Функция 'Лампа со шторой' спрашивает день ли на улице, закрыты ли шторы, включена ли лампа, после чего отвечает на вопрос светло ли в комнате\n";
			cout << endl;

			break;

		default:
			std::cout << endl << "Некорректное значение.\n\n";
			break;
		}
	}
}

