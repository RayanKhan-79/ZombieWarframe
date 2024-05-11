#include "NightTimeSiege.h"

void NightTimeSiege::createBack(RenderWindow& window)
{

	background_Texture.loadFromFile("./Images/lvl_2_w_back.png");
	background_Sprite.setTexture(background_Texture);
	background_Sprite.setPosition(0, 0);
	window.draw(background_Sprite);
}

NightTimeSiege::NightTimeSiege()
	: Levels(6, 3, 16, 3)
{

}
