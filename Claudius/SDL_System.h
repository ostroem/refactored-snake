#pragma once
#include <stdexcept>
#include "SDL.h"

class SDL_System {
public:
	SDL_System(Uint32 flag) { // <-- default constructors should be noexcept HOWEVER, it may throw that's why it's
		if (SDL_Init(flag) != 0) {					// not noexcept
			throw std::runtime_error(SDL_GetError());
		}
	}
	~SDL_System() {
		SDL_Quit();
	}
	SDL_System(const SDL_System&) = delete;
	SDL_System(const SDL_System&&) = delete;
	SDL_System& operator=(const SDL_System&) = delete;
	SDL_System& operator=(const SDL_System&&) = delete;
};