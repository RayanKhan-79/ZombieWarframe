#pragma once
#include "Sun.h"
#include <SFML/Audio.hpp>
class GenSun
{
private:

	float interval;
	Sun* sun;
	Clock clock;

public:

	GenSun(float interval = 1);
	void spawnSun();
	void moveSun(RenderWindow& window);
	bool Update(Event& e);
};

