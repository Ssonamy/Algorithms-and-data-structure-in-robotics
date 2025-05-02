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
    File(const std::string& name, const std::string& extension, int size);

    // Конструктор копирования
    File(const File& other); 

    // Конструктор по умолчанию
    File(); 

    // Получение полного имени файла
    std::string getFullName() const;

    // Получение размера в КБ
    double getSizeInKB() const;

    // Получение размера в МБ
    double getSizeInMB() const;

    // Изменение расширения файла
    void changeExtension(const std::string newExtension);

    // Вывод информации
    void printFileInfo() const;

private:

    // Форматирование даты
    std::string formatCreationDate() const;
};
