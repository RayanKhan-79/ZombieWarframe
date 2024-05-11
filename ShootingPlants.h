#pragma once
#include "Plant.h"
#include "Sentry.h"

class ShootingPlants : public Plant
{
protected:
	Bullet* Pea;

public:
	ShootingPlants(int x, int y, int health);
	virtual void UpdateAnimation(float interval);
	virtual void Shoot() { std::cout << "S-Plant\n"; }
 };

