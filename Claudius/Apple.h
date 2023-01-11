#pragma once
#include "Renderer.h"
#include "Utils.h"

class Apple {
private:
	Position position;
public:
	Apple() noexcept;
	void render(const Renderer& renderer) const noexcept;
	void randomize_position() noexcept;
	Position get_position() const noexcept;
};