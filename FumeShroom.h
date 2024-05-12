#pragma once
#include "ShootingPlants.h"
class FumeShroom : public ShootingPlants
{
public:
	FumeShroom(int x, int y, int health, int pixelsX, int pixelsY);
	void UpdateAnimation(float interval);
};

