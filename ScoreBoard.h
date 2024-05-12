#pragma once
#include "coordinates.h"
#include<SFML/Graphics.hpp>
using namespace sf;

class ScoreBoard
{
	int suns;
	int score;
	//coordinates Pos;
	Texture texture;
	Sprite sprite;
	Font font;
	Text sunText;
	Text scoreText;

public:
	ScoreBoard() : suns(0), score(0)
	{
		texture.loadFromFile("./Images/button_large.png");
		sprite.setTexture(texture);

		if (!font.loadFromFile("arial.ttf")) {
			// Handle font loading error
		}

		sunText.setFont(font); // Set the font
		sunText.setCharacterSize(32); // Set the character size
		sunText.setFillColor(sf::Color::White); // Set the fill color
		
		scoreText.setFont(font);
		scoreText.setCharacterSize(32);
		scoreText.setFillColor(sf::Color::White);

		sprite.setPosition(10, 600);
		sunText.setPosition(30, 615); // Position the text at the top left corner
		scoreText.setPosition(30, 645);
	}

	void IncrementSuns(int amount)
	{
		suns += amount;
	}

	void UpdateScore(int amount)
	{
		score = amount;
	}

	void draw(RenderWindow& window)
	{
		sunText.setString("Suns: " + std::to_string(suns));
		scoreText.setString("Score: " + std::to_string(score));
		window.draw(sprite);
		window.draw(sunText);
		window.draw(scoreText);
	}
};

