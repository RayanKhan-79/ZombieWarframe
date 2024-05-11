#include "BeginnersGarden.h"

void BeginnersGarden::createBack(RenderWindow& window)
{
	background_Texture.loadFromFile("./Images/lvl_1_w_back.png");
	background_Sprite.setTexture(background_Texture);
	background_Sprite.setPosition(0, 0);
	window.draw(background_Sprite);
}

BeginnersGarden::BeginnersGarden()
	: Levels(2,1,8,0)
	
{
	
}