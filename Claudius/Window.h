#pragma once
#include "SDL_render.h"
#include "SDL_Delete.h"
#include <memory>
#include <string>
#include "Config.h"

class Window {
public:
	Window();
	SDL_Window* get_ptr() const noexcept;
private:
	std::unique_ptr<SDL_Window, SDL_Deleter> window;
};