#pragma once
#include"Zombie.h"
#include<iostream>

class FootballZombie : public Zombie
{

//	int offset_y = 0;

public:
	FootballZombie(int = 400, int = 3, int = 8, int = 1000, int = randGrid(180), int = 215, int = 180);
	void UpdateAnimation(float deltaTime);
	void Move();

};

