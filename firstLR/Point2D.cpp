#include "Point2D.h"
#include <iostream>

using namespace std;

// ����������� ��������������
Point2D::Point2D(double inputX, double inputY)
	: x(inputX), y(inputY) {}

// ����������� �� ���������
Point2D::Point2D()
	: x(0.0), y(0.0) {}

// ������ �
double Point2D::getX() const { return x; }

// ������ �
double Point2D::getY() const { return y; }

// ������ � 
void Point2D::setX(double newX) { x = newX; }

// ������ �
void Point2D::setY(double newY) { y = newY; }

// ���������� ��������� ����� ��� ����� ���� �������� ����� ������
std::istream& operator>>(std::istream& is, Point2D& point) {
	is >> point.x >> point.y;
	return is;
}