#pragma once
#include "ShootingPlants.h"
class SnowPea : public ShootingPlants
{
public:
	SnowPea(int x, int y, int health, int pixelsX=131, int pixelsY=135);
	void UpdateAnimation(float interval);
};

