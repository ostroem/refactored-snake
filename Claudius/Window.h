#pragma once
#include <memory>
#include <string>
#include "SDL_render.h"

#include "SDL_Delete.h"
#include "Config.h"

class Window {
public:
	Window(std::string title_, int width_, int height_);
	SDL_Window* get_ptr() const noexcept;
private:
	std::unique_ptr<SDL_Window, SDL_Deleter> window;
};