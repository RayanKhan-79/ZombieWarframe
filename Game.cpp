#include "Game.h"


Game::Game()
	: level(NULL), 
	playgameIcon("Play", coordinates(465, 130), 56, 27, coordinates(735,270)), 
	InstructionIcon("Instructions", coordinates(465, 280), 149, 25, coordinates(735, 420)),
	highScoreIcon("High Score", coordinates(465, 430), 137, 31, coordinates(735, 570)),
	Quit("Quit", coordinates(910, 540), 58, 29, coordinates(1180, 680)), 
	end(false)
{
	Texture buttonTexture;
	buttonTexture.loadFromFile("./Images/button.png");
	playgameIcon.setTexture(buttonTexture);
	InstructionIcon.setTexture(buttonTexture);
	highScoreIcon.setTexture(buttonTexture);
	Quit.setTexture(buttonTexture);

	mainTexture.loadFromFile("./Images/main_back.png");
	MainMenu.setTexture(mainTexture);
	MainMenu.setPosition(0, 0);
}

void Game::drawIcons(RenderWindow& window)
{

	playgameIcon.draw(window);
	InstructionIcon.draw(window);
	highScoreIcon.draw(window);
	Quit.draw(window);
}

void Game::playGame()
{

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
				std::cout << "x: " << Mouse::getPosition(Gamewindow).x << " y: " << Mouse::getPosition(Gamewindow).y << "\n";
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

				level = new BeginnersGarden;
				std::cout << "BEGINNER'S GARDEN\n";
				if (level->start())
				{
					
					delete level;
					level = new ZombieOutskirts;
					
					std::cout << "ZOMBIE OUTSKIRTS\n";
					
					if (level->start())
					{
					
						delete level;
						level = new SunflowerFields;

						std::cout << "SUNFLOWER FIELDS\n";
						
						if (level->start())
						{
						
							delete level;
							level = new FoggyForest;

							std::cout << "FOGGY FOREST\n";

							if (level->start())
							{
							
								delete level;
								level = new NightTimeSiege;

								std::cout << "FOGGY FOREST\n";

								if (level->start())
								{
								
									delete level;
									level = new RoofTopRampage;
								
									std::cout << "ROOF TOP RAMPAGE\n";

									if (level->start())
									{
									
										delete level;
										
										std::cout << "YOU WON\n";
									}

								}
						
							}
					
						}

					}
					
				}

			}

			if (!Gamewindow.isOpen() && end == false)
			{
				playGame();
			}
		}



		Gamewindow.draw(MainMenu);

		drawIcons(Gamewindow);

		Gamewindow.display();

	}

}

Game::~Game()
{
	delete level;
	level = NULL;
}