#include "Walnut.h"

Walnut::Walnut(int x, int y, int health, int pixelsX, int pixelsY) :Plant(x,y,health, pixelsX, pixelsY)
{
	switchTime = 0.15;
	texture.loadFromFile("./Images/Wallnut_roll1.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));
	sprite.setPosition(Pos.x, Pos.y);
}
void Walnut::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 5)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * pixelsX, 0, pixelsX, pixelsY));
}

void Walnut::RolyPoly()
{
	if (Pos.x >= 1200)
		health = 0;

	Pos.x += 5;
	mid.x += 5;
	sprite.setPosition(Pos.x, Pos.y);
}

void Walnut::mark(Zombie* zombie)
{
	zombie->getHealth() -= 2000;
	Color c(0, 255, 0);
	sprite.setColor(c);
}

void Walnut::mark(DancingZombie* zombie)
{
	zombie->getHealth() -= 2000;
	Color c(0, 255, 0);
	sprite.setColor(c);
}

void Walnut::mark(BackUpDancer* zombie)
{
	zombie->getHealth() -= 2000;
	Color c(0, 255, 0);
	sprite.setColor(c);
}