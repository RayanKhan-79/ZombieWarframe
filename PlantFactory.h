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
    Plant* plants[20]; 
    int numPlants;
public:
    PlantFactory();
    //void InitializeIcons()  // Move to PlantFactory Constructor later
    //{
    //    // Initialize all textures (even locked ones)
    //    seedTextures[0].loadFromFile("./Images/img3.png");  // Sunflower
    //    seedTextures[1].loadFromFile("./Images/img4.png");  // Peashooter
    //    seedTextures[2].loadFromFile("./Images/img5.png");  // whaterver is unlocked in the next level

    //    seedPackets = new SeedPackets * [plantsUnlocked] {};

    //    for (int i = 0; i < plantsUnlocked; i++)
    //    {
    //        seedPackets[i] = new SeedPackets(coordinates(10, (80 * i) + 80), true);
    //        seedPackets[i]->setTexture(seedTextures[0]);
    //    }


    //}
    void DrawPlants(RenderWindow& window, float deltaTime);
    void DrawIcons(); // Draw all icons
    void spawnSunflowerRandomly(int numRows, int numCols);

    int getNumPlants() const { return numPlants; }
    Plant* const* getPlants() const { return plants; }
};
