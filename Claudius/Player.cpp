#include "Player.h"
#include "RenderManager.h"
#include <algorithm>


Player::Player() noexcept
		: direction(directions::down), movement_speed(10), x_difference({ }), y_difference({ })
{
	position = { 100, 200 };
	color = { 0, 255, 0, 255 };
	rect = { position.x, position.y, 10, 10 };
	parts.push_back({ position, color, rect });

}
void Player::render(RenderManager& renderManager)
{
	renderManager.pushback_entries(position, rect, color);

	for (int i = 0; i < parts.size(); i++)
	{
		renderManager.pushback_entries(parts.at(i).position, parts.at(i).rect, parts.at(i).color);
	}
}

void Player::update()
{
	x_difference.at(0) = position.x - parts.at(0).position.x;
	y_difference.at(0) = position.y - parts.at(0).position.y;

	for (int i = 1; i < parts.size(); i++)
	{
		x_difference.at(i) = parts.at(i).position.x - parts.at(i - 1).position.x;
		y_difference.at(i) = parts.at(i).position.y - parts.at(i - 1).position.y;
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

	parts.at(0).position += Vector2Int(x_difference.at(0), y_difference.at(0));

	for (int i = 1; i < parts.size(); i++)
	{
		parts.at(i).position += Vector2Int(x_difference.at(i - 1), y_difference.at(i - 1));
		parts.at(i).rect.x = parts.at(i).position.x;
		parts.at(i).rect.y = parts.at(i).position.y;
	}


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

void Player::set_position(Entity& part) noexcept
{
	part.rect.x = part.position.x;
	part.rect.y = part.position.y;
}
