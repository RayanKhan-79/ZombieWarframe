#include "Plant.h"
#include "Icon.h"
#include "Sunflower.h"
#include "PeaShooter.h"
#include "Walnut.h"
#include "CherryBomb.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "FumeShroom.h"
#include "SeedPackets.h"
#include "ScoreBoard.h"
#include <SFML/Audio.hpp>

class PlantFactory
{
protected:
    SeedPackets** seedPackets;
    Texture seedTextures[7]{};  // Total number of plants
    int plantsUnlocked;

    CherryBomb* cherryBomb;
    
    Walnut* wallnuts[5]{};
    int wallnutCount;

    Plant* plants[50]{};
    int numPlants;
public:
    bool selected = false;

    PlantFactory(int plantsUnlocked);
    
    int Clicked(Event& event);

    void genSuns_Sunflower();

    void UpdateSuns(ScoreBoard&, Event&);

    //void SelectPlants(int x);

    void DrawPlants(RenderWindow& window, float deltaTime);

    void DeleteDeadPlants(bool FIELD_GAME_STATUS[][9]);

    void RollWallNuts();

    void Shoot();

    void PlantClicked(Event& e, bool& shovel);

    bool spawnSunflowerAtPosition(int x, int y, int check, ScoreBoard& scoreboard);
    //testing
    //void spawnSunflowerRandomly(int numRows, int numCols);
    void DrawIcons(RenderWindow& window); // Draw all icons
 
    
    int getWallnutCount() const { return wallnutCount; }
    Walnut* const* getWallnuts() { return wallnuts; }
    int getNumPlants() const { return numPlants; }
    Plant* const* getPlants() const { return plants; }
    CherryBomb* getCherryBomb() { return cherryBomb; }

    //testing
    bool spawnSunflowerAtPosition(int x, int y, int check, ScoreBoard& scoreboard);
};
