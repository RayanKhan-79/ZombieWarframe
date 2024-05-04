#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include"Game.h"

using namespace sf;
using namespace std;


int main()
{
	//MainMenuScreen MMS;
	//MMS.render();

	Game PlantsVsZombeis;
	PlantsVsZombeis.playGame();
	return 0;
}
