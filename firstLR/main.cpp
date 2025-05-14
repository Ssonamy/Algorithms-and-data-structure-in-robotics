#include <iostream>
#include <string>
#include "functions.h"
#include "console_init.h"

using namespace std;

int main() 
{
	initConsole();
	string input;

	cout << "_________________________________________________________\n";
	cout << "Добро пожаловать в программу выбора решения лабораторной:\n";
	cout << "_________________________________________________________\n";


	//По мере выполнения буду добавлять варианты выбора

	while (true)
	{
		cout << "Введите:\n";
		cout << "1. Лабораторная номер 1: Сортировка.\n";
		cout << "2. Лабораторная номер 2: Класс File (Упрощенный).\n";
		cout << "3. Лабораторная номер 2: Класс Rectangle (Прямоугольник).\n";
		cout << "4. Лабораторная номер 3: Небесная карта\n";

		cout << "0. Выход\n" << endl;

		int forSwitch = autoInt();


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

		case 4:
			cout << endl;
			if (thirdLrVar6())
				return 0;
			cout << endl;
			break;

		// тест локали и может чего то ещё в будущем
		case -1351:
			std::cout << "Версия С++: " << __cplusplus << std::endl;
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