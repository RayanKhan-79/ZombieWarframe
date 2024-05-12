#include "Repeater.h"

Repeater::Repeater(int x, int y, int health) : ShootingPlants(x, y, health)
{
	texture.loadFromFile("./Images/Repeater.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 139, 0, 139, 135));
	sprite.setPosition(Pos.x, Pos.y);
}
void Repeater::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 5)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * 139, 0, 139, 135));
}

Repeater::Repeater(int x, int y, int health, int pixelsX, int pixelsY)
	: ShootingPlants(x, y, health, pixelsX, pixelsY)
{

}
