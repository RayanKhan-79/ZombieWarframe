#include "CherryBomb.h"

CherryBomb::CherryBomb(int x, int y, int health, int pixelsX, int pixlesY) 
    : Plant(x, y, health, pixelsX, pixlesY),
    BlastPoint1(Pos.x - 95, Pos.y - 118*2 + pixlesY),
    BlastPoint2(Pos.x + 95*2, Pos.y + 118 + pixlesY)
{

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
        {
            offset = 0;
            health = 0;
            std::cout << "Blast --> " << BlastPoint1.x << ' ' << BlastPoint2.x << "\n" << BlastPoint1.y << ' ' << BlastPoint2.y << "\n";
        }
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
