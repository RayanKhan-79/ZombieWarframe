#include "BackUpDancer.h"

BackUpDancer::BackUpDancer(int health, int speed, int damage, int x, int y, int pixelsX, int pixelsY)
	: Zombie(health, speed, damage, x, y, pixelsX, pixelsY), speed_y(speed)
{
	switchTime = 0.3;
	hitArea.x = Pos.x + 95;
	hitArea.y = Pos.y + pixelsY;
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

	sprite.setPosition(Pos.x, Pos.y);
	window.draw(sprite);
}

void BackUpDancer::Move()
{
	if (action == "attacking" || Pos.x <= 150)
		return;

	if (!spawned || health <= 0)
		return;

	if (Pos.y + 180 <= 118 * 2 + 85)
		speed_y = speed;

	if (Pos.y + 180 >= 118 * 5 + 85)
		speed_y = -speed;


	Pos.x -= speed;
	hitArea.x -= speed;

	Pos.y += speed_y;
	hitArea.y += speed_y;

}

void BackUpDancer::SpawnAnimation(float deltaTime)
{
	texture.loadFromFile("./Images/02.png");
	sprite.setTexture(texture);


	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offsetX++;

		if (offsetX > 9)
		{
			texture.loadFromFile("./Images/03.png");
			sprite.setTextureRect(IntRect(offsetX * pixelsX, 0, pixelsX, pixelsY));

			spawned = true;
			offsetX = 0;
			return;
		}
	}

	sprite.setTextureRect(IntRect(offsetX * 153, 0, 153, 180));
	sprite.setPosition(Pos.x, Pos.y);
}

void BackUpDancer::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offsetX++;

		if (offsetX > 3)
			offsetX = 0;
	}
	sprite.setTextureRect(IntRect(offsetX * pixelsX, 0, pixelsX, pixelsY));
}

