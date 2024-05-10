#include "ZombieFactory.h"


ZombieFactory::ZombieFactory()
	: spawnInterval(3), numOfZombies(0), zombieLimit(4), numOfDancers(0), DancersLimit(1), zombies(NULL), Dancers(NULL) 
{
	backupDancers = new BackUpDancer**[DancersLimit] {};
	for (int i = 0; i < DancersLimit; i++)
		backupDancers[i] = new BackUpDancer*[4]{};
}

bool ZombieFactory::isIntervalReached()
{
	if (clock.getElapsedTime().asSeconds() < spawnInterval)
		return false;

	clock.restart();
	return true;
}

bool ZombieFactory::spawnNextWave()
{
	
	for (int i = 0; i < numOfZombies; i++)
		if (zombies[i]->getHealth() > 0)
			return false;

	for (int i = 0; i < numOfDancers; i++)
		if (Dancers[i]->getHealth() > 0)
			return false;

	for (int i = 0; i < numOfDancers; i++)
		for (int j = 0; j < 4; j++)
			if (backupDancers[i][j] && backupDancers[i][j]->getHealth() > 0)
				return false;

	for (int i = 0; i < numOfZombies; i++)
	{
		delete zombies[i];
		zombies[i] = NULL;
	}

	for (int i = 0; i < numOfDancers; i++)
	{
		delete Dancers[i];
		Dancers[i] = NULL;
	}

	for (int i = 0; i < numOfDancers; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			delete backupDancers[i][j];
			backupDancers[i][j] = NULL;
		}
	}

	delete[] zombies;
	delete[] Dancers;
	
	zombies = NULL;
	Dancers = NULL;
	
	numOfZombies = 0;
	numOfDancers = 0;
	
}

void ZombieFactory::spawnWave()
{
	spawnNextWave();

	if (zombies == NULL) 
	{

		zombies = new Zombie*[zombieLimit];		
	}

	if (Dancers == NULL)
	{
		Dancers = new DancingZombie*[DancersLimit];
	}

	
	spawnZombie();
}

void ZombieFactory::spawnZombie()
{

	if (!isIntervalReached())
		return;
	
	/*if (numOfDancers >= DancersLimit && numOfZombies >= zombieLimit)
		return;*/

	switch (rand()%2)
	{
		case 0:

			if (numOfZombies < zombieLimit)
			{


				switch (rand() % 3)
				{
					case 0:
						zombies[numOfZombies] = new Zombie;
						break;

					case 1:
						zombies[numOfZombies] = new FootballZombie;
						break;

					case 2:
						zombies[numOfZombies] = new BalloonZombie;
						break;

				}
				numOfZombies++;
				return;
			}

		case 1:
			if (numOfDancers < DancersLimit)
			{
				Dancers[numOfDancers] = new DancingZombie;
				numOfDancers++;
			}
	}
}

void ZombieFactory::DrawZombies(RenderWindow& window, float deltaTime)
{

		for (int j = 0; j < numOfZombies; j++)
		{

				zombies[j]->Move();
				zombies[j]->Draw(window, deltaTime);

		}

		for (int j = 0; j < numOfDancers; j++)
		{
			
				Dancers[j]->Move();
				Dancers[j]->Draw(window, deltaTime);
	
				std::cout << j << Dancers[j]->getHealth() << '\n';
				if (Dancers[j]->getHealth() > 0)
					Dancers[j]->Assign(backupDancers[j]);

		}

		if (backupDancers == NULL)
			return;

		for (int i = 0; i < numOfDancers; i++)
		{
			if (backupDancers[i] == NULL)
				continue;
		
			for (int j = 0; j < 4; j++)
			{
				if (backupDancers[i][j] == NULL)
					continue; 

				backupDancers[i][j]->Move();
				backupDancers[i][j]->Draw(window, deltaTime);
			}
		}


}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < numOfDancers; i++)
	{
		for (int j = 0; j < 4; j++)
			delete backupDancers[i][j];
		delete[] backupDancers[i];
	}
	delete backupDancers;


	for (int i = 0; i < numOfZombies; i++)
		delete zombies[i];
		
	for (int i = 0; i < numOfDancers; i++)
		delete Dancers[i];

	delete[] zombies;
	delete[] Dancers;
}