#pragma once
#include "Plant.h"
#include"DancingZombie.h"

class Walnut : public Plant
{
public:
	Walnut(int x, int y, int health, int pixelsX = 138, int pixelsY = 140);
	void UpdateAnimation(float deltaTime);
	void RolyPoly();
	void mark(Zombie* zombie);
	void mark(DancingZombie* zombie);
	void mark(BackUpDancer* zombie);

};

