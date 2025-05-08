#include <iostream>
#include <string>
#include <clocale>
#include "functions.h"


using namespace std;

bool isInt(const string& x) {
	try {
		int value = stoi(x);
		return true;
	}
	catch (...) {
		return false;
	}
}

int stringToInt(string x) {
	return stoi(x);
}

int autoInput()
{
	std::setlocale(LC_ALL, "ru_RU.utf8");

	while (true) {
		string input;
		int output;

		cout << "Введите: ";
		cin >> input;
		if (!isInt(input)) {
			cout << "Введите корректное число.\n";
			continue;
		}
		return output = stringToInt(input);
	}
}