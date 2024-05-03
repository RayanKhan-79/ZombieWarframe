#include "DancingZombie.h"

DancingZombie::DancingZombie(float spawnInterval, int count, int health, int speed, int damage, int x, int y)
	: Zombie(health, speed, damage, x, y), spawnInterval(spawnInterval), count(count), backUpDancers(NULL), speed_y(speed)
{
//	image.loadFromFile("./Images/11.png");

	texture.loadFromFile("./Images/11.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 125, 0, 125, 180));
	sprite.setPosition(Pos.x, Pos.y);
}

void DancingZombie::checkStatus()
{
	if (backUpDancers == NULL)
		return;

	for (int i = 0; i < count; i++)
		if (backUpDancers[i]->getHealth() > 0)
			return;

	for (int i = 0; i < count; i++)
	{
		delete backUpDancers[i];
		backUpDancers[i] = NULL;
	}
	delete[] backUpDancers;
	backUpDancers = NULL;

	clock.restart();
}

void DancingZombie::SpawnBackUp()
{
	checkStatus();

	if (backUpDancers != NULL)
	{
		return;
	}

	if (clock.getElapsedTime().asSeconds() < spawnInterval)
	{
		return;
	}



	backUpDancers = new BackUpDancer * [4] {};
	backUpDancers[0] = new BackUpDancer(200, 1, 5, Pos.x + 95, Pos.y);  // East
	backUpDancers[1] = new BackUpDancer(200, 1, 5, Pos.x - 95, Pos.y);  // West
	
	if (Pos.y + 180 <= 118*4 + 85)
	{
		backUpDancers[2] = new BackUpDancer(200, 1, 5, Pos.x, Pos.y + 118);  // South
	}
	else
	{
		backUpDancers[2] = new BackUpDancer(200, 1, 5, Pos.x - 47, Pos.y);
	}
	if (Pos.y + 180 >=  118*2 + 85)
	{
		backUpDancers[3] = new BackUpDancer(200, 1, 5, Pos.x, Pos.y - 118);  // North
	}
	else
	{
		backUpDancers[3] = new BackUpDancer(200, 1, 5, Pos.x - 47, Pos.y);
	}



	clock.restart();

}
void DancingZombie::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		
		offset++;
		if (offset == 4)
			offset = 0;
	}

	sprite.setTextureRect(IntRect(offset * 125, 0, 125, 180));
}

void DancingZombie::Move()
{
	SpawnBackUp();
	if (backUpDancers && clock.getElapsedTime().asSeconds() < 5)
		return;

	Pos.x -= speed;

	if (/*Pos.y + 180 >= 118 * 1 + 85 &&*/ Pos.y + 180 <= 118 * 2 + 85)
		speed_y = speed;

	if (/*Pos.y + 180 <= 118 * 5 + 85 &&*/ Pos.y + 180 >= 118 * 5 + 85)
		speed_y = -speed;

	//if (Pos.y + 180 <= 118 * 5 + 85 && Pos.y + 180 >= 118 * 4 + 85)
	//	speed_y = -speed_y;

	Pos.y += speed_y;

	//health -= 3;
	for (int i = 0; i < count; i++)
	{
		if (backUpDancers != NULL)
		backUpDancers[i]->Move();
	}
}

void DancingZombie::Draw(RenderWindow& window, float deltaTime)
{
	UpdateAnimation(deltaTime);
	sprite.setPosition(Pos.x, Pos.y);
	for (int i = 0; i < count; i++)
		if (backUpDancers != NULL)
		{
			backUpDancers[i]->Draw(window, deltaTime);
		}
	window.draw(sprite);
}

DancingZombie::~DancingZombie()
{
	if (backUpDancers != NULL)
	{
		for (int i = 0; i < count; i++)
			if (backUpDancers[i] != NULL)
			{
				delete backUpDancers[i];
				backUpDancers = NULL;
			}
		delete[] backUpDancers;
		backUpDancers = NULL;
	}
}