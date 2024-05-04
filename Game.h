#pragma once
#include"MainMenuScreen.h"
#include"Levels.h"

class Game
{
	//MainMenuScreen mainMenu;
	bool end;
	
	RenderWindow Gamewindow;
	Sprite MainMenu;
	Icon playgameIcon;
	Icon InstructionIcon;
	Icon highScoreIcon;
	Icon Quit;


	InstructionScreen iS;
	HighScoreScreen hS;
	Levels* level;
	
public:
	Game()
		: level(NULL), playgameIcon("Play", coordinates(456, 130)), InstructionIcon("Instructions", coordinates(465, 280)), highScoreIcon("High Score", coordinates(465, 430)), Quit("Quit", coordinates(910, 540)), end(false)
	{
		Texture texture_1;
		texture_1.loadFromFile("./Images/button.png");
		playgameIcon.setTexture(texture_1, 56, 27);
		InstructionIcon.setTexture(texture_1, 149, 25);
		highScoreIcon.setTexture(texture_1, 137, 31);
		Quit.setTexture(texture_1, 58, 29);

		Texture texture;
		texture.loadFromFile("./Images/main_back.png");
		MainMenu.setTexture(texture);
	}

	void createBack(RenderWindow& window) {
		//Drawing the background
		Image map_image;
		//map_image.loadFromFile("./Images/backwindow.jpg");
		//map_image.loadFromFile("./Images/lvl_1_w_back.png");   //"../SFML/Images/backwindow.jpg"
		map_image.loadFromFile("./Images/lvl_2_w_back.png");   //"../SFML/Images/backwindow.jpg"
		//map_image.loadFromFile("./Images/lvl_5_w_back.png");   //"../SFML/Images/backwindow.jpg"
		
		/*Texture map;
		map.loadFromImage(map_image);
		Sprite s_map;
		s_map.setTexture(map);
		s_map.setPosition(0, 0);
		window.draw(s_map);*/

		Texture texture;
		texture.loadFromFile("./Images/main_back.png");
		MainMenu.setTexture(texture);
		MainMenu.setPosition(0, 0);
		window.draw(MainMenu);
	}

	void drawIcons(RenderWindow& window)
	{

		playgameIcon.draw(window);
		InstructionIcon.draw(window);
		highScoreIcon.draw(window);
		Quit.draw(window);
	}

	void playGame()
	{
		//RenderWindow window(VideoMode(1200, 700), "PvZ");
		//window.setPosition(Vector2i(100, 100));

		Gamewindow.create(VideoMode(1200, 700), "PvZ");
		Gamewindow.setPosition(Vector2i(100, 100));

		while (Gamewindow.isOpen())
		{


			Event e;
			while (Gamewindow.pollEvent(e))
			{

				if (e.type == Event::Closed || Quit.isClicked(e))
				{
					end = true;
					Gamewindow.close();
				}


				// For Testing
				if (e.type == Event::MouseButtonReleased)
				{
					//std::cout << "x: " << Mouse::getPosition(window).x << " y: " << Mouse::getPosition(window).y << "\n";
				}
				// ==========

				if (InstructionIcon.isClicked(e))
				{
					Gamewindow.close();

					hS.getWindow().close();

					iS.render();
				}

				if (highScoreIcon.isClicked(e))
				{
					Gamewindow.close();

					iS.getWindow().close();

					hS.render();
				}

				if (playgameIcon.isClicked(e))
				{
					Gamewindow.close();
					hS.getWindow().close();

					iS.getWindow().close();

					level->start();
				}

				if (!Gamewindow.isOpen() && end == false)
				{
					playGame();
					//window.create(VideoMode(1200, 700), "PvZ");
					////window.clear();
					//window.setPosition(Vector2i(100, 100));
				}
			}



			createBack(Gamewindow);

			drawIcons(Gamewindow);

			Gamewindow.display();

		}

	}

	~Game()
	{
		delete level;
		level = NULL;
	}
};

