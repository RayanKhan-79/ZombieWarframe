#include "Game.h"


Game::Game()
	: level(NULL), playgameIcon("Play", coordinates(456, 130), 56, 27), InstructionIcon("Instructions", coordinates(465, 280), 149, 25), highScoreIcon("High Score", coordinates(465, 430), 137, 31), 
	Quit("Quit", coordinates(910, 540), 58, 29), end(false)
{
	Texture texture_1;
	texture_1.loadFromFile("./Images/button.png");
	playgameIcon.setTexture(texture_1);
	InstructionIcon.setTexture(texture_1);
	highScoreIcon.setTexture(texture_1);
	Quit.setTexture(texture_1);

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

				delete level;


				// For Testing
				if (progress % 2 == 0)
					level = new BeginnersGarden;
				else
					level = new NightTimeSiege;
				progress++;
				// =======

				level->start();
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