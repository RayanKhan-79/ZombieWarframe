#pragma once
#include "ShootingPlants.h"
class PeaShooter : public ShootingPlants
{
public:
	PeaShooter();
	PeaShooter(int x, int y, int health);
	void UpdateAnimation(float deltaTime);
};

