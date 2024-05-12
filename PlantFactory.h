#include "Plant.h"
#include "Icon.h"
#include "Sunflower.h"
#include "PeaShooter.h"
#include "Walnut.h"
#include "CherryBomb.h"
#include "SeedPackets.h"



class PlantFactory
{
protected:
    SeedPackets** seedPackets = NULL;
    Texture seedTextures[7]{};  // Total number of plants
    int plantsUnlocked;


    Plant* plants[50]{};
    int numPlants;






    //int SpriteWidth;
    //int SpriteHeight;

public:
    PlantFactory(int plantsUnlocked);

    void DrawPlants(RenderWindow& window, float deltaTime);

    void spawnSunflowerAtPosition(int x, int y);

    void DeleteDeadPlants(bool FIELD_GAME_STATUS[][9]);

    void Shoot();

    void PlantClicked(Event& e, bool& shovel);

    //testing
    void spawnSunflowerRandomly(int numRows, int numCols);
    void DrawIcons(RenderWindow& window); // Draw all icons
 
    
    
    int getNumPlants() const { return numPlants; }
    Plant* const* getPlants() const { return plants; }
    //int getSpriteWidth() { return SpriteWidth; }
    //int getSpriteHeight() { return SpriteHeight; }
};
