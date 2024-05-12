#pragma once
#include "Plant.h"
#include "Bullet.h"

class ShootingPlants : public Plant
{
protected:
	Bullet* Pea;
	Clock clock;

public:
	ShootingPlants(int x, int y, int health, int pixelsX, int pixelsY);
	virtual void UpdateAnimation(float interval);
	virtual void Shoot() { std::cout << "S-Plant\n"; }
 };

