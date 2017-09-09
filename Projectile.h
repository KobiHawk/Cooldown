#pragma once
#include "Structs.h"
class Projectile
{
public:
	Projectile();
	~Projectile();

private:
	Velocity velocity;
	Position position;
};

