#include "Mouse.h"



Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}

Position Mouse::handleClickEvent()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	Position result = { x, y };
	return result;
}