#include "Levels.h"
#include <SFML/Audio.hpp>
Levels::Levels(int plantsUnlocked, int zombiesUnlocked, int maxZombies, int maxDancers)
	:
	pauseIcon(coordinates(1030, 10), coordinates(1180, 55)),
	SkipLevel(coordinates(1030, 60), coordinates(1180, 100)),
	pauseMenu(coordinates(325, 50)), 
	Shovel(coordinates(1130,630), coordinates(1200,700)), 
	pf(plantsUnlocked),
	zf(maxZombies, maxDancers, zombiesUnlocked),
	sunGenerator(10)
	
	
{

	for (int i = 0; i < 5; i++)
		movers[i] = new Movers(coordinates(215, 85 + 118 * (i + 1) - 70));

	Texture pauseTexture;
	pauseTexture.loadFromFile("./Images/PauseButton.png");
	Texture skipTexture;
	skipTexture.loadFromFile("./Images/SkipLevel.png");
	Texture shovelTexture;
	shovelTexture.loadFromFile("./Images/shovelicon.png");
	pauseIcon.setTexture(pauseTexture);
	SkipLevel.setTexture(skipTexture);
	Shovel.setTexture(shovelTexture);
}

void Levels::drawMovers(RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
		movers[i]->draw(window);
}

void Levels::MoveMovers()
{
	for (int i = 0; i < 5; i++)
		movers[i]->Move();
}

void Levels::cherryBlast()
{

	if (!pf.getCherryBomb())
		return;

	for (int i = 0; i < zf.getNumberOfZombies(); i++)
		if (LargeAreaMatch(pf.getCherryBomb()->getBlastPoint1(), pf.getCherryBomb()->getBlastPoint2(), zf.getZombies()[i]->getHitArea()))
		{

			zf.getZombies()[i]->getHealth() -= 1000;
			//killCount++;
		}

	for (int i = 0; i < zf.getNumberOfDancers(); i++)
	{
		if (LargeAreaMatch(pf.getCherryBomb()->getBlastPoint1(), pf.getCherryBomb()->getBlastPoint2(), zf.getDancers()[i]->getHitArea()))
		{

			zf.getDancers()[i]->getHealth() -= 1000;
			//killCount++;
		}

		for (int k = 0; k < 4; k++)
			if (zf.getBackUp()[i][k] && LargeAreaMatch(pf.getCherryBomb()->getBlastPoint1(), pf.getCherryBomb()->getBlastPoint2(), zf.getBackUp()[i][k]->getHitArea()))
			{

				zf.getBackUp()[i][k]->getHealth() -= 1000;
				//killCount++;
			}
	
	}

	




}

void Levels::TriggerMovers()
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < zf.getNumberOfZombies(); i++)
		{
			if (approxMatch(zf.getZombies()[i]->getHitArea(), movers[j]->getmid()))
			{
				movers[j]->mark(zf.getZombies()[i]);
				zf.getZombies()[i]->mark();
				//killCount++;
			}
		}

		for (int i = 0; i < zf.getNumberOfDancers(); i++)
		{
			if (approxMatch(zf.getDancers()[i]->getHitArea(), movers[j]->getmid()))
			{
				movers[j]->mark(zf.getDancers()[i]);
				zf.getDancers()[i]->mark();
				//killCount++;
			}
		}
		for (int i = 0; i < zf.getNumberOfDancers(); i++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (zf.getBackUp()[i][k] && approxMatch(zf.getBackUp()[i][k]->getHitArea(), movers[j]->getmid()))
				{
					movers[j]->mark(zf.getBackUp()[i][k]);
					zf.getBackUp()[i][k]->mark();
					//killCount++;
				}
			}
		}
	}
}

