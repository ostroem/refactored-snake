#pragma once
#include <stdexcept>
#include "SDL.h"

struct SDL_System {
	SDL_System(Uint32 flag);
	~SDL_System();

	SDL_System(const SDL_System&) = delete;
	SDL_System(const SDL_System&&) = delete;
	SDL_System& operator=(const SDL_System&) = delete;
	SDL_System& operator=(const SDL_System&&) = delete;
};