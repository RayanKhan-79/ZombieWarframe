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
    void displayKillCount() {
        std::ifstream file("killcount.txt");
        if (file.is_open()) {
            sf::Font font;
            if (!font.loadFromFile("./Font/molger-regular.otf")) {
                std::cerr << "Error loading font file!" << std::endl;
                return;
            }

            sf::Text text;
            text.setFont(font);
            text.setCharacterSize(94);
            text.setFillColor(sf::Color::Green);
            text.setPosition(400, 145);

            std::string displayText = "HighScore:\n";

            int killCount;
            for (int i = 1; i <= 3 && file >> killCount; ++i) {
                std::string suffix;
                if (i == 1) suffix = "st";
                else if (i == 2) suffix = "nd";
                else if (i == 3) suffix = "rd";

                displayText += std::to_string(i) + suffix + ": " + std::to_string(killCount) + "\n";
            }

            text.setString(displayText);
            window.draw(text);

            file.close();
        }
        else {
            std::cerr << "Error opening file!" << std::endl;
        }
    }


};



