#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>
#include <algorithm>

void Player::Initialize()
{
	color = { 0, 255, 0, 255 };
	rect = { 0, 0, 10, 10 };
	position = { 100, 200 };
	player_score = 0;

	for (auto& part : parts)
	{
		part.color = { 255, 0, 0, 0 };
		part.rect = { 0, 0, 10, 10 };
		part.position = { };
	}
}

void Player::Render(RenderManager& renderManager)
{
	renderManager.Render(position, rect, color);

	for (int i = 0; i < player_score; i++)
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
		position = { -1, 0 };
		parts[0].position = { x_difference[0], y_difference[0] };

		for (int i = 1; i < player_size; i++)
		{
			parts[i].position = { x_difference[i - 1], y_difference[i - 1] };
		}
	}
	else if (direction == directions::right)
	{
		position = { 1, 0 };
		parts[0].position = { x_difference[0], y_difference[0] };

		for (int i = 1; i < player_size; i++)
		{
			parts[i].position = { x_difference[i - 1], y_difference[i - 1] };
		}
	}
	else if (direction == directions::up)
	{
		position = { 0, -1 };
		parts[0].position = { x_difference[0], y_difference[0] };

		for (int i = 1; i < player_size; i++)
		{
			parts[i].position = { x_difference[i - 1], y_difference[i - 1] };
		}
	}
	else if (direction == directions::down)
	{
		position = { 0, 1 };
		parts[0].position = { x_difference[0], y_difference[0] };

		for (int i = 1; i < player_size; i++)
		{
			parts[i].position = { x_difference[i - 1], y_difference[i - 1] };
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
	player_score = 0;
	direction = directions::right;

	position = { 100, 200 };
}