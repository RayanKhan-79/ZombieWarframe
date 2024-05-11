#include "Sunflower.h"
Sunflower::Sunflower() :Plant()
{
	spriteHeight = 140;
	spriteWidth = 105;
}
Sunflower::Sunflower(int x, int y, int health) :Plant(x,y,health)
{
	spriteHeight = 140;
	spriteWidth = 105;
	texture.loadFromFile("./Images/Sunflower.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * spriteWidth, 0, spriteWidth, spriteHeight));
	sprite.setPosition(Pos.x, Pos.y);
}
void Sunflower::UpdateAnimation(float deltaTime) {
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 6)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * spriteWidth, 0, spriteWidth, spriteHeight));
}
















