#include "Zombie.h"

Zombie::Zombie(int health, int speed, int damage, int x, int y, int pixelsX, int pixelsY)
	: Pos(x, y), health(health), speed(speed), slowSpeed(speed/2), damage(damage), offset(0), Total_Animation_Time(0), switchTime(0.3), pixelsX(pixelsX), pixelsY(pixelsY),
	hitArea(x + 95, y + pixelsY), action("moving")
{


	texture.loadFromFile("./Images/zombie.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, pixelsX, pixelsY));
	sprite.setPosition(Pos.x, Pos.y);
	
}



void Zombie::Attack(Plant* plant)
{
	if (health <= 0)
		return;

	action = "attacking";
	plant->mark();
	plant->getHealth() -= damage;
	if (health <= 0 || plant->getHealth() <= 0)
	{
		action = "moving";
		return;
	}
}

void Zombie::Draw(RenderWindow& window, float deltaTime)
{

	if (health > 0)
	{
		UpdateAnimation(deltaTime);
		sprite.setPosition(Pos.x, Pos.y);
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

		if (offset == 5)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * pixelsX, 0, pixelsX, pixelsY));
}

void Zombie::Move()
{
	if (action == "attacking" || Pos.x <= 150)
		return;

	Pos.x -= speed;
	hitArea.x -= speed;
}


int& Zombie::getHealth() 
{
	return health;
}

void Zombie::getShotAt(Bullet* bullet)
{

		
	health -= bullet->getDamage();

	if (bullet->getType() == "frozen")
	{
		speed = slowSpeed;
		sprite.setColor(Color::Blue);
	}

	bullet->setCollisonStatus(true);
	
	
}

