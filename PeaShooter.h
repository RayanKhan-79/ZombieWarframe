#pragma once
#include "ShootingPlants.h"
class PeaShooter : public ShootingPlants
{
	Clock clock;
public:
	PeaShooter(int x, int y, int health);
	void UpdateAnimation(float deltaTime);
	void Shoot();
	void Draw(RenderWindow& window, float deltaTime);
	Bullet* getBullet()
	{
		return Pea;
	}
};

