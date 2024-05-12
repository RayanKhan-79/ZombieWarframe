#include "Repeater.h"


Repeater::Repeater(int x, int y, int health, int pixelsX, int pixelsY)
	: PeaShooter(x, y, health, pixelsX, pixelsY)
{
	bulletCount = 2;
	texture.loadFromFile("./Images/Repeater.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 139, 0, 139, 135));
	sprite.setPosition(Pos.x, Pos.y);

	Pea = new Bullet * [bulletCount] {};
}

void Repeater::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 5)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * 139, 0, 139, 135));
}

void Repeater::Shoot()
{
	if (clock.getElapsedTime().asSeconds() < 0.5 || Pea[0] || Pea[1])
		return;

	clock.restart();
	Pea[0] = new Bullet(coordinates(Pos.x + 40, Pos.y + 50), 70, "normal");
	Pea[1] = new Bullet(coordinates(Pos.x + 70, Pos.y + 50), 70, "normal");
}

void Repeater::Draw(RenderWindow& window, float deltaTime)
{
	if (health > 0)
	{
		UpdateAnimation(deltaTime);
		window.draw(sprite);

		for (int i = 0; i < 2; i++)
		{
			if (Pea[i])
			{
				if (Pea[i]->Existance())
				{
					Pea[i]->Move();
					Pea[i]->draw(window);
				}

				else
				{
					delete Pea[i];
					Pea[i] = NULL;
				}
			}
		}
	}

}
