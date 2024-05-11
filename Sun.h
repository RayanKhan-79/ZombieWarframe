#pragma once
#include "Icon.h"
#include "coordinates.h"
class Sun
{
private:
	int score;
	int interval;
	int health;
	float Total_Animation_Time;
	int offset;
	coordinates Pos;
	Texture texture;
	Sprite sprite;
public:
	Sun();
	Sun(float interval);
	void UpdateAnimation(float deltaTime, float switchTime);
	void spawnSun();
	void scoreDisplay(sf::RenderWindow& window, sf::Font& font);
	void isClick(sf::Event& event);
	Sprite getSprite() { return sprite;  }
};

