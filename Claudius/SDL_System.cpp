#include <stdexcept>

#include "SDL_System.h"

SDL_System::SDL_System(Uint32 flags_) {
	if (SDL_Init(flags_) != 0) {
		throw std::runtime_error(SDL_GetError());
	}
}

SDL_System::~SDL_System() {
	SDL_Quit();
}
