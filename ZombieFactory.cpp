#include "ZombieFactory.h"


ZombieFactory::ZombieFactory(int num_Of_Waves)
	: spawnInterval(3), num_Of_Zombie(0), zombie_Limit(4), waveCalled(false), waves_Spawned(0), num_Of_Waves(num_Of_Waves) 
{
	zombies = new Zombie**[num_Of_Waves] {};
}

bool ZombieFactory::isIntervalReached()
{
	if (clock.getElapsedTime().asSeconds() < spawnInterval)
		return false;

	clock.restart();
	return true;
}

bool ZombieFactory::waveDefeated()
{


	for (int j = 0; j < num_Of_Zombie; j++)
		if (zombies[waves_Spawned][j]->getHealth() > 0)
			return false;

	waves_Spawned++;
	num_Of_Zombie = 0;

	if (waves_Spawned >= num_Of_Waves)
		return false;

	return true;
}

void ZombieFactory::spawnWave()
{
	if (waves_Spawned >= num_Of_Waves)
	{
		return;
	}

	if (!waveCalled || waveDefeated()) 
	{
		std::cout << "WAVE-" << waves_Spawned + 1 << "\n";

		zombies[waves_Spawned] = new Zombie*[zombie_Limit];
		waveCalled = true;
		
		//waves_Spawned++;
	}

	
	spawnZombie();
}

void ZombieFactory::spawnZombie()
{
	if (waves_Spawned >= num_Of_Waves)
	{
		return;
	}

	if (!isIntervalReached())
		return;

	if (num_Of_Zombie >= zombie_Limit)
		return;

	switch (rand() % 2)
	{
		case 0:
			zombies[waves_Spawned][num_Of_Zombie] = new Zombie();
			break;
		case 1:
			zombies[waves_Spawned][num_Of_Zombie] = new FootballZombie();
			break;
	}
	num_Of_Zombie++;
}

void ZombieFactory::DrawZombies(RenderWindow& window, float deltaTime)
{

		if (waves_Spawned >= num_Of_Waves)
		{
			return;
		}

		for (int j = 0; j < num_Of_Zombie; j++)
		{
			if (zombies[waves_Spawned][j]->getHealth() > 0)
			{
				zombies[waves_Spawned][j]->Move();
				zombies[waves_Spawned][j]->Draw(window, deltaTime);
			}
		}
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < waves_Spawned; i++)
	{
		for (int j = 0; j < num_Of_Zombie; j++)
			delete zombies[i][j];
		
		delete[] zombies[i];
	}
	delete[] zombies;
}