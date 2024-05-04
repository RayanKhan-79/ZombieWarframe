#include "Plant.h"
Plant::Plant(int x, int y, int health) :Pos(x, y), health(health), offset(0), Total_Animation_Time(0), switchTime(0.3)
{
	texture.loadFromFile("./Images/Sunflower.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 101, 0, 101, 135));
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

		if (offset > 6)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * 101, 0, 101, 138));
}