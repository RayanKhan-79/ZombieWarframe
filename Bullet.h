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






