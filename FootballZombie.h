#pragma once
#include"Zombie.h"
class FootballZombie : public Zombie
{



public:
	FootballZombie(int = 600, int = 3, int = 8, int = 1000, int = randGrid(170));
	void UpdateAnimation(float deltaTime);
};

