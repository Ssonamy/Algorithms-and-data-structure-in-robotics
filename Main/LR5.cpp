#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

//Определение целочисленности числа
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

//Перевод из строки в число
int INTj() {
	while (true) {
		string number;
		int num;

		cout << "Введите число:" << endl;
		cin >> number;
		if (isInt(number)) {
			return num = stoi(number);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}
}

void del(vector<int>& vec, int num) {
	for (int i = 1; i < sqrt(num); i++) {
		if (num % i == 0) {
			vec.push_back(i);
			vec.push_back(num / i);
		}
	}
}

int fibobnachi(int destination) {
	switch (destination) {
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		return fibobnachi(destination - 1) + fibobnachi(destination - 2);
	}
}

//Нахождение факториала числа
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

//Нахождение наибольшего общего делителя
void NOD() {
	int a, b, max = 0;
	vector<int> delA;
	vector<int> delB;

	//Ввод первого числа
	a = INTj();
	//Создание массива делителей первого числа
	del(delA, a);

	//Ввод второго числа
	b = INTj();
	//Создание массива делителей второго числа
	del(delB, b);

	for (int i : delA) {
		for (int j : delB) {
			if (i == j && max < i) {
				max = i;
			}
		}
	}

	cout << "Наибольший общий делитель чисел " << a << " и " << b << " = " << max << "." << endl;
}

//Проверка числа на простоту
void isPrime() {
	int num;
	num = INTj();
	bool isprime = 1;

	if (num > 0) {
		switch (num) {
		case 1:
			cout << "Число не является простым.\n";
			break;
		case 2:
			cout << "Число является простым.\n";
			break;
		case 3:
			cout << "Число является простым.\n";
			break;
		case 4:
			cout << "Число не является простым.\n";
			break;
		default:
			for (int i = 2; i < sqrt(num); i++)
			{
				if (num % i == 0) {
					isprime = 0;
					break;
				}
			}
			if (isprime) {
				cout << "Число является простым." << endl;
			}
			else {
				cout << "Число не является простым." << endl;
			}
		}
	}
}

//Проверка строки на то, является ли она палиндромом
void palindrome() {
	string str, rts;

	cout << "Введите строку:" << endl;
	cin >> str;

	//Разворот строки
	for (int i = str.size() - 1; i >= 0; --i) {
		rts += str[i];
	}

	if (rts == str) {
		cout << "Строка является палиндромом." << endl;
	}
	else {
		cout << "Строки не являются палиндромами." << endl << "Введенная строка:" << endl << str << endl << "Развернутая строка:" << rts << endl;
	}
}

//Вычисление ряда Фибобначи
void fibonacciNumbers() {
	int destination;
	cout << "Введите до какого числа будет вычисляться ряд" << endl;
	destination = INTj();
	cout << "Последовательность Фибоначчи: ";
	for (int i = 0; i < destination; i++) {
		cout << fibobnachi(i) << " ";
	}
	cout << endl;
}

//Вызов справки
void hepl() {
	cout << "Список команд:" << endl;
	cout << "1. Факториал -- запрашивает у пользователя на ввод число, после чего выводит факториал этого числа" << endl;
	cout << "2. Наибольший общий делитель -- запрашивает на ввод пользователя два целых числа, затем выводит наибольший общий делитель двух этих чисел." << endl;
	cout << "3. Простое число -- запрашивает на ввод Целое число, затем выводит является ли это число простым." << endl;
	cout << "4. Палиндром -- запрашивает на ввод пользователя строку, затем выводит является ли эта строка палиндромом." << endl;
	cout << "5. Ряд Фибоначи -- запрашивает у пользователя число, затем выводит столько элементов ряда фибоначи" << endl;
	cout << "6. Помощь -- вызывает этот список." << endl;
}

//Перевод команд в числа, для работы переключателя в мэйне
int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		num = stoi(input);
		return num;
	}
	else {
		if (input == "Факториал") {
			return 1;
		}
		else if (input == "НОД" || input == "Наибольший общий делитель") {
			return 2;
		}
		else if (input == "Простое число") {
			return 3;
		}
		else if (input == "Палиндром") {
			return 4;
		}
		else if (input == "Ряд Фибоначи") {
			return 5;
		}
		else if (input == "Помощь") {
			return 6;
		}
		else if (input == "Выход") {
			return 0;
		}
		else if (input == "") {
			return -1;
		}
	}

	return num = 6;
}

int FifthLaba()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Вы запустили сборник функций лабораторной №5.\nДля обращения к функциям наберите порядковый номер задачи или укажите её название.\nДля вызова справки введите 'Помощь'.\nДля выхода введите 'Выход'." << endl;

	while (true) {

		string input;
		int* newInput = new int;
		getline(cin, input);
		*newInput = forSwitch(input);

		switch (*newInput) {
		case -1:
			continue;
		case 0:
			cout << "Выход из программы...";
			return 0;
		case 1:
			cout << "Факториал" << endl;
			factorial();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 2:
			cout << "Наибольший общий делитель" << endl;
			NOD();
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
			cout << "Палиндром" << endl;
			palindrome();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 5:
			cout << "Ряд Фибоначи" << endl;
			fibonacciNumbers();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 6:
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
}
