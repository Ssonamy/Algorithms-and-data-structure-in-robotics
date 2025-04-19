#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include "functions.h"

using namespace std;

void multiplication() {
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
	cout << "������� ��������� ����� " << num << ".\n";
	for (int i = 1; i <= 10; i++) {
		cout << num << " * " << i << " = " << num * i << endl;

	}
}

void sum3() {
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
			cout << "������������ ��������\n";
		}
	}
	int s = 0;
	for (int i = 1; i <= num; i++) {
		s = s + i;
	}
	cout << "����� ����� �� 1 �� " << num << " = " << s << endl;
}

void isPrime3() {
	int num;
	while (true) {
		string number;

		cout << "������� �����:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			if (num > 0) {
				break;
			}
			else {
				"������� ����� ������ ����.\n";
			}
		}
		else {
			cout << "������������ ��������\n";
		}
	}
	switch (num) {
	case 1:
		cout << "����� �� �������� �������.\n";
	case 2:
		cout << "����� �������� �������.\n";
	case 3:
		cout << "����� �������� �������.\n";
	default:
		for (int i = 2; i < sqrt(num); i++)
		{
			if (num % i == 0) {
				cout << "����� �� �������� �������." << endl;
				break;
			}
			else {
				cout << "����� �������� �������." << endl;
				break;
			}
		}

	}
}

void factorial3() {
	int num;
	while (true) {
		string number;
		cout << "������� �����:" << endl;
		cin >> number;

		if (isInt(number)) {
			num = stoi(number);
			if (num < 0) {
				cout << "������: ��������� �� �������� ��� ������������� �����.\n";
			}
			else if (num > 20) {
				cout << "������: ����� ������� ������� ��� ������� ����������.\n";
			}
			else {
				break;
			}
		}
		else {
			cout << "������������ ��������\n";
		}
	}

	long long s = 1;
	for (int i = 2; i <= num; i++) {
		s *= i;
	}

	cout << "��������� " << num << " = " << s << endl;
}

void hepl3() {
	cout << "������ ������:\n1. ������� ��������� -- ��� ����� ����� �������������, ������� ������� ����� ���������� �� ����� �� 1 �� 10." << endl;
	cout << "2. ����� -- ��� ����� ����� �������������, ������� ������� ����� ���� ����� �� 1 �� N, ��� N -- ���� ������������." << endl;
	cout << "3. ������� ����� -- ��� ����� ����� �������������, ������� �������, �������� �� ����� �������." << endl;
	cout << "4. ��������� -- ��� ����� ����� �������������, ������� ������� ��������� ���������� �����." << endl;
	cout << "5. ������ -- " << endl;
}

int ThirdLaba() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {

		cout << "�� ��������� ������� ������� ������������ ����� 3." << endl;
		cout << "�������:" << endl;
		cout << "1. '������� ���������'" << endl;
		cout << "2. '�����'" << endl;
		cout << "3. '������� �����'" << endl;
		cout << "4. '���������'" << endl;
		cout << "5. �������" << endl;
		cout << "0. �����." << endl;

		int forSwitch = autoInput();

		switch (forSwitch) {
		case 0:
			cout << "����� �� ���������...";
			return 0;
		case 1:
			cout << "������� ���������" << endl;
			multiplication();
			break;
		case 2:
			cout << "�����" << endl;
			sum3();
			break;
		case 3:
			cout << "������� �����" << endl;
			isPrime3();
			break;
		case 4:
			cout << "���������" << endl;
			factorial3();
			break;
		case 5:
			cout << "�������" << endl;
			hepl3();
			break;

		default:
			cout << "������� ���������� �������.\n";
			break;
		}

	}

	return 0;
}
