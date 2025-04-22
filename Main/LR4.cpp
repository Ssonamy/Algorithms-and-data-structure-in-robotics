#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"

using namespace std;

void arrayElements() {
	string input;
	int* arr = nullptr;
	int size = 0;

	cout << "������� ����� ����� ������:" << endl;
	getline(cin, input);

	stringstream ss(input);
	int temp;

	while (ss >> temp) {
		size++;  // ����������� ������ �������
	}
	arr = new int[size]; // �������� ������ ��� �������

	ss.clear();
	ss.str(input);

	for (int i = 0; i < size; i++) {
		ss >> arr[i]; // ��������� ������
	}

	cout << "������:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;
	cout << endl;
}

void sum4() {
	string input;
	int* arr = nullptr;
	int size = 0;
	int s = 0;

	cout << "������� ����� ����� ������:" << endl;
	getline(cin, input);

	stringstream ss(input);
	int temp;

	while (ss >> temp) {
		size++;  // ����������� ������ �������
	}
	arr = new int[size]; // �������� ������ ��� �������

	ss.clear();
	ss.str(input);

	for (int i = 0; i < size; i++) {
		ss >> arr[i]; // ��������� ������
	}

	cout << "����� ��������� �������:" << endl;
	for (int i = 0; i < size; i++)
	{
		s += arr[i];
	}

	cout << s << endl;
	delete[] arr;
}

void transposition() {
	int rows, cols;

	cout << "������� ���������� �����" << endl;
	rows =autoInput();

	int** matrix = new int* [rows];

	cout << "������� ���������� ��������" << endl;
	cols =autoInput();
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	// ������������� �������
	cout << "������� �������� �������:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

	int** transMatrix = new int* [cols]; // ������� ����� ��������� ������
	for (int i = 0; i < cols; i++) {
		transMatrix[i] = new int[rows];
	}

	// ������������� �������
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transMatrix[j][i] = matrix[i][j];
		}
	}

	// ����� ����������������� �������
	cout << "����������������� �������:" << endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << transMatrix[i][j] << " ";
		}
		cout << endl;
	}

	// ����������� ������
	for (int i = 0; i < cols; i++) {
		delete[] transMatrix[i];
	}
	delete[] transMatrix;
}

void dotProduct() {
	while (true) {
		string input1, input2;
		int* arr1 = nullptr;
		int* arr2 = nullptr;
		int size1 = 0, size2 = 0;
		int s = 0;

		cout << "������ ������." << endl;
		cout << "������� ����� ����� ������:" << endl;
		getline(cin, input1);

		//���� ������� �������
		stringstream ss1(input1);
		int temp;
		while (ss1 >> temp) {
			size1++;  // ����������� ������ �������
		}
		arr1 = new int[size1]; // �������� ������ ��� �������

		ss1.clear();
		ss1.str(input1);
		for (int i = 0; i < size1; i++) {
			ss1 >> arr1[i]; // ��������� ������
		}

		//���� ������� �������
		cout << "������ ������." << endl;
		cout << "������� ����� ����� ������:" << endl;
		getline(cin, input2);

		stringstream ss2(input2);
		while (ss2 >> temp) {
			size2++;  // ����������� ������ �������
		}
		arr2 = new int[size2]; // �������� ������ ��� �������

		ss2.clear();
		ss2.str(input2);
		for (int i = 0; i < size2; i++) {
			ss2 >> arr2[i]; // ��������� ������
		}

		// ��������� ��������� �������� ��������
		if (size1 == size2) {
			// ��������� ��������� ������������
			for (int i = 0; i < size1; ++i) {
				s += arr1[i] * arr2[i];
			}
			cout << "��������� ������������ ���� �������� = " << s << "." << endl;

			// ����������� ������
			delete[] arr1;
			delete[] arr2;
			break;
		}
		else {
			cout << "���������� ��������� �������� �� �����. ������� ���������� ����������." << endl;

			// ����������� ������ ����� ��������� ������
			delete[] arr1;
			delete[] arr2;
		}
	}

}

void hepl4() {
	cout << "������ ������:\n1. �������� ������� -- ����������� �� ���� ������������ ������ ����� �����, ������� ������������ ���������� � ������ � ������� ���." << endl;
	cout << "2. ����� -- ����������� �� ���� ������������ ������ ����� �����, ������� ������������ ���������� � ������ � ������� ����� ��� ���������." << endl;
	cout << "3. ���������������� -- ����������� �� ���� ���������� ����� � �������� �������, ����� ���� ������������ ������ �������� �������, ������� ������� �������������." << endl;
	cout << "4. ��������� ������������ -- ����������� �� ���� ������������ ��� ������� ����� ����� ������ �������, ����� ���� ������� ��������� ������������ ���� ��������." << endl;
	cout << "5. ������ -- " << endl;
}

int FourhtLaba()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�� ��������� ������� ������� ������������ ����� 4." << endl;
	cout << "�������:" << endl;
	cout << "1.'�������� �������'" << endl;
	cout << "2.'�����'" << endl;
	cout << "3.'����������������'" << endl;
	cout << "4.'��������� ������������'" << endl;
	cout << "5. �������" << endl;
	cout << "0. �����" << endl;
	while (true) {

		int forSwitch = autoInput();
		switch (forSwitch) {
		case 0:
			cout << "����� �� ���������...";
			return 0;

		case 1:
			cout << "�������� �������" << endl;
			arrayElements();
			break;

		case 2:
			cout << "�����" << endl;
			sum4();
			break;

		case 3:
			cout << "����������������" << endl;
			transposition();
			break;

		case 4:
			cout << "��������� ������������" << endl;
			dotProduct();
			break;

		case 5:
			cout << "�������" << endl;
			hepl4();
			break;

		default:
			cout << "������� ���������� �������.\n";
			break;
		}
	}
	return 0;
}