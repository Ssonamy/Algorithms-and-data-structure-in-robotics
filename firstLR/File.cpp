#include "File.h"
#include <iostream>
#include <string>

using namespace std;

// Конструктор для инициализации полей
File::File(string name, string extension, int size)
    : name(name), extension(extension), size(size), creationDate(chrono::system_clock::now()) {
    if (size < 0) {
        cout << "Ошибка: размер файла не может быть отрицательным!" << endl;
        this->size = 0;
        cout << "Создан файл: " << name << "." << extension << " (" << size << " байт)"  << endl;
    }
}

// Метод для получения имени файла
string File::getFullName() {
    return name + "." + extension;
}

// Метод для получения размера файла в килобайтах 
double File::getSizeInKB() {
    return size / 1024.0;
}

// Метод для получения размера файла в мегабайтах
double File::getSizeInMB() {
    return size / (1024.0 * 1024.0);
}

// Метод для вывода информации о файле
void File::printFileInfo() {
    cout << "Имя файла: " << getFullName() << endl;
    cout << "Размер файла: " << size << " байт" << endl;
    cout << "Размер файла: " << getSizeInKB() << " КБ" << endl;
    cout << "Размер файла: " << getSizeInMB() << " МБ" << endl;
    cout << "Дата создания: " << formatCreationDate() << endl;
}

// Конструктор копирования
File::File(const File& other)
    : name(other.name), extension(other.extension), size(other.size), creationDate(other.creationDate)
{
    std::cout << "Файл успешно скопирован!" << std::endl;
}

// Метод для изменения расширения
void File::changeExtension(string newExtension) {
    File::extension = newExtension;
}

// Вспомогательный метод для форматирования даты
string File::formatCreationDate() const {
    std::time_t t = std::chrono::system_clock::to_time_t(creationDate); // стандартное время Unix (количество секунд с 1 января 1970)
    std::tm tm{};                                                       // пустая структура даты

    localtime_s(&tm, &t);                                               // перевод из time_t в tm

    std::ostringstream oss;                                             // поток для формирования строки
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");                     // изменение формата даты на гггг-мм-дд чч:мм:сс
    return oss.str();
}

