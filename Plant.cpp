#include "Plant.h"
Plant::Plant(int x, int y, int health, int pixelsX, int pixelsY)
	: Pos(x, y), health(health), offset(0), Total_Animation_Time(0),
	switchTime(0.2), mid(x + (pixelsX / 2), y + (pixelsY / 2)), pixelsX(pixelsX), pixelsY(pixelsY) {}


bool Plant::isClicked(Event& e)
{
	if (e.type != Event::MouseButtonReleased)
		return false;

	if (e.mouseButton.x > Pos.x && e.mouseButton.x < Pos.x + 95 && e.mouseButton.y > Pos.y && e.mouseButton.y < Pos.y + 118)
	{
		return true;
	}

	return false;
}

void Plant::Draw(RenderWindow& window, float deltaTime)
{
	if (health > 0)
	{
		UpdateAnimation(deltaTime);
		window.draw(sprite);
	}
}

void Plant::UpdateAnimation(float deltaTime)
{
	Total_Animation_Time += deltaTime;
	if (Total_Animation_Time >= switchTime)
	{
		Total_Animation_Time -= switchTime;
		offset++;

		if (offset == 8)
			offset = 0;
	}
	sprite.setTextureRect(IntRect(offset * 105, 0, 105, 140));
}
void Plant::mark()
{
	Color c(255, 0, 0);
	sprite.setColor(c);
}

int Plant::getBulletCount()
{
	return 0;
}

Bullet** Plant::getBullet()
{
	Bullet* ignore = NULL;
	Bullet** ignore2 = &ignore;

	return ignore2;
}