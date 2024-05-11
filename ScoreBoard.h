#pragma once
#include "coordinates.h"
#include<SFML/Graphics.hpp>
using namespace sf;

class ScoreBoard
{
	int score;
	//coordinates Pos;
	Texture texture;
	Sprite sprite;
	Font font;
	Text scoreText;

public:
	ScoreBoard() : score(0)
	{
		texture.loadFromFile("./Images/button_large.png");
		sprite.setTexture(texture);

		if (!font.loadFromFile("arial.ttf")) {
			// Handle font loading error
		}

		scoreText.setFont(font); // Set the font
		scoreText.setCharacterSize(32); // Set the character size
		scoreText.setFillColor(sf::Color::White); // Set the fill color
		//scoreText.setString("Score: " + 0); // Set the text string

		sprite.setPosition(10, 600);
		scoreText.setPosition(30, 615); // Position the text at the top left corner
	}

	void IncrementScore(int amount)
	{
		score += amount;
	}

	void draw(RenderWindow& window)
	{
		scoreText.setString("Score: " + std::to_string(score));
		window.draw(sprite);
		window.draw(scoreText);
	}
};

