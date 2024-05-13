#pragma once
#include "PeaShooter.h"
class Repeater : public PeaShooter
{

public:
	Repeater() { }
	Repeater(int x, int y, int health, int pixelsX=139, int pixelsY=135);
	void UpdateAnimation(float interval);
	void Draw(RenderWindow& window, float deltaTime);
	void Shoot();
};

