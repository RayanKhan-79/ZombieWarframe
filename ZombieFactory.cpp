#include "ZombieFactory.h"


ZombieFactory::ZombieFactory()
	: spawnInterval(3), num_Of_Zombie(0), zombie_limit(10), zombies(NULL), waveCalled(false) {}

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
		zombies = new Zombie * [zombie_limit];
		waveCalled = true;
	}
	spawnZombie();
}

void ZombieFactory::spawnZombie()
{
	if (!isIntervalReached())
		return;

	if (num_Of_Zombie >= zombie_limit)
		return;

	switch (rand() % 2)
	{
		case 0:
			zombies[num_Of_Zombie] = new Zombie();
			break;
		case 1:
			zombies[num_Of_Zombie] = new FootballZombie();
			break;
	}
	num_Of_Zombie++;
}

void ZombieFactory::DrawZombies(RenderWindow& window, float deltaTime)
{
	for (int i = 0; i < num_Of_Zombie; i++)
	{

		zombies[i]->Move();
		zombies[i]->Draw(window, deltaTime);
	}
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < num_Of_Zombie; i++)
		delete zombies[i];
	delete[] zombies;
}