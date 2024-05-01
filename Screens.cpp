#include"Screens.h"

Screens::Screens() : pos(0,0) {};

RenderWindow& Screens::getWindow()
{
	return window;
}