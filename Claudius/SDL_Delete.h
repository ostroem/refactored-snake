#pragma once
#include "SDL_render.h"

struct SDL_Deleter {
	void operator()(SDL_Window* ptr_) const noexcept;
	void operator()(SDL_Renderer* ptr_) const noexcept;
};