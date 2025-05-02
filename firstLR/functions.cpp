#include <iostream>
#include <string>
#include <windows.h>
#include "functions.h"


using namespace std;

bool isInt(string x) {
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
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

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