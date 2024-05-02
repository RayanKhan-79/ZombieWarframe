#pragma once
#include "Screens.h"

class InstructionScreen : public Screens
{
	Icon Back;
public:
	InstructionScreen();
	void render();
	void drawIcons();
};


