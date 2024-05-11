#pragma once
#include "Icon.h"
class SeedPackets : public Icon  // Create a seperate file for this
{
    bool unlocked;
public:
    SeedPackets(coordinates pos, coordinates area, bool unlocked) : Icon(pos, area), unlocked(unlocked)
    {}
};

