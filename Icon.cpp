#include "Icon.h"

void Icon::setTexture(Texture texture)
{
	icontexture = texture;
	iconSprite.setTexture(icontexture);

	
	dimensions.x += pos.x;
	dimensions.y += pos.y;
	
	//text.setPosition(pos.x + (270 - txt_width)/2, pos.y + (140 - txt_height)/2);
}

Icon::Icon(coordinates pos) : pos(pos)
{
	iconSprite.setPosition(pos.x, pos.y);
}

void Icon::draw(RenderWindow& window)
{
	
	window.draw(iconSprite);
	window.draw(text);
}

Icon::Icon(std::string message, coordinates pos, int txt_width, int txt_height) : pos(pos), dimensions(270, 140)
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

	if (e.mouseButton.x > pos.x && e.mouseButton.x < pos.x + 270 && e.mouseButton.y > pos.y && e.mouseButton.y < pos.y + 140)
		return true;
	


	return false;
}
