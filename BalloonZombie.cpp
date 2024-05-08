#include "BalloonZombie.h"

BalloonZombie::BalloonZombie(int health, int speed, int damage, int x, int y) : Zombie(health,speed,damage,x,y), ballonIsPopped(false), pixelsX(150), pixelsY(210)
{
	texture.loadFromFile("./Images/balloon.png");
	
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));
}

void BalloonZombie::UpdateAnimation(float deltaTime)
{
	if (health <= 150)
		ballonIsPopped = true;

	if (ballonIsPopped)
	{
		pixelsX = 164;
		pixelsY = 180;
		speed = 1;
		texture.loadFromFile("./Images/zombie.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));
	}

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

//void BalloonZombie::fly()
//{
//
//}

void BalloonZombie::move()
{
	Pos.x -= speed;

	// Testing
	health -= 2;
	//========
	
	sprite.setPosition(Pos.x, Pos.y);
}
