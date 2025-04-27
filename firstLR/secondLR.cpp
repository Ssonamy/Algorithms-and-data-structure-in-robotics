#include <iostream>   // для cout
#include <string>     // для string
#include <iomanip>    // для форматирования вывода даты
#include <chrono>     // для времени
#include <sstream>    // для строкового потока
#include <windows.h>
#include "functions.h"


using namespace std;

// ===================================
// Класс File
// ===================================

class File {
private:
    string name;          // имя файла
    string extension;     // расширение файла
    int size;             // размер файла в байтах

    // Дата создания файла (используем chrono для хранения времени)
    chrono::system_clock::time_point creationDate;

public:
     //-----------------------------------
     //Конструктор для инициализации полей
     //-----------------------------------
    File(string name, string extension, int size)
    {
        this->name = name;
        this->extension = extension;
        this->size = size;
        this->creationDate = chrono::system_clock::now(); // дата создания — текущий момент
    }

    // -----------------------------------
    // Метод для получения полного имени файла (имя + точка + расширение)
    // -----------------------------------
    string getFullName()
    {
        return name + "." + extension;
    }

    // -----------------------------------
    // Метод для получения размера файла в килобайтах
    // -----------------------------------
    double getSizeInKB()
    {
        return size / 1024.0; // перевод из байтов в килобайты
    }

    // -----------------------------------
    // Метод для получения размера файла в мегабайтах
    // -----------------------------------
    double getSizeInMB()
    {
        return size / (1024.0 * 1024.0); // перевод из байтов в мегабайты
    }

    // -----------------------------------
    // Метод для изменения расширения файла
    // -----------------------------------
    void changeExtension(string newExtension)
    {
        extension = newExtension;
    }

    // -----------------------------------
    // Метод для вывода информации о файле
    // -----------------------------------
    void printFileInfo()
    {
        cout << "Имя файла: " << getFullName() << endl;
        cout << "Размер файла: " << size << " байт" << endl;
        cout << "Размер файла: " << getSizeInKB() << " КБ" << endl;
        cout << "Размер файла: " << getSizeInMB() << " МБ" << endl;
        cout << format("Дата создания: {}\n", creationDate);
    }

private:
    // -----------------------------------
    // Вспомогательный метод для форматирования даты создания
    // -----------------------------------
    string formatCreationDate() const
    {
        // Преобразуем дату создания в системное время
        time_t creationTimeT = chrono::system_clock::to_time_t(creationDate);

        // Структура времени
        tm tm{};
#ifdef _WIN32
        localtime_s(&tm, &creationTimeT); // безопасная версия для Windows
#endif

        // Строковый поток для форматирования
        ostringstream oss;
        oss << put_time(&tm, "%Y-%m-%d %H:%M:%S"); // формат: год-месяц-день часы:минуты:секунды
        return oss.str();
    }
};

// ===================================
// Главная функция
// ===================================

int secondLR()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    //Изменение кодировки для вывода корректных символов на кирилице

    
    string name, extension; //Предварительное обьявление переменных для последующего заполнения

    File personalFile("example", "txt", 2048); // Создание "Пустого" экземпляра класса для последующей перезаписи

    File myFile("example", "txt", 2048); // Создание экземпляра класса как примера для вывода


    cout << "Файл (Упрощенный)\n" << endl;

    while (true) {

        cout << "Введите:\n";
        cout << "1. Добавить новый файл" << endl;
        cout << "2. Изменить расширение файла" << endl;
        cout << "3. Вывести информацию о файле" << endl;
        cout << "4. Вывести пример" << endl;
        cout << "0. Назад" << endl;
        int forSwitch = autoInput(); // "автоматический" ввод числового значения 

        switch (forSwitch)
        {
        default:
            cout << "Некорректное значение." << endl;
            break;
        case 1: // Добавление нового экземпляра
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
        
        case 2: //Изменение расширения файла
        {
            string newExtension; // строка в которую записывается новое расширение
            cout << endl << "Введите новое расширение файла: ";
            cin >> newExtension;
            personalFile.changeExtension(newExtension); //Изменение расширенмя
            cout << "Расширение успешно изменено!" << endl << endl;
            break;
        }

        case 3: //Вывод информации о файле
        {
            cout << endl;
            personalFile.printFileInfo(); //Вывод информации о файле
            cout << endl;
            break;
        }
        case 4: //Вывод примера (случай по умолчанию) 
            cout << endl;
           
            myFile.printFileInfo(); // Вывод информации о файле

            cout << endl;

            myFile.changeExtension("log"); // Изменение расширения файла

           
            myFile.printFileInfo(); // Снова вывод информации о файле
            cout << endl;
            break;

        case 0:
            cout << endl << "Главное меню" << endl;
            return 0;
        }
    }
}
