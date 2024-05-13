#pragma once
#include "coordinates.h"
#include<SFML/Graphics.hpp>
using namespace sf;

class ScoreBoard
{
	int suns;
	int score;
	int lives;
	Texture texture;
	Sprite sprite;
	Font font;
	Text sunText;
	Text scoreText;
	Text liveText;

public:
	ScoreBoard(); 
	void IncrementSuns(int amount);
	void UpdateScore(int amount);
	void UpdateLives(int amount);
	void draw(RenderWindow& window);
	int getSun() { return suns; }
    void setSun(int x){ suns = x; }
};

