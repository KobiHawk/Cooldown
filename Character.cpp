#include "Character.h"
#include <string>


Character::Character()
{
	location.x = 0;
	location.y = 0;
	location.w = 0;
	location.h = 0;
	velocity = { 0.0f, 0.0f };
}


Character::~Character()
{
}

Character::Character(int x, int y, int w, int h)
{
	location.x = x;
	location.y = y;
	location.w = w;
	location.h = h;
	velocity = { 0.0f, 0.0f };
}

Velocity Character::getVelocity()
{
	return velocity;
}

Position Character::getCenter()
{
	Position result = { location.x + (location.w / 2), location.y + (location.h / 2) };
	return result;
}

void Character::setPosition(int x, int y, int w, int h)
{
	location.x = x;
	location.y = y;
	location.w = w;
	location.h = h;
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
	location.x += velocity.velocityX;
	location.y += velocity.velocityY;
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
	Position newPosition = { getCenter().x, getCenter().y};
	Velocity newVelocity = { (target.x - location.x)/60.0f, (target.y - location.y)/60.0f }; // divides by 60 for frame rate

	Projectile *result = new Projectile(newPosition, newVelocity);

	return *result;
}