#include "coordinates.h"

coordinates::coordinates(int x, int y) : x(x), y(y) {}

bool approxMatch(const coordinates& hit_1, const coordinates& pos_2)
{
	//if (pos_2.x >= pos_1.x && pos_2.x <= hit_1.x && (pos_2.y+145-118) >= (pos_1.y+180-118) && (pos_2.y+145-118) <= hit_1.y)
	//	return true;

	if 
	(
		pos_2.x >= hit_1.x - 95 &&
		pos_2.x <= hit_1.x &&
		pos_2.y >= hit_1.y - 118 &&
		pos_2.y <= hit_1.y
	)
	{
		return true;
	}

	return false;
}

bool LargeAreaMatch(const coordinates& p1, const coordinates& p2, const coordinates& zombie)
{
	
	if
	(
			zombie.x - 47 >= p1.x &&
			zombie.x - 47 <= p2.x &&
			zombie.y - 60 >= p1.y &&
			zombie.y - 60 <= p2.y
	)
	{
		return true;
	}

	return false;
		
}

int randGrid(int Y_pixels)
{
	return (118 * (rand() % 4 + 1)) + 85 - Y_pixels;
}