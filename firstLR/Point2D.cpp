#include "Point2D.h"
#include <iostream>

using namespace std;

// Конструктор инициалихзации
Point2D::Point2D(double inputX, double inputY)
	: x(inputX), y(inputY) {}

// Конструктор по умолчанию
Point2D::Point2D()
	: x(0.0), y(0.0) {}

// Геттер Х
double Point2D::getX() const { return x; }

// Геттер У
double Point2D::getY() const { return y; }

// Сеттер Х 
void Point2D::setX(double newX) { x = newX; }

// Сеттер У
void Point2D::setY(double newY) { y = newY; }

// Перегрузка оператора ввода для ввода двух значений через пробел
std::istream& operator>>(std::istream& is, Point2D& point) {
	is >> point.x >> point.y;
	return is;
}