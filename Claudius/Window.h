#pragma once
#include "SDL_render.h"
#include "SDL_Delete.h"
#include <memory>
#include <string>

class Window {
public:
	Window(std::string title, unsigned int width, unsigned int height);
	SDL_Window* get_ptr() const noexcept;
private:
	std::unique_ptr<SDL_Window, SDL_Deleter> window;
};