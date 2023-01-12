#include "SDL_Delete.h"

void SDL_Deleter::operator()(SDL_Window* ptr_) const noexcept {
	if (ptr_) {
		SDL_DestroyWindow(ptr_);
	}
}

void SDL_Deleter::operator()(SDL_Renderer* ptr_) const noexcept {
	if (ptr_) {
		SDL_DestroyRenderer(ptr_);
	}
}
