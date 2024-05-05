#pragma once
#include"InstructionScreen.h"
#include"HighScoreScreen.h"
#include"Levels.h"
#include"BeginnersGarden.h"
#include"NightTimeSiege.h"

// Grid 
// origin	  -->   [300px ,85px]
// SE corner  -->   [1155px, 675px]
// width	  -->	1155px - 300px = 855px
// height	  -->	675px - 85px = 590px
// tile		  -->	95px * 118px

class Game
{
	bool end;

	// For Testing
	int progress = 0;
	// =====
	
	RenderWindow Gamewindow;
	Texture mainTexture;
	Sprite MainMenu;
	Icon playgameIcon;
	Icon InstructionIcon;
	Icon highScoreIcon;
	Icon Quit;


	InstructionScreen iS;
	HighScoreScreen hS;
	Levels* level;
	
public:
	Game();

	void drawIcons(RenderWindow& window);

	void playGame();

	~Game();

};

