#include "PlantFactory.h"

PlantFactory::PlantFactory(int plantsUnlocked) 
    : numPlants(0), 
    plantsUnlocked(plantsUnlocked) 

{
    // Initialize all textures (even locked ones)
    seedTextures[0].loadFromFile("./Images/Sunflower_i.png");  // Sunflower
    seedTextures[1].loadFromFile("./Images/Peashooter_i.png");  // Peashooter
    seedTextures[2].loadFromFile("./Images/Wallnut_i.png");  // Walnut
    seedTextures[3].loadFromFile("./Images/Cherrybomb_i.png");  // CherryBomb
    seedTextures[4].loadFromFile("./Images/Repeater_i.png");  // Repeater
    seedTextures[5].loadFromFile("./Images/Snowpea_i.png");  // Snowpea
    seedTextures[6].loadFromFile("./Images/Fumeshroom_i.png");  // fumeShroom
   
    


    seedPackets = new SeedPackets * [plantsUnlocked] {};

    for (int i = 0; i < plantsUnlocked; i++)
    {
        seedPackets[i] = new SeedPackets(coordinates(10, (85 * i) + 50), coordinates(140, (85 * i) + 130), true);
        seedPackets[i]->setTexture(seedTextures[i]);
    }
}

void PlantFactory::DrawProjectiles(RenderWindow& window)
{
   // projectiles[0]->draw(window);
    //for (int i = 0; i < 50; i++)
    //    if (projectiles[i])
    //        projectiles[i]->draw(window);
}

void PlantFactory::DeleteProjectiles()
{
    //for (int i = 0; i < 1; i++)
    //    if (projectiles[i] && projectiles[i]->Existance() == false)
    //    {
    //        delete projectiles[i];
    //        projectiles[i] = NULL;
    //    }
}

void PlantFactory::MoveProjectiles()
{

    //projectiles[0]->Move();
    //for (int i = 0; i < 50; i++)
    //    if (projectiles[i])
    //    {
    //        projectiles[i]->Move();
    //    }
}

void PlantFactory::Shoot()
{
        
    for (int i = 0; i < numPlants; i++)
        plants[i]->Shoot();
}


void PlantFactory::spawnSunflowerAtPosition(int x, int y)
{

    if (numPlants < 50) 
    {
        if (/*Peashooter type plants*/ 1)
        {
            plants[numPlants] = new PeaShooter(x, y, 100);
            
        }
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
    //if (numPlants < 10)
    //{
    //    int randomRow = rand() % numRows;
    //    int randomCol = rand() % numCols;

    //    plants[numPlants] = new Plant(randomCol * 95 + 300, randGrid(138), 300);
    //    numPlants++;
    //}
}
