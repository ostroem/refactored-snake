#pragma once
#include "Renderer.h"
#include "Utils.h"

class Apple {
private:
	Position position;
public:
	Apple(Position position) noexcept;
	void render(const Renderer& renderer) const noexcept;
	void set_position(Position position_) noexcept;
	Position get_position() const noexcept;
};