void Levels::collisionDetection()
{
	for (int j = 0; j < pf.getNumPlants(); j++)
	{
		for (int i = 0; i < zf.getNumberOfZombies(); i++)
		{
			if (approxMatch(zf.getZombies()[i]->getHitArea(), pf.getPlants()[j]->getHitArea()))
			{
				
				zf.getZombies()[i]->Attack(pf.getPlants()[j]);

				//std::cout << pf.getPlants()[j]->getHealth() << '\n';
			}

			for (int m = 0; m < pf.getPlants()[j]->getBulletCount(); m++)
			{
				if (pf.getPlants()[j]->getBullet() != NULL && pf.getPlants()[j]->getBullet()[m] != NULL && approxMatch(zf.getZombies()[i]->getHitArea(), pf.getPlants()[j]->getBullet()[m]->getCoordinates()))
				{
					if (zf.getZombies()[i]->getHealth() > 0)
					{
						zf.getZombies()[i]->mark();
						zf.getZombies()[i]->getShotAt(pf.getPlants()[j]->getBullet()[m]);
					}

					//else
					//{
					//	killCount++;
					//}
				}
			}


		}

		for (int i = 0; i < zf.getNumberOfDancers(); i++)
		{
			if (approxMatch(zf.getDancers()[i]->getHitArea(), pf.getPlants()[j]->getHitArea()))
			{
				zf.getDancers()[i]->Attack(pf.getPlants()[j]);

				//std::cout << pf.getPlants()[j]->getHealth() << '\n';
			}
			for (int m = 0; m < pf.getPlants()[j]->getBulletCount(); m++)
			{
				if (pf.getPlants()[j]->getBullet() != NULL && pf.getPlants()[j]->getBullet()[m] != NULL && approxMatch(zf.getDancers()[i]->getHitArea(), pf.getPlants()[j]->getBullet()[m]->getCoordinates()))
				{
					if (zf.getDancers()[i]->getHealth() > 0)
					{
						zf.getDancers()[i]->mark();
						zf.getDancers()[i]->getShotAt(pf.getPlants()[j]->getBullet()[m]);
					}

					//else
					//{
					//	killCount++;
					//}
				}
			}


		}

		for (int i = 0; i < zf.getNumberOfDancers(); i++)
			for (int k = 0; k < 4; k++)
			{
				if (zf.getBackUp()[i][k] && approxMatch(zf.getBackUp()[i][k]->getHitArea(), pf.getPlants()[j]->getHitArea()))
				{
					zf.getBackUp()[i][k]->Attack(pf.getPlants()[j]);
					//std::cout << pf.getPlants()[j]->getHealth() << '\n';

				}

				for (int m = 0; m < pf.getPlants()[j]->getBulletCount(); m++)
				{
					if (pf.getPlants()[j]->getBullet() != NULL && pf.getPlants()[j]->getBullet()[m] != NULL && zf.getBackUp()[i][k] != NULL && approxMatch(zf.getBackUp()[i][k]->getHitArea(), pf.getPlants()[j]->getBullet()[m]->getCoordinates()))
					{
						if (zf.getBackUp()[i][k]->getHealth() > 0)
						{
							zf.getBackUp()[i][k]->mark();
							zf.getBackUp()[i][k]->getShotAt(pf.getPlants()[j]->getBullet()[m]);
						}

						//else
						//{
						//	killCount++;
						//}
					}
				}

			}


	}
}

int Levels::winCondition()
{
	if (zf.isWaveLimitReached())
		return 1;  // Player has won

	if (lives <= 0)
		return 2;  // Player has lost

	else 
		return 0;  // Neither won nor lost continue playing
}

