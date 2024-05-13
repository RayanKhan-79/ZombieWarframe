#include "GenSun.h"
GenSun::GenSun(float interval)
	: interval(interval), sun(NULL)
{

}

void GenSun::spawnSun()
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


void GenSun::moveSun(RenderWindow& window)
{
	if (!sun)
		return;

	sun->Move();
	sun->draw(window);
}

bool GenSun::Update(Event& e)
{
	if (sun && sun->isClicked(e))
	{

		delete sun;
		sun = NULL;
		return true;
	}

	return false;
}
