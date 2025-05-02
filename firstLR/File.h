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
    File(std::string name, std::string extension, int size);
    std::string getFullName();

    // ����������� �����������
    File(const File& other); 

    // ��������� ������� � ��
    double getSizeInKB();

    // ��������� ������� � ��
    double getSizeInMB();

    // ��������� ���������� �����
    void changeExtension(std::string newExtension);

    // ����� ����������
    void printFileInfo();

private:

    // �������������� ����
    std::string formatCreationDate() const;
};
