#include "Character.h"
#include <string>


Character::Character()
{
	x = 0;
	y = 0;
	w = 0;
	h = 0;
	velocity = { 0.0f, 0.0f };
}


Character::~Character()
{
}

SDL_Rect Character::getSDL_Rect()
{
	SDL_Rect result = { x, y, w, h };
	return result;
}

Velocity Character::getVelocity()
{
	return velocity;
}

void Character::setPosition(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Character::setVelocity(float velocityX, float velocityY)
{
	velocity.velocityX = velocityX;
	velocity.velocityY = velocityY;
}

/*
return: void
param: int x: -1 for moving left, 1 for moving right, 0 for not moving.
param: int y: -1 for moving up, 1 for moving down, 0 for not moving.

This function is called every frame to see where the player wants to move the character.
Sometimes it won't move anywhere.
*/
void Character::move(int x, int y)
{
	//check to see if we're rolling, to determine the velocity cap
	float maxVelocity = MAX_VELOCITY;
	if (rollTicksRemaining > 0)
	{
		maxVelocity *= 2;
		rollTicksRemaining--;
	}

	//slow down X if we're not moving on the X axis
	if (x == 0)
	{
		if ((velocity.velocityX < MAX_VELOCITY / 100.0f) && (velocity.velocityX > -MAX_VELOCITY / 100.0f))//going very slow
		{
			velocity.velocityX = 0;//stop
		}
		else if (velocity.velocityX > 0) //going right
		{
			velocity.velocityX -= (SPEED / 2.0f);
		}
		else //going left
		{
			velocity.velocityX += (SPEED / 2.0f);
		}
		
	}
	else //still moving on X axis
	{
		velocity.velocityX += (SPEED * x);
	}

	//slow down Y if we're not moving on the Y axis
	if (y == 0)
	{
		if ((velocity.velocityY < MAX_VELOCITY / 100.0f) && (velocity.velocityY > -MAX_VELOCITY / 100.0f))//going very slow
		{
			velocity.velocityY = 0;//stop
		}
		else if (velocity.velocityY > 0) //going down
		{
			velocity.velocityY -= (SPEED / 2.0f);
		}
		else //going up
		{
			velocity.velocityY += (SPEED / 2.0f);
		}
		
	}
	else //still moving on Y axis
	{
		velocity.velocityY += (SPEED * y);
	}

	//cap speed
	//x axis
	if (velocity.velocityX > maxVelocity)
	{
		velocity.velocityX = maxVelocity;
	}
	if (velocity.velocityX < -maxVelocity)
	{
		velocity.velocityX = -maxVelocity;
	}
	//y axis
	if (velocity.velocityY > maxVelocity)
	{
		velocity.velocityY = maxVelocity;
	}
	if (velocity.velocityY < -maxVelocity)
	{
		velocity.velocityY = -maxVelocity;
	}

	//move character based on velocity
	this->x += velocity.velocityX;
	this->y += velocity.velocityY;
}

void Character::roll()
{
	velocity.velocityX *= 2;
	velocity.velocityY *= 2;
	rollTicksRemaining = DASH_DURATION; // will count down, preventing the movespeed cap from applying until roll is done.
}

Projectile Character::fire(Position target)
{

	//initialize new projectile
	SDL_Rect newRect = { this->x + (w/2), this->y + (h/2), 4, 4 };
	Velocity newVelocity = { (target.x - x)/60.0f, (target.y - y)/60.0f }; // divides by 60 for frame rate

	Projectile* result = new Projectile(newRect, newVelocity);

	//result->setSDL_Rect(newRect);
	//result->setVelocity(newVelocity);



	return *result;
}