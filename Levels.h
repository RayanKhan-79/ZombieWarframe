#pragma once
#include"Icon.h"
#include"ZombieFactory.h"
#include"PlantFactory.h"
#include"PauseMenu.h"
#include"Movers.h"
#include"ScoreBoard.h"
#include "GenSun.h"
#include <fstream>

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
	Movers* movers[5];
	ZombieFactory zf;
	PlantFactory pf;
	GenSun sunGenerator;
	int lives = 3;

public:
	Levels(int plantsUnlocked, int zombiesUnlocked, int maxZombies, int maxDancers);
	void collisionDetection();
	void decrementLives();
	virtual void createBack(RenderWindow& window) = 0;
	bool start(int& killCount);
	void drawMovers(RenderWindow& window);
	void TriggerMovers();
	void wallNutCollisions();
	void MoveMovers();
	int winCondition();
	void cherryBlast();

};


