#include <iostream>   // для cout
#include <string>     // для string
#include <iomanip>    // для форматирования вывода даты
#include <chrono>     // для времени
#include <sstream>    // для строкового потока
#include <windows.h>
#include "functions.h"
#include "File.h"
#include "tests.h"

using namespace std;

int secondLR()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    string name, extension;                             // Предварительное обьявление переменных для последующего заполнения

    File personalFile;                                  // Создание "Пустого" экземпляра класса для последующей перезаписи

    File myFile("example", "txt", 2048);                // Создание экземпляра класса как примера для вывода

    cout << "Файл (Упрощенный)\n" << endl;

    while (true) {

        cout << "Введите:\n";
        cout << "1. Добавить новый файл" << endl;
        cout << "2. Изменить расширение файла" << endl;
        cout << "3. Вывести информацию о файле" << endl;
        cout << "4. Вывести пример" << endl;
        cout << "5. Запуск тестов" << endl;
        cout << "0. Назад" << endl;
        int forSwitch = autoInput(); 
                                                        // "автоматический" ввод числового значения 
        switch (forSwitch)
        {
        default:
            cout << "Некорректное значение." << endl;
            break;

        case 1:                                         // Добавление нового экземпляра
        {
            cout << endl << "Введите название: ";
            cin >> name;
            cout << endl << "Введите расширение: ";
            cin >> extension;
            cout << endl << "Введите размер файла: ";
            int size = autoInput();

            personalFile = File(name, extension, size);
            cout << "Файл успешно создан!" << endl << endl;
            break;
        }

        case 2:                                         // Изменение расширения файла
        {
            string newExtension;                        // Cтрока в которую записывается новое расширение
            cout << endl << "Введите новое расширение файла: ";
            cin >> newExtension;
            personalFile.changeExtension(newExtension); //Изменение расширенмя
            cout << "Расширение успешно изменено!" << endl << endl;
            break;
        }

        case 3:                                         // Вывод информации о файле
        {
            cout << endl;
            personalFile.printFileInfo();               // Вывод информации о файле
            cout << endl;
            break;
        }
        case 4:                                         // Вывод примера (случай по умолчанию) 
            cout << endl;
           
            myFile.printFileInfo();                     // Вывод информации о файле

            cout << endl;

            myFile.changeExtension("log");              // Изменение расширения файла

           
            myFile.printFileInfo();                     // Снова вывод информации о файле
            cout << endl;
            break;

        case 5:
            cout << endl;

            cout << "Запуск тестов." << endl;
            testFileClass();
            cout << endl;
            break;

        case 0:
            cout << endl << "Главное меню" << endl;
            return 0;
        }
    }
}
