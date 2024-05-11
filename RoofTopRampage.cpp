#include "RoofTopRampage.h"

void RoofTopRampage::createBack(RenderWindow& window)
{

	background_Texture.loadFromFile("./Images/lvl_2_w_back.png");
	background_Sprite.setTexture(background_Texture);
	background_Sprite.setPosition(0, 0);
	window.draw(background_Sprite);
}

RoofTopRampage::RoofTopRampage()
	: Levels(7, 3, 20, 3)
{

}