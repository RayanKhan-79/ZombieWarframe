#pragma once
#include "Plant.h"
#include "Sun.h"

class Sunflower :public Plant
{
private:
	float interval;
	Sun* sun;
	Clock clock;
	
	
public:
	Sunflower(int x, int y, int health, int interval = 6, int pixelsX = 105, int pixelsY = 140);
	void UpdateAnimation(float deltaTime);
	void genSun();
	bool Update(Event& e);
	virtual void Draw(RenderWindow& window, float deltaTime);

};

