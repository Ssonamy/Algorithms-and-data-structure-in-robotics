#pragma once
#include "CelestialBody.h"
#include <vector>
#include <string>
#include <unordered_map>


class CelestialSystem :
    public CelestialBody
{
private:
    std::vector<CelestialBody> members;
    std::unordered_map<std::string, int> nameIndexMap; // ��� - ������
    int primaryIndex;

public:
    // ����������� �� ���������
    CelestialSystem();

    // ����������� � ������
    CelestialSystem(double ra, double dec, double mag, const std::string& name, const std::vector<CelestialBody>& members, const std::unordered_map<std::string, int>& nameIndexMap, int primaryIndex = -1);

    // ����������� �����������
    CelestialSystem(const CelestialSystem& other);

    // ����� ��� ���������� ����
    void addBody(const CelestialBody& body);

    // ����� ��� �������� ����
    void removeBody(int index);

    // ����� ��� ������ ���-������ �������
    const std::vector<CelestialBody>& getMembers() const;

    // ����� ������������ ���������� ���-������ �������
    int getQuantity() const;

    // ������ ������� �������� ����
    int getPrimaryIndex() const;

    // ���������������� ����� ������ ����������
    void printInfo() const override;
    
    // ����� ��� ������ ������� �� ����� ����
    const CelestialBody* getBodyByName(const std::string& name) const;

    // ����� ��� ������������ �������� ���� �������
    bool setPrimaryByName(const std::string& name);

};
