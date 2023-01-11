#include <stdexcept>

#include "Window.h"

Window::Window(std::string title, int width, int height)
	: window(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0)) {
	if (window == nullptr) {
		throw std::runtime_error(SDL_GetError());
	}
}

SDL_Window* Window::get_ptr() const noexcept {
	return window.get();
}