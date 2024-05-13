#include "PlantFactory.h"

PlantFactory::PlantFactory(int plantsUnlocked) 
    : numPlants(0), 
    plantsUnlocked(plantsUnlocked),
    seedPackets(NULL),
    cherryBomb(NULL),
    wallnutCount(0)
    
    

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

void PlantFactory::RollWallNuts()
{
    for (int i = 0; i < wallnutCount; i++)
        if (wallnuts[i] && wallnuts[i]->getHealth() > 0)
        {
            wallnuts[i]->RolyPoly();
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

    for (int i = 0; i < 5; i++)
        if (wallnuts && wallnuts[i] && wallnuts[i]->getHealth() <= 0)
        {
            // wont update field game status
            wallnutCount--;
            delete wallnuts[i];
            wallnuts[i] = NULL;
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

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5-1; j++)
            if (wallnuts[j] == NULL && wallnuts[j + 1] != NULL)
            {
                Walnut* temp = wallnuts[j + 1];
                wallnuts[j + 1] = wallnuts[j];
                wallnuts[j] = temp;
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

//
//void PlantFactory::spawnSunflowerAtPosition(int x, int y)
//{
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
#include <SFML/Audio.hpp>

bool PlantFactory::spawnSunflowerAtPosition(int x, int y, int check, ScoreBoard& scoreboard)
{
    // Load the sound file
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("./Audio/Plantsound.mp3")) {
        std::cout << "Loading error of plant spawn audio" << std::endl;
        return false;
    }

    // Create a sound instance
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100.0f);

    switch (check)
    {
    case 0:
        return false;

    case 1:
        if (scoreboard.getSun() >= 100)
        {
            scoreboard.setSun(scoreboard.getSun() - 100);
            std::cout << "Sunflower " << std::endl;
            plants[numPlants] = new Sunflower(x, y, 100);
            numPlants++;
        }
        else
        {
            return false;
        }
        break;
    case 2:
        if (scoreboard.getSun() >= 100)
        {
            scoreboard.setSun(scoreboard.getSun() - 100);
            std::cout << "PeaShooter " << std::endl;
            plants[numPlants] = new PeaShooter(x, y, 100);
            numPlants++;
        }
        else
        {
            return false;
        }
        break;
    case 3:
        if (scoreboard.getSun() >= 50)
        {
            scoreboard.setSun(scoreboard.getSun() - 50);
            std::cout << "Walnut " << std::endl;
            wallnuts[wallnutCount] = new Walnut(x, y, 900);
            wallnutCount++;
            return false;
        }
        else
        {
            return false;
        }
        break;
    case 4:
        if (scoreboard.getSun() >= 150)
        {
            scoreboard.setSun(scoreboard.getSun() - 150);
            std::cout << "Cherrybomb " << std::endl;
            cherryBomb = new CherryBomb(x, y, 100);
        }
        else
        {
            return false;
        }
        break;
    case 5:
        if (scoreboard.getSun() >= 200)
        {
            scoreboard.setSun(scoreboard.getSun() - 200);
            std::cout << "Repeater " << std::endl;
            plants[numPlants] = new Repeater(x, y, 100);
            numPlants++;
        }
        else
        {
            return false;
        }
        break;
    case 6:
        if (scoreboard.getSun() >= 175)
        {
            scoreboard.setSun(scoreboard.getSun() - 175);
            std::cout << "Snowpea " << std::endl;
            plants[numPlants] = new SnowPea(x, y, 100);
            numPlants++;
        }
        else
        {
            return false;
        }
        break;
    case 7:
        if (scoreboard.getSun() >= 75)
        {
            scoreboard.setSun(scoreboard.getSun() - 75);
            std::cout << "FumeShroom " << std::endl;
            plants[numPlants] = new FumeShroom(x, y, 100);
            numPlants++;
        }
        else
        {
            return false;
        }
        break;
    default:
        return false;
    }
    return true;
    

    while (sound.getStatus() == sf::Sound::Playing) {
        // Optional: You can add a delay here if needed
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

    if (cherryBomb)
        cherryBomb->Draw(window,deltaTime);

    for (int i = 0; i < wallnutCount; i++)
        if (wallnuts[i])
            wallnuts[i]->Draw(window, deltaTime);
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
