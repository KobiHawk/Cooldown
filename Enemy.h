#pragma once
#include "Character.h"
#include <stdio.h>

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();

	void setKey(int key) { this->key = key; }
	int getKey() { return key; }

	Enemy(const Enemy&) = default;
	Enemy& operator=(const Enemy &newEnemy);

	SDL_Rect getSDL_Rect() { return Character::getSDL_Rect(); }

private:
	int key = -1;

};

