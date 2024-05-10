#pragma once
#include"Zombie.h"
class BackUpDancer : public Zombie
{
	bool spawned = false;
	int speed_y;

public:
	BackUpDancer(int = 200, int = 1, int = 5, int = 1000, int = randGrid(180), int = 125, int = 180);
	void Draw(RenderWindow&, float deltaTime);
	void SpawnAnimation(float deltaTime);
	void UpdateAnimation(float deltaTime);
	//void DeathAnimation(float deltaTime);
	void Move();
};

