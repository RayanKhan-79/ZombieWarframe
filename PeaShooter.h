#pragma once
#include "Plant.h"
class PeaShooter : public Plant
{
	Bullet* Pea;
	Clock clock;
public:
	PeaShooter(int x, int y, int health, int pixelsX = 115, int pixelsY = 135);
	void UpdateAnimation(float deltaTime);
	virtual void Shoot();
	void Draw(RenderWindow& window, float deltaTime);
	Bullet* getBullet()
	{
		return Pea;
	}
};

