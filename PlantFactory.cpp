#include "PlantFactory.h"

PlantFactory::PlantFactory(int plantsUnlocked) : numPlants(0) , plantsUnlocked(plantsUnlocked)
{
    // Initialize all textures (even locked ones)
    seedTextures[0].loadFromFile("./Images/Sunflower_SD.png");  // Sunflower
    seedTextures[1].loadFromFile("./Images/Peashooter_SD.png");  // Peashooter
    seedTextures[2].loadFromFile("./Images/Walnut_SD.png");  // Walnut
    seedTextures[3].loadFromFile("./Images/Cherrybomb_SD.png");  // CherryBomb
    seedTextures[4].loadFromFile("./Images/Repeater_SD.png");  // Repeater
    seedTextures[5].loadFromFile("./Images/Snowpea_SD.png");  // Snowpea
    seedTextures[6].loadFromFile("./Images/Fumeshroom_SD.png");  // fumeShroom
   

    //seedPackets = new SeedPackets * [plantsUnlocked] {};

    //for (int i = 0; i < plantsUnlocked; i++)
    //{
    //    seedPackets[i] = new SeedPackets(coordinates(10, (83 * i) + 83), true);
    //    seedPackets[i]->setTexture(seedTextures[i]);
    //}



    seedPackets = new SeedPackets * [plantsUnlocked] {};

    for (int i = 0; i < plantsUnlocked; i++)
    {
        seedPackets[i] = new SeedPackets(coordinates(10, (85 * i) + 50), coordinates(140, (85 * i) + 130), true);
        seedPackets[i]->setTexture(seedTextures[i]);
    }
}
void PlantFactory::spawnSunflowerAtPosition(int x, int y)
{
    if (numPlants < 50) {
        plants[numPlants] = new Sunflower(x, y, 100); 
        numPlants++;
    }
}
void PlantFactory::DrawIcons(RenderWindow& window)
{
    for (int i = 0; i < plantsUnlocked; ++i)
    {
        seedPackets[i]->draw(window);
    }
}
void PlantFactory::DrawPlants(RenderWindow& window, float deltaTime)
{
    for (int i = 0; i < numPlants; ++i)
    {
        plants[i]->Draw(window, deltaTime);
    }
}

void PlantFactory::spawnSunflowerRandomly(int numRows, int numCols)
{
    if (numPlants < 10)
    {
        int randomRow = rand() % numRows;
        int randomCol = rand() % numCols;

        plants[numPlants] = new Plant(randomCol * 95 + 300, randGrid(138), 300);
        numPlants++;
    }
}
