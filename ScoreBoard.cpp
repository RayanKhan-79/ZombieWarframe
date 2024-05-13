#include "ScoreBoard.h"
ScoreBoard::ScoreBoard() : suns(100), score(0), lives(0)
{
	texture.loadFromFile("./Images/scoreboard1.png");
	sprite.setTexture(texture);

	if (!font.loadFromFile("./Font/molger-regular.otf")) {
		// Handle font loading error
	}

	Color Green(0, 170, 0);

	sunText.setFont(font); // Set the font
	sunText.setCharacterSize(28); // Set the character size
	sunText.setFillColor(Green); // Set the fill color

	scoreText.setFont(font);
	scoreText.setCharacterSize(28);
	scoreText.setFillColor(Green);

	liveText.setFont(font);
	liveText.setCharacterSize(28);
	liveText.setFillColor(Green);

	sprite.setPosition(10, 600);
	sunText.setPosition(30, 600); // Position the text at the top left corner
	scoreText.setPosition(30, 630);
	liveText.setPosition(30, 660);
}

void ScoreBoard::IncrementSuns(int amount)
{
	suns += amount;
}

void ScoreBoard::UpdateScore(int amount)
{
	score = amount;
}

void ScoreBoard::UpdateLives(int amount)
{
	lives = amount;
}

void ScoreBoard::draw(RenderWindow& window)
{
	sunText.setString("Suns: " + std::to_string(suns));
	scoreText.setString("Score: " + std::to_string(score));
	liveText.setString("Lives: " + std::to_string(lives));
	window.draw(sprite);
	window.draw(sunText);
	window.draw(liveText);
	window.draw(scoreText);
}
