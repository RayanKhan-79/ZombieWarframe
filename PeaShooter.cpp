#include "PeaShooter.h"

PeaShooter::PeaShooter(int x, int y, int health, int pixelsX, int pixelsY)
	: Plant (x,y,health, pixelsX, pixelsY), Pea(NULL), bulletCount(1)
{
	
	texture.loadFromFile("./Images/Peashooter.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));
	sprite.setPosition(Pos.x, Pos.y);
	Pea = new Bullet * [bulletCount] {};
}

void PeaShooter::Shoot()
{

	if (clock.getElapsedTime().asSeconds() < 0.5 || Pea[0])
		return;

	clock.restart();
	Pea[0] = new Bullet(coordinates(Pos.x + 50, Pos.y + 50), 70, "normal");
}

void PeaShooter::Draw(RenderWindow& window, float deltaTime)
{
	if (health > 0)
	{
		UpdateAnimation(deltaTime);
		window.draw(sprite);

		if (Pea[0])
		{
			if (Pea[0]->Existance())
			{
				Pea[0]->Move();
				Pea[0]->draw(window);
			}

			else
			{
				delete Pea[0];
				Pea[0] = NULL;
			}
		}
	}

}

void PeaShooter::UpdateAnimation(float deltaTime) {
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 8)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * pixelsX, 0, pixelsX, pixelsY));
}