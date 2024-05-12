#pragma once
#include "ShootingPlants.h"
class Repeater : public ShootingPlants
{

public:
	Repeater(int x, int y, int health, int pixelsX=139, int pixelsY=135);
	void UpdateAnimation(float interval);
};

