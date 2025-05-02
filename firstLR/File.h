#pragma once
#include <string>
#include <chrono>

class File {
private:
    std::string name;                                        // ��� �����
    std::string extension;                                   // ���������� �����
    int size;                                                // ������ ����� � ������
    std::chrono::system_clock::time_point creationDate;      // ����� �������� �����

public:
    // ������������� �����
    File(const std::string& name, const std::string& extension, int size);

    // ����������� �����������
    File(const File& other); 

    // ����������� �� ���������
    File(); 

    // ��������� ������� ����� �����
    std::string getFullName() const;

    // ��������� ������� � ��
    double getSizeInKB() const;

    // ��������� ������� � ��
    double getSizeInMB() const;

    // ��������� ���������� �����
    void changeExtension(const std::string newExtension);

    // ����� ����������
    void printFileInfo() const;

private:

    // �������������� ����
    std::string formatCreationDate() const;
};
