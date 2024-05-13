#include "Sun.h"
Sun::Sun(coordinates pos)
	: Icon(pos, coordinates(pos.x + 100, pos.y + 100))
{
	icontexture.loadFromFile("./Images/Sun.png");
	iconSprite.setTexture(icontexture);
	iconSprite.setTextureRect(IntRect(0, 0, 100, 100));
}

void Sun::Move()
{

	pos.y += 2;
	Area.y += 2;
	iconSprite.setPosition(pos.x, pos.y);
}