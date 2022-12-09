#include "Player.h"
#include "RenderManager.h"
#include <algorithm>

Player::Player() noexcept
		: direction(directions::down), player_size(50), movement_speed(10),
		parts({ }), new_snake(false), x_difference({ }), y_difference({ })
{
	position = { 100, 200 };
	color = { 0, 255, 0, 255 };
	rect = { 0, 0, 10, 10 };
}
void Player::Render(RenderManager& renderManager)
{
	renderManager.Render(position, rect, color);

	for (int i = 0; i < 50; i++)
	{
		renderManager.Render(parts[i].position, parts[i].rect, parts[i].color);
	}
}

void Player::Update()
{
	x_difference[0] = position.x - parts[0].position.x;
	y_difference[0] = position.y - parts[0].position.y;

	for (int i = 1; i < (player_size - 1); i++)
	{
		x_difference[i] = parts[i].position.x - parts[i + 1].position.x;
		y_difference[i] = parts[i].position.y - parts[i + 1].position.y;
	}

	if (direction == directions::left)
	{
		position = position + Vector2Int(-movement_speed, 0);
		parts[0].position = parts[0].position + Vector2Int(x_difference[0], y_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].position = parts[i].position + Vector2Int(x_difference[i - 1], y_difference[i - 1]);
		}
	}
	else if (direction == directions::right)
	{
		position = position + Vector2Int(movement_speed, 0);
		parts[0].position = parts[0].position + Vector2Int(x_difference[0], y_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].position = parts[i].position + Vector2Int(x_difference[i - 1], y_difference[i - 1]);
		}
	}
	else if (direction == directions::up)
	{
		position = position + Vector2Int(0, -movement_speed);
		parts[0].position = parts[0].position + Vector2Int(x_difference[0], y_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].position = parts[i].position + Vector2Int(x_difference[i - 1], y_difference[i - 1]);
		}
	}
	else if (direction == directions::down)
	{
		position = position + Vector2Int(0, movement_speed);
		parts[0].position = parts[0].position + Vector2Int(x_difference[0], y_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].position = parts[i].position + Vector2Int(x_difference[i - 1], y_difference[i - 1]);
		}
	}
}

void Player::OnKeyDown(SDL_Keycode key)
{
	if (key == SDLK_LEFT)
	{
		direction = directions::left;
	}
	else if (key == SDLK_RIGHT)
	{
		direction = directions::right;
	}
	else if (key == SDLK_UP)
	{
		direction = directions::up;
	}
	else if (key == SDLK_DOWN)
	{
		direction = directions::down;
	}
}

void Player::ResetPlayer()
{
	direction = directions::right;

	position = { 100, 200 };
}