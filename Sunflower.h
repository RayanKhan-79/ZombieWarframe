#pragma once
#include "Plant.h"
class Sunflower :public Plant
{
public:
	Sunflower();
	Sunflower(int x, int y, int health);
	void UpdateAnimation(float deltaTime);
};

