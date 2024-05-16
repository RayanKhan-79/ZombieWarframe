#pragma once
//#include <SFML/System/Clock.hpp> 
#include "Plant.h"

class CherryBomb : public Plant
{
private:
    bool Blast;
    int offsetY;
    Clock timer; 
    coordinates BlastPoint1;
    coordinates BlastPoint2;

public:
    CherryBomb(int x, int y, int health, int pixelsX = 140, int pixlesY = 140);
    void UpdateAnimation(float deltaTime);
    void blast(float deltaTime);
    coordinates getBlastPoint1() { return BlastPoint1; }
    coordinates getBlastPoint2() { return BlastPoint2; }
    bool getStatus() const { return Blast; }
};
