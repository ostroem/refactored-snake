#pragma once		// #pragma once == Compile this file once.

#include "Vector2Int.h"
#include "Color.h"
#include "Rectangle.h"
#include "SDL_keycode.h"
#include <array>

struct RenderManager;

struct Entity
{
	Vector2Int position {};
	Color color {};
	Rectangle rect {};
};

class Player : Entity
{
public:
	Player() noexcept;

	void OnKeyDown(SDL_Keycode key);
	void Render(RenderManager& renderManager);				// A reference or pointer doesn't need to be #include, just a forward declare.
	void Update();
	void ResetPlayer();
	Vector2Int get_position() const noexcept { return position; }
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

	bool new_snake = false;
	std::array<int, 50> x_difference;
	std::array<int, 50> y_difference;
};