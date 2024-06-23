#include "FootballZombie.h"

FootballZombie::FootballZombie(int health, int speed, int damage, int x, int y, int pixelsX, int pixelsY) 
	: Zombie(health, speed, damage, x, y, pixelsX, pixelsY)
{
	hitArea.x = Pos.x + 95;
	hitArea.y = Pos.y + pixelsY;

	texture.loadFromFile("./Images/football_zombie.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));

	sprite.setPosition(Pos.x, Pos.y);
}

void FootballZombie::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offsetX++;

		if (offsetX == 5)
		{
			offsetX = 0;
			offsetY++;

			if (offsetY == 6)
				offsetY = 0;
		}
	}
	
		sprite.setTextureRect(IntRect(offsetX * pixelsX, offsetY * pixelsY, pixelsX, pixelsY));


}

void FootballZombie::Move()
{
	if (action == "attacking" || Pos.x <= 150)
		return;

	Pos.x -= speed;
	hitArea.x -= speed;

	int random = rand() % 50;
	
	if (random == 0 && Pos.y + 180 <= 118*4 + 85)
	{
		Pos.y += 118;
		hitArea.y += 118;
	}

	if (random == 49 && Pos.y + 180 >= 118*2 + 85)
	{
		Pos.y -= 118;
    	hitArea.y -= 118;
	}

	//sprite.setPosition(Pos.x, Pos.y);
}