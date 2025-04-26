#include <iostream>   // ��� cout
#include <string>     // ��� string
#include <iomanip>    // ��� �������������� ������ ����
#include <chrono>     // ��� �������
#include <sstream>    // ��� ���������� ������
#include <windows.h>

using namespace std;

// ===================================
// ����� File
// ===================================

class File {
private:
    string name;          // ��� �����
    string extension;     // ���������� �����
    int size;             // ������ ����� � ������

    // ���� �������� ����� (���������� chrono ��� �������� �������)
    chrono::system_clock::time_point creationDate;

public:
    // -----------------------------------
    // ����������� ��� ������������� �����
    // -----------------------------------
    File(string name, string extension, int size)
    {
        this->name = name;
        this->extension = extension;
        this->size = size;
        this->creationDate = chrono::system_clock::now(); // ���� �������� � ������� ������
    }

    // -----------------------------------
    // ����� ��� ��������� ������� ����� ����� (��� + ����� + ����������)
    // -----------------------------------
    string getFullName()
    {
        return name + "." + extension;
    }

    // -----------------------------------
    // ����� ��� ��������� ������� ����� � ����������
    // -----------------------------------
    double getSizeInKB()
    {
        return size / 1024.0; // ������� �� ������ � ���������
    }

    // -----------------------------------
    // ����� ��� ��������� ������� ����� � ����������
    // -----------------------------------
    double getSizeInMB()
    {
        return size / (1024.0 * 1024.0); // ������� �� ������ � ���������
    }

    // -----------------------------------
    // ����� ��� ��������� ���������� �����
    // -----------------------------------
    void changeExtension(string newExtension)
    {
        extension = newExtension;
    }

    // -----------------------------------
    // ����� ��� ������ ���������� � �����
    // -----------------------------------
    void printFileInfo()
    {
        cout << "��� �����: " << getFullName() << endl;
        cout << "������ �����: " << size << " ����" << endl;
        cout << "������ �����: " << getSizeInKB() << " ��" << endl;
        cout << "������ �����: " << getSizeInMB() << " ��" << endl;
        cout << "���� ��������: " << formatCreationDate() << endl;
    }

private:
    // -----------------------------------
    // ��������������� ����� ��� �������������� ���� ��������
    // -----------------------------------
    string formatCreationDate() const
    {
        // ����������� ���� �������� � ��������� �����
        time_t creationTimeT = chrono::system_clock::to_time_t(creationDate);

        // ��������� �������
        tm tm{};
#ifdef _WIN32
        localtime_s(&tm, &creationTimeT); // ���������� ������ ��� Windows
#else
        localtime_r(&creationTimeT, &tm); // ���������� ������ ��� Linux/Unix
#endif

        // ��������� ����� ��� ��������������
        ostringstream oss;
        oss << put_time(&tm, "%Y-%m-%d %H:%M:%S"); // ������: ���-�����-���� ����:������:�������
        return oss.str();
    }
};

// ===================================
// ������� �������
// ===================================

int secondLR()
{
    SetConsoleCP(1251);
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    SetConsoleOutputCP(1251);
     
    
    // ������� ������ �����
    File myFile("example", "txt", 2048);

    // ������� ���������� � �����
    myFile.printFileInfo();

    cout << endl;

    // ������ ���������� �����
    myFile.changeExtension("log");

    // ����� ������� ���������� � �����
    myFile.printFileInfo();

    return 0;
}
