#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <string>
#include "functions.h"

using namespace std;

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string input;
	int forSwitch;

	cout << "_______________________________________\n";
	cout << "����� ���������� � ��������� ������ ������� ������������:\n";
	cout << "�������:\n";
	cout << "1. ������������ ����� 1: ����������.\n";

	cout << "0. �����\n";


	//�� ���� ���������� ���� ��������� �������� ������

	while (true)
	{
		forSwitch = autoInput();

		switch (forSwitch)
		{
		case 1:
			firstLR();
			break;

		//case 2:
		// ����������� �������...
		//	cout << "second is also successful\n";

		case 0:
			cout << "�����...\n";
			return 0;

		default:
			cout << "������� ���������� ��������.\n";

			break;
		}
	}

	return 0;
}