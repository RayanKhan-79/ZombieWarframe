#pragma once
#include "Zombie.h"
class BalloonZombie :public Zombie
{

public:
	BalloonZombie(int=200,int=3,int=5,int=1000,int=randGrid(238),int=127,int=238);
	void UpdateAnimation(float deltaTime);
	virtual void Attack(Plant* plant) {};
};

