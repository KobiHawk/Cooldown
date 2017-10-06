#pragma once
#include "Structs.h"
#include <SDL.h>
class Projectile
{
public:
	Projectile();
	~Projectile();

	SDL_Rect getSDL_Rect();
	Velocity getVelocity();
	void setSDL_Rect(SDL_Rect location);
	void setVelocity(Velocity velocity);
	void move();

private:
	Velocity velocity;
	SDL_Rect location;
	const int SPRITE_SIZE = 4;

};

