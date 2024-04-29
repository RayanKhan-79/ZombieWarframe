#pragma once
#include"Zombie.h"
#include"FootballZombie.h"
#include<iostream>
#include<ctime>

class ZombieFactory
{
	float spawnInterval;
	
	int num_Of_Zombie;
	int zombie_Limit;

	int waves_Spawned;
	int num_Of_Waves;
	
	Zombie*** zombies;
	Clock clock;
	
	bool waveCalled;
	


public:
	ZombieFactory(int num_Of_Waves);


	bool isIntervalReached();


	void spawnWave();


	void spawnZombie();


	void DrawZombies(RenderWindow& window, float deltaTime);


	bool waveDefeated();


	~ZombieFactory();

};

