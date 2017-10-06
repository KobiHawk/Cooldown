#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include "Character.h"
#include "Mouse.h"
#include "ProjectileManager.h"

bool init();
SDL_Texture* loadTexture(std::string path);
bool loadMedia();
void close();

Character player;
ProjectileManager projectileManager;
SDL_Window* window;
SDL_Surface* screenSurface;
SDL_Renderer* renderer;
SDL_Texture* playerTexture;
SDL_Texture* projectileTexture;
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;
const int FRAME_RATE = 60;
int speed = 5;

bool init()
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

SDL_Texture* loadTexture(std::string path)
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

void close()
{
	SDL_DestroyTexture(playerTexture);
	playerTexture = NULL;

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool loadMedia()
{
	bool result = true;

	playerTexture = loadTexture("Assets/Images/RedCircle.png");
	if (playerTexture == NULL)
	{
		result = false;
	}
	projectileTexture = loadTexture("Assets/Images/Bullet.png");
	if (projectileTexture == NULL)
	{
		result = false;
	}
	return result;
}

int main(int argc, char* argv[])
{
	if (!init())
	{
		printf("Init failed!");
	}
	else
	{

		if (!loadMedia())
		{
			printf("Load media failed!");
		}
		else
		{
			bool quit = false;
			int moveX;
			int moveY;

			//SDL_Rect drawDestination = { (SCREEN_WIDTH / 2) - 64, (SCREEN_HEIGHT / 2) - 64, 64, 64 }; // character size here
			player.setPosition((SCREEN_WIDTH / 2) - 64, (SCREEN_HEIGHT / 2) - 64, 64, 64);

			SDL_Event e;
			Mouse mouse;
			Position mousePosition;
			//ProjectileManager projectileManager;

			while (!quit) // main game loop
			{
				//first thing to do is poll all events
				while (SDL_PollEvent(&e) != 0) // keep polling until no events on current frame
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_SPACE:
							player.roll();
							break;
						default:
							break;
							//switch for input here
						}
					}
					else if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						mousePosition = mouse.handleClickEvent();
						projectileManager.add(player.fire(mousePosition));
					}
					
				}
				//end event handling

				//movement, independent of events, based solely on keyboard input
				const Uint8* state = SDL_GetKeyboardState(NULL);

				moveX = 0; //as an int 
				moveY = 0;
				
				if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])
				{
					moveY--;
				}
				if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])
				{
					moveY++;
				}
				if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
				{
					moveX--;
				}
				if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
				{
					moveX++;
				}
				player.move(moveX, moveY);
				//end player movement
				
				//end movement

				SDL_RenderClear(renderer);
				SDL_RenderCopy(renderer, playerTexture, NULL, &player.getSDL_Rect());

				//manage projectiles
				for (int i = 0; i < projectileManager.getCurrProjectiles(); i++)
				{
					//move all projectiles, then render them
					projectileManager.returnProjectileAt(i).move();
					SDL_RenderCopy(renderer, projectileTexture, NULL, &projectileManager.returnProjectileAt(i).getSDL_Rect());
				}
				SDL_RenderPresent(renderer); // blit

			} // end of game loop, should be nothing after
		} 
	}
	close();
	return 0;
}
