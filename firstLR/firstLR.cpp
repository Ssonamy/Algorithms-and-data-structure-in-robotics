#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

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

// Ввод целого числа
int INTj() {
	while (true) {
		string number;
		int num;

		std::cout << "Введите число:" << endl;
		cin >> number;
		if (isInt(number)) {
			return num = stoi(number);
			break;
		}
		else {
			std::cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}
}


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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "_______________________________________\n";
	cout << "Добро пожаловать в программу сортировки.\n";
	cout << "Введите:\n";
	cout << "1. Сортировка пузырьком.\n";
	cout << "2. Сортировка вставками.\n";
	cout << "2. Сортировка слиянием.\n";
	cout << "_______________________________________\n";

	int choise;
	cin >> choise;
	while (true) {
		switch (choise) {

		case 1:
			bubbleSort();
			break;

		default:
			break;
		}
	}
}