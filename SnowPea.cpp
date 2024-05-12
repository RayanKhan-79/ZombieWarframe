#include "SnowPea.h"
SnowPea::SnowPea(int x, int y, int health, int pixelsX, int pixelsY) 
	: PeaShooter(x, y, health, pixelsX, pixelsY)
{
	texture.loadFromFile("./Images/Snowpea.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 131, 0, 131, 135));
	sprite.setPosition(Pos.x, Pos.y);
	Pea = new Bullet * [bulletCount] {};
}
void SnowPea::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 8)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * 131, 0, 131, 135));
}

void SnowPea::Shoot()
{
	if (clock.getElapsedTime().asSeconds() < 0.5 || Pea[0])
		return;

	clock.restart();
	Pea[0] = new Bullet(coordinates(Pos.x + 50, Pos.y + 50), 70, "frozen");
}