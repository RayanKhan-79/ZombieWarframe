#pragma once
#include "Sun.h"
class GenSun
{
private:

	float interval;
	Sun* sun;
	Clock clock;

public:

	GenSun(float interval = 10)
		: interval(interval), sun(NULL)
	{

	}
	
	void spawnSun()
	{
		if (clock.getElapsedTime().asSeconds() < interval)
			return;

		if (sun)
			return;

		int x = (rand() % 855) + 300;
		int y = 0;

		sun = new Sun(coordinates(x, y));
		clock.restart();
	}

	void moveSun(RenderWindow& window)
	{
		if (!sun)
			return;

		sun->Move();
		sun->draw(window);
	}

	bool Update(Event& e)
	{
		if (sun && sun->isClicked(e))
		{
			delete sun;
			sun = NULL;
			return true;
		}

		return false;
	}
};

