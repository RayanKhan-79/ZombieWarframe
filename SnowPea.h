#pragma once
#include "PeaShooter.h"
class SnowPea : public PeaShooter
{

public:
	SnowPea() { }
	SnowPea(int x, int y, int health, int pixelsX=131, int pixelsY=135);
	void UpdateAnimation(float interval);
	void Shoot();
};

