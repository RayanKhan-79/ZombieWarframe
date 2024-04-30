#include "FootballZombie.h"

FootballZombie::FootballZombie(int health, int speed, int damage, int x, int y) : Zombie(health, speed, damage, x, y) 
{
	image.loadFromFile("./Images/ffzanimation.png");

	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 176, 0, 176, 196));



	sprite.setPosition(Pos.x, Pos.y);
}

void FootballZombie::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 3)
			offset = 0;
	}
	
	if (health >= 300)
	{
		sprite.setTextureRect(IntRect(offset * 176, 0, 176, 196));
		return;
	}



	texture.loadFromFile("./Images/hfzanimation.png");
	sprite.setTextureRect(IntRect(offset * 237, 0, 237, 212));

}

void FootballZombie::Move()
{
	Pos.x -= speed;
	health -= 3;

	int random = rand() % 20;
	
	if (random == 0 && Pos.y <= 514 - 108)
	{
		Pos.y += 108;
	}

	if (random == 19 && Pos.y >= 62 + 108)
	{
		Pos.y -= 108;
	}

	sprite.setPosition(Pos.x, Pos.y);
}