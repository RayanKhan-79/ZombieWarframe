#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
using namespace sf;

class Screens
{
protected:
	RenderWindow window;
	Texture texture;
	Sprite sprite;
	coordinates pos;

public:
	Screens();
	RenderWindow& getWindow();
};
