#include "CelestialSystem.h"

using namespace std;

CelestialSystem::CelestialSystem()
	: CelestialBody(), members() {
}

CelestialSystem::CelestialSystem(double ra, double dec, double mag, const std::string& name, const std::vector<CelestialBody>& members)
	: CelestialBody(ra, dec, mag, name), 
	members(members) {
}

//CelestialSystem::addBody() {
// 
//}

//CelestialSystem::removeBody(){
//
//}