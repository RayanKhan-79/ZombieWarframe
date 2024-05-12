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

    void storeKillCount(int killCount) {
        std::ifstream inFile("killcount.txt");
        std::ofstream tempFile("temp.txt");

        if (inFile.is_open() && tempFile.is_open()) {
            int existingKill;
            bool inserted = false;
            bool insertedKillCount = false;

            // Read existing kill counts and append the new one
            while (inFile >> existingKill) {
                if (killCount >= existingKill && !inserted && !insertedKillCount) {
                    tempFile << killCount << "\n";
                    insertedKillCount = true;
                }
                tempFile << existingKill << "\n";
                if (!inserted && insertedKillCount) {
                    inserted = true;
                }
            }

            // If the new kill count is the largest, add it at the end
            if (!insertedKillCount) {
                tempFile << killCount << "\n";
            }

            inFile.close();
            tempFile.close();

            // Replace the original file with the sorted file
            std::remove("killcount.txt");
            std::rename("temp.txt", "killcount.txt");
        }
        else {
            std::cerr << "Error: Unable to open file(s) for reading or writing.\n";
        }
    }
	~Game();

};

