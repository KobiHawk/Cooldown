#pragma once
#include "Structs.h"
#include <SDL.h>
class Projectile
{
public:
	Projectile();
	Projectile::Projectile(Position newPosition, Velocity newVelocity);
	~Projectile();

	SDL_Rect getSDL_Rect();
	Velocity getVelocity();
	int getSpriteSize() { return SPRITE_SIZE; }
	void setSDL_Rect(SDL_Rect location);
	void setVelocity(Velocity velocity);
	void move();

private:
	const float SPEED = 3.5f;

	Velocity velocity;
	SDL_Rect location;
	const int SPRITE_SIZE = 4;

};

