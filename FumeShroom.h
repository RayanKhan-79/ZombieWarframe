#pragma once
#include "Plant.h"
class FumeShroom : public Plant
{
	Bullet* Pea;
	Clock clock;
public:
	FumeShroom(int x, int y, int health, int pixelsX, int pixelsY);
	void UpdateAnimation(float interval);
};

