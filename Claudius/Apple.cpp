#include "Apple.h"
#include "Config.h"

Apple::Apple() noexcept {
	randomize_position();
}

void Apple::render(const Renderer& renderer) const noexcept {
	renderer.render(position, APPLE_COLOR);
}

Position Apple::get_position() const noexcept {
	return position;
}

int Apple::get_x() const noexcept
{
	return position.x;
}

int Apple::get_y() const noexcept
{
	return position.y;
}

void Apple::randomize_position() noexcept{
	constexpr int denom = 10;
	position.x = rand() % (Config::WINDOW_WIDTH / denom) * denom;
	position.y = rand() % (Config::WINDOW_HEIGHT / denom) * denom;

}

