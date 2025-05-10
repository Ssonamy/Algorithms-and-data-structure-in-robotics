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
    std::unordered_map<std::string, int> nameIndexMap; // имя - индекс
    int primaryIndex;

public:
    // Конструктор по умолчанию
    CelestialSystem();

    // Конструктор с полями
    CelestialSystem(double ra, double dec, double mag, const std::string& name, const std::vector<CelestialBody>& members, const std::unordered_map<std::string, int>& nameIndexMap, int primaryIndex = -1);

    // Конструктор копирования
    CelestialSystem(const CelestialSystem& other);

    // Метод для добавления тела
    void addBody(const CelestialBody& body);

    // Метод для удаления тела
    void removeBody(int index);

    // Метод для вывода тел-членов системы
    const std::vector<CelestialBody>& getMembers() const;

    // Метод возвращающий количество тел-членов системы
    int getQuantity() const;

    // Геттер индекса главного тела
    int getPrimaryIndex() const;

    // Переопределенный метод вывода информации
    void printInfo() const override;
    
    // Метод для вывода индекса по имени тела
    const CelestialBody* getBodyByName(const std::string& name) const;

    // Метод для установления главного тела системы
    bool setPrimaryByName(const std::string& name);

};
