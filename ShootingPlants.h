#pragma once
#include "Plant.h"
class ShootingPlants : public Plant
{
public:
	ShootingPlants() { }
	ShootingPlants(int x, int y, int health);
	virtual void UpdateAnimation(float interval);
 };

