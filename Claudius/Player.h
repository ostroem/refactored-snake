#pragma once		// #pragma once == Compile this file once.

#include "Vector2Int.h"
#include "Color.h"
#include "Rectangle.h"
#include "SDL_keycode.h"

struct RenderManager;

struct Player
{
	struct PlayerPart
	{
		Vector2Int position;
		Color color;
		Rectangle rect;
	};

	//Static == belongs to the class, not the object of the class.
	static const int player_size = 50;
	PlayerPart parts[player_size];
	
	Vector2Int position;
	Color color;
	Rectangle rect;
	void OnKeyDown(SDL_Keycode key);
	void Initialize();
	void Render(RenderManager& renderManager);				// A reference or pointer doesn't need to be #include, just a forward declare.
	void Update(double dt);
	void ResetPlayer();

	int size = 10;
	const float movement_speed = 10.0f;

	bool moving_right = false;
	bool moving_left = false;
	bool moving_up = false;
	bool moving_down = false;
	bool new_snake = false;

	float x_array_difference[player_size] = {};
	float y_array_difference[player_size] = {};

	int player_score = 0;
};