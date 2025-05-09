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
    // ����������� �� ���������
    CelestialSystem();

    // ����������� � ������
    CelestialSystem(double ra, double dec, double mag, const std::string& name, const std::vector<CelestialBody>& members);

    // ����� ��� ���������� ����
    void addBody();

    // ����� ��� �������� ����
    void removeBody();

};

