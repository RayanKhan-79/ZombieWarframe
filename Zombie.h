#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
#include"Sentry.h"
#include"Plant.h"

using namespace sf;



class Zombie
{
protected:
	int health;
	int speed;
	int damage;

	float Total_Animation_Time;
	float switchTime;
	int offset;
	int pixelsX;
	int pixelsY;
	
	Texture texture;
	Sprite sprite;
	coordinates Pos;
	coordinates hitArea;

public:
	std::string action;

public:
	Zombie(int=200, int=1, int=5, int=1000, int=randGrid(180), int=180, int=180);
	virtual void Draw(RenderWindow&, float);
	virtual void Move();
	virtual void UpdateAnimation(float interval);
	void Attack(Plant*);
	void Collision(Bullet*);



	// Getters & Setters
	int getHealth() const;
	coordinates getPosition() const { return Pos; }
	coordinates getHitArea() const { return hitArea; }


};

