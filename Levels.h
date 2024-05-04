#pragma once
#include"ZombieFactory.h"
#include"PlantFactory.h"

class Levels
{

protected:


	RenderWindow window;
	Texture texture;
	Sprite backgroundSprite;
	//Music backGroundMusic

	ZombieFactory zf;
	PlantFactory pf;

public:

	//Drawing the background
	void createBack(RenderWindow& window) {
		//Drawing the background
		Image map_image;
		//map_image.loadFromFile("./Images/backwindow.jpg");
		//map_image.loadFromFile("./Images/lvl_1_w_back.png");   //"../SFML/Images/backwindow.jpg"
		map_image.loadFromFile("./Images/lvl_2_w_back.png");   //"../SFML/Images/backwindow.jpg"
		//map_image.loadFromFile("./Images/lvl_5_w_back.png");   //"../SFML/Images/backwindow.jpg"
		Texture map;
		map.loadFromImage(map_image);
		Sprite s_map;
		s_map.setTexture(map);
		s_map.setPosition(0, 0);
		window.draw(s_map);
	}

	void start()
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

		//Zombie* z1(NULL);
		ZombieFactory zf;
		//Sentry sentry;
		float deltaTime;
		while (window.isOpen())
		{
			deltaTime = clock.restart().asSeconds();


			float time = clock.getElapsedTime().asMicroseconds();
			float moneyTime = timeMoney.getElapsedTime().asSeconds();



			clock.restart();
			time = time / 800;



			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}



				if (event.type == Event::MouseButtonReleased)
					std::cout << "Game --> x: " << Mouse::getPosition(window).x << " y: " << Mouse::getPosition(window).y << "\n";
			}



			//Create a background
			createBack(window);
			//createMap(window);

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

			zf.spawnWave();
			zf.DrawZombies(window, deltaTime);
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

		//MainMenuScreen::render();
	}
	

};

