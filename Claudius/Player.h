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
	Position& head();
	void push_part();
	void update_head_position();
	void update_parts_position();

private:
	enum class directions {
		up,
		down,
		left,
		right
	};
private:
	directions direction = directions::up;
	std::vector<Position> parts;
};