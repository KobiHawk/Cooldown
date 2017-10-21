#pragma once
#include <SDL.h>
#include "Structs.h"
#include "Projectile.h"
#include "Hitbox.h"

class Character
{
public:
	Character();
	~Character();
	Character::Character(int x, int y, int w, int h);
	SDL_Rect getSDL_Rect() { return location; }
	Velocity getVelocity();
	Position getCenter();
	void setPosition(int x, int y, int w, int h);
	void setVelocity(float velocityX, float velocityY);

	void move(int x, int y);
	void roll();
	Projectile fire(Position target);

protected:
	const float MAX_VELOCITY = 5;
	const float SPEED = 0.5f;
	const int DASH_DURATION = 20;

	//position
	SDL_Rect location;

	//velocity
	Velocity velocity;

	int rollTicksRemaining;
};



