#include "Plant.h"
class PlantFactory
{
protected:
    Plant* plants[10]; 
    int numPlants;
public:
    PlantFactory();
    void DrawPlants(RenderWindow& window, float deltaTime);
    void spawnSunflowerRandomly(int numRows, int numCols);
};
