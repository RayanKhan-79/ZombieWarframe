#include "HighScoreScreen.h"

HighScoreScreen::HighScoreScreen()
{
	texture.loadFromFile("./Images/H_S.png");
	sprite.setTexture(texture);
}

void HighScoreScreen::render()
{
	window.create(VideoMode(1200, 700), "High Score");
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