#include "PeaShooter.h"

PeaShooter::PeaShooter(int x, int y, int health) 
	: ShootingPlants (x,y,health)
{
	
	texture.loadFromFile("./Images/Peashooter.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 115, 0, 115, 135));
	sprite.setPosition(Pos.x, Pos.y);
}

void PeaShooter::Shoot()
{

	if (clock.getElapsedTime().asSeconds() < 0.5 || Pea)
		return;

	clock.restart();
	Pea = new Bullet(coordinates(Pos.x + 50, Pos.y + 50));
}

void PeaShooter::Draw(RenderWindow& window, float deltaTime)
{
	if (health > 0)
	{
		UpdateAnimation(deltaTime);
		window.draw(sprite);

		if (Pea)
		{
			if (Pea->Existance())
			{
				Pea->Move();
				Pea->draw(window);
			}

			else
			{
				delete Pea;
				Pea = NULL;
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
	sprite.setTextureRect(IntRect(offset * 115, 0, 115, 135));
}