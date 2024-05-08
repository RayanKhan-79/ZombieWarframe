#include "Plant.h"

Plant::Plant() :Pos(0, 0), health(0), offset(0), Total_Animation_Time(0), switchTime(0)
{

}
Plant::Plant(int x, int y, int health) :Pos(x, y), health(health), offset(0), Total_Animation_Time(0), switchTime(0.2)
{
	
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
	sprite.setTextureRect(IntRect(offset * 117, 0, 117, 138));
}