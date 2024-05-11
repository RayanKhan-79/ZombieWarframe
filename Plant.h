#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"

using namespace sf;
class Plant
{
protected:
	int health;
	
	float Total_Animation_Time ;
	float switchTime;
	int offset;
	int pixelsX;
	int pixelsY;
	
	Texture texture;
	Sprite sprite;
	coordinates Pos;
	coordinates mid;

public:
	Plant(int x, int y=randGrid(145), int h=200);
	virtual void Draw(RenderWindow& window, float deltaTime);
	virtual void UpdateAnimation(float interval);
	bool isClick();
	coordinates getPosition() { return Pos; }
	coordinates getHitArea() { return mid; }
	int& getHealth() { return health; }
	void mark() 
	{
		Color c(255, 0, 0);
		sprite.setColor(c);
	}
};

