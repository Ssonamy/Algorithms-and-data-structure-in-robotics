#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <string>
#include "functions.h"

using namespace std;


// Простой поиск
void simpleSearch() {
	string forVec, input;
	vector<int> vec;
	int num, target, i = 1;
	bool found = 0;

	// ввод массива 
	std::cout << "Введите числа массива через пробел" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // создание потока для обработки строки

	while (ss >> num) { // читаем числа из потока пока читается
		vec.push_back(num);
	}

	std::cout << "Введите искомое число" << endl;
	cin >> input;
	target = stringToInt(input);

	for (int val : vec) {

		if (val == target) {
			std::cout << "Искомое число " << target << " есть в массиве с индексом " << i << "." << endl;
			found = 1;
			break;
		}
		else {
			i++;
		}
	}
	if (!found) {
		std::cout << "Число не найдено." << endl;
	}

}

int binSearch(vector<int> vec, int target) {
	int left = 0;
	int right = vec.size();

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (vec[mid] == target) {
			return mid;
		}
		else if (vec[mid] < target) {
			left = mid + 1; // Сужаем поиск к правой половине
		}
		else {
			right = mid - 1; // Сужаем поиск к левой половине
		}
	}
	return -1;
}

// Сортировка пузырьком
void bubbleSort() {
	string forVec;
	vector<int> vec;
	int num;

	// ввод массива 
	std::cout << "Введите числа массива через пробел" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // создание потока для обработки строки

	while (ss >> num) { // читаем числа из потока пока читается
		vec.push_back(num);
	}

	// вывод не отсортированного массива
	std::cout << "Вы ввели числа:" << endl;
	for (int val : vec) {
		std::cout << val << " ";
	}

	int n = vec.size();
	bool swapped;
	// вывод отсортированного массива
	std::cout << endl << "Отсортированные значения:" << endl;

	for (int i = 0; i < n - 1; ++i) {
		swapped = false;

		for (int j = 0; j < n - i - 1; ++j) {

			if (vec[j] > vec[j + 1]) {
				// Меняем местами элементы
				swap(vec[j], vec[j + 1]);
				swapped = true; // Указываем, что была перестановка
			}
		}

		// Если за весь проход не было перестановок, выходим
		if (!swapped) break;
	}

	for (int val : vec) {
		std::cout << val << " ";
	}
	std::cout << endl;
}

// Функция, осуществляющая слияние
void merge(vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1; // Размер левого подмассива
	int n2 = right - mid;    // Размер правого подмассива

	// Создаем временные массивы
	vector<int> leftArr(n1), rightArr(n2);

	// Копируем данные в временные массивы
	for (int i = 0; i < n1; ++i) {
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < n2; ++j) {
		rightArr[j] = arr[mid + 1 + j];
	}

	// Слияние временных массивов обратно в arr
	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		}
		else {
			arr[k++] = rightArr[j++];
		}
	}

	// Копируем оставшиеся элементы
	while (i < n1) {
		arr[k++] = leftArr[i++];
	}
	while (j < n2) {
		arr[k++] = rightArr[j++];
	}
}

// Рекурсивная функция сортировки слиянием
void mergeSor(vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2; // Находим середину

		// Сортируем первую и вторую половины
		mergeSor(arr, left, mid);
		mergeSor(arr, mid + 1, right);

		// Сливаем отсортированные половины
		merge(arr, left, mid, right);
	}
}

// Функция, ввод массива, сортировка
void mergeSort() {

	string forVec;
	vector<int> vec;
	int num;

	// ввод массива 
	std::cout << "Введите числа массива через пробел" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // создание потока для обработки строки

	while (ss >> num) { // читаем числа из потока пока читается
		vec.push_back(num);
	}

	mergeSor(vec, 0, vec.size() - 1);

	cout << "Отсортированный массив: ";
	for (int num : vec) {
		cout << num << " ";
	}
	cout << endl;

}

// Двоичный поиск
void binSearc() {
	string forVec;
	vector<int> vec;
	int num, target, res, i = 1;
	bool found = 0;

	// ввод массива 
	std::cout << "Введите числа массива через пробел" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // создание потока для обработки строки

	while (ss >> num) { // читаем числа из потока пока читается
		vec.push_back(num);
	}

	mergeSor(vec, 0, vec.size() - 1);

	std::cout << "Введите искомое число" << endl;
	cin >> target;

	res = binSearch(vec, target);
	if (res != -1) {
		cout << "Элемент найден на позиции: " << res + 1 << endl;
	}
	else {
		cout << "Элемент не найден." << endl;
	}
}

// Список функций
void hepl() {
	std::cout << "Список команд:";
	std::cout << "1. Простой поиск -- Пользователь вводит массив чисел, после вводит искомое число." << endl;
	std::cout << "2. Двоичный поиска -- Пользователь вводит массив чисел, после вводит искомое число." << endl;
	std::cout << "3. Сортировка пузырьком -- Пользователь вводит массив чисел, функция сортирует массив, выводит отсортированный." << endl;
	std::cout << "4. Сортировка слиянием -- Пользователь вводит массив чисел, функция сортирует массив, выводит отсортированный." << endl;
	std::cout << "5. Помощь -- вызывает список команд (вы здесь)." << endl;
}

// Преобразование названий функций в команды.
int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		num = stoi(input);
		return num;
	}
	else {
		if (input == "Простой поиск") {
			return 1;
		}
		else if (input == "Двоичный поиск") {
			return 2;
		}
		else if (input == "Сортировка пузырьком") {
			return 3;
		}
		else if (input == "Сортировка слиянием") {
			return 4;
		}
		else if (input == "Помощь") {
			return 5;
		}
		else if (input == "Выход") {
			return 0;
		}
		else if (input == "") {
			return -1;
		}
	}

	return 6;
}


int FirstLaba()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	std::cout << "Вы запустили сборник функций лабораторной №1.\nДля обращения к функциям наберите порядковый номер задачи или укажите её название.\nДля вызова справки введите 'Помощь'.\nДля выхода введите 'Выход'." << endl;
	while (true) {

		string input;
		int* newInput = new int;
		getline(cin, input);
		*newInput = forSwitch(input);

		switch (*newInput) {
		case -1:
			continue; // Внезапно решение проблемы 0_0
		case 0:
			std::cout << "Выход из программы...";
			return 0;
		case 1:
			std::cout << "Простой поиск" << endl;
			simpleSearch();
			delete newInput;
			newInput = nullptr;
			std::cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 2:
			std::cout << "Бинарный поиск" << endl;
			binSearc();
			delete newInput;
			newInput = nullptr;
			std::cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 3:
			std::cout << "Сортировка пузырьком" << endl;
			bubbleSort();
			delete newInput;
			newInput = nullptr;
			std::cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 4:
			std::cout << "Сортировка слиянием" << endl;
			mergeSort();
			delete newInput;
			newInput = nullptr;
			std::cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 5:
			std::cout << "Помощь" << endl;
			hepl();
			delete newInput;
			newInput = nullptr;
			std::cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;

		default:
			std::cout << "Введите корректную команду.\n";
			delete newInput;
			newInput = nullptr;
			std::cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		}
	}

}