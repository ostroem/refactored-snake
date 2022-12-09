#pragma once
#include "SDL_render.h"
#include <memory>
#include <assert.h>
struct Window {
	Window(std::string title, unsigned int width, unsigned int height) noexcept {
		window = SDL_CreateWindow(title.c_str(), 0, 0, width, height, 0);
		assert(window != nullptr);
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