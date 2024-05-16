#include "BalloonZombie.h"

BalloonZombie::BalloonZombie(int health, int speed, int damage, int x, int y, int pixelsX, int pixelsY) : Zombie(health,speed,damage,x,y,pixelsX,pixelsY), offsetY(0)
{
	switchTime = 0.1f;
	texture.loadFromFile("./Images/baaalooon.png");
	
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));
}

void BalloonZombie::UpdateAnimation(float deltaTime)
{

	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;
		if (offset == 6)
		{
			offsetY++;
			offset = 0;
			if (offsetY == 4)
				offsetY = 0;
		}

	}

	sprite.setTextureRect(IntRect(offset * pixelsX, offsetY * pixelsY, pixelsX, pixelsY));
}




