#pragma once
#include"Zombie.h"
#include"BackUpDancer.h"

class DancingZombie : public Zombie
{
	int speed_y;
	float spawnInterval;
	Clock clock;



public:
	DancingZombie(float = 5, int = 200, int = 3, int = 5, int = 1000, int = randGrid(180), int = 125, int = 180);
	void UpdateAnimation(float deltaTime);
	void SummonBackUp(BackUpDancer**& backUp);
	void resetTime()
	{
		clock.restart();
	}
	void Move();


};

