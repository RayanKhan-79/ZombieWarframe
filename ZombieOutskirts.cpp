#include "ZombieOutskirts.h"

void ZombieOutskirts::createBack(RenderWindow& window)
{
	background_Texture.loadFromFile("./Images/lvl_1_w_back.png");
	background_Sprite.setTexture(background_Texture);
	background_Sprite.setPosition(0, 0);
	window.draw(background_Sprite);
}

ZombieOutskirts::ZombieOutskirts()
	: Levels(3,3,8,2)
{

}