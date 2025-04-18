#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"

using namespace std;

int main() 
{
	SetConsoleCP(CP_UTF8);
	//SetConsoleCP(1251);
	SetConsoleOutputCP(CP_UTF8);
	//SetConsoleOutputCP(1251);
	

	string input;
	int forSwitch;

	cout << "_______________________________________\n";
	cout << "Добро пожаловать в программу выбора решения лабораторной:\n";
	cout << "Введите:\n";
	cout << "1. Лабораторная номер 1: Сортировка.\n";

	cout << "0. Выход\n";


	//По мере выполнения буду добавлять варианты выбора

	while (true)
	{
		forSwitch = autoInput();

		switch (forSwitch)
		{
		case 1:
			firstLR();
			break;

		case 0:
			cout << "Выход...\n";
			return 0;

		case -1351:
			cin >> input;
			cout << input << endl << endl;
			return 0;

		default:
			cout << "Введите корректное значение.\n";

			break;
		}
	}

	return 0;
}