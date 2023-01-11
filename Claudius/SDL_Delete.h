#pragma once
#include "SDL_render.h"

struct SDL_Deleter {
	void operator()(SDL_Window* ptr) const noexcept;
	void operator()(SDL_Renderer* ptr) const noexcept;
};