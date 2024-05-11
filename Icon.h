#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
#include<iostream>
using namespace sf;

class Icon
{
protected:
	Texture icontexture;
	Sprite iconSprite;

	coordinates pos;
	coordinates Area;

public:

	Icon(coordinates, coordinates);

	void setTexture(Texture);

	void draw(RenderWindow&);

	bool isClicked(Event&);

	//coordinates getPos() const { return pos; }
	Sprite getSprite() const { return iconSprite; }
	
};

