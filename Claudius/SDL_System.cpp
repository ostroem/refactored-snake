#include "SDL_System.h"

SDL_System::SDL_System(Uint32 flag) {
	if (SDL_Init(flag) != 0) {
		throw std::runtime_error(SDL_GetError());
	}
}

SDL_System::~SDL_System()
{
	SDL_Quit();
}
