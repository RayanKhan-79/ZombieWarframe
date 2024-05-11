#include "FootballZombie.h"

FootballZombie::FootballZombie(int health, int speed, int damage, int x, int y, int pixelsX, int pixelsY) 
	: Zombie(health, speed, damage, x, y, pixelsX, pixelsY) 
{
	switchTime = 0.15;
	hitArea.x = Pos.x + 95;
	hitArea.y = Pos.y + pixelsY;

	texture.loadFromFile("./Images/footballZombie.png");
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
		offset++;

		if (offset == 6)
			offset = 0;
	}
	
	//if (health >= 300)
	//{
		sprite.setTextureRect(IntRect(offset * pixelsX, 0, pixelsX, pixelsY));
	//	return;
	//}



	//texture.loadFromFile("./Images/hfzanimation.png");
	//sprite.setTextureRect(IntRect(offset * 237, 0, 237, 212));

}

void FootballZombie::Move()
{
	if (action == "attacking")
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