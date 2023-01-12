#pragma once
#pragma warning(push, 0)
#pragma warning(disable : 26812)
#include "SDL.h"
#pragma warning(pop)

struct SDL_System {
	SDL_System(Uint32 flags_);
	~SDL_System();

	SDL_System(const SDL_System&) = delete;
	SDL_System(const SDL_System&&) = delete;
	SDL_System& operator=(const SDL_System&) = delete;
	SDL_System& operator=(const SDL_System&&) = delete;
};