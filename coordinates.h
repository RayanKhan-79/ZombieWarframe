#pragma once
#include<iostream>

struct coordinates 
{

	int x;
	int y;
	coordinates(int = 0, int = 0); 

};
bool approxMatch(const coordinates&, const coordinates&);
bool LargeAreaMatch(const coordinates&, const coordinates&, const coordinates&);
int randGrid(int);
	
