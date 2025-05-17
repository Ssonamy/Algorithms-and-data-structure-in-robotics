#pragma once
#include "CelestialBody.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

class CelestialSystem : public CelestialBody {
private:
    std::vector<std::shared_ptr<CelestialBody>> members; 
    std::unordered_map<std::string, int> nameIndexMap;

public:
    CelestialSystem();
    CelestialSystem(double ra, double dec, double mag, const std::string& name,
        const std::vector<std::shared_ptr<CelestialBody>>& members,
        const std::unordered_map<std::string, int>& nameIndexMap);

    std::shared_ptr<CelestialSystem> deepCopy() const;

    CelestialSystem(const CelestialSystem& other);

    void addBody(const std::shared_ptr<CelestialBody>& body);
    void removeBody(const std::shared_ptr<CelestialBody>& bodyToRemove);

    const std::vector<std::shared_ptr<CelestialBody>>& getMembers() const;
    std::vector<std::shared_ptr<CelestialBody>>& getMembers();

    int getQuantity() const;

    void printInfo() const override;
    const std::shared_ptr<CelestialBody> getBodyByName(const std::string& name) const;

    bool isBodyInSystemByName(const std::string& name);

};
