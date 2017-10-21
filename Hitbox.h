#pragma once
#include <SDL.h>
#include <stdio.h>

//Abstract class Hitbox
//Used in HitboxManager to check all objects that projectiles can collide with
class Hitbox
{
public:
	Hitbox();
	~Hitbox();

	SDL_Rect getSDL_Rect()
	{
		SDL_Rect result = { 0,0,0,0 };
		printf("Error: Called getSDL_Rect of a Hitbox");
		return result;
	}
};

