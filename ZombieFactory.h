#pragma once
#include"Zombie.h"
#include"FootballZombie.h"
#include"DancingZombie.h"
#include"BackUpDancer.h"
#include"BalloonZombie.h"
#include<iostream>
#include<ctime>

class ZombieFactory
{
	float spawnInterval;

	int numOfZombies;
	int zombieLimit;

	Zombie** zombies;
	DancingZombie** Dancers;

	BackUpDancer*** backupDancers;
	
	int numOfDancers;
	int DancersLimit;
	
	Clock clock;




public:
	ZombieFactory();

	bool spawnNextWave();

	bool isIntervalReached();

	void spawnWave();

	void spawnZombie();

	void DrawZombies(RenderWindow& window, float deltaTime);

	Zombie** getZombies() { return zombies; }

	DancingZombie** getDancers() { return Dancers; }

	BackUpDancer*** getBackUp() { return backupDancers; }

	int getNumberOfDancers() { return numOfDancers; }

	int getNumberOfZombies() { return numOfZombies; }


	~ZombieFactory();
};

