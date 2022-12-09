#pragma once
#include "SDL_render.h"
#include <memory>
#include <assert.h>
#include <stdexcept>
struct Window {
	Window(std::string title, unsigned int width, unsigned int height) {
		window = SDL_CreateWindow(title.c_str(), 0, 0, width, height, 0);
		if (window == nullptr) {
			throw std::runtime_error(SDL_GetError());
		}
	}
	~Window() {
		SDL_DestroyWindow(window);
	}
	Window(const Window& other) = delete;
	Window(const Window&& other) = delete;
	Window& operator=(const Window& other) = delete;
	Window& operator=(const Window&& other) = delete;

	SDL_Window* window;
};