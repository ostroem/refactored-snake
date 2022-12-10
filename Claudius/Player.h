#pragma once		// #pragma once == Compile this file once.

#include "Entity.h"
#include "SDL_keycode.h"
#include <array>
#include "RenderManager.h"

class Player : public Entity {
public:
	Player() noexcept;

	void OnKeyDown(SDL_Keycode key) noexcept;
	void Render(RenderManager& renderManager);				// A reference or pointer doesn't need to be #include, just a forward declare.
	void Update();
	void ResetPlayer();
	Vector2Int get_position() const noexcept { return position; }
	void set_position();
private:
	enum class directions {
		up,
		down,
		left,
		right
	};
	directions direction;
public:
	std::array<Entity, 50> parts;
private:
	const int player_size;
	const int movement_speed;

	std::array<int, 50> x_difference;
	std::array<int, 50> y_difference;
};