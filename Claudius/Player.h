#pragma once
#include <vector>
#include "SDL_keycode.h"

#include "Renderer.h"
#include "Utils.h"

Position get_randomized_position() noexcept;

class Player {
private:
	std::vector<Position> body_parts{};
	Position velocity{};
public:
	Player() noexcept;
	void update() noexcept;
	void render(const Renderer& renderer_) const noexcept;
private:
	void update_parts_position() noexcept;
	void update_head_position() noexcept;
	Position& head() noexcept;
public:
	void grow() noexcept;
	void reset(Position position_) noexcept;
	void on_key_down(SDL_Keycode key_) noexcept;

	Position get_position() const noexcept;

	std::vector<Position> get_body_parts() noexcept;
};