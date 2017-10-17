#pragma once
#include "Character.h"
#include <stdio.h>

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();

	SDL_Rect getSDL_Rect() { return Character::getSDL_Rect(); }
	
private:

};

