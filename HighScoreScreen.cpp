#include "HighScoreScreen.h"

HighScoreScreen::HighScoreScreen() : Back("Back", coordinates(910, 540), 60, 25, coordinates(1180, 680))
{
	Texture texture_icon;
	texture_icon.loadFromFile("./Images/button.png");
	Back.setTexture(texture_icon);

	texture.loadFromFile("./Images/H_S.png");
	sprite.setTexture(texture);
}

void HighScoreScreen::drawIcons()
{
	Back.draw(window);
}

void HighScoreScreen::render()
{
	window.create(VideoMode(1200, 700), "High Score");
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