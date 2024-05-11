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

	pos.x += 5;
	mid.x += 5;
}
