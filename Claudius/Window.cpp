#include "Window.h"
#include <stdexcept>
Window::Window(std::string title, unsigned int width, unsigned int height) {
	SDL_Window* ptr = SDL_CreateWindow(title.c_str(), 0, 0, width, height, 0);
	if (ptr == nullptr) {
		throw std::runtime_error(SDL_GetError());
	}
	window = std::unique_ptr<SDL_Window, SDL_Deleter>(ptr);
	SDL_SetWindowPosition(window.get(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

SDL_Window* Window::get_ptr() const noexcept {
	return window.get();
}