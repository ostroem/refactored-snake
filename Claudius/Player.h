#pragma once

#include "Entity.h"
#include "SDL_keycode.h"
#include <array>
#include "RenderManager.h"

class Player {
public:
	Player();

	void on_key_down(SDL_Keycode key) noexcept;
	void render(RenderManager& renderManager);
	void update();
	void reset() noexcept;
	Vector2Int get_position() const;
	void grow();
	bool is_head_colliding_with_part();
	bool is_head_out_of_bounds();

private:
	Entity& head();
	Entity construct_part() const noexcept;
	void set_position(Entity& part) noexcept;
	void push_part() noexcept;
	void update_head_direction();
	void update_parts_position();

private:
	enum class directions {
		up,
		down,
		left,
		right
	};
private:
	directions direction;
	std::vector<Entity> parts;
	const int movementSpeed = 10;
};