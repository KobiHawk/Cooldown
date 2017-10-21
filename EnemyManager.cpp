#include "EnemyManager.h"


EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

bool EnemyManager::add(Enemy& newEnemy)
{
	if (enemies.size() >= MAX_ENEMIES)
	{
		return false;
	}
	else
	{
		newEnemy.setKey(currKey); // the enemy needs to know what his key is so we can look him up when he dies
		enemies[currKey] = newEnemy; // used to prevent overwriting enemies when a previous enemy in the list dies
		currKey++;
		return true;
	}
}

bool EnemyManager::erase(int key)
{
	bool result = true;

	if (key > enemies.size())
	{
		result = false;
	}
	else
	{
		enemies.erase(key);
	}

	/*
	std::vector<Enemy>::iterator iterator;
	iterator = find(enemies.begin(), enemies.end(), target);
	if (iterator != enemies.end())
	{
		enemies.erase(iterator);
		currEnemies--;
	}
	else
	{
		result = false;
	}
	*/

	return result;
}
/*
returnEnemyAt(int index)

Returns the enemy based on its key.
*/
Enemy EnemyManager::returnEnemyAt(int index)
{
	Enemy result;

	std::map<int, Enemy>::iterator iterator;

	iterator = enemies.find(index);
	if (iterator != enemies.end())
	{
		//found it 
		result = iterator->second; //returns the second value of the pair, the enemy that we found (first is an int, the key)
	}

	return result;
}

/*
returnEnemyIndex(int index)

Returns the enemy based on its index in the map.
*/
Enemy& EnemyManager::returnEnemyIndex(int index)
{
	Enemy result;

	if (index > enemies.size())
	{
		return result;
	}
	else
	{
		return enemies[index];
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