#pragma once
#include"Icon.h"
#include"ZombieFactory.h"
#include"PlantFactory.h"
#include"PauseMenu.h"
#include"Movers.h"
class Levels
{

protected:

	Icon pauseIcon;
	Icon SkipLevel;
	Texture background_Texture;
	Sprite background_Sprite;
	PauseMenu pauseMenu;
	//Music backGroundMusic

	Movers* movers[5];
	ZombieFactory zf;
	PlantFactory pf;

	int lives = 3;
	int killCount;
	//int plantsUnlocked;
	//int zombiesUnlocked;

public:
	Levels(int plantsUnlocked, int zombiesUnlocked, int maxZombies, int maxDancers);
	void collisionDetection();
	virtual void createBack(RenderWindow& window) = 0;
	bool start();
	void drawMovers(RenderWindow& window);
	void TriggerMovers();
	void MoveMovers();
	//int getKills() { return killCount; }
	//int getMax() { return maxZombies; }
	int winCondition();

};

