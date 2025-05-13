#include "CelestialBody.h"
#include "clocale"

using namespace std; 

CelestialBody::CelestialBody()
	: rightAscension(0), declination(0), magnitude(0), name("Unnamed") {}

CelestialBody::CelestialBody(double rightAscension, double declination, double magnitude, const string& name)
	: rightAscension(normalizeAngle(rightAscension)), 
	declination(validateDeclination(declination)), 
	magnitude(validateMagnitude(magnitude)), 
	name(validateName(name)) {}

CelestialBody::CelestialBody(const CelestialBody& other)
	: rightAscension(normalizeAngle(other.rightAscension)),
	declination(validateDeclination(other.declination)),
	magnitude(validateMagnitude(other.magnitude)),
	name(validateName(other.name)) {}

double CelestialBody::getRightAscension() const {
	return rightAscension;
}
double CelestialBody::getDeclination() const {
	return declination;
}
double CelestialBody::getMagnitude() const {
	return magnitude;
}
string CelestialBody::getName() const {
	return name;
}

void CelestialBody::setRightAscension(double newRightAscension) {
	rightAscension = normalizeAngle(newRightAscension);
}

void CelestialBody::setDeclination(double newDeclination) {
	declination = validateDeclination(newDeclination);
}

void CelestialBody::setMagnitude(double newMagnitude) {
	magnitude = validateMagnitude(newMagnitude);
}
void CelestialBody::setName(const std::string& newName) {
	name = validateName(newName);
}

void CelestialBody::printInfo() const {
	setlocale(LC_ALL, "ru_RU.utf8");

	cout << "\nИмя тела: " << name << endl;
	cout << "Координаты тела:\nПрямое восхождение: " << rightAscension;
	cout << "\nСклонение: " << declination;
	cout << "\nВидимая звездная величина: " << magnitude;
}

double CelestialBody::normalizeAngle(double angle) {
	return fmod(fmod(angle, 360.0) + 360.0, 360.0);
}

double CelestialBody::validateDeclination(double dec) {
	if (dec < -90.0 || dec > 90.0) {
		throw invalid_argument("Склонение должно быть в диапазоне от -90 до 90 градусов.");
	}
	return dec;
}

double CelestialBody::validateMagnitude(double mag) {
	if (mag < -30.0 || mag > 30.0) {
		throw invalid_argument("Недопустимое значение видимой звездной величины.");
	}
	return mag;
}

string CelestialBody::validateName(const string& n) {
	if (n.empty()) {
		return "Unnamed";
	}
	return n;
}
