#pragma once
#include"GameOverScreen.h"
#include"InstructionScreen.h"
#include"HighScoreScreen.h"
#include"Levels.h"
#include"BeginnersGarden.h"
#include"ZombieOutskirts.h"
#include"SunflowerFields.h"
#include "FoggyForest.h"
#include"NightTimeSiege.h"
#include "RoofTopRampage.h"
#include "string.h"
#include <fstream>
#include <iostream>
#include <sstream>
// Grid 
// origin	  -->   [300px ,85px]
// SE corner  -->   [1155px, 675px]
// width	  -->	1155px - 300px = 855px
// height	  -->	675px - 85px = 590px
// tile		  -->	95px * 118px

class Game
{
	bool end;
	bool win;

    String name;
    Text dispName;

	RenderWindow Gamewindow;
	Texture mainTexture;
	Sprite MainMenu;
	Icon playgameIcon;
	Icon InstructionIcon;
	Icon highScoreIcon;
	Icon Quit;
    Icon EnterName;
    Icon Badges;

	int killCount;
    Font font;

	GameOverScreen gS;
	InstructionScreen iS;
	HighScoreScreen hS;
	Levels* level;
	
public:

	Game();
	void drawIcons(RenderWindow& window);
	void playGame();
    void storeKillCount(int killCount); 
	~Game();

};

