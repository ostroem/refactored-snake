#include <stdexcept>

#include "Renderer.h"

Renderer::Renderer(const Window& window_)
	: renderer(SDL_CreateRenderer(window_.get_ptr(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED)) {
	if (renderer == nullptr) {
		throw std::runtime_error(SDL_GetError());
	}
}

void Renderer::set_draw_color(Uint8 r_, Uint8 g_, Uint8 b_, Uint8 a_) const noexcept {
	SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BlendMode::SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer.get(), r_, g_, b_, a_);
}

void Renderer::render(Position position_, Color color_) const noexcept {
	const SDL_Rect rect{ position_.x, position_.y, TILE_SIZE, TILE_SIZE };

	set_draw_color(color_.r, color_.g, color_.b, color_.a);
	fill_rect(rect);
}

void Renderer::clear() const noexcept {
	set_draw_color(0, 0, 0, 0);
	SDL_RenderClear(renderer.get());
}
void Renderer::present() const noexcept {
	SDL_RenderPresent(renderer.get());
	clear();
}
void Renderer::fill_rect(const SDL_Rect& rect_) const noexcept {
	SDL_RenderFillRect(renderer.get(), &rect_);
}