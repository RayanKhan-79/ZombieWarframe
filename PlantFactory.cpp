#include "PlantFactory.h"
PlantFactory::PlantFactory() : numPlants(0) , plantsUnlocked(8)
{
    // Initialize all textures (even locked ones)
    seedTextures[0].loadFromFile("./Images/sunFlower_i.png");  // Sunflower
    seedTextures[1].loadFromFile("./Images/peaShooter_i.png");  // Peashooter
    seedTextures[2].loadFromFile("./Images/wallNut_i.png");  // whaterver is unlocked in the next level
    seedTextures[3].loadFromFile("./Images/cherryBomb_i.png");  // Peashooter
    seedTextures[4].loadFromFile("./Images/rePeater_i.png");  // Sunflower
    seedTextures[5].loadFromFile("./Images/snowPea_i.png");  // whaterver is unlocked in the next level
    seedTextures[6].loadFromFile("./Images/fumeShroom_i.png");  // Sunflower
   

    // Initialize all textures (even locked ones)
    seedTextures[0].loadFromFile("./Images/img3.png");  // Sunflower
    seedTextures[1].loadFromFile("./Images/img4.png");  // Peashooter
    seedTextures[2].loadFromFile("./Images/img5.png");  // whaterver is unlocked in the next level

    seedPackets = new SeedPackets * [plantsUnlocked] {};

    for (int i = 0; i < plantsUnlocked; i++)
    {
        seedPackets[i] = new SeedPackets(coordinates(10, (80 * i) + 80), true);
        seedPackets[i]->setTexture(seedTextures[i]);
    }



    seedPackets = new SeedPackets * [plantsUnlocked] {};

    for (int i = 0; i < plantsUnlocked; i++)
    {
        seedPackets[i] = new SeedPackets(coordinates(10, (85 * i) + 50), true);
        seedPackets[i]->setTexture(seedTextures[i]);
    }
}
void PlantFactory::spawnSunflowerAtPosition(int x, int y)
{
    if (numPlants < 10) {
        plants[numPlants] = new Plant(x, y, 100); 
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
