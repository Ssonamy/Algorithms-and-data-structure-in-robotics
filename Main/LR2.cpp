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

		cout << "������� �����:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "������������ ��������.\n";
		}
	}
	if (num % 2 == 0) {
		cout << "��������� ����� ������." << endl;
	}
	else {
		cout << "��������� ����� ��������." << endl;
	}

}
//2
void leapYear() {
	int num;
	while (true) {
		string number;
		cout << "������� ���:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "������������ ��������\n";
		}
	}
	if (((num % 4 == 0) and !(num % 100 == 0)) || (num % 400 == 0)) {
		cout << "��� ����������." << endl;
	}
	else if ((num % 100 == 0) and !(num % 400 == 0)) {
		cout << "��� �� ����������." << endl;
	}
	else {
		cout << "��� �� ����������." << endl;
	}
}
//3
void maxOfThree() {
	int a;
	while (true) { // ������ �����
		cout << "������� ������ �����:" << endl;
		a = autoInput();
	}

	int b;
	while (true) { // ������ �����
		cout << "������� ������ �����:" << endl;
		b = autoInput();
	}

	int c;
	while (true) { // ������ ����� 
		cout << "������� ������ �����:" << endl;
		c = autoInput();
	}

	if ((a == b) and (a == c)) {
		cout << "��� ����� ���������. ������������ ��� " << a << "!" << endl;
	}
	else {
		int max = a;
		if (b >= max) {
			max = b;
		}
		if (c >= max) {
			max = c;
		}
		cout << "������������ �������� ��� - " << max << "!" << endl;
	}
}
//4
void vowelOrConsonant() {
	string vowel = "������������������AEIOU"; // ������ �� ��������
	string consonant = "����������������������������������������������QWRTYPSDFGHJKLZXCVBNM"; // ������ � ����������
	char letter, upLetter;
	while (true) {
		cout << "������� �����" << endl;
		cin >> letter;
		upLetter = toupper(letter);
		if (vowel.find(upLetter) != string::npos) {
			cout << "����� " << letter << " �������" << endl;
			break;
		}
		else if (consonant.find(upLetter) != string::npos) {
			cout << "����� " << letter << " ���������" << endl;
			break;
		}
		else {
			cout << letter << " -- �� �����!\n���������� ��� ���. \n" << endl;
		}
	}
}
//5
void hepl2() {
	cout << "������ ������:\n1. ������ ��� �������� -- ��� ����� ����� �������������, ������� ������ � ����� �������� �� ��������.\n";
	cout << "2. ���������� ��� -- ��� ����� ����, ������� �������� �� ������ ���������� ��� ��� ���.\n3. ������������ �� ���� -- ������� ������� ������������ �� �������� ������������� �����.\n4. ������� ��� ��������� -- ������� �������� �������� �� ������, ������� ����� ��� ���.\n5. ������ -- �������� ������ ������ (�� �����).\n";
}

int SecondLaba() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {

		cout << "�� ��������� ������� ������� ������������ ����� 2.\n";
		cout << "�������:\n";
		cout << "1.'������ ��� ��������'\n";
		cout << "2.'���������� ���'\n";
		cout << "3.'������������ �� ����'\n";
		cout << "4.'������� ��� ���������'\n";
		cout << "5.�������\n";
		cout << "0. �����.\n\n";


		int forSwitch = autoInput();
		switch (forSwitch) {
		case 0:
			cout << "����� �� ���������...";
			return 0;
		case 1:
			cout << "������ ��� ��������" << endl;
			evenOrOdd();
			break;
		case 2:
			cout << "���������� ���" << endl;
			leapYear();
			break;
		case 3:
			cout << "������������ �� ����" << endl;
			maxOfThree();
			break;
		case 4:
			cout << "������� ��� ���������" << endl;
			vowelOrConsonant();
			break;
		case 5:
			cout << "�������" << endl;
			hepl2();
			break;

		default:
			cout << "������� ���������� �������.\n";
			break;
		}

	}
	return 0;
}