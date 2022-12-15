#include "Player.h"
#include "RenderManager.h"
#include <algorithm>


Player::Player() noexcept
	: direction(directions::down)
{
	constexpr int startX = 100;
	constexpr int startY = 200;

	const Color color = Color(0, 255, 0, 255);
	const SDL_Rect rect{ 0, 0, 10, 10 };

	parts.push_back({ Vector2Int(startX, startY),
					color,
					rect });

}
void Player::render(RenderManager& renderManager)
{
	for (int i = 0; i < parts.size(); i++)
	{
		renderManager.pushback_entries(parts.at(i).position, parts.at(i).rect, parts.at(i).color);
	}
}

void Player::update()
{
	switch (direction) {
	case directions::up:
		head().position += Vector2Int(0, -movementSpeed);
		break;
	case directions::down:
		head().position += Vector2Int(0, movementSpeed);
		break;
	case directions::left: 
		head().position += Vector2Int(-movementSpeed, 0);
		break;
	case directions::right:
		head().position += Vector2Int(movementSpeed, 0);
		break;
	}
	size_t index = parts.size() - 1;
	std::for_each(parts.begin(), parts.end(), [&](Entity& part) {
		if (index != 0) {
			parts.at(index).position = parts.at(index - 1).position;
		}
		set_position(part);
		index--;
				  });
}

void Player::on_key_down(SDL_Keycode key) noexcept
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

void Player::reset() noexcept
{
	parts.clear();
}

void Player::set_position(Entity& part) noexcept
{
	part.rect.x = part.position.x;
	part.rect.y = part.position.y;
}

void Player::grow()
{
	parts.push_back(head());
}
