#include "Rectangle.h"
#include <limits>
#include <stdexcept>

using namespace std;

// ����������� �������������
Rectangle::Rectangle(const Point2D& upperLeftCorner, const double width, const double height)
	: upperLeftCorner(upperLeftCorner), width(width), height(height) {
	if (width <= 0 || height <= 0) {
		throw invalid_argument("������ � ������ ������ ���� ��������������");
	}
	if (width > numeric_limits<double>::max() / height) {
		throw overflow_error("������� ��������� ����������� ���������� ��������.");
	}
}

// ����������� �� ���������
Rectangle::Rectangle()
	: upperLeftCorner(Point2D()), width(1), height(1) {}

// ����������� �����������
Rectangle::Rectangle(const Rectangle& other)
	: upperLeftCorner(other.upperLeftCorner), width(other.width), height(other.height) {}


// ���������� �������
double Rectangle::calculateArea() const
{
	return width * height;
}

// ���������� �������
double Rectangle::calculatePerimeter() const
{
	return 2 * (width + height);
}

// �������� ������ �� �����
bool Rectangle::isInside(Point2D point) const
{
	double X = point.getX();
	double Y = point.getY();

	return (X >= upperLeftCorner.getX() &&
		X <= upperLeftCorner.getX() + width &&
		Y >= upperLeftCorner.getY() - height &&
		Y <= upperLeftCorner.getY());;
}

