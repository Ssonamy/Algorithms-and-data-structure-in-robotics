#pragma once
#include <iostream>


class Point2D {
private:
	double x;

	double y;

public:
	// ������������� �����
	Point2D(const double inputX, const double inputY);

	// ����������� �� ���������
	Point2D();

	// ������ X
	double getX() const;

	// ������ Y
	double getY() const;

	// ������ X
	void setX(const double inputX);

	// ������ Y
	void setY(const double inputY);

	void print() const;

	// ���������� ��������� ����� ��� ����� ���� �������� ����� ������
	friend std::istream& operator>>(std::istream& is, Point2D& point);

};
