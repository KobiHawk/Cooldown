#pragma once
#include <SDL.h>
#include <string>

class System
{
public:
	System();
	~System();

	bool init();
	void close();
	SDL_Texture* loadTexture(std::string path);

private:
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Renderer* renderer;

	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 1024;
};

