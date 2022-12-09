#pragma once
#include "Window.h"
struct Renderer {

	Renderer(const Window& window) noexcept {
		renderer = SDL_CreateRenderer(window.window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
		assert(renderer != nullptr);
	}
	~Renderer() {
		SDL_DestroyRenderer(renderer);
	}

	void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}

	void clear() {
		SDL_RenderClear(renderer);
	}
	void present() {
		SDL_RenderPresent(renderer);
	}
	void render_fillrect(const SDL_Rect& rect) {
		SDL_RenderFillRect(renderer, &rect);
	}

	SDL_Renderer* renderer;
};