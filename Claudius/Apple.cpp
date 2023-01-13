#include "Apple.h"
#include "Config.h"

Apple::Apple(Position position_) noexcept
	: position(position_){
}

void Apple::render(const Renderer& renderer_) const noexcept {
	renderer_.render(position, APPLE_COLOR);
}

void Apple::set_position(Position position_) noexcept {
	position = position_;
}

Position Apple::get_position() const noexcept {
	return position;
}