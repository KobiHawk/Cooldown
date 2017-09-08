#pragma once
#include <SDL.h>
#include "Structs.h"
class Mouse
{
public:
	Mouse();
	~Mouse();

	Position handleClickEvent();
};

