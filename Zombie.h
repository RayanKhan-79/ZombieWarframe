#pragma once
#include<SFML/Graphics.hpp>
#include"coordinates.h"
#include"Bullet.h"
#include"Plant.h"

using namespace sf;



class Zombie
{
protected:
	int health;
	int speed;
	int slowSpeed;
	int damage;
	bool reachedHome = false;
	
	float Total_Animation_Time;
	float switchTime;
	int offset;
	int pixelsX;
	int pixelsY;
	
	Texture texture;
	Sprite sprite;
	coordinates Pos;
	coordinates hitArea;
	std::string action;


public:
	Zombie(int=200, int=2, int=5, int=1000, int=randGrid(180), int=180, int=180);
	virtual void Draw(RenderWindow&, float);
	virtual void Move();
	virtual void UpdateAnimation(float interval);
	virtual void Attack(Plant*);

	void getShotAt(Bullet*);

	// Getters & Setters
	int& getHealth();
	coordinates getPosition() const { return Pos; }
	coordinates getHitArea() const { return hitArea; }
	bool getReachedHomeStatus() const { return reachedHome; }
	void setReachedHomeStatus(bool boolean) { reachedHome = boolean; }
	void mark();
};

