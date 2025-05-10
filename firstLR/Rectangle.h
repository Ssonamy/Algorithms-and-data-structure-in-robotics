#pragma once
#include "Point2D.h"

class Rectangle {
private:
	Point2D upperLeftCorner;

	double width;

	double height;

public:

	// ����������� �� ���������
	Rectangle();

	// ����������� �������������
	Rectangle(const Point2D& upperLeftCorner, double width, double height);

	// ����������� �����������
	Rectangle(const Rectangle& other);

	// ���������� �������
	double calculateArea() const;

	// ���������� �������
	double calculatePerimeter()  const;

	// �������� ������ �� �����
	bool isInside(Point2D point) const;
};