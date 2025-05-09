#pragma once
#include "CelestialBody.h"
#include <vector>
#include <string>

class CelestialSystem :
    public CelestialBody
{
private:
    std::vector<CelestialBody> members;

public:
    // Конструктор по умолчанию
    CelestialSystem();

    // Конструктор с полями
    CelestialSystem(double ra, double dec, double mag, const std::string& name, const std::vector<CelestialBody>& members);

    // Метод для добавления тела
    void addBody();

    // Метод для удаления тела
    void removeBody();

};

