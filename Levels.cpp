#include "Levels.h"

void Levels::start()
{
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
	const int ROWS = 5;
	const int COLS = 9;

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

	DancingZombie* z1[5]{};
	for (int i = 0; i < 5; i++)
		z1[i] = new DancingZombie(5, 4, 200, 4);
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
				std::cout << "x: " << MousePosition.x<<std::endl;
				std::cout << "y: " << MousePosition.y<<std::endl;
				pf.spawnSunflowerAtPosition(MousePosition.x, MousePosition.y);
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
			pf.spawnSunflowerRandomly(5, 9);
			pf.DrawPlants(window, deltaTime);
			
			for (int i = 0; i < 5; i++)
			{
				z1[i]->Move();
				z1[i]->Draw(window, deltaTime);
			}

			for (int i = 0; i < 5; i++)
				for (int j = 0; j < pf.getNumPlants(); j++)
				{
					if (approxMatch(z1[i]->getHitArea(), pf.getPlants()[j]->getPosition()))
					{
						//z1[i] ->action = "attacking";
						//z1[i]->Attack(pf.getPlants()[j]);

						//std::cout << pf.getPlants()[j]->getHealth() << '\n';

					}
					if (z1[i]->getBackUp())
					{
						BackUpDancer** back = z1[i]->getBackUp();
						for (int k = 0; k < 4; k++)
							if (approxMatch(back[k]->getHitArea(), pf.getPlants()[j]->getPosition()))
							{
								back[k]->action = "attacking";
								back[k]->Attack(pf.getPlants()[j]);
								std::cout << pf.getPlants()[j]->getHealth() << '\n';
							}
					}
				
				}
			//zf.spawnWave();
			//zf.DrawZombies(window, deltaTime);
			//collisionDetection();
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

