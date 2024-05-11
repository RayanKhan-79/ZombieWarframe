#pragma once
#include"coordinates.h"
#include<SFML/Graphics.hpp>
#include<iostream>

class Bullet
{
	coordinates pos;
	sf::CircleShape bullet;
	sf::Clock clock;
	bool collided;
	
public:
	Bullet(coordinates pos) : pos(pos), collided(false)
	{
		sf::Color c(255, 0, 0);
		bullet.setFillColor(c);
		bullet.setRadius(5);
		bullet.setPosition(pos.x, pos.y);
	}

	void Move()
	{
		if (clock.getElapsedTime().asSeconds() < 0.001)
			return;

		clock.restart();
		pos.x += 20.f;
	}

	void draw(sf::RenderWindow& window)
	{
		bullet.setPosition(pos.x, pos.y);
		window.draw(bullet);
		//std::cout << "Sentry--> Bx: " << pos.x << " By: " << pos.y << "\n";
		
	}

	bool Existance()
	{
		if (collided || pos.x >= 1200 /*out of screen*/)
			return false;

		return true;
	}

	coordinates& getCoordinates()
	{
		return pos;
	}

	void setCollisonStatus(bool boolean)
	{
		collided = boolean;
	}

};

class Sentry
{
	
	coordinates pos;
	sf::RectangleShape shape;
	sf::Clock clock;
	Bullet* bullets;

	//int* bullets;

public:
	Sentry(coordinates pos) : pos(pos), bullets(NULL)
	{
		sf::Color c(0, 0, 0);
		shape.setFillColor(c);
		shape.setSize(sf::Vector2f(80, 160));
	}

	void shoot()
	{


		if (clock.getElapsedTime().asSeconds() < 0.5 || bullets)
			return;

		clock.restart();
		bullets = new Bullet(coordinates(pos.x + 80, pos.y + 80));
	}


	void draw(sf::RenderWindow& window)
	{
		shape.setPosition(pos.x, pos.y);
		window.draw(shape);

		if (bullets)
		{
			if (bullets->Existance())
				bullets->draw(window);

			else
			{
				delete bullets;
				bullets = NULL;
			}
		}

	}

	Bullet* getBullet()
	{
		return bullets;
	}



};






