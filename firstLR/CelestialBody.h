#pragma once
#include <string>

class CelestialBody {
private:
	// Координаты:
	// Прямое восхождение
	double rightAscension;
	// Координаты:
	// Склонение
	double declination;

	// Видимая звездная величина
	double magnitude;

	// Имя объекта
	std::string name;

public:
	CelestialBody();

	CelestialBody(double rightAscension, double declination, double magnitude, const std::string& name);

	CelestialBody(const CelestialBody& other);

	double getRightAscension() const;
	double getDeclination() const;
	double getMagnitude() const;
	std::string getName() const;

	void setRightAscension(double newRightAscension);
	void setDeclination(double newDeclination);
	void setMagnitude(double newMagnitude);
	void setName(const std::string& newName);

	virtual void printInfo() const;

	double normalizeAngle(double angle);
	double validateDeclination(double dec);
	double validateMagnitude(double mag);
	std::string validateName(const std::string& n);

};