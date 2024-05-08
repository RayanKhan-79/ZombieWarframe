#include "ZombieFactory.h"


ZombieFactory::ZombieFactory()
	: spawnInterval(3), num_Of_Zombie(0), zombie_Limit(7), zombies(NULL) {}

bool ZombieFactory::isIntervalReached()
{
	if (clock.getElapsedTime().asSeconds() < spawnInterval)
		return false;

	clock.restart();
	return true;
}

bool ZombieFactory::spawnNextWave()
{
	
	for (int i = 0; i < num_Of_Zombie; i++)
		if (zombies[i]->getHealth() > 0)
			return false;

	for (int i = 0; i < num_Of_Zombie; i++)
	{
		delete zombies[i];
		zombies[i] = NULL;
	}
	delete[] zombies;
	zombies = NULL;
	num_Of_Zombie = 0;

}

void ZombieFactory::spawnWave()
{
	spawnNextWave();

	if (zombies == NULL) 
	{


		zombies = new Zombie*[zombie_Limit];		
	}

	
	spawnZombie();
}

void ZombieFactory::spawnZombie()
{

	if (!isIntervalReached())
		return;

	if (num_Of_Zombie >= zombie_Limit)
		return;

	//switch (rand() % 4)
	//{
	//	case 0:
			zombies[num_Of_Zombie] = new Zombie(200,8);
	//		break;

	//	case 1:
	//		zombies[num_Of_Zombie] = new FootballZombie;
	//		break;

	//	case 2:
	//		zombies[num_Of_Zombie] = new DancingZombie(10,4,200,8);
	//		break;

	//	case 3:
	//		zombies[num_Of_Zombie] = new BalloonZombie;
	//		break;

	//}
	num_Of_Zombie++;
}

void ZombieFactory::DrawZombies(RenderWindow& window, float deltaTime)
{

		for (int j = 0; j < num_Of_Zombie; j++)
		{

				zombies[j]->Move();
				zombies[j]->Draw(window, deltaTime);

		}
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < num_Of_Zombie; i++)
		delete zombies[i];
		
	delete[] zombies;
}