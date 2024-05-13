#include "Sunflower.h"

Sunflower::Sunflower(int x, int y, int health, int interval, int pixelsX, int pixelsY) 
	: Plant(x,y,health,pixelsX,pixelsY), interval(interval), sun(NULL)
{

	texture.loadFromFile("./Images/Sunflower.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));
	sprite.setPosition(Pos.x, Pos.y);
}
void Sunflower::UpdateAnimation(float deltaTime) {
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 6)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * pixelsX, 0, pixelsX, pixelsY));
}

void Sunflower::genSun()
{
	if (clock.getElapsedTime().asSeconds() < interval)
		return;

	if (sun)
		return;

	sun = new Sun(coordinates(mid.x, Pos.y));
	//clock.restart();
}

bool Sunflower::Update(Event& e)
{
	if (sun && sun->isClicked(e))
	{
		delete sun;
		sun = NULL;
		clock.restart();
		return true;
	}

	return false;
}

void Sunflower::Draw(RenderWindow& window, float deltaTime)
{
	if (health > 0)
	{
		UpdateAnimation(deltaTime);
		window.draw(sprite);
	}

	if (sun)
	{
		sun->draw(window);
	}

}
















