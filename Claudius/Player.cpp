#include "Player.h"
#include "RenderManager.h"
#include <algorithm>


Player::Player() noexcept
		: direction(directions::down), movementSpeed(10), xDifference({ }), yDifference({ })
{
	constexpr int startX = 100;
	constexpr int startY = 200;

	const Color color = Color(0, 255, 0, 0);
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
	//xDifference.at(0) = position.x - parts.at(0).position.x;
	//yDifference.at(0) = position.y - parts.at(0).position.y;

	//for (int i = 1; i < parts.size(); i++)
	//{
	//	xDifference.at(i) = parts.at(i).position.x - parts.at(i - 1).position.x;
	//	yDifference.at(i) = parts.at(i).position.y - parts.at(i - 1).position.y;
	//}
	switch (direction) {
	case directions::up:
		parts.at(0).position += Vector2Int(0, -movementSpeed);
		break;
	case directions::down:
		parts.at(0).position += Vector2Int(0, movementSpeed);
		break;
	case directions::left: 
		parts.at(0).position += Vector2Int(-movementSpeed, 0);
		break;
	case directions::right:
		parts.at(0).position += Vector2Int(movementSpeed, 0);
		break;
	}
	for (auto& part : parts) {
		part.rect.x = part.position.x;
		part.rect.y = part.position.y;
	}
	//parts.at(0).position += Vector2Int(xDifference.at(0), yDifference.at(0));

	//for (int i = 1; i < parts.size(); i++)
	//{
	//	parts.at(i).position += Vector2Int(xDifference.at(i - 1), yDifference.at(i - 1));
	//	parts.at(i).rect.x = parts.at(i).position.x;
	//	parts.at(i).rect.y = parts.at(i).position.y;
	//}


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

void Player::reset()
{
	//direction = directions::right;

	//position = { 100, 200 };
}

void Player::set_position(Entity& part) noexcept
{
	part.rect.x = part.position.x;
	part.rect.y = part.position.y;
}

void Player::initialize_parts(Entity part) noexcept {
	part.rect = { 0, 0, 10, 10 };
	part.color = { 255, 0, 0, 0 };
	part.position = { get_position().x - 10, get_position().y };
	part.rect.x = part.position.x;
	part.rect.y = part.position.y;
}

void Player::grow()
{
	constexpr Entity newPart = {};
	initialize_parts(newPart);
	parts.push_back(newPart);
}
