#include "Game.h"
#include <SFML/Audio.hpp>

Game::Game()
	: level(NULL),
	playgameIcon(coordinates(465, 220), coordinates(735, 300)),
	InstructionIcon(coordinates(465, 310), coordinates(735, 390)),
	highScoreIcon(coordinates(465, 400), coordinates(735, 480)),
	Quit(coordinates(910, 600), coordinates(1180, 680)),
	EnterName(coordinates(465, 490), coordinates(735, 580)),
	Badges(coordinates(465, 10), coordinates(630,70)),
	end(false),
	win(false),
	killCount(0)
{
	
	Texture buttonTextures[6];
	buttonTextures[0].loadFromFile("./Images/PlayButton.png");
	buttonTextures[1].loadFromFile("./Images/Instructions.png");
	buttonTextures[2].loadFromFile("./Images/HighScore.png");
	buttonTextures[3].loadFromFile("./Images/Quit.png");
	buttonTextures[4].loadFromFile("./Images/button_large.png");
	buttonTextures[5].loadFromFile("./Images/badges0.png");


	playgameIcon.setTexture(buttonTextures[0]);
	InstructionIcon.setTexture(buttonTextures[1]);
	highScoreIcon.setTexture(buttonTextures[2]);
	Quit.setTexture(buttonTextures[3]);
	EnterName.setTexture(buttonTextures[4]);
	Badges.setTexture(buttonTextures[5]);

	mainTexture.loadFromFile("./Images/main_back.png");
	MainMenu.setTexture(mainTexture);
	MainMenu.setPosition(0, 0);


	font.loadFromFile("./Font/COMICSANSBOLD.ttf");
	dispName.setPosition(465, 500);
	dispName.setCharacterSize(32);
	dispName.setFillColor(Color(255, 0, 0));
	dispName.setFont(font);
	dispName.setString("");
}

void Game::drawIcons(RenderWindow& window)
{

	playgameIcon.draw(window);
	InstructionIcon.draw(window);
	highScoreIcon.draw(window);
	Quit.draw(window);
	EnterName.draw(window);
	Badges.draw(window);
	window.draw(dispName);
}

void Game::playGame()
{
	bool toggle = false;
	Gamewindow.create(VideoMode(1200, 700), "Plant Vs Zombies");
	Gamewindow.setPosition(Vector2i(100, 100));

	sf::Music backgroundMusic;
	if (!backgroundMusic.openFromFile("./Audio/game.mp3")) {
		std::cerr << "Error loading background music!" << std::endl;
		return; // Exit if music file loading fails
	}

	// Set the volume to 50
	backgroundMusic.setVolume(50);

	// Play the music in a loop
	backgroundMusic.setLoop(true);
	backgroundMusic.play();

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

			if (EnterName.isClicked(e))
			{
				toggle = true;
			}

			if (e.type == Event::TextEntered && toggle)
			{
				std::cout << std::to_string(e.text.unicode) << ' ';
				name += e.text.unicode;
				dispName.setString(name);
			}

			if (e.type == Event::KeyReleased && e.key.code == Keyboard::Enter && toggle)
			{
				toggle = false;
			}
			
			if (e.type == Event::MouseButtonReleased)
			{
				std::cout << "x: " << Mouse::getPosition(Gamewindow).x << " y: " << Mouse::getPosition(Gamewindow).y << "\n";
			}


			if (InstructionIcon.isClicked(e))
			{
				backgroundMusic.setVolume(0);
				Gamewindow.close();

				hS.getWindow().close();

				iS.render();
			}

			if (highScoreIcon.isClicked(e))
			{
				backgroundMusic.setVolume(0);
				Gamewindow.close();

				iS.getWindow().close();

				hS.render();
			}

			if (playgameIcon.isClicked(e))
			{
				backgroundMusic.setVolume(0);
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
				storeKillCount(killCount);
			}
		}

		Gamewindow.draw(MainMenu);

		drawIcons(Gamewindow);

		//Gamewindow.draw(dispName);

		Gamewindow.display();

	}

}
void Game::storeKillCount(int killCount) {
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

Game::~Game()
{
	if (level != NULL)
	{
		delete level;
		level = NULL;
	}
}