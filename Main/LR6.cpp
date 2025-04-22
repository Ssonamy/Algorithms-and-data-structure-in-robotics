#include <iostream>
#include <windows.h>
#include <fstream> // ��� ������ � �������
#include <string>
#include "functions.h"

using namespace std;

// ���������� ��������� ��� 4, 5 �������
struct Person {
	string name;  // ���������� string ������ ������� char
	int age;
	double height;
};

//������ �������, ���������� � ���� ���� ������������
void textToFile() {
	// ��� �����
	string filename = "output.txt";

	// ������� ������ ofstream � ��������� ���� � ������ ������ (����������� ����, ���� �� ��� ����������)
	ofstream file(filename, ios::trunc);

	// ���������, ������� �� ������� ����
	if (!file) {
		cerr << "������ ��� �������� ����� ��� ������!" << endl;
		return; // ��������� ��������� � �������
	}

	// ���� ������ �� ������������
	cout << "������� ������ ��� ������ � ���� (������� \"STOP\" ��� ���������� �����):" << endl;

	string line;
	while (true) {
		getline(cin, line); // ��������� ������ �� ������������
		if (line == "STOP") {
			break; // ��������� ����, ���� ������������ ���� "STOP"
		}
		file << line << "\n"; // ���������� ������ � ����
	}

	// ��������� ����
	file.close();

	// �������� ������������ �� �������� ������
	cout << "������ ������� �������� � ����: " << filename << endl;
}

//������ �������, ������� �� ��� ���� ��������� � ���� � ������� ������ �������
void fileToDisplay() {
	// ��� ����� (��� �� ����, ������� ������������� ��� ������)
	string filename = "output.txt";

	// ������� ������ ifstream ��� ������ �� �����
	ifstream file(filename);

	// ���������, ������� �� ������� ����
	if (!file) {
		cerr << "������: ���������� ������� ���� " << filename << " ��� ������!" << endl;
		return; // ��������� ��������� � �������
	}

	// ������ ������ �� ����� � ������� �� �� �����
	cout << "���������� ����� \"" << filename << "\":" << endl;

	string line;
	while (getline(file, line)) {
		cout << line << endl; // ������� ������ ������
	}

	// ��������� ����
	file.close();

}

//������ ������ ��������� � ���� �������������� ������, �� ������ ��������� ������
void addstrings() {
	// ��� �����
	string filename = "output.txt";

	// ������� ������ ofstream � ������ ����������
	ofstream file(filename, ios::app);

	// ���������, ������� �� ������� ����
	if (!file) {
		cerr << "������ ��� �������� ����� ��� ���������� ������!" << endl;
		return; // ��������� ��������� � �������
	}

	// ���� ������ �� ������������
	cout << "������� ������ ��� ���������� � ���� (������� \"STOP\" ��� ���������� �����):" << endl;

	string line;
	while (true) {
		getline(cin, line); // ��������� ������ �� ������������
		if (line == "STOP") {
			break; // ��������� ����, ���� ������������ ���� "STOP"
		}
		file << line << "\n"; // ��������� ������ � ����
	}

	// ��������� ����
	file.close();

	// �������� ������������ �� �������� ������
	cout << "������ ������� ��������� � ����: " << filename << endl;
}

//��������� ������, ���������� ���� ������������ � ��������� ���������
void writeToFile() {
	string filename = "data.bin";
	ofstream file(filename);
	if (!file) {
		cerr << "������ ��� �������� ����� ��� ������!" << endl;
		return;
	}

	Person person;
	cout << "������� ���: ";
	getline(cin, person.name);
	cout << "������� �������: ";
	person.age =autoInput();
	cout << "������� ���� (� �����������): ";
	person.height =autoInput();

	// ���������� ������ � ��������� �������
	file << person.name << "\n";
	file << person.age << "\n";
	file << person.height << "\n";

	cout << "������ ������� �������� � ����." << endl;
}

void readFromFile() {
	string filename = "data.bin";
	ifstream file(filename);
	if (!file) {
		cerr << "������ ��� �������� ����� ��� ������!" << endl;
		return;
	}

	Person person;

	// ������ ������ �� �����
	getline(file, person.name);
	file >> person.age;
	file >> person.height;

	// ������� ������
	cout << "���: " << person.name << endl;
	cout << "�������: " << person.age << endl;
	cout << "����: " << person.height << " ��" << endl;
}


void copyingToAnother() {
	//�������� ����
	string sourceFile = "output.txt";

	//���� ����������
	string destinationFile = "destinationFile.txt";

	// ��������� �������� ����
	ifstream inputFile(sourceFile);
	if (!inputFile) {
		cerr << "�� ������� ������� ���� " << sourceFile << " ��� ������!" << endl;
		return;
	}

	// ��������� ���� ����������
	ofstream outputFile(destinationFile);
	if (!outputFile) {
		cerr << "�� ������� ������� ���� " << destinationFile << " ��� ������!" << endl;
		return;
	}

	// ������ ��������� � ����������
	string line;
	while (getline(inputFile, line)) {
		outputFile << line << '\n';
	}

	cout << "���� ������� ����������." << endl;
}

//����� �������
void hepl6() {
	cout << "������ ������:" << endl;
	cout << "1. ����� � ���� -- ���������� �������� ����� � ����." << endl;
	cout << "2. ����� -- ������� ����� �� �����." << endl;
	cout << "3. ���������� ����� -- ���������� �������� ����� � ����� �����." << endl;
	cout << "4. �������� ���� -- ������ ��� ������ � ��������� �������: ������ ��������� ������ � ���� � ����������� ������ �� ����." << endl;
	cout << "5. ����������� ����� � ������ -- �������� ���������� ������ ����� � ������." << endl;
	cout << "6. ������ -- �������� ���� ������." << endl;
}

int SixthLaba() {
	int choice;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�� ��������� ������� ������� ������������ ����� 6." << endl;
	cout << "�������:" << endl;
	cout << "1. '����� � ����'" << endl;
	cout << "2. '�����'"<< endl;
	cout << "3. '���������� �����'" << endl;
	cout << "4. '�������� ����'" << endl;
	cout << "5. '����������� ����� � ������'" << endl;
	cout << "6. �������" << endl;
	cout << "0. �����" << endl;

	while (true) {

		int forSwitch = autoInput();
		switch (forSwitch) {
		case 0:
			cout << "����� �� ���������...";
			return 0;
		case 1:
			cout << "����� � ����" << endl;
			textToFile();
			break;
		case 2:
			cout << "�����" << endl;
			fileToDisplay();
			break;
		case 3:
			cout << "���������� �����" << endl;
			while (true) {
				addstrings();
				break;
		case 4:
			cout << "�������� ����" << endl;
			do {
				cout << "\n�������� ��������:\n";
				cout << "1. �������� ������ � ����\n";
				cout << "2. ��������� ������ �� �����\n";
				cout << "0. �����\n";
				cout << "��� �����: ";
				choice = autoInput();

				switch (choice) {
				case 1:
					writeToFile();
					break;
				case 2:
					readFromFile();
					break;
				case 0:
					cout << "����� �� ���������." << endl;
					break;
				default:
					cout << "������������ �����! ���������� �����." << endl;
				}
			} while (choice != 0);
			break;

		case 5:
			cout << "����������� ����� � ������" << endl;
			copyingToAnother();
			break;

		case 6:
			cout << "�������" << endl;
			hepl6();
			break;

		default:
			cout << "������� ���������� �������.\n";
			break;
			}
		}
	}
}