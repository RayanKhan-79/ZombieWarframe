#pragma once
#include"Zombie.h"
#include<iostream>

class FootballZombie : public Zombie
{

public:
	FootballZombie(int = 600, int = 3, int = 8, int = 1000, int = randGrid(180), int = 215, int = 180);
	void UpdateAnimation(float deltaTime);
	void Move();

};

