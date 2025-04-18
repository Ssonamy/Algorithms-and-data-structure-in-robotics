#include <iostream>
#include <string>
#include <windows.h>

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
//1
void evenOrOdd() {
	int num;
	while (true) {
		string number;

		cout << "Введите число:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}
	if (num % 2 == 0) {
		cout << "Введенное число четное." << endl;
	}
	else {
		cout << "Введенное число нечетное." << endl;
	}

}
//2
void leapYear() {
	int num;
	while (true) {
		string number;
		cout << "Введите год:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}
	if (((num % 4 == 0) and !(num % 100 == 0)) || (num % 400 == 0)) {
		cout << "Год високосный." << endl;
	}
	else if ((num % 100 == 0) and !(num % 400 == 0)) {
		cout << "Год не високосный." << endl;
	}
	else {
		cout << "Год не високосный." << endl;
	}
}
//3
void maxOfThree() {
	int a;
	while (true) { // первое число
		string a1;
		cout << "Введите Первое число:" << endl;
		cin >> a1;
		if (isInt(a1)) {
			a = stoi(a1);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}

	int b;
	while (true) { // второе число
		string b2;
		cout << "Введите Второе число:" << endl;
		cin >> b2;
		if (isInt(b2)) {
			b = stoi(b2);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}

	int c;
	while (true) { // третье число 
		string c3;
		cout << "Введите Третье число:" << endl;
		cin >> c3;
		if (isInt(c3)) {
			c = stoi(c3);
			break;
		}
		else {
			cout << "Ошибка: Введите корректное числовое значение.\n";
		}
	}

	if ((a == b) and (a == c)) {
		cout << "Все числа одинаковы. Максимальное это " << a << "!" << endl;
	}
	else {
		int max = a;
		if (b >= max) {
			max = b;
		}
		if (c >= max) {
			max = c;
		}
		cout << "Максимальное значение это - " << max << "!" << endl;
	}
}
//4
void vowelOrConsonant() {
	string vowel = "УЕЫАОЭЯИЮуеыаоэяиюAEIOU"; // Массив сс гласными
	string consonant = "ЙЦКНГШЩЗХЪФВПРЛДЖЧСМТЬБйцкнгшщзхъфвпрлджчсмтьбQWRTYPSDFGHJKLZXCVBNM"; // массив с согласными
	char letter, upLetter;
	while (true) {
		cout << "Введите букву" << endl;
		cin >> letter;
		upLetter = toupper(letter);
		if (vowel.find(upLetter) != string::npos) {
			cout << "Буква " << letter << " гласная" << endl;
			break;
		}
		else if (consonant.find(upLetter) != string::npos) {
			cout << "Буква " << letter << " согласная" << endl;
			break;
		}
		else {
			cout << letter << " не буква!\nПопробуйте еще раз. \n" << endl;
		}
	}
}
//5
void hepl() {
	cout << "Список команд:\n1. Четное или нечетное -- при вводе числа пользователем, функция выдает в ответ проверку на четность.\n";
	cout << "2. Високосный год -- при вводе года, функция отвечает на вопрос високосный год или нет.\n3. Максимальное из трех -- функция выводит максимальное из введённых пользователем чисел.\n4. Гласная или согласная -- функция отвечает отвечает на вопрос, гласная буква или нет.\n5. Помощь -- вызывает список команд (вы здесь).\n";
}

int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		return num = stoi(input);
	}
	else {
		if (input == "Четное или нечетное") {
			return num = 1;
		}
		else if (input == "Високосный год") {
			return num = 2;
		}
		else if (input == "Максимальное из трех") {
			return num = 3;
		}
		else if (input == "Гласная или согласная") {
			return num = 4;
		}
		else if (input == "Помощь") {
			return num = 5;
		}
		else if (input == "Выход") {
			return num = 0;
		}
	}
}

int SecondLaba() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Вы запустили сборник функций лабораторной №2.\nДля обращения к функциям наберите порядковый номер задачи или укажите её название.\n";
	while (true) {

		string input;
		int* newInput = new int;
		getline(cin, input);
		*newInput = forSwitch(input);

		switch (*newInput) {
		case 0:
			cout << "Выход из программы...";
			return 0;
		case 1:
			cout << "Четное или нечетное" << endl;
			evenOrOdd();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 2:
			cout << "Високосный год" << endl;
			leapYear();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 3:
			cout << "Максимальное из трех" << endl;
			maxOfThree();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 4:
			cout << "Гласная или согласная" << endl;
			vowelOrConsonant();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		case 5:
			cout << "Помощь" << endl;
			hepl();
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;

		default:
			cout << "Введите корректную команду.\n";
			delete newInput;
			newInput = nullptr;
			cout << "Для вызова справки наберите 'Помощь'.\nДля выхода напишите 'Выход'. \n";
			break;
		}

	}
	return 0;
}