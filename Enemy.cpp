#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Enemy& Enemy::operator=(const Enemy &newEnemy)
{
	this->location = newEnemy.location;
	this->velocity = newEnemy.velocity;
	this->rollTicksRemaining = newEnemy.rollTicksRemaining;
	this->key = newEnemy.key;
	
	return *this;
}