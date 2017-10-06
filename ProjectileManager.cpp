#include "ProjectileManager.h"



ProjectileManager::ProjectileManager()
{
}


ProjectileManager::~ProjectileManager()
{
}

bool ProjectileManager::add(Projectile newProjectile)
{
	//Projectile thisProjectile = newProjectile;
	//thisProjectile.setSDL_Rect(newProjectile.getSDL_Rect());
	//thisProjectile.setVelocity(newProjectile.getVelocity());
	if (currProjectiles >= MAX_PROJECTILES)
	{
		return false;
	}
	else
	{
		projectiles.push_back(newProjectile);
		//projectiles[currProjectiles] = thisProjectile;
		currProjectiles++;
		return true;
	}
}

//Return the address, not a copy, because the modifications made to the projectile need to stay
Projectile& ProjectileManager::returnProjectileAt(int index)
{
	Projectile result;
	if (index >= currProjectiles)
	{
		return result;
	}
	else
	{
		return projectiles.at(index);
	}
}