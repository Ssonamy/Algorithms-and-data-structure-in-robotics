#pragma once
#include "CelestialSystem.h"
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

class SkyMap {
private:
    std::unordered_map<std::string, int> systemNameIndexMap;
    std::vector<std::shared_ptr<CelestialSystem>> systems;
    std::string name;
    
public:
    SkyMap();
    SkyMap(const std::vector<std::shared_ptr<CelestialSystem>> systems, const std::unordered_map<std::string, int> systemNameIndexMap, const std::string& name = "Карта");

    SkyMap(const SkyMap& other);
    std::shared_ptr<SkyMap> deepCopy() const;

    void addSystem(const std::shared_ptr<CelestialSystem>& system);
    void removeSystem(int index);
    void removeSystemByName(const std::string& name);
    void removeSystemByPointer(const std::shared_ptr<CelestialSystem>& systemToRemove);

    int getQuantity() const;
    const CelestialSystem* getSystemByName(const std::string& name) const;

    void printAll() const;
    void filterByMagnitude(double maxMag);
    void rotateMap(double angleDegrees);

    bool isSystemInSystemByName(const std::string& name);
};