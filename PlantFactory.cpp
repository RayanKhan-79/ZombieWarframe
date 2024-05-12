#include "PlantFactory.h"

PlantFactory::PlantFactory(int plantsUnlocked) : numPlants(0) , plantsUnlocked(plantsUnlocked)
{
    // Initialize all textures (even locked ones)
    seedTextures[0].loadFromFile("./Images/Sunflower_i.png");  // Sunflower
    seedTextures[1].loadFromFile("./Images/Peashooter_i.png");  // Peashooter
    seedTextures[2].loadFromFile("./Images/Wallnut_i.png");  // Walnut
    seedTextures[3].loadFromFile("./Images/Cherrybomb_i.png");  // CherryBomb
    seedTextures[4].loadFromFile("./Images/Repeater_i.png");  // Repeater
    seedTextures[5].loadFromFile("./Images/Snowpea_i.png");  // Snowpea
    seedTextures[6].loadFromFile("./Images/Fumeshroom_i.png");  // fumeShroom
   

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
int PlantFactory::Clicked(Event& event)
{
    std::cout << "I am in click" << std::endl;
        
    for (int i = 0; i < plantsUnlocked; i++)
        if (seedPackets[i]->isClicked(event))
            return (i + 1);

    return 0;

    //if (seedPackets[0]->isClicked(event))
    //{
    //    return 1;
    //}
    //else if (seedPackets[1]->isClicked(event))
    //{
    //    return 2;
    //}
    //else if (seedPackets[2]->isClicked(event))
    //{
    //    return 3;
    //}
    //else if (seedPackets[3]->isClicked(event))
    //{
    //    return 4;
    //}
    //else if (seedPackets[4]->isClicked(event))
    //{
    //    return 5;
    //}
    //else if (seedPackets[5]->isClicked(event))
    //{
    //    return 6;
    //}
    //else if (seedPackets[6]->isClicked(event))
    //{
    //    return 7;
    //}
    

}
void PlantFactory::spawnSunflowerAtPosition(int x, int y, int check)
{
    
    switch (check)
    {
    case 0:
        selected = false;
        return;

    case 1:
        std::cout << "Sunflower " << std::endl;
        plants[numPlants] = new Sunflower(x, y, 100);
        break;
    case 2:
        std::cout << "PeaShooter " << std::endl;
        plants[numPlants] = new PeaShooter(x, y, 100);
        break;
    case 3:
        std::cout << "Walnut " << std::endl;
        plants[numPlants] = new Walnut(x, y, 100);
        break;
    case 4:
        std::cout << "Cherrybomb " << std::endl;
        plants[numPlants] = new CherryBomb(x, y, 100);
        break;
    case 5:
        std::cout << "Repeater " << std::endl;
        plants[numPlants] = new Repeater(x, y, 100);
        break;
    case 6:
        std::cout << "Snowpea " << std::endl;
        plants[numPlants] = new SnowPea(x, y, 100);
        break;
    case 7:
        std::cout << "FumeShroom " << std::endl;
        plants[numPlants] = new FumeShroom(x, y, 100);
        break;
    default:
        break;
    }
    numPlants++;
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
