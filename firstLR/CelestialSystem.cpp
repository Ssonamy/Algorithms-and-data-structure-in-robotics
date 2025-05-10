//   ��� ��� ��� ���������, �� � ���� ����������� ������ � ����:
// ����:
//      ����������:
//      ������ �����������;
//      ���������;
// 
//      ������� �������� ��������;
//      ��� �������;

// ������:
//      ������� ���� �����
//      ������� ���� �����
//      printInfo
//      ������ ��� ���������

#include "CelestialSystem.h"

using namespace std;


CelestialSystem::CelestialSystem()
    : CelestialBody(), members(), primaryIndex(-1), nameIndexMap() {
}

CelestialSystem::CelestialSystem(double ra, double dec, double mag, const string& name, const vector<CelestialBody>& members, const unordered_map<string, int>& nameIndexMap, int primaryIndex)
    : CelestialBody(ra, dec, mag, name),
    members(members),
    nameIndexMap(nameIndexMap),
    primaryIndex(primaryIndex) {
}

CelestialSystem::CelestialSystem(const CelestialSystem& other)
    : CelestialBody(other),
    members(other.members),
    primaryIndex(other.primaryIndex),
    nameIndexMap(other.nameIndexMap) {
}

void CelestialSystem::addBody(const CelestialBody& body) {
    string name = body.getName();
    if (nameIndexMap.find(name) == nameIndexMap.end()) {
        members.push_back(body);
        nameIndexMap[name] = members.size() - 1;
    }
    else {
        cerr << "���� � ������ \"" << name << "\" ��� ���������� � �������.\n";
    }
}

void CelestialSystem::removeBody(int index) {
    if (index >= 0 && index < members.size()) {
        string nameToRemove = members[index].getName();
        members.erase(members.begin() + index);
        nameIndexMap.erase(nameToRemove);

        // ��������� �������
        for (auto& pair : nameIndexMap) {
            if (pair.second > index)
                pair.second--;
        }

        if (primaryIndex == index) {
            primaryIndex = -1;
        }
        else if (primaryIndex > index) {
            primaryIndex--;
        }
    }
}

const vector<CelestialBody>& CelestialSystem::getMembers() const {
    return members;
}

int CelestialSystem::getQuantity() const{
    return members.size();
}

int CelestialSystem::getPrimaryIndex() const{
    return primaryIndex;
}
void CelestialSystem::printInfo() const {
    cout << "�������������� �������: " << getName() << endl;

    if (primaryIndex >= 0 && primaryIndex < members.size()) {
        cout << "\n�������� ����:\n";   
        members[primaryIndex].printInfo();
    }

    cout << "\n����� ������� (" << members.size() << "):\n";
    for (size_t i = 0; i < members.size(); ++i) {
        if (static_cast<int>(i) == primaryIndex) {
            cout << " - (������� ����) ";
        }
        else {
            cout << " - ";
        }
        members[i].printInfo();
        cout << endl;
    }
}

const CelestialBody* CelestialSystem::getBodyByName(const string& name) const {
    auto it = nameIndexMap.find(name);
    if (it != nameIndexMap.end()) {
        return &members[it->second];
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
