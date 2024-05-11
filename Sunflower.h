#pragma once
#include "Plant.h"
class Sunflower :public Plant
{
private:
	int spriteWidth;
	int spriteHeight;
public:
	Sunflower();
	Sunflower(int x, int y, int health);
	void UpdateAnimation(float deltaTime);
	int getSpriteWidth() { return spriteWidth; }
	int getSpriteHeight() { return spriteHeight;  }
};

