#pragma once
#include "Zombie.h"
class BalloonZombie :public Zombie
{

	bool ballonIsPopped;
	int pixelsX;
	int pixelsY;
public:
	BalloonZombie(int=200,int=3,int=5,int=1000,int=randGrid(180));
	void UpdateAnimation(float deltaTime);
	//void fly();
	void move();

};

