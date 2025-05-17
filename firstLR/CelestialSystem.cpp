#include "CelestialSystem.h"
#include <iostream>

using namespace std;

CelestialSystem::CelestialSystem()
    : CelestialBody(){
}

CelestialSystem::CelestialSystem(double ra, double dec, double mag, const string& name,
    const vector<shared_ptr<CelestialBody>>& members,
    const unordered_map<string, int>& nameIndexMap)
    : CelestialBody(ra, dec, mag, name),
    members(members),
    nameIndexMap(nameIndexMap){
}

CelestialSystem::CelestialSystem(const CelestialSystem& other)
    : CelestialBody(other),
    members(other.members),
    nameIndexMap(other.nameIndexMap) {
}

shared_ptr<CelestialSystem> CelestialSystem::deepCopy() const {
    vector<shared_ptr<CelestialBody>> newMembers;
    unordered_map<string, int> newIndexMap;

    for (size_t i = 0; i < members.size(); ++i) {
        shared_ptr<CelestialBody> newBody = make_shared<CelestialBody>(*members[i]);
        newMembers.push_back(newBody);
        newIndexMap[newBody->getName()] = static_cast<int>(i);
    }

    return make_shared<CelestialSystem>(
        getRightAscension(),
        getDeclination(),
        getMagnitude(),
        getName(),
        newMembers,
        newIndexMap
    );
}

void CelestialSystem::addBody(const shared_ptr<CelestialBody>& body) {
    string name = body->getName();
    if (nameIndexMap.find(name) == nameIndexMap.end()) {
        members.push_back(body);
        nameIndexMap[name] = static_cast<int>(members.size()) - 1;
    }
    else {
        cerr << "Тело с именем \"" << name << "\" уже существует в системе.\n" << endl;
    }
}


void CelestialSystem::removeBody(const shared_ptr<CelestialBody>& bodyToRemove) {
    auto it = find(members.begin(), members.end(), bodyToRemove);
    if (it != members.end()) {
        int index = static_cast<int>(distance(members.begin(), it));
        string nameToRemove = (*it)->getName();

        members.erase(it);
        nameIndexMap.erase(nameToRemove);

        for (auto& pair : nameIndexMap) {
            if (pair.second > index) {
                pair.second--;
            }
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


void CelestialSystem::printInfo() const {
    cout << "Гравитационная система: " << getName() << endl;

    cout << "\nЧлены системы (" << members.size() << "):\n";
    for (size_t i = 0; i < members.size(); ++i) {
        cout << " - ";
        members[i]->printInfo();
        cout << endl;
    }
}

bool CelestialSystem::isBodyInSystemByName(const string& name) {
    auto it = nameIndexMap.find(name);
    if (it != nameIndexMap.end()) {
        return true;
    }
    else {
        return false;
    }
}

const shared_ptr<CelestialBody> CelestialSystem::getBodyByName(const string& name) const {
    auto it = nameIndexMap.find(name);
    if (it != nameIndexMap.end()) {
        return members[it->second];
    }
    return nullptr;
}