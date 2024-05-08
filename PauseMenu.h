#pragma once
#include"coordinates.h"
#include<SFML/Graphics.hpp>
using namespace sf;

class PauseMenu 
{
	Sprite sprite;
	Texture texture;
	coordinates pos;

public:
	bool paused = false;

	PauseMenu(coordinates pos);
	bool resumeIsClicked(Event& e);
	void draw(RenderWindow& window);
};

