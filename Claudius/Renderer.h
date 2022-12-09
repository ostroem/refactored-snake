#pragma once
#include "Window.h"
#include <stdexcept>
struct Renderer {

	Renderer(const Window& window) {
		renderer = SDL_CreateRenderer(window.window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) {
			throw std::runtime_error(SDL_GetError());
		}
	}
	~Renderer() {
		SDL_DestroyRenderer(renderer);
	}

	Renderer(const Renderer& other) = delete;
	Renderer(const Renderer&& other) = delete;
	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(const Renderer&& other) = delete;

	void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const noexcept {
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}

	void clear() const noexcept {
		SDL_RenderClear(renderer);
	}
	void present() const noexcept {
		SDL_RenderPresent(renderer);
	}
	void render_fillrect(const SDL_Rect& rect) const noexcept {
		SDL_RenderFillRect(renderer, &rect);
	}

	SDL_Renderer* renderer;
};