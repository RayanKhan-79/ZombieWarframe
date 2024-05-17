#include "ZombieFactory.h"

ZombieFactory::ZombieFactory(int zombieLimit, int DancersLimit, int zombiesUnlocked, int waveLimit)
	: spawnInterval(1), 
	numOfZombies(0), 
	numOfDancers(0), 
	waveCount(0),
	zombieLimit(zombieLimit), 
	DancersLimit(DancersLimit), 
	waveLimit(waveLimit),
	zombies(NULL), 
	Dancers(NULL), 
	zombiesUnlocked(zombiesUnlocked)
{
	buffer.loadFromFile("./Audio/zombiesWave.mp3");
	sound.setBuffer(buffer);
	sound.setVolume(100.f);
	backupDancers = new BackUpDancer**[DancersLimit] {};
	for (int i = 0; i < DancersLimit; i++)
		backupDancers[i] = new BackUpDancer*[4]{};
}

bool ZombieFactory::isIntervalReached()
{
	if (spawnClock.getElapsedTime().asSeconds() < spawnInterval)
		return false;

	spawnClock.restart();
	return true;
}

void ZombieFactory::UpdateBackUpDancers()
{
	
	for (int i = 0; i < DancersLimit; i++)
	{
		if (backupDancers[i][0] == NULL)
			continue;

		bool dead = true;
		for (int j = 0; j < 4; j++)
		{
			if (backupDancers[i][j]->getHealth() > 0)
				dead = false;
		}

		if (dead)
		{
			for (int j = 0; j < 4; j++)
			{
				delete backupDancers[i][j];
				backupDancers[i][j] = NULL;
			}

			if (Dancers[i])
				Dancers[i]->resetTime();
		}
	}
}

bool ZombieFactory::spawnNextWave(int& kills)
{

	
	// All zombies haven't been spawned yet
	if (numOfZombies != zombieLimit || numOfDancers != DancersLimit)
		return false;
	
	// Do not call next wave if even a single zombie is still alive
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
	
	


	// Deallocate memory to allow use in the next wave
	for (int i = 0; i < numOfZombies; i++)
	{
		delete zombies[i];
		zombies[i] = NULL;
		kills++;
		std::cout << "kills: " << kills << '\n';
	}

	for (int i = 0; i < numOfDancers; i++)
	{
		delete Dancers[i];
		Dancers[i] = NULL;
		kills++;
		std::cout << "kills: " << kills << '\n';
	}

	for (int i = 0; i < numOfDancers; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			delete backupDancers[i][j];
			backupDancers[i][j] = NULL;
			kills++;
			std::cout << "kills: " << kills << '\n';
		}
	}

	delete[] zombies;
	delete[] Dancers;
	
	zombies = NULL;
	Dancers = NULL;
	
	// set counters to 0
	numOfZombies = 0;
	numOfDancers = 0;	

	// Play the sound
	sound.play();
	if (sound.getStatus() == Sound::Playing)
		spawnClock.restart();

	// keeping track of the number of waves called so far
	std::cout << "Spawning next wave" << std::endl;
	waveCount++;
	std::cout << waveCount + 1 << '\n';

	return true;

}

void ZombieFactory::spawnWave(int& kills)
{
	UpdateBackUpDancers();
	
	spawnNextWave(kills);


	if (zombies == NULL) 
	{
		zombies = new Zombie*[zombieLimit];		
		waveCalled = true;
	}

	if (Dancers == NULL)
	{
		Dancers = new DancingZombie*[DancersLimit];
		waveCalled = true;
	}


	
	spawnZombie();
}

void ZombieFactory::spawnZombie()
{

	if (!isIntervalReached())
		return;
	


	switch (rand()%2)
	{
		case 0:

			if (numOfZombies < zombieLimit)
			{
				if (zombiesUnlocked == 1)
				{
					zombies[numOfZombies] = new Zombie;
					std::cout << "Zombie\n";
				}

				else
				{
					switch (rand() % 3)
					{
						case 0:
							zombies[numOfZombies] = new Zombie;
							std::cout << "Zombie\n";
							break;

						case 1:
							zombies[numOfZombies] = new FootballZombie;
							std::cout << "FZombie\n";
							break;

						case 2:
							zombies[numOfZombies] = new BalloonZombie;
							std::cout << "BZombie\n";
							break;

					}
				}
				numOfZombies++;
				return;
			}

		case 1:
			if (numOfDancers < DancersLimit)
			{
				Dancers[numOfDancers] = new DancingZombie;
				std::cout << "DZombie\n";
				numOfDancers++;
			}
	}
}

void ZombieFactory::DrawZombies(RenderWindow& window, float deltaTime)
{

		for (int j = 0; j < numOfZombies; j++)
		{
			if (zombies[j]->getHealth() > 0)
			{
				zombies[j]->Move();
				zombies[j]->Draw(window, deltaTime);
			}

		}

		for (int j = 0; j < numOfDancers; j++)
		{
			if (Dancers[j]->getHealth() > 0)
			{
				Dancers[j]->Move();
				Dancers[j]->Draw(window, deltaTime);
			}
	

				if (Dancers[j]->getHealth() > 0)
					Dancers[j]->SummonBackUp(backupDancers[j]);

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

				if (backupDancers[i][j]->getHealth() > 0)
				{
					backupDancers[i][j]->Move();
					backupDancers[i][j]->Draw(window, deltaTime);
				}
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