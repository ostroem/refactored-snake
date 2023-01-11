#pragma once
#include <vector>
#include "SDL_keycode.h"

#include "Renderer.h"
#include "Utils.h"

class Player {
private:
	enum class Directions {
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	Directions direction = Directions::UP;
	std::vector<Position> parts;
public:
	Player() noexcept;
	void update() noexcept;
	void render(const Renderer& renderer) const noexcept;
private:
	void update_parts_position() noexcept;
	void update_head_position() noexcept;
	void set_head_position(Position pos) noexcept;
public:
	void grow() noexcept;
	void reset() noexcept;
	void on_key_down(SDL_Keycode key) noexcept;

	Position get_position() const noexcept;
	Position get_head() const noexcept;

	std::vector<Position>::iterator get_parts_begin() noexcept;
	std::vector<Position>::iterator get_parts_end() noexcept;

	int get_head_x() const noexcept;
	int get_head_y() const noexcept;

};