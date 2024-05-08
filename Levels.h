#pragma once
#include"Icon.h"
#include"ZombieFactory.h"
#include"PlantFactory.h"

class Levels
{

protected:

	Icon pauseIcon;
	Texture background_Texture;
	Sprite background_Sprite;
	//Music backGroundMusic

	ZombieFactory zf;
	PlantFactory pf;

public:
	Levels()
		: pauseIcon(coordinates(1038, 10))
	{
		Texture texture;
		texture.loadFromFile("./Images/test2.png");
		pauseIcon.setTexture(texture);
	}

	virtual void createBack(RenderWindow& window) = 0;
	void start();

};

