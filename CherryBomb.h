#pragma once
#include <SFML/System/Clock.hpp> 
#include "Plant.h"

class CherryBomb : public Plant
{
private:
    sf::Clock timer; 

public:
    CherryBomb();
    CherryBomb(int x, int y, int health);
    void UpdateAnimation(float deltaTime);
    void UpdateAnimation_cherry(float deltaTime);
    void blast(float deltaTime);
};
