#pragma once
#include "CelestialSystem.h"
#include <string>
#include <vector>
#include <unordered_map>

class SkyMap
{
private:
	std::vector<CelestialSystem> systems;
	std::unordered_map<std::string, int> systemNameIndexMap;

public:

	// Конструктор с полями
	SkyMap(std::vector<CelestialSystem> system, std::unordered_map<std::string, int> systemNameIndexMap);
	
	// Добавление звездной системы на карту
	void addSystem(const CelestialSystem& system);

	// Удаление системы с карты
	void removeSystem(int index);

	// Геттер количества систем
	int getQuantity() const;

	// Геттер индекса системы по имени
	const CelestialSystem* getSystemByName(const std::string& name) const;

	// Вывод всех систем
	void printAll() const;

	// Фильтр по яркости
	void filterByMagnitude(double maxMag);

	// Поворот карты
	void rotateMap(double angleDegrees);

};

