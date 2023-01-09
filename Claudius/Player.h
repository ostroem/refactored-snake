#pragma once
#include <vector>
#include "SDL_keycode.h"

#include "Renderer.h"
#include "Utils.h"

class Player {
public:
	Player() noexcept;

	void on_key_down(SDL_Keycode key) noexcept;
	void render(Renderer& renderer) const noexcept;
	void update();
	void reset() noexcept;
	Position get_position() const;
	void grow();
	bool is_head_colliding_with_part();
	bool is_head_out_of_bounds();

private:
	Position& head() noexcept;
	void update_head_position() noexcept;
	void update_parts_position() noexcept;

private:
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