#pragma once
#include "ShootingPlants.h"
class SnowPea : public ShootingPlants
{
public:
	SnowPea() { }
	SnowPea(int x, int y, int health);
	void UpdateAnimation(float interval);
};

