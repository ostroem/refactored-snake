#include "Player.h"
#include "RenderManager.h"
#include <algorithm>

Player::Player() noexcept
		: direction(directions::down), player_size(50), movement_speed(10),
		parts({ }), x_difference({ }), y_difference({ })
{
	position = { 100, 200 };
	color = { 0, 255, 0, 255 };
	rect = { position.x, position.y, 10, 10 };
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
	switch (direction) {
	case directions::up:
		position += Vector2Int(0, -movement_speed);
		break;
	case directions::down:
		position += Vector2Int(0, movement_speed);
		break;
	case directions::left: 
		position += Vector2Int(-movement_speed, 0);
		break;
	case directions::right:
		position += Vector2Int(movement_speed, 0);
		break;
	}

	parts[0].position += Vector2Int(x_difference[0], y_difference[0]);

	for (int i = 1; i < player_size; i++)
	{
		parts[i].position += Vector2Int(x_difference[i - 1], y_difference[i - 1]);
		parts[i].rect.x = parts[i].position.x;
		parts[i].rect.y = parts[i].position.y;
	}
	set_position();

}

void Player::OnKeyDown(SDL_Keycode key) noexcept
{
	switch (key)
	{
	case SDLK_LEFT:
		direction = directions::left; break;
	case SDLK_RIGHT:
		direction = directions::right; break;
	case SDLK_UP:
		direction = directions::up; break;
	case SDLK_DOWN:
		direction = directions::down; break;
	default: break;
	}
}

void Player::ResetPlayer()
{
	direction = directions::right;

	position = { 100, 200 };
}

void Player::set_position()
{
	rect.x = position.x;
	rect.y = position.y;
}
