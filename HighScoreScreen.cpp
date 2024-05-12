#include "HighScoreScreen.h"
#include <SFML/Audio.hpp>
HighScoreScreen::HighScoreScreen() : Back(coordinates(910, 600), coordinates(1180, 680))
{
	Texture texture_icon;
	texture_icon.loadFromFile("./Images/BackButton.png");
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

	sf::Music backgroundMusic;
	if (!backgroundMusic.openFromFile("./Audio/score.mp3")) {
		std::cerr << "Error loading background music!" << std::endl;
		return; // Exit if music file loading fails
	}

	// Set the volume to 50
	backgroundMusic.setVolume(50);

	// Play the music in a loop
	backgroundMusic.setLoop(true);
	backgroundMusic.play();

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
		displayKillCount();
		drawIcons();
		window.display();
	}
}