#pragma once
#include "Plant.h"
class PeaShooter : public Plant
{
protected:
	Bullet** Pea;
	int bulletCount;
	Clock clock;
public:
	PeaShooter(int x, int y, int health, int pixelsX = 111, int pixelsY = 135);
	void UpdateAnimation(float deltaTime);
	virtual void Shoot();
	void Draw(RenderWindow& window, float deltaTime);
	int getBulletCount() { return bulletCount; }
	Bullet** getBullet()
	{
		return Pea;
	}
};

