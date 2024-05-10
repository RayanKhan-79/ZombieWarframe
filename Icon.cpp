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
	window.draw(text);
}

Icon::Icon(std::string message, coordinates pos, int txt_width, int txt_height, coordinates Area)
	: pos(pos), Area(Area)
{
	Color green(1, 50, 32);
	font.loadFromFile("font/Noland-Bold.otf");

	text.setFont(font);
	text.setCharacterSize(32);
	text.setFillColor(green);
	text.setString(message);
	text.setPosition(pos.x + (270 - txt_width) / 2, pos.y + (140 - txt_height) / 2);
	iconSprite.setPosition(pos.x, pos.y);
}

bool Icon::isClicked(Event& e)
{
	if (e.type != Event::MouseButtonReleased)
		return false;

	if (e.mouseButton.x > pos.x && e.mouseButton.x < Area.x && e.mouseButton.y > pos.y && e.mouseButton.y < Area.y)
		return true;
	


	return false;
}
