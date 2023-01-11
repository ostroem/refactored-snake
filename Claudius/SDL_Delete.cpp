#include "SDL_Delete.h"

void SDL_Deleter::operator()(SDL_Window* window_ptr) const noexcept {
	if (window_ptr) {
		SDL_DestroyWindow(window_ptr);
	}
}

void SDL_Deleter::operator()(SDL_Renderer* renderer_ptr) const noexcept {
	if (renderer_ptr) {
		SDL_DestroyRenderer(renderer_ptr);
	}
}
