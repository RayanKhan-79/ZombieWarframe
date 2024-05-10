#pragma once
#include"Icon.h"
#include"ZombieFactory.h"
#include"PlantFactory.h"
#include"PauseMenu.h"
class Levels
{

protected:

	Icon pauseIcon;
	Texture background_Texture;
	Sprite background_Sprite;
	PauseMenu pauseMenu;
	//Music backGroundMusic

	ZombieFactory zf;
	PlantFactory pf;

	int lives = 3;
	int killCount;
	int maxZombies;
	//int plantsUnlocked;
	//int zombiesUnlocked;

public:
	Levels(int);
	void collisionDetection();
	virtual void createBack(RenderWindow& window) = 0;
	bool start();
	int getKills() { return killCount; }
	int getMax() { return maxZombies; }
	int winCondition();

};

