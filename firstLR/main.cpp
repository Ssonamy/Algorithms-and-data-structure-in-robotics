#include <iostream>
//#include <windows.h>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"
#include <clocale>

using namespace std;

int main() 
{
	//SetConsoleCP(CP_UTF8);
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(CP_UTF8);
	//SetConsoleOutputCP(1251);
	std::setlocale(LC_ALL, "ru_RU.utf8");
	

	string input;

	cout << "_______________________________________\n";
	cout << "Добро пожаловать в программу выбора решения лабораторной:\n";


	//По мере выполнения буду добавлять варианты выбора

	while (true)
	{
		cout << "Введите:\n";
		cout << "1. Лабораторная номер 1: Сортировка.\n";
		cout << "2. Лабораторная номер 2: Класс File (Упрощенный).\n";
		cout << "3. Лабораторная номер 2: Класс Rectangle (Прямоугольник).";

		cout << "0. Выход\n";

		int forSwitch = autoInput();

		switch (forSwitch)
		{
		case 1:
			firstLR();
			break;

		case 2:
			cout << "\n";
			if (secondLrFile()) 
				return 0;
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			if (secondLrRectangle())
				return 0;
			cout << "\n";
			break;

		case 0:
			cout << "Выход...\n";
			return 0;


		// тест локали и может чего то ещё в будущем
		case -1351:
			std::cout << __cplusplus << std::endl;
			cin >> input;
			cout << input << endl << endl;
			return 0;

		default:
			cout << "Некорректное значение.\n";

			break;
		}
	}

	return 0;
}