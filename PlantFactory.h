#include "Plant.h"
#include "Icon.h"

class PlantFactory
{
protected:
    Icon** seedPackets;
    int plantsUnlocked;
    Plant* plants[10]; 
    int numPlants;
public:
    PlantFactory();
    void DrawPlants(RenderWindow& window, float deltaTime);
    void DrawIcons();
    void spawnSunflowerRandomly(int numRows, int numCols);
};
