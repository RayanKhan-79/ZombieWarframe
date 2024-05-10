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

	int waveCount = 0;

public:
	Levels();
	void collisionDetection();
	virtual void createBack(RenderWindow& window) = 0;
	void start();

};

