#pragma once
#include "coordinates.h"
#include<SFML/Graphics.hpp>
using namespace sf;

class ScoreBoard
{
	int suns;
	int score;
	int lives;

	//coordinates Pos;
	Texture texture;
	Sprite sprite;
	Font font;
	Text sunText;
	Text scoreText;
	Text liveText;

public:
	ScoreBoard() : suns(1000), score(0), lives(0)
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

	void IncrementSuns(int amount)
	{
		suns += amount;
	}

	void UpdateScore(int amount)
	{
		score = amount;
	}

	void UpdateLives(int amount)
	{
		lives = amount;
	}

	void draw(RenderWindow& window)
	{
		sunText.setString("Suns: " + std::to_string(suns));
		scoreText.setString("Score: " + std::to_string(score));
		liveText.setString("Lives: " + std::to_string(lives));
		window.draw(sprite);
		window.draw(sunText);
		window.draw(liveText);
		window.draw(scoreText);
	}

	int getSun() 
	{
		return suns;
	}

	void setSun(int x)
	{
		suns = x;
	}
};

