#pragma once
#include"Screens.h"
#include"PlayGameScreen.h"
#include"InstructionScreen.h"
#include"HighScoreScreen.h"
#include"Icon.h"

class MainMenuScreen : public Screens
{
	PlayGameScreen playGame;
	InstructionScreen instructionScreen;
	HighScoreScreen highScoreScreen;

	Icon playgameIcon;
	Icon InstructionIcon;
	Icon highScoreIcon;
	Icon Quit;

public:
	MainMenuScreen();
	void drawIcons();
	void render();
	bool EndStatus() const { return end; }
};




