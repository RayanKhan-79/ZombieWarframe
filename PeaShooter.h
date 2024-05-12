#pragma once
#include "ShootingPlants.h"
class PeaShooter : public ShootingPlants
{

public:
	PeaShooter(int x, int y, int health, int pixelsX = 115, int pixelsY = 135);
	void UpdateAnimation(float deltaTime);
	void Shoot();
	void Draw(RenderWindow& window, float deltaTime);
	Bullet* getBullet()
	{
		return Pea;
	}
};

