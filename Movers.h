#pragma once
#include"coordinates.h"
#include<SFML/Graphics.hpp>
#include "ZombieFactory.h"
using namespace sf;

class Movers
{
	Texture texture;
	Sprite sprite;
	bool triggered;
	coordinates pos;
	coordinates mid;

public:
	Movers(coordinates);
	void Move();
	void draw(RenderWindow& window);

	coordinates getPos() { return pos; }
	coordinates getmid() { return mid; }
	void mark(Zombie* zombie);
	void mark(DancingZombie* zombie);
	void mark(BackUpDancer* zombie);
};

