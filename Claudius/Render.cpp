#include "Renderer.h"

Renderer::Renderer(const Window& window) {
	SDL_Renderer* ptr = SDL_CreateRenderer(window.get_ptr(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (ptr == nullptr) {
		throw std::runtime_error(SDL_GetError());
	}
	renderer = std::unique_ptr<SDL_Renderer, SDL_Deleter>(ptr);
}

void Renderer::set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const noexcept {
	SDL_SetRenderDrawBlendMode(renderer.get(), SDL_BlendMode::SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer.get(), r, g, b, a);
}
void Renderer::render() noexcept {

}

void Renderer::clear() const noexcept {
	SDL_RenderClear(renderer.get());
}
void Renderer::present() const noexcept {
	SDL_RenderPresent(renderer.get());
}
void Renderer::render_fillrect(const SDL_Rect& rect) const noexcept {
	SDL_RenderFillRect(renderer.get(), &rect);
}