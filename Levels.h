#pragma once
#include"ZombieFactory.h"
#include"PlantFactory.h"

class Levels
{

protected:


	Texture background_Texture;
	Sprite background_Sprite;
	//Music backGroundMusic

	ZombieFactory zf;
	PlantFactory pf;

public:

	virtual void createBack(RenderWindow& window) = 0;
	void start();

};

