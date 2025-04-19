#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <string>
#include "functions.h"

using namespace std;

// ������� �����
void simpleSearch() {
	string forVec, input;
	vector<int> vec;
	int num, target, i = 1;
	bool found = 0;

	// ���� ������� 
	std::cout << "������� ����� ������� ����� ������" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // �������� ������ ��� ��������� ������

	while (ss >> num) { // ������ ����� �� ������ ���� ��������
		vec.push_back(num);
	}

	std::cout << "������� ������� �����" << endl;
	cin >> input;
	target = stringToInt(input);

	for (int val : vec) {

		if (val == target) {
			std::cout << "������� ����� " << target << " ���� � ������� � �������� " << i << "." << endl;
			found = 1;
			break;
		}
		else {
			i++;
		}
	}
	if (!found) {
		std::cout << "����� �� �������." << endl;
	}

}

int binSearch(vector<int> vec, int target) {
	int left = 0;
	int right = vec.size();

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (vec[mid] == target) {
			return mid;
		}
		else if (vec[mid] < target) {
			left = mid + 1; // ������ ����� � ������ ��������
		}
		else {
			right = mid - 1; // ������ ����� � ����� ��������
		}
	}
	return -1;
}

// ���������� ���������
void bubbleSort() {
	string forVec;
	vector<int> vec;
	int num;

	// ���� ������� 
	std::cout << "������� ����� ������� ����� ������" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // �������� ������ ��� ��������� ������

	while (ss >> num) { // ������ ����� �� ������ ���� ��������
		vec.push_back(num);
	}

	// ����� �� ���������������� �������
	std::cout << "�� ����� �����:" << endl;
	for (int val : vec) {
		std::cout << val << " ";
	}

	int n = vec.size();
	bool swapped;
	// ����� ���������������� �������
	std::cout << endl << "��������������� ��������:" << endl;

	for (int i = 0; i < n - 1; ++i) {
		swapped = false;

		for (int j = 0; j < n - i - 1; ++j) {

			if (vec[j] > vec[j + 1]) {
				// ������ ������� ��������
				swap(vec[j], vec[j + 1]);
				swapped = true; // ���������, ��� ���� ������������
			}
		}

		// ���� �� ���� ������ �� ���� ������������, �������
		if (!swapped) break;
	}

	for (int val : vec) {
		std::cout << val << " ";
	}
	std::cout << endl;
}

// �������, �������������� �������
void mmerge1(vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1; // ������ ������ ����������
	int n2 = right - mid;    // ������ ������� ����������

	// ������� ��������� �������
	vector<int> leftArr(n1), rightArr(n2);

	// �������� ������ � ��������� �������
	for (int i = 0; i < n1; ++i) {
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < n2; ++j) {
		rightArr[j] = arr[mid + 1 + j];
	}

	// ������� ��������� �������� ������� � arr
	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		}
		else {
			arr[k++] = rightArr[j++];
		}
	}

	// �������� ���������� ��������
	while (i < n1) {
		arr[k++] = leftArr[i++];
	}
	while (j < n2) {
		arr[k++] = rightArr[j++];
	}
}

// ����������� ������� ���������� ��������
void mergeSor(vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2; // ������� ��������

		// ��������� ������ � ������ ��������
		mergeSor(arr, left, mid);
		mergeSor(arr, mid + 1, right);

		// ������� ��������������� ��������
		mmerge1(arr, left, mid, right);
	}
}

// �������, ���� �������, ����������
void mergeSo() {

	string forVec;
	vector<int> vec;
	int num;

	// ���� ������� 
	std::cout << "������� ����� ������� ����� ������" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // �������� ������ ��� ��������� ������

	while (ss >> num) { // ������ ����� �� ������ ���� ��������
		vec.push_back(num);
	}

	mergeSor(vec, 0, vec.size() - 1);

	cout << "��������������� ������: ";
	for (int num : vec) {
		cout << num << " ";
	}
	cout << endl;

}

// �������� �����
void binSearc() {
	string forVec;
	vector<int> vec;
	int num, target, res, i = 1;
	bool found = 0;

	// ���� ������� 
	std::cout << "������� ����� ������� ����� ������" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // �������� ������ ��� ��������� ������

	while (ss >> num) { // ������ ����� �� ������ ���� ��������
		vec.push_back(num);
	}

	mergeSor(vec, 0, vec.size() - 1);

	std::cout << "������� ������� �����" << endl;
	cin >> target;

	res = binSearch(vec, target);
	if (res != -1) {
		cout << "������� ������ �� �������: " << res + 1 << endl;
	}
	else {
		cout << "������� �� ������." << endl;
	}
}

// ������ �������
void hepl1() {
	std::cout << "������ ������:";
	std::cout << "1. ������� ����� -- ������������ ������ ������ �����, ����� ������ ������� �����." << endl;
	std::cout << "2. �������� ������ -- ������������ ������ ������ �����, ����� ������ ������� �����." << endl;
	std::cout << "3. ���������� ��������� -- ������������ ������ ������ �����, ������� ��������� ������, ������� ���������������." << endl;
	std::cout << "4. ���������� �������� -- ������������ ������ ������ �����, ������� ��������� ������, ������� ���������������." << endl;
	std::cout << "5. ������ -- �������� ������ ������ (�� �����)." << endl;
}

int FirstLaba()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {

		std::cout << "�� ��������� ������� ������� ������������ ����� 1. " << endl;
		std::cout << "������� " << endl;
		std::cout << "1. ������� �����" << endl;
		std::cout << "2. �������� �����" << endl;
		std::cout << "3. ���������� ���������" << endl;
		std::cout << "4. ���������� ��������" << endl;
		std::cout << "5. �������" << endl;
		std::cout << "0. �����" << endl;

		int forSwitch = autoInput(); 

		switch (forSwitch) {
		case 0:
			std::cout << "����� �� ���������...";
			return 0;
		case 1:
			std::cout << "������� �����" << endl;
			simpleSearch();
			break;
		case 2:
			std::cout << "�������� �����" << endl;
			binSearc();
			break;
		case 3:
			std::cout << "���������� ���������" << endl;
			bubbleSort();
			break;
		case 4:
			std::cout << "���������� ��������" << endl;
			mergeSo();
			break;
		case 5:
			std::cout << "�������" << endl;
			hepl1();
			break;

		default:
			std::cout << "������������ ��������.\n";
			break;
		}
	}

}