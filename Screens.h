#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
#include"Icon.h"
using namespace sf;

class Screens
{
protected:
	bool end = false;
	RenderWindow window;
	Texture texture;
	Sprite sprite;
	coordinates pos;

public:
	Screens();
	RenderWindow& getWindow();
	void setTexture(Texture tex)
	{
		sprite.setTexture(tex);
	}
};
