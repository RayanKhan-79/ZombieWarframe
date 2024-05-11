#include "Icon.h"

void Icon::setTexture(Texture texture)
{
	icontexture = texture;
	iconSprite.setTexture(icontexture);
}

Icon::Icon(coordinates pos, coordinates Area) : pos(pos), Area(Area)
{
	iconSprite.setPosition(pos.x, pos.y);
}

void Icon::draw(RenderWindow& window)
{
	window.draw(iconSprite);
}


bool Icon::isClicked(Event& e)
{
	if (e.type != Event::MouseButtonReleased)
		return false;

	if (e.mouseButton.x > pos.x && e.mouseButton.x < Area.x && e.mouseButton.y > pos.y && e.mouseButton.y < Area.y)
		return true;
	


	return false;
}
