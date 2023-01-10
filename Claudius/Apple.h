#pragma once
#include "Renderer.h"
#include "Utils.h"

class Apple {
public:
	Apple() noexcept;
	void render(const Renderer& renderer) const noexcept;
	Position get_position() const noexcept;
	int get_x() const noexcept;
	int get_y() const noexcept;
	void randomize_position() noexcept;
private:
	Position position;
};