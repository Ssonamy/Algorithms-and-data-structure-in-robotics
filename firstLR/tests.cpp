#include "tests.h"
#include "File.h"
#include <iostream>
#include <cassert>
using namespace std;

void testFileClass() {
    cout << endl << "Тест конструктора с положительным размером" << endl;
    File file1("test", "txt", 2048);
    cout << "Файл с названием 'test', расширением 'txt', размером 2048 байта" << endl;
    assert(file1.getFullName() == "test.txt");
    assert(file1.getSizeInKB() == 2.0);
    cout << "Файл корректный" << endl << endl;

    cout << "Тест конструктора с отрицательным размером" << endl;
    cout << "Файл с названием 'bad', расширением 'log', размером -500 байта" << endl;
    File file2("bad", "log", -500);
    assert(file2.getSizeInKB() == 0.0);         
    cout << "Размер исправлен на 0" << endl;
    cout << "Размер файла:" << file2.getSizeInKB() << " байт" << endl << endl;

    cout << "Тест смены расширения" << endl;
    file1.changeExtension("md");
    assert(file1.getFullName() == "test.md");
    cout << "Расширение изменено успешно" << endl << endl;

    cout << "Тест конструктора копирования" << endl;
    File copy = file1;
    assert(copy.getFullName() == "test.md");
    copy.changeExtension("bak");
    assert(file1.getFullName() == "test.md");   // оригинал не должен измениться
    assert(copy.getFullName() == "test.bak");   // копия изменилась

    cout << endl << "Тесты пройдены успешно!" << endl;
}

