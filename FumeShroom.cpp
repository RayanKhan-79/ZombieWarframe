#include "FumeShroom.h"
FumeShroom::FumeShroom(int x, int y, int health, int pixelsX, int pixelsY)
	: Plant(x,y,health, pixelsX, pixelsY)
{
	texture.loadFromFile("./Images/Fume-Shroom.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));
	sprite.setPosition(Pos.x, Pos.y);
}
void FumeShroom::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 4)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * pixelsX, 0, pixelsX, pixelsY));
}