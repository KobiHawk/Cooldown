#pragma once
#include <string>
#include <SDL.h>
#include "Projectile.h"

class ProjectileManager
{
public:
	ProjectileManager();
	~ProjectileManager();

private:
	const static int MAX_PROJECTILES = 200;
	Projectile projectiles[MAX_PROJECTILES];
	int currProjectiles = 0;

	SDL_Texture* projectileTexture;
};

