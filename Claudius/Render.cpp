#include "Renderer.h"
#include <concepts>

Renderer::Renderer(const Window& window)
	: renderer(SDL_CreateRenderer(window.get_ptr(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED)) {
	if (renderer == nullptr) {
		throw std::runtime_error(SDL_GetError());
	}
}

void Renderer::set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const noexcept {
	SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BlendMode::SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer.get(), r, g, b, a);
}

void Renderer::render(Position position, Color color) const noexcept {
	const SDL_Rect rect{ position.x, position.y, TILE_SIZE, TILE_SIZE };

	set_draw_color(color.r, color.g, color.b, color.a);
	render_fillrect(rect);
}

void Renderer::clear() const noexcept {
	set_draw_color(0, 0, 0, 0);
	SDL_RenderClear(renderer.get());
}
void Renderer::present() const noexcept {
	SDL_RenderPresent(renderer.get());
	clear();
}
void Renderer::render_fillrect(const SDL_Rect& rect) const noexcept {
	SDL_RenderFillRect(renderer.get(), &rect);
}