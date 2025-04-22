#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"

using namespace std;

void arrayElements() {
	string input;
	int* arr = nullptr;
	int size = 0;

	cout << "Введите числа через пробел:" << endl;
	getline(cin, input);

	stringstream ss(input);
	int temp;

	while (ss >> temp) {
		size++;  // Увеличиваем размер массива
	}
	arr = new int[size]; // Выделяем память для массива

	ss.clear();
	ss.str(input);

	for (int i = 0; i < size; i++) {
		ss >> arr[i]; // Заполняем массив
	}

	cout << "Массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;
	cout << endl;
}

void sum4() {
	string input;
	int* arr = nullptr;
	int size = 0;
	int s = 0;

	cout << "Введите числа через пробел:" << endl;
	getline(cin, input);

	stringstream ss(input);
	int temp;

	while (ss >> temp) {
		size++;  // Увеличиваем размер массива
	}
	arr = new int[size]; // Выделяем память для массива

	ss.clear();
	ss.str(input);

	for (int i = 0; i < size; i++) {
		ss >> arr[i]; // Заполняем массив
	}

	cout << "Сумма элементов массива:" << endl;
	for (int i = 0; i < size; i++)
	{
		s += arr[i];
	}

	cout << s << endl;
	delete[] arr;
}

void transposition() {
	int rows, cols;

	cout << "Введите количество строк" << endl;
	rows =autoInput();

	int** matrix = new int* [rows];

	cout << "Введите количество столбцов" << endl;
	cols =autoInput();
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	// Инициализация матрицы
	cout << "Введите элементы матрицы:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

	int** transMatrix = new int* [cols]; // Создаем новый двумерный массив
	for (int i = 0; i < cols; i++) {
		transMatrix[i] = new int[rows];
	}

	// Транспонируем матрицу
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transMatrix[j][i] = matrix[i][j];
		}
	}

	// Вывод транспонированной матрицы
	cout << "Транспонированная матрица:" << endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << transMatrix[i][j] << " ";
		}
		cout << endl;
	}

	// Освобождаем память
	for (int i = 0; i < cols; i++) {
		delete[] transMatrix[i];
	}
	delete[] transMatrix;
}

void dotProduct() {
	while (true) {
		string input1, input2;
		int* arr1 = nullptr;
		int* arr2 = nullptr;
		int size1 = 0, size2 = 0;
		int s = 0;

		cout << "Первый массив." << endl;
		cout << "Введите числа через пробел:" << endl;
		getline(cin, input1);

		//Ввод первого массива
		stringstream ss1(input1);
		int temp;
		while (ss1 >> temp) {
			size1++;  // Увеличиваем размер массива
		}
		arr1 = new int[size1]; // Выделяем память для массива

		ss1.clear();
		ss1.str(input1);
		for (int i = 0; i < size1; i++) {
			ss1 >> arr1[i]; // Заполняем массив
		}

		//Ввод второго массива
		cout << "Второй массив." << endl;
		cout << "Введите числа через пробел:" << endl;
		getline(cin, input2);

		stringstream ss2(input2);
		while (ss2 >> temp) {
			size2++;  // Увеличиваем размер массива
		}
		arr2 = new int[size2]; // Выделяем память для массива

		ss2.clear();
		ss2.str(input2);
		for (int i = 0; i < size2; i++) {
			ss2 >> arr2[i]; // Заполняем массив
		}

		// Проверяем равенство размеров массивов
		if (size1 == size2) {
			// Вычисляем скалярное произведение
			for (int i = 0; i < size1; ++i) {
				s += arr1[i] * arr2[i];
			}
			cout << "Скалярное произведение двух векторов = " << s << "." << endl;

			// Освобождаем память
			delete[] arr1;
			delete[] arr2;
			break;
		}
		else {
			cout << "Количество координат векторов не равно. Введите корректные координаты." << endl;

			// Освобождаем память перед повторным вводом
			delete[] arr1;
			delete[] arr2;
		}
	}

}

void hepl4() {
	cout << "Список команд:\n1. Элементы массива -- запрашивает на ввод пользователя массив целых чисел, которые впоследствии записывает в массив и выводит его." << endl;
	cout << "2. Сумма -- запрашивает на ввод пользователя массив целых чисел, которые впоследствии записывает в массив и выводит сумму его элементов." << endl;
	cout << "3. Транспонирование -- запрашивает на ввод количество строк и столбцов матрицы, после чего пользователь вводит элементы матрицы, которую функция транспонирует." << endl;
	cout << "4. Скалярное произведение -- Запрашивает на ввод пользователя два массива целых чисел одного размера, после чего выводит скалярное произведение этих массивов." << endl;
	cout << "5. Помощь -- " << endl;
}

int FourhtLaba()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Вы запустили сборник функций лабораторной номер 4." << endl;
	cout << "Введите:" << endl;
	cout << "1.'Элементы массива'" << endl;
	cout << "2.'Сумма'" << endl;
	cout << "3.'Транспонирование'" << endl;
	cout << "4.'Скалярное произведение'" << endl;
	cout << "5. Справка" << endl;
	cout << "0. Выход" << endl;
	while (true) {

		int forSwitch = autoInput();
		switch (forSwitch) {
		case 0:
			cout << "Выход из программы...";
			return 0;

		case 1:
			cout << "Элементы массива" << endl;
			arrayElements();
			break;

		case 2:
			cout << "Сумма" << endl;
			sum4();
			break;

		case 3:
			cout << "Транспонирование" << endl;
			transposition();
			break;

		case 4:
			cout << "Скалярное произведение" << endl;
			dotProduct();
			break;

		case 5:
			cout << "Справка" << endl;
			hepl4();
			break;

		default:
			cout << "Введите корректную команду.\n";
			break;
		}
	}
	return 0;
}