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

struct Player
{
	Player() = default;

	enum class directions {
		up,
		down,
		left,
		right
	};
	directions direction;

	//Static == belongs to the class, not the object of the class.
	static const int player_size = 50;
	std::array<Entity, 50> parts;
	
	Vector2Int position;
	Color color;
	Rectangle rect;
	void OnKeyDown(SDL_Keycode key);
	void Initialize();
	void Render(RenderManager& renderManager);				// A reference or pointer doesn't need to be #include, just a forward declare.
	void Update();
	void ResetPlayer();

	int size = 10;
	const float movement_speed = 10.0f;

	bool new_snake = false;
	std::array<int, 50> x_difference;
	std::array<int, 50> y_difference;

	int player_score = 0;
};