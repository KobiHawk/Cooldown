#pragma once
#include <string>
#include <SDL.h>
#include "Projectile.h"
#include <vector>

struct Node
{
	Projectile projectile;
	Node* next;
};

class LinkedList
{
public:

private:
	Node head;
	int totalProjectiles;
};


class ProjectileManager
{
public:
	ProjectileManager();
	~ProjectileManager();

	int getCurrProjectiles() { return currProjectiles; }
	bool add(Projectile newProjectile);
	Projectile returnProjectileAt(int index);

private:
	const static int MAX_PROJECTILES = 200;
	int currProjectiles = 0;

	std::vector<Projectile> projectiles;

	//SDL_Texture* projectileTexture;
};

