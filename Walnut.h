#pragma once
#include "Plant.h"
class Walnut : public Plant
{
public:
	Walnut();
	Walnut(int x, int y, int health);
	void UpdateAnimation(float deltaTime);
};

