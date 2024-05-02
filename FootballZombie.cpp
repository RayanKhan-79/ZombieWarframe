#include "FootballZombie.h"

FootballZombie::FootballZombie(int health, int speed, int damage, int x, int y) : Zombie(health, speed, damage, x, y) 
{
	switchTime = 0.15;
	//image.loadFromFile("./Images/image_2_2.png");

	//texture.loadFromImage(image);
	texture.loadFromFile("./Images/image_2_2.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 215, 0, 215, 180));



	sprite.setPosition(Pos.x, Pos.y);
}

void FootballZombie::switchLane(int dir)
{
	if (dir == 0)
	{
		Pos.y += speed * 3;
		if (Pos.y >= 118 * 3 + 85 - 180 && Pos.y <= 118 * 4 + 85 - 180)
			switchRow = 2;

		return;
	}

	if (dir == 1)
	{
		Pos.y -= speed * 3;
		if (Pos.y >= 118 * 0 + 85 - 180 && Pos.y <= 118 * 1 + 85 - 180)
			switchRow = 2;

		return;
	}
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
		sprite.setTextureRect(IntRect(offset * 215, 0, 215, 180));
	//	return;
	//}



	//texture.loadFromFile("./Images/hfzanimation.png");
	//sprite.setTextureRect(IntRect(offset * 237, 0, 237, 212));

}

void FootballZombie::Move()
{
	Pos.x -= speed;
	health -= 3;

	int random = rand() % 20;
	
	if (random == 0 && Pos.y <= 118*4 + 85 - 180)
	{
		switchRow = 0;
	}

	if (random == 19 && Pos.y >= 118*0 + 85)
	{
		switchRow = 1;
	}

	switchLane(switchRow);
	sprite.setPosition(Pos.x, Pos.y);
}