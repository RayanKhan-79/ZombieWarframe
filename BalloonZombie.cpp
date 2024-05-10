#include "BalloonZombie.h"

BalloonZombie::BalloonZombie(int health, int speed, int damage, int x, int y, int pixelsX, int pixelsY) : Zombie(health,speed,damage,x,y,pixelsX,pixelsY)
{
	texture.loadFromFile("./Images/balloon.png");
	
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
		if (offset == 3)
			offset = 0;

	}

	sprite.setTextureRect(IntRect(offset * pixelsX, 0, pixelsX, pixelsY));
}




