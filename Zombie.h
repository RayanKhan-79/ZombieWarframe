#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
#include"Sentry.h"

using namespace sf;

int randGrid(int);

class Zombie
{
protected:
	int health;
	int speed;
	int damage;

	//Image image;
	float Total_Animation_Time;
	float switchTime;
	int offset;
	int pixelsX;
	int pixelsY;
	
	Texture texture;
	Sprite sprite;
	coordinates Pos;

public:
	Zombie(int=200, int=1, int=5, int=1000, int=randGrid(180), int=164, int=180);
	virtual void Draw(RenderWindow&, float);
	virtual void Move();
	virtual void UpdateAnimation(float interval);
	//void Attack();
	void Collision(Bullet*);


	// Getters & Setters
	int getHealth() const;


};

