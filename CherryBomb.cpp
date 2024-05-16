#include "CherryBomb.h"

CherryBomb::CherryBomb(int x, int y, int health, int pixelsX, int pixlesY) 
    : Plant(x, y, health, pixelsX, pixlesY),
    BlastPoint1(Pos.x - 95, Pos.y - 118*2 + pixlesY),
    BlastPoint2(Pos.x + 95*2, Pos.y + 118 + pixlesY),
    Blast(false),
    offsetY(0)
{
    switchTime = 0.05;
    mid.x = Pos.x;
    mid.y = Pos.y + 70;

    texture.loadFromFile("./Images/Cherrybomb_static.png");
    sprite.setTexture(texture);
    sprite.setPosition(Pos.x, Pos.y);

    // Start the timer with a delay of 5 seconds
    timer.restart();
}

void CherryBomb::UpdateAnimation(float deltaTime)
{
    if (!Blast)
        return;

    Total_Animation_Time += deltaTime;
    if (Total_Animation_Time >= switchTime)
    {
        Total_Animation_Time -= switchTime;
        offset++;

        if (offset == 6)
        {
            offset = 0;
            offsetY++;
            
            if (offsetY == 2)
                health = 0;
        }
    }
    sprite.setTextureRect(IntRect(offset * 200, offsetY * 200, 200, 200));
}

void CherryBomb::blast(float deltaTime)
{
    //cherrybomb appears for some time
    if (timer.getElapsedTime().asSeconds() >= 0.5f)
    {
       //loading blast animation
        Blast = true;
        texture.loadFromFile("./Images/xplosions/r01.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(offset * 200, offsetY * 200, 200, 200));
        sprite.setPosition(Pos.x, Pos.y);
        sprite.setOrigin(pixelsX / 2, pixelsY / 2);
        sprite.setScale(2, 2);


    }
}
