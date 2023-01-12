#pragma once
#include "Window.h"
#include "Utils.h"

class Renderer {
public:
	Renderer(const Window& window);

	void set_draw_color(Uint8 r_, Uint8 g_, Uint8 b_, Uint8 a_) const noexcept;
	void render(Position part_, Color color_) const noexcept;
	void clear() const noexcept;
	void present() const noexcept;
	void fill_rect(const SDL_Rect& rect_) const noexcept;
private:
	std::unique_ptr<SDL_Renderer, SDL_Deleter> renderer;
};