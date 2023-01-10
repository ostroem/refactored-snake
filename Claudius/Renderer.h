#pragma once
#include <stdexcept>

#include "Window.h"
#include "Utils.h"
#include <concepts>


class Renderer {
public:
	Renderer(const Window& window);

	void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const noexcept;
	void render(Position part, Color color) const noexcept;
	void clear() const noexcept;
	void present() const noexcept;
	void render_fillrect(const SDL_Rect& rect) const noexcept;
private:
	std::unique_ptr<SDL_Renderer, SDL_Deleter> renderer;
};