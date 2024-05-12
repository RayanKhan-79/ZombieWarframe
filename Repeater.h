#pragma once
#include "ShootingPlants.h"
class Repeater : public ShootingPlants
{
public:
	Repeater() { }
	Repeater(int x, int y, int health);
	void UpdateAnimation(float interval);
};

