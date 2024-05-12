#include "Plant.h"
#include "Icon.h"
#include "Sunflower.h"
#include "PeaShooter.h"
#include "Walnut.h"
#include "CherryBomb.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "FumeShroom.h"
#include "SeedPackets.h"



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
    bool selected = false;

    PlantFactory(int plantsUnlocked);
    int Clicked(Event& event);
    void SelectPlants(int x);
    void DrawPlants(RenderWindow& window, float deltaTime);

    void spawnSunflowerRandomly(int numRows, int numCols);
    //void DrawIcons(); // Draw all icons

    int getNumPlants() const { return numPlants; }
    Plant* const* getPlants() const { return plants; }
    int getSpriteWidth() { return SpriteWidth; }
    int getSpriteHeight() { return SpriteHeight; }
    void DrawIcons(RenderWindow& window); // Draw all icons

    //testing
    void spawnSunflowerAtPosition(int x, int y, int check);
};
