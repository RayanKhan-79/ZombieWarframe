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

void HighScoreScreen::displayKillCount() {
	std::ifstream file("killcount.txt");
	if (file.is_open()) {
		sf::Font font;
		if (!font.loadFromFile("./Font/molger-regular.otf")) {
			std::cerr << "Error loading font file!" << std::endl;
			return;
		}

		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(94);
		text.setFillColor(sf::Color::Green);
		text.setPosition(400, 145);

		std::string displayText = "HighScore:\n";

		int killCount;
		for (int i = 1; i <= 3 && file >> killCount; ++i) {
			std::string suffix;
			if (i == 1) suffix = "st";
			else if (i == 2) suffix = "nd";
			else if (i == 3) suffix = "rd";

			displayText += std::to_string(i) + suffix + ": " + std::to_string(killCount) + "\n";
		}

		text.setString(displayText);
		window.draw(text);

		file.close();
	}
	else {
		std::cerr << "Error opening file!" << std::endl;
	}
}