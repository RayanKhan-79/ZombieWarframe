#include "PeaShooter.h"
PeaShooter::PeaShooter()
{

}
PeaShooter::PeaShooter(int x, int y, int health) :Plant (x,y,health)
{
	texture.loadFromFile("./Images/Peashooter.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(offset * 121, 0, 121, 138));
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
	sprite.setTextureRect(IntRect(offset * 117, 0, 117, 138));
}