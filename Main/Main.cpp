#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
	//SetConsoleCP(CP_UTF8);
	SetConsoleCP(1251);
	//SetConsoleOutputCP(CP_UTF8);
	SetConsoleOutputCP(1251);


	string input;
	int forSwitch;

	cout << "_______________________________________\n";
	cout << "Добро пожаловать в программу выбора решения лабораторной:\n";


	//По мере выполнения буду добавлять варианты выбора

	while (true)
	{
		cout << "_______________________________________\n";
		cout << "Введите:\n";
		cout << "0. Лабораторная номер 0: 'Вводный сборник заданий'.\n";
		cout << "1. Лабораторная номер 1: 'Поиск и сортировка'.\n";
		cout << "2. Лабораторная номер 2: ''.\n";
		cout << "3. Лабораторная номер 3: ''.\n";
		cout << "4. Лабораторная номер 4: ''.\n";
		cout << "5. Лабораторная номер 5: ''.\n";
		cout << "6. Лабораторная номер 6: ''.\n";
		cout << "7. Лабораторная номер 7: ''.\n";
		cout << "-1. Выход\n";
		cout << "_______________________________________\n" << endl;

		forSwitch = autoInput();

		switch (forSwitch)
		{
		case 0:
			cout << endl;
			ZeroLaba();
			cout << endl <<endl;
			break;

		case 1:
			cout << endl;
			FirstLaba();
			cout << endl << endl;
			break;

		case 2:
			cout << endl;
			SecondLaba();
			cout << endl << endl;
			break;

		case 3:
			cout << endl;
			ThirdLaba();
			cout << endl << endl;
			break;

		case 4:
			cout << endl;
			FourhtLaba();
			cout << endl << endl;
			break;

		case 5:
			cout << endl;
			FifthLaba();
			cout << endl << endl;
			break;

		case 6:
			cout << endl;
			SixthLaba();
			cout << endl << endl;
			break;

		case 7:
			cout << endl;
			SeventhLaba();
			cout << endl << endl;
			break;

		case -1:
			cout << endl;
			cout << "Выход...\n";
			cout << endl << endl;
			return 0;

		case -1351:

			//тест вывода и ввода символов
			cin >> input;
			cout << input << endl << endl;
			return 0;

		default:
			cout << endl;
			cout << "Введите корректное значение.\n";
			cout << endl;
			break;
		}
	}

	return 0;
}