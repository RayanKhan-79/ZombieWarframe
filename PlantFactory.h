#include "Plant.h"
#include "Icon.h"



class SeedPackets : public Icon  // Create a seperate file for this
{
    bool unlocked;
public:
    SeedPackets(coordinates pos, coordinates area, bool unlocked) : Icon(pos,area), unlocked(unlocked)
    {}
};

class PlantFactory
{
protected:
    SeedPackets** seedPackets = NULL;
    Texture seedTextures[7]{};  // Total number of plants
    int plantsUnlocked;
    Plant* plants[50]{};
    int numPlants;
    int SpriteWidth;
    int SpriteHeight;
public:

    PlantFactory(int plantsUnlocked);

    void DrawPlants(RenderWindow& window, float deltaTime);

    void spawnSunflowerRandomly(int numRows, int numCols);
    void DrawIcons(); // Draw all icons
    void spawnSunflowerRandomly(int numRows, int numCols);

    int getNumPlants() const { return numPlants; }
    Plant* const* getPlants() const { return plants; }
    int getSpriteWidth() { return SpriteWidth; }
    int getSpriteHeight() { return SpriteHeight; }
    void DrawIcons(RenderWindow& window); // Draw all icons

    //testing
    void spawnSunflowerAtPosition(int x, int y);
};
