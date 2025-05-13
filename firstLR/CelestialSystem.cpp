#include "CelestialSystem.h"
#include <iostream>

using namespace std;

CelestialSystem::CelestialSystem()
    : CelestialBody(), primaryIndex(-1) {
}

CelestialSystem::CelestialSystem(double ra, double dec, double mag, const string& name,
    const vector<shared_ptr<CelestialBody>>& members,
    const unordered_map<string, int>& nameIndexMap,
    int primaryIndex)
    : CelestialBody(ra, dec, mag, name),
    members(members),
    nameIndexMap(nameIndexMap),
    primaryIndex(primaryIndex) {
}

CelestialSystem::CelestialSystem(const CelestialSystem& other)
    : CelestialBody(other),
    members(other.members),
    nameIndexMap(other.nameIndexMap),
    primaryIndex(other.primaryIndex) {
}

void CelestialSystem::addBody(const shared_ptr<CelestialBody>& body) {
    string name = body->getName();
    if (nameIndexMap.find(name) == nameIndexMap.end()) {
        members.push_back(body);
        nameIndexMap[name] = static_cast<int>(members.size()) - 1;
    }
    else {
        cerr << "Тело с именем \"" << name << "\" уже существует в системе.\n";
    }
}

void CelestialSystem::removeBody(const shared_ptr<CelestialBody>& bodyToRemove) {
    for (size_t i = 0; i < members.size(); ++i) {
        if (members[i] == bodyToRemove) {
            string nameToRemove = members[i]->getName();
            members.erase(members.begin() + i);

            for (auto& pair : nameIndexMap) {
                if (pair.second > index) pair.second--;
            }

            if (primaryIndex == index) primaryIndex = -1;
            else if (primaryIndex > index) primaryIndex--;
        }
    }
}

const vector<shared_ptr<CelestialBody>>& CelestialSystem::getMembers() const {
    return members;
}

vector<shared_ptr<CelestialBody>>& CelestialSystem::getMembers() {
    return members;
}

int CelestialSystem::getQuantity() const {
    return static_cast<int>(members.size());
}

int CelestialSystem::getPrimaryIndex() const {
    return primaryIndex;
}

void CelestialSystem::printInfo() const {
    cout << "Гравитационная система: " << getName() << endl;

    if (primaryIndex >= 0 && primaryIndex < members.size()) {
        cout << "\nОсновное тело:\n";
        members[primaryIndex]->printInfo();
    }

    cout << "\nЧлены системы (" << members.size() << "):\n";
    for (size_t i = 0; i < members.size(); ++i) {
        if (static_cast<int>(i) == primaryIndex) cout << " - (главное тело) ";
        else cout << " - ";
        members[i]->printInfo();
        cout << endl;
    }
}

const shared_ptr<CelestialBody> CelestialSystem::getBodyByName(const string& name) const {
    auto it = nameIndexMap.find(name);
    if (it != nameIndexMap.end()) {
        return members[it->second];
    }
    return nullptr;
}

bool CelestialSystem::setPrimaryByName(const string& name) {
    auto it = nameIndexMap.find(name);
    if (it != nameIndexMap.end()) {
        primaryIndex = it->second;
        return true;
    }
    return false;
}