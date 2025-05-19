#include "SkyMap.h"
#include <cmath>

using namespace std;

SkyMap::SkyMap() : systems(), systemNameIndexMap(), name("") {}
SkyMap::SkyMap(const vector<shared_ptr<CelestialSystem>> systems, unordered_map<string, int> systemNameIndexMap, const string& name)
    : systems(systems), systemNameIndexMap(systemNameIndexMap), name(name) {
}
SkyMap::SkyMap(const SkyMap& other)
: systems(other.systems), systemNameIndexMap(other.systemNameIndexMap), name(other.name) {}

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

shared_ptr<SkyMap> SkyMap::deepCopy() const {
    vector<shared_ptr<CelestialSystem>> newSystems; 
    unordered_map<string, int> newIndexMap;

    for (const auto& system : systems) {
        auto clonedSystem = system->deepCopy();
        newIndexMap[clonedSystem->getName()] = static_cast<int>(newSystems.size());
        newSystems.push_back(clonedSystem);
    }

    string newName = "Копия " +  getName();
    return make_shared<SkyMap>(newSystems, newIndexMap, newName);
}

void SkyMap::setName(const string& newName) {
    name = newName;
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

int SkyMap::getQuantity() const {
    return static_cast<int>(systems.size());
}
string SkyMap::getName() const {
    return name;
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

bool SkyMap::isSystemInMapByName(const string& name)
{
    for (const auto& system : systems) {
        if (system->getName() == name) {
            return true;
        }
    }
        return false;
}

shared_ptr<SkyMap> SkyMap::filterByMagnitude(double maxMag) {
    auto newMap = make_shared<SkyMap>();

    for (const auto& system : systems) {
        vector<shared_ptr<CelestialBody>> filteredBodies;
        unordered_map<string, int> newIndexMap;

        const auto& bodies = system->getMembers();
        for (size_t i = 0; i < bodies.size(); ++i) {
            if (bodies[i]->getMagnitude() <= maxMag) {
                newIndexMap[bodies[i]->getName()] = static_cast<int>(filteredBodies.size());
                filteredBodies.push_back(bodies[i]);
            }
        }

        if (!filteredBodies.empty()) {
            auto filteredSystem = make_shared<CelestialSystem>(
                system->getRightAscension(),
                system->getDeclination(),
                system->getMagnitude(),
                system->getName(),
                filteredBodies,
                newIndexMap
            );
            newMap->addSystem(filteredSystem);
        }
    }

    return newMap;
}

void SkyMap::printInfo() const {
    cout << "Карта (" << getQuantity() <<  "): " << name << endl << endl;
    for (const auto& system : systems) {
        system->printInfo();
    }
}