#pragma once
#include <vector>
#include "SDL_keycode.h"

#include "Renderer.h"
#include "Utils.h"

class Player {
public:
	Player() noexcept;

	void render(Renderer& renderer) const noexcept;
	void update() noexcept;

	void grow() noexcept;
	bool is_head_colliding_with_part();
	bool is_head_out_of_bounds();

	void reset() noexcept;
	void on_key_down(SDL_Keycode key) noexcept;
	Position get_position() const noexcept;

private:
	void update_head_position() noexcept;
	void update_parts_position() noexcept;
	Position& head() noexcept;

	enum class Directions {
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

private:
	Directions direction = Directions::UP;
	std::vector<Position> parts;
};