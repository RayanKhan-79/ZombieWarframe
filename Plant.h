#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"

using namespace sf;
class Plant
{
protected:
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
	coordinates getPosition() { return Pos; }
	int& getHealth() { return health; }
	void mark() 
	{
		Color c(255, 0, 0);
		sprite.setColor(c);
	}
};

