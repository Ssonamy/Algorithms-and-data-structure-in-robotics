#include "tests.h"
#include "File.h"
#include <iostream>
#include <cassert>
#include <cmath> // для abs()
using namespace std;

void testFileClass() {
    cout << endl << "Тест конструктора по умолчанию" << endl;
    File defaultFile;
    assert(defaultFile.getFullName() == "."); // если пустое имя и расширение
    assert(defaultFile.getSizeInKB() == 0.0);
    cout << "Конструктор по умолчанию работает корректно" << endl << endl;

    cout << "Тест конструктора с положительным размером" << endl;
    File file1("test", "txt", 2048);
    assert(file1.getFullName() == "test.txt");
    assert(file1.getSizeInKB() == 2.0);
    cout << "Файл корректный" << endl << endl;

    cout << "Тест конструктора с отрицательным размером" << endl;
    File file2("bad", "log", -500);
    assert(file2.getSizeInKB() == 0.0);
    cout << "Размер исправлен на 0" << endl;
    cout << "Размер файла: " << file2.getSizeInKB() << " КБ" << endl << endl;

    cout << "Тест смены расширения" << endl;
    file1.changeExtension("md");
    assert(file1.getFullName() == "test.md");
    cout << "Расширение изменено успешно" << endl << endl;

    cout << "Тест конструктора копирования" << endl;
    File copy = file1;
    assert(copy.getFullName() == "test.md");
    copy.changeExtension("bak");
    assert(file1.getFullName() == "test.md"); // оригинал не должен измениться
    assert(copy.getFullName() == "test.bak");
    cout << "Конструктор копирования работает корректно" << endl << endl;

    cout << "Тест селекторов (getSizeInKB и getSizeInMB)" << endl;
    File f("report", "docx", 20480);
    assert(f.getFullName() == "report.docx");
    assert(abs(f.getSizeInKB() - 20.0) < 0.01);
    assert(abs(f.getSizeInMB() - 0.0195) < 0.001);
    cout << "Методы доступа работают корректно" << endl << endl;

    cout << "Тест модификаторов (changeExtension)" << endl;
    f.changeExtension("pdf");
    assert(f.getFullName() == "report.pdf");
    cout << "Метод изменения состояния работает корректно" << endl << endl;

    cout << "Тесты пройдены успешно!" << endl;
}
