#pragma once
#include "Zombie.h"
class BalloonZombie :public Zombie
{
	int offsetY;
public:
	BalloonZombie(int=200,int=3,int=5,int=1000,int=randGrid(205),int=110,int=205);
	void UpdateAnimation(float deltaTime);
	virtual void Attack(Plant* plant) {};
};

