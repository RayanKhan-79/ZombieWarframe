#pragma once
#include"Icon.h"
#include"ZombieFactory.h"
#include"PlantFactory.h"
#include"PauseMenu.h"
class Levels
{

protected:

	Icon pauseIcon;
	Texture background_Texture;
	Sprite background_Sprite;
	PauseMenu pauseMenu;
	//Music backGroundMusic

	ZombieFactory zf;
	PlantFactory pf;

public:
	Levels() 
		: pauseIcon(coordinates(1030, 10)), pauseMenu(coordinates(325,50))
	{
		Texture texture;
		texture.loadFromFile("./Images/test2.png");
		pauseIcon.setTexture(texture);
	}

	void collisionDetection()
	{
		for (int i = 0; i < zf.getNumberOfZombies(); i++)
			for (int j = 0; j < pf.getNumPlants(); j++)
			{
				if (approxMatch(zf.getZombies()[i]->getHitArea(), pf.getPlants()[j]->getPosition()))
				{
					//pf.getPlants()[j]->mark();
					zf.getZombies()[i]->action = "attacking";
					zf.getZombies()[i]->Attack(pf.getPlants()[j]);

					std::cout << pf.getPlants()[j]->getHealth() << '\n';
					//////std::cout << "px: " << zf.getZombies()[i]->getPosition().x << "  hx: " << zf.getZombies()[i]->getHitArea().x << '\n';
					//////std::cout << "py: " << zf.getZombies()[i]->getPosition().y + 180 - 118 << "  hy: " << zf.getZombies()[i]->getHitArea().y << '\n';
					//////std::cout << "Plant:\n";
					//////std::cout << "px: " << pf.getPlants()[i]->getPosition().x << "  hx: " << pf.getPlants()[i]->getPosition().x + 95 << '\n';
					//////std::cout << "py: " << pf.getPlants()[i]->getPosition().y + 145 - 118 << "  hy: " << pf.getPlants()[i]->getPosition().y + 145 << '\n';
					//system("pause");
				}
				//if (zf.getZombies()[i]->getPosition().x >= pf.getPlants()[j]->getPosition().x)
				if (zf.getZombies()[i]->name == "dancer")
				{
					Zombie* danc = zf.getZombies()[i];
					for (int k = 0; k < 4; k++)
					{
						
					}
				}
			}
	}

	virtual void createBack(RenderWindow& window) = 0;
	void start();

};

