#include "ZombieFactory.h"


ZombieFactory::ZombieFactory()
	: spawnInterval(3), num_Of_Zombie(0), zombie_Limit(4), waveCalled(false), zombies(NULL) {}

bool ZombieFactory::isIntervalReached()
{
	if (clock.getElapsedTime().asSeconds() < spawnInterval)
		return false;

	clock.restart();
	return true;
}

void ZombieFactory::spawnWave()
{

	if (!waveCalled) 
	{
		
		zombies = new Zombie*[zombie_Limit];
		waveCalled = true;
		
		
	}

	
	spawnZombie();
}

void ZombieFactory::spawnZombie()
{

	if (!isIntervalReached())
		return;

	if (num_Of_Zombie >= zombie_Limit)
		return;

	switch (rand() % 3)
	{
		case 0:
			zombies[num_Of_Zombie] = new Zombie;
			break;

		case 1:
			zombies[num_Of_Zombie] = new FootballZombie;
			break;

		case 2:
			zombies[num_Of_Zombie] = new DancingZombie;
			break;
	}
	num_Of_Zombie++;
}

void ZombieFactory::DrawZombies(RenderWindow& window, float deltaTime)
{

		for (int j = 0; j < num_Of_Zombie; j++)
		{
			//if (zombies[j]->getHealth() > 0)
			//{
				zombies[j]->Move();
				zombies[j]->Draw(window, deltaTime);
			//}
		}
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < num_Of_Zombie; i++)
		delete zombies[i];
		
	delete[] zombies;
}