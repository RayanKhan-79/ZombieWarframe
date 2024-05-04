#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
#include "Zombie.h"
using namespace sf;
class Plant
{
private:
	int health;
	coordinates Pos;
	Image image;
	Texture texture;
	Sprite sprite;
	float Total_Animation_Time ;
	float switchTime;
	int offset;
public:
	Plant(int x, int y=randGrid(145), int h=1);
	virtual void Draw(RenderWindow& window, float deltaTime);
	virtual void UpdateAnimation(float interval);
	bool isClick();
};

