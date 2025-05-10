#include "File.h"
#include <iostream>
#include <cassert>
#include "Rectangle.h"
#include "Point2D.h"
#include "CelestialBody.h"
#include "CelestialSystem.h"

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
    assert(r1.calculateArea() == 1.0);
    assert(r1.calculatePerimeter() == 4.0);
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

    cout << endl << "Тесты пройдены успешно!" << endl;
}

void testCelestialBodyClass(){
	cout << endl << "Тест конструктора по умолчанию" << endl;
	CelestialBody defaultBody;
	assert(defaultBody.getRightAscension() == 0.0);
	assert(defaultBody.getDeclination() == 0.0);
	assert(defaultBody.getMagnitude() == 0.0);
	assert(defaultBody.getName() == "Unnamed");
	cout << "Конструктор по умолчанию работает корректно" << endl << endl;
	cout << "Тест конструктора с параметрами" << endl;
	CelestialBody body(15.0, -30.0, 5.5, "Сириус");
	assert(body.getRightAscension() == 15.0);
	assert(body.getDeclination() == -30.0);
	assert(body.getMagnitude() == 5.5);
	assert(body.getName() == "Сириус");
	cout << "Конструктор с параметрами работает корректно" << endl << endl;
	cout << "Тест конструктора копирования" << endl;
	CelestialBody copyBody(body);
	assert(copyBody.getRightAscension() == body.getRightAscension());
	assert(copyBody.getDeclination() == body.getDeclination());
	assert(copyBody.getMagnitude() == body.getMagnitude());
	assert(copyBody.getName() == body.getName());
	cout << "Конструктор копирования работает корректно" << endl << endl;
	cout << "Тест селекторов и модификаторов" << endl;
	body.setRightAscension(20.0);
	body.setDeclination(-45.0);
	body.setMagnitude(3.5);
	body.setName("Полярная звезда");

	assert(body.getRightAscension() == 20.0);
	assert(body.getDeclination() == -45.0);
	assert(body.getMagnitude() == 3.5);
	assert(body.getName() == "Полярная звезда");

	cout << "Методы доступа и изменения состояния работают корректно" << endl << endl;
	cout << "Тест валидации значений" << endl;

	try {
		body.setDeclination(100.0); // некорректное значение
		assert(false); // не должен дойти до этой строки
	}
    catch (const invalid_argument&) {
        cout << "Обнаружено исключение" << endl;
    }
    try
    {
		body.setMagnitude(-50.0); // некорректное значение
		assert(false); // не должен дойти до этой строки
    }
    catch (const std::invalid_argument&)
    {
        cout << "Обнаружено исключение" << endl;
    }
    body.setName(""); // некорректное значение
    assert(body.getName() == "Unnamed");


	cout << "Тесты пройдены успешно!" << endl;
}

void testCelestialSystemClass() {
    cout << "\nТест конструктора по умолчанию" << endl;
    CelestialSystem defaultSystem;
    assert(defaultSystem.getQuantity() == 0);
    assert(defaultSystem.getPrimaryIndex() == -1);
    assert(defaultSystem.getMembers().empty());
    cout << "Конструктор по умолчанию работает корректно\n" << endl;

    cout << "Тест конструктора с параметрами" << endl;
    vector<CelestialBody> bodies = {
        CelestialBody(0.0, 0.0, 1.0, "Alpha"),
        CelestialBody(1.0, 1.0, 2.0, "Beta")
    };
    unordered_map<string, int> nameMap = { {"Alpha", 0}, {"Beta", 1} };
	CelestialSystem paramSystem(10.0, -10.0, 0.5, "System A", bodies, nameMap, 0);
    assert(paramSystem.getQuantity() == 2);
    assert(paramSystem.getPrimaryIndex() == 0);
    assert(paramSystem.getBodyByName("Alpha") != nullptr);
    assert(paramSystem.getBodyByName("Beta") != nullptr);
    assert(paramSystem.getBodyByName("Gamma") == nullptr);
    cout << "Конструктор с параметрами работает корректно\n" << endl;

    cout << "Тест конструктора копирования" << endl;
    CelestialSystem copiedSystem(paramSystem);
    assert(copiedSystem.getQuantity() == paramSystem.getQuantity());
    assert(copiedSystem.getPrimaryIndex() == paramSystem.getPrimaryIndex());
    assert(copiedSystem.getBodyByName("Alpha")->getName() == "Alpha");
    cout << "Конструктор копирования работает корректно\n" << endl;

    cout << "Тест добавления тела" << endl;
    CelestialBody newBody(5.0, 5.0, 1.5, "Gamma");
    copiedSystem.addBody(newBody);
    assert(copiedSystem.getQuantity() == 3);
    assert(copiedSystem.getBodyByName("Gamma") != nullptr);
    cout << "Добавление работает корректно\n" << endl;

    cout << "Тест добавления тела с повторяющимся именем" << endl;
    copiedSystem.addBody(newBody); // Должно вывести сообщение, но не добавить
    assert(copiedSystem.getQuantity() == 3);
    cout << "Проверка на дубликаты работает корректно\n" << endl;

    cout << "Тест удаления тела" << endl;
    copiedSystem.removeBody(2); // Удаляем "Gamma"
    assert(copiedSystem.getQuantity() == 2);
    assert(copiedSystem.getBodyByName("Gamma") == nullptr);
    cout << "Удаление работает корректно\n" << endl;

    cout << "Тест удаления главного тела" << endl;
    copiedSystem.removeBody(0); // Удаляем "Alpha" (основное)
    assert(copiedSystem.getPrimaryIndex() == -1);
    cout << "Удаление основного тела корректно сбрасывает индекс\n" << endl;

    cout << "Все тесты CelestialSystem пройдены успешно!" << endl;
}

