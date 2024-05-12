#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
	: Restart(coordinates(465,550), coordinates(735,630))
{

	Texture iconTexture;
	iconTexture.loadFromFile("./Images/RestartButton.png");
	Restart.setTexture(iconTexture);

	texture.loadFromFile("./Images/GameOverScreen0.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

}
void GameOverScreen::Render()
{
	window.create(VideoMode(1200, 700), "Plants Vs Zombies");
	window.setPosition(Vector2i(100, 100));
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed || Restart.isClicked(e))
				window.close();
		}


		window.draw(sprite);
		drawIcons();
		window.display();
	}
}

void GameOverScreen::drawIcons()
{
	Restart.draw(window);
}