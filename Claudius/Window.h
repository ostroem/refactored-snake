#pragma once
#include "SDL_render.h"
#include <memory>
#include <assert.h>
struct Window {
	Window() noexcept {
		window = SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
		assert(window != nullptr);
	}
	SDL_Window* window;
};