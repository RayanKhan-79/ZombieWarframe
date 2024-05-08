#include "Walnut.h"
Walnut::Walnut()
{

}
Walnut::Walnut(int x, int y, int health) :Plant(x,y,health)
{
	texture.loadFromFile("./Images/Wallnut.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 115, 0, 115, 135));
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
	sprite.setTextureRect(IntRect(offset * 115, 0, 115, 135));
}