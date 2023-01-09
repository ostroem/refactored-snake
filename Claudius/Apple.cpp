#include "Apple.h"
#include "Config.h"

Apple::Apple() noexcept {
	randomize_position();
}

void Apple::render(Renderer& renderer) const noexcept {
	renderer.render(position, APPLE_COLOR);
}

Position Apple::get_position() const noexcept {
	return position;
}

void Apple::randomize_position() noexcept{
	constexpr int denom = 10;
	position.x = rand() % (Config::WINDOW_WIDTH / denom) * denom;
	position.y = rand() % (Config::WINDOW_HEIGHT / denom) * denom;

}

