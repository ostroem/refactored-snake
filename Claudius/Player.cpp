#include "Player.h"
#include "RenderManager.h"
#include <algorithm>

Player::Player()
	: direction(directions::up) {
	push_part();
}
void Player::render(RenderManager& renderManager) {
	for(auto& p : parts) {
		renderManager.pushback_entries(p.position, p.rect, p.color);
	}
}

void Player::update() {
	update_parts_position();
	update_head_direction();
}

void Player::on_key_down(SDL_Keycode key) noexcept {
	switch (key) {
	case SDLK_LEFT:
		if (direction != directions::right)
			direction = directions::left;
		break;
	case SDLK_RIGHT:
		if(direction != directions::left)
			direction = directions::right; 
		break;
	case SDLK_UP:
		if(direction != directions::down)
			direction = directions::up; 
		break;
	case SDLK_DOWN:
		if(direction != directions::up)
			direction = directions::down;
		break;
	default: break;
	}
}

void Player::reset() {
	parts.clear();
	push_part();
}

void Player::set_position(Entity& part) noexcept {
	part.rect.x = part.position.x;
	part.rect.y = part.position.y;
}

void Player::grow() {
	parts.push_back(head());
}

void Player::update_parts_position() {
	for (size_t i = parts.size() - 1; i > 0; --i)
	{
		parts.at(i).position = parts.at(i - 1).position;
		set_position(parts.at(i));
	}
}

void Player::push_part() noexcept
{
	parts.push_back(construct_part());
}

Entity Player::construct_part() noexcept{
	constexpr int startX = 100;
	constexpr int startY = 200;

	const Color color = Color(0, 255, 0, 255);
	const SDL_Rect rect{ startX, startY, 10, 10 };

	return Entity{ Vector2Int(startX, startY),
					color,
					rect };
}

void Player::update_head_direction() {
	switch (direction) {
	case directions::up:
		head().position += Vector2Int(0, -movementSpeed); break;
	case directions::down:
		head().position += Vector2Int(0, movementSpeed); break;
	case directions::left:
		head().position += Vector2Int(-movementSpeed, 0); break;
	case directions::right:
		head().position += Vector2Int(movementSpeed, 0); break;
	default: break;
	}
	set_position(head());

}

bool Player::is_head_colliding_with_part()
{
	for (int i = 1; i < parts.size() - 1; i++) {
		if (parts.at(i).position == head().position)
			return true;
	}
	return false;
}

bool Player::is_head_out_of_bounds()
{
	if (head().position.x > 1280 || head().position.x < 0)
		return true;
	if (head().position.y > 720 || head().position.y < 0)
		return true;
	return false;
}
