#pragma once
#include "ShootingPlants.h"
class Repeater : public ShootingPlants
{
	Repeater() { }
	Repeater(int x, int y, int health);
	void UpdateAnimation(float interval);
};

