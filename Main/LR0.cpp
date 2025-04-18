#include <iostream>
#include <windows.h> //Для изменения кодировки Windows 
#include <string>
#include <cmath>
using namespace std;

void name() {
	string name;
	std::cout << "Введите свое имя : ...\n"; //Вывод на экран
	cin >> name;
	std::cout << "Привет, " << name << "!\n";
}

void arithmetic() {

	float a, b;
	string c, d;

	// Ввод первого числа
	while (true) {

		std::cout << "Введите первое число: ";
		cin >> c;

		try {
			a = stof(c); // Конвертируем строку в число
			break; // Если ввод корректный, выходим из цикла
		}
		catch (...) {
			std::cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}

	// Ввод второго числа
	while (true) {

		std::cout << "Введите второе число: ";
		cin >> d;

		try {
			b = stof(d); // Конвертируем строку в число
			break; // Если ввод корректный, выходим из цикла
		}
		catch (...) {
			std::cout << "Ошибка: Введите корректное числовое значение.\n";
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
}

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
			std::cout << "Ошибка: Введите корректное числовое значение.\n";
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
			std::cout << "Ошибка: Введите корректное числовое значение.\n";
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
			std::cout << "Ошибка: Введите корректное числовое значение.\n";
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
			std::cout << "Ошибка: Введите корректное числовое значение.\n";
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
			std::cout << "Ошибка: Введите корректное числовое значение.\n";
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
		std::cout << "Задёрнуты ли шторы?\n"; //Проверка закрыты ли шторы
		cin >> c;
		if ((c == "Да") or (c == "да") or (c == "Д") or (c == "д") or (c == "Нет") or (c == "нет") or (c == "Н") or (c == "н")) {
			if ((c == "Да") or (c == "да") or (c == "Д") or (c == "д")) {
				curtainsCondition = 1;
			}
			else {
				curtainsCondition = 0;
			}
			break;
		}
		else {
			std::cout << "Введите Да/Нет\n";
		}
	}

	while (true) {
		std::cout << "Лампа включена?\n"; //Проверка включена ли лампа
		cin >> l;
		if ((l == "Да") or (l == "да") or (l == "Д") or (l == "д") or (l == "Нет") or (l == "нет") or (l == "Н") or (l == "н")) {
			if ((l == "Да") or (l == "да") or (l == "Д") or (l == "д")) {
				lampCondition = 1;
			}
			else {
				lampCondition = 0;
			}
			break;
		}
		else {
			std::cout << "Введите Да/Нет\n";
		}
	}

	if ((isDay == 1 and curtainsCondition == 0) or lampCondition == 1) {
		std::cout << "В комнате светло!\n";
	}
	else {
		std::cout << "В комнате темно\n";
	}
}

int forSwitch(string input) {

	int newInput;
	try {
		return newInput = stoi(input);
	}
	catch (...) {
		if (input == "Имя") {
			return newInput = 1;
		}
		else if (input == "Арифметика") {
			return newInput = 2;
		}
		else if (input == "Уравнение") {
			return newInput = 3;
		}
		else if (input == "Ещё уравнение") {
			return newInput = 4;
		}
		else if (input == "Лампа со шторой") {
			return newInput = 5;
		}
		else if ((input == "help") or (input == "?")) {
			return newInput = 6;
		}
		else if (input == "exit") {
			return newInput = 0;
		}
		else {
			return newInput = 7;
		}
	}

}

int ZeroLaba()
{
	SetConsoleOutputCP(1251); //Позволяет выводить консоли русский текст адекватно
	SetConsoleCP(1251); //Делает ввод с клавиатуры на русском адекватным 
	std::cout << "Добро пожаловать в набор программ нулевой лабораторной! \nДля обращения к функциям наберите порядковый номер задачи или укажите её название.\n";


	while (true) {
		string input;
		int* newInput = new int;


		getline(cin, input);
		*newInput = forSwitch(input);
		switch (*newInput) {
		case 0:
			std::cout << "Выход из программы...";
			return 0;
		case 1: // Первая функция
			std::cout << "Вы вызвали функцию 'Имя'\n";
			name();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите '?' или 'help'.\nДля выхода напишите 'exit'. \n";
			break;
		case 2: // Вторая функция
			std::cout << "Вы вызвали функцию 'Арифметика'\n";
			arithmetic();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите '?' или 'help'.\nДля выхода напишите 'exit'. \n";
			break;
		case 3: // Третья функция
			std::cout << "Вы вызвали функцию 'Уравнение'\n";
			equation();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите '?' или 'help'.\nДля выхода напишите 'exit'. \n";
			break;
		case 4: // Четвертая функция
			std::cout << "Вы вызвали функцию 'Ещё Уравнение'\n";
			oneMoreEquation();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите '?' или 'help'.\nДля выхода напишите 'exit'. \n";
			break;
		case 5: // Пятая функция
			std::cout << "Вы вызвали функцию 'Лампа со шторой\n'";
			lampWithCurtain();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите '?' или 'help'.\nДля выхода напишите 'exit'. \n";
			break;
		case 6: // Помощь
			std::cout << "Справка: \nФункция 'Имя' запрашивает Ваше имя, затем приветствует Вас. \nФункция 'Арифметика' запрашивает на ввод два числа, затем выводит сумму, разность, произведение и, если возможно частное.";
			std::cout << "Функция 'Уравнение' запрашивает на ввод два числа, b и c, затем находит x в уравнении bx + c = 0. \nФункция 'Ещё уравнение' запрашивает на ввод три числа, a, b, c, затем, находит корни уравнения ax^2 + bx + c = 0.";
			std::cout << "Функция 'Лампа со шторой' спрашивает день ли на улице, закрыты ли шторы, включена ли лампа, после чего отвечает на вопрос светло ли в комнате\n";
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите '?' или 'help'.\nДля выхода напишите 'exit'. \n";
			break;
		case 7:
			std::cout << "Введите корректную команду.\n";
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите '?' или 'help'.\nДля выхода напишите 'exit'. \n";
			break;
		}
	}
}

