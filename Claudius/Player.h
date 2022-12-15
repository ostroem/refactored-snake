#pragma once		// #pragma once == Compile this file once.

#include "Entity.h"
#include "SDL_keycode.h"
#include <array>
#include "RenderManager.h"

class Player {
public:
	Player() noexcept;

	void on_key_down(SDL_Keycode key) noexcept;
	void render(RenderManager& renderManager);
	void update();
	void reset() noexcept;
	Vector2Int get_position() const 
	{ 
		return parts.at(0).position;
	}
	void set_position(Entity& part) noexcept;
	void grow();
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
	const int rectSize = 10;
};