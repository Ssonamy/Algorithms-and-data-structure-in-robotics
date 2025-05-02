#pragma once
#include <string>
#include <chrono>

class File {
private:
    std::string name;                                        // имя файла
    std::string extension;                                   // расширение файла
    int size;                                                // размер файла в байтах
    std::chrono::system_clock::time_point creationDate;      // время создания файла

public:
    // Инициализация полей
    File(std::string name, std::string extension, int size);
    std::string getFullName();

    // Конструктор копирования
    File(const File& other); 

    // Получение размера в КБ
    double getSizeInKB();

    // Получение размера в МБ
    double getSizeInMB();

    // Изменение расширения файла
    void changeExtension(std::string newExtension);

    // Вывод информации
    void printFileInfo();

private:

    // Форматирование даты
    std::string formatCreationDate() const;
};
