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
