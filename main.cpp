#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
//#include"../SFML/Images/"

using namespace sf;
using namespace std;


struct coordinats {
	int x;
	int y;
	coordinats(int x, int y) : x(x), y(y) {}
};


class Zombie
{
	int health;
	int speed;
	int damage;
	Image image;
	Texture texture;
	Sprite sproota;
	coordinats Pos;

public:
	Zombie(int health, int speed, int damage, int x, int y) :Pos(x,y), health(health), speed(speed), damage(damage)
	{
		image.loadFromFile("./Images/zombie.png");
		texture.loadFromImage(image);
		sproota.setTexture(texture);
		sproota.setPosition(Pos.x, Pos.y);
	}


	void Draw(RenderWindow& window)
	{
		window.draw(sproota);
	}

	void Move()
	{
		Pos.x -= speed;
		sproota.setPosition(Pos.x, Pos.y);
	}


};


//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	map_image.loadFromFile("./Images/backwindow.jpg");   //"../SFML/Images/backwindow.jpg"
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
	map_image.loadFromFile("./Images/grid.png");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(300, 140);

	window.draw(s_map);
}


int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("./Images/icon.png"))
	{
		return 1;
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
	
	Zombie z1(200, 1, 20, 1200, 150);
	Zombie z2(200, 1, 20, 1200, 260);
	Zombie z3(200, 2, 20, 1200, 370);
	Zombie z4(200, 2, 20, 1200, 480);
	Zombie z5(200, 3, 20, 1200, 590);





	Clock clock;
	Clock time;
	double S_time = time.getElapsedTime().asSeconds();
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		double E_time = time.getElapsedTime().asSeconds();
		double FPS = 1/(E_time);
		time.restart();
		cout << "FPS : " << FPS << endl;

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
	
		z1.Draw(window);
		z1.Move();
		z2.Draw(window);
		z2.Move();
		z3.Draw(window);
		z3.Move();
		z4.Draw(window);
		z4.Move();
		z5.Draw(window);
		z5.Move();

		
		window.setSize(sf::Vector2u(1200, 700));
		window.setPosition(Vector2i(100, 100));
		window.display();
	}
	return 0;
}
