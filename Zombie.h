#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
using namespace sf;

int randGrid(int);

class Zombie
{
protected:
	int health;
	int speed;
	int damage;

	Image image;
	float Total_Animation_Time;
	float switchTime;
	int offset;
	
	Texture texture;
	Sprite sprite;
	coordinates Pos;

public:
	Zombie(int=200, int=1, int=5, int=1000, int=randGrid(190));
	void Draw(RenderWindow&, float);
	void Move();
	virtual void UpdateAnimation(float interval);
	//void Attack();
	//void Collision();

};

