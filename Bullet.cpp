#include "Bullet.h"

Bullet::Bullet(coordinates pos, int damage, std::string type) : pos(pos), collided(false), damage(damage), type(type)
{
	texture.loadFromFile("./Images/Pea.png");
	bullet.setTexture(texture);
	
	if (type == "frozen")
	{
		bullet.setColor(sf::Color(0, 0, 255));
	}
	//sf::Color c(255, 0, 0);
	//bullet.setFillColor(c);
	//bullet.setRadius(5);
	bullet.setPosition(pos.x, pos.y);
}

void Bullet::Move()
{
	if (clock.getElapsedTime().asSeconds() < 0.001)
		return;

	clock.restart();
	pos.x += 20.f;
}

void Bullet::draw(sf::RenderWindow& window)
{
	bullet.setPosition(pos.x, pos.y);
	window.draw(bullet);

}

bool Bullet::Existance()
{
	if (collided || pos.x >= 1200)
		return false;

	return true;
}

coordinates& Bullet::getCoordinates()
{
	return pos;
}

void Bullet::setCollisonStatus(bool boolean)
{
	collided = boolean;
}

int Bullet::getDamage()
{
	return damage;
}

std::string Bullet::getType()
{
	return type;
}