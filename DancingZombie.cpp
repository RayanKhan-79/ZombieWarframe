#include "DancingZombie.h"

DancingZombie::DancingZombie(float spawnInterval, int health, int speed, int damage, int x, int y, int pixelsX, int pixelsY)
	: Zombie(health, speed, damage, x, y, pixelsX, pixelsY), spawnInterval(spawnInterval), speed_y(speed)
{
	hitArea.x = Pos.x + 95;
	hitArea.y = Pos.y + pixelsY;
	texture.loadFromFile("./Images/11.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));

	sprite.setPosition(Pos.x, Pos.y);
}


//void DancingZombie::checkStatus()
//{
//	if (backUpDancers == NULL)
//		return;
//
//	for (int i = 0; i < count; i++)
//		if (backUpDancers[i]->getHealth() > 0)
//			return;
//
//	for (int i = 0; i < count; i++)
//	{
//		delete backUpDancers[i];
//		backUpDancers[i] = NULL;
//	}
//	delete[] backUpDancers;
//	backUpDancers = NULL;
//
//	clock.restart();
//}



//void DancingZombie::checkAssignment(BackUpDancer**& backUp)
//{
//	if (!backUp[0] || !backUp[1] || !backUp[2] || !backUp[3])
//		return;
//
//	for (int i = 0; i < 4; i++)
//		if (backUp[i]->getHealth() > 0)
//			return;
//
//	for (int i = 0; i < 4; i++)
//	{
//		delete backUp[i];
//		backUp[i] = NULL;
//	}
//
//	clock.restart();
//}

void DancingZombie::SummonBackUp(BackUpDancer**& backUp)
{
	//checkAssignment(backUp);

	if (backUp[0] || backUp[1] || backUp[2] || backUp[3])
		return;

	if (clock.getElapsedTime().asSeconds() < spawnInterval)
		return;

	backUp[0] = new BackUpDancer(200, 1, 5, Pos.x + 95, Pos.y);  // East
	backUp[1] = new BackUpDancer(200, 1, 5, Pos.x - 95, Pos.y);  // West
		
	if (Pos.y + 180 <= 118*4 + 85)
	{
		backUp[2] = new BackUpDancer(200, 1, 5, Pos.x, Pos.y + 118);  // South
	}
	else
	{
		backUp[2] = new BackUpDancer(200, 1, 5, Pos.x - 47, Pos.y);
	}
	if (Pos.y + 180 >=  118*2 + 85)
	{
		backUp[3] = new BackUpDancer(200, 1, 5, Pos.x, Pos.y - 118);  // North
	}
	else
	{
		backUp[3] = new BackUpDancer(200, 1, 5, Pos.x - 47, Pos.y);
	}

	std::cout << "Summon!\n";
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

	sprite.setTextureRect(IntRect(offset * pixelsX, 0, pixelsX, pixelsY));
}

void DancingZombie::Move()
{


	if (action == "attacking")
		return;


	Pos.x -= speed;
	hitArea.x -= speed;

	if (Pos.y + 180 <= 118 * 2 + 85)
		speed_y = speed;

	if (Pos.y + 180 >= 118 * 5 + 85)
		speed_y = -speed;


	Pos.y += speed_y;
	hitArea.y += speed_y;

}

