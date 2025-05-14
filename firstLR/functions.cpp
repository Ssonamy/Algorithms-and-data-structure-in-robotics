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
bool isDouble(const std::string& x) {
	try {
		double value = stod(x);
		return true;
	}
	catch (...) {
		return false;
	}
}

int autoInt(){
	while (true) {
		string input;

		cout << "Введите: ";
		cin >> input;
		if (!isInt(input)) {
			cout << "Введите корректное число.\n" << endl;
			continue;
		}
		return stoi(input);
	}
}