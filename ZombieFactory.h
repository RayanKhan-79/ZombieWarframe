#pragma once
#include"Zombie.h"
#include"FootballZombie.h"
#include"DancingZombie.h"
#include"BackUpDancer.h"
#include<iostream>
#include<ctime>

class ZombieFactory
{
	float spawnInterval;
	
	int num_Of_Zombie;
	int zombie_Limit;
	
	Zombie** zombies;
	Clock clock;
	
	bool waveCalled;

	int test = 0;
	


public:
	ZombieFactory();

	
	bool spawnNextWave();


	bool isIntervalReached();


	void spawnWave();


	void spawnZombie();


	void DrawZombies(RenderWindow& window, float deltaTime);


	~ZombieFactory();

};

