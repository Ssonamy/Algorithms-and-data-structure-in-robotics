#pragma once
#include "Point2D.h"

class Rectangle {
private:
	Point2D upperLeftCorner;

	double width;

	double height;

public:

	// Конструктор по умолчанию
	Rectangle();

	// Конструктор инициализации
	Rectangle(const Point2D& upperLeftCorner, double width, double height);

	// Конструктор копирования
	Rectangle(const Rectangle& other);

	// Вычисление площади
	double calculateArea() const;

	// Вычисление площади
	double calculatePerimeter()  const;

	// Проверка внутри ли точка
	bool isInside(Point2D point) const;
};