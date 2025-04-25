#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <ctime>
#include <iomanip>

class File {
private:
    std::string name;
    std::string extension;
    int size; // в байтах
    std::tm creationDate;

public:
    // Конструктор по умолчанию
    File() : name("Untitled"), extension("txt"), size(0) {
        std::time_t t = std::time(nullptr);
        creationDate = *std::localtime(&t);
    }

    // Конструктор инициализации
    File(const std::string& name, const std::string& extension, int size, const std::tm& creationDate)
        : name(name), extension(extension), size(size), creationDate(creationDate) {
        if (size < 0)
            throw std::invalid_argument("Размер файла не может быть отрицательным");
    }

    // Конструктор копирования
    File(const File& other)
        : name(other.name), extension(other.extension), size(other.size), creationDate(other.creationDate) {
    }

    // Геттеры
    std::string getName() const { return name; }
    std::string getExtension() const { return extension; }
    int getSize() const { return size; }
    std::tm getCreationDate() const { return creationDate; }

    // Сеттеры
    void setName(const std::string& newName) { name = newName; }
    void setExtension(const std::string& newExtension) { extension = newExtension; }
    void setSize(int newSize) {
        if (newSize < 0)
            throw std::invalid_argument("Размер не может быть отрицательным");
        size = newSize;
    }

    void setCreationDate(const std::tm& newDate) { creationDate = newDate; }

    // Метод для получения полного имени файла
    std::string getFullName() const {
        return name + "." + extension;
    }

    // Размер в килобайтах
    double getSizeInKB() const {
        return size / 1024.0;
    }

    // Размер в мегабайтах
    double getSizeInMB() const {
        return size / (1024.0 * 1024);
    }

    // Метод для печати информации о файле
    void printFileInfo() const {
        std::cout << "Имя файла: " << name << "\n"
            << "Расширение: " << extension << "\n"
            << "Размер: " << size << " байт\n"
            << "Дата создания: " << std::put_time(&creationDate, "%d.%m.%Y %H:%M:%S") << "\n";
    }

    // Метод для изменения расширения
    void changeExtension(const std::string& newExtension) {
        extension = newExtension;
    }
};

// Тесты
void runTests() {
    std::time_t t = std::time(nullptr);
    std::tm now = *std::localtime(&t);

    // Тест конструктора инициализации
    File f1("doc", "pdf", 2048, now);
    assert(f1.getFullName() == "doc.pdf");
    assert(f1.getSize() == 2048);
    assert(f1.getSizeInKB() == 2.0);

    // Тест конструктора по умолчанию
    File f2;
    assert(f2.getExtension() == "txt");

    // Тест конструктора копирования
    File f3 = f1;
    assert(f3.getName() == "doc");

    // Тест исключений
    try {
        File badFile("fail", "exe", -500, now);
        assert(false); // не должно дойти до сюда
    }
    catch (const std::invalid_argument&) {
        assert(true); // исключение поймано
    }

    // Тест изменения расширения
    f1.changeExtension("docx");
    assert(f1.getExtension() == "docx");

    std::cout << "Тесты пройдены успешно.\n";
}

int secondLR() {
    runTests();

    std::time_t t = std::time(nullptr);
    std::tm now = *std::localtime(&t);

    File myFile("report", "txt", 4096, now);
    myFile.printFileInfo();
    return 0;
}
