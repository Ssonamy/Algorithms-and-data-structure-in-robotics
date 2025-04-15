#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"

using namespace std;

int firstLR()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char switch_on;

	cout << "_______________________________________\n";
	cout << "Добро пожаловать в программу сортировки.\n";
	cout << "Введите:\n";
	cout << "1. Сортировка пузырьком.\n";
	cout << "2. Сортировка вставками.\n";
	cout << "2. Сортировка слиянием.\n";
	cout << "_______________________________________\n";
	cout << "Введите:";
	cin >> switch_on;

	//switch (switch_on)
	//{
	//case 1:
	//	cout << "все норм";
	//	break;
	//default:
	//	cout << "ты лох";
	//	break;
	//}
	return 0;
}