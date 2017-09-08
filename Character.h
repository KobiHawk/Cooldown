#pragma once
#include <SDL.h>
#include "Structs.h"

class Character
{
public:
	Character();
	~Character();
	SDL_Rect getPosition();
	Velocity getVelocity();
	void setPosition(int x, int y, int w, int h);
	void setVelocity(float velocityX, float velocityY);

	void move(int x, int y);
	void roll();
	void fire(Position target);

private:



	const float MAX_VELOCITY = 5;
	const float SPEED = 0.5f;
	const int DASH_DURATION = 20;

	//position
	int x;
	int y;
	int w;
	int h;

	//velocity
	Velocity velocity;

	int rollTicksRemaining;
};



