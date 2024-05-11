#include "Levels.h"
void Levels::start()
{
	const int GRID_LEFT = 300;
	const int GRID_TOP = 85;
	const int GRID_WIDTH = 855;
	const int GRID_HEIGHT = 590;
	const int CELL_WIDTH = 118;
	const int CELL_HEIGHT = 95;


	auto withinGrid = [&](int mouseX, int mouseY) {
	
		return (mouseX >= GRID_LEFT && mouseX < GRID_LEFT + GRID_WIDTH &&
			mouseY >= GRID_TOP && mouseY < GRID_TOP + GRID_HEIGHT);
		};

	const int ROWS = 5;
	const int COLS = 9;


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
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	Clock timeMoney;





	Clock clock;
	Clock time;
	window.setFramerateLimit(20);

	//Zombie* z1(NULL);
	//ZombieFactory zf;
	//Sentry sentry;
	float deltaTime;
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
				window.close();
			}

			if (pauseIcon.isClicked(event) || pauseMenu.paused == true)
			{
				pauseMenu.paused = true;
			}

			if (pauseMenu.resumeIsClicked(event))
			{
				pauseMenu.paused = false;
			}



			if (event.type == Event::MouseButtonReleased)
			{
				MousePosition.x = Mouse::getPosition(window).x;
				MousePosition.y = Mouse::getPosition(window).y;

				// Check if the mouse click is within the game grid
				if (withinGrid(MousePosition.x, MousePosition.y)) {
					// Calculate the row and column of the clicked cell
					int row = (MousePosition.y - GRID_TOP) / CELL_HEIGHT;
					int col = (MousePosition.x - GRID_LEFT) / CELL_WIDTH;

					// Calculate the position of the plant
					int plantX = GRID_LEFT + col * CELL_WIDTH + CELL_WIDTH / 2; // Center of the cell
					int plantY = GRID_TOP + row * CELL_HEIGHT + CELL_HEIGHT / 2; // Center of the cell

					// Adjust the position to draw the sprite from its middle
					plantX -= pf.getSpriteWidth() / 2;
					plantY -= pf.getSpriteHeight() / 2;

					// Spawn the plant at the calculated position
					pf.spawnSunflowerAtPosition(plantX, plantY);
				}
			}





			if (event.type == Event::MouseButtonReleased)
				std::cout << "Game --> x: " << Mouse::getPosition(window).x << " y: " << Mouse::getPosition(window).y << "\n";
		}



		//Create a background

		pauseIcon.draw(window);

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
		//	pf.spawnSunflowerRandomly(5, 9);
			pf.DrawPlants(window, deltaTime);
			zf.spawnWave();
			zf.DrawZombies(window, deltaTime);
			collisionDetection();
		}

		else if (pauseMenu.paused == true)
		{
			pauseMenu.draw(window);
		}
		
		pf.DrawIcons(window);
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



		window.setSize(sf::Vector2u(1200, 700));
		window.setPosition(Vector2i(100, 100));
		window.display();
	}
}

