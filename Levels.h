#pragma once
#include"Icon.h"
#include"ZombieFactory.h"
#include"PlantFactory.h"
#include"PauseMenu.h"
#include"Movers.h"
#include"ScoreBoard.h"
#include "GenSun.h"
//#include"Sentry.h"

class Levels
{

protected:

	Icon pauseIcon;
	Icon SkipLevel;
	Icon Shovel;
	Texture background_Texture;
	Sprite background_Sprite;
	PauseMenu pauseMenu;
	ScoreBoard scoreBoard;
	//Music backGroundMusic

	

	Movers* movers[5];
	ZombieFactory zf;
	PlantFactory pf;
	GenSun sunGenerator;
	int lives = 3;
	//int plantsUnlocked;
	//int zombiesUnlocked;

public:
	Levels(int plantsUnlocked, int zombiesUnlocked, int maxZombies, int maxDancers);
	void collisionDetection();
	void BulletCollisions();
	virtual void createBack(RenderWindow& window) = 0;
	bool start(int& killCount);
	void drawMovers(RenderWindow& window);
	void TriggerMovers();
	void MoveMovers();
	//int getKills() { return killCount; }
	//int getMax() { return maxZombies; }
	int winCondition();

	void cherryBlast();

};

