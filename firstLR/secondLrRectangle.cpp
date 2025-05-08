#include <iostream>
#include "functions.h"
#include "Rectangle.h"
#include "tests.h"
#include <clocale>

//#include "Point2D.h"

using namespace std;
void ex() {
    Rectangle exampleRect(Point2D(0.0, 0.0), 15, 10); // Создание экземпляра для вывода примера
    cout << endl <<  "Создан прямоугольник с левой верхней точкой в (0,0) шириной 15 и высотой 10" << endl;
    cout << "Площадь прямоугольника равна: " << exampleRect.calculateArea() << endl;
    cout << "Периметр прямоугольника равен: " << exampleRect.calculatePerimeter() << endl;
    if (exampleRect.isInside(Point2D(7, 7)))
        cout << "Точка с координатами (7, 7) находится в пределах прямоугольника" << endl;
    
    else 
        cout << "Точка с координатами (7, 7) не находится в пределах прямоугольника" << endl;

    if (exampleRect.isInside(Point2D(0, -2)))
        cout << "Точка с координатами (0, -2) находится в пределах прямоугольника" << endl;

    else
        cout << "Точка с координатами (0, -2) не находится в пределах прямоугольника" << endl << endl;
}

bool secondLrRectangle()
{
    std::setlocale(LC_ALL, "ru_RU.utf8");

    Rectangle rect; // Инициализация пустого экземпляра для последующей работы с ним
    Point2D point;

    cout << "Прямоугольник" << endl;

    while (true) {

        cout << "Введите:\n";
        cout << "1. Создать новый прямоугольник" << endl;
        cout << "2. Найти периметр" << endl;
        cout << "3. Найти площадь" << endl;
        cout << "4. Проверить точку" << endl;
        cout << "5. Вывести пример" << endl;
        cout << "6. Запуск тестов" << endl;
        cout << "0. Назад" << endl;
        cout << "-1. Выход" << endl;

        int forSwitch = autoInput();

        switch (forSwitch)
        {

        default:
            cout << "Некорректное значение." << endl;
            break;

        case 1:
            double width, height;
            cout << "Введите координаты левой верхней точки через пробел: ";
            cin >> point;
            cout << endl << "Введите ширину: ";
            cin >> width;
            cout << endl << "Введите высоту: ";
            cin >> height; cout << endl;
            try {
                rect = Rectangle(point, width, height);
                cout << "Прямоугольник успешно создан!" << endl;
            }
            catch (const invalid_argument&) {
                cout << "Ошибка: Некорректное значение" << endl;
            }

            break;

        case 2:
        {
            cout << "Периметр прямоугольника равен " << rect.calculatePerimeter() << endl;
            break;
        }
        case 3:
        {
            cout << "Площадь прямоугольника равна " << rect.calculateArea() << endl;
            break;
        }
        case 4:
        {
            cout << "Введите точку: ";
            cin >> point;
            if (rect.isInside(point))
                cout << "Точка находится внутри прямоугольника." << endl;
            else
                cout << "Точка не находится внутри прямоугольника." << endl;
            break;
        }
        case 5:
           ex();
            break;

        case 6:
            testRectangleClass();
            break;

        case 0:
            cout << endl << "Главное меню" << endl;
            return 0;
        case -1:
            cout << endl << "Завершение программы." << endl;

            return 1;
        }
    }
}