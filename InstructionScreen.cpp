#include "InstructionScreen.h"

InstructionScreen::InstructionScreen() : Back(coordinates(910,600), coordinates(1180, 680))
{
	Texture texture_icon;
	texture_icon.loadFromFile("./Images/BackButton.png");
	Back.setTexture(texture_icon);

	texture.loadFromFile("./Images/I.png");
	sprite.setTexture(texture);
}

void InstructionScreen::drawIcons()
{
	Back.draw(window);
}

void InstructionScreen::render()
{
	window.create(VideoMode(1200, 700), "Instructions");
	window.setPosition(Vector2i(100, 100));
	while (window.isOpen())
	{

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed || Back.isClicked(e))
				window.close();

		}

		window.clear();
		window.draw(sprite);
		drawIcons();
		window.display();
	}
}
