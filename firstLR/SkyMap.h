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

public:
    SkyMap();
    SkyMap(std::vector<std::shared_ptr<CelestialSystem>> systems, std::unordered_map<std::string, int> systemNameIndexMap);

    void addSystem(const std::shared_ptr<CelestialSystem>& system);
    void removeSystem(int index);
    void removeSystemByName(const std::string& name);
    void removeSystemByPointer(const std::shared_ptr<CelestialSystem>& systemToRemove);

    void removeBodyFromAllSystems(const std::shared_ptr<CelestialBody>& bodyToRemove);

    int getQuantity() const;
    const CelestialSystem* getSystemByName(const std::string& name) const;

    void printAll() const;
    void filterByMagnitude(double maxMag);
    void rotateMap(double angleDegrees);
};