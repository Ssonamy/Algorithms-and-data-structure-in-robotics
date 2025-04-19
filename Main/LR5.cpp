#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "functions.h"
using namespace std;

void del(vector<int>& vec, int num) {
	for (int i = 1; i < sqrt(num); i++) {
		if (num % i == 0) {
			vec.push_back(i);
			vec.push_back(num / i);
		}
	}
}

int fibobnachi(int destination) {
	switch (destination) {
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		return fibobnachi(destination - 1) + fibobnachi(destination - 2);
	}
}

//���������� ���������� �����
void factorial5() {
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

//���������� ����������� ������ ��������
void NOD() {
	int a, b, max = 0;
	vector<int> delA;
	vector<int> delB;

	//���� ������� �����
	a =autoInput();
	//�������� ������� ��������� ������� �����
	del(delA, a);

	//���� ������� �����
	b =autoInput();
	//�������� ������� ��������� ������� �����
	del(delB, b);

	for (int i : delA) {
		for (int j : delB) {
			if (i == j && max < i) {
				max = i;
			}
		}
	}

	cout << "���������� ����� �������� ����� " << a << " � " << b << " = " << max << "." << endl;
}

//�������� ����� �� ��������
void isPrime5() {
	int num =autoInput();
	bool isprime = 1;

	if (num > 0) {
		switch (num) {
		case 1:
			cout << "����� �� �������� �������.\n";
			break;
		case 2:
			cout << "����� �������� �������.\n";
			break;
		case 3:
			cout << "����� �������� �������.\n";
			break;
		case 4:
			cout << "����� �� �������� �������.\n";
			break;
		default:
			for (int i = 2; i < sqrt(num); i++)
			{
				if (num % i == 0) {
					isprime = 0;
					break;
				}
			}
			if (isprime) 
				cout << "����� �������� �������." << endl;
			else 
				cout << "����� �� �������� �������." << endl;
		}
	}
}

//�������� ������ �� ��, �������� �� ��� �����������
void palindrome() {
	string str, rts;

	cout << "������� ������:" << endl;
	cin >> str;

	//�������� ������
	for (int i = str.size() - 1; i >= 0; --i) {
		rts += str[i];
	}

	if (rts == str) {
		cout << "������ �������� �����������." << endl;
	}
	else {
		cout << "������ �� �������� ������������." << endl << "��������� ������:" << endl << str << endl << "����������� ������:" << rts << endl;
	}
}

//���������� ���� ���������
void fibonacciNumbers() {
	int destination;
	cout << "������� �� ������ ����� ����� ����������� ���" << endl;
	destination =autoInput();
	cout << "������������������ ���������: ";
	for (int i = 0; i < destination; i++) {
		cout << fibobnachi(i) << " ";
	}
	cout << endl;
}

//����� �������
void hepl5() {
	cout << "������ ������:" << endl;
	cout << "1. ��������� -- ����������� � ������������ �� ���� �����, ����� ���� ������� ��������� ����� �����" << endl;
	cout << "2. ���������� ����� �������� -- ����������� �� ���� ������������ ��� ����� �����, ����� ������� ���������� ����� �������� ���� ���� �����." << endl;
	cout << "3. ������� ����� -- ����������� �� ���� ����� �����, ����� ������� �������� �� ��� ����� �������." << endl;
	cout << "4. ��������� -- ����������� �� ���� ������������ ������, ����� ������� �������� �� ��� ������ �����������." << endl;
	cout << "5. ��� �������� -- ����������� � ������������ �����, ����� ������� ������� ��������� ���� ��������" << endl;
	cout << "6. ������ -- �������� ���� ������." << endl;
}

int FifthLaba()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�� ��������� ������� ������� ������������ ����� 5." << endl;
	cout << "�������:" << endl;
	cout << "1. '���������'" << endl;
	cout << "2. '���������� ����� ��������'" << endl;
	cout << "3. '������� �����'" << endl;
	cout << "4. '���������'" << endl;
	cout << "5. '��� ��������'" << endl;
	cout << "6. �������" << endl;
	cout << "0. �����" << endl;

	while (true) {

		int forSwitch = autoInput();
		switch (forSwitch) {
		case 0:
			cout << "����� �� ���������...";
			return 0;

		case 1:
			cout << "���������" << endl;
			factorial5();
			break;

		case 2:
			cout << "���������� ����� ��������" << endl;
			NOD();
			break;

		case 3:
			cout << "������� �����" << endl;
			isPrime5();
			break;

		case 4:
			cout << "���������" << endl;
			palindrome();
			break;

		case 5:
			cout << "��� ��������" << endl;
			fibonacciNumbers();
			break;

		case 6:
			cout << "�������" << endl;
			hepl5();
			break;

		default:
			cout << "������� ���������� �������.\n";
			break;
		}
	}
}
