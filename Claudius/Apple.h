#pragma once

#include "Renderer.h"
#include "Utils.h"

class Apple {
public:
	Apple() noexcept;
	void render(Renderer& renderer) const noexcept;
	Position get_position() const noexcept;
	void randomize_position() noexcept;
private:
	Position position;
};