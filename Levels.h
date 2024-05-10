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

public:
	Levels() 
		: pauseIcon(coordinates(1030, 10)), pauseMenu(coordinates(325,50))
	{
		Texture texture;
		texture.loadFromFile("./Images/test2.png");
		pauseIcon.setTexture(texture);
	}

	void collisionDetection();
	virtual void createBack(RenderWindow& window) = 0;
	void start();

};

