#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
using namespace sf;

class Zombie
{
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
	Zombie(int=200, int=1, int=5, int=1000, int=240);
	void Draw(RenderWindow&, float);
	void Move();
	void UpdateAnimation(float interval);
	//void Attack();
	//void Collision();

};

