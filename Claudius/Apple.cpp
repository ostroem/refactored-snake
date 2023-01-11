#include "Apple.h"
#include "Config.h"

Apple::Apple() noexcept {
	randomize_position();
}

void Apple::randomize_position() noexcept{
	constexpr int denom = 10;
	position.x = rand() % (Config::WINDOW_WIDTH / denom) * denom;
	position.y = rand() % (Config::WINDOW_HEIGHT / denom) * denom;
}

Position Apple::get_position() const noexcept {
	return position;
}

void Apple::render(const Renderer& renderer) const noexcept {
	renderer.render(position, APPLE_COLOR);
}