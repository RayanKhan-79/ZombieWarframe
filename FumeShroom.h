#pragma once
#include "Plant.h"
class FumeShroom : public Plant
{
	Clock clock;
public:
	FumeShroom(int x, int y, int health, int pixelsX = 145, int pixelsY = 140);
	void UpdateAnimation(float interval);
};

