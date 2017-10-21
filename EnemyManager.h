#pragma once
#include <string>
#include <SDL.h>
#include "Enemy.h"
#include <vector>
#include <map>

/*
Identical to ProjectileManager, but for things with Enemies that Projectiles can collide with.
Tried to find a way to incorporate generic vectors, but couldn't quite figure it out.
Should be merged with ProjectileManager someday.
*/

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	int getCurrEnemies() { return enemies.size(); }
	bool add(Enemy& newEnemy);
	bool erase(int key);
	Enemy returnEnemyAt(int index);
	Enemy& returnEnemyIndex(int index);
	bool EnemyManager::checkCollision(SDL_Rect a, SDL_Rect b);

private:
	const static int MAX_ENEMIES = 200;
	//int currEnemies = 0;
	int currKey = 0;

	//std::vector<Enemy> enemies;
	std::map<int, Enemy> enemies;

	//SDL_Texture* projectileTexture;
};

