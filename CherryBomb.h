#pragma once
#include <SFML/System/Clock.hpp> 
#include "Plant.h"

class CherryBomb : public Plant
{
private:
    sf::Clock timer; 
    coordinates BlastPoint1;
    coordinates BlastPoint2;

public:
    CherryBomb() { }
    CherryBomb(int x, int y, int health, int pixelsX = 140, int pixlesY = 140);
    void UpdateAnimation(float deltaTime);
    void UpdateAnimation_cherry(float deltaTime);
    void blast(float deltaTime);
    coordinates getBlastPoint1() { return BlastPoint1; }
    coordinates getBlastPoint2() { return BlastPoint2; }
};
