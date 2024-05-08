#include "PlantFactory.h"
PlantFactory::PlantFactory() : numPlants(0) {}

void PlantFactory::spawnSunflowerRandomly(int numRows, int numCols)
{
    if (numPlants < 20) 
    {
        int randomRow = rand() % numRows; 
        int randomCol = rand() % numCols; 
        
        plants[numPlants] = new Plant(randomCol * 95 + 300, randGrid(138), 1000);
        numPlants++;
    }
}

void PlantFactory::DrawPlants(RenderWindow& window, float deltaTime)
{
    for (int i = 0; i < numPlants; ++i)
    {
        plants[i]->Draw(window, deltaTime);
    }
}
