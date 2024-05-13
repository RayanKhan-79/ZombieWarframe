#pragma once
#include "Screens.h"
#include <fstream>
class HighScoreScreen : public Screens
{
	Icon Back;
public:
	HighScoreScreen();
	void render();
	void drawIcons();
    void displayKillCount(); 

};



