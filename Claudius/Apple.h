#pragma once
#include "Renderer.h"
#include "Utils.h"

Position get_randomized_position() noexcept;

class Apple {
private:
	Position position = get_randomized_position();
public:
	void render(const Renderer& renderer) const noexcept;
	void set_position(Position position_) noexcept;
	Position get_position() const noexcept;
};