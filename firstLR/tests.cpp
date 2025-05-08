#include "tests.h"
#include "File.h"
#include <iostream>
#include <cassert>
#include "Rectangle.h"
#include "Point2D.h"
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

void testRectangleClass() {
    cout << endl << "Тест конструктора по умолчанию" << endl;
    Rectangle r1;
    assert(r1.calculateArea() == 0.0);
    assert(r1.calculatePerimeter() == 0.0);
    cout << "Конструктор по умолчанию работает корректно" << endl << endl;

    cout << "Тест конструктора с положительными значениями ширины и высоты" << endl;
    Rectangle r2(Point2D(0.0, 0.0), 10.0, 5.0);
    assert(r2.calculateArea() == 50.0);
    assert(r2.calculatePerimeter() == 30.0);
    cout << "Площадь и периметр рассчитываются корректно" << endl << endl;

    cout << "Тест граничных точек (внутри и на краях прямоугольника)" << endl;
    assert(r2.isInside(Point2D(0.0, 0.0)) == true);            // угол
    assert(r2.isInside(Point2D(10.0, 0.0)) == true);           // правый край
    assert(r2.isInside(Point2D(5.0, -5.0)) == true);           // центр
    assert(r2.isInside(Point2D(0.0, -5.0)) == true);           // нижний левый
    assert(r2.isInside(Point2D(10.0, -5.0)) == true);          // нижний правый
    assert(r2.isInside(Point2D(11.0, -5.0)) == false);         // вне
    cout << "Метод isInside работает корректно" << endl << endl;

    cout << "Тест конструктора копирования" << endl;
    Rectangle r3(r2);
    assert(r3.calculateArea() == 50.0);
    assert(r3.isInside(Point2D(5.0, -2.0)) == true);
    cout << "Конструктор копирования работает корректно" << endl << endl;

    cout << "Тест выброса исключения при некорректных значениях" << endl;
    try {
        Rectangle r4(Point2D(0.0, 0.0), -3.0, 4.0);
        assert(false); // не должен дойти до этой строки
    }
    catch (const invalid_argument&) {
        cout << "Обнаружено исключение при отрицательной ширине — корректно" << endl;
    }

    try {
        Rectangle r5(Point2D(0.0, 0.0), 3.0, -4.0);
        assert(false); // не должен дойти до этой строки
    }
    catch (const invalid_argument&) {
        cout << "Обнаружено исключение при отрицательной высоте — корректно" << endl;
    }

    cout << endl << "Все тесты Rectangle успешно пройдены!" << endl;
}