#pragma once		// #pragma once == Compile this file once.

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
	void set_position(Entity& part) noexcept;
	void grow();
	void update_parts_position();
	void push_part();
	Entity construct_part();
	void update_head_direction();
	Entity& head() {
		return parts.at(0);
	}
private:
	enum class directions {
		up,
		down,
		left,
		right
	};
	directions direction;
private:
	std::vector<Entity> parts;
	const int movementSpeed = 10;
};