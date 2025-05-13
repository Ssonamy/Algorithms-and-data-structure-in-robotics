#pragma once
#include "CelestialSystem.h"
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

class SkyMap {
private:
    std::vector<CelestialSystem> systems;
    std::unordered_map<std::string, int> systemNameIndexMap;

public:
    SkyMap();
    SkyMap(std::vector<CelestialSystem> systems, std::unordered_map<std::string, int> systemNameIndexMap);

    void addSystem(const CelestialSystem& system);
    void removeSystem(int index);

    int getQuantity() const;
    const CelestialSystem* getSystemByName(const std::string& name) const;
    void printAll() const;

    void filterByMagnitude(double maxMag);
    void rotateMap(double angleDegrees);
};