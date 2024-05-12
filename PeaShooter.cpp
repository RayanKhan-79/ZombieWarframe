#include "PeaShooter.h"
PeaShooter::PeaShooter()
{

}
PeaShooter::PeaShooter(int x, int y, int health) :ShootingPlants (x,y,health)
{
	texture.loadFromFile("./Images/Peashooter.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 111, 0, 111, 135));
	sprite.setPosition(Pos.x, Pos.y);
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
	sprite.setTextureRect(IntRect(offset * 111, 0, 111, 135));
}