#pragma once
#include <string>
#include <SDL.h>
#include "Bullet.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

private:
	const static int MAX_BULLETS = 200;
	Bullet bullets[MAX_BULLETS];
	int currBullets = 0;

	SDL_Texture* bulletTexture;
};

