#pragma once
#include"Zombie.h"
#include<iostream>

class FootballZombie : public Zombie
{
	
public:
	FootballZombie(int = 400, int = 3, int = 8, int = 1000, int = randGrid(240), int = 240, int = 240);
	void UpdateAnimation(float deltaTime);
	void Move();

};

