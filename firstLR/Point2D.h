#pragma once
#include <iostream>


class Point2D {
private:
	double x;

	double y;

public:
	// Инициализация полей
	Point2D(const double inputX, const double inputY);

	// Конструктор по умолчанию
	Point2D();

	// Геттер X
	double getX() const;

	// Геттер Y
	double getY() const;

	// Сеттер X
	void setX(const double inputX);

	// Сеттер Y
	void setY(const double inputY);

	void print() const;

	// Перегрузка оператора ввода для ввода двух значений через пробел
	friend std::istream& operator>>(std::istream& is, Point2D& point);

};
