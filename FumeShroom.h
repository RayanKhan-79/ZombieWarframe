#pragma once
#include "ShootingPlants.h"
class FumeShroom : public ShootingPlants
{
public:
	FumeShroom(int x, int y, int health);
	void UpdateAnimation(float interval);
};

