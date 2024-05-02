#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
#include<iostream>
using namespace sf;

class Icon
{
	Texture icontexture;
	Sprite iconSprite;
	Font font;
	Text text;
	std::string message;

	coordinates pos;
	coordinates dimensions;

public:
	Icon(std::string, coordinates);

	void setTexture(Texture, int, int);

	void draw(RenderWindow&);

	bool isClicked(Event&);

	//coordinates getPos() const { return pos; }
	//Sprite getSprite() const { return iconSprite; }
	
};

