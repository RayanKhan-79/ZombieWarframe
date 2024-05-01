#include "Zombie.h"

Zombie::Zombie(int health, int speed, int damage, int x, int y) :Pos(x, y), health(health), speed(speed), damage(damage), offset(0), Total_Animation_Time(0), switchTime(0.6)
{
	image.loadFromFile("./Images/zanimation2.png");

	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 120, 0, 120, 190));
	sprite.setPosition(Pos.x, Pos.y);
}


void Zombie::Draw(RenderWindow& window, float deltaTime)
{

	if (health > 0)
	{
		UpdateAnimation(deltaTime);
		window.draw(sprite);
	}
}

void Zombie::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset > 2)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * 120, 0, 120, 190));
}

void Zombie::Move()
{
	Pos.x -= speed;
	health -= 2;
	sprite.setPosition(Pos.x, Pos.y);
}


int Zombie::getHealth() const
{
	return health;
}

int randGrid(int Y_pixels)
{
	return (108 * (rand() % 5 - 1)) + Y_pixels;
}