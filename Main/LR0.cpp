#include <iostream>
#include <windows.h> //��� ��������� ��������� Windows 
#include <string>
#include <cmath>
#include "functions.h"

using namespace std;

void name() {
	string name;
	std::cout << "������� ���� ��� : ...\n"; //����� �� �����
	cin >> name;
	std::cout << endl << "������, " << name << "!\n";
} // ������� ����� � ������ ����� 

void arithmetic() {

	float a, b;
	string input;

	// ���� ������� �����
	while (true) {

		std::cout << endl << "������� ������ �����: ";
		cin >> input;

		if (isInt(input)) {
			a = stringToInt(input);
			break;
		}
		else {
			cout << "������������ ��������.\n";
		}
	}

	// ���� ������� �����
	while (true) {

		std::cout << "������� ������ �����: ";
		cin >> input;

		if (isInt(input)) {
			b = stringToInt(input);
			break;
		}
		else {
			cout << "������������ ��������.\n";
		}
	}

	// ����� �����������
	std::cout << endl << "��������� ��������: " << a + b << ";\n";
	std::cout << "��������� ���������: " << a - b << ";\n";
	std::cout << "��������� ���������: " << a * b << ";\n";

	// �������� ������� �� ����
	if (b != 0) {
		std::cout << "��������� �������: " << a / b << '\n';
	}
	else {
		std::cout << "������: ������� �� ���� ����������.\n";
	}
} // ���������� ���� ��������� ������� ���������� � � � 

void equation() {
	float b, c;
	string initialC, initialB;

	// ���� b
	while (true) {
		std::cout << "������� 'b': ";
		cin >> initialB;
		try {
			b = stof(initialB);
			break;
		}
		catch (...) {
			std::cout << "������������ ��������.\n";
		}
	}

	// ���� c
	while (true) {
		std::cout << endl << "������� 'c': ";
		cin >> initialC;
		try {
			c = stof(initialC);
			break;
		}
		catch (...) {
			std::cout << "������������ ��������.\n";
		}
	}
	if (b != 0) {
		std::cout << "x = " << -c / b << endl;
	}
	else {
		std::cout << "� ���������� ����������.\n";
	}

}

void oneMoreEquation() {

	float a, b, c, d, x1, x2;
	string initialA, initialB, initialC;

	// ���� �
	while (true) {
		std::cout << "������� 'a': ";
		cin >> initialA;
		try {
			a = stof(initialA);
			break;
		}
		catch (...) {
			std::cout << "������������ ��������\n";
		}
	}

	// ���� b
	while (true) {
		std::cout << "������� 'b': ";
		cin >> initialB;
		try {
			b = stof(initialB);
			break;
		}
		catch (...) {
			std::cout << "������������ ��������\n";
		}
	}

	// ���� c
	while (true) {
		std::cout << "������� 'c': ";
		cin >> initialC;
		try {
			c = stof(initialC);
			break;
		}
		catch (...) {
			std::cout << "������������ ��������\n";
		}
	}

	d = pow(b, 2) - 4 * a * c;
	if (d < 0) {
		std::cout << endl << "��� ������������ ������.\n";
	}
	else {
		x1 = (-b + sqrt(d)) / 2 * a;
		x2 = (-b - sqrt(d)) / 2 * a;
		if (x1 == x2) {
			std::cout << endl << "��� ����� �����: " << x1 << endl;
		}
		else {
			std::cout << endl << "������ ������ �����: " << x1 << endl;
			std::cout << endl << "������ ������ �����: " << x2 << endl;
		}
	}

}

void lampWithCurtain() {
	bool isDay, curtainsCondition, lampCondition;
	string d, c, l;

	while (true) {
		std::cout << endl << "�� ����� ����? (��/���) \n"; //��������, ���� �� �� �����
		cin >> d;
		if ((d == "��")(d == "���")) {
			if ((d == "��")) {
				isDay = 1;
			}
			else {
				isDay = 0;
			}
			break;
		}
		else {
			std::cout << endl << "������� ��/���\n";
		}
	}

	while (true) {
		std::cout << endl << "�������� �� �����? (��/���) \n"; //�������� ������� �� �����
		cin >> c;
		if ((c == "��") or (c == "���")) {
			if ((c == "��")) {
				curtainsCondition = 1;
			}
			else {
				curtainsCondition = 0;
			}
			break;
		}
		else {
			std::cout << "������������ ��������.\n";
		}
	}

	while (true) {
		std::cout << endl << "����� ��������? (��/���)\n"; //�������� �������� �� �����
		cin >> l;
		if ((l == "��") or (l == "���")) {
			if ((l == "��")) {
				lampCondition = 1;
			}
			else {
				lampCondition = 0;
			}
			break;
		}
		else {
			std::cout << "������������ ��������.\n";
		}
	}

	if ((isDay == 1 and curtainsCondition == 0) or lampCondition == 1) {
		std::cout << endl << "� ������� ������!\n";
	}
	else {
		std::cout << endl << "� ������� �����\n";
	}
}

int ZeroLaba()
{
	SetConsoleOutputCP(1251); //��������� �������� ������� ������� ����� ���������
	SetConsoleCP(1251); //������ ���� � ���������� �� ������� ���������� 
	std::cout << "����� ���������� � ����� �������� ������� ������������!\n";


	while (true) {
		cout << "�������:\n";
		cout << "1. '���'\n";
		cout << "2. '����������'\n";
		cout << "3. '���������'\n";
		cout << "4. '��� ���������'\n";
		cout << "5. '����� �� ������' \n";
		cout << "6. ������� \n";
		cout << "0. �����.\n" << endl;


		int forSwitch = autoInput();

		switch (forSwitch) {
		case 0:
			cout << endl;
			std::cout << "����� �� ���������...";
			return 0;

		case 1: // ������ �������
			cout << endl;
			std::cout << "�� ������� ������� '���'\n";
			name();
			cout << endl;
			break;

		case 2: // ������ �������
			cout << endl;
			std::cout << "�� ������� ������� '����������'\n";
			arithmetic();		
			cout << endl;
			break;

		case 3: // ������ �������
			cout << endl;
			std::cout << "�� ������� ������� '���������'\n";
			equation();
			cout << endl;

			break;

		case 4: // ��������� �������
			cout << endl;
			std::cout << "�� ������� ������� '��� ���������'\n";
			oneMoreEquation();
			cout << endl;

			break;

		case 5: // ����� �������
			cout << endl;
			std::cout << "�� ������� ������� '����� �� ������\n'";
			lampWithCurtain();
			cout << endl;

			break;

		case 6: // ������
			cout << endl;

			std::cout << "�������: \n������� '���' ����������� ���� ���, ����� ������������ ���. \n������� '����������' ����������� �� ���� ��� �����, ����� ������� �����, ��������, ������������ �, ���� �������� �������.";
			std::cout << "������� '���������' ����������� �� ���� ��� �����, b � c, ����� ������� x � ��������� bx + c = 0. \n������� '��� ���������' ����������� �� ���� ��� �����, a, b, c, �����, ������� ����� ��������� ax^2 + bx + c = 0.";
			std::cout << "������� '����� �� ������' ���������� ���� �� �� �����, ������� �� �����, �������� �� �����, ����� ���� �������� �� ������ ������ �� � �������\n";
			cout << endl;

			break;

		default:
			std::cout << endl << "������������ ��������.\n\n";
			break;
		}
	}
}

