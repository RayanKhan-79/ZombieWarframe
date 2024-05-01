#pragma once
#include"Screens.h"
#include"PlayGameScreen.h"
#include"InstructionScreen.h"
#include"HighScoreScreen.h"

class MainMenuScreen : public Screens
{
	PlayGameScreen playGame;
	InstructionScreen instructionScreen;
	HighScoreScreen highScoreScreen;

public:
	MainMenuScreen();
	void render();
};




