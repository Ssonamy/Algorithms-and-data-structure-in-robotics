#include "Rectangle.h"
#include <limits>
#include <stdexcept>

using namespace std;

// Конструктор инициализации
Rectangle::Rectangle(const Point2D& upperLeftCorner, const double width, const double height)
	: upperLeftCorner(upperLeftCorner), width(width), height(height) {
	if (width <= 0 || height <= 0) {
		throw invalid_argument("Ширина и высота должны быть положительными");
	}
	if (width > numeric_limits<double>::max() / height) {
		throw overflow_error("Площадь превышает максимально допустимое значение.");
	}
}

// Конструктор по умолчанию
Rectangle::Rectangle()
	: upperLeftCorner(Point2D()), width(1), height(1) {}

// Конструктор копирования
Rectangle::Rectangle(const Rectangle& other)
	: upperLeftCorner(other.upperLeftCorner), width(other.width), height(other.height) {}


// Вычисление площади
double Rectangle::calculateArea() const
{
	return width * height;
}

// Вычисление площади
double Rectangle::calculatePerimeter() const
{
	return 2 * (width + height);
}

// Проверка внутри ли точка
bool Rectangle::isInside(Point2D point) const
{
	double X = point.getX();
	double Y = point.getY();

	return (X >= upperLeftCorner.getX() &&
		X <= upperLeftCorner.getX() + width &&
		Y >= upperLeftCorner.getY() - height &&
		Y <= upperLeftCorner.getY());;
}

