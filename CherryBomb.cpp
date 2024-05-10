#include "CherryBomb.h"

CherryBomb::CherryBomb()
{

}

CherryBomb::CherryBomb(int x, int y, int health) : Plant(x, y, health)
{
    texture.loadFromFile("./Images/Cherrybomb_static.png");
    sprite.setTexture(texture);
    sprite.setPosition(Pos.x, Pos.y);

    // Start the timer with a delay of 5 seconds
    timer.restart();
}

void CherryBomb::UpdateAnimation(float deltaTime)
{
    blast(deltaTime);

}

void CherryBomb::UpdateAnimation_cherry(float deltaTime)
{
    Total_Animation_Time += deltaTime;
    if (Total_Animation_Time >= switchTime)
    {
        Total_Animation_Time -= switchTime;
        offset++;

        if (offset == 8)
            offset = 0;
             health = 0;
    }
    sprite.setTextureRect(IntRect(offset * 238, 0, 238, 180));
}

void CherryBomb::blast(float deltaTime)
{
    //cherrybomb appears for some time
    if (timer.getElapsedTime().asSeconds() >= 0.5f)
    {
       //loading blast animation
        texture.loadFromFile("./Images/Cherrybomb_blast.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(offset * 238, 0, 238, 180));
        sprite.setPosition(Pos.x, Pos.y);

        //updating
        UpdateAnimation_cherry(deltaTime);
    }
}