bool Levels::start(int& killCount)
{
	const int GRID_LEFT = 300;
	const int GRID_TOP = 85;
	const int GRID_WIDTH = 855;
	const int GRID_HEIGHT = 590;
	const int CELL_WIDTH = 95;
	const int CELL_HEIGHT = 118;


	auto withinGrid = [&](int mouseX, int mouseY) {
	
		return (mouseX >= GRID_LEFT && mouseX < GRID_LEFT + GRID_WIDTH &&
			mouseY >= GRID_TOP && mouseY < GRID_TOP + GRID_HEIGHT);
		};

	const int ROWS = 5;
	const int COLS = 9;
	
	int x = 1;
	srand(time(0));

	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	window.setPosition(Vector2i(100, 100));

	Image icon;
	if (!icon.loadFromFile("./Images/icon.png"))
	{
		//return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53


	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = 0;
		}
	}

	Clock timeMoney;

	//Texture tex;
	//tex.loadFromFile("./Images/Sunflower_i.png");
	//SeedPackets kicon(coordinates(300, 300), coordinates(400, 400), 1);
	//kicon.setTexture(tex);



	Clock clock;
	Clock time;
	window.setFramerateLimit(20);

	//DancingZombie* z1[5]{};
	//for (int i = 0; i < 5; i++)
	//	z1[i] = new DancingZombie(5, 4, 200, 4);
	//ZombieFactory zf;
	


	float deltaTime;
	bool shovel = false;

	sf::Music backgroundMusic;
	if (!backgroundMusic.openFromFile("./Audio/level.mp3")) {
		std::cerr << "Error loading background music!" << std::endl;
		return false; // Exit if music file loading fails
	}

	// Set the volume to 50
	backgroundMusic.setVolume(50);

	// Play the music in a loop
	backgroundMusic.setLoop(true);
	backgroundMusic.play();

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();


		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();



		clock.restart();
		time = time / 800;

		createBack(window);

		coordinates MousePosition;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				return false;
				window.close();
			}

			if (pauseIcon.isClicked(event) || pauseMenu.paused == true)
			{
				pauseMenu.paused = true;
			}

			if (SkipLevel.isClicked(event))
			{
				return true;
			}

			if (pauseMenu.resumeIsClicked(event))
			{
				pauseMenu.paused = false;
			}

			if (Shovel.isClicked(event))
			{
				shovel = true;
			}

			if (sunGenerator.Update(event))
			{
				scoreBoard.IncrementSuns(25);
			}

			//if (kicon.isClicked(event))
			//{

			//	std::cout << "I am clcikedddd";
			//}
			//if (seed.isClicked(event))
			//{
			//}
			//else if (event.type == Event::MouseButtonReleased)
			//	{
			//		MousePosition.x = Mouse::getPosition(window).x;
			//		MousePosition.y = Mouse::getPosition(window).y;

			//		int x = 1;

			//		// Check if the mouse click is within the game grid
			//		if (withinGrid(MousePosition.x, MousePosition.y))
			//		{
			//			// Calculate the row and column of the clicked cell
			//			int row = (MousePosition.y - GRID_TOP) / CELL_HEIGHT;
			//			int col = (MousePosition.x - GRID_LEFT) / CELL_WIDTH;

			//			std::cout << "GRID: " << col << ' ' << row << '\n';



			//			// *********************************
			//			// Itni zyadi mathematics karney ki kya zaroorat thi ?
			//			// *********************************

			//			// Calculate the position of the plant
			//			// int plantX = GRID_LEFT + col * CELL_WIDTH + CELL_WIDTH / 2; // Center of the cell
			//			// int plantY = GRID_TOP + row * CELL_HEIGHT + CELL_HEIGHT / 2; // Center of the cell

			//			// Adjust the position to draw the sprite from its middle
			//			// plantX -= pf.getSpriteWidth() / 2;
			//			// plantY -= pf.getSpriteHeight() / 2;
			//			// Spawn the plant at the calculated position
			//			// pf.spawnSunflowerAtPosition(plantX, plantY);

			//			// *********************************
			//			// Bas itni sa likna tha :)
			//			// *********************************
			//			if (FIELD_GAME_STATUS[row][col] == 0)
			//			{
			//				FIELD_GAME_STATUS[row][col] = 1;

			//				int plantX = GRID_LEFT + col * CELL_WIDTH;
			//				int plantY = GRID_TOP + row * CELL_HEIGHT;
			//				pf.spawnSunflowerAtPosition(plantX, plantY - 140 + CELL_HEIGHT, x);
			//			}
			//			//-------------------------------------------
			//		}
			//	}
			//if (event.type == Event::MouseButtonReleased && Mouse::getPosition().x < 290 && pf.selected == false)
			//{
			//	x = pf.Clicked(event);
			//	pf.selected = true;
			//}
			/*else if (int x = pf.Clicked(event))
			{*/
			

			else if (event.type == Event::MouseButtonReleased)
			{
				MousePosition.x = Mouse::getPosition(window).x;
				MousePosition.y = Mouse::getPosition(window).y;
				pf.PlantClicked(event, shovel);

					if (pf.selected == false)
					{
						x = pf.Clicked(event);
						pf.selected = true;
					}


					// Check if the mouse click is within the game grid
					if (withinGrid(MousePosition.x, MousePosition.y) && pf.selected == true)
					{
						pf.selected = false;
						// Calculate the row and column of the clicked cell
						int row = (MousePosition.y - GRID_TOP) / CELL_HEIGHT;
						int col = (MousePosition.x - GRID_LEFT) / CELL_WIDTH;

						std::cout << "GRID: " << col << ' ' << row << '\n';



						// *********************************
						// Itni zyadi mathematics karney ki kya zaroorat thi ?
						// *********************************

						// Calculate the position of the plant
						// int plantX = GRID_LEFT + col * CELL_WIDTH + CELL_WIDTH / 2; // Center of the cell
						// int plantY = GRID_TOP + row * CELL_HEIGHT + CELL_HEIGHT / 2; // Center of the cell

						// Adjust the position to draw the sprite from its middle
						// plantX -= pf.getSpriteWidth() / 2;
						// plantY -= pf.getSpriteHeight() / 2;
						// Spawn the plant at the calculated position
						// pf.spawnSunflowerAtPosition(plantX, plantY);

						// *********************************
						// Bas itni sa likna tha :)
						// *********************************
						if (FIELD_GAME_STATUS[row][col] == 0)
						{
							FIELD_GAME_STATUS[row][col] = 1;

							int plantX = GRID_LEFT + col * CELL_WIDTH;
							int plantY = GRID_TOP + row * CELL_HEIGHT;
							pf.spawnSunflowerAtPosition(plantX, plantY - 140 + CELL_HEIGHT, x);
						}
						//-------------------------------------------
					}
			}
			//seed.draw(window);
			//
			//}

		//Sun implementation
		//	while (window.pollEvent(event)) {
		//		if (event.type == sf::Event::Closed) {
		//			window.close();
		//		}
		//		// Pass the event to Sun's isClick function
		//		sun.isClick(event);
		//	}

		//	sun.UpdateAnimation(deltaTime,0.25);

		//	window.draw(sun.getSprite());

		//	// Draw the score
		//	sun.scoreDisplay(window, font);


		//	if (event.type == Event::MouseButtonReleased)
		//		std::cout << "Game --> x: " << Mouse::getPosition(window).x << " y: " << Mouse::getPosition(window).y << "\n";
		}



		//kicon.draw(window);
		scoreBoard.draw(window);
		pauseIcon.draw(window);
		SkipLevel.draw(window);
		Shovel.draw(window);
		//if (z1 == NULL)
		//{
		//	z1 = new Zombie(200, 1, 20, 1000, 118 * 2 + 85 - 180);
		//}

		//if (z1 && z1->getHealth() < 0)
		//{
		//	delete z1;
		//	z1 = NULL;
		//}

		//sentry.shoot();
		//sentry.draw(window);
		if (pauseMenu.paused == false) 
		{
			//pf.spawnSunflowerRandomly(5, 9);
			cherryBlast();
			pf.DeleteDeadPlants(FIELD_GAME_STATUS);
			pf.DrawPlants(window, deltaTime);
			
			pf.Shoot();


			//pf.DeleteProjectiles();
			//std::cout << "KILLS: " << zf.getKills() << '\n';
			scoreBoard.UpdateScore(killCount);
			sunGenerator.spawnSun();
			sunGenerator.moveSun(window);
			//sun.draw(window);
			//sun.Move();
			//for (int i = 0; i < 5; i++)
			//{
			//	z1[i]->Move();
			//	z1[i]->Draw(window, deltaTime);
			//}

			//for (int i = 0; i < 5; i++)
			//	for (int j = 0; j < pf.getNumPlants(); j++)
			//	{
			//		if (approxMatch(z1[i]->getHitArea(), pf.getPlants()[j]->getPosition()))
			//		{
			//			//z1[i] ->action = "attacking";
			//			//z1[i]->Attack(pf.getPlants()[j]);

			//			//std::cout << pf.getPlants()[j]->getHealth() << '\n';

			//		}
			//		if (z1[i]->getBackUp())
			//		{
			//			BackUpDancer** back = z1[i]->getBackUp();
			//			for (int k = 0; k < 4; k++)
			//				if (approxMatch(back[k]->getHitArea(), pf.getPlants()[j]->getPosition()))
			//				{
			//					back[k]->action = "attacking";
			//					back[k]->Attack(pf.getPlants()[j]);
			//					std::cout << pf.getPlants()[j]->getHealth() << '\n';
			//				}
			//		}
			//	
			//	}


			zf.spawnWave(killCount);
			zf.DrawZombies(window, deltaTime);
			collisionDetection();
			TriggerMovers();
			MoveMovers();
		}

		else if (pauseMenu.paused == true)
		{
			pauseMenu.draw(window);

		}
		
		pf.DrawIcons(window);
		drawMovers(window);
		//pf.DrawPlants(window, deltaTime);
		//zf.spawnWave();
		//zf.DrawZombies(window, deltaTime);
		
		//if (z1)
		//{
		//	z1->Collision(sentry.getBullet());
		//	z1->Draw(window, deltaTime);
		//	z1->Move();
		//	z1->UpdateAnimation(deltaTime);
		//}

		if (winCondition() == 1)
			return true;

		if (winCondition() == 2)
			return false;


		window.setSize(sf::Vector2u(1200, 700));
		window.setPosition(Vector2i(100, 100));
		window.display();
	}
}












//////std::cout << "px: " << zf.getZombies()[i]->getPosition().x << "  hx: " << zf.getZombies()[i]->getHitArea().x << '\n';
//////std::cout << "py: " << zf.getZombies()[i]->getPosition().y + 180 - 118 << "  hy: " << zf.getZombies()[i]->getHitArea().y << '\n';
//////std::cout << "Plant:\n";
//////std::cout << "px: " << pf.getPlants()[i]->getPosition().x << "  hx: " << pf.getPlants()[i]->getPosition().x + 95 << '\n';
//////std::cout << "py: " << pf.getPlants()[i]->getPosition().y + 145 - 118 << "  hy: " << pf.getPlants()[i]->getPosition().y + 145 << '\n';
//system("pause");
