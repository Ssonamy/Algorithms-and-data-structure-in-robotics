#include <iostream>
#include <string>

using namespace std;

bool isInt(string x) {
	bool flag;
	try {
		int value = stoi(x);
		return flag = true;
	}
	catch (...) {
		return flag = false;
	}
}

int stringToInt(string x) {
	if (isInt(x)) {
		return stoi(x);
	}
}