#include <iostream>
#include <string>
#include <windows.h>
#include "functions.h"

using namespace std;

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
			cout << "Некорректное значение.\n";
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
			cout << "Некорректное значение\n";
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
		cout << "Введите Первое число:" << endl;
		a = autoInput();
	}

	int b;
	while (true) { // второе число
		cout << "Введите Второе число:" << endl;
		b = autoInput();
	}

	int c;
	while (true) { // третье число 
		cout << "Введите Третье число:" << endl;
		c = autoInput();
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
			cout << letter << " -- не буква!\nПопробуйте еще раз. \n" << endl;
		}
	}
}
//5
void hepl2() {
	cout << "Список команд:\n1. Четное или нечетное -- при вводе числа пользователем, функция выдает в ответ проверку на четность.\n";
	cout << "2. Високосный год -- при вводе года, функция отвечает на вопрос високосный год или нет.\n3. Максимальное из трех -- функция выводит максимальное из введённых пользователем чисел.\n4. Гласная или согласная -- функция отвечает отвечает на вопрос, гласная буква или нет.\n5. Помощь -- вызывает список команд (вы здесь).\n";
}

int SecondLaba() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {

		cout << "Вы запустили сборник функций лабораторной номер 2.\n";
		cout << "Введите:\n";
		cout << "1.'Четное или нечетное'\n";
		cout << "2.'Високосный год'\n";
		cout << "3.'Максимальное из трех'\n";
		cout << "4.'Гласная или согласная'\n";
		cout << "5.Справка\n";
		cout << "0. Выход.\n\n";


		int forSwitch = autoInput();
		switch (forSwitch) {
		case 0:
			cout << "Выход из программы...";
			return 0;
		case 1:
			cout << "Четное или нечетное" << endl;
			evenOrOdd();
			break;
		case 2:
			cout << "Високосный год" << endl;
			leapYear();
			break;
		case 3:
			cout << "Максимальное из трех" << endl;
			maxOfThree();
			break;
		case 4:
			cout << "Гласная или согласная" << endl;
			vowelOrConsonant();
			break;
		case 5:
			cout << "Справка" << endl;
			hepl2();
			break;

		default:
			cout << "Введите корректную команду.\n";
			break;
		}

	}
	return 0;
}