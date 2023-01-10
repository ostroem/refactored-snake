#pragma once
#include <vector>
#include "SDL_keycode.h"

#include "Renderer.h"
#include "Utils.h"

class Player {
public:
	Player() noexcept;

	void render(const Renderer& renderer) const noexcept;
	void update() noexcept;

	void grow() noexcept;

	void reset() noexcept;
	void on_key_down(SDL_Keycode key) noexcept;
	Position get_position() const noexcept;
	std::vector<Position>::iterator get_parts_begin() noexcept {
		return parts.begin();
	}
	std::vector<Position>::iterator get_parts_end() noexcept {
		return parts.end();
	}
	int get_head_x() const noexcept { return get_head().x; }
	int get_head_y() const noexcept { return get_head().y; }
	std::vector<Position> get_parts() {
		return parts;
	}

private:
	void update_head_position() noexcept;
	void update_parts_position() noexcept;
	Position get_head() const noexcept;
	void set_head_position(Position pos) noexcept;

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