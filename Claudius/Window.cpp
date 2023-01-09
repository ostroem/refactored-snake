#include "Window.h"
#include <stdexcept>
Window::Window() // SDL_CreateWIndow could fail, hence we cannot declare it noexcept
	: window(SDL_CreateWindow(Config::TITLE.data(), 0, 0, Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, 0)){
	if (window == nullptr) {
		throw std::runtime_error(SDL_GetError());
	}
	SDL_SetWindowPosition(window.get(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

SDL_Window* Window::get_ptr() const noexcept {
	return window.get();
}