#pragma once
#include"Zombie.h"
#include"BackUpDancer.h"

class DancingZombie : public Zombie
{
	BackUpDancer** backUpDancers;
	int count;
	int speed_y;
	float spawnInterval;
	Clock clock;



public:
	DancingZombie(float = 10, int = 4, int = 200, int = 3, int = 5, int = 1000, int = randGrid(180), int = 125, int = 180);
	void SpawnBackUp();
	void UpdateAnimation(float deltaTime);
	//void Draw(RenderWindow&, float);
	void Assign(BackUpDancer**& backUp);
	void checkAssignment(BackUpDancer**& backUp);
	//virtual void Attack(Plant*);
	void checkStatus();
	void Move();
	BackUpDancer** getBackUp();
	//~DancingZombie();

};

