#pragma once
#include "Renderer.h"
#include "Utils.h"

class Apple {
private:
	Position position = get_randomized_position();
public:
	void render(const Renderer& renderer) const noexcept;
	Position get_position() const noexcept;
	void set_position(Position position_) noexcept;

};