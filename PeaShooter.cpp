#include "PeaShooter.h"
PeaShooter::PeaShooter()
{

}
PeaShooter::PeaShooter(int x, int y, int health) :Plant (x,y,health)
{
	texture.loadFromFile("./Images/Peashooter.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 121, 0, 121, 138));
	sprite.setPosition(Pos.x, Pos.y);
}