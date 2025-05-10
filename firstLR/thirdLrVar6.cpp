#include <iostream>
#include "functions.h"
#include <clocale>
#include <string>
#include "tests.h"


using namespace std;


bool thirdLrVar6() {
	setlocale(LC_ALL, "ru_RU.utf8");

	cout << "Карта звездного неба" << endl;
	while (true) {

		cout << "Введите: " << endl;
		cout << "1. чтото будетпотом" << endl; // Исправить!!!!!!!!
		cout << "5. Тестирование " << endl;
		cout << "0. Назад. " << endl;
		cout << "-1. Выход. " << endl;

		int forSwitch = autoInput();

		switch (forSwitch)
		{
		case 1:
			break;

		case 5:
			while (true)
			{
			cout << endl << "_____________" << endl;
			cout << "Тестирование:" << endl;
			cout << "Введите:" << endl;
			cout << "1. Тестирование класса CelestialBody" << endl;
			cout << "2. Тестирование класса CelestialSystem" << endl;
			cout << "3. Тестирование небесной карты" << endl;
			cout << "4. Тестирование всех элементов" << endl;
			cout << "0. Назад" << endl;
			cout << "-1. Выход" << endl;

			int forTest = autoInput();
			switch (forTest)
			{
			case 1:
				testCelestialBodyClass();
				cout << endl;
				break;

			case 2:
				testCelestialSystemClass();
				cout << endl;
				break;

			case 3:
				//testSkyMapClass();
				cout << endl;
				break;

			case 4:

				testCelestialBodyClass();
				cout << endl;
				testCelestialSystemClass();
				cout << endl;
				//testSkyMapClass();
				cout << endl;
				break;

			case 0:
				return 0;

			case -1:
				return 1;
			default:
				cout << "Некорректное значение." << endl;
				break;
			}
		}
		default:
			cout << "Некорректное значение.\n";
			break;
		}
	}

	return 0;
}