#include "Projectile.h"
#include <stdio.h>



Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}

void Projectile::move()
{
	location.x += velocity.velocityX;
	location.y += velocity.velocityY;
	//location.x++;
	//location.y++;
}

SDL_Rect Projectile::getSDL_Rect()
{
	return location;
}
Velocity Projectile::getVelocity()
{
	return velocity;
}
void Projectile::setSDL_Rect(SDL_Rect location)
{
	this->location = location;
	this->location.h = SPRITE_SIZE;
	this->location.w = SPRITE_SIZE;
}
void Projectile::setVelocity(Velocity velocity)
{
	this->velocity = velocity;
}