#include "PauseMenu.h"

PauseMenu::PauseMenu(coordinates pos) 
	: pos(pos)
{

	texture.loadFromFile("./Images/PauseMenu.png");
	sprite.setTexture(texture);

}

bool PauseMenu::resumeIsClicked(Event& e)
{
	if (e.type != Event::MouseButtonReleased)
		return false;

	if (e.mouseButton.x >= 375 && e.mouseButton.x <= 800 && e.mouseButton.y >= 540 && e.mouseButton.y <= 600)
		return true;


	return false;
}

void PauseMenu::draw(RenderWindow& window)
{
	sprite.setPosition(pos.x, pos.y);
	window.draw(sprite);

}