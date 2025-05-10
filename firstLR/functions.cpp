#include <iostream>
#include <string>

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

int stringToInt(const string x) {
	return stoi(x);
}

int autoInput()
{

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