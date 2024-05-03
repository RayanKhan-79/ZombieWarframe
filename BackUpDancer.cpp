#include "BackUpDancer.h"

BackUpDancer::BackUpDancer(int health, int speed, int damage, int x, int y)
	: Zombie(health, speed, damage, x, y)
{

}

void BackUpDancer::Draw(RenderWindow& window, float deltaTime)
{
	if (!spawned)
		SpawnAnimation(deltaTime);

	else
		UpdateAnimation(deltaTime);

	if (health < 100)
	{
		texture.loadFromFile("./Images/04.png");
	}

	if (health <= 0)
	{
		texture.loadFromFile("./Images/01.png");
	}

	window.draw(sprite);
}

void BackUpDancer::Move()
{
	if (!spawned || health <= 0)
		return;

	Pos.x -= speed;
	health -= 2;
	sprite.setPosition(Pos.x, Pos.y);
}

void BackUpDancer::SpawnAnimation(float deltaTime)
{
	texture.loadFromFile("./Images/02.png");
	sprite.setTexture(texture);


	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset > 9)
		{
			texture.loadFromFile("./Images/03.png");
			sprite.setTextureRect(IntRect(offset * 125, 0, 125, 180));

			spawned = true;
			offset = 0;
			return;
		}
	}

	sprite.setTextureRect(IntRect(offset * 153, 0, 153, 180));
	sprite.setPosition(Pos.x, Pos.y);
}

void BackUpDancer::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset > 3)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * 125, 0, 125, 180));
}

