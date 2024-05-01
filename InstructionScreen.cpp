#include "InstructionScreen.h"

InstructionScreen::InstructionScreen()
{
	texture.loadFromFile("./Images/I.png");
	sprite.setTexture(texture);
}

void InstructionScreen::render()
{
	window.create(VideoMode(1200, 700), "Instructions");
	while (window.isOpen())
	{

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}
