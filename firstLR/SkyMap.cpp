#include "SkyMap.h"
#include <cmath>

using namespace std;

SkyMap::SkyMap() : systems(), systemNameIndexMap() {}

SkyMap::SkyMap(vector<shared_ptr<CelestialSystem>> systems, unordered_map<string, int> systemNameIndexMap)
    : systems(systems), systemNameIndexMap(systemNameIndexMap) {
}

void SkyMap::addSystem(const shared_ptr<CelestialSystem>& system) {
    string name = system->getName();
    if (systemNameIndexMap.find(name) == systemNameIndexMap.end()) {
        systems.push_back(system);
        systemNameIndexMap[name] = static_cast<int>(systems.size()) - 1;
    }
    else {
        cerr << "Система с именем \"" << name << "\" уже существует в системе.\n";
    }
}

void SkyMap::removeSystem(int index) {
    if (index >= 0 && index < static_cast<int>(systems.size())) {
        string nameToRemove = systems[index]->getName();
        systems.erase(systems.begin() + index);
        systemNameIndexMap.erase(nameToRemove);

        for (auto& pair : systemNameIndexMap) {
            if (pair.second > index) pair.second--;
        }
    }
}

void SkyMap::removeSystemByName(const string& name) {
    auto it = systemNameIndexMap.find(name);
    if (it != systemNameIndexMap.end()) {
        int index = it->second;
        systems.erase(systems.begin() + index);
        systemNameIndexMap.erase(it);

        for (auto& pair : systemNameIndexMap) {
            if (pair.second > index) pair.second--;
        }
        cout << "Система \"" << name << "\" удалена.\n";
    }
    else {
        cerr << "Система с именем \"" << name << "\" не найдена.\n";
    }
}

void SkyMap::removeSystemByPointer(const shared_ptr<CelestialSystem>& systemToRemove) {
    for (size_t i = 0; i < systems.size(); ++i) {
        if (systems[i] == systemToRemove) {
            string name = systems[i]->getName();
            systems.erase(systems.begin() + i);
            systemNameIndexMap.erase(name);

            for (auto& pair : systemNameIndexMap) {
                if (pair.second > static_cast<int>(i)) pair.second--;
            }
            cout << "Система \"" << name << "\" удалена по указателю.\n";
            return;
        }
    }
    cerr << "Система не найдена по указателю.\n";
}

void SkyMap::removeBodyFromAllSystems(const shared_ptr<CelestialBody>& bodyToRemove) {
    for (auto& system : systems) {
        system->removeBody(bodyToRemove);
    }
}

int SkyMap::getQuantity() const {
    return static_cast<int>(systems.size());
}

const CelestialSystem* SkyMap::getSystemByName(const string& name) const {
    auto it = systemNameIndexMap.find(name);
    if (it != systemNameIndexMap.end()) {
        return systems[it->second].get();
    }
    return nullptr;
}


void SkyMap::rotateMap(double angleDegrees) {
    for (auto& system : systems) {
        system->setRightAscension(fmod(system->getRightAscension() + angleDegrees + 360.0, 360.0));
        auto& members = system->getMembers();
        for (auto& body : members) {
            double newRA = fmod(body->getRightAscension() + angleDegrees + 360.0, 360.0);
            body->setRightAscension(newRA);
        }
    }
}

void SkyMap::filterByMagnitude(double maxMag) {
    vector<shared_ptr<CelestialSystem>> filteredSystems;
    unordered_map<string, int> newSystemIndexMap;

    for (const auto& system : systems) {
        vector<shared_ptr<CelestialBody>> filteredBodies;
        unordered_map<string, int> newIndexMap;
        int newPrimaryIndex = -1;

        const auto& bodies = system->getMembers();
        for (size_t i = 0; i < bodies.size(); ++i) {
            if (bodies[i]->getMagnitude() <= maxMag) {
                newIndexMap[bodies[i]->getName()] = static_cast<int>(filteredBodies.size());
                filteredBodies.push_back(bodies[i]);
                if (i == static_cast<size_t>(system->getPrimaryIndex())) {
                    newPrimaryIndex = static_cast<int>(filteredBodies.size()) - 1;
                }
            }
        }

        if (!filteredBodies.empty()) {
            auto filteredSystem = make_shared<CelestialSystem>(
                system->getRightAscension(),
                system->getDeclination(),
                system->getMagnitude(),
                system->getName(),
                filteredBodies,
                newIndexMap,
                newPrimaryIndex
            );
            newSystemIndexMap[filteredSystem->getName()] = static_cast<int>(filteredSystems.size());
            filteredSystems.push_back(filteredSystem);
        }
    }

    systems = filteredSystems;
    systemNameIndexMap = newSystemIndexMap;
}

void SkyMap::printAll() const {
    for (const auto& system : systems) {
        system->printInfo();
    }
}