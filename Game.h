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

#include <iostream>
#include <fstream>
    void displayBadges()
    {
       
    }
    void storeKillCount(int killCount) {
        std::ifstream inFile("killcount.txt");
        std::ofstream tempFile("temp.txt");
        if (!inFile.is_open()) {
            std::cerr << "Error: Unable to open input file 'killcount.txt'\n";
            return;
        }

        if (!tempFile.is_open()) {
            std::cerr << "Error: Unable to open output file 'temp.txt'\n";
            inFile.close();
            return;
        }

        int existingKill;
        bool inserted = false;

        // Read existing kill counts and insert the new one in sorted order
        while (inFile >> existingKill) {
            if (killCount >= existingKill && !inserted) {
                tempFile << killCount << "\n";
                inserted = true;
            }
            tempFile << existingKill << "\n";
        }

        // If the new kill count is the smallest, add it at the end
        if (!inserted) {
            tempFile << killCount << "\n";
        }

        inFile.close();
        tempFile.close();

        // Replace the original file with the sorted file
        std::remove("killcount.txt");
        std::rename("temp.txt", "killcount.txt");
    }

	~Game();

};

