#include "EnemyManager.h"


EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

bool EnemyManager::add(Enemy newEnemy)
{
	if (currEnemies >= MAX_ENEMIES)
	{
		return false;
	}
	else
	{
		enemies.push_back(newEnemy);
		currEnemies++;
		return true;
	}
}

/*
bool EnemyManager::remove(Enemy target)
{
	Enemies.
}
*/

Enemy& EnemyManager::returnEnemyAt(int index)
{
	Enemy result;
	if (index >= currEnemies)
	{
		return result;
	}
	else
	{
		return enemies.at(index);
	}
}

//Credit for this function to lazyfoo, will probably make my own at some point
bool EnemyManager::checkCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;


	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}