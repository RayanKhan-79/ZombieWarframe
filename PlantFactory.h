#include "Plant.h"
#include "Icon.h"



class SeedPackets : public Icon  // Create a seperate file for this
{
    bool unlocked;
public:
    SeedPackets(coordinates pos, bool unlocked) : Icon(pos), unlocked(unlocked)
    {}
};

class PlantFactory
{
protected:
    SeedPackets** seedPackets = NULL;
    Texture seedTextures[7]{};  // Total number of plants
    int plantsUnlocked;
    Plant* plants[10]{};
    int numPlants;
public:
    PlantFactory();
    void DrawPlants(RenderWindow& window, float deltaTime);
    void DrawIcons(RenderWindow& window); // Draw all icons

    //testing
    void spawnSunflowerAtPosition(int x, int y);
};
