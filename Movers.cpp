#include "Movers.h"

Movers::Movers(coordinates pos) : pos(pos), mid(pos.x, pos.y+35), triggered(false)
{
	texture.loadFromFile("./Images/mover.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos.x, pos.y);
}

void Movers::draw(RenderWindow& window)
{
	sprite.setPosition(pos.x, pos.y);
	window.draw(sprite);
}

void Movers::Move()
{
	if (!triggered)
		return;

	pos.x += 15;
	mid.x += 15;
}
void Movers::mark(Zombie* zombie)
{
	zombie->getHealth() -= 2000;
	triggered = true;
}

void Movers::mark(DancingZombie* zombie)
{
	zombie->getHealth() -= 2000;
	triggered = true;
}

void Movers::mark(BackUpDancer* zombie)
{
	zombie->getHealth() -= 2000;
	triggered = true;
}

