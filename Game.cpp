#include "Game.h"


Game::Game()
	: level(NULL), 
	playgameIcon(coordinates(465, 220), coordinates(735,300)), 
	InstructionIcon(coordinates(465, 310), coordinates(735, 390)),
	highScoreIcon(coordinates(465, 400), coordinates(735, 480)),
	Quit(coordinates(910, 600), coordinates(1180, 680)), 
	end(false),
	win(false),
	killCount(0)
{
	
	Texture buttonTextures[4];
	buttonTextures[0].loadFromFile("./Images/PlayButton.png");
	buttonTextures[1].loadFromFile("./Images/Instructions.png");
	buttonTextures[2].loadFromFile("./Images/HighScore.png");
	buttonTextures[3].loadFromFile("./Images/Quit.png");

	playgameIcon.setTexture(buttonTextures[0]);
	InstructionIcon.setTexture(buttonTextures[1]);
	highScoreIcon.setTexture(buttonTextures[2]);
	Quit.setTexture(buttonTextures[3]);

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

				level = new BeginnersGarden();
				std::cout << "BEGINNER'S GARDEN\n";
				if (level->start(killCount))
				{
					
					delete level;
					level = new ZombieOutskirts();
					
					std::cout << "ZOMBIE OUTSKIRTS\n";
					
					if (level->start(killCount))
					{
					
						delete level;
						level = new SunflowerFields();

						std::cout << "SUNFLOWER FIELDS\n";
						
						if (level->start(killCount))
						{
						
							delete level;
							level = new FoggyForest();

							std::cout << "FOGGY FOREST\n";

							if (level->start(killCount))
							{
							
								delete level;
								level = new NightTimeSiege();

								std::cout << "FOGGY FOREST\n";

								if (level->start(killCount))
								{
								
									delete level;
									level = new RoofTopRampage();
								
									std::cout << "ROOF TOP RAMPAGE\n";

									if (level->start(killCount))
									{
									
										delete level;
										level = NULL;
										win = true;
										std::cout << "YOU WON\n";
									}

								}
						
							}
					
						}

					}
					
				}

				if (!win)
				{
					gS.Render();
					
				}


			}

			if (!Gamewindow.isOpen() && end == false)
			{
				win = false;
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
	if (level != NULL)
	{
		delete level;
		level = NULL;
	}
}