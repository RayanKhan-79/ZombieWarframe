#pragma once
#include"coordinates.h"
#include<SFML/Graphics.hpp>
#include<iostream>


class Bullet
{
	int damage;
	std::string type;
	coordinates pos;
	sf::Texture texture;
	sf::Sprite bullet;
	sf::Clock clock;
	bool collided;
	
public:
	Bullet(coordinates pos, int damage, std::string type);

	void Move();
	
	void draw(sf::RenderWindow& window);

	bool Existance();

	coordinates& getCoordinates();

	void setCollisonStatus(bool boolean);

	int getDamage();

	std::string getType();

};

//class Sentry
//{
//	
//	coordinates pos;
//	sf::RectangleShape shape;
//	sf::Clock clock;
//	Bullet* bullets;
//
//	//int* bullets;
//
//public:
//	Sentry(coordinates pos) : pos(pos), bullets(NULL)
//	{
//		sf::Color c(0, 0, 0);
//		shape.setFillColor(c);
//		shape.setSize(sf::Vector2f(80, 160));
//	}
//
//	void shoot()
//	{
//
//
//		if (clock.getElapsedTime().asSeconds() < 0.5 || bullets)
//			return;
//
//		clock.restart();
//		bullets = new Bullet(coordinates(pos.x + 80, pos.y + 80));
//	}
//
//
//	void draw(sf::RenderWindow& window)
//	{
//		shape.setPosition(pos.x, pos.y);
//		window.draw(shape);
//
//		if (bullets)
//		{
//			if (bullets->Existance())
//				bullets->draw(window);
//
//			else
//			{
//				delete bullets;
//				bullets = NULL;
//			}
//		}
//
//	}
//
//	Bullet* getBullet()
//	{
//		return bullets;
//	}
//
//
//
//};






