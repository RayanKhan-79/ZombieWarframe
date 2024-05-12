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
            int killCount;
            file >> killCount;

            sf::Font font;
            if (!font.loadFromFile("arial.ttf")) {
                std::cerr << "Error loading font file!" << std::endl;
                return;
            }

            sf::Text text;
            text.setFont(font);
            text.setString("Kill Count: " + std::to_string(killCount));
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::White);
            text.setPosition(20, 20);

            window.draw(text);
        }
        else {
            std::cerr << "Error opening file!" << std::endl;
        }
    }
};



