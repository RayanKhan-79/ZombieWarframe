#include "Icon.h"

void Icon::setTexture(Texture texture, int txt_width, int txt_height)
{
	icontexture = texture;
	iconSprite.setTexture(icontexture);
	iconSprite.setPosition(pos.x, pos.y);
	
	dimensions.x += pos.x;
	dimensions.y += pos.y;
	
	text.setPosition(pos.x + (270 - txt_width)/2, pos.y + (140 - txt_height)/2);
}

void Icon::draw(RenderWindow& window)
{
	
	window.draw(iconSprite);
	window.draw(text);
}

Icon::Icon(std::string message, coordinates pos) : pos(pos), dimensions(270, 140)
{
	Color green(1, 50, 32);
	font.loadFromFile("font/Noland-Bold.otf");

	text.setFont(font);
	text.setCharacterSize(32);
	text.setFillColor(green);
	text.setString(message);
}

bool Icon::isClicked(Event& e)
{
	if (e.type != Event::MouseButtonReleased)
		return false;

	if (e.mouseButton.x > pos.x && e.mouseButton.x < pos.x + 270 && e.mouseButton.y > pos.y && e.mouseButton.y < pos.y + 140)
		return true;
	


	return false;
}
