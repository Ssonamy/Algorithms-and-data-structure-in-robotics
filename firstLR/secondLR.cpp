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
    int size; // � ������
    std::tm creationDate;

public:
    // ����������� �� ���������
    File() : name("Untitled"), extension("txt"), size(0) {
        std::time_t t = std::time(nullptr);
        creationDate = *std::localtime(&t);
    }

    // ����������� �������������
    File(const std::string& name, const std::string& extension, int size, const std::tm& creationDate)
        : name(name), extension(extension), size(size), creationDate(creationDate) {
        if (size < 0)
            throw std::invalid_argument("������ ����� �� ����� ���� �������������");
    }

    // ����������� �����������
    File(const File& other)
        : name(other.name), extension(other.extension), size(other.size), creationDate(other.creationDate) {
    }

    // �������
    std::string getName() const { return name; }
    std::string getExtension() const { return extension; }
    int getSize() const { return size; }
    std::tm getCreationDate() const { return creationDate; }

    // �������
    void setName(const std::string& newName) { name = newName; }
    void setExtension(const std::string& newExtension) { extension = newExtension; }
    void setSize(int newSize) {
        if (newSize < 0)
            throw std::invalid_argument("������ �� ����� ���� �������������");
        size = newSize;
    }

    void setCreationDate(const std::tm& newDate) { creationDate = newDate; }

    // ����� ��� ��������� ������� ����� �����
    std::string getFullName() const {
        return name + "." + extension;
    }

    // ������ � ����������
    double getSizeInKB() const {
        return size / 1024.0;
    }

    // ������ � ����������
    double getSizeInMB() const {
        return size / (1024.0 * 1024);
    }

    // ����� ��� ������ ���������� � �����
    void printFileInfo() const {
        std::cout << "��� �����: " << name << "\n"
            << "����������: " << extension << "\n"
            << "������: " << size << " ����\n"
            << "���� ��������: " << std::put_time(&creationDate, "%d.%m.%Y %H:%M:%S") << "\n";
    }

    // ����� ��� ��������� ����������
    void changeExtension(const std::string& newExtension) {
        extension = newExtension;
    }
};

// �����
void runTests() {
    std::time_t t = std::time(nullptr);
    std::tm now = *std::localtime(&t);

    // ���� ������������ �������������
    File f1("doc", "pdf", 2048, now);
    assert(f1.getFullName() == "doc.pdf");
    assert(f1.getSize() == 2048);
    assert(f1.getSizeInKB() == 2.0);

    // ���� ������������ �� ���������
    File f2;
    assert(f2.getExtension() == "txt");

    // ���� ������������ �����������
    File f3 = f1;
    assert(f3.getName() == "doc");

    // ���� ����������
    try {
        File badFile("fail", "exe", -500, now);
        assert(false); // �� ������ ����� �� ����
    }
    catch (const std::invalid_argument&) {
        assert(true); // ���������� �������
    }

    // ���� ��������� ����������
    f1.changeExtension("docx");
    assert(f1.getExtension() == "docx");

    std::cout << "����� �������� �������.\n";
}

int secondLR() {
    runTests();

    std::time_t t = std::time(nullptr);
    std::tm now = *std::localtime(&t);

    File myFile("report", "txt", 4096, now);
    myFile.printFileInfo();
    return 0;
}
