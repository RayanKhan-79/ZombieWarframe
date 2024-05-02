#include "PlayGameScreen.h"
#include "ZombieFactory.h"

//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("./Images/backwindow.jpg");
	//map_image.loadFromFile("./Images/lvl_1_w_back.png");   //"../SFML/Images/backwindow.jpg"
	//map_image.loadFromFile("./Images/lvl_2_w_back.png");   //"../SFML/Images/backwindow.jpg"
	//map_image.loadFromFile("./Images/lvl_5_w_back.png");   //"../SFML/Images/backwindow.jpg"
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

//Drawing the map
void createMap(RenderWindow& window) {
	//Drawing a map
	Image map_image;//объект изображения для карты
	map_image.loadFromFile("./Images/lvl_1_map.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(300, 140);

	window.draw(s_map);
}



PlayGameScreen::PlayGameScreen()
{
	texture.loadFromFile("./Images/backwindow.jpg");
	sprite.setTexture(texture);
}

void PlayGameScreen::render()
{
	//window.create(VideoMode(1200, 700), "Game");
	//while (window.isOpen())
	//{

	//	Event e;
	//	while (window.pollEvent(e))
	//	{
	//		if (e.type == Event::Closed)
	//			window.close();
	//	}

	//	window.clear();
	//	window.draw(sprite);
	//	window.display();
	//}


	srand(time(0));
	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	//Game icon
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
	window.setFramerateLimit(10);

	//Zombie z1(200, 1, 20, 1000, 150);
	ZombieFactory zf;

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
				window.close();
		}



		//Create a background
		createBack(window);
		createMap(window);



		zf.spawnWave();
		zf.DrawZombies(window, deltaTime);
		//z1.Draw(window, deltaTime);
		//z1.Move();
		//z1.UpdateAnimation(deltaTime);



		window.setSize(sf::Vector2u(1200, 700));
		window.setPosition(Vector2i(100, 100));
		window.display();
	}
}