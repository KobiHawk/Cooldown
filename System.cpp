#include "System.h"
#include <SDL_image.h>



System::System()
{
	init();
}


System::~System()
{
	close();
}

bool System::init()
{
	bool result = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL Error: %s\n", SDL_GetError());
		result = false;
	}
	else
	{
		window = SDL_CreateWindow("Cooldown", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
		if (window == NULL)
		{
			printf("SDL Error: %s\n", SDL_GetError());
			result = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL)
			{
				printf("Renderer failed to load. SDL Error: %s\n", SDL_GetError());
				result = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG; // we want to load PNGs
				if (!(IMG_Init(imgFlags) & imgFlags)) // if we're not loading PNGs, but some other image format
				{
					printf("IMG Error: %s\n", IMG_GetError());
					result = false; // its an error
				}
				else
				{
					//everything loaded properly!
					screenSurface = SDL_GetWindowSurface(window);
				}
			}
		}
	}


	return result;
}

void System::close()
{
	//SDL_DestroyTexture(gTexture);
	//gTexture = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* System::loadTexture(std::string path)
{
	SDL_Texture* result = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Failed to load image %s. SDL_Image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		result = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (result == NULL)
		{
			printf("Failed to create texture from %s. SDL_Image Error: %s\n", path.c_str(), IMG_GetError());
		}

		SDL_FreeSurface(loadedSurface);

	}

	return result;
}