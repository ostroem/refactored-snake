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
	void reset();
	Vector2Int get_position() const 
	{ 
		return parts.at(0).position;
	}
	bool is_head_colliding_with_part();
	bool is_head_out_of_bounds();

private:
	void set_position(Entity& part) noexcept;
	void grow();
	void push_part() noexcept;
	Entity& head() {
		return parts.at(0);
	}
	void update_head_direction();
	void update_parts_position();
	Entity construct_part() noexcept;
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