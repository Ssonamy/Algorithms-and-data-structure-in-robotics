#include <iostream>   // для cout
#include <string>     // для string
#include <iomanip>    // для форматирования вывода даты
#include <chrono>     // для времени
#include <sstream>    // для строкового потока
#include <windows.h>

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
    // -----------------------------------
    // Конструктор для инициализации полей
    // -----------------------------------
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
        cout << "Дата создания: " << formatCreationDate() << endl;
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
#else
        localtime_r(&creationTimeT, &tm); // безопасная версия для Linux/Unix
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
    SetConsoleCP(1251);
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    SetConsoleOutputCP(1251);
     
    
    // Создаем объект файла
    File myFile("example", "txt", 2048);

    // Выводим информацию о файле
    myFile.printFileInfo();

    cout << endl;

    // Меняем расширение файла
    myFile.changeExtension("log");

    // Снова выводим информацию о файле
    myFile.printFileInfo();

    return 0;
}
