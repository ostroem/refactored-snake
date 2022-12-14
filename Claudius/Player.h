#pragma once		// #pragma once == Compile this file once.

#include "Entity.h"
#include "SDL_keycode.h"
#include <array>
#include "RenderManager.h"

class Player : public Entity {
public:
	Player() noexcept;

	void on_key_down(SDL_Keycode key) noexcept;
	void render(RenderManager& renderManager);				// A reference or pointer doesn't need to be #include, just a forward declare.
	void update();
	void reset();
	Vector2Int get_position() const noexcept { return position; }
	void set_position(Entity& part) noexcept;
private:
	enum class directions {
		up,
		down,
		left,
		right
	};
	directions direction;
public:
	std::vector<Entity> parts;
private:
	const int movementSpeed;

	std::array<int, 50> xDifference;
	std::array<int, 50> yDifference;
};