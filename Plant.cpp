#include "Plant.h"
Plant::Plant(int x, int y, int health) 
	: Pos(x, y), health(health), offset(0), Total_Animation_Time(0),
	switchTime(0.2), mid(x, y + 70)

Plant::Plant() :Pos(0, 0), health(0), offset(0), Total_Animation_Time(0), switchTime(0)
{

}
Plant::Plant(int x, int y, int health) :Pos(x, y), health(health), offset(0), Total_Animation_Time(0), switchTime(0.2)
{
	texture.loadFromFile("./Images/Sunflower.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 105, 140));
	sprite.setPosition(Pos.x, Pos.y);

}
void Plant::Draw(RenderWindow& window, float deltaTime)
{
	if (health > 0)
	{
		UpdateAnimation(deltaTime);
		window.draw(sprite);
	}
}

void Plant::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 8)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * 105, 0, 105, 140));
}