#pragma once
#include "Screens.h"

class GameOverScreen : public Screens
{
	Icon Restart;

public:
	GameOverScreen();
	void Render();
	void drawIcons();
};

//protected:
//	bool end = false;
//	RenderWindow window;
//	Texture texture;
//	Sprite sprite;
//	coordinates pos;
//
//public:
//	Screens();
//	RenderWindow& getWindow();
//	void setTexture(Texture tex)
//	{
//		sprite.setTexture(tex);
//	}