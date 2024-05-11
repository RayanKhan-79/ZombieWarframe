#include "FoggyForest.h"

FoggyForest::FoggyForest()
	: Levels(5, 3, 12, 3)
{

}
void FoggyForest::createBack(RenderWindow& window)
{
	background_Texture.loadFromFile("./Images/lvl_2_w_back.png");
	background_Sprite.setTexture(background_Texture);
	background_Sprite.setPosition(0, 0);
	window.draw(background_Sprite);
}