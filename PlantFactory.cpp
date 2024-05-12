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

void PlantFactory::PlantClicked(Event& e, bool& shovel)
{
    std::cout << shovel;
    for (int i = 0; i < numPlants; i++)
        if (plants[i]->isClicked(e) && shovel == true)
        {
            plants[i]->getHealth() = 0;
            shovel = false;
            return;
        }
                
}


void PlantFactory::DeleteDeadPlants(bool FIELD_GAME_STATUS[][9])
{

    if (cherryBomb && cherryBomb->getHealth() <= 0)
    {
        int COL = (cherryBomb->getHitArea().x - 300) / 95;
        int ROW = (cherryBomb->getHitArea().y - 85) / 118;

        FIELD_GAME_STATUS[ROW][COL] = 0;
        std::cout << "FGS = " << COL << ' ' << ROW << '\n';

        delete cherryBomb;
        cherryBomb = NULL;

    }

    for (int i = 0; i < 45; i++)
        if (plants[i] && plants[i]->getHealth() <= 0)
        {
            int COL = (plants[i]->getHitArea().x - 300)/95;
            int ROW = (plants[i]->getHitArea().y - 85)/118;
            
            FIELD_GAME_STATUS[ROW][COL] = 0;
            std::cout << "FGS = " << COL << ' ' << ROW << '\n';

            delete plants[i];
            plants[i] = NULL;
            numPlants--;
        }

    for (int i = 0; i < 45; i++)
        for (int j = 0; j < 45-1; j++)
            if (plants[j] == NULL && plants[j + 1] != NULL)
            {
                Plant* temp = plants[j+1];
                plants[j + 1] = plants[j];
                plants[j] = temp;
            }
}



void PlantFactory::Shoot()
{
        
    for (int i = 0; i < numPlants; i++)
        plants[i]->Shoot();
}


void PlantFactory::spawnSunflowerAtPosition(int x, int y)
{

    cherryBomb = new CherryBomb(x, y, 50);

    //if (numPlants < 50) {
    //    plants[numPlants] = new PeaShooter(x, y, 100); 
    //    numPlants++;
    //}
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

    if (cherryBomb)
        cherryBomb->Draw(window,deltaTime);
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
